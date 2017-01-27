/*
    CC26x0 CMSIS
    Unofficial release
    (c) Alexey Kramarenko 2017
    alexeyk13@yandex.ru

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CC26X0_H
#define CC26X0_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum IRQn
{
//--------------------------  Cortex-M3 processor exceptions ---------------------------------------
  NonMaskableInt_IRQn         = -14,    /*!< Non Maskable Interrupt                                                 */
  MemoryManagement_IRQn       = -12,    /*!< Cortex-M3 Memory Management Interrupt                                  */
  BusFault_IRQn               = -11,    /*!< Cortex-M3 Bus Fault Interrupt                                          */
  UsageFault_IRQn             = -10,    /*!< Cortex-M3 Usage Fault Interrupt                                        */
  SVCall_IRQn                 = -5,     /*!< Cortex-M3 SV Call Interrupt                                            */
  DebugMonitor_IRQn           = -4,     /*!< Cortex-M3 Debug Monitor Interrupt                                      */
  PendSV_IRQn                 = -2,     /*!< Cortex-M3 Pend SV Interrupt                                            */
  SysTick_IRQn                = -1,     /*!< Cortex-M3 System Tick Interrupt                                        */

//----------------------------  CC2x0 specific exceptions ------------------------------------------
  GPIO_IRQn                   = 0,      /*!< AON edge detect                                                        */
  I2C_IRQn                    = 1,      /*!< I2C                                                                    */
  RFCCPE1_IRQn                = 2,      /*!< RF Core Command & Packet Engine 1                                      */
  AONRTC_IRQn                 = 4,      /*!< AON RTC                                                                */
  UART0_IRQn                  = 5,      /*!< UART0 Rx and Tx                                                        */
  AUXSWEvent0_IRQn            = 6,      /*!< AUX software event 0                                                   */
  SSI0_IRQn                   = 7,      /*!< SSI0 Rx and Tx                                                         */
  SSI1_IRQn                   = 8,      /*!< SSI1 Rx and Tx                                                         */
  RFCCPE0_IRQn                = 9,      /*!< RF Core Command & Packet Engine 0                                      */
  RFCHardware_IRQn            = 10,     /*!< RF Core Hardware                                                       */
  RFCCmdAck_IRQn              = 11,     /*!< RF Core Command Acknowledge                                            */
  I2S_IRQn                    = 12,     /*!< I2S                                                                    */
  AUXSWEvent1_IRQn            = 13,     /*!< AUX software event 1                                                   */
  Watchdog_IRQn               = 14,     /*!< Watchdog timer                                                         */
  Timer0A_IRQn                = 15,     /*!< Timer 0 subtimer A                                                     */
  Timer0B_IRQn                = 16,     /*!< Timer 0 subtimer B                                                     */
  Timer1A_IRQn                = 17,     /*!< Timer 1 subtimer A                                                     */
  Timer1B_IRQn                = 18,     /*!< Timer 1 subtimer B                                                     */
  Timer2A_IRQn                = 19,     /*!< Timer 2 subtimer A                                                     */
  Timer2B_IRQn                = 20,     /*!< Timer 2 subtimer B                                                     */
  Timer3A_IRQn                = 21,     /*!< Timer 3 subtimer A                                                     */
  Timer3B_IRQn                = 22,     /*!< Timer 3 subtimer B                                                     */
  Crypto_IRQn                 = 23,     /*!< Crypto Core Result available                                           */
  uDMA_IRQn                   = 24,     /*!< uDMA Software                                                          */
  uDMAErr_IRQn                = 25,     /*!< uDMA Error                                                             */
  Flash_IRQn                  = 26,     /*!< Flash controller                                                       */
  SWEvent0_IRQn               = 27,     /*!< Software Event 0                                                       */
  AUXCombEvent_IRQn           = 28,     /*!< AUX combined event                                                     */
  AONProg_IRQn                = 29,     /*!< AON programmable 0                                                     */
  DynProg_IRQn                = 30,     /*!< Dynamic Programmable interrupt source (Default: PRCM)                  */
  AUXCompA_IRQn               = 31,     /*!< AUX Comparator A                                                       */
  AUXADC_IRQn                 = 32,     /*!< AUX ADC new sample or ADC DMA done, ADC underflow, ADC overflow        */
  TRNG_IRQn                   = 33      /*!< TRNG event                                                             */
} IRQn_Type;

/** @addtogroup Configuration_of_CMSIS
  * @{
  */

/* Processor and Core Peripheral Section */ /* Configuration of the Template Processor and Core Peripherals */

//Not sure about revision
#define __CM3_REV              		0x0101		/*!< Cortex-M3 Core Revision               */
#define __MPU_PRESENT           	0         	/*!< MPU present or not                    */
#define __NVIC_PRIO_BITS          	3         	/*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    	0         	/*!< Set to 1 if different SysTick Config is used */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "../../../../Include/core_cm3.h"
//the only useful file in all SDK
#include "hw_memmap.h"
#include <stdint.h>

/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/******************************************************************************/
/*                                                                            */
/*                             AON_EVENT                                      */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t MCUWUSEL;                      /*!< Wake-up Selector For MCU                                           */
  __IO  uint32_t AUXWUSEL;                      /*!< Wake-up Selector For AUX                                           */
  __IO  uint32_t EVTOMCUSEL;                    /*!< Event Selector For MCU Event Fabric                                */
  __IO  uint32_t RTCSEL;                        /*!< RTC Capture Event Selector For AON_RTC                             */
} AON_EVENT_Type;


/******************************************************************************/
/*                                                                            */
/*                                EVENT                                       */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t A;
  __IO  uint32_t B;
  __I   uint32_t RESERVED0[62];
} EVENT_GPT_CAPTSEL_Type;

typedef struct
{
  __I   uint32_t SREQ;
  __I   uint32_t REQ;
} EVENT_uDMA_CHSEL_Type;

typedef struct
{
  __I   uint32_t CPUIRQSEL[34];                 /*!< Output Selection for CPU Interrupt                                 */
  __I   uint32_t RESERVED0[30];
  __I   uint32_t RFCSEL[10];                    /*!< Output Selection for RFC Event                                     */
  __I   uint32_t RESERVED1[54];
  EVENT_GPT_CAPTSEL_Type GPT_CAPTSEL[3];        /*!< Output Selection for GPT0-2                                        */
  EVENT_uDMA_CHSEL_Type uDMA_CHSEL[25];         /*!< Output Selection for DMA Channel                                   */
  __I   uint32_t RESERVED2[14];
  EVENT_GPT_CAPTSEL_Type GPT_CAPTSEL3;          /*!< Output Selection for GPT3                                          */
  __IO  uint32_t AUXSEL0;                       /*!< Output Selection for AUX Subscriber 0                              */
  __I   uint32_t RESERVED4[63];
  __I   uint32_t CM3NMISEL0;                    /*!< Output Selection for NMI Subscriber 0                              */
  __I   uint32_t RESERVED5[63];
  __IO  uint32_t I2SSTMPSEL0;                   /*!< Output Selection for I2S Subscriber 0                              */
  __I   uint32_t RESERVED6[63];
  __IO  uint32_t FRZSEL0;                       /*!< Output Selection for FRZ Subscriber 0                              */
  __I   uint32_t RESERVED7[319];
  __IO  uint32_t SWEV;                          /*!< Set or Clear Software Events                                       */
} EVENT_Type;


/******************************************************************************/
/*                                                                            */
/*                             AUX_DDI0_OSC                                   */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t CTL0;                          /*!< Control 0                                                          */
  __IO  uint32_t CTL1;                          /*!< Control 1                                                          */
  __IO  uint32_t RADCEXTCFG;                    /*!< RADC External Configuration                                        */
  __IO  uint32_t AMPCOMPCTL;                    /*!< Amplitude Compensation Control                                     */
  __IO  uint32_t AMPCOMPTH1;                    /*!< Amplitude Compensation Threashold 1                                */
  __IO  uint32_t AMPCOMPTH2;                    /*!< Amplitude Compensation Threashold 2                                */
  __IO  uint32_t ANABYPASSVAL1;                 /*!< Analog Bypass Values 1                                             */
  __IO  uint32_t ANABYPASSVAL2;                 /*!< Internal                                                           */
  __IO  uint32_t ATESTCTL;                      /*!< Analog Test Control                                                */
  __IO  uint32_t ADCDOUBLERNANOAMPCTL;          /*!< ADC Doubler Nanoamp Control                                        */
  __IO  uint32_t XOSCHFCTL;                     /*!< XOSCHF Control                                                     */
  __IO  uint32_t LFOSCCTL;                      /*!< Low Frequency Oscillator Control                                   */
  __IO  uint32_t RCOSCHFCTL;                    /*!< RCOSCHF Control                                                    */
  __I   uint32_t STAT0;                         /*!< Status 0                                                           */
  __I   uint32_t STAT1;                         /*!< Status 1                                                           */
  __I   uint32_t STAT2;                         /*!< Status 2                                                           */
} AUX_DDI0_OSC_Type;


/******************************************************************************/
/*                                                                            */
/*                            AON_SYSCTL                                      */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t PWRCTL;                        /*!< Power Management                                                   */
  __IO  uint32_t RESETCTL;                      /*!< Reset Management                                                   */
  __IO  uint32_t SLEEPCTL;                      /*!< Sleep Mode                                                         */
} AON_SYSCTL_Type;


/******************************************************************************/
/*                                                                            */
/*                              AON_WUC                                       */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t MCUCLK;                        /*!< MCU Clock Management                                               */
  __IO  uint32_t AUXCLK;                        /*!< AUX Clock Management                                               */
  __IO  uint32_t MCUCFG;                        /*!< MCU Configuration                                                  */
  __IO  uint32_t AUXCFG;                        /*!< AUX Configuration                                                  */
  __IO  uint32_t AUXCTL;                        /*!< AUX Control                                                        */
  __IO  uint32_t PWRSTAT;                       /*!< Power Status                                                       */
  __IO  uint32_t SHUTDOWN;                      /*!< Shutdown Control                                                   */
  __I   uint32_t RESERVED0;
  __IO  uint32_t CTL0;                          /*!< Control 0                                                          */
  __IO  uint32_t CTL1;                          /*!< Control 1                                                          */
  __I   uint32_t RESERVED1[2];
  __IO  uint32_t RECHARGECFG;                   /*!< Recharge Controller Configuration                                  */
  __IO  uint32_t RECHARGESTAT;                  /*!< Recharge Controller Status                                         */
  __IO  uint32_t OSCCFG;                        /*!< Oscillator Configuration                                           */
  __I   uint32_t RESERVED2;
  __IO  uint32_t JTAGCFG;                       /*!< JTAG Configuration                                                 */
  __IO  uint32_t JTAGUSERCODE;                  /*!< JTAG USERCODE                                                      */
} AON_WUC_Type;


