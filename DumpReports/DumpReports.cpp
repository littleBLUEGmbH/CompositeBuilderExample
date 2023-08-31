#include <stdint.h>
#include <iostream>

#include "stm32g4xx.h"
#include "usbd_custom_hid_if_0.c"
#include "usbd_custom_hid_if_1.c"

USBD_HandleTypeDef hUsbDeviceFS;

uint8_t USBD_CUSTOM_HID_ReceivePacket(USBD_HandleTypeDef *pdev)
{
    (void)pdev;
    return 0;
}

void hexdump(const uint8_t *pBuffer, size_t size)
{
    bool first = true;

    for (size_t i = 0; i < size; i++)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            std::cout << " ";
        }

        uint8_t b = pBuffer[i];

        if (b < 16)
        {
            std::cout << "0";
        }

        std::cout << std::hex << (unsigned)b;

        if ((i % 16) == 15)
        {
            std::cout << std::endl;
            first = true;
        }
    }

    std::cout << std::endl;
}


#define HEXDUMP(data) \
    std::cout << "" #data "(" << sizeof(data) << " bytes):" << std::endl; \
    hexdump(data, sizeof(data)); \
    std::cout << std::endl



int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    // TODO HEXDUMP(desc_configuration);
    HEXDUMP(CUSTOM_HID_0_ReportDesc_FS);
    HEXDUMP(CUSTOM_HID_1_ReportDesc_FS);

    return 0;
}
