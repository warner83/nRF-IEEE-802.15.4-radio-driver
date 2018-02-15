/* Copyright (c) 2017 - 2018, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this
 *      list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *
 *   3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef NRF_DRIVER_RADIO802154_CONFIG_H__
#define NRF_DRIVER_RADIO802154_CONFIG_H__

#ifdef NRF_DRV_RADIO802154_PROJECT_CONFIG
#include NRF_DRV_RADIO802154_PROJECT_CONFIG
#endif

#include <nrf.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nrf_driver_radio802154_config 802.15.4 driver configuration
 * @{
 * @ingroup nrf_driver_radio802154
 * @brief Configuration of 802.15.4 radio driver for nRF SoC.
 */

/*******************************************************************************
 * @section Radio Driver Configuration.
 ******************************************************************************/

/**
 * @def NRF_DRV_RADIO802154_CCA_MODE
 *
 * CCA Mode used by the driver.
 *
 */
#ifndef NRF_DRV_RADIO802154_CCA_MODE_DEFAULT
#define NRF_DRV_RADIO802154_CCA_MODE_DEFAULT  NRF_RADIO_CCA_MODE_ED
#endif

/**
 * @def NRF_DRV_RADIO802154_CCA_ED_THRESHOLD
 *
 * Energy Detection Threshold used in CCA procedure.
 *
 */
#ifndef NRF_DRV_RADIO802154_CCA_ED_THRESHOLD_DEFAULT
#define NRF_DRV_RADIO802154_CCA_ED_THRESHOLD_DEFAULT  0x2D
#endif

/**
 * @def NRF_DRV_RADIO802154_CCA_CORR_THRESHOLD
 *
 * Correlator Threshold used in CCA procedure.
 *
 */
#ifndef NRF_DRV_RADIO802154_CCA_CORR_THRESHOLD_DEFAULT
#define NRF_DRV_RADIO802154_CCA_CORR_THRESHOLD_DEFAULT  0x2D
#endif

/**
 * @def NRF_DRV_RADIO802154_CCA_CORR_LIMIT
 *
 * Correlator limit used in CCA procedure.
 *
 */
#ifndef NRF_DRV_RADIO802154_CCA_CORR_LIMIT_DEFAULT
#define NRF_DRV_RADIO802154_CCA_CORR_LIMIT_DEFAULT  0x02
#endif

/**
 * @def NRF_DRV_RADIO802154_INTERNAL_IRQ_HANDLING
 *
 * If the driver should internally handle the RADIO IRQ.
 * In case the driver is used in an OS the RADIO IRQ may be handled by the OS and passed to
 * the driver @sa nrf_drv_radio802154_irq_handler(). In this case internal handling should be
 * disabled.
 */

#ifndef NRF_DRV_RADIO802154_INTERNAL_IRQ_HANDLING

#if RAAL_SOFTDEVICE
#define NRF_DRV_RADIO802154_INTERNAL_IRQ_HANDLING 0
#else // RAAL_SOFTDEVICE
#define NRF_DRV_RADIO802154_INTERNAL_IRQ_HANDLING 1
#endif // RAAL_SOFTDEVICE

#endif // NRF_DRV_RADIO802154_INTERNAL_IRQ_HANDLING

/**
 * @def NRF_DRV_RADIO802154_IRQ_PRIORITY
 *
 * Interrupt priority for RADIO peripheral.
 * It is recommended to keep IRQ priority high (low number) to prevent losing frames due to
 * preemption.
 *
 */
#ifndef NRF_DRV_RADIO802154_IRQ_PRIORITY
#define NRF_DRV_RADIO802154_IRQ_PRIORITY  0
#endif

/**
 * @def NRF_DRV_RADIO802154_TIMER_INSTANCE
 *
 * TIMER instance used by FSM for Ack IFS and by FEM module.
 *
 */
#ifndef NRF_DRV_RADIO802154_TIMER_INSTANCE
#define NRF_DRV_RADIO802154_TIMER_INSTANCE NRF_TIMER1
#endif

