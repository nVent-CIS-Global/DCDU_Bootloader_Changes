 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include <stdio.h>
#include <string.h>
#include "common.h"

#define Slave1_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define Slave1_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define RA5_GetValue()              PORTAbits.RA5

#define READ_CMD                    0x01
#define READ_CMD_SIZE               0x02
#define READ_MSG_SIZE               0x03
#define WRITE_MSG_SIZE              0x05

#define VER_REG                     0x001
#define CTRL_REG                    0x002
#define CTEMP_REG                   0x00D
#define EXTEMP_REG                  0x00E
#define VAVG_REG                    0x00F
#define IAVG_REG                    0x010
#define VRMS_REG                    0x011
#define IRMS_REG                    0x012
#define PWR_REG                     0x013
#define VAR_REG                     0x014
#define VA_REG                      0x015
#define FREQ_REG                    0x016
#define AVG_PWR_REG                 0x017
#define PF_REG                      0x018

#define FIFTY_PCT_DUTY              0x7D00

#define UART_RX_BUF_SIZE            128

#define FW_VER                      0x003

#define SLIP_END                    0xC0                                        
#define SLIP_ESC                    0xDB                                        
#define SLIP_ESC_END                0xDC                                        
#define SLIP_ESC_ESC                0xDD   
#define ACK                         0x00                                        
#define NACK                        0x80
#define SLIPCMD_READ                0x10
#define SLIPCMD_BLK_READ            0x20
#define SLIPCMD_WRITE               0x11

#define SLIP_TEMP_REG               0x0000
#define SLIP_FREQ_REG               0x0001
#define SLIP_VOLTAGE_A_REG          0x0007
#define SLIP_VOLTAGE_B_REG          0x0008
#define SLIP_OUTLET_REG             0x0010
#define SLIP_RELAY_REG              0x0288


uint8_t spiTxData[5]={0};        
uint8_t spiRxData[5]={0};
uint8_t uartTxBuffer[64];
uint8_t uartRxBuffer[UART_RX_BUF_SIZE];
volatile uint8_t uartRxBufferHead = 0;
volatile bool validMsg = 0;

uint16_t timer0Count = 0;

volatile bool isTxTransferDone = 0;
volatile bool isRxTransferDone = 0;

volatile bool buttonPressed = 0;
volatile bool ms500elapsed = 0;
bool relayStatus = 0;
bool buttonLatched = 0;

volatile uint8_t uart3RxCount;

uint8_t slotAddress = 0;

bool SPIWriteMessage = 0;

 
typedef enum
{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    OFF          
} rgbState;

rgbState rgb = RED;

struct measurementObject {
    uint24_t   fwVersion;
    uint24_t   ctrlRegister;
    int24_t    chipTemp;
    int24_t    extTemp;
    int24_t    avgVoltage;
    int24_t    avgCurrent;
    int24_t    rmsVoltage;    
    int24_t    rmsCurrent;
    int24_t    activePower;
    int24_t    reactivePower;
    int24_t    apparentPower;
    int24_t    frequency;
    int24_t    avgActivePower;
    int24_t    powerFactor;
};

struct scaledMeasurementObject {
    uint32_t   fwVersion;
    uint32_t   ctrlRegister;
    int32_t    chipTemp;
    int32_t    extTemp;
    int32_t    avgVoltage;
    int32_t    avgCurrent;
    int32_t    rmsVoltage;    
    int32_t    rmsCurrent;
    int32_t    activePower;
    int32_t    reactivePower;
    int32_t    apparentPower;
    int32_t    frequency;
    int32_t    avgActivePower;
    int32_t    powerFactor;
};

struct splitMeasurementObject {
    uint8_t    chipTemp[4];
    uint8_t    extTemp[4];
    uint8_t    avgVoltage[4];
    uint8_t    avgCurrent[4];
    uint8_t    rmsVoltage[4];    
    uint8_t    rmsCurrent[4];
    uint8_t    activePower[4];
    uint8_t    reactivePower[4];
    uint8_t    apparentPower[4];
    uint8_t    frequency[4];
    uint8_t    avgActivePower[4];
    uint8_t    powerFactor[4];
};

struct measurementObject meterMeasurements;
struct scaledMeasurementObject scaledMeasurements;
struct splitMeasurementObject splitMeasurements;

