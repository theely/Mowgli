EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 10
Title "Project Mowgli"
Date "2022-05-22"
Rev "1.0.1"
Comp ""
Comment1 "(c) CyberNet / cn@warp.at"
Comment2 "https://github.com/cloudn1ne/Mowgli"
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	4200 3100 3500 3100
Wire Wire Line
	4200 3200 3500 3200
$Sheet
S 1700 4150 1800 900 
U 628CB5EF
F0 "PAC5223QM (Blade Motor)" 50
F1 "PAC5223QM.sch" 50
F2 "PAC5223_UART_TX" O R 3500 4250 50 
F3 "PAC5223_UART_RX" I R 3500 4350 50 
F4 "PAC5223_nRESET1" I R 3500 4950 50 
F5 "PAC5223_PE0" O R 3500 4600 50 
F6 "PAC5223_PD7" O R 3500 4700 50 
$EndSheet
Wire Wire Line
	4200 4250 3500 4250
Wire Wire Line
	3500 4350 4200 4350
$Sheet
S 7200 2850 2300 5150
U 628D8F35
F0 "STM32F103 (Main CPU)" 50
F1 "STM32F103.sch" 50
F2 "PAC5223_nRESET1" O L 7200 6600 50 
F3 "PAC5210_PC4" U L 7200 3050 50 
F4 "PAC5210_74366_nOE" I L 7200 2950 50 
F5 "PAC5210_PC3" U L 7200 3150 50 
F6 "TF4_24V" O R 9500 2950 50 
F7 "LED" O R 9500 4950 50 
F8 "HC245_STM32_PE10" I L 7200 5450 50 
F9 "HC245_STM32_PE12" I L 7200 5650 50 
F10 "HC245_STM32_PE13" I L 7200 5750 50 
F11 "HC245_STM32_PE11" I L 7200 5550 50 
F12 "HC245_STM32_PB14" I L 7200 3950 50 
F13 "HC245_STM32_PD13" O L 7200 5250 50 
F14 "HC245_STM32_PB8" O L 7200 3350 50 
F15 "HC245_STM32_PB9" O L 7200 3450 50 
F16 "HC245_STM32_PB12" O L 7200 3750 50 
F17 "HC245_STM32_PD5" O L 7200 4850 50 
F18 "HC245_STM32_PD6" I L 7200 4950 50 
F19 "HC245_STM32_PB10" O L 7200 3550 50 
F20 "HC245_STM32_PB11" I L 7200 3650 50 
F21 "HC245_STM32_PC10" O L 7200 4300 50 
F22 "HC245_STM32_PC11" I L 7200 4400 50 
F23 "J6_Pin_1" O L 7200 7500 50 
F24 "J6_Pin_3" I L 7200 7600 50 
F25 "SPI3_DIO" B R 9500 7400 50 
F26 "SPI3_CLK" O R 9500 7500 50 
F27 "SPI3_FLASH_nCS" O R 9500 7600 50 
F28 "SPI3_DO" O R 9500 7300 50 
F29 "ACCEL_SCL" O R 9500 6950 50 
F30 "ACCEL_SDA" O R 9500 7050 50 
F31 "CHARGE_LOW_SIDE_DRIVER" O R 9500 3100 50 
F32 "CHARGE_HIGHSIDE_DRIVER" O R 9500 3200 50 
F33 "Charge_Voltage" I R 9500 3550 59 
$EndSheet
Wire Wire Line
	3500 4950 3600 4950
$Sheet
S 1700 3000 1800 900 
U 628A0B7D
F0 "PAC5210QS (Drive Motors)" 50
F1 "PAC5210QS.sch" 50
F2 "PAC5210_UART_TX" O R 3500 3100 50 
F3 "PAC5210_UART_RX" I R 3500 3200 50 
F4 "PAC5210_PC4" I L 1700 3200 50 
F5 "PAC5210_74366_nOE" I L 1700 3300 50 
F6 "PAC5210_PC3" I L 1700 3100 50 
F7 "PAC5210_PA6" O R 3500 3300 50 
F8 "PAC5210_PE4" O R 3500 3400 50 
$EndSheet
$Comp
L Device:LED D?
U 1 1 628F5BF0
P 10550 4950
F 0 "D?" H 10543 4695 50  0000 C CNN
F 1 "LED" H 10543 4786 50  0000 C CNN
F 2 "" H 10550 4950 50  0001 C CNN
F 3 "~" H 10550 4950 50  0001 C CNN
	1    10550 4950
	-1   0    0    1   
$EndComp
Wire Wire Line
	10400 4950 9500 4950
Entry Wire Line
	7100 3050 7200 3150
Entry Wire Line
	7100 2950 7200 3050
Entry Wire Line
	7100 2850 7200 2950
Entry Wire Line
	1600 3000 1700 3100
Entry Wire Line
	1600 3100 1700 3200
Entry Wire Line
	1600 3200 1700 3300
