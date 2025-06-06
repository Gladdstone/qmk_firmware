/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "quantum.h"

// clang-format off
#ifdef RGB_MATRIX_ENABLE

#define AZEM_ORANGE 0xf7, 0x7a, 0x2a

const ckled2001_led g_ckled2001_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, I_1,    G_1,    H_1},
    {0, G_2,    H_2,    I_2},
    {0, H_3,    I_3,    G_3},
    {0, I_4,    G_4,    H_4},
    {0, G_5,    H_5,    I_5},
    {0, H_6,    I_6,    G_6},
    {0, I_7,    G_7,    H_7},
    {0, G_8,    H_8,    I_8},
    {0, H_9,    I_9,    G_9},
    {0, I_10,   G_10,   H_10},
    {0, G_11,   H_11,   I_11},
    {0, H_12,   I_12,   G_12},
    {0, I_13,   G_13,   H_13},
    {0, H_15,   I_15,   G_15},
    {0, I_16,   G_16,   H_16},
    {1, A_2,    B_2,    C_2,},

    {0, C_1,    A_1,    B_1},
    {0, A_2,    B_2,    C_2},
    {0, B_3,    C_3,    A_3},
    {0, C_4,    A_4,    B_4},
    {0, A_5,    B_5,    C_5},
    {0, B_6,    C_6,    A_6},
    {0, C_7,    A_7,    B_7},
    {0, A_8,    B_8,    C_8},
    {0, B_9,    C_9,    A_9},
    {0, C_10,   A_10,   B_10},
    {0, A_11,   B_11,   C_11},
    {0, B_12,   C_12,   A_12},
    {0, C_13,   A_13,   B_13},
    {0, A_14,   B_14,   C_14},
    {0, B_15,   C_15,   A_15},
    {0, C_16,   A_16,   B_16},
    {1, G_2,    H_2,    I_2},

    {0, F_1,    D_1,    E_1},
    {0, D_2,    E_2,    F_2},
    {0, E_3,    F_3,    D_3},
    {0, F_4,    D_4,    E_4},
    {0, D_5,    E_5,    F_5},
    {0, E_6,    F_6,    D_6},
    {0, F_7,    D_7,    E_7},
    {0, D_8,    E_8,    F_8},
    {0, E_9,    F_9,    D_9},
    {0, F_10,   D_10,   E_10},
    {0, D_11,   E_11,   F_11},
    {0, E_12,   F_12,   D_12},
    {0, F_13,   D_13,   E_13},
    {0, D_14,   E_14,   F_14},
    {0, E_15,   F_15,   D_15},
    {0, F_16,   D_16,   E_16},
    {1, A_1,    B_1,    C_1},

    {1, C_16,   A_16,   B_16},
    {1, A_15,   B_15,   C_15},
    {1, B_14,   C_14,   A_14},
    {1, C_13,   A_13,   B_13},
    {1, A_12,   B_12,   C_12},
    {1, B_11,   C_11,   A_11},
    {1, C_10,   A_10,   B_10},
    {1, A_9,    B_9,    C_9},
    {1, B_8,    C_8,    A_8},
    {1, C_7,    A_7,    B_7},
    {1, A_6,    B_6,    C_6},
    {1, B_5,    C_5,    A_5},
    {1, A_3,    B_3,    C_3},

    {1, I_16,   G_16,   H_16},
    {1, H_14,   I_14,   G_14},
    {1, I_13,   G_13,   H_13},
    {1, G_12,   H_12,   I_12},
    {1, H_11,   I_11,   G_11},
    {1, I_10,   G_10,   H_10},
    {1, G_9,    H_9,    I_9},
    {1, H_8,    I_8,    G_8},
    {1, I_7,    G_7,    H_7},
    {1, G_6,    H_6,    I_6},
    {1, H_5,    I_5,    G_5},
    {1, G_3,    H_3,    I_3},
    {1, I_1,    G_1,    H_1},

    {1, F_16,   D_16,   E_16},
    {1, D_15,   E_15,   F_15},
    {1, E_14,   F_14,   D_14},
    {1, F_10,   D_10,   E_10},
    {1, D_6,    E_6,    F_6},
    {1, E_5,    F_5,    D_5},
    {1, F_4,    D_4,    E_4},
    {1, D_3,    E_3,    F_3},
    {1, E_2,    F_2,    D_2},
    {1, F_1,    D_1,    E_1},
    {1, A_4,    B_4,    C_4}
};

