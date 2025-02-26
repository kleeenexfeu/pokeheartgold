#include <nitro/os/interrupt.h>

OSIrqCallbackInfo OSi_IrqCallbackInfo[8];

u16 OSi_IrqCallbackInfoIndex[] = {
    REG_OS_IE_D0_SHIFT,
    REG_OS_IE_D1_SHIFT,
    REG_OS_IE_D2_SHIFT,
    REG_OS_IE_D3_SHIFT,
    REG_OS_IE_T0_SHIFT,
    REG_OS_IE_T1_SHIFT,
    REG_OS_IE_T2_SHIFT,
    REG_OS_IE_T3_SHIFT,
#ifdef SDK_ARM7
    REG_OS_IE_VB_SHIFT,
#endif
};

void OS_IrqDummy(void) {}

void OSi_IrqCallback(int index) {
    OSIrqMask imask = (1UL << OSi_IrqCallbackInfoIndex[index]);
    void (*callback)(void *) = OSi_IrqCallbackInfo[index].func;
    OSi_IrqCallbackInfo[index].func = NULL;
    if (callback) callback(OSi_IrqCallbackInfo[index].arg);
    OS_SetIrqCheckFlag(imask);
    if (!OSi_IrqCallbackInfo[index].enable)
        OS_DisableIrqMask(imask);
}

void OSi_IrqDma0(void) {
    OSi_IrqCallback(OSi_IRQCALLBACK_NO_DMA0);
}

void OSi_IrqDma1(void) {
    OSi_IrqCallback(OSi_IRQCALLBACK_NO_DMA1);
}

void OSi_IrqDma2(void) {
    OSi_IrqCallback(OSi_IRQCALLBACK_NO_DMA2);
}

void OSi_IrqDma3(void) {
    OSi_IrqCallback(OSi_IRQCALLBACK_NO_DMA3);
}

void OSi_IrqTimer0(void) {
    OSi_IrqCallback(OSi_IRQCALLBACK_NO_TIMER0);
}

void OSi_IrqTimer1(void) {
    OSi_IrqCallback(OSi_IRQCALLBACK_NO_TIMER1);
}

void OSi_IrqTimer2(void) {
    OSi_IrqCallback(OSi_IRQCALLBACK_NO_TIMER2);
}

void OSi_IrqTimer3(void) {
    OSi_IrqCallback(OSi_IRQCALLBACK_NO_TIMER3);
}
