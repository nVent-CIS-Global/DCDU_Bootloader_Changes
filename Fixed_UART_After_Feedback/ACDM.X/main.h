/* 
 * File:   main.h
 * Author: Rizwan
 *
 * Created on November 6, 2024, 9:02 AM
 */

/* USER CODE BEGIN Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

	
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define UART_RX_BUF_SIZE     128
#define BOOT_MOTOR

#define verNum "0.3"
//#define vString "\r\nBoot-Motor: Ver:"##verNum
	
	
#define RS485_EN_Pin GPIO_PIN_11
#define RS485_EN_GPIO_Port GPIOB
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);
void clearUARTbuffer(void);
//Fetch the entire contents of the UART buffer at the time
uint8_t readUARTbuffer(uint8_t* RdBuffer);

void writeUARTBuffer(uint8_t* writeBuffer, uint8_t size);
/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define HSDA_Pin GPIO_PIN_13
#define HSDA_GPIO_Port GPIOC
#define HSCL_Pin GPIO_PIN_14
#define HSCL_GPIO_Port GPIOC
#define SW_Pin GPIO_PIN_15
#define SW_GPIO_Port GPIOC
#define CW_Pin GPIO_PIN_0
#define CW_GPIO_Port GPIOF
#define CCW_Pin GPIO_PIN_1
#define CCW_GPIO_Port GPIOF
#define OCP_Pin GPIO_PIN_0
#define OCP_GPIO_Port GPIOA
#define T3_Pin GPIO_PIN_1
#define T3_GPIO_Port GPIOA
#define T2_Pin GPIO_PIN_4
#define T2_GPIO_Port GPIOA
#define EEPROMCS_Pin GPIO_PIN_0
#define EEPROMCS_GPIO_Port GPIOB
#define T1_Pin GPIO_PIN_1
#define T1_GPIO_Port GPIOB
#define RS485EN_Pin GPIO_PIN_11
#define RS485EN_GPIO_Port GPIOB
#define KEY_Pin GPIO_PIN_11
#define KEY_GPIO_Port GPIOA
#define KEY_EXTI_IRQn EXTI4_15_IRQn
#define OCEN1_Pin GPIO_PIN_12
#define OCEN1_GPIO_Port GPIOA
#define LOCK3_Pin GPIO_PIN_15
#define LOCK3_GPIO_Port GPIOA
#define OCEN3_Pin GPIO_PIN_3
#define OCEN3_GPIO_Port GPIOB
#define LOCK1_Pin GPIO_PIN_4
#define LOCK1_GPIO_Port GPIOB
#define OCEN2_Pin GPIO_PIN_7
#define OCEN2_GPIO_Port GPIOB
#define DOOR_Pin GPIO_PIN_8
#define DOOR_GPIO_Port GPIOB
#define LOCK2_Pin GPIO_PIN_9
#define LOCK2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