/**
 * @def NRF_DRV_RADIO802154_EGU_INSTANCE
 *
 * EGU instance used by FSM for synchronize PPIs.
 *
 */
#ifndef NRF_DRV_RADIO802154_EGU_INSTANCE
#define NRF_DRV_RADIO802154_EGU_INSTANCE NRF_EGU0
#endif

/**
 * @def NRF_DRV_RADIO802154_PENDING_SHORT_ADDRESSES
 *
 * Number of slots containing short addresses of nodes for which pending data is stored.
 *
 */
#ifndef NRF_DRV_RADIO802154_PENDING_SHORT_ADDRESSES
#define NRF_DRV_RADIO802154_PENDING_SHORT_ADDRESSES  10
#endif

/**
 * @def NRF_DRV_RADIO802154_PENDING_EXTENDED_ADDRESSES
 *
 * Number of slots containing extended addresses of nodes for which pending data is stored.
 *
 */
#ifndef NRF_DRV_RADIO802154_PENDING_EXTENDED_ADDRESSES
#define NRF_DRV_RADIO802154_PENDING_EXTENDED_ADDRESSES  10
#endif

/**
 * @def NRF_DRV_RADIO802154_RX_BUFFERS
 *
 * Number of buffers in receive queue.
 *
 */
#ifndef NRF_DRV_RADIO802154_RX_BUFFERS
#define NRF_DRV_RADIO802154_RX_BUFFERS  16
#endif

/**
 * @def NRF_DRV_RADIO802154_SHORT_CCAIDLE_TXEN
 *
 * RADIO peripheral can start transmission using short CCAIDLE->TXEN or interrupt handler.
 * If NRF_DRV_RADIO802154_SHORT_CCAIDLE_TXEN is set to 0 interrupt handler is used, otherwise
 * short is used.
 *
 */
#ifndef NRF_DRV_RADIO802154_SHORT_CCAIDLE_TXEN
#define NRF_DRV_RADIO802154_SHORT_CCAIDLE_TXEN  1
#endif

/**
 * @def NRF_DRV_RADIO802154_NOTIFICATION_SWI_PRIORITY
 *
 * Priority of software interrupt used to call notification from 802.15.4 driver.
 *
 */
#ifndef NRF_DRV_RADIO802154_NOTIFICATION_SWI_PRIORITY
#define NRF_DRV_RADIO802154_NOTIFICATION_SWI_PRIORITY 5
#endif

/**
 * @def NRF_DRV_RADIO802154_EXCLUDE_BCC_MATCHING
 *
 * Setting this flag will disable NRF_RADIO_EVENT_BCMATCH handling, and therefore address filtering during frame reception.
 * With this flag set to 1, address filtering is done after receiving a frame, during NRF_RADIO_EVENT_END handling.
 *
 */
#ifndef NRF_DRV_RADIO802154_DISABLE_BCC_MATCHING
#define NRF_DRV_RADIO802154_DISABLE_BCC_MATCHING 0
#endif

/**
 * @def NRF_DRV_RADIO802154_NOTIFY_CRCERROR
 *
 * With this flag set to 1 CRC errors would be notified to upper layers. This requires interrupt handler to be used.
 *
 */
#ifndef NRF_DRV_RADIO802154_NOTIFY_CRCERROR
#define NRF_DRV_RADIO802154_NOTIFY_CRCERROR  1
#endif

/**
 * @def NRF_DRV_RADIO802154_FRAME_TIMESTAMP_ENABLED
 *
 * If timestamps should be added to received frames.
 * Enabling this feature enables @sa nrf_drv_radio802154_received_timsestamp_raw,
 * @sa nrf_drv_radio802154_received_timestamp, @sa nrf_drv_radio802154_transmitted_timestamp_raw and
 * @sa nrf_drv_radio802154_transmitted_timestamp functions that add timestamps to received frames.
 *
 */
