/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_conf.h
  * @version        : v1.0_Cube
  * @brief          : Header for usbd_conf.c file.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CONF__H__
#define __USBD_CONF__H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN INCLUDE */

#define USB_TOUCH_HORI_AXIS_PHYS_SIZE     400
#define USB_TOUCH_VERT_AXIS_PHYS_SIZE     275
#define USB_TOUCH_HORI_AXIS_RESOLUTION    1919
#define USB_TOUCH_VERT_AXIS_RESOLUTION    1079

// #define USB_HID_USE_MOUSE_PAD
#define USB_HID_MAX_CONTACT_COUNT 10
#define USB_MULTITOUCH_BY_DEFAULT 1

#if (USB_MULTITOUCH_BY_DEFAULT==1)
	#define HID_MULTI_TOUCH_REPORT_DESCRIPTOR_SIZE (66u+(USB_HID_MAX_CONTACT_COUNT*65u))
#else
	#define HID_MULTI_TOUCH_REPORT_DESCRIPTOR_SIZE (160u+(USB_HID_MAX_CONTACT_COUNT*65u))
#endif
#define HID_VENDOR_REPORT_DESCRIPTOR_SIZE 0x249
/* USER CODE END INCLUDE */

/** @addtogroup USBD_OTG_DRIVER
  * @brief Driver for Usb device.
  * @{
  */

/** @defgroup USBD_CONF USBD_CONF
  * @brief Configuration file for Usb otg low level driver.
  * @{
  */

/** @defgroup USBD_CONF_Exported_Variables USBD_CONF_Exported_Variables
  * @brief Public variables.
  * @{
  */

/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Defines USBD_CONF_Exported_Defines
  * @brief Defines for configuration of the Usb device.
  * @{
  */

/*---------- -----------*/
#define USBD_MAX_NUM_INTERFACES     1U
/*---------- -----------*/
#define USBD_MAX_NUM_CONFIGURATION     1U
/*---------- -----------*/
#define USBD_MAX_STR_DESC_SIZ     512U
/*---------- -----------*/
#define USBD_DEBUG_LEVEL     0U
/*---------- -----------*/
#define USBD_LPM_ENABLED     1U
/*---------- -----------*/
#define USBD_SELF_POWERED     1U
/*---------- -----------*/
#define USBD_CUSTOMHID_0_OUTREPORT_BUF_SIZE     2U
/*---------- -----------*/
#define USBD_CUSTOM_HID_0_REPORT_DESC_SIZE     HID_MULTI_TOUCH_REPORT_DESCRIPTOR_SIZE+0U
#define USBD_CUSTOM_HID_1_REPORT_DESC_SIZE     HID_VENDOR_REPORT_DESCRIPTOR_SIZE+0U
/*---------- -----------*/
#define CUSTOM_HID_FS_BINTERVAL     0x5U

/****************************************/
/* #define for FS and HS identification */
#define DEVICE_FS 		0
#define DEVICE_HS 		1

/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Macros USBD_CONF_Exported_Macros
  * @brief Aliases.
  * @{
  */
/* Memory management macros make sure to use static memory allocation */
/** Alias for memory allocation. */

#define USBD_malloc         (void *)USBD_static_malloc

/** Alias for memory release. */
#define USBD_free           USBD_static_free

/** Alias for memory set. */
#define USBD_memset         memset

/** Alias for memory copy. */
#define USBD_memcpy         memcpy

/** Alias for delay. */
#define USBD_Delay          HAL_Delay

/* DEBUG macros */

#if (USBD_DEBUG_LEVEL > 0)
#define USBD_UsrLog(...)    printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_UsrLog(...)
#endif /* (USBD_DEBUG_LEVEL > 0U) */

#if (USBD_DEBUG_LEVEL > 1)

#define USBD_ErrLog(...)    printf("ERROR: ");\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_ErrLog(...)
#endif /* (USBD_DEBUG_LEVEL > 1U) */

#if (USBD_DEBUG_LEVEL > 2)
#define USBD_DbgLog(...)    printf("DEBUG : ");\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_DbgLog(...)
#endif /* (USBD_DEBUG_LEVEL > 2U) */

/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Types USBD_CONF_Exported_Types
  * @brief Types.
  * @{
  */

/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_FunctionsPrototype USBD_CONF_Exported_FunctionsPrototype
  * @brief Declaration of public functions for Usb device.
  * @{
  */

/* Exported functions -------------------------------------------------------*/
void *USBD_static_malloc(uint32_t size);
void USBD_static_free(void *p);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __USBD_CONF__H__ */