/******************************************************************************/
/*                                                                            */
/*                                PRCM                                        */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t INFRCLKDIVR;                   /*!< Infrastructure Clock Division Factor For Run Mode                  */
  __IO  uint32_t INFRCLKDIVS;                   /*!< Infrastructure Clock Division Factor For Sleep Mode                */
  __IO  uint32_t INFRCLKDIVDS;                  /*!< Infrastructure Clock Division Factor For DeepSleep Mode            */
  __IO  uint32_t VDCTL;                         /*!< MCU Voltage Domain Control                                         */
  __I   uint32_t RESERVED0[6];
  __IO  uint32_t CLKLOADCTL;                    /*!< Clock Load Control                                                 */
  __IO  uint32_t RFCCLKG;                       /*!< RFC Clock Gate                                                     */
  __IO  uint32_t VIMSCLKG;                      /*!< VIMS Clock Gate                                                    */
  __I   uint32_t RESERVED1[2];
  __IO  uint32_t SECDMACLKGR;                   /*!< TRNG, CRYPTO And UDMA Clock Gate For Run Mode                      */
  __IO  uint32_t SECDMACLKGS;                   /*!< TRNG, CRYPTO And UDMA Clock Gate For Sleep Mode                    */
  __IO  uint32_t SECDMACLKGDS;                  /*!< TRNG, CRYPTO And UDMA Clock Gate For Deep Sleep Mode               */
  __IO  uint32_t GPIOCLKGR;                     /*!< GPIO Clock Gate For Run Mode                                       */
  __IO  uint32_t GPIOCLKGS;                     /*!< GPIO Clock Gate For Sleep Mode                                     */
  __IO  uint32_t GPIOCLKGDS;                    /*!< GPIO Clock Gate For Deep Sleep Mode                                */
  __IO  uint32_t GPTCLKGR;                      /*!< GPT Clock Gate For Run Mode                                        */
  __IO  uint32_t GPTCLKGS;                      /*!< GPT Clock Gate For Sleep Mode                                      */
  __IO  uint32_t GPTCLKGDS;                     /*!< GPT Clock Gate For Deep Sleep Mode                                 */
  __IO  uint32_t I2CCLKGR;                      /*!< I2C Clock Gate For Run Mode                                        */
  __IO  uint32_t I2CCLKGS;                      /*!< I2C Clock Gate For Sleep Mode                                      */
  __IO  uint32_t I2CCLKGDS;                     /*!< I2C Clock Gate For Deep Sleep Mode                                 */
  __IO  uint32_t UARTCLKGR;                     /*!< UART Clock Gate For Run Mode                                       */
  __IO  uint32_t UARTCLKGS;                     /*!< UART Clock Gate For Sleep Mode                                     */
  __IO  uint32_t UARTCLKGDS;                    /*!< UART Clock Gate For Deep Sleep Mode                                */
  __IO  uint32_t SSICLKGR;                      /*!< SSI Clock Gate For Run Mode                                        */
  __IO  uint32_t SSICLKGS;                      /*!< SSI Clock Gate For Sleep Mode                                      */
  __IO  uint32_t SSICLKGDS;                     /*!< SSI Clock Gate For Deep Sleep Mode                                 */
  __IO  uint32_t I2SCLKGR;                      /*!< I2S Clock Gate For Run Mode                                        */
  __IO  uint32_t I2SCLKGS;                      /*!< I2S Clock Gate For Sleep Mode                                      */
  __IO  uint32_t I2SCLKGDS;                     /*!< I2S Clock Gate For Deep Sleep Mode                                 */
  __I   uint32_t RESERVED2[10];
  __IO  uint32_t CPUCLKDIV;                     /*!< Internal                                                           */
  __I   uint32_t RESERVED3[3];
  __IO  uint32_t I2SBCLKSEL;                    /*!< I2S Clock Control                                                  */
  __IO  uint32_t GPTCLKDIV;                     /*!< GPT Scalar                                                         */
  __IO  uint32_t I2SCLKCTL;                     /*!< I2S Clock Control                                                  */
  __IO  uint32_t I2SMCLKDIV;                    /*!< MCLK Division Ratio                                                */
  __IO  uint32_t I2SBCLKDIV;                    /*!< BCLK Division Ratio                                                */
  __IO  uint32_t I2SWCLKDIV;                    /*!< WCLK Division Ratio                                                */
  __I   uint32_t RESERVED4[11];
  __O   uint32_t SWRESET;                       /*!< SW Initiated Resets                                                */
  __IO  uint32_t WARMRESET;                     /*!< WARM Reset Control And Status                                      */
  __I   uint32_t RESERVED5[6];
  __IO  uint32_t PDCTL0;                        /*!< Power Domain Control                                               */
  __IO  uint32_t PDCTL0RFC;                     /*!< RFC Power Domain Control                                           */
  __IO  uint32_t PDCTL0SERIAL;                  /*!< SERIAL Power Domain Control                                        */
  __IO  uint32_t PDCTL0PERIPH;                  /*!< PERIPH Power Domain Control                                        */
  __I   uint32_t RESERVED6;
  __I   uint32_t PDSTAT0;                       /*!< Power Domain Status                                                */
  __I   uint32_t PDSTAT0RFC;                    /*!< RFC Power Domain Status                                            */
  __I   uint32_t PDSTAT0SERIAL;                 /*!< SERIAL Power Domain Status                                         */
  __I   uint32_t PDSTAT0PERIPH;                 /*!< PERIPH Power Domain Status                                         */
  __I   uint32_t RESERVED7[11];
  __IO  uint32_t PDCTL1;                        /*!< Power Domain Control                                               */
  __I   uint32_t RESERVED8;
  __IO  uint32_t PDCTL1CPU;                     /*!< CPU Power Domain Control                                           */
  __IO  uint32_t PDCTL1RFC;                     /*!< RFC Power Domain Control                                           */
  __IO  uint32_t PDCTL1VIMS;                    /*!< VIMS Power Domain Control                                          */
  __I   uint32_t RESERVED9;
  __I   uint32_t PDSTAT1;                       /*!< Power Domain Status                                                */
  __I   uint32_t PDSTAT1BUS;                    /*!< BUS Power Domain Status                                            */
  __I   uint32_t PDSTAT1RFC;                    /*!< RFC Power Domain Status                                            */
  __I   uint32_t PDSTAT1CPU;                    /*!< CPU Power Domain Status                                            */
  __I   uint32_t PDSTAT1VIMS;                   /*!< VIMS Power Domain Status                                           */
  __I   uint32_t RESERVED10[10];
  __IO  uint32_t RFCMODESEL;                    /*!< Selected RFC Mode                                                  */
  __I   uint32_t RESERVED11[3];
  __IO  uint32_t PWRPROFSTAT;                   /*!< Power Profiler Register                                            */
  __I   uint32_t RESERVED12[16];
  __IO  uint32_t RAMRETEN;                      /*!< Memory Retention Control                                           */
} PRCM_Type;


/******************************************************************************/
/*                                                                            */
/*                               FLASH                                        */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I   uint32_t RESERVED0[7];
  __I   uint32_t STAT;                          /*!< FMC and Efuse Status                                               */
  __I   uint32_t RESERVED1;
  __IO  uint32_t CFG;                           /*!< Internal                                                           */
  __IO  uint32_t SYSCODE_START;                 /*!< Internal                                                           */
  __IO  uint32_t FLASH_SIZE;                    /*!< Internal                                                           */
  __I   uint32_t RESERVED2[3];
  __IO  uint32_t FWLOCK;                        /*!< Internal                                                           */
  __IO  uint32_t FWFLAG;                        /*!< Internal                                                           */
  __I   uint32_t RESERVED3[1007];
  __IO  uint32_t EFUSE;                         /*!< Internal                                                           */
  __IO  uint32_t EFUSEADDR;                     /*!< Internal                                                           */
  __IO  uint32_t DATAUPPER;                     /*!< Internal                                                           */
  __IO  uint32_t DATALOWER;                     /*!< Internal                                                           */
  __IO  uint32_t EFUSECFG;                      /*!< Internal                                                           */
  __I   uint32_t EFUSESTAT;                     /*!< Internal                                                           */
  __I   uint32_t ACC;                           /*!< Internal                                                           */
  __IO  uint32_t BOUNDARY;                      /*!< Internal                                                           */
  __I   uint32_t EFUSEFLAG;                     /*!< Internal                                                           */
  __IO  uint32_t EFUSEKEY;                      /*!< Internal                                                           */
  __I   uint32_t EFUSERELEASE;                  /*!< Internal                                                           */
  __I   uint32_t EFUSEPINS;                     /*!< Internal                                                           */
  __IO  uint32_t EFUSECRA;                      /*!< Internal                                                           */
  __IO  uint32_t EFUSEREAD;                     /*!< Internal                                                           */
  __IO  uint32_t EFUSEPROGRAM;                  /*!< Internal                                                           */
  __IO  uint32_t EFUSEERROR;                    /*!< Internal                                                           */
  __I   uint32_t SINGLEBIT;                     /*!< Internal                                                           */
  __I   uint32_t TWOBIT;                        /*!< Internal                                                           */
  __IO  uint32_t SELFTESTCYC;                   /*!< Internal                                                           */
  __IO  uint32_t SELFTESTSIGN;                  /*!< Internal                                                           */
  __I   uint32_t RESERVED4[1004];
  __IO  uint32_t FRDCTL;                        /*!< Internal                                                           */
  __IO  uint32_t FSPRD;                         /*!< Internal                                                           */
  __IO  uint32_t FEDACCTL1;                     /*!< Internal                                                           */
  __I   uint32_t RESERVED5[4];
  __IO  uint32_t FEDACSTAT;                     /*!< Internal                                                           */
  __I   uint32_t RESERVED6[4];
  __IO  uint32_t FBPROT;                        /*!< Internal                                                           */
  __IO  uint32_t FBSE;                          /*!< Internal                                                           */
  __I   uint32_t FBBUSY;                        /*!< Internal                                                           */
  __IO  uint32_t FBAC;                          /*!< Internal                                                           */
  __IO  uint32_t FBFALLBACK;                    /*!< Internal                                                           */
  __I   uint32_t FBPRDY;                        /*!< Internal                                                           */
  __IO  uint32_t FPAC1;                         /*!< Internal                                                           */
  __IO  uint32_t FPAC2;                         /*!< Internal                                                           */
  __IO  uint32_t FMAC;                          /*!< Internal                                                           */
  __I   uint32_t FMSTAT;                        /*!< Internal                                                           */
  __I   uint32_t RESERVED7[3];
  __IO  uint32_t FLOCK;                         /*!< Internal                                                           */
  __I   uint32_t RESERVED8[6];
  __IO  uint32_t FVREADCT;                      /*!< Internal                                                           */
  __IO  uint32_t FVHVCT1;                       /*!< Internal                                                           */
  __IO  uint32_t FVHVCT2;                       /*!< Internal                                                           */
  __IO  uint32_t FVHVCT3;                       /*!< Internal                                                           */
  __IO  uint32_t FVNVCT;                        /*!< Internal                                                           */
  __IO  uint32_t FVSLP;                         /*!< Internal                                                           */
  __IO  uint32_t FVWLCT;                        /*!< Internal                                                           */
  __IO  uint32_t FEFUSECTL;                     /*!< Internal                                                           */
  __IO  uint32_t FEFUSESTAT;                    /*!< Internal                                                           */
  __IO  uint32_t FEFUSEDATA;                    /*!< Internal                                                           */
  __IO  uint32_t FSEQPMP;                       /*!< Internal                                                           */
  __I   uint32_t RESERVED9[21];
  __IO  uint32_t FBSTROBES;                     /*!< Internal                                                           */
  __IO  uint32_t FPSTROBES;                     /*!< Internal                                                           */
  __IO  uint32_t FBMODE;                        /*!< Internal                                                           */
  __IO  uint32_t FTCR;                          /*!< Internal                                                           */
  __IO  uint32_t FADDR;                         /*!< Internal                                                           */
  __I   uint32_t RESERVED10[2];
  __IO  uint32_t FTCTL;                         /*!< Internal                                                           */
  __IO  uint32_t FWPWRITE[8];                   /*!< Internal                                                           */
  __IO  uint32_t FWPWRITE_ECC;                  /*!< Internal                                                           */
  __I   uint32_t FSWSTAT;                       /*!< Internal                                                           */
  __I   uint32_t RESERVED11[46];
  __I   uint32_t FSM_GLBCTL;                    /*!< Internal                                                           */
  __I   uint32_t FSM_STATE;                     /*!< Internal                                                           */
  __I   uint32_t FSM_STAT;                      /*!< Internal                                                           */
  __IO  uint32_t FSM_CMD;                       /*!< Internal                                                           */
  __IO  uint32_t FSM_PE_OSU;                    /*!< Internal                                                           */
  __IO  uint32_t FSM_VSTAT;                     /*!< Internal                                                           */
  __IO  uint32_t FSM_PE_VSU;                    /*!< Internal                                                           */
  __IO  uint32_t FSM_CMP_VSU;                   /*!< Internal                                                           */
  __IO  uint32_t FSM_EX_VAL;                    /*!< Internal                                                           */
  __IO  uint32_t FSM_RD_H;                      /*!< Internal                                                           */
  __IO  uint32_t FSM_P_OH;                      /*!< Internal                                                           */
  __IO  uint32_t FSM_ERA_OH;                    /*!< Internal                                                           */
  __I   uint32_t FSM_SAV_PPUL;                  /*!< Internal                                                           */
  __IO  uint32_t FSM_PE_VH;                     /*!< Internal                                                           */
  __I   uint32_t RESERVED12[2];
  __IO  uint32_t FSM_PRG_PW;                    /*!< Internal                                                           */
  __IO  uint32_t FSM_ERA_PW;                    /*!< Internal                                                           */
  __I   uint32_t RESERVED13[3];
  __I   uint32_t FSM_SAV_ERA_PUL;               /*!< Internal                                                           */
  __I   uint32_t FSM_TIMER;                     /*!< Inlernal                                                           */
  __I   uint32_t FSM_MODE;                      /*!< Internal                                                           */
  __I   uint32_t FSM_PGM;                       /*!< Internal                                                           */
  __I   uint32_t FSM_ERA;                       /*!< Internal                                                           */
  __IO  uint32_t FSM_PRG_PUL;                   /*!< Internal                                                           */
  __IO  uint32_t FSM_ERA_PUL;                   /*!< Internal                                                           */
  __IO  uint32_t FSM_STEP_SIZE;                 /*!< Internal                                                           */
  __I   uint32_t FSM_PUL_CNTR;                  /*!< Internal                                                           */
  __IO  uint32_t FSM_EC_STEP_HEIGHT;            /*!< Internal                                                           */
  __IO  uint32_t FSM_ST_MACHINE;                /*!< Internal                                                           */
  __IO  uint32_t FSM_FLES;                      /*!< Internal                                                           */
  __I   uint32_t RESERVED14;
  __IO  uint32_t FSM_WR_ENA;                    /*!< Internal                                                           */
  __I   uint32_t FSM_ACC_PP;                    /*!< Internal                                                           */
  __I   uint32_t FSM_ACC_EP;                    /*!< Internal                                                           */
  __I   uint32_t RESERVED15[3];
  __I   uint32_t FSM_ADDR;                      /*!< Internal                                                           */
  __IO  uint32_t FSM_SECTOR;                    /*!< Internal                                                           */
  __I   uint32_t FMC_REV_ID;                    /*!< Internal                                                           */
  __I   uint32_t FSM_ERR_ADDR;                  /*!< Internal                                                           */
  __I   uint32_t FSM_PGM_MAXPUL;                /*!< Internal                                                           */
  __IO  uint32_t FSM_EXECUTE;                   /*!< Internal                                                           */
  __I   uint32_t RESERVED16[2];
  __IO  uint32_t FSM_SECTOR1;                   /*!< Internal                                                           */
  __IO  uint32_t FSM_SECTOR2;                   /*!< Internal                                                           */
  __I   uint32_t RESERVED17[6];
  __IO  uint32_t FSM_BSLE[2];                   /*!< Internal                                                           */
  __I   uint32_t RESERVED18[2];
  __IO  uint32_t FSM_BSLP[2];                   /*!< Internal                                                           */
  __I   uint32_t RESERVED19[66];
  __I   uint32_t FCFG_BANK;                     /*!< Internal                                                           */
  __I   uint32_t FCFG_WRAPPER;                  /*!< Internal                                                           */
  __I   uint32_t FCFG_BNK_TYPE;                 /*!< Internal                                                           */
  __I   uint32_t RESERVED20;
  __I   uint32_t FCFG_B_START[8];               /*!< Internal                                                           */
  __I   uint32_t FCFG_B0_SSIZE0;                /*!< Internal                                                           */
} FLASH_Type;


