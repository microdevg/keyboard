/*
 * matriz_keyboard.h
 *
 *  Created on: 17 de Abril 2024
 *      Author: German Velardez
 *      Email: germanvelardez16@gmail.com
 */



#include <stdio.h>
#include <string.h>
#include <freertos/FreeRTOS.h>
//#include "keyboard.h"
#include "keypad.h"





#define KEY_FOR_CLEAN_DISPLAY			'#'
#define LEN_BUFFER						10
#define DELAY_FOR_PRESSED_KEY			500


uint8_t buffer[LEN_BUFFER]={0};
int len = 0;





static void add_key(char key){
	if (len >= LEN_BUFFER - 1) {
		memset(buffer,0,LEN_BUFFER);
		len = 0;} 
	buffer[len]=key;
	len++;
}




void app_main(void)
{
	keypad_init();
	for(;;){
		vTaskDelay(200/portTICK_PERIOD_MS);
	}

}