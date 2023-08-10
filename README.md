# CompositeBuilderExample

This code is confgured to be run on the NUCLEO-G474RE evaluation board.

The purpose of this code is show the use of the composite builder to for a USB composite device with two custom hid interfaces.

The first interface is a HID multitouch, the second a vendor specific HID interface.

The hardware initialization is done with STM32CubeMX generated code.

## Successor to STM32F373 legacy code

The STM32G4 project is a successor to an existing STM32F373 project that was configured with a heavily patched version of the STM32_USB-FS-Device_Driver.

Because of this we have an existing implementation, with existing reports and report descriptors we want to mimic as closely as possible.

The expected reports can be seen in these files:

* Doc/DescriptorDump_RAFI_Glasscape_Touch STM32F373.txt
* Doc/Report Descriptor STM32F373 0 MultiTouch.txt
* Doc/Report Descriptor STM32F373 1 Vendor.txt
* Doc/Report Descriptor STM32F373 RAW.txt

## Current implementation / problems

The current state of the implementation can be seen in the following files:

* DescriptorDump_RAFI_Glasscape_Touch ONLY Interface 0.txt: output if only the interface 0 was activated
* DescriptorDump_RAFI_Glasscape_Touch ONLY Interface 1.txt: output if only the interface 1 was activated

With both interfaces active there are errors when enumerating the devices. Because of this no dumps are available.

## Tools

* <https://www.thesycon.de/eng/usb_descriptordumper.shtml>(Thesycon USB Descriptor Dumper v2.17.0): used to create the "DescriptorDump*.txt" files
* <https://github.com/DIGImend/usbhid-dump>(Usbhid-dump): Tool on Linux used to create the RAW report descriptor dump (`sudo usbhid-dump -m 05BD`)
* <https://eleccelerator.com/usbdescreqparser/>(USB Descriptor and Request Parser): Used to paste in the RAW descriptor dump, so the parsed report descriptors
