#ifndef LCD_H
#define LCD_H

/**
 * @file lcd.h
 * @brief Functions related to the LCD screen
 */

/* Opcode definitions for LCD_cmd - pg.24 of the datasheet          */

/** Entry mode set                                      */
#define ENTRY_MODE_SET          0x04
#define INCREMENT               0x02
#define DECREMENT               0x00
#define SHIFT_DISPLAY           0x01

/** Display on/off control                              */
#define DISPLAY_SET             0x08
#define DISPLAY_ON              0x04
#define CURSOR_ON               0x02
#define CURSOR_BLINK_ON         0x01

/** Cursor or display shift                             */
#define SHIFT                   0x10
#define DISPLAY                 0x08
#define CURSOR                  0x00
#define RIGHT                   0x04
#define LEFT                    0x00

/**
 * @brief The colours available on the LCD
 */
typedef enum {
    Black,
    Red,
    Yellow,
    Green,
    Cyan,
    Blue,
    Magenta,
    White
} Colour;

/** display shift record */
extern int LCD_DISPLAY_SHIFT;

/**
 * @brief Initialise the LCD screen
 * @return 0, on success
 */
int LCD_init();

/**
 * @brief Send a command to the LCD screen.
 * @details
 * - for a list of available commands, please refer to the definition list
 * above.
 * - for examples, please refer to LCD_init
 * - for more details, please refer to pg. 24 of the datasheet
 * @return 0, on success
 */
int LCD_cmd(uint8_t cmd);

/**
 * @brief Send a character to the LCD screen.
 * @return
 * - 0, on success
 * - -1 when LCD has not been initialised
 */
int LCD_putchar (char c);


/**
 * @brief change LCD colour
 * @return 0, on success
 */
int LCD_colour(Colour colour);

/**
 * @brief clear the LCD
 * @details the cursor will be moved to the starting position.
 * @return 0, on success
 */
int LCD_clear();

/**
 * @brief move the cursor on LCD to the starting position
 * @return 0, on success
 */
int LCD_home();

/**
 * @brief return LCD current cursor address
 * @note the side effect includes saving the current DDRAM address to a static
 * variable.
 */
uint8_t LCD_cursor_addr();

/**
 * @brief clear the current line on LCD
 * @return 0, on success
 */
int LCD_line_clear();

/**
 * @brief printf for the LCD
 * @return the number of characters printed
 * @note maximum string length: 80 characters, which is the size of the DDRAM
 */
int LCD_printf(const char *format, ...);

/**
 * @brief printf with automatic line wrap
 * @details This version of printf will clear the display, and print a
 * formatted string, and automatically wrap the string when it reaches the end
 * of the first line
 * @return the number of characters printed
 * @note maxium string length: 32 characters, which is all the characters on
 * the LCD.
 */
int LCD_wrap_printf(const char *format, ...);


/**
 * @brief move the LCD cursor by n characters
 * @return the resulting cursor address.
 */
int LCD_cursor_move(int n);

/**
 * @brief shift the content that is being displayed by LCD
 * @return the current display shift
 */
int LCD_display_shift(int n);

/* Temporarily included */
uint8_t read_byte(int RS);
int write_byte(uint8_t data, int RS);

#endif