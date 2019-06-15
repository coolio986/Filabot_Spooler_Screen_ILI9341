/*!
 * @file Adafruit_TFTDMA.h
 *
 * This is part of Adafruit's SAMD51 DMA-driven ILI9341 display library.
 * It is designed specifically for this microcontroller and display combo,
 * using the display's parallel interface.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Phil "PaintYourDragon" Burgess for Adafruit Industries.
 *
 * BSD license, all text here must be included in any redistribution.
 */

#ifndef _ADAFRUIT_TFTDMA_H_
#define _ADAFRUIT_TFTDMA_H_

#include <stdint.h>

#define TFT_INTERFACE_8   0 ///< 8-bit parallel interface
#define TFT_INTERFACE_16  1 ///< 16-bit parallel - work-in-progress
#define TFT_INTERFACE_SPI 2 ///< SPI - totally not implemented at all

// Display interface must be defined at compile-time, it's baked-in deep.
#define TFT_INTERFACE TFT_INTERFACE_8  ///< Select interface methodology
#define TFTWIDTH      320  ///< Display width in pixels
#define TFTHEIGHT     240  ///< Display height in pixels

#define ILI9341_MADCTL_MY 0x80  ///< Row Address Order
#define ILI9341_MADCTL_MX 0x40  ///< Column Address Order
#define ILI9341_MADCTL_MV 0x20  ///< Row/Column Exchange
#define ILI9341_MADCTL_ML 0x10  ///< Vertical Regresh Order
#define ILI9341_MADCTL_RGB 0x00 ///< RGB Order
#define ILI9341_MADCTL_BGR 0x08 ///< BGR Order
#define ILI9341_MADCTL_MH 0x04  ///< Horizontal Regresh Order

// Rotation definitions
#define ROTATION0 ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR  
#define ROTATION90 ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR
#define ROTATION180 ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR  
#define ROTATION270 ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR


// Color definitions
#define ILI9341_ALICEBLUE 0xF7DF 
#define ILI9341_ANTIQUEWHITE 0xFF5A 
#define ILI9341_AQUA 0x07FF 
#define ILI9341_AQUAMARINE 0x7FFA 
#define ILI9341_AZURE 0xF7FF 
#define ILI9341_BEIGE 0xF7BB 
#define ILI9341_BISQUE 0xFF38 
#define ILI9341_BLACK 0x0000 
#define ILI9341_BLANCHEDALMOND 0xFF59 
#define ILI9341_BLUE 0x001F 
#define ILI9341_BLUEVIOLET 0x895C 
#define ILI9341_BROWN 0xA145 
#define ILI9341_BURLYWOOD 0xDDD0 
#define ILI9341_CADETBLUE 0x5CF4 
#define ILI9341_CHARTREUSE 0x7FE0 
#define ILI9341_CHOCOLATE 0xD343 
#define ILI9341_CORAL 0xFBEA 
#define ILI9341_CORNFLOWERBLUE 0x64BD 
#define ILI9341_CORNSILK 0xFFDB 
#define ILI9341_CRIMSON 0xD8A7 
#define ILI9341_CYAN 0x07FF 
#define ILI9341_DARKBLUE 0x0011 
#define ILI9341_DARKCYAN 0x0451 
#define ILI9341_DARKGOLDENROD 0xBC21 
#define ILI9341_DARKGRAY 0xAD55 
#define ILI9341_DARKGREEN 0x0320 
#define ILI9341_DARKKHAKI 0xBDAD 
#define ILI9341_DARKMAGENTA 0x8811 
#define ILI9341_DARKOLIVEGREEN 0x5345 
#define ILI9341_DARKORANGE 0xFC60 
#define ILI9341_DARKORCHID 0x9999 
#define ILI9341_DARKRED 0x8800 
#define ILI9341_DARKSALMON 0xECAF 
#define ILI9341_DARKSEAGREEN 0x8DF1 
#define ILI9341_DARKSLATEBLUE 0x49F1 
#define ILI9341_DARKSLATEGRAY 0x2A69 
#define ILI9341_DARKTURQUOISE 0x067A 
#define ILI9341_DARKVIOLET 0x901A 
#define ILI9341_DEEPPINK 0xF8B2 
#define ILI9341_DEEPSKYBLUE 0x05FF 
#define ILI9341_DIMGRAY 0x6B4D 
#define ILI9341_DODGERBLUE 0x1C9F 
#define ILI9341_FIREBRICK 0xB104 
#define ILI9341_FLORALWHITE 0xFFDE 
#define ILI9341_FORESTGREEN 0x2444 
#define ILI9341_FUCHSIA 0xF81F 
#define ILI9341_GAINSBORO 0xDEFB 
#define ILI9341_GHOSTWHITE 0xFFDF 
#define ILI9341_GOLD 0xFEA0 
#define ILI9341_GOLDENROD 0xDD24 
#define ILI9341_GRAY 0x8410 
#define ILI9341_GREEN 0x0400 
#define ILI9341_GREENYELLOW 0xAFE5 
#define ILI9341_HONEYDEW 0xF7FE 
#define ILI9341_HOTPINK 0xFB56 
#define ILI9341_INDIANRED 0xCAEB 
#define ILI9341_INDIGO 0x4810 
#define ILI9341_IVORY 0xFFFE 
#define ILI9341_KHAKI 0xF731 
#define ILI9341_LAVENDER 0xE73F 
#define ILI9341_LAVENDERBLUSH 0xFF9E 
#define ILI9341_LAWNGREEN 0x7FE0 
#define ILI9341_LEMONCHIFFON 0xFFD9 
#define ILI9341_LIGHTBLUE 0xAEDC 
#define ILI9341_LIGHTCORAL 0xF410 
#define ILI9341_LIGHTCYAN 0xE7FF 
#define ILI9341_LIGHTGOLDENRODYELLOW 0xFFDA 
#define ILI9341_LIGHTGREEN 0x9772 
#define ILI9341_LIGHTGREY 0xD69A 
#define ILI9341_LIGHTPINK 0xFDB8 
#define ILI9341_LIGHTSALMON 0xFD0F 
#define ILI9341_LIGHTSEAGREEN 0x2595 
#define ILI9341_LIGHTSKYBLUE 0x867F 
#define ILI9341_LIGHTSLATEGRAY 0x7453 
#define ILI9341_LIGHTSTEELBLUE 0xB63B 
#define ILI9341_LIGHTYELLOW 0xFFFC 
#define ILI9341_LIME 0x07E0 
#define ILI9341_LIMEGREEN 0x3666 
#define ILI9341_LINEN 0xFF9C 
#define ILI9341_MAGENTA 0xF81F 
#define ILI9341_MAROON 0x8000 
#define ILI9341_MEDIUMAQUAMARINE 0x6675 
#define ILI9341_MEDIUMBLUE 0x0019 
#define ILI9341_MEDIUMORCHID 0xBABA 
#define ILI9341_MEDIUMPURPLE 0x939B 
#define ILI9341_MEDIUMSEAGREEN 0x3D8E 
#define ILI9341_MEDIUMSLATEBLUE 0x7B5D 
#define ILI9341_MEDIUMSPRINGGREEN 0x07D3 
#define ILI9341_MEDIUMTURQUOISE 0x4E99 
#define ILI9341_MEDIUMVIOLETRED 0xC0B0 
#define ILI9341_MIDNIGHTBLUE 0x18CE 
#define ILI9341_MINTCREAM 0xF7FF 
#define ILI9341_MISTYROSE 0xFF3C 
#define ILI9341_MOCCASIN 0xFF36 
#define ILI9341_NAVAJOWHITE 0xFEF5 
#define ILI9341_NAVY 0x0010 
#define ILI9341_OLDLACE 0xFFBC 
#define ILI9341_OLIVE 0x8400 
#define ILI9341_OLIVEDRAB 0x6C64 
#define ILI9341_ORANGE 0xFD20 
#define ILI9341_ORANGERED 0xFA20 
#define ILI9341_ORCHID 0xDB9A 
#define ILI9341_PALEGOLDENROD 0xEF55 
#define ILI9341_PALEGREEN 0x9FD3 
#define ILI9341_PALETURQUOISE 0xAF7D 
#define ILI9341_PALEVIOLETRED 0xDB92 
#define ILI9341_PAPAYAWHIP 0xFF7A 
#define ILI9341_PEACHPUFF 0xFED7 
#define ILI9341_PERU 0xCC27 
#define ILI9341_PINK 0xFE19 
#define ILI9341_PLUM 0xDD1B 
#define ILI9341_POWDERBLUE 0xB71C 
#define ILI9341_PURPLE 0x8010 
#define ILI9341_RED 0xF800 
#define ILI9341_ROSYBROWN 0xBC71 
#define ILI9341_ROYALBLUE 0x435C 
#define ILI9341_SADDLEBROWN 0x8A22 
#define ILI9341_SALMON 0xFC0E 
#define ILI9341_SANDYBROWN 0xF52C 
#define ILI9341_SEAGREEN 0x2C4A 
#define ILI9341_SEASHELL 0xFFBD 
#define ILI9341_SIENNA 0xA285 
#define ILI9341_SILVER 0xC618 
#define ILI9341_SKYBLUE 0x867D 
#define ILI9341_SLATEBLUE 0x6AD9 
#define ILI9341_SLATEGRAY 0x7412 
#define ILI9341_SNOW 0xFFDF 
#define ILI9341_SPRINGGREEN 0x07EF 
#define ILI9341_STEELBLUE 0x4416 
#define ILI9341_TAN 0xD5B1 
#define ILI9341_TEAL 0x0410 
#define ILI9341_THISTLE 0xDDFB 
#define ILI9341_TOMATO 0xFB08 
#define ILI9341_TURQUOISE 0x471A 
#define ILI9341_VIOLET 0xEC1D 
#define ILI9341_WHEAT 0xF6F6 
#define ILI9341_WHITE 0xFFFF 
#define ILI9341_WHITESMOKE 0xF7BE 
#define ILI9341_YELLOW 0xFFE0 
#define ILI9341_YELLOWGREEN 0x9E66