/******************************************************************************/
/*                                                                            */
/*                                VIMS                                        */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I   uint32_t STAT;                          /*!< Status                                                             */
  __IO  uint32_t CTL;                           /*!< Control                                                            */
} VIMS_Type;


/******************************************************************************/
/*                                                                            */
/*                                CCFG                                        */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I   uint32_t RESERVED0[1002];
  __I   uint32_t EXT_LF_CLK;                    /*!< Extern LF clock configuration                                      */
  __I   uint32_t MODE_CONF_1;                   /*!< Mode Configuration 1                                               */
  __I   uint32_t SIZE_AND_DIS_FLAGS;            /*!< CCFG Size and Disable Flags                                        */
  __I   uint32_t MODE_CONF;                     /*!< Mode Configuration 0                                               */
  __I   uint32_t VOLT_LOAD[2];                  /*!< Voltage Load                                                       */
  __I   uint32_t RTC_OFFSET;                    /*!< Real Time Clock Offset                                             */
  __I   uint32_t FREQ_OFFSET;                   /*!< Frequency Offset                                                   */
  __I   uint32_t IEEE_MAC[2];                   /*!< IEEE MAC Address                                                   */
  __I   uint32_t IEEE_BLE[2];                   /*!< IEEE BLE Address                                                   */
  __I   uint32_t BL_CONFIG;                     /*!< Bootloader Configuration                                           */
  __I   uint32_t ERASE_CONF;                    /*!< Erase Configuration                                                */
  __I   uint32_t CCFG_TI_OPTIONS;               /*!< TI Options                                                         */
  __I   uint32_t CCFG_TAP_DAP_0;                /*!< Test Access Points Enable 0                                        */
  __I   uint32_t CCFG_TAP_DAP_1;                /*!< Test Access Points Enable 1                                        */
  __I   uint32_t IMAGE_VALID_CONF;              /*!< Image Valid                                                        */
  __I   uint32_t CCFG_PROT[4];                  /*!< Protect Sectors                                                    */
} CCFG_Type;


/******************************************************************************/
/*                                                                            */
/*                               FCFG1                                        */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I   uint32_t RESERVED0[40];
  __I   uint32_t MISC_CONF_1;                   /*!< Misc configurations                                                */
  __I   uint32_t MISC_CONF_2;                   /*!< Internal                                                           */
  __I   uint32_t RESERVED1[7];
  __I   uint32_t CONFIG_RF_FRONTEND_DIV5;       /*!< Internal                                                           */
  __I   uint32_t CONFIG_RF_FRONTEND_DIV6;       /*!< Internal                                                           */
  __I   uint32_t CONFIG_RF_FRONTEND_DIV10;      /*!< Internal                                                           */
  __I   uint32_t CONFIG_RF_FRONTEND_DIV12;      /*!< Internal                                                           */
  __I   uint32_t CONFIG_RF_FRONTEND_DIV15;      /*!< Internal                                                           */
  __I   uint32_t CONFIG_RF_FRONTEND_DIV30;      /*!< Internal                                                           */
  __I   uint32_t CONFIG_SYNTH_DIV5;             /*!< Internal                                                           */
  __I   uint32_t CONFIG_SYNTH_DIV6;             /*!< Internal                                                           */
  __I   uint32_t CONFIG_SYNTH_DIV10;            /*!< Internal                                                           */
  __I   uint32_t CONFIG_SYNTH_DIV12;            /*!< Internal                                                           */
  __I   uint32_t CONFIG_SYNTH_DIV15;            /*!< Internal                                                           */
  __I   uint32_t CONFIG_SYNTH_DIV30;            /*!< Internal                                                           */
  __I   uint32_t CONFIG_MISC_ADC_DIV5;          /*!< Internal                                                           */
  __I   uint32_t CONFIG_MISC_ADC_DIV6;          /*!< Internal                                                           */
  __I   uint32_t CONFIG_MISC_ADC_DIV10;         /*!< Internal                                                           */
  __I   uint32_t CONFIG_MISC_ADC_DIV12;         /*!< Internal                                                           */
  __I   uint32_t CONFIG_MISC_ADC_DIV15;         /*!< Internal                                                           */
  __I   uint32_t CONFIG_MISC_ADC_DIV30;         /*!< Internal                                                           */
  __I   uint32_t RESERVED2[3];
  __I   uint32_t SHDW_DIE_ID[4];                /*!< Shadow of [JTAG_TAP::EFUSE:DIE_ID]                                 */
  __I   uint32_t RESERVED3[4];
  __I   uint32_t SHDW_OSC_BIAS_LDO_TRIM;        /*!< Internal                                                           */
  __I   uint32_t SHDW_ANA_TRIM;                 /*!< Internal                                                           */
  __I   uint32_t RESERVED4[9];
  __I   uint32_t FLASH_NUMBER;
  __I   uint32_t RESERVED5;
  __I   uint32_t FLASH_COORDINATE;
  __I   uint32_t FLASH_E_P;                     /*!< Internal                                                           */
  __I   uint32_t FLASH_C_E_P_R;                 /*!< Internal                                                           */
  __I   uint32_t FLASH_P_R_PV;                  /*!< Internal                                                           */
  __I   uint32_t FLASH_EH_SEQ;                  /*!< Internal                                                           */
  __I   uint32_t FLASH_VHV_E;                   /*!< Internal                                                           */
  __I   uint32_t FLASH_PP;                      /*!< Internal                                                           */
  __I   uint32_t FLASH_PROG_EP;                 /*!< Internal                                                           */
  __I   uint32_t FLASH_ERA_PW;                  /*!< Internal                                                           */
  __I   uint32_t FLASH_VHV;                     /*!< Internal                                                           */
  __I   uint32_t FLASH_VHV_PV;                  /*!< Internal                                                           */
  __I   uint32_t FLASH_V;                       /*!< Internal                                                           */
  __I   uint32_t RESERVED6[62];
  __I   uint32_t USER_ID;                       /*!< User Identification.                                               */
  __I   uint32_t RESERVED7[6];
  __I   uint32_t FLASH_OTP_DATA3;               /*!< Internal                                                           */
  __I   uint32_t ANA2_TRIM;                     /*!< Internal                                                           */
  __I   uint32_t LDO_TRIM;                      /*!< Internal                                                           */
  __I   uint32_t RESERVED8[11];
  __I   uint32_t MAC_BLE[2];                    /*!< MAC BLE Address                                                    */
  __I   uint32_t MAC_15_4[2];                   /*!< MAC IEEE 802.15.4 Address                                          */
  __I   uint32_t RESERVED9[4];
  __I   uint32_t FLASH_OTP_DATA4;               /*!< Internal                                                           */
  __I   uint32_t MISC_TRIM;                     /*!< Miscellaneous Trim Parameters                                      */
  __I   uint32_t RCOSC_HF_TEMPCOMP;             /*!< Internal                                                           */
  __I   uint32_t RESERVED10;
  __I   uint32_t ICEPICK_DEVICE_ID;             /*!< IcePick Device Identification                                      */
  __I   uint32_t FCFG1_REVISION;                /*!< Factory Configuration (FCFG1) Revision                             */
  __I   uint32_t MISC_OTP_DATA;                 /*!< Misc OTP Data                                                      */
  __I   uint32_t RESERVED11[8];
  __I   uint32_t IOCONF;                        /*!< IO Configuration                                                   */
  __I   uint32_t RESERVED12;
  __I   uint32_t CONFIG_IF_ADC;                 /*!< Internal                                                           */
  __I   uint32_t CONFIG_OSC_TOP;                /*!< Internal                                                           */
  __I   uint32_t CONFIG_RF_FRONTEND;            /*!< Internal                                                           */
  __I   uint32_t CONFIG_SYNTH;                  /*!< Internal                                                           */
  __I   uint32_t SOC_ADC_ABS_GAIN;              /*!< AUX_ADC Gain in Absolute Reference Mode                            */
  __I   uint32_t SOC_ADC_REL_GAIN;              /*!< AUX_ADC Gain in Relative Reference Mode                            */
  __I   uint32_t RESERVED13;
  __I   uint32_t SOC_ADC_OFFSET_INT;            /*!< AUX_ADC Temperature Offsets in Absolute Reference Mode             */
  __I   uint32_t SOC_ADC_REF_TRIM_AND_OFFSET_EXT;/*!< Internal                                                          */
  __I   uint32_t AMPCOMP_TH1;                   /*!< Internal                                                           */
  __I   uint32_t AMPCOMP_TH2;                   /*!< Internal                                                           */
  __I   uint32_t AMPCOMP_CTRL1;                 /*!< Internal                                                           */
  __I   uint32_t ANABYPASS_VALUE2;              /*!< Internal                                                           */
  __I   uint32_t CONFIG_MISC_ADC;               /*!< Internal                                                           */
  __I   uint32_t RESERVED14;
  __I   uint32_t VOLT_TRIM;                     /*!< Internal                                                           */
  __I   uint32_t OSC_CONF;                      /*!< OSC Configuration                                                  */
  __I   uint32_t FREQ_OFFSET;                   /*!< Internal                                                           */
  __I   uint32_t CAP_TRIM;                      /*!< Internal                                                           */
  __I   uint32_t MISC_OTP_DATA_1;               /*!< Internal                                                           */
  __I   uint32_t PWD_CURR_20C;                  /*!< Power Down Current Control 20C                                     */
  __I   uint32_t PWD_CURR_35C;                  /*!< Power Down Current Control 35C                                     */
  __I   uint32_t PWD_CURR_50C;                  /*!< Power Down Current Control 50C                                     */
  __I   uint32_t PWD_CURR_65C;                  /*!< Power Down Current Control 65C                                     */
  __I   uint32_t PWD_CURR_80C;                  /*!< Power Down Current Control 80C                                     */
  __I   uint32_t PWD_CURR_95C;                  /*!< Power Down Current Control 95C                                     */
  __I   uint32_t PWD_CURR_110C;                 /*!< Power Down Current Control 110C                                    */
  __I   uint32_t PWD_CURR_125C;                 /*!< Power Down Current Control 125C                                    */
} FCFG1_Type;


