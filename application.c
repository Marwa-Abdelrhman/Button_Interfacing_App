/* 
 * File:   application.c
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 12:53 AM
 */


#include"application.h"



led_t led_0={.port_name=PORTC_INDEX,.pin=GPIO_PIN0,.led_state=GPIO_STATE_LOW};
led_t led_1={.port_name=PORTC_INDEX,.pin=GPIO_PIN1,.led_state=GPIO_STATE_LOW};

button_t btn_0={.btn_pin.port=PORTD_INDEX,
                .btn_pin.pin=GPIO_PIN0,
                .btn_pin.direction=GPIO_DIRECTION_INPUT,
                .btn_pin.state=GPIO_STATE_LOW,
                .btn_connection_typ=BUTTON_ACTIVE_HIGH,
                .btn_state=BUTTON_RELEASED};
                
button_t btn_1={.btn_pin.port=PORTD_INDEX,
                .btn_pin.pin=GPIO_PIN1,
                .btn_pin.direction=GPIO_DIRECTION_INPUT,
                .btn_pin.state=GPIO_STATE_HIGH,
                .btn_connection_typ=BUTTON_ACTIVE_LOW,
                .btn_state=BUTTON_RELEASED};




Std_RetrunType ret=E_NOK;
button_state_t btn_high_state_0=BUTTON_RELEASED;
button_state_t btn_low_state_1=BUTTON_RELEASED;


int main() {
    app_init();
    while(1){


        ret=button_read_state(&btn_0,&btn_high_state_0);
        ret=button_read_state(&btn_1,&btn_low_state_1);

        if(btn_high_state_0 == BUTTON_PRESSED)
        {
            ret=led_on(&led_0);
        }
        else if(btn_high_state_0 == BUTTON_RELEASED)
        {
            ret=led_off(&led_0);
        }

        if(btn_low_state_1 == BUTTON_RELEASED)
        {
            ret=led_off(&led_1);
        }
        else if(btn_low_state_1 == BUTTON_PRESSED)
        {
            ret=led_on(&led_1);
        }

    }
        return (EXIT_SUCCESS);
}

void app_init(void){
  
    ret=led_init(&led_0);
    ret=led_init(&led_1);
    ret=button_init(&btn_0);
    ret=button_init(&btn_1);

    
}