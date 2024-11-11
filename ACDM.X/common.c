/**
  ******************************************************************************
  * @file    IAP/src/common.c 
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    10/15/2010
  * @brief   This file provides all the common functions.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/** @addtogroup IAP
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "ymodem.h"
#include "hwConfig.h"
#include "main.h"
#include "boot.h"
#include "stdio.h"
#include "string.h"
#include "util.h"

/*
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Convert an Integer to a string
  * @param  str: The string
  * @param  intnum: The intger to be converted
  * @retval None
  */

//#define UART_RX_BUF_SIZE            128
//volatile uint8_t uart2RxCount;
//volatile uint8_t uart2RxBufferHead = 0;
//uint8_t uart2TxBuffer[64];
//uint8_t uart2RxBuffer[UART_RX_BUF_SIZE];
//
//void UART2RxCompleteHandler(void) 
//{
//
//}
//
//void clearUART2buffer(void)
//{
//    memset(uart2RxBuffer, 0x00, sizeof(uart2RxBuffer));
//    uart2RxBufferHead = 0;
//}
//
////Fetch the entire contents of the UART buffer at the time
//uint8_t readUART2buffer(uint8_t* RdBuffer)
//{
//    uint8_t nBytesRead = 0;
//    
//    while (uart2RxCount != 0)
//    {
//        RdBuffer[nBytesRead] = UART2_Read();
//        nBytesRead++;
//    }
//    return nBytesRead;
//}
//
//void writeUART2Buffer(uint8_t* writeBuffer, uint8_t size)
//{
//    uint8_t nBytesWritten = 0;
//    while (nBytesWritten < size)
//    {
//        while(!UART2_IsTxReady());
//        UART2_Write(writeBuffer[nBytesWritten++]);
//    }
//    return;
//}


void Int2Str(uint8_t* str, int32_t intnum)
{
  uint32_t i, Div = 1000000000, j = 0, Status = 0;

  for (i = 0; i < 10; i++)
  {
    str[j++] = (intnum / Div) + 48;

    intnum = intnum % Div;
    Div /= 10;
    if ((str[j-1] == '0') & (Status == 0))
    {
      j = 0;
    }
    else
    {
      Status++;
    }
  }
}

/**
  * @brief  Convert a string to an integer
  * @param  inputstr: The string to be converted
  * @param  intnum: The intger value
  * @retval 1: Correct
  *         0: Error
  */
uint32_t Str2Int(uint8_t *inputstr, int32_t *intnum)
{
  uint32_t i = 0, res = 0;
  uint32_t val = 0;

  if (inputstr[0] == '0' && (inputstr[1] == 'x' || inputstr[1] == 'X'))
  {
    if (inputstr[2] == '\0')
    {
      return 0;
    }
    for (i = 2; i < 11; i++)
    {
      if (inputstr[i] == '\0')
      {
        *intnum = val;
        /* return 1; */
        res = 1;
        break;
      }
      if (ISVALIDHEX(inputstr[i]))
      {
        val = (val << 4) + CONVERTHEX(inputstr[i]);
      }
      else
      {
        /* return 0, Invalid input */
        res = 0;
        break;
      }
    }
    /* over 8 digit hex --invalid */
    if (i >= 11)
    {
      res = 0;
    }
  }
  else /* max 10-digit decimal input */
  {
    for (i = 0;i < 11;i++)
    {
      if (inputstr[i] == '\0')
      {
        *intnum = val;
        /* return 1 */
        res = 1;
        break;
      }
      else if ((inputstr[i] == 'k' || inputstr[i] == 'K') && (i > 0))
      {
        val = val << 10;
        *intnum = val;
        res = 1;
        break;
      }
      else if ((inputstr[i] == 'm' || inputstr[i] == 'M') && (i > 0))
      {
        val = val << 20;
        *intnum = val;
        res = 1;
        break;
      }
      else if (ISVALIDDEC(inputstr[i]))
      {
        val = val * 10 + CONVERTDEC(inputstr[i]);
      }
      else
      {
        /* return 0, Invalid input */
        res = 0;
        break;
      }
    }
    /* Over 10 digit decimal --invalid */
    if (i >= 11)
    {
      res = 0;
    }
  }

  return res;
}

/**
  * @brief  Get an integer from the HyperTerminal
  * @param  num: The inetger
  * @retval 1: Correct
  *         0: Error
  */