/******************************************************************************/
/*                                                                            */
/*                               CRYPTO                                       */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t DMACH_CTL;                     /*!< DMA Channel Control                                                */
  __IO  uint32_t DMACH_EXTADDR;                 /*!< DMA Channel External Address                                       */
  __I   uint32_t RESERVED0;
  __IO  uint32_t DMACH_LEN;                     /*!< DMA Channel Length                                                 */
  __I   uint32_t RESERVED1[2];
} CRYPTO_DMA_TypeDef;

typedef union
{
  __I   uint32_t DATA_OUT;                      /*!< AES Data Output                                                    */
  __O   uint32_t DATA_IN ;                      /*!< AES Data Input                                                     */
} CRYPTO_DATA_TypeDef;

typedef struct
{
  CRYPTO_DMA_TypeDef DMA0;                      /*!< DMA Channel 0                                                      */
  __I   uint32_t DMASTAT;                       /*!< DMA Controller Status                                              */
  __O   uint32_t DMASWRESET;                    /*!< DMA Controller Software Reset                                      */
  CRYPTO_DMA_TypeDef DMA1;                      /*!< DMA Channel 1                                                      */
  __I   uint32_t RESERVED0[16];
  __IO  uint32_t DMABUSCFG;                     /*!< DMA Controller Master Configuration                                */
  __I   uint32_t DMAPORTERR;                    /*!< DMA Controller Port Error                                          */
  __I   uint32_t RESERVED1[31];
  __I   uint32_t DMAHWVER;                      /*!< DMA Controller Version                                             */
  __I   uint32_t RESERVED2[192];
  __IO  uint32_t KEYWRITEAREA;                  /*!< Key Write Area                                                     */
  __IO  uint32_t KEYWRITTENAREA;                /*!< Key Written Area Status                                            */
  __IO  uint32_t KEYSIZE;                       /*!< Key Size                                                           */
  __IO  uint32_t KEYREADAREA;                   /*!< Key Read Area                                                      */
  __I   uint32_t RESERVED3[60];
  __O   uint32_t AESKEY2[4];                    /*!< Clear AES_KEY2/GHASH Key                                           */
  __O   uint32_t AESKEY3[4];                    /*!< Clear AES_KEY3                                                     */
  __I   uint32_t RESERVED4[8];
  __IO  uint32_t AESIV[4];                      /*!< AES Initialization Vector                                          */
  __IO  uint32_t AESCTL;                        /*!< AES Input/Output Buffer Control                                    */
  __O   uint32_t AESDATALEN[2];                 /*!< Crypto Data Length                                                 */
  __O   uint32_t AESAUTHLEN;                    /*!< AES Authentication Length                                          */
  CRYPTO_DATA_TypeDef DATA[4];                  /*!< AES Data Input/Output                                              */
  __I   uint32_t AESTAGOUT[4];                  /*!< AES Tag Output                                                     */
  __I   uint32_t RESERVED5[96];
  __IO  uint32_t ALGSEL;                        /*!< Master Algorithm Select                                            */
  __IO  uint32_t DMAPROTCTL;                    /*!< Master Protection Control                                          */
  __I   uint32_t RESERVED6[14];
  __IO  uint32_t SWRESET;                       /*!< Software Reset                                                     */
  __I   uint32_t RESERVED7[15];
  __IO  uint32_t IRQTYPE;                       /*!< Interrupt Configuration                                            */
  __IO  uint32_t IRQEN;                         /*!< Interrupt Enable                                                   */
  __O   uint32_t IRQCLR;                        /*!< Interrupt Clear                                                    */
  __O   uint32_t IRQSET;                        /*!< Interrupt Set                                                      */
  __I   uint32_t IRQSTAT;                       /*!< Interrupt Status                                                   */
  __I   uint32_t RESERVED8[26];
  __I   uint32_t HWVER;                         /*!< CTRL Module Version                                                */
} CRYPTO_Type;


/******************************************************************************/
/*                                                                            */
/*                              AON_IOC                                       */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t IOSTRMIN;                      /*!< Internal                                                           */
  __IO  uint32_t IOSTRMED;                      /*!< Internal                                                           */
  __IO  uint32_t IOSTRMAX;                      /*!< Internal                                                           */
  __IO  uint32_t IOCLATCH;                      /*!< IO Latch Control                                                   */
  __IO  uint32_t CLK32KCTL;                     /*!< SCLK_LF External Output Control                                    */
} AON_IOC_Type;


/******************************************************************************/
/*                                                                            */
/*                                GPIO                                        */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __O   uint32_t DOUT_BIT_BANG[8];              /*!< Data Output (big bang)                                             */
  __I   uint32_t RESERVED0[24];
  __IO  uint32_t DOUT;                          /*!< Data Output                                                        */
  __I   uint32_t RESERVED1[3];
  __O   uint32_t DOUTSET;                       /*!< Data Out Set                                                       */
  __I   uint32_t RESERVED2[3];
  __O   uint32_t DOUTCLR;                       /*!< Data Out Clear                                                     */
  __I   uint32_t RESERVED3[3];
  __O   uint32_t DOUTTGL;                       /*!< Data Out Toggle                                                    */
  __I   uint32_t RESERVED4[3];
  __I   uint32_t DIN;                           /*!< Data Input                                                         */
  __I   uint32_t RESERVED5[3];
  __IO  uint32_t DOE;                           /*!< Data Output Enable                                                 */
  __I   uint32_t RESERVED6[3];
  __IO  uint32_t EVFLAGS;                       /*!< Event Register                                                     */
} GPIO_Type;


/******************************************************************************/
/*                                                                            */
/*                                IOC                                         */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t IOCFG[32];                     /*!< Configuration of DIO                                               */
} IOC_Type;


/******************************************************************************/
/*                                                                            */
/*                               uDMA                                         */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I   uint32_t STATUS;                        /*!< Status                                                             */
  __O   uint32_t CFG;                           /*!< Configuration                                                      */
  __IO  uint32_t CTRL;                          /*!< Channel Control Data Base Pointer                                  */
  __I   uint32_t ALTCTRL;                       /*!< Channel Alternate Control Data Base Pointer                        */
  __I   uint32_t WAITONREQ;                     /*!< Channel Wait On Request Status                                     */
  __O   uint32_t SOFTREQ;                       /*!< Channel Software Request                                           */
  __O   uint32_t SETBURST;                      /*!< Channel Set UseBurst                                               */
  __IO  uint32_t CLEARBURST;                    /*!< Channel Clear UseBurst                                             */
  __IO  uint32_t SETREQMASK;                    /*!< Channel Set Request Mask                                           */
  __O   uint32_t CLEARREQMASK;                  /*!< Clear Channel Request Mask                                         */
  __IO  uint32_t SETCHANNELEN;                  /*!< Set Channel Enable                                                 */
  __O   uint32_t CLEARCHANNELEN;                /*!< Clear Channel Enable                                               */
  __IO  uint32_t SETCHNLPRIALT;                 /*!< Channel Set Primary-Alternate                                      */
  __O   uint32_t CLEARCHNLPRIALT;               /*!< Channel Clear Primary-Alternate                                    */
  __IO  uint32_t SETCHNLPRIORITY;               /*!< Set Channel Priority                                               */
  __O   uint32_t CLEARCHNLPRIORITY;             /*!< Clear Channel Priority                                             */
  __I   uint32_t RESERVED0[3];
  __IO  uint32_t ERROR;                         /*!< Error Status and Clear                                             */
  __I   uint32_t RESERVED1[301];
  __IO  uint32_t REQDONE;                       /*!< Channel Request Done                                               */
  __I   uint32_t RESERVED2[6];
  __IO  uint32_t DONEMASK;                      /*!< Channel Request Done Mask                                          */
} uDMA_Type;


/******************************************************************************/
/*                                                                            */
/*                                GPT                                         */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t CFG;                           /*!< Configuration                                                      */
  __IO  uint32_t TAMR;                          /*!< Timer A Mode                                                       */
  __IO  uint32_t TBMR;                          /*!< Timer B Mode                                                       */
  __IO  uint32_t CTL;                           /*!< Control                                                            */
  __O   uint32_t SYNC;                          /*!< Synch Register                                                     */
  __I   uint32_t RESERVED0;
  __IO  uint32_t IMR;                           /*!< Interrupt Mask                                                     */
  __I   uint32_t RIS;                           /*!< Raw Interrupt Status                                               */
  __I   uint32_t MIS;                           /*!< Masked Interrupt Status                                            */
  __IO  uint32_t ICLR;                          /*!< Interrupt Clear                                                    */
  __IO  uint32_t TAILR;                         /*!< Timer A Interval Load Register                                     */
  __IO  uint32_t TBILR;                         /*!< Timer B Interval Load Register                                     */
  __IO  uint32_t TAMATCHR;                      /*!< Timer A Match Register                                             */
  __IO  uint32_t TBMATCHR;                      /*!< Timer B Match Register                                             */
  __IO  uint32_t TAPR;                          /*!< Timer A Pre-scale                                                  */
  __IO  uint32_t TBPR;                          /*!< Timer B Pre-scale                                                  */
  __IO  uint32_t TAPMR;                         /*!< Timer A Pre-scale Match                                            */
  __IO  uint32_t TBPMR;                         /*!< Timer B Pre-scale Match                                            */
  __I   uint32_t TAR;                           /*!< Timer A Register                                                   */
  __I   uint32_t TBR;                           /*!< Timer B Register                                                   */
  __IO  uint32_t TAV;                           /*!< Timer A Value                                                      */
  __IO  uint32_t TBV;                           /*!< Timer B Value                                                      */
  __I   uint32_t RESERVED1;
  __I   uint32_t TAPS;                          /*!< Timer A Pre-scale Snap-shot                                        */
  __I   uint32_t TBPS;                          /*!< Timer B Pre-scale Snap-shot                                        */
  __I   uint32_t TAPV;                          /*!< Timer A Pre-scale Value                                            */
  __I   uint32_t TBPV;                          /*!< Timer B Pre-scale Value                                            */
  __IO  uint32_t DMAEV;                         /*!< DMA Event                                                          */
  __I   uint32_t RESERVED2[976];
  __I   uint32_t VERSION;                       /*!< Peripheral Version                                                 */
  __IO  uint32_t ANDCCP;                        /*!< Combined CCP Output                                                */
} GPT_Type;


