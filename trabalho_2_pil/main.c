//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "scicomm.h"

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
float theta = 0.0f;
#pragma DATA_SECTION(sref,"Cla1ToCpuMsgRAM");
float sref;

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