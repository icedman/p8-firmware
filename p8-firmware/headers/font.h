#pragma once
/*
 * Bitmap font
 * font[character] is a byte array of the vertical columns of a letter
 * font[character][0] is the first (leftmost) column
 * The LSB of a column is the top most pixel.
 * To get the binary value of the nth pixel of a column going downwards, do (font[character][col] >> n-1) & 1;
 * Since some fonts don't represent the unprintable characters, (ascii 0-31), it starts at the first printable character, space
 * So in order to print an ascii character, you must first subtract an offset of 32 from the code to get the index of the font array
 * This is optional depending on the font, so there is a preprocessor command that handles that
 */

#define FONT_NEEDS_OFFSET false
#define FONT_WIDTH 5
#define FONT_HEIGHT 8

#define CHAR_NONE 0
#define GLYPH_CLOCK_UNSEL 1
#define GLYPH_CLOCK_SEL 2
#define GLYPH_DATA_UNSEL 3
#define GLYPH_DATA_SEL 4
#define GLYPH_STOPWATCH_UNSEL 5
#define GLYPH_STOPWATCH_SEL 6
#define GLYPH_SETTINGS_UNSEL 7
#define GLYPH_SETTINGS_SEL 8
#define GLYPH_ARROW_RIGHT 9
#define GLYPH_ARROW_LEFT 10
#define GLYPH_INFO_UNSEL 11
#define GLYPH_INFO_SEL 12
#define GLYPH_POWER_UNSEL 13
#define GLYPH_POWER_SEL 14
#define GLYPH_REBOOT_UNSEL 15
#define GLYPH_BOOTLOADER_UNSEL 16
#define GLYPH_WALKING 17
#define GLYPH_BATTERY 18
#define GLYPH_SMILEY 19
#define GLYPH_KM 20
#define GLYPH_WALKING_NO_EARTH 21

