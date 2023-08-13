/* 
 * File:   application.c
 * Author: Abdallah Saad
 * Created on November 28, 2023, 8:43 PM
 */

#include "application.h"


timer0_t timer0_counter_obj = {
    .TMR0_InterruptHandler = NULL ,
    .timer0_mode = TIMER0_COUNTER_MODE,
    .timer0_counter_edge = TIMER0_COUNTER_RISING_EDGE_CFG,
    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE,
    .prescaler_enable = TIMER0_PRESCALER_DISABLE_CFG,
    .timer0_preload_value = 0
};

uint16 Counter_Value  ,Seconds ,  Minutes , Hours ; 
uint8 key_value,value11 , value12 , value21 , value22  , value31 ,value32 , counter = 0;
int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    ret = Timer0_Init(&timer0_counter_obj) ; 
    ret = lcd_4bit_send_string_pos(&lcd_1 ,1 ,1 , "Press 1 to set") ; 
    ret = lcd_4bit_send_string_pos(&lcd_1 ,2 ,1 , "Press 0 to reset") ; 


    while(1){

 
        for(counter=0; counter<=50; counter++){
            ret= Timer0_Read_Value(&timer0_counter_obj , &Counter_Value) ; 
            if(60 == Counter_Value){
                ret = Timer0_Write_Value(&timer0_counter_obj , 0) ; 
                Minutes ++ ; 
                if(60 == Minutes){
                    Hours++ ; 
                    Minutes = 0 ; 
                    if(24 == Hours){
                        Hours = 0 ; 
                    }
                }
            }
            ret = seven_segement_write_number(&segment_1, (uint8)(Counter_Value%10));
            ret = gpio_pin_write_logic(&seg_pin_6, GPIO_HIGH);
            ret = keypad_get_value(&keypad1 , &key_value) ; 
            ret = gpio_pin_write_logic(&seg_pin_6, GPIO_LOW);
            ret = seven_segement_write_number(&segment_1, (uint8)(Counter_Value/10));
            ret = gpio_pin_write_logic(&seg_pin_5, GPIO_HIGH);
            __delay_ms(2) ;
            ret = gpio_pin_write_logic(&seg_pin_5, GPIO_LOW);
            
            ret = seven_segement_write_number(&segment_1, (uint8)(Minutes%10));
            ret = gpio_pin_write_logic(&seg_pin_4, GPIO_HIGH);
            __delay_ms(2) ;
            ret = gpio_pin_write_logic(&seg_pin_4, GPIO_LOW);
            ret = seven_segement_write_number(&segment_1, (uint8)(Minutes/10));
            ret = gpio_pin_write_logic(&seg_pin_3, GPIO_HIGH);
            __delay_ms(2) ;
            ret = gpio_pin_write_logic(&seg_pin_3, GPIO_LOW);
            
            ret = seven_segement_write_number(&segment_1, (uint8)(Hours%10));
            ret = gpio_pin_write_logic(&seg_pin_2, GPIO_HIGH);
            __delay_ms(2) ; 
            ret = gpio_pin_write_logic(&seg_pin_2, GPIO_LOW);
            ret = seven_segement_write_number(&segment_1, (uint8)(Hours/10));
            ret = gpio_pin_write_logic(&seg_pin_1, GPIO_HIGH);
            __delay_ms(2) ; 
            ret = gpio_pin_write_logic(&seg_pin_1, GPIO_LOW);
            
            if('0' == key_value){
                ret = Timer0_Write_Value(&timer0_counter_obj , 0) ; 
                Minutes = 0 ; 
                Hours = 0 ; 
                key_value = '#' ; 
            }
            if('1' == key_value){

                ret = lcd_4bit_send_command(&lcd_1 , _LCD_CLEAR) ; 
                __delay_ms(200) ; 
                ret = lcd_4bit_send_string_pos(&lcd_1 ,1 ,1 , "Seconds: ") ;
                ret = keypad_get_value_blocking(&keypad1 , &value11) ; 
                ret =lcd_4bit_send_char_data_pos(&lcd_1 ,1 ,10,value11) ; 
                
                ret = keypad_get_value_blocking(&keypad1 , &value12) ; 
                ret =lcd_4bit_send_char_data_pos(&lcd_1 ,1 ,11,value12) ;
                __delay_ms(500) ; 
                
                ret = lcd_4bit_send_command(&lcd_1 , _LCD_CLEAR) ; 

                ret = lcd_4bit_send_string_pos(&lcd_1 ,1 ,1 , "Minutes: ") ;
                ret = keypad_get_value_blocking(&keypad1 , &value21) ; 
                ret =lcd_4bit_send_char_data_pos(&lcd_1 ,1 ,10,value21) ; 
                
                ret = keypad_get_value_blocking(&keypad1 , &value22) ; 
                ret =lcd_4bit_send_char_data_pos(&lcd_1 ,1 ,11,value22) ;
                __delay_ms(500) ; 
                
                ret = lcd_4bit_send_command(&lcd_1 , _LCD_CLEAR) ; 
                ret = lcd_4bit_send_string_pos(&lcd_1 ,1 ,1 , "Hours: ") ;
                ret = keypad_get_value_blocking(&keypad1 , &value31) ; 
                ret =lcd_4bit_send_char_data_pos(&lcd_1 ,1 ,8,value31) ; 
                
                ret = keypad_get_value_blocking(&keypad1 , &value32) ; 
                ret =lcd_4bit_send_char_data_pos(&lcd_1 ,1 ,9,value32) ;
                __delay_ms(500) ; 
                
                Seconds = (value11 -'0')*10 + (value12 - '0') ; 
                int mul_seconds = Seconds/60 ; 
                Seconds %= 60 ; 
                ret = Timer0_Write_Value(&timer0_counter_obj , Seconds) ;
                Minutes = (value21 -'0')*10 + (value22 - '0') ;
                int mul_minutes = Minutes/60 ; 
                Minutes = Minutes%60 +mul_seconds ; 
                Hours = (value31 -'0')*10 + (value32 - '0') ; 
                Hours = Hours%24 +mul_minutes ; 
                
                ret = lcd_4bit_send_command(&lcd_1 , _LCD_CLEAR) ; 
                ret = lcd_4bit_send_string_pos(&lcd_1 ,1 ,1 , "Press 1 to set") ; 
                ret = lcd_4bit_send_string_pos(&lcd_1 ,2 ,1 , "Press 0 to reset") ; 
                key_value = '#' ; 
                
                
            }

        }


    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize() ; 
    
}




