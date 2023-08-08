/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : usb_device.c
 * @version        : v3.0_Cube
 * @brief          : This file implements the USB Device
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#if 0
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_customhid.h"
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN Includes */
#endif

#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_def.h"
#include "usbd_desc.h"
#include "usbd_customhid.h"
#include "usbd_custom_hid_if_0.h"
#include "usbd_custom_hid_if_1.h"
#include "usbd_composite_builder.h"

/* USER CODE END Includes */

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
/* Defines the report size number of each report descriptor */
#if (LIBCONFIG_USB_MULTITOUCH_BY_DEFAULT==1)
#define HID_MULTI_TOUCH_REPORT_DESCRIPTOR_SIZE (66+(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT*65))
#else
#define HID_MULTI_TOUCH_REPORT_DESCRIPTOR_SIZE (160+(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT*65))
#endif
#define HID_ALPHA_REPORT_DESCRIPTOR_SIZE 0x003F
#define HID_MOUSE_REPORT_DESCRIPTOR_SIZE 0x0034
#define HID_VENDOR_REPORT_DESCRIPTOR_SIZE 0x249

/* Defines the descriptor sizes of device and config descriptor */
#define HID_DEVICE_DESC_SIZE                18
#define HID_CONFIG_DESC_SIZE                LE(0x0042)     //Totallength (= 9+9+9+7+9+9+7+7)


/* USER CODE END PV */

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

extern void Error_Handler(void);
/* USB Device Core handle declaration. */
USBD_HandleTypeDef hUsbDeviceFS;
extern USBD_DescriptorsTypeDef CUSTOM_HID_Desc;

/*
 * -- Insert your variables declaration here --
 */
/* USER CODE BEGIN 0 */
uint8_t USBD_CustomHID_ep_0[1] = {0x81};
uint8_t USBD_CustomHID_ep_1[4] = {0x82, 0x02, 0x83, 0x03};
/* USER CODE END 0 */

/*
 * -- Insert your external function declaration here --
 */
/* USER CODE BEGIN 1 */
/* USER CODE END 1 */

/**
 * Init USB device Library, add supported class and start the library
 * @retval None
 */
void MX_USB_Device_Init(void)
{
	/* USER CODE BEGIN USB_Device_Init_PreTreatment */
#if 0
	/* USER CODE END USB_Device_Init_PreTreatment */

	/* Init Device Library, add supported class and start the library. */
	if (USBD_Init(&hUsbDeviceFS, &CUSTOM_HID_Desc, DEVICE_FS) != USBD_OK) {
		Error_Handler();
	}
	if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_CUSTOM_HID) != USBD_OK) {
		Error_Handler();
	}
	if (USBD_CUSTOM_HID_RegisterInterface(&hUsbDeviceFS, &USBD_CustomHID_fops_FS) != USBD_OK) {
		Error_Handler();
	}
	if (USBD_Start(&hUsbDeviceFS) != USBD_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USB_Device_Init_PostTreatment */
#endif

	/* Init Device Library, add supported class and start the library. */
	if (USBD_Init(&hUsbDeviceFS, &CUSTOM_HID_Desc, DEVICE_FS) != USBD_OK)
	{
		Error_Handler();
	}
	if (USBD_CUSTOM_HID_RegisterInterface(&hUsbDeviceFS, &USBD_CustomHID_fops_FS_0) != USBD_OK)
	{
		Error_Handler();
	}
	if (USBD_RegisterClassComposite(&hUsbDeviceFS, &USBD_CUSTOM_HID, CLASS_TYPE_CHID, USBD_CustomHID_ep_0) != USBD_OK)
	{
		Error_Handler();
	}
	if (USBD_CUSTOM_HID_RegisterInterface(&hUsbDeviceFS, &USBD_CustomHID_fops_FS_1) != USBD_OK)
	{
		Error_Handler();
	}
	if (USBD_RegisterClassComposite(&hUsbDeviceFS, &USBD_CUSTOM_HID, CLASS_TYPE_CHID, USBD_CustomHID_ep_1) != USBD_OK)
	{
		Error_Handler();
	}
	if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
	{
		Error_Handler();
	}

	/* USER CODE END USB_Device_Init_PostTreatment */
}

/**
 * @}
 */

/**
 * @}
 */

