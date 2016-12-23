/*
*********************************************************************************************************
* @file    	mouse.c
* @author  	SY
* @version 	V1.0.0
* @date    	2016-11-22 09:05:55
* @IDE	 	Keil V5.22.0.0
* @Chip    	STM32F407VE
* @brief   	鼠标相关操作源文件
*********************************************************************************************************
* @attention
*
* 
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Private Includes
*********************************************************************************************************
*/
#include "kernel.h"
#include "usbh_usr.h"

/*
*********************************************************************************************************
*                              				Private define
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                              				Private typedef
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Private constants
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Private macro
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Private variables
*********************************************************************************************************
*/
static HID_MOUSE_TypeDef g_mouse;
HID_MOUSE_TypeDef * const g_mousePtr = &g_mouse;

/*
*********************************************************************************************************
*                              				Private function prototypes
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Private functions
*********************************************************************************************************
*/
/*
*********************************************************************************************************
* Function Name : HID_MouseInit
* Description	: 鼠标初始化
* Input			: None
* Output		: None
* Return		: None
*********************************************************************************************************
*/
void HID_MouseInit(HID_MOUSE_TypeDef *mouse)
{
	memset(mouse, 0x00, sizeof(HID_MOUSE_TypeDef));
}

/*
*********************************************************************************************************
* Function Name : HID_MouseProcess
* Description	: 鼠标进程
* Input			: None
* Output		: None
* Return		: None
*********************************************************************************************************
*/
void HID_MouseProcess(HID_MOUSE_TypeDef *mouse)
{
	switch (mouse->status)
	{
		case HID_MOUSE_IDLE:
			mouse->status = HID_MOUSE_START;
			break;
		case HID_MOUSE_WAIT:
		{
			HID_MOUSE_Info_TypeDef *m_pinfo = USBH_HID_GetMouseInfo(&hUsbHostHS);
			memcpy(&mouse->value, m_pinfo, sizeof(HID_MOUSE_Info_TypeDef));
			
			ECHO(DEBUG_KERNEL_HID,"X = %d, Y = %d",m_pinfo->x, m_pinfo->y);
			ECHO(DEBUG_KERNEL_HID,"button1 = %d, button2 = %d, button3 = %d",\
									m_pinfo->buttons[0],m_pinfo->buttons[1],m_pinfo->buttons[2]);
			break;
		}
		case HID_MOUSE_START:
			mouse->status = HID_MOUSE_WAIT;
			ECHO(DEBUG_KERNEL_HID,"鼠标开始捕获...");
			break;
		default:
			mouse->status = HID_MOUSE_IDLE;
			break;
	}
}



/************************ (C) COPYRIGHT STMicroelectronics **********END OF FILE*************************/