/******************************************************************************/
/*                                                                            */
/*                               AON_RTC                                      */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t CTL;                           /*!< Control                                                            */
  __IO  uint32_t EVFLAGS;                       /*!< Event Flags, RTC Status                                            */
  __IO  uint32_t SEC;                           /*!< Second Counter Value, Integer Part                                 */
  __IO  uint32_t SUBSEC;                        /*!< Second Counter Value, Fractional Part                              */
  __I   uint32_t SUBSECINC;                     /*!< Subseconds Increment                                               */
  __IO  uint32_t CHCTL;                         /*!< Channel Configuration                                              */
  __IO  uint32_t CH0CMP;                        /*!< Channel 0 Compare Value                                            */
  __IO  uint32_t CH1CMP;                        /*!< Channel 1 Compare Value                                            */
  __IO  uint32_t CH2CMP;                        /*!< Channel 2 Compare Value                                            */
  __IO  uint32_t CH2CMPINC;                     /*!< Channel 2 Compare Value Auto-increment                             */
  __I   uint32_t CH1CAPT;                       /*!< Channel 1 Capture Value                                            */
  __IO  uint32_t SYNC;                          /*!< AON Synchronization                                                */
} AON_RTC_Type;


/******************************************************************************/
/*                                                                            */
/*                                  WDT                                       */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t LOAD;                          /*!< Configuration                                                      */
  __I   uint32_t VALUE;                         /*!< Current Count Value                                                */
  __IO  uint32_t CTL;                           /*!< Control                                                            */
  __O   uint32_t ICR;                           /*!< Interrupt Clear                                                    */
  __I   uint32_t RIS;                           /*!< Raw Interrupt Status                                               */
  __I   uint32_t MIS;                           /*!< Masked Interrupt Status                                            */
  __I   uint32_t RESERVED0[256];
  __IO  uint32_t TEST;                          /*!< Test Mode                                                          */
  __I   uint32_t INT_CAUS;                      /*!< Interrupt Cause Test Mode                                          */
  __I   uint32_t RESERVED1[504];
  __IO  uint32_t LOCK;                          /*!< Lock                                                               */
} WDT_Type;


/******************************************************************************/
/*                                                                            */
/*                                 TRNG                                       */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I   uint32_t OUT[2];                        /*!< Random Number Readout Value                                        */
  __I   uint32_t IRQFLAGSTAT;                   /*!< Interrupt Status                                                   */
  __IO  uint32_t IRQFLAGMASK;                   /*!< Interrupt Mask                                                     */
  __O   uint32_t IRQFLAGCLR;                    /*!< Interrupt Flag Clear                                               */
  __IO  uint32_t CTL;                           /*!< Control                                                            */
  __IO  uint32_t CFG0;                          /*!< Configuration 0                                                    */
  __IO  uint32_t ALARMCNT;                      /*!< Alarm Control                                                      */
  __IO  uint32_t FROEN;                         /*!< FRO Enable                                                         */
  __IO  uint32_t FRODETUNE;                     /*!< FRO De-tune Bit                                                    */
  __IO  uint32_t ALARMMASK;                     /*!< Alarm Event                                                        */
  __IO  uint32_t ALARMSTOP;                     /*!< Alarm Shutdown                                                     */
  __IO  uint32_t LFSR[3];                       /*!< LFSR Readout Value                                                 */
  __I   uint32_t RESERVED0[15];
  __I   uint32_t HWOPT;                         /*!< TRNG Engine Options Information                                    */
  __I   uint32_t HWVER0;                        /*!< HW Version 0                                                       */
  __I   uint32_t RESERVED1[2006];
  __I   uint32_t IRQSTATMASK;                   /*!< Interrupt Status After Masking                                     */
  __I   uint32_t RESERVED2;
  __I   uint32_t HWVER1;                        /*!< HW Version 1                                                       */
  __I   uint32_t RESERVED3[2];
  __IO  uint32_t IRQSET;                        /*!< Interrupt Set                                                      */
  __IO  uint32_t SWRESET;                       /*!< SW Reset Control                                                   */
  __I   uint32_t RESERVED4;
  __I  uint32_t IRQSTAT;                        /*!< Interrupt Status                                                   */
} TRNG_Type;


/******************************************************************************/
/*                                                                            */
/*                                AUX_ADI4                                    */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint8_t MUX0;                           /*!< Internal                                                           */
  __IO  uint8_t MUX1;                           /*!< Internal                                                           */
  __IO  uint8_t MUX2;                           /*!< Internal                                                           */
  __IO  uint8_t MUX3;                           /*!< Internal                                                           */
  __IO  uint8_t ISRC;                           /*!< Current Source                                                     */
  __IO  uint8_t COMP;                           /*!< Comparator                                                         */
  __I   uint8_t RESERVED0;
  __IO  uint8_t MUX4;                           /*!< Internal                                                           */
  __IO  uint8_t ADC0;                           /*!< ADC Control 0                                                      */
  __IO  uint8_t ADC1;                           /*!< ADC Control 1                                                      */
  __IO  uint8_t ADCREF0;                        /*!< ADC Reference 0                                                    */
  __IO  uint8_t ADCREF1;                        /*!< ADC Reference 1                                                    */
} AUX_ADI4_Type;


/******************************************************************************/
/*                                                                            */
/*                                 AUX_AIODIO                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t GPIODOUT;                      /*!< General Purpose Input/Output Data Out                              */
  __IO  uint32_t IOMODE;                        /*!< Input Output Mode                                                  */
  __I   uint32_t GPIODIN;                       /*!< General Purpose Input Output Data In                               */
  __IO  uint32_t GPIODOUTSET;                   /*!< General Purpose Input Output Data Out Set                          */
  __IO  uint32_t GPIODOUTCLR;                   /*!< General Purpose Input Output Data Out Clear                        */
  __IO  uint32_t GPIODOUTTGL;                   /*!< General Purpose Input Output Data Out Toggle                       */
  __IO  uint32_t GPIODIE;                       /*!< General Purpose Input Output Input Enable                          */
} AUX_AIODIO_Type;


/******************************************************************************/
/*                                                                            */
/*                                  AUX_EVCTL                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t VECCFG[2];                     /*!< Vector Configuration                                               */
  __IO  uint32_t SCEWEVSEL;                     /*!< Sensor Controller Engine Wait Event Selection                      */
  __IO  uint32_t EVTOAONFLAGS;                  /*!< Events To AON Domain Flags                                         */
  __IO  uint32_t EVTOAONPOL;                    /*!< Events To AON Domain Polarity                                      */
  __IO  uint32_t DMACTL;                        /*!< Direct Memory Access Control                                       */
  __O   uint32_t SWEVSET;                       /*!< Software Event Set                                                 */
  __I   uint32_t EVSTAT0;                       /*!< Event Status 0                                                     */
  __I   uint32_t EVSTAT1;                       /*!< Event Status 1                                                     */
  __IO  uint32_t EVTOMCUPOL;                    /*!< Event To MCU Domain Polarity                                       */
  __IO  uint32_t EVTOMCUFLAGS;                  /*!< Events to MCU Domain Flags                                         */
  __IO  uint32_t COMBEVTOMCUMASK;               /*!< Combined Event To MCU Domain Mask                                  */
  __I   uint32_t RESERVED0;
  __IO  uint32_t VECFLAGS;                      /*!< Vector Flags                                                       */
  __O   uint32_t EVTOMCUFLAGSCLR;               /*!< Events To MCU Domain Flags Clear                                   */
  __O   uint32_t EVTOAONFLAGSCLR;               /*!< Events To AON Domain Clear                                         */
  __O   uint32_t VECFLAGSCLR;                   /*!< Vector Flags Clear                                                 */
} AUX_EVCTL_Type;


/******************************************************************************/
/*                                                                            */
/*                                  AUX_SMPH                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t SMPH[8];                       /*!< Semaphore                                                          */
  __IO  uint32_t AUTOTAKE;                      /*!< Sticky Request For Single Semaphore                                */
} AUX_SMPH_Type;

/******************************************************************************/
/*                                                                            */
/*                                   AUX_TDC                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __O   uint32_t CTL;                           /*!< Control                                                            */
  __I   uint32_t STAT;                          /*!< Status                                                             */
  __I   uint32_t RESULT;                        /*!< Result                                                             */
  __IO  uint32_t SATCFG;                        /*!< Saturation Configuration                                           */
  __IO  uint32_t TRIGSRC;                       /*!< Trigger Source                                                     */
  __IO  uint32_t TRIGCNT;                       /*!< Trigger Counter                                                    */
  __IO  uint32_t TRIGCNTLOAD;                   /*!< Trigger Counter Load                                               */
  __IO  uint32_t TRIGCNTCFG;                    /*!< Trigger Counter Configuration                                      */
  __IO  uint32_t PRECTL;                        /*!< Prescaler Control                                                  */
  __IO  uint32_t PRECNT;                        /*!< Prescaler Counter                                                  */
} AUX_TDC_Type;


/******************************************************************************/
/*                                                                            */
/*                                  AUX_TIMER                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t TCFG[2];                       /*!< Timer Configuration                                                */
  __IO  uint32_t T0CTL;                         /*!< Timer 0 Control                                                    */
  __IO  uint32_t TTARGET[2];                    /*!< Timer Target                                                       */
  __IO  uint32_t T1CTL;                         /*!< Timer 1 Control                                                    */
} AUX_TIMER_Type;


/******************************************************************************/
/*                                                                            */
/*                                   AUX_WUC                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t MODCLKEN0;                     /*!< Module Clock Enable                                                */
  __IO  uint32_t PWROFFREQ;                     /*!< Power Off Request                                                  */
  __IO  uint32_t PWRDWNREQ;                     /*!< Power Down Request                                                 */
  __I   uint32_t PWRDWNACK;                     /*!< Power Down Acknowledgment                                          */
  __IO  uint32_t CLKLFREQ;                      /*!< Low Frequency Clock Request                                        */
  __I   uint32_t CLKLFACK;                      /*!< Low Frequency Clock Acknowledgment                                 */
  __I   uint32_t RESERVED0[4];
  __I   uint32_t WUEVFLAGS;                     /*!< Wake-up Event Flags                                                */
  __IO  uint32_t WUEVCLR;                       /*!< Wake-up Event Clear                                                */
  __IO  uint32_t ADCCLKCTL;                     /*!< ADC Clock Control                                                  */
  __IO  uint32_t TDCCLKCTL;                     /*!< TDC Clock Control                                                  */
  __IO  uint32_t REFCLKCTL;                     /*!< Reference Clock Control                                            */
  __IO  uint32_t RTCSUBSECINC[2];               /*!< Real Time Counter Sub Second Increment                             */
  __IO  uint32_t RTCSUBSECINCCTL;               /*!< Real Time Counter Sub Second Increment Control                     */
  __IO  uint32_t MCUBUSCTL;                     /*!< MCU Bus Control                                                    */
  __I   uint32_t MCUBUSSTAT;                    /*!< MCU Bus Status                                                     */
  __I   uint32_t AONCTLSTAT;                    /*!< AON Domain Control Status                                          */
  __IO  uint32_t AUXIOLATCH;                    /*!< AUX Input Output Latch                                             */
  __I   uint32_t RESERVED1;
  __IO  uint32_t MODCLKEN1;                     /*!< Module Clock Enable 1                                              */
} AUX_WUC_Type;


/******************************************************************************/
/*                                                                            */
/*                                  AUX_ANAIF                                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I   uint32_t RESERVED0[4];
  __IO  uint32_t ADCCTL;                        /*!< ADC Control                                                        */
  __I   uint32_t ADCFIFOSTAT;                   /*!< ADC FIFO Status                                                    */
  __IO  uint32_t ADCFIFO;                       /*!< ADC FIFO                                                           */
  __O   uint32_t ADCTRIG;                       /*!< ADC Trigger                                                        */
  __IO  uint32_t ISRCCTL;                       /*!< Current Source Control                                             */
} AUX_ANAIF_Type;


