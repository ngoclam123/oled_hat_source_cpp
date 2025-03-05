cmake_minimum_required(VERSION 3.10)


project(PiZeroOled VERSION 1.0)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/src/DEV_Config.c
    ${PROJECT_SOURCE_DIR}/src/dev_hardware_i2c.c
    ${PROJECT_SOURCE_DIR}/src/dev_hardware_SPI.c
    ${PROJECT_SOURCE_DIR}/src/font12.c
    ${PROJECT_SOURCE_DIR}/src/font16.c
    ${PROJECT_SOURCE_DIR}/src/font20.c
    ${PROJECT_SOURCE_DIR}/src/font24.c
    ${PROJECT_SOURCE_DIR}/src/font8.c
    ${PROJECT_SOURCE_DIR}/src/KEY_APP.c
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/OLED_Driver.c
    ${PROJECT_SOURCE_DIR}/src/OLED_GUI.c
    ${PROJECT_SOURCE_DIR}/src/sysfs_gpio.c
)


target_include_directories(${PROJECT_NAME} PRIVATE 
    ${PROJECT_SOURCE_DIR}/inc
)

set(TAGET_GPIO_LIB "USE_DEV_LIB")

if(TAGET_GPIO_LIB STREQUAL "USE_BCM2835_LIB")
    target_link_libraries(${PROJECT_NAME} PRIVATE
        bcm2835
        m
    )
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        USE_BCM2835_LIB
    )
elseif(TAGET_GPIO_LIB STREQUAL "USE_WIRINGPI_LIB")
    target_link_libraries(${PROJECT_NAME} PRIVATE
        wiringPi
        m
    )
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        USE_WIRINGPI_LIB
    )
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE
        lgpio
        m
    )
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        USE_DEV_LIB
    )
endif()

