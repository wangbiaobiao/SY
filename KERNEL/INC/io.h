/*
*********************************************************************************************************
* @file    	io.h
* @author  	SY
* @version 	V1.0.0
* @date    	2016-10-18 11:13:32
* @IDE	 	Keil V5.18.0.0
* @Chip    	STM32F407VE
* @brief   	IO内核头文件
*********************************************************************************************************
* @attention
*
* 
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Define to prevent recursive inclusion
*********************************************************************************************************
*/
#ifndef __IO_H
#define __IO_H

/*
*********************************************************************************************************
*                              				Exported Includes
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                              				Exported define
*********************************************************************************************************
*/
/**
 *	提供给用户调用的IO位掩码
 */
#define IO_INPUT_MASK_NULL					0x00000001

#define IO_OUTPUT_MASK_BEEP					0x00000001

#define IO_LAMP_MASK_COMM					0x00000001
#define IO_LAMP_MASK_PUMP_OPEN				0x00000002
#define IO_LAMP_MASK_PUMP_CLOSE				0x00000004

/*
*********************************************************************************************************
*                              				Exported types
*********************************************************************************************************
*/
typedef struct tagIO_TypeDef IO_TypeDef;


/*
*********************************************************************************************************
*                              				Exported constants
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported macro
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported variables
*********************************************************************************************************
*/
extern struct tagIO_TypeDef *g_ioDevicePtr;

/*
*********************************************************************************************************
*                              				Exported functions
*********************************************************************************************************
*/
void IO_Init( void );
void IO_Task( void );
void *GetIO_BeepHandle( IO_TypeDef *IO );

uint32_t IO_ReadInput( IO_TypeDef *IO );
uint32_t IO_ReadOutput( IO_TypeDef *IO );
uint32_t IO_ReadLamp( IO_TypeDef *IO );
void IO_WriteOutputMask( IO_TypeDef *IO, uint32_t clrMask, uint32_t setMask, uint32_t toggleMask );
void IO_WriteLampMask( IO_TypeDef *IO, uint32_t clrMask, uint32_t setMask, uint32_t toggleMask );

void __OpenBeep( void *devicePrt );
void __CloseBeep( void *devicePrt );


#endif
/************************ (C) COPYRIGHT STMicroelectronics **********END OF FILE*************************/