/******************************************************************************/
/*                                                                            */
/*                               AON_BATMON                                   */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO  uint32_t CTL;                           /*!< Internal                                                           */
  __IO  uint32_t MEASCFG;                       /*!< Internal                                                           */
  __I   uint32_t RESERVED0;
  __IO  uint32_t TEMPP[3];                      /*!< Internal                                                           */
  __IO  uint32_t BATMONP[2];                    /*!< Internal                                                           */
  __IO  uint32_t IOSTRP0;                       /*!< Internal                                                           */
  __IO  uint32_t FLASHPUMPP0;                   /*!< Internal                                                           */
  __I   uint32_t BAT;                           /*!< Last Measured Battery Voltage                                      */
  __IO  uint32_t BATUPD;                        /*!< Battery Update                                                     */
  __I   uint32_t TEMP;                          /*!< Temperature                                                        */
  __IO  uint32_t TEMPUPD;                       /*!< Temperature Update                                                 */
} AON_BATMON_Type;


/******************************************************************************/
/*                                                                            */
/*                                  USART                                     */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t DR;                             /*!< Data                                                               */
  union {
    __I  uint32_t RSR;                          /*!< Status                                                             */
    __O  uint32_t ECR;                          /*!< Error Clear                                                        */
  };
  __I   uint32_t RESERVED0[4];
  __I  uint32_t FR;                             /*!< Flag                                                               */
  __I   uint32_t RESERVED1[2];
  __IO uint32_t IBRD;                           /*!< Integer Baud-Rate Divisor                                          */
  __IO uint32_t FBRD;                           /*!< Fractional Baud-Rate Divisor                                       */
  __IO uint32_t LCRH;                           /*!< Line Control                                                       */
  __IO uint32_t CTL;                            /*!< Control                                                            */
  __IO uint32_t IFLS;                           /*!< Interrupt FIFO Level Select                                        */
  __IO uint32_t IMSC;                           /*!< Interrupt Mask Set/Clear                                           */
  __I  uint32_t RIS;                            /*!< Raw Interrupt Status                                               */
  __I  uint32_t MIS;                            /*!< Masked Interrupt Status                                            */
  __O  uint32_t ICR;                            /*!< Interrupt Clear                                                    */
  __IO uint32_t DMACTL;                         /*!< DMA Control                                                        */
} USART_Type;


/******************************************************************************/
/*                                                                            */
/*                                   SSI                                      */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CR0;                            /*!< Control 0                                                          */
  __IO uint32_t CR1;                            /*!< Control 1                                                          */
  __IO uint32_t DR;                             /*!< Data                                                               */
  __I  uint32_t SR;                             /*!< Status                                                             */
  __IO uint32_t CPSR;                           /*!< Clock Prescale                                                     */
  __IO uint32_t IMSC;                           /*!< Interrupt Mask Set and Clear                                       */
  __I  uint32_t RIS;                            /*!< Raw Interrupt Status                                               */
  __I  uint32_t MIS;                            /*!< Masked Interrupt Status                                            */
  __O  uint32_t ICR;                            /*!< Interrupt Clear                                                    */
  __IO uint32_t DMACR;                          /*!< DMA Control                                                        */
} SSI_Type;


/******************************************************************************/
/*                                                                            */
/*                                   I2C                                      */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t SOAR;                           /*!< Slave Own Address                                                  */
  union {
    __I  uint32_t SSTAT;                        /*!< Slave Status                                                       */
    __O  uint32_t SCTL;                         /*!< Slave Control                                                      */
  };
  __IO uint32_t SDR;                            /*!< Slave Data                                                         */
  __IO uint32_t SIMR;                           /*!< Slave Interrupt Mask                                               */
  __I uint32_t SRIS;                            /*!< Slave Raw Interrupt Status                                         */
  __I uint32_t SMIS;                            /*!< Slave Masked Interrupt Status                                      */
  __O  uint32_t SICR;                           /*!< Slave Interrupt Clear                                              */
  __I   uint32_t RESERVED0[505];
  __IO uint32_t MSA;                            /*!< Master Salve Address                                               */
  union {
    __I  uint32_t MSTAT;                        /*!< Master Status                                                      */
    __O  uint32_t MCTRL;                        /*!< Master Control                                                     */
  };
  __IO uint32_t MDR;                            /*!< Master Data                                                        */
  __IO uint32_t MTPR;                           /*!< I2C Master Timer Period                                            */
  __IO uint32_t MIMR;                           /*!< Master Interrupt Mask                                              */
  __I  uint32_t MRIS;                           /*!< Master Raw Interrupt Status                                        */
  __I  uint32_t MMIS;                           /*!< Master Masked Interrupt Status                                     */
  __O  uint32_t MICR;                           /*!< Master Interrupt Clear                                             */
  __IO uint32_t MCR;                            /*!< Master Configuration                                               */
} I2C_Type;


/******************************************************************************/
/*                                                                            */
/*                                   I2S                                      */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t AIFWCLKSRC;                     /*!< WCLK Source Selection                                              */
  __IO uint32_t AIFDMACFG;                      /*!< DMA Buffer Size Configuration                                      */
  __IO uint32_t AIFDIRCFG;                      /*!< Pin Direction                                                      */
  __IO uint32_t AIFFMTCFG;                      /*!< Serial Interface Format Configuration                              */
  __IO uint32_t AIFWMASK[3];                    /*!< Word Selection Bit Mask for Pin                                    */
  __IO uint32_t AIFPWMVALUE;                    /*!< Audio Interface PWM Debug Value                                    */
  __IO uint32_t AIFINPTRNEXT;                   /*!< DMA Input Buffer Next Pointer                                      */
  __IO uint32_t AIFINPTR;                       /*!< DMA Input Buffer Current Pointer                                   */
  __IO uint32_t AIFOUTPTRNEXT;                  /*!< DMA Output Buffer Next Pointer                                     */
  __IO uint32_t AIFOUTPTR;                      /*!< DMA Output Buffer Current Pointer                                  */
  __I   uint32_t RESERVED0;
  __IO uint32_t STMPCTL;                        /*!< SampleStaMP Generator Control Register                             */
  __I  uint32_t STMPXCNTCAPT0;                  /*!< Captured XOSC Counter Value, Capture Channel 0                     */
  __I  uint32_t STMPXPER;                       /*!< XOSC Period Value                                                  */
  __I  uint32_t STMPWCNTCAPT0;                  /*!< Captured WCLK Counter Value, Capture Channel 0                     */
  __IO uint32_t STMPWPER;                       /*!< WCLK Counter Period Value                                          */
  __IO uint32_t STMPINTRIG;                     /*!< WCLK Counter Trigger Value for Input Pins                          */
  __IO uint32_t STMPOUTTRIG;                    /*!< WCLK Counter Trigger Value for Output Pins                         */
  __IO uint32_t STMPWSET;                       /*!< WCLK Counter Set Operation                                         */
  __IO uint32_t STMPWADD;                       /*!< WCLK Counter Add Operation                                         */
  __IO uint32_t STMPXPERMIN;                    /*!< XOSC Minimum Period Value                                          */
  __I  uint32_t STMPWCNT;                       /*!< Current Value of WCNT                                              */
  __I  uint32_t STMPXCNT;                       /*!< Current Value of XCNT                                              */
  __I  uint32_t STMPXCNTCAPT1;                  /*!< Captured XOSC Counter Value, Capture Channel 1                     */
  __I  uint32_t STMPWCNTCAPT1;                  /*!< Captured WCLK Counter Value, Capture Channel 1                     */
  __I   uint32_t RESERVED1;
  __IO uint32_t IRQMASK;                        /*!< Masked Interrupt Status Register                                   */
  __I  uint32_t IRQFLAGS;                       /*!< Raw Interrupt Status Register                                      */
  __O  uint32_t IRQSET;                         /*!< Interrupt Set Register                                             */
  __O  uint32_t IRQCLR;                         /*!< Interrupt Clear Register                                           */
} I2S_Type;


/******************************************************************************/
/*                                                                            */
/*                                  RFC_RAT                                   */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __I   uint32_t RESERVED0;
  __IO uint32_t RATCNT;                         /*!< Radio Timer Counter Value                                          */
  __I   uint32_t RESERVED1[30];
  __IO uint32_t RATCHVAL[8];                    /*!< Timer Channel Capture/Compare Register                             */
} RFC_RAT_Type;


/******************************************************************************/
/*                                                                            */
/*                                 RFC_DBELL                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t CMDR;                           /*!< Doorbell Command Register                                          */
  __I  uint32_t CMDSTA;                         /*!< Doorbell Command Status Register                                   */
  __IO uint32_t RFHWIFG;                        /*!< Interrupt Flags From RF Hardware Modules                           */
  __IO uint32_t RFHWIEN;                        /*!< Interrupt Enable For RF Hardware Modules                           */
  __IO uint32_t RFCPEIFG;                       /*!< Interrupt Flags For Command and Packet Engine
                                                     Generated Interrupts                                               */
  __IO uint32_t RFCPEIEN;                       /*!< Interrupt Enable For Command and Packet Engine
                                                     Generated Interrupts                                               */
  __IO uint32_t RFCPEISL;                       /*!< Interrupt Vector Selection For Command and Packet
                                                     Engine Generated Interrupts                                        */
  __IO uint32_t RFACKIFG;                       /*!< Doorbell Command Acknowledgement Interrupt Flag                    */
  __IO uint32_t SYSGPOCTL;                      /*!< RF Core General Purpose Output Control                             */
} RFC_DBELL_Type;


/******************************************************************************/
/*                                                                            */
/*                                   RFC_PWR                                  */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  __IO uint32_t PWMCLKEN;                       /*!< RF Core Power Management and Clock Enable                          */
} RFC_PWR_Type;


/******************************************************************************/
/*                                                                            */
/*                           Peripheral declaration                           */
/*                                                                            */
/******************************************************************************/

#define AON_BATMON                              ((AON_BATMON_Type*)AON_BATMON_BASE)
#define AON_EVENT                               ((AON_EVENT_Type*)AON_EVENT_BASE)
#define AON_IOC                                 ((AON_IOC_Type*)AON_IOC_BASE)
#define AON_RTC                                 ((AON_RTC_Type*)AON_RTC_BASE)
#define AON_SYSCTL                              ((AON_SYSCTL_Type*)AON_SYSCTL_BASE)
#define AON_WUC                                 ((AON_WUC_Type*)AON_WUC_BASE)
#define AUX_ADI4                                ((AUX_ADI4_Type*)AUX_ADI4_BASE)
#define AUX_AIODIO0                             ((AUX_AIODIO_Type*)AUX_IODIO0_BASE)
#define AUX_AIODIO1                             ((AUX_AIODIO_Type*)AUX_IODIO1_BASE)
#define AUX_ANAIF                               ((AUX_ANAIF_Type*)AUX_ANAIF_BASE)
#define AUX_DDI0_OSC                            ((AUX_DDI0_OSC_Type*)AUX_DDI0_OSC_BASE)
#define AUX_EVCTL                               ((AUX_EVCTL_Type*)AUX_EVCTL_BASE)
#define AUX_SMPH                                ((AUX_MSPH_Type*)AUX_SMPH_BASE)
#define AUX_TDC                                 ((AUX_TDC_Type*)AUX_TDC_BASE)
#define AUX_TIMER                               ((AUX_TIMER_Type*)AUX_TIMER_BASE)
#define AUX_WUC                                 ((AUX_WUC_Type*)AUX_WUC_BASE)
#define CCFG                                    ((CCFG_Type*)CCFG_BASE)
#define FCFG1                                   ((FCFG1_Type*)FCFG1_BASE)
#define FLASH                                   ((FLASH_Type*)FLASH_BASE)
#define GPT0                                    ((GPT_Type*)GPT0_BASE)
#define GPT1                                    ((GPT_Type*)GPT1_BASE)
#define GPT2                                    ((GPT_Type*)GPT2_BASE)
#define GPT3                                    ((GPT_Type*)GPT3_BASE)
#define RFC_PWR                                 ((RFC_PWR_Type*)RFC_PWR_BASE)
#define RFC_DBELL                               ((RFC_DBELL_Type*)RFC_DBELL_BASE)
#define RFC_RAT                                 ((RFC_RAT_Type*)RFC_RAT_BASE)
#define CRYPTO                                  ((CRYPTO_Type*)CRYPTO_BASE)
#define EVENT                                   ((EVENT_Type*)EVENT_BASE)
#define GPIO                                    ((GPIO_Type*)GPIO_BASE)
#define I2C0                                    ((I2C_Type*)I2C0_BASE)
#define I2S0                                    ((I2S_Type*)I2S0_BASE)
#define IOC                                     ((IOC_Type*)IOC_BASE)
#define PRCM                                    ((PRCM_Type*)PRCM_BASE)
#define SSI0                                    ((SSI_Type*)SSI0_BASE)
#define SSI1                                    ((SSI_Type*)SSI1_BASE)
#define TRNG                                    ((TRNG_Type*)TRNG_BASE)
#define UART0                                   ((USART_Type*)UART0_BASE)
#define uDMA0                                   ((uDMA_Type*)uDMA0_BASE)
#define VIMS                                    ((VIMS_Type*)VIMS_BASE)
#define WDT                                     ((WDT_Type*)WDT_BASE)