Wire Bus Line
	1600 2350 7100 2350
Wire Wire Line
	3600 4950 3600 6600
Wire Wire Line
	4200 4600 3500 4600
Wire Wire Line
	4200 4700 3500 4700
Wire Wire Line
	4200 3400 3500 3400
Wire Wire Line
	4200 3300 3500 3300
Text Notes 2400 3200 0    50   Italic 10
USART 2
Text Notes 2400 4350 0    50   Italic 10
USART 3
Wire Wire Line
	3600 6600 7200 6600
Wire Wire Line
	7200 3350 6400 3350
Wire Wire Line
	6400 3450 7200 3450
Wire Wire Line
	7200 3550 6400 3550
Wire Wire Line
	6400 3650 7200 3650
Wire Wire Line
	7200 3750 6400 3750
Wire Wire Line
	6400 3950 7200 3950
Wire Wire Line
	7200 4300 6400 4300
Wire Wire Line
	6400 4400 7200 4400
Wire Wire Line
	7200 4850 6400 4850
Wire Wire Line
	6400 4950 7200 4950
Wire Wire Line
	7200 5250 6400 5250
Wire Wire Line
	6400 5450 7200 5450
Wire Wire Line
	7200 5550 6400 5550
Wire Wire Line
	6400 5650 7200 5650
Wire Wire Line
	7200 5750 6400 5750
Text Notes 6650 5650 0    50   ~ 0
4x PWM
Text Notes 6650 4950 0    50   Italic 10
USART 2
Text Notes 6650 4400 0    50   Italic 10
UART 4
Text Notes 6650 3650 0    50   Italic 10
USART 3
Text Label 10400 2950 0    50   ~ 0
Enable_24V_Motors
$Sheet
S 5550 6950 850  1350
U 62926FC8
F0 "J18 (Red Connector)" 50
F1 "J18 (Red Connector).sch" 50
F2 "J18_Pin_1" I L 5550 7050 50 
F3 "J18_Pin_7" O L 5550 7650 50 
F4 "J18_Pin_8" I L 5550 7750 50 
F5 "J18_Pin_2" U L 5550 7150 50 
F6 "J18_Pin_6" U L 5550 7500 50 
$EndSheet
Entry Wire Line
	4100 6100 4200 6000
Entry Wire Line
	4100 6000 4200 5900
Entry Wire Line
	4100 5900 4200 5800
Wire Bus Line
	4100 6950 4950 6950
Entry Wire Line
	4950 7150 5050 7050
Wire Wire Line
	5550 7050 5050 7050
Entry Wire Line
	4950 7650 5050 7750
Entry Wire Line
	4950 7550 5050 7650
Wire Wire Line
	5550 7750 5050 7750
Wire Wire Line
	5050 7650 5550 7650
Text Notes 4650 6000 0    50   Italic 10
UART 4
Text Notes 5200 7750 0    50   Italic 10
UART 4
$Sheet
S 5550 8700 800  1350
U 6292FE67
F0 "J6 (Control Panel)" 50
F1 "J6 (Control Panel).sch" 50
F2 "J6_Pin_9" U L 5550 9400 50 
F3 "J6_Pin_1" I R 6350 8850 50 
F4 "J6_Pin_3" O R 6350 8950 50 
$EndSheet
Wire Wire Line
	5550 7500 4700 7500
Wire Wire Line
	4700 7500 4700 9400
Wire Wire Line
	4700 9400 5550 9400
$Sheet
S 7500 8650 850  1350
U 62934C83
F0 "J5 (Signal)" 50
F1 "J5 (Signal).sch" 50
F2 "J5_Pin_1" U L 7500 8750 50 
F3 "J5_Pin_4" I L 7500 9100 50 
F4 "J5_Pin_5" I L 7500 9200 50 
$EndSheet
Entry Wire Line
	4100 5150 4200 5050
Entry Wire Line
	4100 5050 4200 4950
Wire Bus Line
	4100 5050 4100 5150
Wire Bus Line
	4100 5150 3950 5150
Wire Bus Line
	3950 5150 3950 6400
Wire Bus Line
	3950 6400 6900 6400
Entry Wire Line
	7400 9200 7500 9100
Entry Wire Line
	7400 9300 7500 9200
Wire Bus Line
	7400 9300 7400 9200
Wire Bus Line
	6900 9200 6900 6400
Wire Bus Line
	6900 9200 7400 9200
Entry Wire Line
	7100 7500 7200 7600
Entry Wire Line
	7100 7400 7200 7500
Entry Wire Line
	6350 8850 6450 8950
Entry Wire Line
	6350 8950 6450 9050
Wire Bus Line
	6450 8750 7050 8750
Wire Bus Line
	7050 8750 7050 7550
Wire Bus Line
	7050 7550 7100 7550
Text Notes 7650 7600 0    50   Italic 10
USART 1
Text Notes 5600 8950 0    50   Italic 10
USART 1
Entry Wire Line
	9500 7400 9600 7500
