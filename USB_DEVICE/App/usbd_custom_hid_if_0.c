/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if_0.c
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
#include "usbd_custom_hid_if_0.h"

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

/** @defgroup USBD_CUSTOM_HID_0_Private_TypesDefinitions USBD_CUSTOM_HID_0_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_0_Private_Defines USBD_CUSTOM_HID_0_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* CONTACT: HID-Multitouch-Descriptor used for every contact */
#define CONTACT\
  0x05, 0x0d,                           /*     USAGE_PAGE (Digitizers)*/\
  0x09, 0x22,                           /*     USAGE (Finger)*/\
  0xa1, 0x02,                           /*     COLLECTION (Logical)*/\
  0x09, 0x42,                           /*       USAGE (Tip Switch)*/\
  0x15, 0x00,                           /*       LOGICAL_MINIMUM (0)*/\
  0x25, 0x01,                           /*       LOGICAL_MAXIMUM (1)*/\
  0x75, 0x01,                           /*       REPORT_SIZE (1)*/\
  0x95, 0x01,                           /*       REPORT_COUNT (1)*/\
  0x81, 0x02,                           /*       INPUT (Data,Var,Abs)*/\
  0x81, 0x03,                           /*       INPUT (Cnst,Ary,Abs)*/\
  0x09, 0x47,                           /*       USAGE (Touch Valid)*/\
  0x81, 0x02,                           /*       INPUT (Data,Var,Abs)*/\
  0x95, 0x05,                           /*       REPORT_COUNT (5)*/\
  0x81, 0x03,                           /*       INPUT (Cnst,Ary,Abs)*/\
  0x75, 0x08,                           /*       REPORT_SIZE (8)*/\
  0x09, 0x51,                           /*       USAGE (Contact Identifier)*/\
  0x25, 0x09,                           /*       LOGICAL_MAXIMUM (9)*/\
  0x95, 0x01,                           /*       REPORT_COUNT (1)*/\
  0x81, 0x02,                           /*       INPUT (Data,Var,Abs)*/\
  0x05, 0x01,                           /*       USAGE_PAGE (Generic Desk..*/\
  0x46, X_SIZE_USB_LSB, X_SIZE_USB_MSB, /*       PHYSICAL_MAXIMUM (1024)  // Screen width in mm*/\
  0x26, X_RES_USB_LSB, X_RES_USB_MSB,   /*       LOGICAL_MAXIMUM (1024)   // Screen resolution in pixel*/\
  0x35, 0x00,                           /*       PHYSICAL_MINIMUM (0)*/\
  0x75, 0x10,                           /*       REPORT_SIZE (16)*/\
  0x09, 0x30,                           /*       USAGE (X)*/\
  0x81, 0x02,                           /*       INPUT (Data,Var,Abs)*/\
  0x46, Y_SIZE_USB_LSB, Y_SIZE_USB_MSB, /*       PHYSICAL_MAXIMUM (1024)  // Screen width in mm*/\
  0x26, Y_RES_USB_LSB, Y_RES_USB_MSB,   /*       LOGICAL_MAXIMUM (1024)   // Screen resolution in pixel*/\
  0x09, 0x31,                           /*       USAGE (Y)*/\
  0x81, 0x02,                           /*       INPUT (Data,Var,Abs)*/\
  0xc0                                  /*    END_COLLECTION*/
// 65 elements
/* End of CONTACT */

#define REPORTID_MTOUCH         0x01
#define REPORTID_MAX_COUNT      0x02
#define REPORTID_CONFIG     0x03
#define REPORTID_CALIBRATION  0x04
#define REPORTID_MOUSE_S_TOUCH      0x05

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_0_Private_Macros USBD_CUSTOM_HID_0_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

