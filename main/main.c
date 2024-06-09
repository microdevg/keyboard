/*
 * matriz_keyboard.h
 *
 *  Created on: 17 de Abril 2024
 *      Author: German Velardez
 *      Email: germanvelardez16@gmail.com
 */



#include <stdio.h>

#include <freertos/FreeRTOS.h>
//#include "keyboard.h"
#include "keypad.h"








static void add_key(char key){
	// Averiguar porque con printf si no termino 
	// el string con \n no se imprime
	printf("%c\n",key);

}





static void callback_buffer(char*buffer){
	printf("\nsend: %s\n",buffer);

}

static void callback_clear(){
	printf("Callback clear\n");
}


void app_main(void)
{
	keypad_init( add_key,callback_buffer,callback_clear);
	for(;;){
		vTaskDelay(200/portTICK_PERIOD_MS);
	}

}