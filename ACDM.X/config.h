#ifndef _CONFIG_H
#define _CONFIG_H
//#include <htc.h>

typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef signed char schar;
typedef signed long slong;
typedef signed int sint;
typedef unsigned long long u64_t;
typedef unsigned int u32_t;


#define READER_UART


#define RS485_RX_IDLE			0
#define RS485_RX_RECIEVE		1


#define E_STATUS RB3
#define M_STATUS RA2

#define LOGIC_SENSOR_NUM	6

#define DOOR_SWITCH_PIN_ON			1
#define DOOR_SWITCH_PIN_OFF			0
#define DOOR_SWITCH_STATUS_ON		1
#define DOOR_SWITCH_STATUS_OFF		0

#define DOOR_OPEN   0
#define DOOR_CLOSED  1 


/* GPIO Pin Definition */
#define GPIO_PORT_FRONTOC_EN GPIOA
#define GPIO_PIN_FRONTOC_EN GPIO_PIN_12

#define GPIO_PORT_FRONTOC GPIOB
#define GPIO_PIN_FRONTOC GPIO_PIN_4

#define GPIO_PORT_REAROC_EN GPIOB
#define GPIO_PIN_REAROC_EN	GPIO_PIN_7
#define GPIO_PORT_REAROC GPIOB
#define GPIO_PIN_REAROC GPIO_PIN_9

#define GPIO_PORT_MLOCKOC_EN GPIOB
#define GPIO_PIN_MLOCKOC_EN GPIO_PIN_3
#define GPIO_PORT_MLOCKOC GPIOA
#define GPIO_PIN_MLOCKOC GPIO_PIN_15

#define GPIO_PORT_CW GPIOF
#define GPIO_PIN_CW GPIO_PIN_0
#define GPIO_PORT_CCW GPIOF
#define GPIO_PIN_CCW GPIO_PIN_1

/* EEPROM Control */
#define GPIO_PIN_EEPROM_CS GPIO_PIN_0
#define GPIO_PORT_EEPROM_CS GPIOB

/* GPIO IIC */
#define IIC_SDA_Pin	GPIO_PIN_13
#define IIC_SCK_Pin GPIO_PIN_14
#define IIC_SCK_GPIO_Port GPIOC
#define IIC_SDA_GPIO_Port GPIOC

/* RS485 Enable */
#define GPIO_PORT_RS485_EN GPIOB
#define GPIO_PIN_RS485_EN GPIO_PIN_11

/* Aisle Definition */
#define GPIO_PORT_AISLE GPIOC
#define GPIO_PIN_AISLE GPIO_PIN_15

#define HID_26F						26
#define HID_35F						35

//#define fwVer  ('0'<<24 + '1'<<16 + '0'<<8 + '0'<<0 )

#endif
