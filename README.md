Ejemplo: Uso de teclado matricial.

En este ejemplo, se muestra cómo configurar, conectar y hacer funcionar un teclado matricial con el ESP32. En la documentación se detalla la distribución de los pines y las conexiones. Te recomiendo revisarla para asegurarte de tener la información correcta.

## Files:

```c  
 matriz_keyboard.c
 matriz_keyboard.h
```



## GPIO Pins connected:

![img](./imgs/matriz_keypad.png)


```c  

// columns are inputs

#define COL_1  GPIO_NUM_25
#define COL_2  GPIO_NUM_26
#define COL_3  GPIO_NUM_27
#define COL_4  GPIO_NUM_14

//rows are output

#define NUM_ROW  4
#define ROW_1    GPIO_NUM_18
#define ROW_2    GPIO_NUM_5
#define ROW_3    GPIO_NUM_17
#define ROW_4    GPIO_NUM_16

```



## ESP32 PINOUT
<p align="left">
  <img src="./imgs/esp32_pinout.jpg" width="480" height="320" >
</p>





## Keypad functions:

 

```c  

/**
 * @brief Init the keyboard
 * 
 */
void keyboard_init();


/**
 * @brief Get the last keyboard, you need to
 *  get 1 in keyboard_check() before to get a valid char 
 * 
 * @return char return the last_char
 */
char keyboard_get_char();


/**
 * @brief Check the keyboard. 
 * if its pressed any key,save the char.
 * 
 * @return int  its 1 if key pressed or 0 if not
 */
int keyboard_check();

```