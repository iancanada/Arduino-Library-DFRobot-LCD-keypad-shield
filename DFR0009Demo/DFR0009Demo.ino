/**
 * @file DFR0009Demo
 * DFR0009 C++ library demo
 * Copyright (C) Ian Jin 
 * iancanada.mail@gmail.com
 * https://github.com/iancanada
 * Twitter: @iancanadaTT
 * 
 * 2015-08-26 First release Ver1.00
 * 
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "IanArduinoRTOS.h"
#include "DFR0009.h"
#include <LiquidCrystal.h>

DFR0009 Key(0);    //analog pin 0 for DFR0009 key pin
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // select the pins used on the LCD panel on DFR0009

// the setup routine runs once when you press reset:
void setup() {                    
  lcd.begin(16, 2);              // start LCD
  lcd.setCursor(0,0);lcd.print("I2S1 OPT RCA TTL");
}

// the loop routine runs over and over again forever:
void loop() {
  
  IanOS.run();
  
  switch(Key.getflag())
  {
    case btnNONE:
      lcd.setCursor(0,1);lcd.print("                ");
      break;       
    case btnRIGHT:
      lcd.setCursor(0,1);lcd.print("KEY is btnRIGHT ");
      break;    
    case btnLEFT:
      lcd.setCursor(0,1);lcd.print("KEY is btnLEFT  ");
      break;      
    case btnUP:
      lcd.setCursor(0,1);lcd.print("KEY is btnUP    ");
      break;      
    case btnDOWN:
      lcd.setCursor(0,1);lcd.print("KEY is btnDOWN  ");
      break;      
    case btnSELECT:
      lcd.setCursor(0,1);lcd.print("KEY is btnSELECT");
      break;              
  } 
}

void IanOStasks(void)  //run once every 10 ms as default
{
  //task 1
  Key.scan();
  //task 2...
}