#include <Adafruit_ZeroDMA.h>
#include "utility/dma.h"
#include <Adafruit_GFX.h>

//--------------------------------------------------------------------------
/*! 
  @brief  A base class that interfaces with the SAMD51 hardware, including
          PORTs, timer/counters, DMA and other operipherals.  Unlikely to
          be instantiated on its own, a few subclasses are provided that
          represent the display and graphics memory in different ways.
          Applications must be designed around ONE of these subclasses and
          stick with it; can't toggle among them.
*/
class Adafruit_TFTDMA : public Adafruit_GFX {
  public:
    /*!
      @brief  Constructor.  Takes note of the hardware configuration to use,
              but does not itself initialize any hardware yet.
      @param  tc      Index of timer/counter peripheral for PWM (used for
                      generating write-strobe pulses), e.g. pass 2 to use
                      the TC2 peripheral.  Certain timer/counters may be
                      in use by other libraries or reserved for the Arduino
                      millis()/micros() timers.
      @param  reset   Index of pin connected to the ILI9341's reset line, or
                      -1 if unconnected.  Using the reset line is optional
                      but strongly recommended.
      @param  cs      Index of pin connected to ILI9341 chip select line.
                      Required; must be >= 0.
      @param  cd      Index of pin connected to ILI9341 command/data line.
                      Required; must be >= 0.
      @param  rd      Index of pin connected to ILI9341 read-strobe line, or
                      -1 if unconnected.  This library currently doesn't
                      read any registers or pixel data from the device; it
                      is coded specifically for this driver and write-only,
                      so -1 is totally acceptable and even preferred here.
                      Maybe this parameter will be removed in the future.
      @param  wr      Index of pin connected to ILI9341 write-strobe line.
                      Required; must be >= 0.  Additionally, this pin must
                      be a valid TCx/WO[0] output for the timer/counter
                      specified by the first parameter, OR a CCL/OUT[x] pin
                      for the same timer counter (see last parameter).
      @param  d0      Index of pin connected to ILI9341 data bit 0 line.
                      Required; must be >= 0.  Additionally, the
                      corresponding PORT bit index for this pin MUST be the
                      least-significant bit of an 8-bit byte (e.g. 0, 8, 16
                      or 24) if using the 8-bit parallel interface, or the
                      least-significant bit of a 16-bit halfword (e.g. 0 or
                      16) if using the 16-bit parallel interface.  Use of
                      the next 7 or 15 bits of the PORT is implied, the pins
                      corresponding to those bits might not be contiguous or
                      sequential; refer to the schematic or device-specific
                      variant.cpp file for insights.
      @param  periph  Peripheral type connected to the write-strobe pin for
                      PWM out.  This can be PIO_TIMER or PIO_TIMER_ALT
                      corresponding to TCx/WO[0] for that pin, or PIO_CCL
                      for CCL/OUT[x] on a pin.  PIO_TIMER and PIO_TIMER_ALT
                      require the use of an external logic inverter (the
                      ILI9341 uses active-low control signals).  PIO_CCL
                      does not need an inverter, but the choice of pins is
                      very limited, perhaps just one or two.
    */
    Adafruit_TFTDMA(int8_t tc, int8_t reset, int8_t cs, int8_t cd,
                    int8_t rd, int8_t wr, int8_t d0, _EPioType periph);
    /*!
      @brief   Initializes all pins and peripherals used by the library.
      @return  true if an error occurred, false otherwise.  An error
               returned here is usually symptomatic of a constructor
               problem, such as an invalid pin or timer number.
    */
    bool               begin(void);
	
	
  protected:
#if TFT_INTERFACE == TFT_INTERFACE_8
    volatile uint8_t  *writePort;    ///< Pointer to 8-bit PORT OUT
    volatile uint8_t  *readPort;     ///< Pointer to 8-bit PORT IN
    volatile uint8_t  *dirSet;       ///< 8-bit PORT direction set
    volatile uint8_t  *dirClr;       ///< 8-bit Port direction clear
#elif TFT_INTERFACE == TFT_INTERFACE_16
    volatile uint16_t *writePort;    ///< Pointer to 16-bit PORT OUT
    volatile uint16_t *readPort;     ///< Pointer to 16-bit PORT IN
    volatile uint16_t *dirSet;       ///< 16-bit PORT direction set
    volatile uint16_t *dirClr;       ///< 16-bit PORT direction clear
#endif
    volatile uint32_t *csPortSet;    ///< Pointer to CS pin PORT SET register
    volatile uint32_t *csPortClr;    ///< Pointer to CS pin PORT CLEAR register
    volatile uint32_t *cdPortSet;    ///< Pointer to CD pin PORT SET register
    volatile uint32_t *cdPortClr;    ///< Pointer to CD pin PORT CLEAR register
    volatile uint32_t *rdPortSet;    ///< Pointer to RD pin PORT SET register
    volatile uint32_t *rdPortClr;    ///< Pointer to RD pin PORT CLEAR register
    volatile uint32_t *wrPortActive; ///< Pointer to WR pin PORT active register
    volatile uint32_t *wrPortIdle;   ///< Pointer to WR pin PORT idle register
    uint32_t           csPinMask;    ///< Bitmask for CS pin PORT
    uint32_t           cdPinMask;    ///< Bitmask for CD pin PORT
    uint32_t           rdPinMask;    ///< Bitmask for RD pin PORT
    uint32_t           wrPinMask;    ///< Bitmask for WR pin PORT
    int8_t             csPin;        ///< Index of CS pin (or -1)
    int8_t             cdPin;        ///< Index of CD pin
    int8_t             rdPin;        ///< Index of RD pin
    int8_t             wrPin;        ///< Index of WR pin
    int8_t             resetPin;     ///< Index of RESET pin (or -1)
    int8_t             d0Pin;        ///< Index of data bit 0 pin
    int8_t             tcNum;        ///< Timer/Counter number
	
	
    _EPioType          wrPeripheral; ///< WR strobe peripheral type
    Adafruit_ZeroDMA   dma;          ///< DMA instance
    /*!
      @brief  Writes an 8-bit value to an ILI9341 configuration register.
      @param  reg    Device register to write.
      @param  value  Value written to register.
    */
    void               writeReg8(uint8_t reg, uint8_t value);
    /*!
      @brief  Writes a 16-bit value to an ILI9341 configuration register.
      @param  reg    Device register to write.
      @param  value  Value written to register.
    */
    void               writeReg16(uint8_t reg, uint16_t value);
    /*!
      @brief  Writes a 32-bit value to an ILI9341 configuration register.
      @param  reg    Device register to write.
      @param  value  Value written to register.
    */
    void               writeReg32(uint8_t reg, uint32_t value);
    /*!
      @brief  Sets the ILI9341 'address window' for subsequent graphics
              operations.  This also issues a MEMORYWRITE command and leaves
              the device selected and in DATA mode for incoming pixel data.
              Inputs are NOT sorted or clipped; subclasses provide
              higher-level functions that ensure the validity of these
              parameters.
      @param  x1  Left edge of graphics window (0 to TFTWIDTH-1).
      @param  y1  Top edge of graphics window (0 to TFTHEIGHT-1).
      @param  x2  Right edge of graphics window (0 to TFTWIDTH-1).
      @param  y2  Bottom edge of graphics window (0 to TFTHEIGHT-1).
    */
    void               setAddrWindow(int16_t x1, int16_t y1,
                                     int16_t x2, int16_t y2);
#if 0 // Not used:
    /*!
      @brief  Reads device ID from ILI9341 and confirms device is this type.
              Currently not used...the library is intended specifically for
              this chip, on purpose-built hardware.
    */
    uint32_t           readID(void);
#endif
};