#ifndef NRF_DRV_RADIO802154_FRAME_TIMESTAMP_ENABLED
#define NRF_DRV_RADIO802154_FRAME_TIMESTAMP_ENABLED 1
#endif

/**
 * @def NRF_DRV_RADIO802154_COUNTER_TIMER_INSTANCE
 *
 * Timer instance used by FSM for detecting when PSDU is being received.
 *
 * @note This configuration is only used when NRF_RADIO_EVENT_BCMATCH event handling is disabled
 *       (@sa NRF_DRV_RADIO802154_DISABLE_BCC_MATCHING).
 */
#ifndef NRF_DRV_RADIO802154_COUNTER_TIMER_INSTANCE
#define NRF_DRV_RADIO802154_COUNTER_TIMER_INSTANCE NRF_TIMER2
#endif

/*******************************************************************************
 * @section Clock Driver Configuration.
 ******************************************************************************/

/**
 * @def NRF_DRV_RADIO802154_CLOCK_IRQ_PRIORITY
 *
 * Priority of clock interrupt used in standalone clock driver implementation.
 *
 * @note This configuration is only applicable for Clock Abstraction Layer implementation
 *       in nrf_drv_radio802154_clock_nodrv.c.
 *
 */
#ifndef NRF_DRV_RADIO802154_CLOCK_IRQ_PRIORITY
#define NRF_DRV_RADIO802154_CLOCK_IRQ_PRIORITY 10
#endif

/**
 * @def NRF_DRV_RADIO802154_CLOCK_IRQ_PRIORITY
 *
 * Low frequency clock source used in standalone clock driver implementation.
 *
 * @note This configuration is only applicable for Clock Abstraction Layer implementation
 *       in nrf_drv_radio802154_clock_nodrv.c.
 *
 */
#ifndef NRF_DRV_RADIO802154_CLOCK_LFCLK_SOURCE
#define NRF_DRV_RADIO802154_CLOCK_LFCLK_SOURCE NRF_CLOCK_LFCLK_Xtal
#endif

/*******************************************************************************
 * @section RTC Driver Configuration.
 ******************************************************************************/

/**
 * @def NRF_DRV_RADIO802154_RTC_IRQ_PRIORITY
 *
 * Priority of RTC interrupt used in standalone timer driver implementation.
 *
 * @note This configuration is only applicable for Timer Abstraction Layer implementation
 *       in nrf_drv_radio802154_timer_nodrv.c.
 *
 */
#ifndef NRF_DRV_RADIO802154_RTC_IRQ_PRIORITY
#define NRF_DRV_RADIO802154_RTC_IRQ_PRIORITY  6
#endif

/**
 * @def NRF_DRV_RADIO802154_RTC_INSTANCE
 *
 * RTC instance used in standalone timer driver implementation.
 *
 * @note This configuration is only applicable for Timer Abstraction Layer implementation
 *       in nrf_drv_radio802154_timer_nodrv.c.
 *
 */
#ifndef NRF_DRV_RADIO802154_RTC_INSTANCE
#define NRF_DRV_RADIO802154_RTC_INSTANCE  NRF_RTC2
#endif

/**
 * @def NRF_DRV_RADIO802154_RTC_IRQ_HANDLER
 *
 * RTC interrupt handler name used in standalone timer driver implementation.
 *
 * @note This configuration is only applicable for Timer Abstraction Layer implementation
 *       in nrf_drv_radio802154_timer_nodrv.c.
 *
 */
#ifndef NRF_DRV_RADIO802154_RTC_IRQ_HANDLER
#define NRF_DRV_RADIO802154_RTC_IRQ_HANDLER  RTC2_IRQHandler
#endif


/**
 * @def NRF_DRV_RADIO802154_RTC_IRQN
 *
 * RTC Interrupt number used in standalone timer driver implementation.
 *
 * @note This configuration is only applicable for Timer Abstraction Layer implementation
 *       in nrf_drv_radio802154_timer_nodrv.c.
 *
 */
#ifndef NRF_DRV_RADIO802154_RTC_IRQN
#define NRF_DRV_RADIO802154_RTC_IRQN  RTC2_IRQn
#endif


