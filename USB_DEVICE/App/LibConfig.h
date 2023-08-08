#ifndef LIBCONFIG_H
#define LIBCONFIG_H

#define LIBCONFIG_ENABLE   1
#define LIBCONFIG_DISABLE  0

/**
 * This define configures the logical resolution of the sensor's X axis in px.
 *
 * Allowed values:
 * 1..4095
 */
#define LIBCONFIG_USB_TOUCH_HORI_AXIS_RESOLUTION    1919

/**
 * This define configures the logical resolution of the sensor's Y axis in px.
 *
 * Allowed values:
 * 1..4095
 */
#define LIBCONFIG_USB_TOUCH_VERT_AXIS_RESOLUTION    1079

/**
 * This define configures the physical size of the sensor's X axis in ms.
 *
 * Allowed values:
 * 1..65535
 */
#define LIBCONFIG_USB_TOUCH_HORI_AXIS_PHYS_SIZE     400

/**
 * This define configures the physical size of the sensor's Y axis in ms.
 *
 * Allowed values:
 * 1..65535
 */
#define LIBCONFIG_USB_TOUCH_VERT_AXIS_PHYS_SIZE     275


/* Touch screen sensor resolution. */
#define X_RES_USB_MSB           (LIBCONFIG_USB_TOUCH_HORI_AXIS_RESOLUTION >> 8)
#define X_RES_USB_LSB           (LIBCONFIG_USB_TOUCH_HORI_AXIS_RESOLUTION & 0xFF)
#define Y_RES_USB_MSB           (LIBCONFIG_USB_TOUCH_VERT_AXIS_RESOLUTION >> 8)
#define Y_RES_USB_LSB           (LIBCONFIG_USB_TOUCH_VERT_AXIS_RESOLUTION & 0xFF)

/* Touch screen sensor physical dimensions. */
#define X_SIZE_USB_MSB          ((LIBCONFIG_USB_TOUCH_HORI_AXIS_PHYS_SIZE) >> 8)
#define X_SIZE_USB_LSB          ((LIBCONFIG_USB_TOUCH_HORI_AXIS_PHYS_SIZE) & 0xFF)
#define Y_SIZE_USB_MSB          ((LIBCONFIG_USB_TOUCH_VERT_AXIS_PHYS_SIZE) >> 8)
#define Y_SIZE_USB_LSB          ((LIBCONFIG_USB_TOUCH_VERT_AXIS_PHYS_SIZE) & 0xFF)

/**
 * This define configures if the device should start up in multi touch mode.
 * (Earlier versions of the touch library started up in single touch mode
 * and were switched to multi touch mode on request of the operation system.)
 *
 * Setting this define to LIBCONFIG_ENABLE will break the touch library's
 * compatibility with Windows versions smaller than 7 and the respective
 * older Windows CE versions.
 *
 * Allowed values:
 * LIBCONFIG_ENABLE, LIBCONFIG_DISABLE
 */
#define LIBCONFIG_USB_MULTITOUCH_BY_DEFAULT			LIBCONFIG_ENABLE

/**
 * This define selects the maximum number of contacts. The number of contacts is
 * used in the USB report descriptor and in USB reports on the touch interface.
 *
 * Allowed values:
 * 1..10
 */
#define LIBCONFIG_USB_HID_MAX_CONTACT_COUNT         10


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

#endif // LIBCONFIG_H
