#ifndef __OLED_GUI_H
#define __OLED_GUI_H
#ifdef __cplusplus
extern "C"
{
#endif
#include "OLED_Driver.h"
#include "fonts.h"

    /********************************************************************************
    function:
                dot pixel
    ********************************************************************************/
    typedef enum
    {
        DOT_PIXEL_1X1 = 1, // dot pixel 1 x 1
        DOT_PIXEL_2X2,     // dot pixel 2 X 2
        DOT_PIXEL_3X3,     // dot pixel 3 X 3
        DOT_PIXEL_4X4,     // dot pixel 4 X 4
        DOT_PIXEL_5X5,     // dot pixel 5 X 5
        DOT_PIXEL_6X6,     // dot pixel 6 X 6
        DOT_PIXEL_7X7,     // dot pixel 7 X 7
        DOT_PIXEL_8X8,     // dot pixel 8 X 8
    } DOT_PIXEL;
#define DOT_PIXEL_DFT DOT_PIXEL_1X1 // Default dot pilex

    /********************************************************************************
    function:
                dot Fill style
    ********************************************************************************/
    typedef enum
    {
        DOT_FILL_AROUND = 1, // dot pixel 1 x 1
        DOT_FILL_RIGHTUP,    // dot pixel 2 X 2
    } DOT_STYLE;
#define DOT_STYLE_DFT DOT_FILL_AROUND // Default dot pilex
    /********************************************************************************
    function:
                solid line and dotted line
    ********************************************************************************/
    typedef enum
    {
        LINE_SOLID = 0,
        LINE_DOTTED,
    } LINE_STYLE;

    /********************************************************************************
    function:
                DRAW Internal fill
    ********************************************************************************/
    typedef enum
    {
        DRAW_EMPTY = 0,
        DRAW_FULL,
    } DRAW_FILL;

/********************************************************************************
function:
            Defines commonly used colors for the display
********************************************************************************/
#define OLED_BACKGROUND BLACK // Default background color
#define FONT_BACKGROUND BLACK // Default font background color
#define FONT_FOREGROUND WHITE // Default font foreground color

#define WHITE 0xFF
#define BLACK 0x00

    /********************************************************************************
    function:
                Macro definition variable name
    ********************************************************************************/
    // Drawing
    void GUI_DrawPoint(POINT Xpoint, POINT Ypoint, COLOR Color, DOT_PIXEL Dot_Pixel, DOT_STYLE Dot_FillWay);
    void GUI_DrawLine(POINT Xstart, POINT Ystart, POINT Xend, POINT Yend, COLOR Color, LINE_STYLE Line_Style, DOT_PIXEL Dot_Pixel);
    void GUI_DrawRectangle(POINT Xstart, POINT Ystart, POINT Xend, POINT Yend, COLOR Color, DRAW_FILL Filled, DOT_PIXEL Dot_Pixel);
    void GUI_DrawCircle(POINT X_Center, POINT Y_Center, LENGTH Radius, COLOR Color, DRAW_FILL Draw_Fill, DOT_PIXEL Dot_Pixel);
    void GUI_Disbitmap(POINT Xpoint, POINT Ypoint, const unsigned char *pBmp, POINT Width, POINT Height);
    // Display string
    void GUI_DisChar(POINT Xstart, POINT Ystart, const char Acsii_Char, sFONT *Font, COLOR Color_Background, COLOR Color_Foreground);
    void GUI_DisString_EN(POINT Xstart, POINT Ystart, const char *pString, sFONT *Font, COLOR Color_Background, COLOR Color_Foreground);
    void GUI_DisNum(POINT Xpoint, POINT Ypoint, int32_t Nummber, sFONT *Font, COLOR Color_Background, COLOR Color_Foreground);

    void GUI_Show(void);

    static const unsigned char waveshare[1024] =
        {
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x11,
            0x11,
            0x00,
            0x9C,
            0x64,
            0x42,
            0x1C,
            0x78,
            0x7A,
            0x78,
            0xEF,
            0xB8,
            0x30,
            0x89,
            0x8C,
            0x70,
            0x19,
            0x91,
            0x88,
            0x9C,
            0xF4,
            0x63,
            0x1E,
            0x78,
            0x7A,
            0x79,
            0xEF,
            0x3C,
            0x78,
            0x89,
            0x9E,
            0xF0,
            0x09,
            0x91,
            0x88,
            0xB1,
            0x84,
            0x63,
            0x12,
            0x40,
            0x42,
            0x43,
            0x02,
            0x24,
            0xCC,
            0xC9,
            0x30,
            0x80,
            0x09,
            0x91,
            0x88,
            0xB1,
            0x84,
            0x67,
            0x12,
            0x40,
            0x42,
            0x42,
            0x02,
            0x24,
            0x84,
            0xC9,
            0x20,
            0x80,
            0x09,
            0x92,
            0x89,
            0xB0,
            0x84,
            0x65,
            0x12,
            0x40,
            0x42,
            0x42,
            0x02,
            0x24,
            0x84,
            0xC9,
            0x20,
            0xC0,
            0x0A,
            0xB2,
            0x4D,
            0x1C,
            0xC7,
            0xE5,
            0x96,
            0x78,
            0x7A,
            0x72,
            0x02,
            0x2C,
            0x84,
            0xA9,
            0x20,
            0x60,
            0x0A,
            0xA2,
            0x45,
            0x14,
            0x67,
            0xE4,
            0x9C,
            0x70,
            0x72,
            0x52,
            0x02,
            0x38,
            0x84,
            0xA9,
            0x20,
            0x30,
            0x0A,
            0x63,
            0xC5,
            0x30,
            0x34,
            0x67,
            0x94,
            0x40,
            0x42,
            0x42,
            0x02,
            0x28,
            0x84,
            0xB9,
            0x20,
            0x10,
            0x06,
            0x67,
            0xC7,
            0x30,
            0x14,
            0x6F,
            0x92,
            0x40,
            0x42,
            0x42,
            0x02,
            0x24,
            0x84,
            0x99,
            0x20,
            0x10,
            0x06,
            0x64,
            0x66,
            0x30,
            0x14,
            0x68,
            0x92,
            0x40,
            0x42,
            0x43,
            0x02,
            0x24,
            0x8C,
            0x99,
            0x20,
            0x10,
            0x06,
            0x64,
            0x22,
            0x3D,
            0xB4,
            0x68,
            0xD3,
            0x78,
            0x7A,
            0x79,
            0xE2,
            0x26,
            0x78,
            0x89,
            0xBE,
            0xF0,
            0x04,
            0x44,
            0x22,
            0x1C,
            0xE4,
            0x48,
            0x51,
            0x78,
            0x7A,
            0x79,
            0xE2,
            0x22,
            0x70,
            0x89,
            0x9E,
            0xE0,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x3F,
            0xFF,
            0xF0,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x3F,
            0xFF,
            0xFE,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x3F,
            0xFF,
            0xFF,
            0x80,
            0x00,
            0x08,
            0x30,
            0x00,
            0x00,
            0x00,
            0x00,
            0x10,
            0x00,
            0x00,
            0x00,
            0x00,
            0x3F,
            0xFF,
            0xF7,
            0xC0,
            0x06,
            0xDB,
            0x30,
            0x3F,
            0xFF,
            0xFC,
            0x00,
            0x70,
            0x00,
            0x7F,
            0xFF,
            0xF0,
            0x3F,
            0xFF,
            0xE7,
            0xE0,
            0x0E,
            0xDB,
            0x30,
            0x3F,
            0xFF,
            0xFC,
            0x7F,
            0xFF,
            0xF8,
            0x7F,
            0xFF,
            0xF0,
            0x3F,
            0xFF,
            0xC7,
            0xF0,
            0x0C,
            0xDB,
            0x7E,
            0x00,
            0x18,
            0x00,
            0x7F,
            0xFF,
            0xF8,
            0x7F,
            0xFF,
            0xF0,
            0x3F,
            0xFF,
            0x87,
            0xF0,
            0x1C,
            0xDB,
            0xFE,
            0x00,
            0x18,
            0x00,
            0x7F,
            0xFF,
            0xF8,
            0x00,
            0x00,
            0xF0,
            0x3F,
            0xFF,
            0x07,
            0xF8,
            0x1C,
            0xDB,
            0xF0,
            0x3F,
            0xFF,
            0xFC,
            0x60,
            0x70,
            0x38,
            0x00,
            0x01,
            0xE0,
            0x3F,
            0xFF,
            0x87,
            0xFC,
            0x18,
            0xDB,
            0xC0,
            0x3F,
            0xFF,
            0xF8,
            0x60,
            0x70,
            0x38,
            0x00,
            0x01,
            0xC0,
            0x20,
            0xC3,
            0x86,
            0x3C,
            0x06,
            0xFF,
            0x00,
            0x30,
            0x18,
            0x18,
            0x60,
            0x70,
            0x38,
            0x00,
            0x03,
            0xC0,
            0x30,
            0xC3,
            0x0C,
            0x3C,
            0x06,
            0xFF,
            0x0C,
            0x30,
            0x18,
            0x18,
            0x60,
            0x70,
            0x38,
            0x00,
            0x03,
            0x80,
            0x30,
            0x43,
            0x0C,
            0x1E,
            0x0E,
            0xFF,
            0x6C,
            0x33,
            0x18,
            0xD8,
            0x60,
            0x70,
            0x38,
            0x07,
            0xFF,
            0x00,
            0x30,
            0x00,
            0x1C,
            0x1E,
            0x0E,
            0x00,
            0x6C,
            0x33,
            0x9B,
            0xD8,
            0x70,
            0x70,
            0x38,
            0x07,
            0xFF,
            0x00,
            0x38,
            0x00,
            0x08,
            0x0E,
            0x1C,
            0xFE,
            0x7C,
            0x30,
            0x18,
            0x18,
            0x7F,
            0xFF,
            0xF8,
            0x07,
            0xFE,
            0x00,
            0x38,
            0x00,
            0x08,
            0x0E,
            0x1C,
            0xFE,
            0x3C,
            0x30,
            0x19,
            0x18,
            0x7F,
            0xFF,
            0xF8,
            0x07,
            0xFE,
            0x00,
            0x38,
            0x00,
            0x00,
            0x06,
            0x1C,
            0xFE,
            0x38,
            0x31,
            0x9B,
            0x98,
            0x60,
            0x70,
            0x38,
            0x00,
            0x0E,
            0x00,
            0x3C,
            0x10,
            0x00,
            0x86,
            0x0C,
            0x00,
            0x38,
            0x33,
            0x99,
            0xD8,
            0x60,
            0x70,
            0x38,
            0x00,
            0x0E,
            0x00,
            0x3C,
            0x10,
            0x00,
            0x82,
            0x0C,
            0x00,
            0x38,
            0x00,
            0x00,
            0x00,
            0x60,
            0x70,
            0x38,
            0x00,
            0x0E,
            0x00,
            0x3C,
            0x18,
            0x41,
            0x86,
            0x0C,
            0x7E,
            0x38,
            0x00,
            0x00,
            0x00,
            0x60,
            0x70,
            0x38,
            0xFF,
            0xFF,
            0xF0,
            0x1E,
            0x38,
            0x41,
            0x86,
            0x0C,
            0x7E,
            0x18,
            0x3F,
            0xFF,
            0xF8,
            0x60,
            0x70,
            0x38,
            0xFF,
            0xFF,
            0xF0,
            0x1E,
            0x38,
            0xE3,
            0x8E,
            0x0C,
            0x7E,
            0x18,
            0x3F,
            0xFF,
            0xF8,
            0x60,
            0x70,
            0x38,
            0xFF,
            0xFF,
            0xF0,
            0x1E,
            0x7C,
            0xE2,
            0x0E,
            0x0C,
            0x66,
            0x38,
            0x00,
            0x00,
            0x18,
            0x7F,
            0xFF,
            0xF8,
            0x00,
            0x0E,
            0x00,
            0x1F,
            0xFF,
            0xFE,
            0x1E,
            0x0C,
            0x66,
            0x38,
            0x00,
            0x00,
            0x18,
            0x7F,
            0xFF,
            0xF0,
            0x00,
            0x0E,
            0x00,
            0x0F,
            0xFF,
            0xFE,
            0x0E,
            0x0C,
            0x66,
            0x38,
            0x1F,
            0xFF,
            0xF8,
            0x7F,
            0xFF,
            0xF0,
            0x00,
            0x0E,
            0x00,
            0x0F,
            0xFF,
            0xFE,
            0x1E,
            0x0C,
            0x66,
            0x3C,
            0x1F,
            0xFF,
            0xF8,
            0x00,
            0x70,
            0x00,
            0x00,
            0x0E,
            0x00,
            0x07,
            0xFF,
            0xFE,
            0x3E,
            0x0C,
            0x66,
            0x3C,
            0x10,
            0x00,
            0x38,
            0x00,
            0x70,
            0x00,
            0x00,
            0x0E,
            0x00,
            0x03,
            0xFF,
            0xFE,
            0x7E,
            0x0C,
            0x66,
            0x7C,
            0x00,
            0x00,
            0x18,
            0x00,
            0x70,
            0x00,
            0x00,
            0x1E,
            0x00,
            0x01,
            0xFF,
            0xFE,
            0xFE,
            0x0C,
            0xE7,
            0xEE,
            0x00,
            0x00,
            0x18,
            0x00,
            0x7F,
            0xF8,
            0x3F,
            0xFE,
            0x00,
            0x00,
            0xFF,
            0xFF,
            0xFE,
            0x0C,
            0xE7,
            0xEE,
            0x3F,
            0xFF,
            0xF8,
            0x00,
            0x3F,
            0xF8,
            0x3F,
            0xFE,
            0x00,
            0x00,
            0x7F,
            0xFF,
            0xFE,
            0x0C,
            0xC7,
            0xC6,
            0x3F,
            0xFF,
            0xF8,
            0x00,
            0x3F,
            0xF8,
            0x3F,
            0xFC,
            0x00,
            0x00,
            0x1F,
            0xFF,
            0xFE,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x03,
            0xFF,
            0xFE,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
    };

    static const uint8_t Bmp4016[96] = // SUN
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF1, 0x81, 0x8F, 0xFC, 0x3F,
            0xF1, 0x81, 0x8F, 0xFC, 0x30, 0x31, 0x81, 0x8C, 0x0C, 0x30, 0x01, 0x81, 0x8C, 0x0C, 0x30, 0x01,
            0x81, 0x8C, 0x0C, 0x3F, 0xF1, 0x81, 0x8C, 0x0C, 0x3F, 0xF1, 0x81, 0x8C, 0x0C, 0x00, 0x31, 0x81,
            0x8C, 0x0C, 0x00, 0x31, 0x81, 0x8C, 0x0C, 0x30, 0x31, 0x81, 0x8C, 0x0C, 0x3F, 0xF1, 0xFF, 0x8C,
            0x0C, 0x3F, 0xF1, 0xFF, 0x8C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    static const uint8_t Signal816[16] = // mobie singal
        {
            0xFE, 0x02, 0x92, 0x0A, 0x54, 0x2A, 0x38, 0xAA, 0x12, 0xAA, 0x12, 0xAA, 0x12, 0xAA, 0x12, 0xAA};

    static const uint8_t Msg816[16] = // message
        {
            0x1F, 0xF8, 0x10, 0x08, 0x18, 0x18, 0x14, 0x28, 0x13, 0xC8, 0x10, 0x08, 0x10, 0x08, 0x1F, 0xF8};

    static const uint8_t Bat816[16] = // batery
        {
            0x0F, 0xFE, 0x30, 0x02, 0x26, 0xDA, 0x26, 0xDA, 0x26, 0xDA, 0x26, 0xDA, 0x30, 0x02, 0x0F, 0xFE};

    static const uint8_t Bluetooth88[8] = // bluetooth
        {
            0x18, 0x54, 0x32, 0x1C, 0x1C, 0x32, 0x54, 0x18};

    static const uint8_t GPRS88[8] = // GPRS
        {
            0xC3, 0x99, 0x24, 0x20, 0x2C, 0x24, 0x99, 0xC3};

    static const uint8_t Alarm88[8] = // alram
        {
            0xC3, 0xBD, 0x42, 0x52, 0x4E, 0x42, 0x3C, 0xC3};

#ifdef __cplusplus
}
#endif
#endif
