/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if_1.c
  * @version        : v1.0_Cube
  * @brief          : USB Device Custom HID interface file.
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

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if_1.h"

/* USER CODE BEGIN INCLUDE */
#include "LibConfig.h"
/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_1_Private_TypesDefinitions USBD_CUSTOM_HID_1_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_1_Private_Defines USBD_CUSTOM_HID_1_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_1_Private_Macros USBD_CUSTOM_HID_1_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */
#define USBD_CUSTOM_HID_1_REPORT_DESC_SIZE HID_VENDOR_REPORT_DESCRIPTOR_SIZE
/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_1_Private_Variables USBD_CUSTOM_HID_1_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_1_ReportDesc_FS[USBD_CUSTOM_HID_1_REPORT_DESC_SIZE] __ALIGN_END =
{
  0x06, 0x00, 0xFF, // USAGE_PAGE (Vendor Defined Page 1)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0xa1, 0x01,                    // COLLECTION (Application)
  0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
  0x26, 0xFF, 0x00,              //   LOGICAL_MAXIMUM (255)
  0x75, 0x08,                    //   REPORT_SIZE (8)
  0x95, 0x3F,                    //   REPORT_COUNT (63)

  0x85, 10,                      //   REPORT_ID (10)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 11,                      //   REPORT_ID (11)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 12,                      //   REPORT_ID (12)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 13,                      //   REPORT_ID (13)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 14,                      //   REPORT_ID (14)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 15,                      //   REPORT_ID (15)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 16,                      //   REPORT_ID (16)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 17,                      //   REPORT_ID (17)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 18,                      //   REPORT_ID (18)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 20,                      //   REPORT_ID (20)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 21,                      //   REPORT_ID (21)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 22,                      //   REPORT_ID (22)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 23,                      //   REPORT_ID (23)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 24,                      //   REPORT_ID (24)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 25,                      //   REPORT_ID (25)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 26,                      //   REPORT_ID (26)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 27,                      //   REPORT_ID (27)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 28,                      //   REPORT_ID (28)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 29,                      //   REPORT_ID (29)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 30,                      //   REPORT_ID (30)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 40,                      //   REPORT_ID (40)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 41,                      //   REPORT_ID (41)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 42,                      //   REPORT_ID (42)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 43,                      //   REPORT_ID (43)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 44,                      //   REPORT_ID (44)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 50,                      //   REPORT_ID (50)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 60,                      //   REPORT_ID (60)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 61,                      //   REPORT_ID (61)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 62,                      //   REPORT_ID (62)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 63,                      //   REPORT_ID (63)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 70,                      //   REPORT_ID (70)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 71,                      //   REPORT_ID (71)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 72,                      //   REPORT_ID (72)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 73,                      //   REPORT_ID (73)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 74,                      //   REPORT_ID (74)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 75,                      //   REPORT_ID (75)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 76,                      //   REPORT_ID (76)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 77,                      //   REPORT_ID (77)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 78,                      //   REPORT_ID (78)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 79,                      //   REPORT_ID (79)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 80,                      //   REPORT_ID (80)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 81,                      //   REPORT_ID (81)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 82,                      //   REPORT_ID (82)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 83,                      //   REPORT_ID (83)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 84,                      //   REPORT_ID (84)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 85,                      //   REPORT_ID (85)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 86,                      //   REPORT_ID (86)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 87,                      //   REPORT_ID (87)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 88,                      //   REPORT_ID (88)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 89,                      //   REPORT_ID (89)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 90,                      //   REPORT_ID (90)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 91,                      //   REPORT_ID (91)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 92,                      //   REPORT_ID (92)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 93,                      //   REPORT_ID (93)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 94,                      //   REPORT_ID (94)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 95,                      //   REPORT_ID (95)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 96,                      //   REPORT_ID (96)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 97,                      //   REPORT_ID (97)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 98,                      //   REPORT_ID (98)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 99,                      //   REPORT_ID (99)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 100,                     //   REPORT_ID (100)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0x85, 101,                     //   REPORT_ID (101)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x81, 0x02,                    //   INPUT (Data,Var,Abs)
  0x09, 0x01,                    //   USAGE (Vendor Usage 1)
  0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)

  0xC0                           // END_COLLECTION
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_1_Exported_Variables USBD_CUSTOM_HID_1_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_1_Private_FunctionPrototypes USBD_CUSTOM_HID_1_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_1_Init_FS(void);
static int8_t CUSTOM_HID_1_DeInit_FS(void);
static int8_t CUSTOM_HID_1_OutEvent_FS(uint8_t event_idx, uint8_t state);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS_1 =
{
  CUSTOM_HID_1_ReportDesc_FS,
  CUSTOM_HID_1_Init_FS,
  CUSTOM_HID_1_DeInit_FS,
  CUSTOM_HID_1_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_1_Private_Functions USBD_CUSTOM_HID_1_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_1_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_1_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_1_OutEvent_FS(uint8_t event_idx, uint8_t state)
{
  /* USER CODE BEGIN 6 */
  UNUSED(event_idx);
  UNUSED(state);

  /* Start next USB packet transfer once data processing is completed */
  if (USBD_CUSTOM_HID_ReceivePacket(&hUsbDeviceFS) != (uint8_t)USBD_OK)
  {
    return -1;
  }

  return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_1_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_1_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