#define USBD_CUSTOM_HID_0_REPORT_DESC_SIZE  HID_MULTI_TOUCH_REPORT_DESCRIPTOR_SIZE

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_0_Private_Variables USBD_CUSTOM_HID_0_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_0_ReportDesc_FS[USBD_CUSTOM_HID_0_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* USER CODE BEGIN 0 */
#ifdef LIBCONFIG_USB_HID_USE_MOUSE_PAD    /* Use MousePad as interface */
  0x05, 0x01,                        // Usage Page (Generic Desktop)
  0x09, 0x02,// Usage (Mouse)
  0xA1, 0x01,// Collection (Application)
  0x09, 0x01,//   Usage (Pointer)
  0xA1, 0x00,//   Collection (Physical)
  0x05, 0x09,//     Usage Page (Buttons)
  0x19, 0x01,//     Usage Minimum (01)
  0x29, 0x03,//     Usage Maximum (03)
  0x15, 0x00,//     Logical Minimum (0)
  0x25, 0x01,//     Logical Maximum (1)
  0x95, 0x03,//     Report Count (3)
  0x75, 0x01,//     Report Size (1)
  0x81, 0x02,//     Input (Data, Variable, Absolute)
  0x95, 0x01,//     Report Count (1)
  0x75, 0x05,//     Report Size (5)
  0x81, 0x01,//     Input (Constant) for padding
  0x05, 0x01,//     Usage Page (Generic Desktop)
  0x09, 0x30,//     Usage (X)
  0x09, 0x31,//     Usage (Y)
  0x09, 0x38,//    Usage Wheel
  0x15, 0x81,//     Logical Minimum (-127)
  0x25, 0x7F,//     Logical Maximum (127)
  0x75, 0x08,//     Report Size (8)
  0x95, 0x03,//     Report Count (3)
  0x81, 0x06,//     Input (Data, Variable, Relative)
  // 0xC0,//   End Collection (Physical)
#else
  // Begin Touch Report Definition
  0x05, 0x0d,                         // USAGE_PAGE (Digitizers)
  0x09, 0x04,                         // USAGE (Touch Screen)
  0xa1, 0x01,                         // COLLECTION (Application)
  0x85, REPORTID_MTOUCH,              //   REPORT_ID (Touch)
  0x65, 0x11,                         //   UNIT (SI Linear : Distance)
  0x55, 0x0F,                         //   UNIT_EXPONENT (-1)
  // 14 elements
  /* Descriptor for contacts defined in a #define in the header of this file */
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >0)
  CONTACT, /*contact0*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >1)
  CONTACT, /*contact1*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >2)
  CONTACT, /*contact2*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >3)
  CONTACT, /*contact3*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >4)
  CONTACT, /*contact4*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >5)
  CONTACT, /*contact5*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >6)
  CONTACT, /*contact6*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >7)
  CONTACT, /*contact7*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >8)
  CONTACT, /*contact8*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >9)
  CONTACT, /*contact9*/
#endif
#if(LIBCONFIG_USB_HID_MAX_CONTACT_COUNT >10)
#warning LIBCONFIG_USB_HID_MAX_CONTACT_COUNT > 10  /* More than 10 contacts defined --> WARNING */
#endif
  // 65 elements each finger
  // Contact Count
  0x05, 0x0d,                         //    USAGE_PAGE (Digitizers)
  0x09, 0x54,                         //    USAGE (Contact Count)
  0x95, 0x01,                         //    REPORT_COUNT (1)
  0x75, 0x08,                         //    REPORT_SIZE (8)
  0x15, 0x00,                         //    LOGICAL_MINIMUM (0)
  0x25, 0x09,                       //    LOGICAL_MAXIMUM (9), 10 contacts
  0x81, 0x02,                         //    INPUT (Data,Var,Abs)
  // 14 elements
  // Scan Time
  0x05, 0x0d,                         //     USAGE_PAGE (Digitizers)
  0x55, 0x0C,                         //     UNIT_EXPONENT (-4)
  0x66, 0x01, 0x10,                   //     UNIT (Seconds)
  0x47, 0xff, 0xff, 0x00, 0x00,       //     PHYSICAL_MAXIMUM (65535)
  0x27, 0xff, 0xff, 0x00, 0x00,       //     LOGICAL_MAXIMUM (65535)
  0x75, 0x10,                         //     REPORT_SIZE (16)
  0x95, 0x01,                         //     REPORT_COUNT (1)
  0x09, 0x56,                         //     USAGE (Scan Time)
  0x81, 0x02,                         //     INPUT (Data,Var,Abs)
  // 25 elements
  // Feature Report Maximum Count
  0x05, 0x0D,                         //     USAGE_PAGE (Digitizers)
  0x85, REPORTID_MAX_COUNT,           //     REPORT_ID (Feature)
  0x95, 0x01,                         //     REPORT_COUNT (1)
  0x75, 0x08,                         //     REPORT_SIZE (8)
  0x09, 0x55,                         //     USAGE(Maximum Count)
  0x25, LIBCONFIG_USB_HID_MAX_CONTACT_COUNT,   //     LOGICAL_MAXIMUM (10)
  0xB1, 0x02,                         //     FEATURE (Data,Var,Abs)
  // 0xc0,                                // END_COLLECTION
  // 15 elements

