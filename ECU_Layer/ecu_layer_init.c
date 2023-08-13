
/* 
 * File:   ecu_layer_init.c
 * Author: Abdallah Saad
 * Created on February 7, 2021, 10:39 PM
 */

#include "ecu_layer_init.h"


void ecu_layer_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = keypad_initialize(&keypad1) ; 
    ret = lcd_4bit_intialize(&lcd_1) ; 
    ret = gpio_pin_intialize(&seg_pin_1) ; 
    ret = gpio_pin_intialize(&seg_pin_2) ; 
    ret = gpio_pin_intialize(&seg_pin_3) ; 
    ret = gpio_pin_intialize(&seg_pin_4) ; 
    ret = gpio_pin_intialize(&seg_pin_5) ; 
    ret = gpio_pin_intialize(&seg_pin_6) ; 
    ret = seven_segement_intialize(&segment_1) ; 

}