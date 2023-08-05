# AHT20 Temperature and Humidity sensor Library
#### suitable for stm32 / based on HAL functions
This Library is free, that all student and users can use it and develop their programs, the program is developed for STM32 micros and based on HAL functions, tested on STM32F1xx series.
This library helps you to initilize AHT20 sensor and measure Temperature and humidity using I2C protocol based on HAL functions on STM32 microcontrollers.

#### How to use
------------
**1:** before "while" loop Initialize Sensor using AHT20_Init(*hi2c).

**2:** use AHT20_Measure() function to sensor start measuring and transmit and receive data.

**3:** after measuring use AHT20_Temp() or AHT20_Humid() to get Temperature & Humidity these functions will return a float value.
   - for Temperature it returns a number between -50 to 90 C (Celsius)
   - for Humidity it returns a number between 0 to 100 %  (Percent)

**4:** you can use AHT20_SoftReset() to reset sensor but it's NOT necessary. we recommend that use this function where happens a bug for measuring.
   - every time you want to know temperature changes you must use AHT20_Measure() again.
   - and then use AHT20_Temp() or AHT20_Humid() again and get new values after reseting sensor you must Initialize Sensor again (using AHT20_Init(*hi2c)).

#### simple example
------------
This is a figure of how you should use functions in C to develope your code.
``` C
    #include "main.h"  
    double T,H;
     int main(){
        sys_init();
        AHT20_Init(&hi2c1);
        while(1){
               AHT20_Measure();
               T=AHT20_Temp();
               H=AHT20_Humid();
               delay(1000);
         }
    }
```