void INT2_Button_Callback(void)
{
    buttonPressed = 1;
}

// Function to classify the module type
void module_Info(int hw_id_2, int hw_id_1, int hw_id_0) {
    switch ((hw_id_2 << 2) | (hw_id_1 << 1) | hw_id_0) {
        case 0b000:
            printf("Module Type: DCDM10A\n");
            break;
        case 0b001:
            printf("Module Type: DCDM35A\n");
            break;
        case 0b010:
            printf("Module Type: DCDM60A\n");
            break;
        case 0b011:
            printf("Module Type: DCCM25A\n");
            break;
        case 0b100:
            printf("Module Type: ACDM10A\n");
            break;
        case 0b101:
            printf("Module Type: ACDM35A\n");
            break;
        case 0b110:
        case 0b111:
            printf("Module Type: RESERVED\n");
            break;
        default:
            printf("Invalid HW_ID\n");
    }
}

// Function to classify the slot location
uint8_t getSlotAddress(void)
{
    return (uint8_t)((~((DIP_BIT3_GetValue() << 3) | (DIP_BIT2_GetValue() << 2) | (DIP_BIT1_GetValue() << 1) | (DIP_BIT0_GetValue()))) & 0x0F);
}

// Function to classify the version
void version_Info(int ver_id_1, int ver_id_0) {
    switch ((ver_id_1 << 1) | ver_id_0) {
        case 0b00:
            printf("Version: V0\n");
            break;
        case 0b01:
            printf("Version: V1\n");
            break;
        case 0b10:
            printf("Version: V2\n");
            break;
        case 0b11:
            printf("Version: V3\n");
            break;
        default:
            printf("Invalid VER_ID\n");
    }
}
 
void SPITxEventHandler(void)
{
    isTxTransferDone = true;
    while(!UART3_IsTxReady());
    if(SPIWriteMessage)
    {
        __delay_us(40);
        LATDbits.LATD3 = 1;
        SPIWriteMessage = 0;
    }
    __delay_us(40);
}

void SPIRxEventHandler(void)
{
    isRxTransferDone = true;
    __delay_us(10);
    LATDbits.LATD3 = 1;
}

void Timer0OverflowHandler(void)
{
    timer0Count++;
    if (timer0Count >= 500)
    {
        LED_GREEN_L_Toggle();
        timer0Count = 0;
        ms500elapsed = 1;
    }
}

void UARTRxCompleteHandler(void) 
{
    LED_BLUE_L_Toggle();
}

void clearUARTbuffer(void)
{
    memset(uartRxBuffer, 0x00, sizeof(uartRxBuffer));
    uartRxBufferHead = 0;
}

//Fetch the entire contents of the UART buffer at the time
uint8_t readUARTbuffer(uint8_t* RdBuffer)
{
    uint8_t nBytesRead = 0;
    
    while (uart3RxCount != 0)
    {
        RdBuffer[nBytesRead] = UART3_Read();
        nBytesRead++;
    }
    return nBytesRead;
}

void writeUARTBuffer(uint8_t* writeBuffer, uint8_t size)
{
    uint8_t nBytesWritten = 0;
    while (nBytesWritten < size)
    {
        while(!UART3_IsTxReady());
        UART3_Write(writeBuffer[nBytesWritten++]);
    }
    return;
}


