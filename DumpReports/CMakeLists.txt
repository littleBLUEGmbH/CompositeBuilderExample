cmake_minimum_required (VERSION 3.10)

project(DummyGlasscapeTouch_tinyusb)

add_executable(DumpReports
    DumpReports.cpp
)

target_include_directories(DumpReports
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../STM32_USB_Device_Library-v2.11.1/Class/CompositeBuilder/Inc
    ${CMAKE_CURRENT_LIST_DIR}/../STM32_USB_Device_Library-v2.11.1/Class/CustomHID/Inc
    ${CMAKE_CURRENT_LIST_DIR}/../STM32_USB_Device_Library-v2.11.1/Core/Inc
    ${CMAKE_CURRENT_LIST_DIR}/../Core/Inc
    #${CMAKE_CURRENT_LIST_DIR}/../Core/Src
    ${CMAKE_CURRENT_LIST_DIR}/../USB_DEVICE/App
    ${CMAKE_CURRENT_LIST_DIR}/../USB_DEVICE/Target
    # ${CMAKE_CURRENT_LIST_DIR}/../tinyusb/src
)

target_compile_definitions(DumpReports
    PRIVATE
    CFG_TUSB_MCU=OPT_MCU_NONE
    TUP_DCD_ENDPOINT_MAX=8
)
