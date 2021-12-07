/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// rom_captivate_msp430fr2676_family.h 
// Macros to facilitate calling functions in the ROM.
//
// Copyright (c) 2018 Texas Instruments Incorporated.  All rights reserved.
// TI Information - Selective Disclosure
//
//*****************************************************************************
#if defined(__TI_COMPILER_VERSION__)
#if __TI_COMPILER_VERSION__ >= 18001001
#define __cc_rom __attribute__((call_conv("cc_rom")))
#else
#error "The cc_rom attribute requires MSP TI COMPILER 18.1.1.LTS or more recent."
#endif  // __TI_COMPILER_VERSION__ >= 
#endif  // (defined(__TI_COMPILER_VERSION__))18001001

#if defined(__IAR_SYSTEMS_ICC__) && (__VER__ < 650)
#error "The __cc_rom attribute requires IAR version 6.50 or more recent."
#endif

#if __REGISTER_R4__ != __REGISTER_FREE__
#error "Incorrect setting for R4, expected it to be free."
#endif

#if __REGISTER_R5__ != __REGISTER_FREE__
#error "Incorrect setting for R5, expected it to be free."
#endif

// Suppress type conversion warning
#ifdef __TI_COMPILER_VERSION__
#pragma diag_suppress 173
#endif

#if (defined(__TI_COMPILER_VERSION__) && !defined(__LARGE_DATA_MODEL__)) || \
    (defined(__IAR_SYSTEMS_ICC__) && (__DATA_MODEL__!=__DATA_MODEL_LARGE__))
#error "Only large data model supported for this ROM."
#endif
#ifndef ROM_CAPTIVATE_MSP430FR2676_H_
#define ROM_CAPTIVATE_MSP430FR2676_H_

#if (defined(__TI_COMPILER_VERSION__) && defined(__LARGE_CODE_MODEL__)) || \
    (defined(__IAR_SYSTEMS_ICC__) && (__CODE_MODEL__==__CODE_MODEL_LARGE__))

//*****************************************************************************
//
// CapTIvate ROM API Definitions
//  - ROM_CAPTIVATE_APITABLE defines the beginning of the ROM section.
//  - ROM_CAPTIVATETABLE is the ROM defined indirect address of the jump table.
//  - ROM_CAPTIVATE_FXNTABLE is the direct address of the jump table.
//  - ROM_CAPTIVATE_JUMPTABLE is the table address to use, and should be 
//    selected as ROM_CAPTIVATETABLE or ROM_CAPTIVATE_FXNTABLE.
//
//*****************************************************************************
#ifndef ROM_TABLE
#define ROM_TABLE               ((uint32_t *)ROMLIB_START)
#endif
#define ROM_CAPTIVATE_APITABLE  ((uint32_t *)ROM_TABLE[2])
#define ROM_CAPTIVATE_VERSION   ((uint32_t)ROM_CAPTIVATE_APITABLE[0])
#define ROM_CAPTIVATETABLE      ((uint32_t *)(ROM_CAPTIVATE_APITABLE[2]))
#define ROM_CAPTIVATE_FXNTABLE  ((uint32_t *)0xc1908)
#define ROM_CAPTIVATE_JUMPTABLE (ROM_CAPTIVATE_FXNTABLE)

//*****************************************************************************
//
// Macro to obtain ROM build version.
//
//*****************************************************************************
#define ROM_CAPTIVATE_getVersion() \
    ((uint32_t)ROM_CAPTIVATE_VERSION)
#ifndef ROM_getVersion
#define ROM_getVersion()        ((uint32_t)(ROMLIB_START[0]))
#endif

//*****************************************************************************
//
// Macros for calling CAPTIVATE ROM functions in the CAPTIVATE API.
//
//*****************************************************************************
// ROM Function Definition: CAPT_selectTimerSource
#define ROM_CAPT_selectTimerSource                                            \
        ((void (__cc_rom *)(uint8_t source))ROM_CAPTIVATE_JUMPTABLE[0])

// ROM Function Definition: CAPT_computeArcTanApprox
#define ROM_CAPT_computeArcTanApprox                                          \
        ((uint16_t (__cc_rom *)(int32_t i32XComp,                             \
                                int32_t i32YComp))ROM_CAPTIVATE_JUMPTABLE[1])