// see quantum/rgb_matrix/rgb_matrix_types.h for struct definition
led_config_t g_led_config = {
	{
		{  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     NO_LED, 13,     14,     15 },
		{  16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29,     30,     31,     32 },
		{  33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     44,     45,     46,     47,     48,     49 },
		{  50,     51,     52,     53,     54,     55,     56,     57,     58,     59,     60,     61,     NO_LED, 62,     NO_LED, NO_LED, NO_LED },
		{  63,     NO_LED, 64,     65,     66,     67,     68,     69,     70,     71,     72,     73,     NO_LED, 74,     NO_LED, 75,     NO_LED },
		{  76,     77,     78,     NO_LED, NO_LED, NO_LED, 79,     NO_LED, NO_LED, NO_LED, 80,     81,     82,     83,     84,     85,     86}
	},
	{
        {0, 0},          {25, 0}, {38, 0}, {51, 0}, {64, 0}, {84, 0}, { 97, 0}, {110, 0}, {123, 0}, {142, 0}, {155, 0}, {168, 0}, {181, 0}, {198, 0}, {211, 0}, {224, 0},
        {0,14}, {12,14}, {25,14}, {38,14}, {51,14}, {64,14}, {77,14}, { 90,14}, {103,14}, {116,14}, {129,14}, {142,14}, {155,14}, {175,14}, {198,14}, {211,14}, {224,14},
        {3,26}, {19,26}, {32,26}, {45,26}, {58,26}, {71,26}, {84,26}, { 97,26}, {110,26}, {123,26}, {136,26}, {149,26}, {162,26}, {178,26}, {198,26}, {211,26}, {224,26},
        {4,39}, {22,39}, {35,39}, {48,39}, {61,39}, {74,39}, {87,39}, {100,39}, {113,39}, {126,39}, {139,39}, {152,39},           {173,39},
        {8,51}, {29,51}, {42,51}, {55,51}, {68,51}, {81,51}, {94,51}, {107,51}, {120,51}, {132,51}, {145,51},                     {170,51},           {211,51},
        {1,64}, {17,64}, {34,64},                            {82,64},                               {131,64}, {147,64}, {163,64}, {180,64}, {198,64}, {211,64}, {224,64}
    },
	{
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,          4,    4,    4,
        4,    8,    8,    8,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,          4,
        4,          4,    4,    4,    4,    4,    4,    4,    4,    4,    4,          4,          4,
        4,    4,    4,                      4,                      4,    4,    4,    4,    4,    4,    4
	}
};

/**
 * handles per-key/LED lighting effects in addition to the active animation. Called
 * every time the RGB Matrix is refreshed.
 *
 * @param led_min led updated (min)
 * @param led_max led updated (max)
 * @return bool
 */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    /* uint8_t layer = get_highest_layer(layer_state); */
    /* uprintf("layer: %u\n", layer); */

    // if (layer == MAC_FN) {
    //     rgb_matrix_set_color_all(RGB_GREEN);
    // } else {
    //     rgb_matrix_set_color_all(RGB_BLUE);
    // }

    rgb_matrix_set_color_all(RGB_WHITE);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for(uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if(index != NO_LED && rgb_matrix_get_mode() == RGB_MATRIX_SOLID_COLOR) {
                keypos_t key = { .row = row, .col = col };
                uint16_t keycode = keymap_key_to_keycode(layer_state, key);

                if(keycode == KC_LEFT) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }

                // debugging note:
                // check to see if it isn't still resolving
                // keymappings against the MAC_BASE layer
                switch(keycode) {
                    /* case KC_BRID: */
                    /*     rgb_matrix_set_color(index, RGB_GREEN); */
                    /*     break; */
                    case KC_F1:
                        rgb_matrix_set_color(index, RGB_GREEN);
                        break;
                    case KC_BRIU:
                        rgb_matrix_set_color(index, RGB_BLUE);
                        break;
                    case KC_F2:
                        rgb_matrix_set_color(index, RGB_BLUE);
                        break;
                    case KC_MCTL:
                        rgb_matrix_set_color(index, RGB_BLUE);
                        break;
                    case KC_F3:
                        rgb_matrix_set_color(index, RGB_BLUE);
                        break;
                    case KC_LPAD:
                        rgb_matrix_set_color(index, RGB_GREEN);
                        break;
                    case KC_F4:
                        rgb_matrix_set_color(index, RGB_GREEN);
                        break;
                    case RGB_VAD:
                        rgb_matrix_set_color(index, RGB_RED);
                        break;
                    case KC_F5:
                        rgb_matrix_set_color(index, RGB_RED);
                        break;
                    case RGB_VAI:
                        rgb_matrix_set_color(index, RGB_RED);
                        break;
                    case KC_F6:
                        rgb_matrix_set_color(index, RGB_RED);
                        break;
                    case KC_MPRV:
                        rgb_matrix_set_color(index, RGB_RED);
                        break;
                    case KC_F7:
                        rgb_matrix_set_color(index, RGB_RED);
                        break;
                    case KC_MPLY:
                        rgb_matrix_set_color(index, RGB_RED);
                        break;
                    case KC_F8:
                        rgb_matrix_set_color(index, RGB_RED);
                    case KC_UP:
                        rgb_matrix_set_color(index, AZEM_ORANGE);
                        break;
                    case KC_DOWN:
                        rgb_matrix_set_color(index, AZEM_ORANGE);
                        break;
                    case KC_LEFT:
                        rgb_matrix_set_color(index, AZEM_ORANGE);
                        break;
                    case KC_RIGHT:
                        rgb_matrix_set_color(index, AZEM_ORANGE);
                        break;
                    case KC_W:
                        rgb_matrix_set_color(index, AZEM_ORANGE);
                        break;
                    case KC_A:
                        rgb_matrix_set_color(index, AZEM_ORANGE);
                        break;
                    case KC_S:
                        rgb_matrix_set_color(index, AZEM_ORANGE);
                        break;
                    case KC_D:
                        rgb_matrix_set_color(index, AZEM_ORANGE);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color_all(0x8b, 0x00, 0x00);  // RGB dark red --- capslock color
    }

    return true;
}

#endif