uint8_t calculate_crc8(uint8_t *data, uint8_t sz )
{
    uint8_t i = 0, j = 0, crc = 0;

    for(j = 0; j < sz; j++)
    {
        crc ^= *data++;
        for ( i = 0; i < 8; i++ )
        {
            if (( crc & 0x80 ) != 0 )
            {
                crc <<= 1;
                crc ^= 0x07;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}


static void slipPacketSend(uint8_t *data, uint8_t dataSize)                     
{
    uint8_t inputIndex = 0;                                                     //indexing variable for the data array to be sent
    uint8_t outputIndex = 5;                                                    //indexing variable for the finished packet to be sent
    uint8_t crc_out;
                                                                                                                                              
    uartTxBuffer[0] = SLIP_END;                                                 //Packet Structure: 0xC0,ADDR,STAT1,STAT2,CODE,DATA.....,CRC,C0
    uartTxBuffer[1] = slotAddress;
    uartTxBuffer[2] = 0x00;
    uartTxBuffer[3] = 0x00;
    uartTxBuffer[4] = 0x00;
    
    crc_out = calculate_crc8(&data[0],dataSize);
    
    for(inputIndex = 0; inputIndex < dataSize; inputIndex++)
    {
            if(data[inputIndex] == SLIP_END)
            {
                    uartTxBuffer[outputIndex] = SLIP_ESC;
                    uartTxBuffer[outputIndex + 1] = SLIP_ESC_END;
                    outputIndex+=2;
            }
            else if(data[inputIndex] == SLIP_ESC)
            {
                    uartTxBuffer[outputIndex] = SLIP_ESC;
                    uartTxBuffer[outputIndex + 1] = SLIP_ESC_ESC;
                    outputIndex+=2;
            }
            else
            {
                    uartTxBuffer[outputIndex] = data[inputIndex];
                    outputIndex++;
            }
    }
    
    //Append CRC and perform byte replacement if necessary
    if(crc_out != SLIP_ESC && crc_out != SLIP_END)
    {
        uartTxBuffer[outputIndex++] = crc_out;
    }
    else if(crc_out == SLIP_END)
    {
        uartTxBuffer[outputIndex] = SLIP_ESC;
        uartTxBuffer[outputIndex + 1] = SLIP_ESC_END;
        outputIndex+=2;
    }
    else if(crc_out == SLIP_ESC)
    {
        uartTxBuffer[outputIndex] = SLIP_ESC;
        uartTxBuffer[outputIndex + 1] = SLIP_ESC_ESC;
        outputIndex+=2;
    }
        
    uartTxBuffer[outputIndex++] = SLIP_END;
    
    /*
    printf("\r\nResponse packet is : ");
    for(uint8_t index = 0; index < outputIndex; index++)
    {
        printf("%x ",uartTxBuffer[index]);
    }
    //printf("\r\nSending response");
    */
    
    writeUARTBuffer(&uartTxBuffer[0], outputIndex);   
}

void send_ack(void)
{
    uint8_t cmd_res_ack[5] = {0xC0,0x00,0x00,0x00,0xC0};
    cmd_res_ack[1] = slotAddress;
    writeUARTBuffer(&cmd_res_ack[0],0x05);
}

void send_nack(void)
{
    uint8_t cmd_res_nack[5]= {0xC0,0x00,0x80,0x89,0xC0};
    cmd_res_nack[1] = slotAddress;
    writeUARTBuffer(&cmd_res_nack[0], 0x05);
}

void processSLIP(uint8_t* RdBuffer, uint8_t msgSize)
{
    uint8_t crc_in;
    uint8_t cmd_type;
    uint16_t reg_address1,reg_address2;
    uint8_t relay_cmd1,relay_cmd2;
    //uint8_t outputData[4] = {0};    
    
    
    //Holds up to 8 registers contents
    uint8_t dummy_voltageAB[8] = {splitMeasurements.avgVoltage[0], splitMeasurements.avgVoltage[1], splitMeasurements.avgVoltage[2], splitMeasurements.avgVoltage[3],
    splitMeasurements.avgVoltage[0], splitMeasurements.avgVoltage[1], splitMeasurements.avgVoltage[2], splitMeasurements.avgVoltage[3]};                          //represents 240V on VA and 0V VB on 6618 Silergy
    
    
    //Passing dummy voltage for testing
    //uint8_t dummy_voltageAB[8] = {0x00, 0x00, 0x3A, 0xFC, 0x00, 0x00, 0x3A, 0xFC};  
    
    //increase this to 40
    uint8_t dummy_block_read[32] = {splitMeasurements.avgActivePower[0], splitMeasurements.avgActivePower[1], splitMeasurements.avgActivePower[2], splitMeasurements.avgActivePower[3],
    0x00, 0x00, 0x00, 0x00, splitMeasurements.avgCurrent[0], splitMeasurements.avgCurrent[1], splitMeasurements.avgCurrent[2], splitMeasurements.avgCurrent[3],
    splitMeasurements.reactivePower[0], splitMeasurements.reactivePower[1], splitMeasurements.reactivePower[2], splitMeasurements.reactivePower[3],
    splitMeasurements.apparentPower[0], splitMeasurements.apparentPower[1], splitMeasurements.apparentPower[2], splitMeasurements.apparentPower[3], 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    
    
    /*
    //Passing dummy current of 20000 which is 0x00, 0x00, 0x4E, 0x20. 20000 is interpreted as 20000/1000 = 20Amps by NMC
    uint8_t dummy_block_read[32] = {splitMeasurements.avgActivePower[0], splitMeasurements.avgActivePower[1], splitMeasurements.avgActivePower[2], splitMeasurements.avgActivePower[3],
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4E, 0x20,
    splitMeasurements.reactivePower[0], splitMeasurements.reactivePower[1], splitMeasurements.reactivePower[2], splitMeasurements.reactivePower[3],
    splitMeasurements.apparentPower[0], splitMeasurements.apparentPower[1], splitMeasurements.apparentPower[2], splitMeasurements.apparentPower[3], 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    */
    
    
    uint8_t dummy_voltagefrequency[16] = {0xff, 0xff, 0xf7, 0x43, 0x00, 0x00, 0x00, 0x00, splitMeasurements.avgVoltage[0], splitMeasurements.avgVoltage[1], splitMeasurements.avgVoltage[2], splitMeasurements.avgVoltage[3],
    splitMeasurements.avgVoltage[0], splitMeasurements.avgVoltage[1], splitMeasurements.avgVoltage[2], splitMeasurements.avgVoltage[3]};                                                  //represents 60Hz on 6618 Silergy
    
        
	//Button status array
	uint8_t buttonON[4] = {0x00, 0x00, 0x00, 0x01};
	uint8_t buttonOFF[4] = {0x00, 0x00, 0x00, 0x00};
    
    if((RdBuffer[0] == 0xC0 && RdBuffer[msgSize - 1] == 0xC0))
    {
        //printf("\r\nSLIP ends look good");
        crc_in=calculate_crc8(&RdBuffer[2],(msgSize - 4));
        if(RdBuffer[msgSize - 2] == crc_in)
        {
            //printf("\r\nCRC matches!");
            cmd_type = RdBuffer[2];                                             //0x10 = Read, 0x11 = Write, 0x20 = Block Read
            reg_address1 = (uint16_t)((RdBuffer[3] << 8) | RdBuffer[4]);
            switch (cmd_type)
            {
                case SLIPCMD_READ:
                    printf("\r\nRead Cmd");
                    printf("\r\nRegister Address: %x",reg_address1);
                    send_ack();
                    __delay_ms(2);
                    if(msgSize == 9)
                    {
                        slipPacketSend(&dummy_voltageAB[0],8);
                    }
                    else if(msgSize == 13)
                    {
                        slipPacketSend(&dummy_voltagefrequency[0],16);
                    }
                    else if(msgSize == 7)
                    {   //relayStatus = 1;//For Testing Button Press
                        /*Relay read implementation*/
                        if(buttonLatched == 1)
							slipPacketSend(&buttonON[0],4);
						else
							slipPacketSend(&buttonOFF[0],4);
                    }
                    break;
                case SLIPCMD_WRITE:
                    printf("\r\nWrite Cmd");
                    printf("\r\nRegister Address: %x",reg_address1);
                    send_ack();
                    if (reg_address1 == SLIP_RELAY_REG)
                    {
                        relay_cmd1 = RdBuffer[8];
                        relay_cmd2 = RdBuffer[5];
                        //IO_RB3_SetHigh();
                        __delay_ms(2);
                        if(((relay_cmd1 & 0x01) == 0x01) && ((relay_cmd2 & 0x80) == 0x80))
                        {
                            RELAY_EN_SetHigh();
                        }
                        else if(((relay_cmd1 & 0x01) == 0x01) && (relay_cmd2 == 0x00))
                        {
                           // if(!buttonLatched)
                            {   
                                RELAY_EN_SetLow();
                            }
                        }
                        slipPacketSend(&dummy_voltageAB[0],0);                  //Response packet will not contain data, hence the msgSize = 0        
                    }
                    break;
                case SLIPCMD_BLK_READ:
                    printf("\r\nBlock Read Cmd");
                    printf("\r\nRegister Address: %x",reg_address1);
                    send_ack();
                    if (reg_address1 == SLIP_OUTLET_REG)
                    {
                        __delay_ms(2);
                        slipPacketSend(&dummy_block_read[0],32);
                    }
                    break;
                default:
                    printf("\r\nNot a valid command");
                    send_nack();
                    break;
            }
        }
        else 
        {
            send_nack();
        }
    }
    return;
}

void readSLIP(void)
{
    bool startByteFound = 0;
    bool validMsg = 0;
    uint8_t uartMsgCount = 0; 
    uint8_t decodedMsgIndex = 0;
    uint8_t decodedMsg[16] = {0};
    uint8_t msgSize = 0;
    
    //Pull the contents of the UART buffer and append to the local buffer
    uartMsgCount = readUARTbuffer(&uartRxBuffer[uartRxBufferHead]);
    
    //Advance the HEAD of the local buffer to reflect total local buffer size
    uartRxBufferHead += uartMsgCount;
    
    //Only go into the decode if the amount of messages in the local buffer is >= 7, relay read message is exactly 7 bytes
    if(uartRxBufferHead >= 7)
    {
        for (int byteIndex = 0; byteIndex < uartRxBufferHead; byteIndex++)
        {
            //printf("\r\nUART msg %d: %x",byteIndex,uartRxBuffer[byteIndex]);
            if(uartRxBuffer[byteIndex] == 0xC0 && startByteFound == 0)
            {
                startByteFound = 1;
                decodedMsg[decodedMsgIndex++] = uartRxBuffer[byteIndex];
                
                if((uartRxBufferHead - byteIndex) < 7)  // Adjusted to "< 7" to handle exactly 7 bytes long messages
                    return;
            }
            //We have previously found a 0xC0 and we have at least 6 more bytes to decode
            else if(startByteFound)
            {
                if(uartRxBuffer[byteIndex] == 0xC0 && decodedMsgIndex < 6)      //If the message index is < 6, then this C0 is actually a beginning C0
                {
                    decodedMsgIndex = 0;
                    decodedMsg[decodedMsgIndex++] = uartRxBuffer[byteIndex];
                    //If the amount of messages left in the local buffer is less than 7, then we need to append buffer on next loop iteration
                    if((uartRxBufferHead - byteIndex) < 7)
                        return;
                }
                else if(uartRxBuffer[byteIndex] == 0xC0 && decodedMsgIndex >= 6)
                {
                    decodedMsg[decodedMsgIndex++] = uartRxBuffer[byteIndex];
                    if(decodedMsg[1] == slotAddress)
                    {
                        validMsg = 1;
                        msgSize = decodedMsgIndex;
                        //Call the function to take action here..........
                    }
                    else
                    {
                        clearUARTbuffer();
                        return;
                    }
                }
                else if(uartRxBuffer[byteIndex] != 0xC0)
                {
                    decodedMsg[decodedMsgIndex++] = uartRxBuffer[byteIndex];
                    if(decodedMsgIndex > 14)
                    {
                        clearUARTbuffer();
                        return;
                    }                   
                }
            }
            else
            {
                clearUARTbuffer();
                return;
            }
        }
    }
    if(validMsg)
    {   
        /*
        printf("\r\n SLIP Command Packet: ");
        for (int i = 0; i < decodedMsgIndex; i++)
        {
            printf("%x ", decodedMsg[i]);
        }
        printf("\r\n");
        //printf("\r\nValid msg for mod 1");
         */
        clearUARTbuffer();
        processSLIP(&decodedMsg[0], msgSize);
    } 
}

void readRegister(uint8_t address)
{
    spiTxData[0] = READ_CMD;
    spiTxData[1] = (uint8_t) (address << 2);
    SPI1_BufferWrite(&spiTxData[0],READ_CMD_SIZE);
    while(!SPI1_IsTxReady());
    isTxTransferDone = 0;
    SPI1_BufferRead(&spiRxData[0],READ_MSG_SIZE);
    while(!SPI1_IsTxReady());
    isRxTransferDone = 0;
}

uint24_t readUnsignedRegister(uint8_t address)
{
    readRegister(address);
    __delay_us(100);
    return ((uint24_t)spiRxData[0] << 16) | ((uint24_t)spiRxData[1] << 8) | (uint24_t)spiRxData[2];
}

int24_t readSignedRegister(uint8_t address)
{
    readRegister(address);
    __delay_us(100);
    return ((int24_t)spiRxData[0] << 16) | ((int24_t)spiRxData[1] << 8) | (int24_t)spiRxData[2];
}

void writeRegister(uint8_t address, uint8_t msb, uint8_t midbyte, uint8_t lsb)
{
    spiTxData[0] = READ_CMD;
    spiTxData[1] = (uint8_t) ((address << 2) | 0x02);
    spiTxData[2] = msb;
    spiTxData[3] = midbyte;
    spiTxData[4] = lsb;
    
    SPIWriteMessage = 1;

    SPI1_BufferWrite(&spiTxData[0],WRITE_MSG_SIZE);
    while(!SPI1_IsTxReady());
}

void rgbSetGreen(void)
{
    PWM4_16BIT_SetSlice1Output1DutyCycleRegister(0);
    PWM1_16BIT_SetSlice1Output1DutyCycleRegister(0);
    PWM1_16BIT_SetSlice1Output2DutyCycleRegister(FIFTY_PCT_DUTY);
    PWM4_16BIT_LoadBufferRegisters();
    PWM1_16BIT_LoadBufferRegisters();
    rgb = GREEN;
}

void rgbSetRed(void)
{
    PWM4_16BIT_SetSlice1Output1DutyCycleRegister(FIFTY_PCT_DUTY);
    PWM1_16BIT_SetSlice1Output1DutyCycleRegister(0);
    PWM1_16BIT_SetSlice1Output2DutyCycleRegister(0);
    PWM4_16BIT_LoadBufferRegisters();
    PWM1_16BIT_LoadBufferRegisters();
    rgb = RED;
}

void rgbSetYellow(void)
{
    PWM4_16BIT_SetSlice1Output1DutyCycleRegister(0xFF00);
    PWM1_16BIT_SetSlice1Output2DutyCycleRegister(0x0100);
    PWM1_16BIT_SetSlice1Output1DutyCycleRegister(0);
    PWM4_16BIT_LoadBufferRegisters();
    PWM1_16BIT_LoadBufferRegisters();
    rgb = YELLOW;
}

void updateRelayRGB(void)
{   
    if(buttonPressed)
    {
        RELAY_EN_Toggle();
        buttonPressed = 0;
        if(RELAY_EN_GetValue() == 1)
        {
            buttonLatched = 1;
        }
        else
        {
            buttonLatched = 0;
        }
    }
    relayStatus = RELAY_EN_GetValue();
    if(relayStatus)
    {
        FAN_PWR_EN_L_SetLow();
    }
    else if(!relayStatus)
    {
        FAN_PWR_EN_L_SetHigh();
    }
    if(BRKR_CLOSED_L_GetValue() == 0)
    {
        if(relayStatus)                                             //If relay is off
        {
            rgbSetGreen();
            //printf("\n\rGreen flag set");
        }
        else if(!relayStatus)
        {
            rgbSetYellow();
            //printf("\n\rYellow flag set");
        }
    }
    else                                                                        //Breaker is OPEN
    {
        rgbSetRed();
        //printf("\n\rRed flag set");
        /*
        if(ms500elapsed)
        {
            if(rgb == RED)
            {
                rgbSetGreen();
            }
            else 
            {
                rgbSetRed();
            }
            ms500elapsed = 0;
        }*/
    }
}


void updateMeasurements(void)
{
    meterMeasurements.fwVersion = readUnsignedRegister(VER_REG);
    meterMeasurements.chipTemp = readSignedRegister(CTEMP_REG);
    meterMeasurements.avgVoltage = readSignedRegister(VAVG_REG);
    meterMeasurements.avgCurrent = readSignedRegister(IAVG_REG);
    //meterMeasurements.avgCurrent = 20;
    meterMeasurements.activePower = readSignedRegister(PWR_REG);
    meterMeasurements.avgActivePower = readSignedRegister(AVG_PWR_REG);
    meterMeasurements.reactivePower = readSignedRegister(VAR_REG);
    meterMeasurements.apparentPower = readSignedRegister(VA_REG);
    meterMeasurements.powerFactor = readSignedRegister(PF_REG);
    
    
    //printf("\r\nFW Version: %lx",(uint32_t)meterMeasurements.fwVersion);
    //printf("\r\nChip Temp: %lu",(uint32_t)meterMeasurements.chipTemp);
    //printf("\r\nAvg Voltage: %ld",(int32_t)meterMeasurements.avgVoltage);
    //printf("\r\nAvg Current: %ld",(int32_t)meterMeasurements.avgCurrent);
    //printf("\r\nActive Power: %ld",(int32_t)meterMeasurements.activePower);
    //printf("\r\nAverage Active Power: %ld",(int32_t)meterMeasurements.avgActivePower);
    //printf("\r\nApparent Power: %ld",(int32_t)meterMeasurements.apparentPower);
    //printf("\r\nPower Factor: %ld",(int32_t)meterMeasurements.powerFactor);*/
}

void measurementByteSplit(void)
{
    splitMeasurements.chipTemp[0] = (scaledMeasurements.chipTemp >> 24) & 0xFF;
    splitMeasurements.chipTemp[1] = (scaledMeasurements.chipTemp >> 16) & 0xFF;
    splitMeasurements.chipTemp[2] = (scaledMeasurements.chipTemp >> 8) & 0xFF;
    splitMeasurements.chipTemp[3] = scaledMeasurements.chipTemp & 0xFF;
    splitMeasurements.avgVoltage[0] = (scaledMeasurements.avgVoltage >> 24) & 0xFF;
    splitMeasurements.avgVoltage[1] = (scaledMeasurements.avgVoltage >> 16) & 0xFF;
    splitMeasurements.avgVoltage[2] = (scaledMeasurements.avgVoltage >> 8) & 0xFF;
    splitMeasurements.avgVoltage[3] = scaledMeasurements.avgVoltage & 0xFF;
    splitMeasurements.avgCurrent[0] = (scaledMeasurements.avgCurrent >> 24) & 0xFF;
    splitMeasurements.avgCurrent[1] = (scaledMeasurements.avgCurrent >> 16) & 0xFF;
    splitMeasurements.avgCurrent[2] = (scaledMeasurements.avgCurrent >> 8) & 0xFF;
    splitMeasurements.avgCurrent[3] = scaledMeasurements.avgCurrent & 0xFF;
    splitMeasurements.activePower[0] = (scaledMeasurements.activePower >> 24) & 0xFF;
    splitMeasurements.activePower[1] = (scaledMeasurements.activePower >> 16) & 0xFF;
    splitMeasurements.activePower[2] = (scaledMeasurements.activePower >> 8) & 0xFF;
    splitMeasurements.activePower[3] = scaledMeasurements.activePower & 0xFF;
    splitMeasurements.avgActivePower[0] = (scaledMeasurements.avgActivePower >> 24) & 0xFF;
    splitMeasurements.avgActivePower[1] = (scaledMeasurements.avgActivePower >> 16) & 0xFF;
    splitMeasurements.avgActivePower[2] = (scaledMeasurements.avgActivePower >> 8) & 0xFF;
    splitMeasurements.avgActivePower[3] = scaledMeasurements.avgActivePower & 0xFF;
    splitMeasurements.reactivePower[0] = (scaledMeasurements.reactivePower >> 24) & 0xFF;
    splitMeasurements.reactivePower[1] = (scaledMeasurements.reactivePower >> 16) & 0xFF;
    splitMeasurements.reactivePower[2] = (scaledMeasurements.reactivePower >> 8) & 0xFF;
    splitMeasurements.reactivePower[3] = scaledMeasurements.reactivePower & 0xFF;
    splitMeasurements.apparentPower[0] = (scaledMeasurements.apparentPower >> 24) & 0xFF;
    splitMeasurements.apparentPower[1] = (scaledMeasurements.apparentPower >> 16) & 0xFF;
    splitMeasurements.apparentPower[2] = (scaledMeasurements.apparentPower >> 8) & 0xFF;
    splitMeasurements.apparentPower[3] = scaledMeasurements.apparentPower & 0xFF;
    /*
    for (uint8_t i = 0; i < 4; i++)
    {
        printf("\r\nByte%d of avgVoltage: %x",i,splitMeasurements.avgVoltage[i]);
    }
    */
}

void scaleMeasurements(void)
{
    float tempMeasurement;
    float voltageScale = -0.154261;
    float currentScale = -0.162745;
    float powerScale = 3.212163;
    float tempScale = 0.1;                                                      //Need to subtract 2200 after multiplying by 0.1
    
    tempMeasurement = ((float)(meterMeasurements.chipTemp) * tempScale) - 2200;
    scaledMeasurements.chipTemp = (int32_t)tempMeasurement;
    tempMeasurement = (float)(meterMeasurements.avgVoltage) * voltageScale;
    //tempMeasurement = 20000;
    scaledMeasurements.avgVoltage = (int32_t)tempMeasurement;
    tempMeasurement = (float)(meterMeasurements.avgCurrent) * currentScale;
    scaledMeasurements.avgCurrent = (int32_t)tempMeasurement;
    tempMeasurement = (float)(meterMeasurements.activePower) * powerScale;
    scaledMeasurements.activePower = (int32_t)tempMeasurement;
    tempMeasurement = (float)(meterMeasurements.avgActivePower) * powerScale;
    scaledMeasurements.avgActivePower = (int32_t)tempMeasurement;
    tempMeasurement = (float)(meterMeasurements.reactivePower) * powerScale;
    scaledMeasurements.reactivePower = (int32_t)tempMeasurement;
    tempMeasurement = (float)(meterMeasurements.apparentPower) * powerScale;
    scaledMeasurements.apparentPower = (int32_t)tempMeasurement;
        
    //scaledMeasurements.powerFactor = 
    
    //printf("\r\nChip Temp: %lu",(uint32_t)meterMeasurements.chipTemp);
    //printf("\r\nScaled Avg Voltage: %ld",scaledMeasurements.avgVoltage);
    //printf("\r\nScaled Avg Current: %ld",scaledMeasurements.avgCurrent);
    //printf("\r\nActive Power: %ld",scaledMeasurements.activePower);
    //printf("\r\nAverage Active Power: %ld",scaledMeasurements.avgActivePower);
    //printf("\r\nApparent Power: %ld",scaledMeasurements.apparentPower);
    //printf("\r\nPower Factor: %ld",scaledMeasurements.powerFactor);
    measurementByteSplit();
}

//static NVMCTRL_ERROR nmv_err = 0;
static volatile bool writeStatus=false;
uint8_t rxData[128]={0};
uint32_t nBytesRead;

/*****************************************************/
int main(void)
{
    //uint8_t uartMsgCount = 0;
    

    uint24_t registerAddress = 0x000;
    
    
    SYSTEM_Initialize();
    SPI1_TxCompleteCallbackRegister(SPITxEventHandler);
    SPI1_RxCompleteCallbackRegister(SPIRxEventHandler);
    TMR0_OverflowCallbackRegister(Timer0OverflowHandler);
    UART3_RxCompleteCallbackRegister(UARTRxCompleteHandler);
    INT2_SetInterruptHandler(INT2_Button_Callback);
            
    memset(uartRxBuffer, 0x00, sizeof(uartRxBuffer));

    // Enable the Global High Interrupts 
    INTERRUPT_GlobalInterruptHighEnable(); 

    // Enable the Global Low Interrupts 
    INTERRUPT_GlobalInterruptLowEnable(); 
    
    SPI1_Open(HOST_CONFIG500KHZ);
    __delay_ms(5);
    //writeRegister(CTRL_REG, 0x00, 0x18, 0x17);
    
    TMR0_Start();
    slotAddress = getSlotAddress();
    while(NVM_IsBusy());
        
    if(NVM_ERROR != NVM_StatusGet()){
        return ( EXIT_FAILURE );
        //do a system reset, this kills the program
    }
    // Link callback functions
//    SERCOM0_USART_ReadCallbackRegister(usartReadEventHandler, (uintptr_t) NULL);
//    SERCOM0_USART_WriteCallbackRegister(usartWriteEventHandler, (uintptr_t) NULL);

    Main_Menu();
       
    while(1)
    {
        //printf("\r\nSlot Address: %x",slotAddress);
        updateRelayRGB();
        updateMeasurements();    
        scaleMeasurements();
        readSLIP();
    }    
}
