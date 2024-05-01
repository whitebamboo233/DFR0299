/*******************************************************************************
 * ----------------------------------------------------------------------------*
 *  elektronikaembedded@gamil.com ,https://elektronikaembedded.wordpress.com   *        	                   
 * ----------------------------------------------------------------------------*
 *                                                                             *
 * File Name  : led.h                                                          *
 *                                                                             *
 * Description : led.c header file                                             *
 *                                                                             *
 * Version     : PrototypeV1.0                                                 *
 *                                                                             *
 * ----------------------------------------------------------------------------*
 * Authors: Sarath S                                                           *
 * Date: May 16, 2017                                                          *
 ******************************************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LED_H
#define __LED_H

/* Includes ------------------------------------------------------------------*/
//#include "led.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#define MAIN_LED        GPIO_Pin_13
#define MAIN_LED_GPIO   GPIOC
#define MAIN_LED_CLOCK  RCC_APB2Periph_GPIOC


#define LED_ON 		0
#define LED_OFF 	1
#define LED_BLINK 	2

#define Initial_Count 3

/* Exported functions ------------------------------------------------------- */

/* ----------------------------------------------------------------------------*
 *
 * Function Name : ledInit
 *
 * Description   : Initialize System Leds(LED Port,Direction,Initial State)
 *
 * Input : None
 *
 * Output  : None
 *
 * Return  : None
 * ----------------------------------------------------------------------------*
 * Authors : Sarath S
 * Date : May 17, 2017
 * ---------------------------------------------------------------------------*/
void ledInit(void);

/* ----------------------------------------------------------------------------*
 *
 * Function Name : ledSetMain
 *
 * Description   : Led State (ON,OFF,Blink)
 *
 * Input : LED_ON (0),LED_OFF (1),LED_BLINK (2)
 *
 * Output  : None
 *
 * Return  : None
 * ----------------------------------------------------------------------------*
 * Authors : Sarath S
 * Date : May 17, 2017
 * ---------------------------------------------------------------------------*/
void ledSetMainLed(uint8_t u8val);



/* ----------------------------------------------------------------------------*
 *
 * Function Name : ledBlinkHandler
 *
 * Description   :ledBlinkHandler 1ns interrupt (Call Form void SysTickHandler(void) stm32fx_it.c file)
 *
 * Input: None
 *
 * Output  : None
 *
 * Return  : None
 * ----------------------------------------------------------------------------*
 * Authors: Sarath S
 * Date: May 17, 2017
 * ---------------------------------------------------------------------------*/
void ledBlinkHandler(void);





#endif /* __LED_H */

/******************* elektronikaembedded@gamil *****END OF FILE****/
