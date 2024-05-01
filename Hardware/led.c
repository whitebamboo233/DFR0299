/*******************************************************************************
 * ----------------------------------------------------------------------------*
 * Copyright (C) elektronikaembedded@gamil.com  	       	               *
 * ----------------------------------------------------------------------------*
 *                                                                             *
 * File Name  : led.c                                                          *
 *                                                                             *
 * Description : led functions                                                 *
 *                                                                             *
 * Version     : PrototypeV1.0                                                 *
 *                                                                             *
 * ----------------------------------------------------------------------------*
 * Authors: Sarath S                                                           *
 * Date: May 16, 2017                                                          *
 ******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "led.h"
#include "delay.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

uint8_t u8ledstate;  /* Led States On (0),Off (1),Blink (2)*/

uint8_t u8mainled_state; /* Led States On (0),Off (1),Blink (2)*/
uint8_t u8mainled_time = 0; /* Led Blink Counter*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

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
void ledInit(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | MAIN_LED_CLOCK, ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
  
  GPIO_InitStructure.GPIO_Pin = MAIN_LED;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  GPIO_ResetBits(MAIN_LED_GPIO, MAIN_LED); /* Led State ON*/

}/* End of this function */

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
void ledSetMainLed(unsigned char u8val)
{
  switch(u8val)
  {
    case 0:  //ON
      GPIO_ResetBits(MAIN_LED_GPIO,MAIN_LED);
      u8mainled_state = LED_OFF;
      break;

    case 1:  //OFF
      GPIO_SetBits(MAIN_LED_GPIO,MAIN_LED);
      u8mainled_state = LED_ON;
      break;
    case 2:  //Blink;
    u8mainled_state = LED_BLINK;
      break;
    default:
      break;
  }
}/* End of this function */




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
void ledBlinkHandler(void)
{
  	if(u8mainled_state == LED_BLINK) /*Main Led Handiler Starts*/
	{
		u8mainled_time++;
		if(u8mainled_time > 100)
		{
			GPIO_ResetBits(MAIN_LED_GPIO,MAIN_LED);
		}else
		{
			GPIO_SetBits(MAIN_LED_GPIO,MAIN_LED);
		}
		if(u8mainled_time > 200)
		{
			u8mainled_time = 0;
		}
	} /* Main Led Handiler End*/
	
}/* End of this function */



/*******************************************************************************
			* End of file *															     *
*******************************************************************************/