/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                  PRCM                                      */
/*                                                                            */
/******************************************************************************/

/*************  Bit definition for PRCM_INFRCLKDIVR register  *****************/
#define PRCM_INFRCLKDIVR_RATIO                  (0x3ul << 0)
#define PRCM_INFRCLKDIVR_RATIO_1                (0x0ul << 0)
#define PRCM_INFRCLKDIVR_RATIO_2                (0x1ul << 0)
#define PRCM_INFRCLKDIVR_RATIO_8                (0x2ul << 0)
#define PRCM_INFRCLKDIVR_RATIO_32               (0x3ul << 0)


/*************  Bit definition for PRCM_INFRCLKDIVS register  *****************/
#define PRCM_INFRCLKDIVS_RATIO                  (0x3ul << 0)
#define PRCM_INFRCLKDIVS_RATIO_1                (0x0ul << 0)
#define PRCM_INFRCLKDIVS_RATIO_2                (0x1ul << 0)
#define PRCM_INFRCLKDIVS_RATIO_8                (0x2ul << 0)
#define PRCM_INFRCLKDIVS_RATIO_32               (0x3ul << 0)


/*************  Bit definition for PRCM_INFRCLKDIVDS register  ****************/
#define PRCM_INFRCLKDIVDS_RATIO                 (0x3ul << 0)
#define PRCM_INFRCLKDIVDS_RATIO_1               (0x0ul << 0)
#define PRCM_INFRCLKDIVDS_RATIO_2               (0x1ul << 0)
#define PRCM_INFRCLKDIVDS_RATIO_8               (0x2ul << 0)
#define PRCM_INFRCLKDIVDS_RATIO_32              (0x3ul << 0)


/*************  Bit definition for PRCM_VDCTL register  ***********************/
#define PRCM_VDCTL_MCU_VD                       (0x1ul << 2)
#define PRCM_VDCTL_ULDO                         (0x1ul << 0)


/*************  Bit definition for PRCM_CLKLOADCTL register  ******************/
#define PRCM_CLKLOADCTL_LOAD_DONE               (0x1ul << 1)
#define PRCM_CLKLOADCTL_LOAD                    (0x1ul << 0)


/*************  Bit definition for PRCM_RFCCLKG register  *********************/
#define PRCM_RFCCLKG_CLK_EN                     (0x1ul << 0)


/*************  Bit definition for PRCM_VIMSCLKG register  ********************/
#define PRCM_VIMSCLKG_CLK_EN                    (0x1ul << 0)


/*************  Bit definition for PRCM_SECDMACLKGR register  *****************/
#define PRCM_SECDMACLKGR_DMA_CLK_EN             (0x1ul << 8)
#define PRCM_SECDMACLKGR_TRNG_CLK_EN            (0x1ul << 1)
#define PRCM_SECDMACLKGR_CRYPTO_CLK_EN          (0x1ul << 0)


/*************  Bit definition for PRCM_SECDMACLKGS register  *****************/
#define PRCM_SECDMACLKGS_DMA_CLK_EN             (0x1ul << 8)
#define PRCM_SECDMACLKGS_TRNG_CLK_EN            (0x1ul << 1)
#define PRCM_SECDMACLKGS_CRYPTO_CLK_EN          (0x1ul << 0)


/*************  Bit definition for PRCM_SECDMACLKGDS register  ****************/
#define PRCM_SECDMACLKGDS_DMA_CLK_EN            (0x1ul << 8)
#define PRCM_SECDMACLKGDS_TRNG_CLK_EN           (0x1ul << 1)
#define PRCM_SECDMACLKGDS_CRYPTO_CLK_EN         (0x1ul << 0)


/*************  Bit definition for PRCM_GPIOCLKGR register  *******************/
#define PRCM_GPIOCLKGR_CLK_EN                   (0x1ul << 0)


/*************  Bit definition for PRCM_GPIOCLKGS register  *******************/
#define PRCM_GPIOCLKGS_CLK_EN                   (0x1ul << 0)


/*************  Bit definition for PRCM_GPIOCLKGDS register  ******************/
#define PRCM_GPIOCLKGDS_CLK_EN                  (0x1ul << 0)


/*************  Bit definition for PRCM_GPTCLKGR register  ********************/
#define PRCM_GPTCLKGR_GPT3_CLK_EN               (0x1ul << 3)
#define PRCM_GPTCLKGR_GPT2_CLK_EN               (0x1ul << 2)
#define PRCM_GPTCLKGR_GPT1_CLK_EN               (0x1ul << 1)
#define PRCM_GPTCLKGR_GPT0_CLK_EN               (0x1ul << 0)


/*************  Bit definition for PRCM_GPTCLKGS register  ********************/
#define PRCM_GPTCLKGS_GPT3_CLK_EN               (0x1ul << 3)
#define PRCM_GPTCLKGS_GPT2_CLK_EN               (0x1ul << 2)
#define PRCM_GPTCLKGS_GPT1_CLK_EN               (0x1ul << 1)
#define PRCM_GPTCLKGS_GPT0_CLK_EN               (0x1ul << 0)


/*************  Bit definition for PRCM_GPTCLKGDS register  *******************/
#define PRCM_GPTCLKGDS_GPT3_CLK_EN              (0x1ul << 3)
#define PRCM_GPTCLKGDS_GPT2_CLK_EN              (0x1ul << 2)
#define PRCM_GPTCLKGDS_GPT1_CLK_EN              (0x1ul << 1)
#define PRCM_GPTCLKGDS_GPT0_CLK_EN              (0x1ul << 0)


/*************  Bit definition for PRCM_I2CCLKGR register  ********************/
#define PRCM_I2CCLKGR_CLK_EN                    (0x1ul << 0)


/*************  Bit definition for PRCM_I2CCLKGS register  ********************/
#define PRCM_I2CCLKGS_CLK_EN                    (0x1ul << 0)


/*************  Bit definition for PRCM_I2CCLKGDS register  *******************/
#define PRCM_I2CCLKGDS_CLK_EN                   (0x1ul << 0)


/*************  Bit definition for PRCM_UARTCLKGR register  *******************/
#define PRCM_UARTCLKGR_CLK_EN                   (0x1ul << 0)


/*************  Bit definition for PRCM_UARTCLKGS register  *******************/
#define PRCM_UARTCLKGS_CLK_EN                   (0x1ul << 0)

/*************  Bit definition for PRCM_UARTCLKGDS register  ******************/
#define PRCM_UARTCLKGDS_CLK_EN                   (0x1ul << 0)


/*************  Bit definition for PRCM_SSICLKGR register  ********************/
#define PRCM_SSICLKGR_SSI1_CLK_EN                (0x1ul << 1)
#define PRCM_SSICLKGR_SSI0_CLK_EN                (0x1ul << 0)


/*************  Bit definition for PRCM_SSICLKGS register  ********************/
#define PRCM_SSICLKGS_SSI1_CLK_EN                (0x1ul << 1)
#define PRCM_SSICLKGS_SSI0_CLK_EN                (0x1ul << 0)


/*************  Bit definition for PRCM_SSICLKGDS register  *******************/
#define PRCM_SSICLKGDS_SSI1_CLK_EN               (0x1ul << 1)
#define PRCM_SSICLKGDS_SSI0_CLK_EN               (0x1ul << 0)


/*************  Bit definition for PRCM_I2SCLKGR register  ********************/
#define PRCM_I2SCLKGR_CLK_EN                    (0x1ul << 0)


/*************  Bit definition for PRCM_I2SCLKGS register  ********************/
#define PRCM_I2SCLKGS_CLK_EN                    (0x1ul << 0)


/*************  Bit definition for PRCM_I2SCLKGDS register  *******************/
#define PRCM_I2SCLKGDS_CLK_EN                   (0x1ul << 0)


/*************  Bit definition for PRCM_CPUCLKDIV register  *******************/
#define PRCM_CPUCLKDIV_RATIO                    (0x1ul << 0)


/*************  Bit definition for PRCM_I2SBCLKSEL register  ******************/
#define PRCM_I2SBCLKSEL_SRC                     (0x1ul << 0)


/*************  Bit definition for PRCM_GPTCLKDIV register  *******************/
#define PRCM_GPTCLKDIV_RATIO                    (0xful << 0)
#define PRCM_GPTCLKDIV_RATIO_VAL(x)             (((x) & 0xful) << 0)
#define PRCM_GPTCLKDIV_RATIO_1                  (0x0ul << 0)
#define PRCM_GPTCLKDIV_RATIO_2                  (0x1ul << 0)
#define PRCM_GPTCLKDIV_RATIO_4                  (0x2ul << 0)
#define PRCM_GPTCLKDIV_RATIO_8                  (0x3ul << 0)
#define PRCM_GPTCLKDIV_RATIO_16                 (0x4ul << 0)
#define PRCM_GPTCLKDIV_RATIO_32                 (0x5ul << 0)
#define PRCM_GPTCLKDIV_RATIO_64                 (0x6ul << 0)
#define PRCM_GPTCLKDIV_RATIO_128                (0x7ul << 0)
#define PRCM_GPTCLKDIV_RATIO_256                (0x8ul << 0)


/*************  Bit definition for PRCM_I2SCLKCTL register  *******************/
#define PRCM_I2SCLKCTL_SMPL_ON_POSEDGE          (0x1ul << 3)

#define PRCM_I2SCLKCTL_WCLK_PHASE               (0x3ul << 1)
#define PRCM_I2SCLKCTL_WCLK_PHASE_SINGLE        (0x0ul << 1)
#define PRCM_I2SCLKCTL_WCLK_PHASE_DUAL          (0x1ul << 1)
#define PRCM_I2SCLKCTL_WCLK_PHASE_USER          (0x2ul << 1)

#define PRCM_I2SCLKCTL_EN                       (0x1ul << 0)


/*************  Bit definition for PRCM_I2SMCLKDIV register  ******************/
#define PRCM_I2SMCLKDIV_MDIV                    (0x3fful << 0)
#define PRCM_I2SMCLKDIV_MDIV_VAL(x)             (((x) & 0x3fful) << 0)


/*************  Bit definition for PRCM_I2SBCLKDIV register  ******************/
#define PRCM_I2SBCLKDIV_BDIV                    (0x3fful << 0)
#define PRCM_I2SBCLKDIV_BDIV_VAL(x)             (((x) & 0x3fful) << 0)


/*************  Bit definition for PRCM_I2SWCLKDIV register  ******************/
#define PRCM_I2SWCLKDIV_WDIV                    (0xfffful << 0)
#define PRCM_I2SWCLKDIV_WDIV_VAL(x)             (((x) & 0xfffful) << 0)


/*************  Bit definition for PRCM_SWRESET register  *********************/
#define PRCM_SWRESET_MCU                        (0x1 << 2)


/*************  Bit definition for PRCM_WARMRESET register  *******************/
#define PRCM_WARMRESET_WR_TO_PINRESET           (0x1 << 2)
#define PRCM_WARMRESET_LOCKUP_STAT              (0x1 << 1)
#define PRCM_WARMRESET_WDT_STAT                 (0x1 << 0)


/*************  Bit definition for PRCM_PDCTL0 register  **********************/
#define PRCM_PDCTL0_PERIPH_ON                   (0x1 << 2)
#define PRCM_PDCTL0_SERIAL_ON                   (0x1 << 1)
#define PRCM_PDCTL0_RFC_ON                      (0x1 << 0)