//--------------------------------------------------------------------------
/*! 
  @brief  Subclass of Adafruit_TFTDMA providing a whole-screen contiguous
          framebuffer.  This is probably the easiest subclass to understand,
          but requires an enormous amount of RAM, nearly 160 kilobytes.
*/
class TFT_framebuffer : public Adafruit_TFTDMA {
  public:
    /*!
      @brief  Constructor.  Takes note of the hardware configuration to use,
              but does not itself initialize any hardware yet.
      @param  tc      Index of timer/counter peripheral for PWM (used for
                      generating write-strobe pulses), e.g. pass 2 to use
                      the TC2 peripheral.  Certain timer/counters may be
                      in use by other libraries or reserved for the Arduino
                      millis()/micros() timers.
      @param  reset   Index of pin connected to the ILI9341's reset line, or
                      -1 if unconnected.  Using the reset line is optional
                      but strongly recommended.
      @param  cs      Index of pin connected to ILI9341 chip select line.
                      Required; must be >= 0.
      @param  cd      Index of pin connected to ILI9341 command/data line.
                      Required; must be >= 0.
      @param  rd      Index of pin connected to ILI9341 read-strobe line, or
                      -1 if unconnected.  This library currently doesn't
                      read any registers or pixel data from the device; it
                      is coded specifically for this driver and write-only,
                      so -1 is totally acceptable and even preferred here.
                      Maybe this parameter will be removed in the future.
      @param  wr      Index of pin connected to ILI9341 write-strobe line.
                      Required; must be >= 0.  Additionally, this pin must
                      be a valid TCx/WO[0] output for the timer/counter
                      specified by the first parameter, OR a CCL/OUT[x] pin
                      for the same timer counter (see last parameter).
      @param  d0      Index of pin connected to ILI9341 data bit 0 line.
                      Required; must be >= 0.  Additionally, the
                      corresponding PORT bit index for this pin MUST be the
                      least-significant bit of an 8-bit byte (e.g. 0, 8, 16
                      or 24) if using the 8-bit parallel interface, or the
                      least-significant bit of a 16-bit halfword (e.g. 0 or
                      16) if using the 16-bit parallel interface.  Use of
                      the next 7 or 15 bits of the PORT is implied, the pins
                      corresponding to those bits might not be contiguous or
                      sequential; refer to the schematic or device-specific
                      variant.cpp file for insights.
      @param  periph  Peripheral type connected to the write-strobe pin for
                      PWM out.  This can be PIO_TIMER or PIO_TIMER_ALT
                      corresponding to TCx/WO[0] for that pin, or PIO_CCL
                      for CCL/OUT[x] on a pin.  PIO_TIMER and PIO_TIMER_ALT
                      require the use of an external logic inverter (the
                      ILI9341 uses active-low control signals).  PIO_CCL
                      does not need an inverter, but the choice of pins is
                      very limited, perhaps just one or two.
    */
    TFT_framebuffer(int8_t tc, int8_t reset, int8_t cs, int8_t cd, int8_t rd,
                    int8_t wr, int8_t d0, _EPioType periph);
					
	
    /*!
      @brief   Initializes all pins and peripherals used by the library.
      @return  true if an error occurred, false otherwise.  An error
               returned here is usually symptomatic of a constructor
               problem, such as an invalid pin or timer number.
    */
    bool            begin(void);
    /*!
      @brief   Refreshes the display based on the current 'dirty rectangle'
               bounds set by other graphics functions.  Initiates a DMA
               transfer and returns immediately -- application can proceed
               with other code at that point but MUST not modify the
               framebuffer as it's transferred.
    */
    void            update(void);
    /*!
      @brief   Wait for the DMA transfer initiated by update() to complete.
               Dirty rectangle is reset and framebuffer can then be modified.
    */
    void            waitForUpdate(void);
    /*!
      @brief   Set or expand the current dirty rectangle to contain a given
               pixel coordinate.  Input MUST be valid; is NOT clipped.  The
               few graphics primitives provided will set or expand the dirty
               rectangle automatically, this function is mostly for one's own
               code that may be modifying the framebuffer contents.
      @param   x  Horizontal position of pixel (0 to TFTWIDTH-1).
      @param   y  Vertical position of pixel (0 to TFTWIDTH-1).
    */
    void            sully(int16_t x, int16_t y);
    /*!
      @brief   Get the base address of the framebuffer.
      @return  Pointer to framebuffer data; contiguous row-major TFTWIDTH x
               TFTHEIGHT uint16_t values.
    */
    uint16_t       *getBuffer(void);
    /*!
      @brief   Get the framebuffer's current dirty rectangle, if any.
               This may be helpful if an application finds it easier or more
               efficient to simply erase a whole bounding area rather than
               multiple small elements within.
      @param   x1  Pointer to signed 16-bit type to hold LEFT edge of dirty
                   rectangle, if set (else will be >= TFTWIDTH).
      @param   y1  Pointer to signed 16-bit type to hold TOP edge of dirty
                   rectangle, if set (else will be >= TFTHEIGHT).
      @param   x2  Pointer to signed 16-bit type to hold RIGHT edge of dirty
                   rectangle, if set (else will be -1).
      @param   y2  Pointer to signed 16-bit type to hold BOTTOM edge of
                   dirty rectangle, if set (else will be -1).
      @return  true if dirty rectangle exists and is valid, false if no
               rectangle has been set (e.g. immediately after update()).
    */
    bool            getDirtyRect(int16_t *x1, int16_t *y1,
                                 int16_t *x2, int16_t *y2);
    /*!
      @brief   Lowest-level pixel-setting operation.  Sets color of pixel
               at a given coordinate.  Does NOT provide clipping, and pixel
               color must already be endian-adjusted if needed to match
               format needed by ILI9341 (MSB first).  Dirty rectangle is
               not updated.
      @param   x      Horizontal position of pixel (0 to TFTWIDTH-1).
      @param   y      Vertical position of pixel (0 to TFTHEIGHT-1).
      @param   color  16-bit (5/6/5 R/G/B) color value, ILI9341 byte order.
    */
    inline void     rawPixel(int16_t x, int16_t y, uint16_t color);
    /*!
      @brief   Set pixel in framebuffer, with clipping, endian-adjustment
                and dirty rectangle update.
      @param   x      Horizontal position of pixel.
      @param   y      Vertical position of pixel.
      @param   color  16-bit (5/6/5 R/G/B) color value, native byte order.
    */
    void            drawPixel(int16_t x, int16_t y, uint16_t color);
    /*!
      @brief   Fill rectangle in framebuffer, with clipping and dirty
               rectangle update.
      @param   x      Left edge of rectangle (right edge if negative width).
      @param   y      Top edge of rectangle (bottom edge if negative height).
      @param   w      Width in pixels.
      @param   h      Height in pixels.
      @param   color  16-bit (5/6/5 R/G/B) color value, native byte order.
    */
    void            fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
                             uint16_t color);
    /*!
      @brief   Fill entire framebuffer with solid color.
      @param   color  16-bit (5/6/5 R/G/B) color value, native byte order.
    */
    void            fillScreen(uint16_t color=0);

    void setRotation(byte rotation);
  private:
    DmacDescriptor *dptr; // Initial allocated DMA descriptor
    DmacDescriptor  descriptor[TFTHEIGHT] __attribute__((aligned(16)));
    uint16_t        framebuf[TFTWIDTH * TFTHEIGHT];
    int16_t         minx, miny, maxx, maxy; // Dirty rect
	
};