// ROM Function Definition: CAPT_clearChannelOffState
#define ROM_CAPT_clearChannelOffState                                         \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Pin))ROM_CAPTIVATE_JUMPTABLE[2])

// ROM Function Definition: CAPT_clearTimer
#define ROM_CAPT_clearTimer                                                   \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[3])

// ROM Function Definition: CAPT_getChecksum
#define ROM_CAPT_getChecksum                                                  \
        ((uint16_t (__cc_rom *)(const uint8_t *pBuffer,                       \
                                const uint16_t ui16Length))ROM_CAPTIVATE_JUMPTABLE[4])

// ROM Function Definition: CAPT_verifyChecksum
#define ROM_CAPT_verifyChecksum                                               \
        ((bool (__cc_rom *)(const uint8_t *pBuffer,                           \
                            const uint16_t ui16Length,                        \
                            const uint16_t ui16Checksum))ROM_CAPTIVATE_JUMPTABLE[5])

// ROM Function Definition: CAPT_updateTouch
#define ROM_CAPT_updateTouch                                                  \
        ((bool (__cc_rom *)(tSensor *pSensor,                                 \
                            tElement *pElement))ROM_CAPTIVATE_JUMPTABLE[6])

// ROM Function Definition: CAPT_getCyclePacket
#define ROM_CAPT_getCyclePacket                                               \
        ((uint16_t (__cc_rom *)(tSensor **sensorArray,                        \
                                uint8_t ui8SensorID,                          \
                                uint8_t ui8Cycle,                             \
                                uint8_t *pBuffer))ROM_CAPTIVATE_JUMPTABLE[7])

// ROM Function Definition: CAPT_clearCAPLPMCFG
#define ROM_CAPT_clearCAPLPMCFG                                               \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[8])

// ROM Function Definition: CAPT_clearChannelOnState
#define ROM_CAPT_clearChannelOnState                                          \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Pin))ROM_CAPTIVATE_JUMPTABLE[9])

