/* 
 * File:   ecu_layer_init.h
 * Author: Abdallah Saad
 * Created on February 7, 2023, 10:39 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

#include "LED/ecu_led.h"
#include "7_Segment/ecu_seven_segment.h"
#include "Rleay/ecu_relay.h"
#include "DC_Motor/ecu_dc_motor.h"
#include "button/ecu_button.h"
#include "KeyPad/ecu_keypad.h"
#include "Chr_LCD/ecu_chr_lcd.h"



pin_config_t seg_pin_1 ={
    .port = PORTB_INDEX    , 
    .pin = GPIO_PIN0 , 
    .logic = GPIO_LOW , 
    .direction = GPIO_DIRECTION_OUTPUT ,
}  ; 

pin_config_t seg_pin_2 ={
    .port = PORTB_INDEX    , 
    .pin = GPIO_PIN1 , 
    .logic = GPIO_LOW , 
    .direction = GPIO_DIRECTION_OUTPUT ,
}  ; 

pin_config_t seg_pin_3 ={
    .port = PORTB_INDEX    , 
    .pin = GPIO_PIN2 , 
    .logic = GPIO_LOW , 
    .direction = GPIO_DIRECTION_OUTPUT ,
}  ; 

pin_config_t seg_pin_4 ={
    .port = PORTB_INDEX    , 
    .pin = GPIO_PIN3 , 
    .logic = GPIO_LOW , 
    .direction = GPIO_DIRECTION_OUTPUT ,
}  ; 
pin_config_t seg_pin_5 ={
    .port = PORTB_INDEX    , 
    .pin = GPIO_PIN4 , 
    .logic = GPIO_LOW , 
    .direction = GPIO_DIRECTION_OUTPUT ,
}  ; 

pin_config_t seg_pin_6 ={
    .port = PORTB_INDEX    , 
    .pin = GPIO_PIN5 , 
    .logic = GPIO_LOW , 
    .direction = GPIO_DIRECTION_OUTPUT ,
}  ; 



chr_lcd_4bit_t lcd_1 = {
    .lcd_rs.port = PORTE_INDEX,
    .lcd_rs.pin = GPIO_PIN0,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTE_INDEX,
    .lcd_en.pin = GPIO_PIN1,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port = PORTC_INDEX,
    .lcd_data[0].pin = GPIO_PIN4,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port = PORTC_INDEX,
    .lcd_data[1].pin = GPIO_PIN5,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port = PORTC_INDEX,
    .lcd_data[2].pin = GPIO_PIN6,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port = PORTC_INDEX,
    .lcd_data[3].pin = GPIO_PIN7,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
};

keypad_t keypad1 = {
    .keypad_row_pins[0].port = PORTD_INDEX,
    .keypad_row_pins[0].pin = GPIO_PIN0,
    .keypad_row_pins[0].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[0].logic = GPIO_LOW,
    .keypad_row_pins[1].port = PORTD_INDEX,
    .keypad_row_pins[1].pin = GPIO_PIN1,
    .keypad_row_pins[1].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[1].logic = GPIO_LOW,
    .keypad_row_pins[2].port = PORTD_INDEX,
    .keypad_row_pins[2].pin = GPIO_PIN2,
    .keypad_row_pins[2].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[2].logic = GPIO_LOW,
    .keypad_row_pins[3].port = PORTD_INDEX,
    .keypad_row_pins[3].pin = GPIO_PIN3,
    .keypad_row_pins[3].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[3].logic = GPIO_LOW,
    .keypad_columns_pins[0].port = PORTD_INDEX,
    .keypad_columns_pins[0].pin = GPIO_PIN4,
    .keypad_columns_pins[0].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[0].logic = GPIO_LOW,
    .keypad_columns_pins[1].port = PORTD_INDEX,
    .keypad_columns_pins[1].pin = GPIO_PIN5,
    .keypad_columns_pins[1].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[1].logic = GPIO_LOW,
    .keypad_columns_pins[2].port = PORTD_INDEX,
    .keypad_columns_pins[2].pin = GPIO_PIN6,
    .keypad_columns_pins[2].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[2].logic = GPIO_LOW,
    .keypad_columns_pins[3].port = PORTD_INDEX,
    .keypad_columns_pins[3].pin = GPIO_PIN7,
    .keypad_columns_pins[3].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[3].logic = GPIO_LOW,
};


segment_t segment_1 = {
    .segment_type = SEGMENT_COMMON_ANODE , 
    .segment_pins[0].direction = GPIO_DIRECTION_OUTPUT , 
    .segment_pins[0].logic = GPIO_LOW , 
    .segment_pins[0].pin = GPIO_PIN0 , 
    .segment_pins[0].port = PORTC_INDEX , 
    .segment_pins[1].direction = GPIO_DIRECTION_OUTPUT , 
    .segment_pins[1].logic = GPIO_LOW , 
    .segment_pins[1].pin = GPIO_PIN1 , 
    .segment_pins[1].port = PORTC_INDEX , 
    .segment_pins[2].direction = GPIO_DIRECTION_OUTPUT , 
    .segment_pins[2].logic = GPIO_LOW , 
    .segment_pins[2].pin = GPIO_PIN2 , 
    .segment_pins[2].port = PORTC_INDEX , 
    .segment_pins[3].direction = GPIO_DIRECTION_OUTPUT , 
    .segment_pins[3].logic = GPIO_LOW , 
    .segment_pins[3].pin = GPIO_PIN3 , 
    .segment_pins[3].port = PORTC_INDEX , 
} ; 

void ecu_layer_intialize(void);

#endif	/* ECU_LAYER_INIT_H */