//--------------------------------------------------------------------------
/*! 
  @brief  Subclass of Adafruit_TFTDMA that does not provide a contiguous
          framebuffer.  Instead, application provides a buffer for graphics
          operations, which are divided into segments and redrawn as needed.
          Uses less RAM that TFT_framebuffer -- only as much as one wants to
          allocate to it (minimum of TFTWIDTH*2 16-bit pixels, or 1,280
          bytes, up to a maximum of 65,535 bytes).  Invokes a user callback
          to draw graphics into this buffer before issuing to the screen.
          There is no permanent framebuffer; graphics are disposed after
          each update, and dirty rectangle handling is the application;s
          responsibility (or update the full screen or sections as needed).
*/
class TFT_segmented : public Adafruit_TFTDMA {
  public:
    /*!
      @brief  Constructor.  Takes note of the hardware configuration to use,
              but does not itself initialize any hardware yet.
      @param  tc      Index of timer/counter peripheral for PWM (used for
                      generating write-strobe pulses), e.g. pass 2 to use
                      the TC2 peripheral.  Certain timer/counters may be
                      in use by other libraries or reserved for the Arduino
                      millis()/micros() timers.
      @param  reset   Index of pin connected to the ILI9341's reset line, or
                      -1 if unconnected.  Using the reset line is optional
                      but strongly recommended.
      @param  cs      Index of pin connected to ILI9341 chip select line.
                      Required; must be >= 0.
      @param  cd      Index of pin connected to ILI9341 command/data line.
                      Required; must be >= 0.
      @param  rd      Index of pin connected to ILI9341 read-strobe line, or
                      -1 if unconnected.  This library currently doesn't
                      read any registers or pixel data from the device; it
                      is coded specifically for this driver and write-only,
                      so -1 is totally acceptable and even preferred here.
                      Maybe this parameter will be removed in the future.
      @param  wr      Index of pin connected to ILI9341 write-strobe line.
                      Required; must be >= 0.  Additionally, this pin must
                      be a valid TCx/WO[0] output for the timer/counter
                      specified by the first parameter, OR a CCL/OUT[x] pin
                      for the same timer counter (see last parameter).
      @param  d0      Index of pin connected to ILI9341 data bit 0 line.
                      Required; must be >= 0.  Additionally, the
                      corresponding PORT bit index for this pin MUST be the
                      least-significant bit of an 8-bit byte (e.g. 0, 8, 16
                      or 24) if using the 8-bit parallel interface, or the
                      least-significant bit of a 16-bit halfword (e.g. 0 or
                      16) if using the 16-bit parallel interface.  Use of
                      the next 7 or 15 bits of the PORT is implied, the pins
                      corresponding to those bits might not be contiguous or
                      sequential; refer to the schematic or device-specific
                      variant.cpp file for insights.
      @param  periph  Peripheral type connected to the write-strobe pin for
                      PWM out.  This can be PIO_TIMER or PIO_TIMER_ALT
                      corresponding to TCx/WO[0] for that pin, or PIO_CCL
                      for CCL/OUT[x] on a pin.  PIO_TIMER and PIO_TIMER_ALT
                      require the use of an external logic inverter (the
                      ILI9341 uses active-low control signals).  PIO_CCL
                      does not need an inverter, but the choice of pins is
                      very limited, perhaps just one or two.
    */
    TFT_segmented(int8_t tc, int8_t reset, int8_t cs, int8_t cd, int8_t rd,
                  int8_t wr, int8_t d0, _EPioType periph);
    /*!
      @brief   Initializes all pins and peripherals used by the library.
      @return  true if an error occurred, false otherwise.  An error
               returned here is usually symptomatic of a constructor
               problem, such as an invalid pin or timer number.
    */
    bool            begin(void);
    /*!
      @brief   Refreshes specified region of the display, using a given
               buffer as working space.  The region will be divided
               vertically into a number of segments, the fewest needed to
               fit into the buffer, and a callback is then invoked to draw
               each segment as needed (segment contents are not preserved;
               every invocation must fully render that segment) and a DMA
               transfer is initiated while then processing the next segment.
               Function returns when last segment transfer is started --
               application can proceed with other code at that point but
               MUST not modify the segment buffer as it's transferred.
               Segment buffer size, specified in bytes, must be a minimum of
               two full scanlines (1,280 bytes), but larger is generally
               better, as RAM allows (e.g. 16 scanlines x 2).  One half of
               the segment buffer is drawn (via callback) while the other
               half is being transferred, swapping each time until the
               entire region is complete.
      @param   x1              Left edge of region to update.
      @param   y1              Top edge of region to update.
      @param   x2              Right edge of region to update.
      @param   y2              Bottom edge of region to update.
      @param   buf             Segment buffer, minimum 1,280 bytes,
                               16 X this or more is recommended, up to a
                               maximum of 65,535 bytes.
      @param   maxSegmentSize  Size of ONE HALF of the segment buffer,
                               e.g. the amount of data that will be rendered
                               or transferred in each segment -- there are
                               two segments being worked with here.
      @param   userCallback    Function for rendering one segment of the
                               region being updated.  Callback is passed a
                               pointer to a segment buffer, the height of
                               the region being updated (in scanlines),
                               and a pointer to optional user data provided
                               by the application.  Callback should return
                               the number of actual scanlines rendered
                               (between 1 and the number of lines passed in,
                               which allows for subsequent calls to be
                               aligned to specific boundaries if needed).
      @param   userData        Pointer to user-defined data structure which
                               can be used to pass data to the callback or
                               between invocations of the callback.  Very
                               little is passed to the callback -- this is
                               by design -- so this structure, or just
                               global variables in one's code, can be used
                               to contain information such as the region
                               width or horizontal/vertical offsets of the
                               segment within the overall screen.  Segments
                               are always processed in-order from top to
                               bottom, so simple incremental counters may be
                               adequate for many situations.
    */
    void            update(int16_t x1, int16_t y1, int16_t x2, int16_t y2,
                           uint16_t *buf, uint16_t maxSegmentSize,
                           int16_t (*userCallback)(uint16_t *dest,
                                                   uint16_t len,
                                                   void *udPtr),
                                                   void *userData);
    /*!
      @brief   Wait for the last DMA transfer initiated by update() to
               complete.  Segment buffer can then be modified by another
               region update.
    */
    void            waitForUpdate(void);
    /*!
      @brief   Lowest-level pixel-setting operation.  Sets color of pixel
               at a given coordinate in the current segment buffer.  Does
               NOT provide clipping, and pixel color must already be
               endian-adjusted if needed to match format needed by ILI9341
               (MSB first).
      @param   x      Horizontal position of pixel (0 to buffer width-1)
      @param   y      Vertical position of pixel (0 to buffer height-1).
      @param   color  16-bit (5/6/5 R/G/B) color value, ILI9341 byte order.
    */
    inline void     rawPixel(int16_t x, int16_t y, uint16_t color);
    /*!
      @brief   Set pixel in segment buffer, with clipping, compensating for
               the offset of the buffer relative to the screen.
      @param   x      Horizontal position of pixel.
      @param   y      Vertical position of pixel.
      @param   color  16-bit (5/6/5 R/G/B) color value, native byte order.
    */
    void            drawPixel(int16_t x, int16_t y, uint16_t color);
    /*!
      @brief   Fill rectangle in segment buffer, with clipping, compensating
               the offset of the buffer relative to the screen.
      @param   x      Left edge of rectangle (right edge if negative width).
      @param   y      Top edge of rectangle (bottom edge if negative height).
      @param   w      Width in pixels.
      @param   h      Height in pixels.
      @param   color  16-bit (5/6/5 R/G/B) color value, native byte order.
    */
    void            fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
                             uint16_t color);
    /*!
      @brief   Fill entire segment buffer with solid color.
      @param   color  16-bit (5/6/5 R/G/B) color value, native byte order.
    */
    void            fillScreen(uint16_t color=0);
  private:
    DmacDescriptor *descriptor;
    uint16_t       *framebuf;
    int16_t         xoffset, yoffset, width, height;
};


