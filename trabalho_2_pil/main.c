//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "scicomm.h"

#pragma DATA_SECTION(x,"Cla1ToCpuMsgRAM");
float x[3]={0};
#pragma DATA_SECTION(y,"Cla1ToCpuMsgRAM");
float y[3]={0};
#pragma DATA_SECTION(vo,"CpuToCla1MsgRAM");
float vo;
#pragma DATA_SECTION(REF,"CpuToCla1MsgRAM");
float REF = 20.0f;

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
    protocolReceiveData(SCI0_BASE,&vo,sizeof(float));

    CLA_forceTasks(myCLA0_BASE,CLA_TASKFLAG_1);
    
    SCI_clearInterruptStatus(SCI0_BASE, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INT_SCI0_RX_INTERRUPT_ACK_GROUP);
}

__interrupt void cla1Isr1()
{
    protocolSendData(SCI0_BASE, &y[0],sizeof(float));
    Interrupt_clearACKGroup(INT_myCLA01_INTERRUPT_ACK_GROUP);
    
}