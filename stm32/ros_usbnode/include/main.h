/**
  ******************************************************************************
  * @file    main.h
  * @author  Georg Swoboda <cn@warp.at>
  * @brief   main / bootup and initialization, motor control routines, usb init
  ******************************************************************************
  * Version 1.0.0
  *  
  ******************************************************************************
  */

/* USER CODE BEGIN Header */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

typedef enum {
    RX_WAIT,
    RX_VALID,
    RX_CRC_ERROR,
    RX_INVALID_ERROR,
    RX_TIMEOUT_ERROR,
}rx_status_e;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

#define DB_ACTIVE 1
#define DB_TRACE(...)\
            do { if (DB_ACTIVE) debug_printf( __VA_ARGS__); } while (0)

void ADC_Test();
float ADC_BatteryVoltage(uint8_t adc_conversions);
float ADC_ChargeVoltage(uint8_t adc_conversions);
float ADC_ChargeCurrent(uint8_t adc_conversions);
void ChargeController(void);
void EmergencyController(void);
void StatusLEDUpdate(void);
void setDriveMotors(uint8_t left_speed, uint8_t right_speed, uint8_t left_dir, uint8_t right_dir);
void setBladeMotor(uint8_t on_off);
uint8_t crcCalc(uint8_t *msg, uint8_t msg_len);
void msgPrint(uint8_t *msg, uint8_t msg_len);
void chirp(uint8_t count);


extern uint16_t  chargecontrol_pwm_val;
extern uint8_t   chargecontrol_is_charging;
extern uint8_t do_chirp;

// uart statistics
extern uint16_t cnt_uart4_overrun;      // master
extern uint16_t cnt_usart2_overrun;     // drive motors

// SPI3 handle (used by spiflash.c)
extern SPI_HandleTypeDef SPI3_Handle;

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

void LED_Init();
void TF4_Init();
void RAIN_Sensor_Init();
void PAC5210RESET_Init();
void MASTER_USART_Init();
void DRIVEMOTORS_USART_Init();
void SystemClock_Config();
void ADC1_Init(void);
void TIM1_Init(void);
void TIM2_Init(void);
void TIM3_Init(void);
void MX_DMA_Init(void);
void Emergency_Init(void);
void SPI3_Init();
void SPI3_DeInit();


// UART Wrapper functions to hide HAL bullshit ...
void MASTER_Transmit(uint8_t *buffer, uint8_t len);
void DRIVEMOTORS_Transmit(uint8_t *buffer, uint8_t len);

// Sensor Wrapper functions
int RAIN_Sense(void);
int HALLSTOP_Left_Sense(void);
int HALLSTOP_Right_Sense(void);

void debug_printf(const char *fmt, ...);


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