/*************  Bit definition for PRCM_PDCTL0RFC register  *******************/
#define PRCM_PDCTL0RFC_ON                       (0x1 << 0)


/*************  Bit definition for PRCM_PDCTL0SERIAL register  ****************/
#define PRCM_PDCTL0SERIAL_ON                    (0x1 << 0)


/*************  Bit definition for PRCM_PDCTL0PERIPH register  ****************/
#define PRCM_PDCTL0PERIPH_ON                    (0x1 << 0)


/*************  Bit definition for PRCM_PDSTAT0 register  *********************/
#define PRCM_PDSTAT0_PERIPH_ON                  (0x1 << 2)
#define PRCM_PDSTAT0_SERIAL_ON                  (0x1 << 1)
#define PRCM_PDSTAT0_RFC_ON                     (0x1 << 0)


/*************  Bit definition for PRCM_PDSTAT0RFC register  ******************/
#define PRCM_PDSTAT0RFC_ON                      (0x1 << 0)


/*************  Bit definition for PRCM_PDSTAT0SERIAL register  ***************/
#define PRCM_PDSTAT0SERIAL_ON                   (0x1 << 0)


/*************  Bit definition for PRCM_PDSTAT0PERIPH register  ***************/
#define PRCM_PDSTAT0PERIPH_ON                   (0x1 << 0)


/*************  Bit definition for PRCM_PDCTL1 register  **********************/
#define PRCM_PDCTL1_VIMS_MODE                   (0x1 << 3)
#define PRCM_PDCTL1_RFC_ON                      (0x1 << 2)
#define PRCM_PDCTL1_CPU_ON                      (0x1 << 1)


/*************  Bit definition for PRCM_PDCTL1CPU register  *******************/
#define PRCM_PDCTL1CPU_ON                       (0x1 << 0)


/*************  Bit definition for PRCM_PDCTL1RFC register  *******************/
#define PRCM_PDCTL1RFC_ON                       (0x1 << 0)


/*************  Bit definition for PRCM_PDCTL1VIMS register  ******************/
#define PRCM_PDCTL1VIMS_ON                      (0x1 << 0)


/*************  Bit definition for PRCM_PDSTAT1 register  *********************/
#define PRCM_PDSTAT1_BUS_ON                     (0x1 << 4)
#define PRCM_PDSTAT1_VIMS_MODE                  (0x1 << 3)
#define PRCM_PDSTAT1_RFC_ON                     (0x1 << 2)
#define PRCM_PDSTAT1_CPU_ON                     (0x1 << 1)


/*************  Bit definition for PRCM_PDSTAT1BUS register  ******************/
#define PRCM_PDSTAT1BUS_ON                      (0x1 << 0)


/*************  Bit definition for PRCM_PDSTAT1RFC register  ******************/
#define PRCM_PDSTAT1RFC_ON                      (0x1 << 0)


/*************  Bit definition for PRCM_PDSTAT1CPU register  ******************/
#define PRCM_PDSTAT1CPU_ON                      (0x1 << 0)


/*************  Bit definition for PRCM_PDSTAT1VIMS register  *****************/
#define PRCM_PDSTAT1VIMS_ON                     (0x1 << 0)

/*************  Bit definition for PRCM_RFCMODESEL register  ******************/
#define PRCM_RFCMODESEL_CURR                    (0x7 << 0)
#define PRCM_RFCMODESEL_CURR_VAL(x)             (((x) & 0x7ul) << 0)


/*************  Bit definition for PRCM_PWRPROFSTAT register  ****************/
#define PRCM_PWRPROFSTAT_VALUE                  (0xff << 0)
#define PRCM_PWRPROFSTAT_VALUE_VAL(x)           (((x) & 0xfful) << 0)


/*************  Bit definition for PRCM_RAMRETEN register  *******************/
#define PRCM_RAMRETEN_RFC                       (0x1 << 2)

#define PRCM_RAMRETEN_VIMS                      (0x3 << 0)
#define PRCM_RAMRETEN_VIMS_CRAM                 (0x1 << 1)
#define PRCM_RAMRETEN_VIMS_TRAM                 (0x1 << 0)
#define PRCM_RAMRETEN_VIMS_RETENTION_DISABLED   (0x0 << 0)
#define PRCM_RAMRETEN_VIMS_RETENTION_ENABLED    (0x1 << 0)
#define PRCM_RAMRETEN_VIMS_NO_RESTRICTIONS      (0x3 << 0)


/******************************************************************************/
/*                                                                            */
/*                                   IOC                                      */
/*                                                                            */
/******************************************************************************/

/*************  Bit definition for IOC_IOCFG register  ************************/
#define IOC_IOCFG_HYST_EN                       (0x1ul << 30)
#define IOC_IOCFG_IO                            (0x1ul << 29)

#define IOC_IOCFG_WU_CFG                        (0x3ul << 27)
#define IOC_IOCFG_WU_CFG_NO                     (0x0ul << 27)
#define IOC_IOCFG_WU_CFG_LOW                    (0x2ul << 27)
#define IOC_IOCFG_WU_CFG_HIGH                   (0x3ul << 27)

#define IOC_IOCFG_IOMODE                        (0x7ul << 24)
#define IOC_IOCFG_IOMODE_NORMAL                 (0x0ul << 24)
#define IOC_IOCFG_IOMODE_INV                    (0x1ul << 24)
#define IOC_IOCFG_IOMODE_OPENDR                 (0x4ul << 24)
#define IOC_IOCFG_IOMODE_OPENDR_INV             (0x5ul << 24)
#define IOC_IOCFG_IOMODE_OPENSRC                (0x6ul << 24)
#define IOC_IOCFG_IOMODE_OPENSRC_INV            (0x7ul << 24)

#define IOC_IOCFG_EDGE_IRQ_EN                   (0x1ul << 18)

#define IOC_IOCFG_EDGE_DET                      (0x3ul << 16)
#define IOC_IOCFG_EDGE_DET_NONE                 (0x0ul << 16)
#define IOC_IOCFG_EDGE_DET_NEGATIVE             (0x1ul << 16)
#define IOC_IOCFG_EDGE_DET_POSITIVE             (0x2ul << 16)
#define IOC_IOCFG_EDGE_DET_BOTH                 (0x3ul << 16)

#define IOC_IOCFG_PULL_CTL                      (0x3ul << 13)
#define IOC_IOCFG_PULL_CTL_DOWN                 (0x1ul << 13)
#define IOC_IOCFG_PULL_CTL_UP                   (0x2ul << 13)
#define IOC_IOCFG_PULL_CTL_DIS                  (0x3ul << 13)

#define IOC_IOCFG_SLEW_RED                      (0x1ul << 12)

#define IOC_IOCFG_IOCURR                        (0x3ul << 10)
#define IOC_IOCFG_IOCURR_2MA                    (0x0ul << 10)
#define IOC_IOCFG_IOCURR_4MA                    (0x1ul << 10)
#define IOC_IOCFG_IOCURR_4_8MA                  (0x2ul << 10)

#define IOC_IOCFG_IOSTR                         (0x3ul << 8)
#define IOC_IOCFG_IOSTR_AUTO                    (0x0ul << 8)
#define IOC_IOCFG_IOSTR_MIN                     (0x1ul << 8)
#define IOC_IOCFG_IOSTR_MED                     (0x2ul << 8)
#define IOC_IOCFG_IOSTR_MAX                     (0x3ul << 8)

#define IOC_IOCFG_PORT_ID                       (0x1fful << 0)
#define IOC_IOCFG_PORT_ID_GPIO                  (0x0 << 0)

#define IOC_IOCFG_PORT_ID_AON_SCS               (1 << 0)
#define IOC_IOCFG_PORT_ID_AON_SCK               (2 << 0)
#define IOC_IOCFG_PORT_ID_AON_SDI               (3 << 0)
#define IOC_IOCFG_PORT_ID_AON_SDO               (4 << 0)
#define IOC_IOCFG_PORT_ID_AON_CLK32K            (7 << 0)

#define IOC_IOCFG_PORT_ID_AUX_IO                (8 << 0)

#define IOC_IOCFG_PORT_ID_MCU_SSI0_RX           (9 << 0)
#define IOC_IOCFG_PORT_ID_MCU_SSI0_TX           (10 << 0)
#define IOC_IOCFG_PORT_ID_MCU_SSI0_FSS          (11 << 0)
#define IOC_IOCFG_PORT_ID_MCU_SSI0_CLK          (12 << 0)

#define IOC_IOCFG_PORT_ID_MCU_I2C_MSSDA         (13 << 0)
#define IOC_IOCFG_PORT_ID_MCU_I2C_MSSCL         (14 << 0)

#define IOC_IOCFG_PORT_ID_MCU_UART0_RX          (15 << 0)
#define IOC_IOCFG_PORT_ID_MCU_UART0_TX          (16 << 0)
#define IOC_IOCFG_PORT_ID_MCU_UART0_CTS         (17 << 0)
#define IOC_IOCFG_PORT_ID_MCU_UART0_RTS         (18 << 0)

#define IOC_IOCFG_PORT_ID_MCU_GPTM_GPTM0        (23 << 0)
#define IOC_IOCFG_PORT_ID_MCU_GPTM_GPTM1        (24 << 0)
#define IOC_IOCFG_PORT_ID_MCU_GPTM_GPTM2        (25 << 0)
#define IOC_IOCFG_PORT_ID_MCU_GPTM_GPTM3        (26 << 0)
#define IOC_IOCFG_PORT_ID_MCU_GPTM_GPTM4        (27 << 0)
#define IOC_IOCFG_PORT_ID_MCU_GPTM_GPTM5        (28 << 0)
#define IOC_IOCFG_PORT_ID_MCU_GPTM_GPTM6        (29 << 0)
#define IOC_IOCFG_PORT_ID_MCU_GPTM_GPTM7        (30 << 0)

#define IOC_IOCFG_PORT_ID_MCU_CM3_SWV           (32 << 0)

#define IOC_IOCFG_PORT_ID_MCU_SSI1_RX           (33 << 0)
#define IOC_IOCFG_PORT_ID_MCU_SSI1_TX           (34 << 0)
#define IOC_IOCFG_PORT_ID_MCU_SSI1_FSS          (35 << 0)
#define IOC_IOCFG_PORT_ID_MCU_SSI1_CLK          (36 << 0)

#define IOC_IOCFG_PORT_ID_MCU_I2S_AD0           (37 << 0)
#define IOC_IOCFG_PORT_ID_MCU_I2S_AD1           (38 << 0)
#define IOC_IOCFG_PORT_ID_MCU_I2S_WCLK          (39 << 0)
#define IOC_IOCFG_PORT_ID_MCU_I2S_BCLK          (40 << 0)
#define IOC_IOCFG_PORT_ID_MCU_I2S_MCLK          (41 << 0)

#define IOC_IOCFG_PORT_ID_RFC_INTERNAL0         (46 << 0)
#define IOC_IOCFG_PORT_ID_RFC_GPO0              (47 << 0)
#define IOC_IOCFG_PORT_ID_RFC_GPO1              (48 << 0)
#define IOC_IOCFG_PORT_ID_RFC_GPO2              (49 << 0)
#define IOC_IOCFG_PORT_ID_RFC_GPO3              (50 << 0)
#define IOC_IOCFG_PORT_ID_RFC_INTERNAL1         (51 << 0)
#define IOC_IOCFG_PORT_ID_RFC_INTERNAL2         (52 << 0)
#define IOC_IOCFG_PORT_ID_RFC_INTERNAL3         (53 << 0)
#define IOC_IOCFG_PORT_ID_RFC_INTERNAL4         (54 << 0)
#define IOC_IOCFG_PORT_ID_RFC_INTERNAL5         (55 << 0)
#define IOC_IOCFG_PORT_ID_RFC_INTERNAL6         (56 << 0)


/** @} */ /* End of group Device_Peripheral_Registers */

#ifdef __cplusplus
}
#endif

#endif // CC26X0_H