// ROM Function Definition: CAPT_pollResetStatus
#define ROM_CAPT_pollResetStatus                                              \
        ((bool (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[10])

// ROM Function Definition: CAPT_pollCIPF
#define ROM_CAPT_pollCIPF                                                     \
        ((bool (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[11])

// ROM Function Definition: CAPT_computeWheelWrap
#define ROM_CAPT_computeWheelWrap                                             \
        ((uint16_t (__cc_rom *)(int16_t i16Position,                          \
                                uint16_t ui16MaxPosition))ROM_CAPTIVATE_JUMPTABLE[12])

// ROM Function Definition: CAPT_powerOn
#define ROM_CAPT_powerOn                                                      \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[13])

// ROM Function Definition: CAPT_startTimer
#define ROM_CAPT_startTimer                                                   \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[14])

// ROM Function Definition: CAPT_accessSensorParameter
#define ROM_CAPT_accessSensorParameter                                        \
        ((tTLParameterAccessResult (__cc_rom *)( tSensor **sensorArray,       \
                                                tParameterPacket *pPacket))ROM_CAPTIVATE_JUMPTABLE[15])

// ROM Function Definition: CAPT_clearCAPSTART
#define ROM_CAPT_clearCAPSTART                                                \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[16])

// ROM Function Definition: CAPT_processSlider
#define ROM_CAPT_processSlider                                                \
        ((void (__cc_rom *)(tSensor *pSlider))ROM_CAPTIVATE_JUMPTABLE[17])

// ROM Function Definition: CAPT_stopTimer
#define ROM_CAPT_stopTimer                                                    \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[18])

// ROM Function Definition: CAPT_setChannelOnState
#define ROM_CAPT_setChannelOnState                                            \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Pin))ROM_CAPTIVATE_JUMPTABLE[19])

// ROM Function Definition: CAPT_initByteQueue
#define ROM_CAPT_initByteQueue                                                \
        ((bool (__cc_rom *)(tByteQueue *pQueue,                               \
                            uint8_t *pBufferArray,                            \
                            uint16_t ui16BufferArraySize))ROM_CAPTIVATE_JUMPTABLE[20])

// ROM Function Definition: CAPT_reseedFilterAll
#define ROM_CAPT_reseedFilterAll                                              \
        ((void (__cc_rom *)(tSensor *pSensor,                                 \
                            tFilterOption WhatToFilter))ROM_CAPTIVATE_JUMPTABLE[21])

// ROM Function Definition: CAPT_writeOffsetTap
#define ROM_CAPT_writeOffsetTap                                               \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint16_t ui16Value))ROM_CAPTIVATE_JUMPTABLE[22])

// ROM Function Definition: CAPT_setChannelOffState
#define ROM_CAPT_setChannelOffState                                           \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Pin))ROM_CAPTIVATE_JUMPTABLE[23])

// ROM Function Definition: CAPT_readOffsetTap
#define ROM_CAPT_readOffsetTap                                                \
        ((uint16_t (__cc_rom *)(uint8_t ui8Block))ROM_CAPTIVATE_JUMPTABLE[24])

// ROM Function Definition: CAPT_enableISR
#define ROM_CAPT_enableISR                                                    \
        ((void (__cc_rom *)(uint16_t interruptEnable))ROM_CAPTIVATE_JUMPTABLE[25])

// ROM Function Definition: CAPT_disableSensorSyncEvent
#define ROM_CAPT_disableSensorSyncEvent                                       \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[26])

// ROM Function Definition: CAPT_readConversion
#define ROM_CAPT_readConversion                                               \
        ((uint16_t (__cc_rom *)(uint8_t ui8Block))ROM_CAPTIVATE_JUMPTABLE[27])

// ROM Function Definition: CAPT_clearCCounter
#define ROM_CAPT_clearCCounter                                                \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[28])

// ROM Function Definition: CAPT_updateProx
#define ROM_CAPT_updateProx                                                   \
        ((bool (__cc_rom *)(tSensor *pSensor,                                 \
                            tElement *pElement))ROM_CAPTIVATE_JUMPTABLE[29])

// ROM Function Definition: CAPT_isByteQueueEmpty
#define ROM_CAPT_isByteQueueEmpty                                             \
        ((bool (__cc_rom *)(tByteQueue *pQueue))ROM_CAPTIVATE_JUMPTABLE[30])

// ROM Function Definition: CAPT_readTimerCompRegister
#define ROM_CAPT_readTimerCompRegister                                        \
        ((uint16_t (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[31])

// ROM Function Definition: CAPT_applySensorFreq
#define ROM_CAPT_applySensorFreq                                              \
        ((void (__cc_rom *)(uint8_t freqSelect,                               \
                            tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[32])

// ROM Function Definition: CAPT_saveCycleResults
#define ROM_CAPT_saveCycleResults                                             \
        ((void (__cc_rom *)(tSensor *pSensor ,                                \
                           tCycle *pCycle))ROM_CAPTIVATE_JUMPTABLE[33])

// ROM Function Definition: CAPT_togglePingPongBuffer
#define ROM_CAPT_togglePingPongBuffer                                         \
        ((bool (__cc_rom *)(tPingPongBuffer *PPBuffer))ROM_CAPTIVATE_JUMPTABLE[34])

// ROM Function Definition: CAPT_powerOff
#define ROM_CAPT_powerOff                                                     \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[35])

// ROM Function Definition: CAPT_clearChannelEnable
#define ROM_CAPT_clearChannelEnable                                           \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Pin))ROM_CAPTIVATE_JUMPTABLE[36])

// ROM Function Definition: CAPT_reset
#define ROM_CAPT_reset                                                        \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[37])

// ROM Function Definition: CAPT_setChannelEnable
#define ROM_CAPT_setChannelEnable                                             \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Pin))ROM_CAPTIVATE_JUMPTABLE[38])

// ROM Function Definition: CAPT_writeCoarseGain
#define ROM_CAPT_writeCoarseGain                                              \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Value))ROM_CAPTIVATE_JUMPTABLE[39])

// ROM Function Definition: CAPT_computeSliderVectors
#define ROM_CAPT_computeSliderVectors                                         \
        ((uint16_t (__cc_rom *)(tSensor *pSlider))ROM_CAPTIVATE_JUMPTABLE[40])

// ROM Function Definition: CAPT_readFineGain
#define ROM_CAPT_readFineGain                                                 \
        ((uint8_t (__cc_rom *)(uint8_t ui8Block))ROM_CAPTIVATE_JUMPTABLE[41])

// ROM Function Definition: CAPT_applySensorParams
#define ROM_CAPT_applySensorParams                                            \
        ((void (__cc_rom *)(tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[42])

// ROM Function Definition: CAPT_stuffSyncBytes
#define ROM_CAPT_stuffSyncBytes                                               \
        ((uint16_t (__cc_rom *)(uint8_t *pBuffer,                             \
                                uint16_t ui16Length))ROM_CAPTIVATE_JUMPTABLE[43])

// ROM Function Definition: CAPT_engageFSM
#define ROM_CAPT_engageFSM                                                    \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[44])

// ROM Function Definition: CAPT_enableRefCap
#define ROM_CAPT_enableRefCap                                                 \
        ((void (__cc_rom *)(tElement* pElement,                               \
                            uint8_t capSize))ROM_CAPTIVATE_JUMPTABLE[45])

// ROM Function Definition: CAPT_stopCCounter
#define ROM_CAPT_stopCCounter                                                 \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[46])

// ROM Function Definition: CAPT_processReceivedData
#define ROM_CAPT_processReceivedData                                          \
        ((bool (__cc_rom *)(tByteQueue *pReceiveQueue,                        \
                            tParameterPacket *pPacket,                        \
                            tTLProtocolProcessingVariables *pVariables))ROM_CAPTIVATE_JUMPTABLE[47])

// ROM Function Definition: CAPT_enableSensorIO
#define ROM_CAPT_enableSensorIO                                               \
        ((void (__cc_rom *)(tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[48])

// ROM Function Definition: CAPT_clearCycleIO
#define ROM_CAPT_clearCycleIO                                                 \
        ((void (__cc_rom *)(tSensor *pSensor,                                 \
                            tCycle *pCycle))ROM_CAPTIVATE_JUMPTABLE[49])

// ROM Function Definition: CAPT_disableSensorIO
#define ROM_CAPT_disableSensorIO                                              \
        ((void (__cc_rom *)(tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[50])

// ROM Function Definition: CAPT_clearSensorProxTouch
#define ROM_CAPT_clearSensorProxTouch                                         \
        ((void (__cc_rom *)(tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[51])

// ROM Function Definition: CAPT_selectCCounterInterval
#define ROM_CAPT_selectCCounterInterval                                       \
        ((void (__cc_rom *)(uint8_t counterSel))ROM_CAPTIVATE_JUMPTABLE[52])

// ROM Function Definition: CAPT_setCycleIO
#define ROM_CAPT_setCycleIO                                                   \
        ((void (__cc_rom *)(tSensor *pSensor,                                 \
                           tCycle *pCycle))ROM_CAPTIVATE_JUMPTABLE[53])

// ROM Function Definition: CAPT_initPingPongBuffer
#define ROM_CAPT_initPingPongBuffer                                           \
        ((bool (__cc_rom *)(tPingPongBuffer *PPBuffer,                        \
                            uint8_t *pBuffer1,                                \
                            uint8_t *pBuffer2))ROM_CAPTIVATE_JUMPTABLE[54])

// ROM Function Definition: CAPT_pushOntoByteQueue
//TODO: have to remove because it has an errant interaction with CCS compiler
//#define ROM_CAPT_pushOntoByteQueue                                            \
//        ((int8_t (__cc_rom *)(tByteQueue *pQueue,                             \
//                              uint8_t ui8DataToAdd))ROM_CAPTIVATE_JUMPTABLE[55])

// ROM Function Definition: CAPT_writeTimerCompRegister
#define ROM_CAPT_writeTimerCompRegister                                       \
        ((void (__cc_rom *)(uint16_t compRegister))ROM_CAPTIVATE_JUMPTABLE[56])

// ROM Function Definition: CAPT_readTimerRegister
#define ROM_CAPT_readTimerRegister                                            \
        ((uint16_t (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[57])

// ROM Function Definition: CAPT_initSensorIO
#define ROM_CAPT_initSensorIO                                                 \
        ((void (__cc_rom *)(tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[58])

// ROM Function Definition: CAPT_writeFineGain
#define ROM_CAPT_writeFineGain                                                \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Value))ROM_CAPTIVATE_JUMPTABLE[59])

// ROM Function Definition: CAPT_startCCounter
#define ROM_CAPT_startCCounter                                                \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[60])

// ROM Function Definition: CAPT_applyCycleFSM
#define ROM_CAPT_applyCycleFSM                                                \
        ((void (__cc_rom *)(tCycle *pCycle))ROM_CAPTIVATE_JUMPTABLE[61])

// ROM Function Definition: CAPT_setCAPSTART
#define ROM_CAPT_setCAPSTART                                                  \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[62])

// ROM Function Definition: CAPT_reseedFilter
#define ROM_CAPT_reseedFilter                                                 \
        ((void (__cc_rom *)(IQ16_t *pFilter,                                  \
                            uint16_t ui16ReseedValue))ROM_CAPTIVATE_JUMPTABLE[63])

// ROM Function Definition: CAPT_saveCycleRawResults
#define ROM_CAPT_saveCycleRawResults                                          \
        ((void (__cc_rom *)(uint8_t indexFreq,                                \
                           tSensor *pSensor,                                  \
                            tCycle *pCycle))ROM_CAPTIVATE_JUMPTABLE[64])

// ROM Function Definition: CAPT_updateFSMTouch
#define ROM_CAPT_updateFSMTouch                                               \
        ((void (__cc_rom *)(tSensor *pSensor,                                 \
                            tElement *pElement))ROM_CAPTIVATE_JUMPTABLE[65])

// ROM Function Definition: CAPT_setCAPLPMCFG
#define ROM_CAPT_setCAPLPMCFG                                                 \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[66])

// ROM Function Definition: CAPT_getByteQueueSize
#define ROM_CAPT_getByteQueueSize                                             \
        ((uint16_t (__cc_rom *)(tByteQueue *pQueue))ROM_CAPTIVATE_JUMPTABLE[67])

// ROM Function Definition: CAPT_setChannelActive
#define ROM_CAPT_setChannelActive                                             \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Pin))ROM_CAPTIVATE_JUMPTABLE[68])

// ROM Function Definition: CAPT_pullFromByteQueue
#define ROM_CAPT_pullFromByteQueue                                            \
        ((int8_t (__cc_rom *)(tByteQueue *pQueue,                             \
                              uint8_t *pDestination))ROM_CAPTIVATE_JUMPTABLE[69])

// ROM Function Definition: CAPT_updateFSMProx
#define ROM_CAPT_updateFSMProx                                                \
        ((void (__cc_rom *)(tSensor *pSensor,                                 \
                            tElement *pElement))ROM_CAPTIVATE_JUMPTABLE[70])

// ROM Function Definition: CAPT_disableTimerTrigMeasurement
#define ROM_CAPT_disableTimerTrigMeasurement                                  \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[71])

// ROM Function Definition: CAPT_selectTimerSourceDivider
#define ROM_CAPT_selectTimerSourceDivider                                     \
        ((void (__cc_rom *)(uint8_t sourceDiv))ROM_CAPTIVATE_JUMPTABLE[72])

// ROM Function Definition: CAPT_processButtons
#define ROM_CAPT_processButtons                                               \
        ((void (__cc_rom *)(tSensor *pButtonGroup))ROM_CAPTIVATE_JUMPTABLE[73])

// ROM Function Definition: CAPT_disableRefCap
#define ROM_CAPT_disableRefCap                                                \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[74])

// ROM Function Definition: CAPT_releaseStabilization
#define ROM_CAPT_releaseStabilization                                         \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[75])

// ROM Function Definition: CAPT_enableTimerTrigMeasurement
#define ROM_CAPT_enableTimerTrigMeasurement                                   \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[76])

// ROM Function Definition: CAPT_enableSensorSyncEvent
#define ROM_CAPT_enableSensorSyncEvent                                        \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[77])

// ROM Function Definition: CAPT_bypassFSM
#define ROM_CAPT_bypassFSM                                                    \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[78])

// ROM Function Definition: CAPT_updateLTA
#define ROM_CAPT_updateLTA                                                    \
        ((void (__cc_rom *)(tSensor *pSensor,                                 \
                            tElement *pElement))ROM_CAPTIVATE_JUMPTABLE[79])

// ROM Function Definition: CAPT_readCoarseGain
#define ROM_CAPT_readCoarseGain                                               \
        ((uint8_t (__cc_rom *)(uint8_t ui8Block))ROM_CAPTIVATE_JUMPTABLE[80])

// ROM Function Definition: CAPT_applyCycleComp
#define ROM_CAPT_applyCycleComp                                               \
        ((void (__cc_rom *)(uint8_t freqOffset,                               \
                           tCycle * pCycle))ROM_CAPTIVATE_JUMPTABLE[81])

// ROM Function Definition: CAPT_updateSensorProxTouch
#define ROM_CAPT_updateSensorProxTouch                                        \
        ((void (__cc_rom *)(tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[82])

// ROM Function Definition: CAPT_clearChannelActive
#define ROM_CAPT_clearChannelActive                                           \
        ((void (__cc_rom *)(uint8_t ui8Block,                                 \
                            uint8_t ui8Pin))ROM_CAPTIVATE_JUMPTABLE[83])

// ROM Function Definition: CAPT_getSensorPacket
#define ROM_CAPT_getSensorPacket                                              \
        ((uint16_t (__cc_rom *)(tSensor **sensorArray,                        \
                                uint8_t ui8SensorID,                          \
                                uint8_t *pBuffer))ROM_CAPTIVATE_JUMPTABLE[84])

// ROM Function Definition: CAPT_disableISR
#define ROM_CAPT_disableISR                                                   \
        ((void (__cc_rom *)(uint16_t interruptDisable))ROM_CAPTIVATE_JUMPTABLE[85])

// ROM Function Definition: CAPT_isByteQueueFull
#define ROM_CAPT_isByteQueueFull                                              \
        ((bool (__cc_rom *)(tByteQueue *pQueue))ROM_CAPTIVATE_JUMPTABLE[86])

// ROM Function Definition: CAPT_forceSensorIO
#define ROM_CAPT_forceSensorIO                                                \
        ((void (__cc_rom *)(tSenseTechnology rxBarTx,                         \
                            tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[87])

// ROM Function Definition: CAPT_blockOnFlag
#define ROM_CAPT_blockOnFlag                                                  \
        ((void (__cc_rom *)(volatile bool *pFlag,                             \
                            uint8_t ui8LPM))ROM_CAPTIVATE_JUMPTABLE[88])

// ROM Function Definition: CAPT_loadCycle
#define ROM_CAPT_loadCycle                                                    \
        ((void (__cc_rom *)(tSensor *pSensor,                                 \
                            uint8_t ui8Cycle,                                 \
                            uint8_t ui8Freq,                                  \
                            bool bFSM))ROM_CAPTIVATE_JUMPTABLE[89])

// ROM Function Definition: CAPT_unloadCycle
#define ROM_CAPT_unloadCycle                                                  \
        ((void (__cc_rom *)(tSensor *pSensor,                                 \
                            uint8_t ui8Cycle,                                 \
                            uint8_t ui8Index,                                 \
                            bool bFSM))ROM_CAPTIVATE_JUMPTABLE[90])

// ROM Function Definition: CAPT_startConversion
#define ROM_CAPT_startConversion                                              \
        ((void (__cc_rom *)(volatile bool *pbEndOfConversionFlag))ROM_CAPTIVATE_JUMPTABLE[91])

// ROM Function Definition: CAPT_cleanupAfterConversion
#define ROM_CAPT_cleanupAfterConversion                                       \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[92])

// ROM Function Definition: CAPT_startConversionAndWaitUntilDone
#define ROM_CAPT_startConversionAndWaitUntilDone                              \
        ((void (__cc_rom *)( volatile bool *pbEndOfConversionFlag,            \
                            uint8_t ui8LPM))ROM_CAPTIVATE_JUMPTABLE[93])

// ROM Function Definition: CAPT_clearIFG
#define ROM_CAPT_clearIFG                                                     \
        ((void (__cc_rom *)(uint16_t ui16InterruptMask))ROM_CAPTIVATE_JUMPTABLE[94])

// ROM Function Definition: CAPT_calibrateGain
#define ROM_CAPT_calibrateGain                                                \
        ((void (__cc_rom *)(tSensor *pSensor,                                 \
                            volatile bool *pbEndOfConversionFlag,             \
                            uint8_t ui8Frequency))ROM_CAPTIVATE_JUMPTABLE[95])

// ROM Function Definition: CAPT_calibrateOffset
// ROM function does not handle offset calibration with input bias current,
// also does not handle offset scale.
//#define ROM_CAPT_calibrateOffset                                              \
//        ((void (__cc_rom *)(tSensor *pSensor,                                 \
//                            volatile bool *pbEndOfConversionFlag,             \
//                            uint8_t ui8Frequency))ROM_CAPTIVATE_JUMPTABLE[96])

// ROM Function Definition: CAPT_testForRecalibration
#define ROM_CAPT_testForRecalibration                                         \
        ((bool (__cc_rom *)(tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[97])

// ROM Function Definition: CAPT_flagAllElementsForReseed
#define ROM_CAPT_flagAllElementsForReseed                                     \
        ((void (__cc_rom *)(tSensor* pSensor))ROM_CAPTIVATE_JUMPTABLE[98])

// ROM Function Definition: CAPT_resolveMultiFreqSet
#define ROM_CAPT_resolveMultiFreqSet                                          \
        ((void (__cc_rom *)(const uint16_t *pNewSet,                          \
                            uint16_t *pResult,                                \
                            uint16_t *pNoiseLevel,                            \
                            bool bRemoveOutlier))ROM_CAPTIVATE_JUMPTABLE[99])

// ROM Function Definition: CAPT_updateSensorTimeout
#define ROM_CAPT_updateSensorTimeout                                          \
        ((void (__cc_rom *)(tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[100])

// ROM Function Definition: CAPT_updateSensorNoise
#define ROM_CAPT_updateSensorNoise                                            \
        ((void (__cc_rom *)(tSensor *pSensor))ROM_CAPTIVATE_JUMPTABLE[101])

// ROM Function Definition: CAPT_convertAbsToRel
#define ROM_CAPT_convertAbsToRel                                              \
        ((uint8_t (__cc_rom *)(uint16_t ui16Ref,                              \
                               uint16_t ui16Abs))ROM_CAPTIVATE_JUMPTABLE[102])

// ROM Function Definition: CAPT_convertRelToAbs
#define ROM_CAPT_convertRelToAbs                                              \
        ((uint16_t (__cc_rom *)(uint16_t ui16Ref,                             \
                                uint8_t ui8Rel))ROM_CAPTIVATE_JUMPTABLE[103])

// ROM Function Definition: CAPT_applyAutoMultiFreqCycleComp
#define ROM_CAPT_applyAutoMultiFreqCycleComp                                  \
        ((void (__cc_rom *)(tCycle *pCycle))ROM_CAPTIVATE_JUMPTABLE[104])

// ROM Function Definition: CAPT_selectElectrodeChargeVoltageSource
#define ROM_CAPT_selectElectrodeChargeVoltageSource                           \
        ((void (__cc_rom *)(tElectrodeChargeVoltageSourceSelectStyle electrodeChargeVoltageSourceSelectStyle))ROM_CAPTIVATE_JUMPTABLE[105])

// ROM Function Definition: CAPT_selectOversamplingCount
#define ROM_CAPT_selectOversamplingCount                                      \
        ((void (__cc_rom *)(tOversamplingStyle oversamplingStyle))ROM_CAPTIVATE_JUMPTABLE[106])

// ROM Function Definition: CAPT_isFrequencyHopping
#define ROM_CAPT_isFrequencyHopping                                           \
        ((bool (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[107])

// ROM Function Definition: CAPT_enableFrequencyHopping
#define ROM_CAPT_enableFrequencyHopping                                       \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[108])

// ROM Function Definition: CAPT_disableFrequencyHopping
#define ROM_CAPT_disableFrequencyHopping                                      \
        ((void (__cc_rom *)(void))ROM_CAPTIVATE_JUMPTABLE[109])

// ROM Function Definition: CAPT_computeIIRFilter32
#define ROM_CAPT_computeIIRFilter32                                           \
        ((uint32_t (__cc_rom *)(IQ16_t *pRaw,                                 \
                                IQ16_t *pFiltered,                            \
                                uint8_t ui8Beta))ROM_CAPTIVATE_JUMPTABLE[110])

// ROM Function Definition: CAPT_computeIIRFilterFast32
#define ROM_CAPT_computeIIRFilterFast32                                       \
        ((uint32_t (__cc_rom *)(IQ16_t *pRaw,                                 \
                                IQ16_t *pFiltered,                            \
                                uint8_t ui8Beta))ROM_CAPTIVATE_JUMPTABLE[111])


#else
#error "Small code/data models are not supported"
#endif

#endif // ROM_CAPTIVATE_MSP430FR2676_H_