//--------------------------------------------------------------------------
/*! 
  @brief  Subclass of Adafruit_TFTDMA in which display (or section thereof)
          is generated one scanline at a time, using a callback which sets
          up one or more sequential 'spans,' providing a start address for
          each and a width in pixels.  The total span width MUST match the
          update region width.  This requires careful planning but might be
          good for scrollers, tile engines, anything with lots of canned
          pixel data in tables.  Uses about 12K RAM.
*/
class TFT_scanline : public Adafruit_TFTDMA {
  public:
    /*!
      @brief  Constructor.  Takes note of the hardware configuration to use,
              but does not itself initialize any hardware yet.
      @param  tc      Index of timer/counter peripheral for PWM (used for
                      generating write-strobe pulses), e.g. pass 2 to use
                      the TC2 peripheral.  Certain timer/counters may be
                      in use by other libraries or reserved for the Arduino
                      millis()/micros() timers.
      @param  reset   Index of pin connected to the ILI9341's reset line, or
                      -1 if unconnected.  Using the reset line is optional
                      but strongly recommended.
      @param  cs      Index of pin connected to ILI9341 chip select line.
                      Required; must be >= 0.
      @param  cd      Index of pin connected to ILI9341 command/data line.
                      Required; must be >= 0.
      @param  rd      Index of pin connected to ILI9341 read-strobe line, or
                      -1 if unconnected.  This library currently doesn't
                      read any registers or pixel data from the device; it
                      is coded specifically for this driver and write-only,
                      so -1 is totally acceptable and even preferred here.
                      Maybe this parameter will be removed in the future.
      @param  wr      Index of pin connected to ILI9341 write-strobe line.
                      Required; must be >= 0.  Additionally, this pin must
                      be a valid TCx/WO[0] output for the timer/counter
                      specified by the first parameter, OR a CCL/OUT[x] pin
                      for the same timer counter (see last parameter).
      @param  d0      Index of pin connected to ILI9341 data bit 0 line.
                      Required; must be >= 0.  Additionally, the
                      corresponding PORT bit index for this pin MUST be the
                      least-significant bit of an 8-bit byte (e.g. 0, 8, 16
                      or 24) if using the 8-bit parallel interface, or the
                      least-significant bit of a 16-bit halfword (e.g. 0 or
                      16) if using the 16-bit parallel interface.  Use of
                      the next 7 or 15 bits of the PORT is implied, the pins
                      corresponding to those bits might not be contiguous or
                      sequential; refer to the schematic or device-specific
                      variant.cpp file for insights.
      @param  periph  Peripheral type connected to the write-strobe pin for
                      PWM out.  This can be PIO_TIMER or PIO_TIMER_ALT
                      corresponding to TCx/WO[0] for that pin, or PIO_CCL
                      for CCL/OUT[x] on a pin.  PIO_TIMER and PIO_TIMER_ALT
                      require the use of an external logic inverter (the
                      ILI9341 uses active-low control signals).  PIO_CCL
                      does not need an inverter, but the choice of pins is
                      very limited, perhaps just one or two.
    */
    TFT_scanline(int8_t tc, int8_t reset, int8_t cs, int8_t cd, int8_t rd,
                 int8_t wr, int8_t d0, _EPioType periph);
    /*!
      @brief   Initializes all pins and peripherals used by the library.
      @return  true if an error occurred, false otherwise.  An error
               returned here is usually symptomatic of a constructor
               problem, such as an invalid pin or timer number.
    */
    bool            begin(void);
    /*!
      @brief   Refreshes specified region of the display.  Region will be
               divided vertically into scanlines, and a callback is then
               invoked to draw each line as needed (line contents are not
               preserved; every invocation must fully render that line) and
               a DMA transfer is initiated while then processing the next
               line.  Function returns when last DMA transfer completes.
      @param   x1            Left edge of region to update.
      @param   y1            Top edge of region to update.
      @param   x2            Right edge of region to update.
      @param   y2            Bottom edge of region to update.
      @param   userCallback  Function for rendering one scanline of the
                             region being updated.  Callback is passed a
                             pointer to a one-scanline working buffer if
                             needed, and a pointer to optional user data
                             provided by the application.
      @param   userData      Pointer to user-defined data structure which can
                             be used to pass data to the callback or between
                             invocations of the callback.  Very little is
                             passed to the callback -- this is by design --
                             so this structure, or just global variables in
                             one's code, can be used to contain information
                             such as the region width or horizontal/vertical
                             offsets of the scanline within the overall
                             screen.
    */
    void            update(int16_t x1, int16_t y1, int16_t x2, int16_t y2,
                           void (*userCallback)(uint16_t *dest, void *udPtr),
                           void *userData);
    /*!
      @brief   User callback invokes this function one or more times to
               specify the next 'span' -- a horizontal length of pixels --
               to issue along the scanline being rendered, left to right.
      @param   addr Pointer to 16-bit pixel data at the start of the span.
      @param   w    Horizontal length of span, in pixels.  The total length
                    of all spans on a given scanline MUST match the width of
                    the region passed to update(); no clipping is performed.
                    Spans are always added sequentially left-to-right, there
                    is no insert or reverse operation; speed is of the
                    essence.  The internal span counter is always reset to 0
                    (left edge of region) at the start of each scanline.
      @param   inc  Selects whether source address increment is enabled in
                    DMA transfer descriptor.  Default is 1 (true).  If 0,
                    and if using the 16-bit parallel interface, this will
                    fill the span with the single color value at 'addr'
                    (in 8-bit mode, this only makes sense if the color's
                    high and low bytes are the same, e.g. black, white and
                    a dubious and strange assortment of colors).
    */
    void            addSpan(uint16_t *addr, int16_t w, bool inc=1);
  private:
    uint8_t         lineIdx;
    uint16_t        spanIdx;
    DmacDescriptor *dptr; // Initial allocated DMA descriptor
    struct scanline {
      DmacDescriptor descriptor[TFTWIDTH] __attribute__((aligned(16)));
      uint16_t       linebuf[TFTWIDTH];
    } scanline[2];
};

#endif // _ADAFRUIT_TFTDMA_H_