const unsigned char font[][5] =
    //Unprintable characters (used for images)
    {
        {0x00, 0x00, 0x00, 0x00, 0x00},  //Empty character
        {0x1E, 0x21, 0x2F, 0x29, 0x1E},  //Clock unselected
        {0x9E, 0xA1, 0xAF, 0xA9, 0x9E},  //Clock selected
        {0x3F, 0x22, 0x24, 0x28, 0x24},  //Data unsel
        {0xBF, 0xA2, 0xA4, 0xA8, 0xA4},  //Data sel
        {0x1C, 0x22, 0x2A, 0x27, 0x1C},  //Stopwatch unselected
        {0x9C, 0xA2, 0xAA, 0xA7, 0x9C},  //Stopwatch selected
        {0x20, 0x10, 0x0C, 0x0A, 0x04},  //Settings unselected
        {0xA0, 0x90, 0x8C, 0x8A, 0x84},  //Settings selected
        {0x7F, 0x3E, 0x1C, 0x08, 0x00},  //Arrow pointing right
        {0x08, 0x1C, 0x3E, 0x7F, 0x00},  //Arrow pointing left
        {0x00, 0x00, 0x3A, 0x00, 0x00},  //Information unselected
        {0x80, 0x80, 0xBA, 0x80, 0x80},  //Information selected
        {0x1C, 0x22, 0x2F, 0x22, 0x1C},  //Power menu unselected
        {0x9C, 0xA2, 0xAF, 0xA2, 0x9C},  //Power menu selected
        {0x64, 0x4E, 0x5F, 0x44, 0x7C},  //Reboot
        {0x04, 0x06, 0x7F, 0x06, 0x04},  //Bootloader
        {0xA8, 0xA4, 0x9E, 0xE4, 0x88},  //Guy walking glyph
        {0x00, 0xFC, 0xFE, 0xFC, 0x00},  //Battery glyph
        {0x24, 0x00, 0x00, 0x42, 0x3C},  //Smiley
        {0xEF, 0x24, 0x6A, 0x20, 0xE0},  //KM glyph
        {0x28, 0x24, 0x1E, 0x64, 0x08},  //Guy walking no earth
        {0x60, 0x60, 0x60, 0x60, 0x60},
        {0x94, 0xA2, 0xFF, 0xA2, 0x94},
        {0x08, 0x04, 0x7E, 0x04, 0x08},
        {0x10, 0x20, 0x7E, 0x20, 0x10},
        {0x08, 0x08, 0x2A, 0x1C, 0x08},
        {0x08, 0x1C, 0x2A, 0x08, 0x08},
        {0x1E, 0x10, 0x10, 0x10, 0x10},
        {0x0C, 0x1E, 0x0C, 0x1E, 0x0C},
        {0x30, 0x38, 0x3E, 0x38, 0x30},
        {0x06, 0x0E, 0x3E, 0x0E, 0x06},

        //Start of printable characters
        {0x00, 0x00, 0x00, 0x00, 0x00},  //Space
        {0x00, 0x00, 0x5F, 0x00, 0x00},  //!
        {0x00, 0x07, 0x00, 0x07, 0x00},  //And so on
        {0x14, 0x7F, 0x14, 0x7F, 0x14},
        {0x24, 0x2A, 0x7F, 0x2A, 0x12},
        {0x23, 0x13, 0x08, 0x64, 0x62},
        {0x36, 0x49, 0x56, 0x20, 0x50},
        {0x00, 0x08, 0x07, 0x03, 0x00},
        {0x00, 0x1C, 0x22, 0x41, 0x00},
        {0x00, 0x41, 0x22, 0x1C, 0x00},
        {0x2A, 0x1C, 0x7F, 0x1C, 0x2A},
        {0x08, 0x08, 0x3E, 0x08, 0x08},
        {0x00, 0x80, 0x70, 0x30, 0x00},
        {0x00, 0x08, 0x08, 0x08, 0x00},
        {0x00, 0x00, 0x60, 0x60, 0x00},
        {0x20, 0x10, 0x08, 0x04, 0x02},
        {0x3E, 0x51, 0x49, 0x45, 0x3E},
        {0x00, 0x42, 0x7F, 0x40, 0x00},
        {0x72, 0x49, 0x49, 0x49, 0x46},
        {0x21, 0x41, 0x49, 0x4D, 0x33},
        {0x18, 0x14, 0x12, 0x7F, 0x10},
        {0x27, 0x45, 0x45, 0x45, 0x39},
        {0x3C, 0x4A, 0x49, 0x49, 0x31},
        {0x41, 0x21, 0x11, 0x09, 0x07},
        {0x36, 0x49, 0x49, 0x49, 0x36},
        {0x46, 0x49, 0x49, 0x29, 0x1E},
        {0x00, 0x00, 0x14, 0x00, 0x00},
        {0x00, 0x40, 0x34, 0x00, 0x00},
        {0x00, 0x08, 0x14, 0x22, 0x41},
        {0x14, 0x14, 0x14, 0x14, 0x14},
        {0x00, 0x41, 0x22, 0x14, 0x08},
        {0x02, 0x01, 0x59, 0x09, 0x06},
        {0x3E, 0x41, 0x5D, 0x59, 0x4E},
        {0x7C, 0x12, 0x11, 0x12, 0x7C},
        {0x7F, 0x49, 0x49, 0x49, 0x36},
        {0x3E, 0x41, 0x41, 0x41, 0x22},
        {0x7F, 0x41, 0x41, 0x41, 0x3E},
        {0x7F, 0x49, 0x49, 0x49, 0x41},
        {0x7F, 0x09, 0x09, 0x09, 0x01},
        {0x3E, 0x41, 0x41, 0x51, 0x73},
        {0x7F, 0x08, 0x08, 0x08, 0x7F},
        {0x00, 0x41, 0x7F, 0x41, 0x00},
        {0x20, 0x40, 0x41, 0x3F, 0x01},
        {0x7F, 0x08, 0x14, 0x22, 0x41},
        {0x7F, 0x40, 0x40, 0x40, 0x40},
        {0x7F, 0x02, 0x1C, 0x02, 0x7F},
        {0x7F, 0x04, 0x08, 0x10, 0x7F},
        {0x3E, 0x41, 0x41, 0x41, 0x3E},
        {0x7F, 0x09, 0x09, 0x09, 0x06},
        {0x3E, 0x41, 0x51, 0x21, 0x5E},
        {0x7F, 0x09, 0x19, 0x29, 0x46},
        {0x26, 0x49, 0x49, 0x49, 0x32},
        {0x03, 0x01, 0x7F, 0x01, 0x03},
        {0x3F, 0x40, 0x40, 0x40, 0x3F},
        {0x1F, 0x20, 0x40, 0x20, 0x1F},
        {0x3F, 0x40, 0x38, 0x40, 0x3F},
        {0x63, 0x14, 0x08, 0x14, 0x63},
        {0x03, 0x04, 0x78, 0x04, 0x03},
        {0x61, 0x59, 0x49, 0x4D, 0x43},
        {0x00, 0x7F, 0x41, 0x41, 0x41},
        {0x02, 0x04, 0x08, 0x10, 0x20},
        {0x00, 0x41, 0x41, 0x41, 0x7F},
        {0x04, 0x02, 0x01, 0x02, 0x04},
        {0x40, 0x40, 0x40, 0x40, 0x40},
        {0x00, 0x03, 0x07, 0x08, 0x00},
        {0x20, 0x54, 0x54, 0x78, 0x40},
        {0x7F, 0x28, 0x44, 0x44, 0x38},
        {0x38, 0x44, 0x44, 0x44, 0x28},
        {0x38, 0x44, 0x44, 0x28, 0x7F},
        {0x38, 0x54, 0x54, 0x54, 0x18},
        {0x00, 0x08, 0x7E, 0x09, 0x02},
        {0x18, 0xA4, 0xA4, 0x9C, 0x78},
        {0x7F, 0x08, 0x04, 0x04, 0x78},
        {0x00, 0x44, 0x7D, 0x40, 0x00},
        {0x20, 0x40, 0x40, 0x3D, 0x00},
        {0x7F, 0x10, 0x28, 0x44, 0x00},
        {0x00, 0x41, 0x7F, 0x40, 0x00},
        {0x7C, 0x04, 0x78, 0x04, 0x78},
        {0x7C, 0x08, 0x04, 0x04, 0x78},
        {0x38, 0x44, 0x44, 0x44, 0x38},
        {0xFC, 0x18, 0x24, 0x24, 0x18},
        {0x18, 0x24, 0x24, 0x18, 0xFC},
        {0x7C, 0x08, 0x04, 0x04, 0x08},
        {0x48, 0x54, 0x54, 0x54, 0x24},
        {0x04, 0x04, 0x3F, 0x44, 0x24},
        {0x3C, 0x40, 0x40, 0x20, 0x7C},
        {0x1C, 0x20, 0x40, 0x20, 0x1C},
        {0x3C, 0x40, 0x30, 0x40, 0x3C},
        {0x44, 0x28, 0x10, 0x28, 0x44},
        {0x4C, 0x90, 0x90, 0x90, 0x7C},
        {0x44, 0x64, 0x54, 0x4C, 0x44},
        {0x00, 0x08, 0x36, 0x41, 0x00},
        {0x00, 0x00, 0x77, 0x00, 0x00},
        {0x00, 0x41, 0x36, 0x08, 0x00},
        {0x02, 0x01, 0x02, 0x04, 0x02},
        {0x3C, 0x26, 0x23, 0x26, 0x3C},
        {0x1E, 0xA1, 0xA1, 0x61, 0x12},
        {0x3A, 0x40, 0x40, 0x20, 0x7A},
        {0x38, 0x54, 0x54, 0x55, 0x59},
        {0x21, 0x55, 0x55, 0x79, 0x41},
        {0x21, 0x54, 0x54, 0x78, 0x41},
        {0x21, 0x55, 0x54, 0x78, 0x40},
        {0x20, 0x54, 0x55, 0x79, 0x40},
        {0x0C, 0x1E, 0x52, 0x72, 0x12},
        {0x39, 0x55, 0x55, 0x55, 0x59},
        {0x39, 0x54, 0x54, 0x54, 0x59},
        {0x39, 0x55, 0x54, 0x54, 0x58},
        {0x00, 0x00, 0x45, 0x7C, 0x41},
        {0x00, 0x02, 0x45, 0x7D, 0x42},
        {0x00, 0x01, 0x45, 0x7C, 0x40},
        {0xF0, 0x29, 0x24, 0x29, 0xF0},
        {0xF0, 0x28, 0x25, 0x28, 0xF0},
        {0x7C, 0x54, 0x55, 0x45, 0x00},
        {0x20, 0x54, 0x54, 0x7C, 0x54},
        {0x7C, 0x0A, 0x09, 0x7F, 0x49},
        {0x32, 0x49, 0x49, 0x49, 0x32},
        {0x32, 0x48, 0x48, 0x48, 0x32},
        {0x32, 0x4A, 0x48, 0x48, 0x30},
        {0x3A, 0x41, 0x41, 0x21, 0x7A},
        {0x3A, 0x42, 0x40, 0x20, 0x78},
        {0x7f, 0x25, 0x25, 0x25, 0x1a},
        {0x39, 0x44, 0x44, 0x44, 0x39},
        {0x3D, 0x40, 0x40, 0x40, 0x3D},
        {0x3C, 0x24, 0xFF, 0x24, 0x24},
        {0x48, 0x7E, 0x49, 0x43, 0x66},
        {0x2B, 0x2F, 0xFC, 0x2F, 0x2B},
        {0xFF, 0x09, 0x29, 0xF6, 0x20},
        {0xC0, 0x88, 0x7E, 0x09, 0x03},
        {0x20, 0x54, 0x54, 0x79, 0x41},
        {0x00, 0x00, 0x44, 0x7D, 0x41},
        {0x30, 0x48, 0x48, 0x4A, 0x32},
        {0x38, 0x40, 0x40, 0x22, 0x7A},
        {0x00, 0x7A, 0x0A, 0x0A, 0x72},
        {0x7D, 0x0D, 0x19, 0x31, 0x7D},
        {0x26, 0x29, 0x29, 0x2F, 0x28},
        {0x26, 0x29, 0x29, 0x29, 0x26},
        {0x30, 0x48, 0x4D, 0x40, 0x20},
        {0x38, 0x08, 0x08, 0x08, 0x08},
        {0x08, 0x08, 0x08, 0x08, 0x38},
        {0x2F, 0x10, 0xC8, 0xAC, 0xBA},
        {0x2F, 0x10, 0x28, 0x34, 0xFA},
        {0x00, 0x00, 0x7B, 0x00, 0x00},
        {0x08, 0x14, 0x2A, 0x14, 0x22},
        {0x22, 0x14, 0x2A, 0x14, 0x08},
        {0xAA, 0x00, 0x55, 0x00, 0xAA},
        {0xAA, 0x55, 0xAA, 0x55, 0xAA},
        {0x00, 0x00, 0x00, 0xFF, 0x00},
        {0x10, 0x10, 0x10, 0xFF, 0x00},
        {0x14, 0x14, 0x14, 0xFF, 0x00},
        {0x10, 0x10, 0xFF, 0x00, 0xFF},
        {0x10, 0x10, 0xF0, 0x10, 0xF0},
        {0x14, 0x14, 0x14, 0xFC, 0x00},
        {0x14, 0x14, 0xF7, 0x00, 0xFF},
        {0x00, 0x00, 0xFF, 0x00, 0xFF},
        {0x14, 0x14, 0xF4, 0x04, 0xFC},
        {0x14, 0x14, 0x17, 0x10, 0x1F},
        {0x10, 0x10, 0x1F, 0x10, 0x1F},
        {0x14, 0x14, 0x14, 0x1F, 0x00},
        {0x10, 0x10, 0x10, 0xF0, 0x00},
        {0x00, 0x00, 0x00, 0x1F, 0x10},
        {0x10, 0x10, 0x10, 0x1F, 0x10},
        {0x10, 0x10, 0x10, 0xF0, 0x10},
        {0x00, 0x00, 0x00, 0xFF, 0x10},
        {0x10, 0x10, 0x10, 0x10, 0x10},
        {0x10, 0x10, 0x10, 0xFF, 0x10},
        {0x00, 0x00, 0x00, 0xFF, 0x14},
        {0x00, 0x00, 0xFF, 0x00, 0xFF},
        {0x00, 0x00, 0x1F, 0x10, 0x17},
        {0x00, 0x00, 0xFC, 0x04, 0xF4},
        {0x14, 0x14, 0x17, 0x10, 0x17},
        {0x14, 0x14, 0xF4, 0x04, 0xF4},
        {0x00, 0x00, 0xFF, 0x00, 0xF7},
        {0x14, 0x14, 0x14, 0x14, 0x14},
        {0x14, 0x14, 0xF7, 0x00, 0xF7},
        {0x14, 0x14, 0x14, 0x17, 0x14},
        {0x10, 0x10, 0x1F, 0x10, 0x1F},
        {0x14, 0x14, 0x14, 0xF4, 0x14},
        {0x10, 0x10, 0xF0, 0x10, 0xF0},
        {0x00, 0x00, 0x1F, 0x10, 0x1F},
        {0x00, 0x00, 0x00, 0x1F, 0x14},
        {0x00, 0x00, 0x00, 0xFC, 0x14},
        {0x00, 0x00, 0xF0, 0x10, 0xF0},
        {0x10, 0x10, 0xFF, 0x10, 0xFF},
        {0x14, 0x14, 0x14, 0xFF, 0x14},
        {0x10, 0x10, 0x10, 0x1F, 0x00},
        {0x00, 0x00, 0x00, 0xF0, 0x10},
        {0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
        {0xF0, 0xF0, 0xF0, 0xF0, 0xF0},
        {0xFF, 0xFF, 0xFF, 0x00, 0x00},
        {0x00, 0x00, 0x00, 0xFF, 0xFF},
        {0x0F, 0x0F, 0x0F, 0x0F, 0x0F},
        {0x38, 0x44, 0x44, 0x38, 0x44},
        {0x7C, 0x2A, 0x2A, 0x3E, 0x14},
        {0x7E, 0x02, 0x02, 0x06, 0x06},
        {0x02, 0x7E, 0x02, 0x7E, 0x02},
        {0x63, 0x55, 0x49, 0x41, 0x63},
        {0x38, 0x44, 0x44, 0x3C, 0x04},
        {0x40, 0x7E, 0x20, 0x1E, 0x20},
        {0x06, 0x02, 0x7E, 0x02, 0x02},
        {0x99, 0xA5, 0xE7, 0xA5, 0x99},
        {0x1C, 0x2A, 0x49, 0x2A, 0x1C},
        {0x4C, 0x72, 0x01, 0x72, 0x4C},
        {0x30, 0x4A, 0x4D, 0x4D, 0x30},
        {0x30, 0x48, 0x78, 0x48, 0x30},
        {0xBC, 0x62, 0x5A, 0x46, 0x3D},
        {0x3E, 0x49, 0x49, 0x49, 0x00},
        {0x7E, 0x01, 0x01, 0x01, 0x7E},
        {0x2A, 0x2A, 0x2A, 0x2A, 0x2A},
        {0x44, 0x44, 0x5F, 0x44, 0x44},
        {0x40, 0x51, 0x4A, 0x44, 0x40},
        {0x40, 0x44, 0x4A, 0x51, 0x40},
        {0x00, 0x00, 0xFF, 0x01, 0x03},
        {0xE0, 0x80, 0xFF, 0x00, 0x00},
        {0x08, 0x08, 0x6B, 0x6B, 0x08},
        {0x36, 0x12, 0x36, 0x24, 0x36},
        {0x06, 0x0F, 0x09, 0x0F, 0x06},
        {0x00, 0x00, 0x18, 0x18, 0x00},
        {0x00, 0x00, 0x10, 0x10, 0x00},
        {0x30, 0x40, 0xFF, 0x01, 0x01},
        {0x00, 0x1F, 0x01, 0x01, 0x1E},
        {0x00, 0x19, 0x1D, 0x17, 0x12},
        {0x00, 0x3C, 0x3C, 0x3C, 0x3C},
        {0x00, 0x00, 0x00, 0x00, 0x00}};