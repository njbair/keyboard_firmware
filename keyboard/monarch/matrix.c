/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"

#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // JTAG disable for PORT F. write JTD bit twice within four cycles.
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);

    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }

    // Enable underlighting
    #ifdef BACKLIGHT_ENABLE
    init_backlight_pin();
    #endif
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

/* Column pin configuration
 * col: 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
 * pin: F4 F1 F0 B0 B1 B2 B3 B7 D0 D1 D2 D3 D5 D4 D6 D7 B4 B5
 */
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRF  &= ~(1<<4 | 1<<1 | 1<<0);
    PORTF |=  (1<<4 | 1<<1 | 1<<0);
    DDRD  &= ~(1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    PORTD |=  (1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    DDRB  &= ~(1<<7 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    PORTB |=  (1<<7 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
}

static matrix_row_t read_cols(void)
{
    return (PINF&(1<<4) ? 0 : (1UL<<0)) |
           (PINF&(1<<1) ? 0 : (1UL<<1)) |
           (PINF&(1<<0) ? 0 : (1UL<<2)) |
           (PINB&(1<<0) ? 0 : (1UL<<3)) |
           (PINB&(1<<1) ? 0 : (1UL<<4)) |
           (PINB&(1<<2) ? 0 : (1UL<<5)) |
           (PINB&(1<<3) ? 0 : (1UL<<6)) |
           (PINB&(1<<7) ? 0 : (1UL<<7)) |
           (PIND&(1<<0) ? 0 : (1UL<<8)) |
           (PIND&(1<<1) ? 0 : (1UL<<9)) |
           (PIND&(1<<2) ? 0 : (1UL<<10)) |
           (PIND&(1<<3) ? 0 : (1UL<<11)) |
           (PIND&(1<<5) ? 0 : (1UL<<12)) |
           (PIND&(1<<4) ? 0 : (1UL<<13)) |
           (PIND&(1<<6) ? 0 : (1UL<<14)) |
           (PIND&(1<<7) ? 0 : (1UL<<15)) |
           (PINB&(1<<4) ? 0 : (1UL<<16)) |
           (PINB&(1<<5) ? 0 : (1UL<<17));
}

/* Row pin configuration
 * row: 0  1  2  3  4
 * pin: E6 F5 F6 F7 C7
 */
static void unselect_rows(void)
{
    // Hi-Z(DDR:0, PORT:0) to unselect
    DDRF  &= ~0b11100000;
    PORTF &= ~0b11100000;
    DDRE  &= ~0b01000000;
    PORTE &= ~0b01000000;
    DDRC  &= ~0b10000000;
    PORTC &= ~0b10000000;
}

static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
    switch (row) {
        case 0:
            DDRE  |= (1<<6);
            PORTE &= ~(1<<6);
            break;
        case 1:
            DDRF  |= (1<<5);
            PORTF &= ~(1<<5);
            break;
        case 2:
            DDRF  |= (1<<6);
            PORTF &= ~(1<<6);
            break;
        case 3:
            DDRF  |= (1<<7);
            PORTF &= ~(1<<7);
            break;
        case 4:
            DDRC  |= (1<<7);
            PORTC &= ~(1<<7);
            break;
    }
}
