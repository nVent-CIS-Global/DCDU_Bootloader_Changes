#ifndef _UTIL_H
#define _UTIL_H
#include "config.h"

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include <string.h>

//typedef  unsigned short uint16_t ;
//typedef  signed short int16_t ;
//typedef  unsigned char uint8_t ;
//typedef  signed char int8_t ;
//typedef  unsigned int  uint32_t ;
//typedef  signed int  int32_t ;



#define SENSOR_SERIAL_LEN				9
#define SENSOR_NAME_LEN					16
#define SENSOR_DESCRIPTION_LEN			16
#define SENSOR_LOCATION_LEN				16
#define SENSOR_ALARM_LEN				8

#define SENSOR_SERIAL_OFFSET			0
#define SENSOR1_NAME_OFFSET				11
#define SENSOR2_NAME_OFFSET				27
#define SENSOR3_NAME_OFFSET				43
#define SENSOR4_NAME_OFFSET				59

#define SENSOR1_DESCRIPTION_OFFSET		75
#define SENSOR2_DESCRIPTION_OFFSET		91
#define SENSOR3_DESCRIPTION_OFFSET		107
#define SENSOR4_DESCRIPTION_OFFSET		123

#define SENSOR1_LOCATION_OFFSET			139
#define SENSOR2_LOCATION_OFFSET			155
#define SENSOR3_LOCATION_OFFSET			171
#define SENSOR4_LOCATION_OFFSET			187

#define SENSOR1_ALARM_OFFSET			203
#define SENSOR2_ALARM_OFFSET			211
#define SENSOR3_ALARM_OFFSET			219
#define SENSOR4_ALARM_OFFSET			227

#define SENSOR_HIDAUTOCLOSE_OFFSET		250

#define ADD_SENSOR_NAME_OFFSET		    (SENSOR_HIDAUTOCLOSE_OFFSET+SENSOR_ALARM_LEN)
#define SENSOR5_NAME_OFFSET				(ADD_SENSOR_NAME_OFFSET)
#define SENSOR6_NAME_OFFSET				(SENSOR5_NAME_OFFSET+SENSOR_NAME_LEN)

#define ADD_SENSOR_DESCRIPTION_OFFSET	(SENSOR6_NAME_OFFSET + SENSOR_NAME_LEN)
#define SENSOR5_DESCRIPTION_OFFSET		(ADD_SENSOR_DESCRIPTION_OFFSET)
#define SENSOR6_DESCRIPTION_OFFSET		(SENSOR5_DESCRIPTION_OFFSET + SENSOR_DESCRIPTION_LEN)

#define ADD_SENSOR_LOCATION_OFFSET      (SENSOR6_DESCRIPTION_OFFSET+SENSOR_DESCRIPTION_LEN)
#define SENSOR5_LOCATION_OFFSET			(ADD_SENSOR_LOCATION_OFFSET)
#define SENSOR6_LOCATION_OFFSET			(SENSOR5_LOCATION_OFFSET+SENSOR_LOCATION_LEN)

#define ADD_SENSOR_ALARM_OFFSET         (SENSOR6_LOCATION_OFFSET+SENSOR_LOCATION_LEN)
#define SENSOR5_ALARM_OFFSET			(ADD_SENSOR_ALARM_OFFSET)
#define SENSOR6_ALARM_OFFSET			(SENSOR5_ALARM_OFFSET+SENSOR_ALARM_LEN)

#define CFG_START_OFFSET                (SENSOR6_ALARM_OFFSET + SENSOR_ALARM_LEN)   // == 0x172 == 372 Bytes == 2976 bits
// EEPROM = AT25640B = 64Kbit

#define cfgoffsetof(st, m) ((size_t)&(((st *)CFG_START_OFFSET)->m))
#define member_size(type, member) sizeof(((type *)0)->member)


struct hCfg
{
   uint16_t hwVer;
   uint8_t  keyPadEn;
   uint8_t  readerEn;
   uint8_t  statusLedMode;
   uint8_t  xstatusLedColor;
   uint16_t idleTime;
   uint16_t doorOpenTime;
   uint32_t maxDoorOpenTime;
   uint16_t autoLockTime;
   float regValtage;
   float adcRes1;
   float adcRes2;
   float adcRes3;
   char hum_a;
   char hum_b;
   char hum_c;
   uint8_t boot;
};



#define DOOR_OPEN	0
#define DOOR_CLOSE	1

#define DOOR_CTRL_OPEN	1
#define DOOR_CTRL_CLOSE	0


#define EEPROM_CS_IO			(LATAbits.LATA1)
#define EEPROM_CS_TRIS			(TRISAbits.TRISA1)
#define EEPROM_SDO_TRIS			(TRISAbits.TRISA6)
#define EEPROM_SCK_TRIS			(TRISBbits.TRISB4)
#define EEPROM_SDI_TRIS			(TRISBbits.TRISB1)
#define EEPROM_SDO_SEL          (APFCON0bits.SDO1SEL)
#define EEPROM_SPI_IF			(PIR1bits.SSP1IF)
#define EEPROM_SPI_IE			(PIE1bits.SSP1IE)
#define EEPROM_SSPBUF			(SSP1BUF)
#define EEPROM_SPICON1			(SSP1CON1)
#define EEPROM_SPICON1bits		(SSP1CON1bits)
#define EEPROM_SPISTAT			(SSP1STAT)
#define EEPROM_SPISTATbits		(SSP1STATbits)
#define ClearSPIDoneFlag()      {EEPROM_SPI_IF = 0;}
#define WaitForDataByte()       {while(!EEPROM_SPI_IF); EEPROM_SPI_IF = 0;}
#define SPI_ON_BIT              (EEPROM_SPICON1bits.SSPEN)

// EEPROM SPI opcodes
#define OPCODE_READ    0x03    // Read data from memory array beginning at selected address
#define OPCODE_WRITE   0x02    // Write data to memory array beginning at selected address
#define OPCODE_WRDI    0x04    // Reset the write enable latch (disable write operations)
#define OPCODE_WREN    0x06    // Set the write enable latch (enable write operations)
#define OPCODE_RDSR    0x05    // Read Status register
#define OPCODE_WRSR    0x01    // Write Status register

#define EEPROM_BUFFER_SIZE              (32)
/*
void spi_eeprominit(void);
void spi_eeprom_read_byte(ulong addr, uchar *data);
void spi_eeprom_write_byte(ulong addr, uchar data);
*/


uchar eepromisbusy(void);

void eeprom_read_string(uint offset, uchar * data, uchar datalen);
void eeprom_write_string(uint offset, uchar * data, uchar datalen);

ulong get_rand(void);
void Delay(ulong delay_count_max);
void rs485bufferclear(uchar * bbufer, uchar len);
void rs485buffercopy(uchar* dest, uchar* src, uchar len);
void rs485bufferclear_long(ulong * bbufer, uchar len);


#ifdef UTIL_GOBAL
#define UTIL_GOBAL
#else 
#define UTIL_GOBAL extern
#endif

UTIL_GOBAL uchar calculateCRC8(uchar * inData, uchar dataLen);
UTIL_GOBAL int16_t cali_sensor(uint16_t adValue);



#endif
