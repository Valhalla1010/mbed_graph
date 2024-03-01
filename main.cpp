#include "mbed.h"
#include "C12832.h"
#include <algorithm>
#include <cstdio>
#include "LM75B.h"
#include "main.h"
//LCD Screen, Task_3: Display graphs.
// this program is a temperature graph that display temperature graph on the LCD.
//when the temperature changes, the line goes up and down.

C12832 lcd(p5, p7, p6, p8, p11); //initialize the C12832 display
LM75B temp(p28, p27);

int main(){

    while(1){
        //vertical-axis
        lcd.line(22, 0, 22, 30, 1);
        //Horis-axis
        lcd.line(22, 28, 112, 28, 1);

        //ptint 50 C.
        lcd.locate(0, 0);
        lcd.printf("50");
        lcd.pixel(20, 0, 1);
        lcd.pixel(19, 0, 1);
        lcd.pixel(22, 0, 1);
        lcd.pixel(23, 0, 1);
        //print 25 C.
        lcd.locate(0, 22);
        lcd.printf("25");
        lcd.pixel(20, 30, 1);
        lcd.pixel(19, 30, 1);
        lcd.pixel(22, 30, 1);
        lcd.pixel(23, 30, 1);
        //time in second
        double clk = 0;
        for(int j = 21; j < 110 ; j++){
            float tempr;
            tempr = temp.temp();
            lcd.locate(70, 0);
            lcd.printf("Temp:%0.2f", tempr);
            float c;
            //temp line
            c = 45 - (tempr - 8);
            lcd.pixel(j, c, 1);
            lcd.copy_to_lcd();
            clk += 0.1;
            lcd.locate(120, 23);
            lcd.printf("S");
            lcd.locate(105, 23);
            lcd.printf("%0.1f",clk);
            wait(0.1);
        }
        lcd.cls();
    }
    return 0;
}   