uint32_t GetIntegerInput(int32_t * num)
{
  uint8_t inputstr[16];

  while (1)
  {
    GetInputString(inputstr);
    if (inputstr[0] == '\0') continue;
    if ((inputstr[0] == 'a' || inputstr[0] == 'A') && inputstr[1] == '\0')
    {
      SerialPutString("User Cancelled \r\n");
      return 0;
    }

    if (Str2Int(inputstr, num) == 0)
    {
      SerialPutString("Error, Input again: \r\n");
    }
    else
    {
      return 1;
    }
  }
}

/**
  * @brief  Test to see if a key has been pressed on the HyperTerminal
  * @param  key: The key pressed
  * @retval 1: Correct
  *         0: Error
  */
uint32_t SerialKeyPressed(uint8_t *key)
{
    uint8_t  RX_Count = 0x00;    
    RX_Count=readUARTbuffer(key);

    if(0 != RX_Count)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

/**
  * @brief  Get a key from the HyperTerminal
  * @param  None
  * @retval The Key Pressed
  */
uint8_t GetKey(void)
{
    uint8_t key = 0;

    /* Waiting for user input */
    uint8_t uartRxData[16];
    
    uint8_t  RX_Count = 0x00;
    uint32_t counter=0;
    
    Timer1_Write(0xFFCE);
    do {
    
        RX_Count=readUARTbuffer(uartRxData);
        Timer1_Start();
        while(!Timer1_HasOverflowOccured());                                    /*!< wait for timer(100us) to Expire*/
        Timer1_Stop();
        counter++;
    
    } while( RX_Count<1 && counter<500000);
    
    if(counter >= 500000)
    {
        return 0xFF;
    }
    
    if(RX_Count > 0)
    {
        key = uartRxData[0];
    }

    return key;

}

/**
  * @brief  Print a character on the HyperTerminal
  * @param  c: The character to be printed
  * @retval None
  */
void SerialPutChar(uint8_t c)
{
    uint8_t uartTxData[4] = {0};
    uartTxData[0]=c;
    writeUARTBuffer(&uartTxData[0],1);
}


/**
  * @brief  Print a string on the HyperTerminal
  * @param  s: The string to be printed
  * @retval None
  */
void Serial_PutString(uint8_t *s)
{
  while (*s != '\0')
  {
    SerialPutChar(*s);
    s++;
  }
}

/**
  * @brief  Get Input string from the HyperTerminal
  * @param  buffP: The input string
  * @retval None
  */
void GetInputString (uint8_t * buffP)
{
    uint32_t bytes_read = 0;
    uint8_t c = 0;
    do
    {
        c = GetKey();
        if (c == '\r')
          break;
        if (c == '\b') /* Backspace */
        {
          if (bytes_read > 0)
          {
            SerialPutString("\b \b");
            bytes_read --;
          }
          continue;
        }
        if (bytes_read >= CMD_STRING_SIZE )
        {
          SerialPutString("Command string size overflow\r\n");
          bytes_read = 0;
          continue;
        }
        if (c >= 0x20 && c <= 0x7E)
        {
          buffP[bytes_read++] = c;
          SerialPutChar(c);
        }
    }
    while (1);
    SerialPutString(("\n\r"));
    buffP[bytes_read] = '\0';
    
}

/**
  * @brief  Calculate the number of pages
  * @param  Size: The image size
  * @retval The number of pages
  */
uint32_t FLASH_PagesMask(uint32_t Size)
{
  uint32_t pagenumber = 0x0;
  uint32_t size = Size;

  if ((size % PAGE_SIZE) != 0)
  {
    pagenumber = (size / PAGE_SIZE) + 1;
  }
  else
  {
    pagenumber = size / PAGE_SIZE;
  }
  return pagenumber;

}

void delay_1s(void)
{
    uint32_t counter = 0;
    Timer1_Write(0xFFCE);
    
    while(counter<10000)                                                        /*!< Wait for 1 second*/
    {
        Timer1_Start();
        while(!Timer1_HasOverflowOccured());                                    /*!< wait for timer(100us) to Expire*/
        Timer1_Stop();                                                       /*!< Disable the TC counter */
        counter++;
    }
}

extern uint8_t dr[20];
/**
  * @brief  Display the Main Menu on to HyperTerminal
  * @param  None
  * @retval None
  */
void Main_Menu(void)
{
    uint8_t key = 0;
    uint8_t keyCount = 0;
    uint32_t timeout = 0;
    uint8_t *ver = (uint8_t *)VersionAddress;                                   //Load App version from flash memory location
    uint32_t *magic_num = (uint32_t *)MAGIC_NUM_ADDR;                           //Magic number pulled from the end of the program memory space
    uint8_t version = *ver;                                                     //App version pulled from address 0x6000
    uint8_t version_upper = version/10;                                         //Version 10's digit
    uint8_t version_lower = version - version_upper * 10;                       //Version 1's digit
    uint8_t boot_version_upper = Bootloader_version/10;                         //Boot Version 10's digit
    uint8_t boot_version_lower = Bootloader_version - boot_version_upper * 10;  //Boot Version 1's digit
        
    timeout = fiveSecTimeout;
    Timer1_Write(0xFFFF - 4000);
    
    //Bootloader Entry Point, waiting for the enable sequence
    do{
        Timer1_Start();
        if (1 == SerialKeyPressed(&key))                                        //Check UART buffer, read first byte out
        {
            if (CARRIAGE_RET == key)                                            //Looking for 0x0D, carriage return
            {
                keyCount++;
                if(keyCount == keyPresstoStart)                                 //3x carriage returns means we enable bootloader
                {
                    break;
                }
            }
        }
        while(!Timer1_HasOverflowOccured());   /*!< wait for timer(1ms) to Expire before checking again*/
        Timer1_Stop();
        timeout--;

    }while(timeout!=0);
    
    Timer1_Stop();                                                   
		
    //If the bootloader is not enabled then jump to application
    if (0==timeout)
    {
        if(*magic_num == MAGIC_NUM)
        {
            //Load the application
            iap_load_app(APP_START_ADDRESS);
        }
        else 
        {
            SerialPutString("\r\nMagic Number Does Not Match... Flash image invalid\r\n\n");
        }
    }
    
    //Once bootloader is enabled, print bootloader menu
    while(1)
    {
        SerialPutString("\r\n===== DCDU Boot Menu  =======\r\n\n");
        SerialPutString("\r\n  Please make a selection within 50 secs\r\n\n");
        SerialPutString("  Update The Firmware ---------------- 1\r\n\n");	
        SerialPutString("  Boot System ------------------------ 2\r\n\n");
        SerialPutString("  Print App Version ------------------ 3\r\n\n");
        SerialPutString("  Print Bootloader Version ----------- 4\r\n\n");
        SerialPutString("========================================\r\n\n");

        //Waiting or NMC or user to send command for menu option
        key = GetKey();	

        if (key == '1')                                                         // Update Main Firmware
        {
            /* Download user application in the Flash */
            SerialPutString("\r\nEnter Flash Mode");
            SerialDownload();
            if(*magic_num == MAGIC_NUM)
            {
                SerialPutString("\r\nMagic Number Matches\r\n\n");
                SerialPutString("\r\n=====	System Starting =======\r\n\n");
                iap_load_app(APP_START_ADDRESS);
            }
            else 
            {
                SerialPutString("\r\nMagic Number Does Not Match... Flash image invalid\r\n\n");
            }
        }
        else if ((key == '2')||(key == 0xC0))                                   //Start Main App, 0xC0 will also enable it because C0 only appears if NMC is not preparing FW upload
        {
            if(*magic_num == MAGIC_NUM)
            {
                SerialPutString("\r\nMagic Number Matches\r\n\n");
                SerialPutString("\r\n=====	System Starting =======\r\n\n");
                iap_load_app(APP_START_ADDRESS);
            }
            else 
            {
                SerialPutString("\r\nMagic Number Does Not Match... Flash image invalid\r\n\n");
            }
        }
        else if (key == '3')                                                    // Key: 3 Print App Version
        {
            SerialPutString("App version is: ");
            SerialPutChar(0x30 + version_upper);
            SerialPutChar(0x30 + version_lower);
        }
        else if (key == '4')                                                    // Key: 4 Print Boot Version
        {
            SerialPutString("Boot version is: ");
            SerialPutChar(0x30 + boot_version_upper);
            SerialPutChar(0x30 + boot_version_lower);
        }
        else if(key == 0xFF)                                                    //getKey should return FF if a timeout occurred
        {
            SerialPutString("Menu Timeout.... Attempting to launch application\r\n\n");
            if(*magic_num == MAGIC_NUM)
            {
                SerialPutString("\r\nMagic Number Matches\r\n\n");
                SerialPutString("\r\n=====	System Starting =======\r\n\n");
                iap_load_app(APP_START_ADDRESS);
            }
            else 
            {
                SerialPutString("\r\nMagic Number Does Not Match... Flash image invalid\r\n\n");
            }
        }     
        else
        {
            SerialPutString("Invalid Number ! ==> The Number Should be Either 1, (2), or 3\r\n\n");
        }
    }
    
}

/**
  * @}
  */

/************************END OF FILE*******************************************/