Entry Wire Line
	9500 7500 9600 7600
Entry Wire Line
	9500 7600 9600 7700
$Sheet
S 12300 6450 1700 1850
U 6293F03E
F0 "SPI and I2C" 50
F1 "SPI_I2C.sch" 50
F2 "SPI3_DIO" B L 12300 7350 50 
F3 "SPI3_CLK" I L 12300 7450 50 
F4 "SPI3_FLASH_nCS" B L 12300 7550 50 
F5 "SPI3_DO" O L 12300 7250 50 
F6 "ACCEL_SCL" I L 12300 6650 50 
F7 "ACCEL_SDA" I L 12300 6750 50 
$EndSheet
Entry Wire Line
	9500 7300 9600 7400
Entry Wire Line
	12200 7650 12300 7550
Entry Wire Line
	12200 7550 12300 7450
Entry Wire Line
	12200 7450 12300 7350
Entry Wire Line
	12200 7350 12300 7250
Wire Bus Line
	12200 7800 9600 7800
Entry Wire Line
	12200 6850 12300 6750
Entry Wire Line
	12200 6750 12300 6650
Entry Wire Line
	9500 7050 9600 7150
Entry Wire Line
	9500 6950 9600 7050
Wire Bus Line
	9600 7200 12200 7200
Text Notes 10800 7750 0    50   Italic 10
SPI3
Text Notes 12500 800  0    118  ~ 24
Project Mowgli - System Architecture
$Sheet
S 4200 2900 2200 3250
U 628B14E1
F0 "HC245" 50
F1 "HC245.sch" 50
F2 "PAC5210_UART_TX" I L 4200 3100 50 
F3 "PAC5210_UART_RX" O L 4200 3200 50 
F4 "PAC5223_UART_TX" I L 4200 4250 50 
F5 "PAC5223_UART_RX" O L 4200 4350 50 
F6 "J5_Pin_5" O L 4200 5050 50 
F7 "J5_Pin_4" O L 4200 4950 50 
F8 "J18_Pin_1" O L 4200 5800 50 
F9 "J18_Pin_7" O L 4200 5900 50 
F10 "PAC5223_PD7" I L 4200 4700 50 
F11 "PAC5223_PE0" I L 4200 4600 50 
F12 "PAC5210_PA6" I L 4200 3300 50 
F13 "PAC5210_PE4" I L 4200 3400 50 
F14 "J11_Pin_6" I L 4200 5450 50 
F15 "HC245_STM32_PE10" O R 6400 5450 50 
F16 "HC245_STM32_PE11" O R 6400 5550 50 
F17 "HC245_STM32_PE12" O R 6400 5650 50 
F18 "HC245_STM32_PE13" O R 6400 5750 50 
F19 "HC245_STM32_PB14" O R 6400 3950 50 
F20 "HC245_STM32_PD6" O R 6400 4950 50 
F21 "HC245_STM32_PB11" O R 6400 3650 50 
F22 "HC245_STM32_PC11" O R 6400 4400 50 
F23 "HC245_STM32_PD5" I R 6400 4850 50 
F24 "HC245_STM32_PB10" I R 6400 3550 50 
F25 "HC245_STM32_PC10" I R 6400 4300 50 
F26 "HC245_STM32_PD13" I R 6400 5250 50 
F27 "HC245_STM32_PB8" I R 6400 3350 50 
F28 "HC245_STM32_PB9" I R 6400 3450 50 
F29 "HC245_STM32_PB12" I R 6400 3750 50 
F30 "J18_Pin_8" I L 4200 6000 50 
$EndSheet
$Sheet
S 12300 2850 1600 1750
U 628DB6FB
F0 "power_charge" 118
F1 "power_charge.sch" 118
F2 "TF4_24V" I L 12300 2950 50 
F3 "CHARGE_LOW_SIDE_DRIVER" I L 12300 3100 50 
F4 "CHARGE_HIGH_SIDE_DRIVER" I L 12300 3200 50 
F5 "Charge_Voltage" O L 12300 3550 59 
$EndSheet
Wire Wire Line
	9500 2950 12300 2950
Wire Wire Line
	12300 3100 9500 3100
Wire Wire Line
	9500 3200 12300 3200
Wire Wire Line
	12300 3550 9500 3550
Wire Bus Line
	6450 8750 6450 9050
Wire Bus Line
	7100 7400 7100 7550
Wire Bus Line
	9600 7050 9600 7200
Wire Bus Line
	12200 6750 12200 7200
Wire Bus Line
	7100 2350 7100 3050
Wire Bus Line
	1600 2350 1600 3200
Wire Bus Line
	4100 5900 4100 6950
Wire Bus Line
	4950 6950 4950 7650
Wire Bus Line
	12200 7350 12200 7800
Wire Bus Line
	9600 7400 9600 7800
$EndSCHEMATC
