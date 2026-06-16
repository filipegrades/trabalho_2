//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "scicomm.h"
#include <math.h>

// Defines
#define pi 3.141592f 
#define sqrt2 1.41421356f
#define vdc 400.0f
#define L 3e-3f
#define R 0.037699f
#define dT 2.5e-6f
#define fg 60.0f
#define km1 ((2*L-dT*R)/(2*L+dT*R))
#define km2 ((dT*vdc)/(4*L+2*dT*R))
#define km3 (dT/(4*L+2*dT*R))
#define TAMANHO_BUFFER 100


#pragma DATA_SECTION(e,"Cla1ToCpuMsgRAM");
float e[3]={0};
#pragma DATA_SECTION(u,"Cla1ToCpuMsgRAM");
float u[2]={0};
#pragma DATA_SECTION(yr,"Cla1ToCpuMsgRAM");
float yr[3]={0};
#pragma DATA_SECTION(i,"CpuToCla1MsgRAM");
float i;
#pragma DATA_SECTION(vg,"CpuToCla1MsgRAM");
float vg;
#pragma DATA_SECTION(REF,"CpuToCla1MsgRAM");
float REF = 10.0f;
#pragma DATA_SECTION(theta,"Cla1ToCpuMsgRAM");
float32_t theta = 0.0f;
#pragma DATA_SECTION(sref,"Cla1ToCpuMsgRAM");
float sref;

// Variaveis do modelo
float il[2] = {0};
float S[2] = {0};
float vt[2] = {0};
float Si[4] = {0};
float vt_amplitude = sqrt2*220.0f;
float vt_dTheta = 2*pi*fg*dT;
float vt_theta = 0.0;
float vt_phi = 0.0;
bool habilitaCalculo = false;

float vt_buffer[TAMANHO_BUFFER];
float il_buffer[TAMANHO_BUFFER];
unsigned int cont_buffer = 0;
//
// Funcao Principal
//
void main(void)
{
    // Inicializacao do dispositivo
    Device_init();
    Interrupt_initModule();
    Interrupt_initVectorTable();
    Board_init();

    // Habilita interrupcoes globais e de tempo real
    EINT;
    ERTM;

    while (1)
    {
        if(habilitaCalculo)
        {
            habilitaCalculo = false;
            vt[0] = vt_amplitude*__sin(vt_theta+vt_phi);
            vt_theta = ((vt_theta+vt_dTheta)<=2*pi) ? (vt_theta+vt_dTheta) : (2*pi - vt_theta+vt_dTheta);
            S[0] = 0.5*((Si[0]+Si[3])-(Si[1]+Si[2]));
            il[0] = km1*il[1] + km2*(S[1]+S[0]) - km3*(vt[1]+vt[0]);
            S[1] = S[0];
            il[1] = il[0];
            vt[1] = vt[0];
            vt_buffer[cont_buffer] = vt[0];
            il_buffer[cont_buffer] = il[0];
            cont_buffer = (cont_buffer+1)%TAMANHO_BUFFER;
        }
    }
}

__interrupt void INT_SCI0_RX_ISR(void)
{
    //protocolReceiveData(SCI0_BASE,&REF,sizeof(float));
    protocolReceiveData(SCI0_BASE,&i,sizeof(float));
    protocolReceiveData(SCI0_BASE,&vg,sizeof(float));

    CLA_forceTasks(myCLA0_BASE,CLA_TASKFLAG_1);
    
    SCI_clearInterruptStatus(SCI0_BASE, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INT_SCI0_RX_INTERRUPT_ACK_GROUP);
}

__interrupt void cla1Isr1()
{
    protocolSendData(SCI0_BASE, &u[0],sizeof(float));
    Interrupt_clearACKGroup(INT_myCLA01_INTERRUPT_ACK_GROUP);
    
}

__interrupt void INT_myCPUTIMER0_ISR()
{
    habilitaCalculo = true;
    Interrupt_clearACKGroup(INT_myCPUTIMER0_INTERRUPT_ACK_GROUP);
}

__interrupt void INT_S1_XINT_ISR()
{
    Si[0] = GPIO_readPin(S1);
    Interrupt_clearACKGroup(INT_S1_XINT_INTERRUPT_ACK_GROUP);
}

__interrupt void INT_S2_XINT_ISR()
{
    Si[1] = GPIO_readPin(S2);
    Interrupt_clearACKGroup(INT_S2_XINT_INTERRUPT_ACK_GROUP);
}

__interrupt void INT_S3_XINT_ISR()
{
    Si[2] = GPIO_readPin(S3);
    Interrupt_clearACKGroup(INT_S3_XINT_INTERRUPT_ACK_GROUP);
}

__interrupt void INT_S4_XINT_ISR()
{
    Si[3] = GPIO_readPin(S4);
    Interrupt_clearACKGroup(INT_S4_XINT_INTERRUPT_ACK_GROUP);
}
