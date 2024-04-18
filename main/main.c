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
#include "keyboard.h"






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
	keyboard_init();
	int check = 0;
	for (;;) {
			check = keyboard_check();
			if(check){
				char key = keyboard_get_char();
				check = 0;
				if(key == KEY_FOR_CLEAN_DISPLAY){
					printf("clean display\n");
					memset(buffer,0,LEN_BUFFER);
					len = 0;}
				else{
				add_key(key);
				printf("%s\n",buffer);}
				vTaskDelay(DELAY_FOR_PRESSED_KEY / portTICK_PERIOD_MS);	
			}
			vTaskDelay(50 / portTICK_PERIOD_MS);	
	}

}