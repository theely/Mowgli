

#ifndef __BOARD_H
#define __BOARD_H

#ifdef __cplusplus
extern "C"
{
#endif

    // this is the sofware version that any other Mowgli components like MowgliRover will match against

#define MOWGLI_SW_VERSION_MAJOR 1
#define MOWGLI_SW_VERSION_BRANCH 11 /* even = stable, odd = testing/unstable */
#define MOWGLI_SW_VERSION_MINOR 1

/********************************************************************************
 * BOARD SELECTION
 * the specific board setting are set a the end of this file
 ********************************************************************************/



/********************************************************************************
* PIN MAPPING



B2  GPIO LED - GPIO_MODE_OUTPUT_PP GPIO_PULLDOWN GPIO_SPEED_HIGH 
C5  GPIO 24V Enable- GPIO_MODE_OUTPUT_PP GPIO_NOPULL GPIO_SPEED_HIGH
E14 GPIO Blade Motor nRESET - (HIGH for no RESET) GPIO_MODE_OUTPUT_PP GPIO_NOPULL GPIO_SPEED_HIGH
E15 GPIO Drive Motors - HC366 OE Pins (LOW to enable) GPIO_MODE_OUTPUT_PP GPIO_NOPULL GPIO_SPEED_HIGH
E8  TIM1_CH1N Charge Control Pins - HighSide/LowSide MosFET  
E9  TIM1_CH1 Charge Control Pins - HighSide/LowSide MosFET 
C0  GPIO Stop button - yellow (HIGH when pressed) GPIO_MODE_INPUT GPIO_PULLDOWN
TODO: CONFLICT UART6 - C8  GPIO Stop button - white (HIGH when pressed)  GPIO_MODE_INPUT GPIO_PULLDOWN
A8  GPIO Mechanical tilt - (HIGH when set) GPIO_MODE_INPUT GPIO_PULLDOWN
B3  SPI3 Flash CLK
B4  SPI3 Flash MISO
B5  SPI3 Flash MISI
A15 GPIO  Flash nCS  GPIO_MODE_OUTPUT_PP GPIO_PULLUP GPIO_SPEED_HIGH 
D0  GPIO Wheel lift blue GPIO_MODE_INPUT GPIO_PULLDOWN
D1  GPIO Wheel lift red  GPIO_MODE_INPUT GPIO_PULLDOWN
TODO: CONFLICT UART6 - C7  GPIO Play button - (LOW when pressed) GPIO_MODE_INPUT GPIO_PULLUP
B13 GPIO Home button - (LOW when pressed) GPIO_MODE_INPUT GPIO_PULLUP
E2  GPIO Rain Sensor - (LOW when active)  GPIO_MODE_INPUT GPIO_PULLUP
D2  GPIO STOP HALL Sensor - (HIGH when set) TODO: find config
D3  GPIO STOP HALL Sensor - (HIGH when set) TODO: find config
[not used] A10 UART1 RX - Master UART Port J16
[not used] A9  UART1 TX - Master UART Port J16
TODO: NOT FOUND C11 UART4 RX (DMA) - Master UART Red Port J18 (DMA)
TODO: NOT FOUND C10 UART4 TX (DMA) - Master UART Red Port J18
D6  UART2 RX (DMA) - Driver motros 
D5  UART2 TX (DMA) - Driver motros 
TODO: Check new port C7 or A12  - B11 UART6 RX (DMA) - Blade motoror 
TODO: Check new port C6 or A11 - B10 UART6 TX (DMA) - Blade motor
A12 USB_DP
A11 USB_DM
A10 UART1 RX (DMA) - Panle UART Port J16
A9  UART1 TX (DMA) - Panle UART Port J16
[not used] B3  GPIO SOFT I2C
[not used] B4  GPIO SOFT I2C
A1  ADC1 - Charge Current
A2  ADC1 - Charge Voltage
A3  ADC1 - Battery Voltage
A7  ADC1 - Charger Voltage
C2  ADC1 - Blade NTC
A6  ADC1 (DMA) - Perimeter
H0  RCC HSE - External crystal 8Mhz
H1  RCC HSE - External crystal 8Mhz
/********************************************************************************




 #define BOARD_YARDFORCE500 1
//#define BOARD_LUV1000RI 1

#define IMU_ALTIMU 
//#define IMU_WT901 

/* definition type don't modify */
#define DEBUG_TYPE_NONE 0
#define DEBUG_TYPE_UART 1
#define DEBUG_TYPE_SWO 2

/* Publish Mowgli Topics */
//#define ROS_PUBLISH_MOWGLI

/* different type of panel are possible */
#define PANEL_TYPE_NONE 0
#define PANEL_TYPE_YARDFORCE_500_CLASSIC 1
#define PANEL_TYPE_YARDFORCE_LUV1000RI 2
#define PANEL_TYPE_YARDFORCE_900_ECO 3

#define BOARD_YARDFORCE500 true //TODO: find proper way to define this

#if defined(BOARD_YARDFORCE500)
#define PANEL_TYPE PANEL_TYPE_YARDFORCE_500_CLASSIC
#define BLADEMOTOR_LENGTH_RECEIVED_MSG 16
#define DEBUG_TYPE 0

#define OPTION_ULTRASONIC 0
#define OPTION_BUMPER 0
#elif defined(BOARD_LUV1000RI)
#define PANEL_TYPE PANEL_TYPE_YARDFORCE_LUV1000RI
#define BLADEMOTOR_LENGTH_RECEIVED_MSG 14

#define DEBUG_TYPE 0

#define OPTION_ULTRASONIC 1
#define OPTION_BUMPER 0
#else

#error "No board selection"
#endif

// define to support IMU Calibration (Mag) via https://github.com/pcdangio/ros-calibration_imu
// #define SUPPORT_ROS_CALIBRATION_IMU           1

// #define I_DONT_NEED_MY_FINGERS              1      // disables EmergencyController() (no wheel lift, or tilt sensing and stopping the blade anymore)

/// nominal max charge current is 1.0 Amp
#define MAX_CHARGE_CURRENT 1.0f
/// limite voltag when switching in 150mA mode
#define LIMIT_VOLTAGE_150MA 28.0f
/// Max voltage allowed 29.4
#define MAX_CHARGE_VOLTAGE 29.0f
/// Max battery voltage allowed
#define BAT_CHARGE_CUTOFF_VOLTAGE 28.0f
/// We consider the battery is full when in CV mode the current below 0.1A
#define CHARGE_END_LIMIT_CURRENT 0.08f
// if voltage is greater than this assume we are docked
#define MIN_DOCKED_VOLTAGE 20.0f
// if voltage is lower this assume battery is disconnected
#define MIN_BATTERY_VOLTAGE 5.0f

// if current is greater than this assume the battery is charging
#define MIN_CHARGE_CURRENT 0.1f
#define LOW_BAT_THRESHOLD 25.2f /* near 20% SOC */
#define LOW_CRI_THRESHOLD 23.5f /* near 0% SOC */

// Emergency sensor timeouts
#define WHEEL_LIFT_EMERGENCY_MILLIS 1000
#define TILT_EMERGENCY_MILLIS 500 // used for both the mechanical and accelerometer based detection
#define STOP_BUTTON_EMERGENCY_MILLIS 100
#define PLAY_BUTTON_CLEAR_EMERGENCY_MILLIS 2000
#define IMU_ONBOARD_INCLINATION_THRESHOLD 0x38 // stock firmware uses 0x2C (way more allowed inclination)

// IMU configuration options
// #define IMU_ONBOARD_ACCELERATION            0
// #define IMU_ONBOARD_TEMP                    1
#define IMU_ACCELERATION 1 // external IMU
#define IMU_ANGULAR 1      // external IMU

// we use J18 (Red 9 pin connector as Master Serial Port)
#define MASTER_J18 1

// enable Drive and Blade Motor UARTS
#define DRIVEMOTORS_USART_ENABLED 1
#define BLADEMOTOR_USART_ENABLED 1
//#define PANEL_USART_ENABLED 1

// our IMU hangs of a bigbanged I2C bus on J18
#define SOFT_I2C_ENABLED 1

#define LED_PIN GPIO_PIN_2
#define LED_GPIO_PORT GPIOB
#define LED_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()

/* 24V Supply */
#define TF4_PIN GPIO_PIN_5
#define TF4_GPIO_PORT GPIOC
#define TF4_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()

/* Blade Motor nRESET - (HIGH for no RESET) */
#define PAC5223RESET_PIN GPIO_PIN_14
#define PAC5223RESET_GPIO_PORT GPIOE
#define PAC5223RESET_GPIO_CLK_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE()

/* Drive Motors - HC366 OE Pins (LOW to enable) */
#define PAC5210RESET_PIN GPIO_PIN_15
#define PAC5210RESET_GPIO_PORT GPIOE
#define PAC5210RESET_GPIO_CLK_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE()

/* Charge Control Pins - HighSide/LowSide MosFET */
#define CHARGE_LOWSIDE_PIN GPIO_PIN_8
#define CHARGE_HIGHSIDE_PIN GPIO_PIN_9
#define CHARGE_GPIO_PORT GPIOE
#define CHARGE_GPIO_CLK_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE();

/* Stop button - (HIGH when pressed) */
#define STOP_BUTTON_YELLOW_PIN GPIO_PIN_0
#define STOP_BUTTON_YELLOW_PORT GPIOC
#define STOP_BUTTON_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define STOP_BUTTON_WHITE_PIN GPIO_PIN_8
#define STOP_BUTTON_WHITE_PORT GPIOC

/* Mechanical tilt - (HIGH when set) */
#define TILT_PIN GPIO_PIN_8
#define TILT_PORT GPIOA
#define TILT_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

/* SPI3 Flash */
#define FLASH_CLK_PIN GPIO_PIN_3  // GPIO B
#define FLASH_MISO_PIN GPIO_PIN_4 // GPIO B
#define FLASH_MOSI_PIN GPIO_PIN_5 // GPIO B
#define FLASH_SPI_PORT GPIOB
#define FLASH_SPI_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define FLASH_nCS_PIN GPIO_PIN_15 // GPIO A
#define FLASH_SPICS_PORT GPIOA
#define FLASH_SPICS_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

/* Wheel lift - (HIGH when set) */
#define WHEEL_LIFT_BLUE_PIN GPIO_PIN_0
#define WHEEL_LIFT_BLUE_PORT GPIOD
#define WHEEL_LIFT_GPIO_CLK_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()
#define WHEEL_LIFT_RED_PIN GPIO_PIN_1
#define WHEEL_LIFT_RED_PORT GPIOD

/* Play button - (LOW when pressed) */
#define PLAY_BUTTON_PIN GPIO_PIN_7
#define PLAY_BUTTON_PORT GPIOC
#define PLAY_BUTTON_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()

/* Home button - (LOW when pressed) */
#define HOME_BUTTON_PIN GPIO_PIN_13
#define HOME_BUTTON_PORT GPIOB
#define HOME_BUTTON_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()


/* Rain Sensor - (LOW when active) */
#define RAIN_SENSOR_PIN GPIO_PIN_2
#define RAIN_SENSOR_PORT GPIOE
#define RAIN_SENSOR_GPIO_CLK_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE()

/* STOP HALL Sensor - (HIGH when set) */
#define HALLSTOP_RIGHT_PIN GPIO_PIN_2
#define HALLSTOP_LEFT_PIN GPIO_PIN_3
#define HALLSTOP_PORT GPIOD
#define HALLSTOP_GPIO_CLK_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()

    /* either J6 or J18 can be the master USART port */
#ifdef MASTER_J6
/* USART1 (J6 Pin 1 (TX) Pin 2 (RX)) */
#define MASTER_USART_INSTANCE USART1
#define MASTER_USART_RX_PIN GPIO_PIN_10
#define MASTER_USART_RX_PORT GPIOA
#define MASTER_USART_TX_PIN GPIO_PIN_9
#define MASTER_USART_TX_PORT GPIOA
#define MASTER_USART_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define MASTER_USART_USART_CLK_ENABLE() __HAL_RCC_USART1_CLK_ENABLE()
#define MASTER_USART_IRQ USART1_IRQn
#endif
#ifdef MASTER_J18
/* UART4 (J18 Pin 7 (TX) Pin 8 (RX)) */
#define MASTER_USART_INSTANCE USART1
#define MASTER_USART_RX_PIN GPIO_PIN_11
#define MASTER_USART_RX_PORT GPIOC
#define MASTER_USART_TX_PIN GPIO_PIN_10
#define MASTER_USART_TX_PORT GPIOC
#define MASTER_USART_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define MASTER_USART_USART_CLK_ENABLE() __HAL_RCC_UART4_CLK_ENABLE()
#define MASTER_USART_IRQ USART1_IRQn
#endif

#ifdef DRIVEMOTORS_USART_ENABLED
/* drive motors PAC 5210 (USART2) */
#define DRIVEMOTORS_USART_INSTANCE USART2

#define DRIVEMOTORS_USART_RX_PIN GPIO_PIN_6
#define DRIVEMOTORS_USART_RX_PORT GPIOD

#define DRIVEMOTORS_USART_TX_PIN GPIO_PIN_5
#define DRIVEMOTORS_USART_TX_PORT GPIOD

#define DRIVEMOTORS_USART_GPIO_CLK_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()
#define DRIVEMOTORS_USART_USART_CLK_ENABLE() __HAL_RCC_USART2_CLK_ENABLE()

#define DRIVEMOTORS_USART_IRQ USART2_IRQn
#define DRIVEMOTORS_MSG_LEN 12
#endif

#ifdef BLADEMOTOR_USART_ENABLED
/* blade motor PAC 5223 (USART3) */
#define BLADEMOTOR_USART_INSTANCE USART6

#define BLADEMOTOR_USART_RX_PIN GPIO_PIN_11
#define BLADEMOTOR_USART_RX_PORT GPIOB

#define BLADEMOTOR_USART_TX_PIN GPIO_PIN_10
#define BLADEMOTOR_USART_TX_PORT GPIOB

#define BLADEMOTOR_USART_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define BLADEMOTOR_USART_USART_CLK_ENABLE() __HAL_RCC_USART6_CLK_ENABLE()
#endif

#ifdef PANEL_USART_ENABLED
#define PANEL_USART_INSTANCE USART1

#define PANEL_USART_RX_PIN GPIO_PIN_10
#define PANEL_USART_RX_PORT GPIOA

#define PANEL_USART_TX_PIN GPIO_PIN_9
#define PANEL_USART_TX_PORT GPIOA

#define PANEL_USART_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define PANEL_USART_USART_CLK_ENABLE() __HAL_RCC_USART1_CLK_ENABLE()
#define PANEL_USART_IRQ USART1_IRQn
#endif

// J18 has the SPI3 pins, as we dont use SPI3, we recycle them for I2C Bitbanging (for our Pololu ALtIMU-10v5)
#ifdef SOFT_I2C_ENABLED
#define SOFT_I2C_SCL_PIN GPIO_PIN_3
#define SOFT_I2C_SCL_PORT GPIOB
#define SOFT_I2C_SDA_PIN GPIO_PIN_4
#define SOFT_I2C_SDA_PORT GPIOB

#define SOFT_I2C_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE();
#endif

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_H */