/*******************************************************************************
 * @section CSMA/CA procedure configuration.
 ******************************************************************************/

/**
 * @def NRF_DRV_RADIO802154_CSMA_CA_ENABLED
 *
 * If CSMA-CA procedure should be enabled by the driver. Disabling CSMA-CA procedure improves
 * driver performance.
 *
 */
#ifndef NRF_DRV_RADIO802154_CSMA_CA_ENABLED
#define NRF_DRV_RADIO802154_CSMA_CA_ENABLED 1
#endif

/**
 * @def NRF_DRV_RADIO802154_CSMA_CA_MIN_BE
 *
 * The minimum value of the backoff exponent (BE) in the CSMA-CA algorithm.
 * (IEEE 802.15.4-2015: 6.2.5.1)
 *
 */
#ifndef NRF_DRV_RADIO802154_CSMA_CA_MIN_BE
#define NRF_DRV_RADIO802154_CSMA_CA_MIN_BE 3
#endif

/**
 * @def NRF_DRV_RADIO802154_CSMA_CA_MAX_BE
 *
 * The maximum value of the backoff exponent, BE, in the CSMA-CA algorithm.
 * (IEEE 802.15.4-2015: 6.2.5.1)
 *
 */
#ifndef NRF_DRV_RADIO802154_CSMA_CA_MAX_BE
#define NRF_DRV_RADIO802154_CSMA_CA_MAX_BE 5
#endif

/**
 * @def NRF_DRV_RADIO802154_CSMA_CA_MAX_CSMA_BACKOFFS
 *
 * The maximum number of backoffs the CSMA-CA algorithm will attempt before declaring a channel
 * access failure.
 *
 */
#ifndef NRF_DRV_RADIO802154_CSMA_CA_MAX_CSMA_BACKOFFS
#define NRF_DRV_RADIO802154_CSMA_CA_MAX_CSMA_BACKOFFS 4
#endif

/*******************************************************************************
 * @section ACK timeout feature configuration.
 ******************************************************************************/

/**
 * @def NRF_DRV_RADIO802154_ACK_TIMEOUT_ENABLED
 *
 * If ACK timeout feature should be enabled in the driver.
 *
 */
#ifndef NRF_DRV_RADIO802154_ACK_TIMEOUT_ENABLED
#define NRF_DRV_RADIO802154_ACK_TIMEOUT_ENABLED 1
#endif

/**
 * @def NRF_DRV_RADIO802154_ACK_TIMEOUT_DEFAULT_TIMEOUT
 *
 * Default timeout time in us for ACK timeout feature.
 *
 */
#ifndef NRF_DRV_RADIO802154_ACK_TIMEOUT_DEFAULT_TIMEOUT
#define NRF_DRV_RADIO802154_ACK_TIMEOUT_DEFAULT_TIMEOUT 7000
#endif

/*******************************************************************************
 * @section Transmission start notification feature configuration.
 ******************************************************************************/

/**
 * @def NRF_DRV_RADIO802154_TX_STARTED_NOTIFY_ENABLED
 *
 * If notification of started transmission should be enabled in the driver.
 *
 * @note This feature is enabled by default if Ack Timeout feature or CSMA-CA feature is enabled.
 *       These features depend on notification of transmission start.
 */
#ifndef NRF_DRV_RADIO802154_TX_STARTED_NOTIFY_ENABLED
#if NRF_DRV_RADIO802154_ACK_TIMEOUT_ENABLED ||                                                     \
    NRF_DRV_RADIO802154_CSMA_CA_ENABLED
#define NRF_DRV_RADIO802154_TX_STARTED_NOTIFY_ENABLED 1
#else
#define NRF_DRV_RADIO802154_TX_STARTED_NOTIFY_ENABLED 0
#endif
#endif // NRF_DRV_RADIO802154_TX_STARTED_NOTIFY_ENABLED

/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif // NRF_DRIVER_RADIO802154_CONFIG_H__