#if (LIBCONFIG_USB_MULTITOUCH_BY_DEFAULT==0)
  // Feature Report Touch Config
  0x09, 0x0E,                         // USAGE (Device Configuration)
  0xa1, 0x01,                         // COLLECTION (Application)
  0x85, REPORTID_CONFIG,              //   REPORT_ID (Configuration)
  0x09, 0x23,                         //   USAGE (Device Settings)
  0xa1, 0x02,                         //   COLLECTION (logical)
  0x09, 0x52,                         //    USAGE (Device Mode)
  0x09, 0x53,                         //    USAGE (Device Identifier)
  0x15, 0x00,                         //    LOGICAL_MINIMUM (0)
  0x25, 0x0A,                         //    LOGICAL_MAXIMUM (10)
  0x75, 0x08,                         //    REPORT_SIZE (8)
  0x95, 0x02,                         //    REPORT_COUNT (2)
  0xb1, 0x02,                         //   FEATURE (Data,Var,Abs)
  0xc0,                                // END_COLLECTION
  // 25 elements
  0xc0,                                 // END_COLLECTION         // 186
  // 1 element
  // Begin Mouse Report Definition (NB: This is a single-touch "mouse" with absolute coordinates, no wheel)
  0x05, 0x01,                        // USAGE_PAGE (Generic Desktop) 0
  0x09, 0x02,                        // USAGE (Mouse) 2
  0xa1, 0x01,                        //   COLLECTION (Application) 4
  0x09, 0x01,                        //   USAGE (Pointer) 8
  0xa1, 0x00,                        //     COLLECTION (Physical) 10
  0x85, REPORTID_MOUSE_S_TOUCH,      //     REPORT_ID (Mouse) 6
  0x05, 0x09,                        //     USAGE_PAGE (Button) 12
  0x19, 0x01,                        //      USAGE_MINIMUM (Button 1) 14
  0x29, 0x02,                        //      USAGE_MAXIMUM (Button 2) 16
  0x15, 0x00,                        //      LOGICAL_MINIMUM (0) 18
  0x25, 0x01,                        //      LOGICAL_MAXIMUM (1) 20
  0x95, 0x02,                        //      REPORT_COUNT (2) 24
  0x75, 0x01,                        //      REPORT_SIZE (1) 22
  0x81, 0x02,                        //      INPUT (Data,Var,Abs) 26
  0x95, 0x06,                        //      REPORT_COUNT (6) 28
  0x81, 0x03,                        //      INPUT (Cnst,Var,Abs) 30
  0x05, 0x01,                         //      USAGE_PAGE (Generic Desktop)
  0x65, 0x11,                         //      UNIT (SI Linear : Distance)
  0x55, 0x0F,                         //        UNIT_EXPONENT (-1)
  0x09, 0x30,                           //      USAGE (X)
  0x26, X_RES_USB_LSB, X_RES_USB_MSB, //      LOGICAL_MAXIMUM (640)   // Screen resolution in pixel
  0x35, 0x00,                           //      PHYSICAL MINIMUM (0)
  0x46, X_SIZE_USB_LSB, X_SIZE_USB_MSB, //      PHYSICAL_MAXIMUM (115)  // Screen width in mm
  0x75, 0x10,                           //      REPORT_SIZE (16)
  0x95, 0x01,                           //      REPORT_COUNT (1)
  0x81, 0x02,                      //      INPUT (Data,Variable, Absolute)
  0x09, 0x31,                           //      USAGE (Y)
  0x26, Y_RES_USB_LSB, Y_RES_USB_MSB, //      LOGICAL_MAXIMUM (480)   // Screen resolution in pixel
  0x35, 0x00,                           //      PHYSICAL MINIMUM (0)
  0x46, Y_SIZE_USB_LSB, Y_SIZE_USB_MSB, //      PHYSICAL_MAXIMUM (87)   // Screen height in  mm
  0x81, 0x02,                      //      INPUT (Data,Variable, Absolute)
  0xc0,                                  //     END_COLLECTION
  // 0xc0                                   //    END_COLLECTION     // 254
  // 68 elements    /* 123 elements
#endif	/* LIBCONFIG_USB_MULTITOUCH_BY_DEFAULT==0 */
#endif /* #ifdef USB_HID_USE_MOUSE_PAD #else */
  /* USER CODE END 0 */
  0xC0    /*     END_COLLECTION	             */
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_0_Exported_Variables USBD_CUSTOM_HID_0_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_0_Private_FunctionPrototypes USBD_CUSTOM_HID_0_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_0_Init_FS(void);
static int8_t CUSTOM_HID_0_DeInit_FS(void);
static int8_t CUSTOM_HID_0_OutEvent_FS(uint8_t event_idx, uint8_t state);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS_0 =
{
  CUSTOM_HID_0_ReportDesc_FS,
  CUSTOM_HID_0_Init_FS,
  CUSTOM_HID_0_DeInit_FS,
  CUSTOM_HID_0_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_0_Private_Functions USBD_CUSTOM_HID_0_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_0_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_0_DeInit_FS(void)
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
static int8_t CUSTOM_HID_0_OutEvent_FS(uint8_t event_idx, uint8_t state)
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
static int8_t USBD_CUSTOM_HID_0_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_0_SendReport(&hUsbDeviceFS, report, len);
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

