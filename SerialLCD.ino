/*
	Serial_LCD - NewHaven Display Example

        Serial Connector    SPI/I2C Connector
        RX  GND VDD          SS  SDO SCK SDI VSS VDD
                                     SCL SDA
         o   o  o            o   o   o   o   o   o
         1   2  3            1   2   3   4   5   6

        Serial Connector
        Pin  Name            Description
        1    RX              RX
        2    VSS             GND
        3    GND             5V
        
        
        SPI/I2C Connector
        Pin  Name             Description
        1    SPI/SS           SPI Slace Select
        2    SPI/SDO          SPI Slace Output
        3    SCK/SCL          SPI SCK / I2C SCL
        4    SDI/SDA          SPI Master Input / I2C SDA
        5    VSS              GND              
        6    VDD              5V

	* LCD RX to Arduino TX
	* LCD GND to Arduino GND
        * LCD VDD to Arduino 5V


*/
#include <Serial_LCD.h>
Serial_LCD myLCD(1); // use 0 for Uno, 1 for Galileo, 0-3 for Mega
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000,
};
void setup()
{
  myLCD.begin(16,2);
  myLCD.showBaudRate(); delay(3000);
  myLCD.showFirmwareVersion(); delay(3000);
  myLCD.clear();
  myLCD.home();
  myLCD.print("Smiley Test");
  myLCD.createChar(0,smiley);
  myLCD.print("Hello World!");
  myLCD.cursor();   delay(3000);
  myLCD.blink();    delay(3000);
  myLCD.noBlink();  delay(3000);
  myLCD.noCursor(); delay(3000);
  myLCD.scrollDisplayLeft();  delay(1000);
  myLCD.scrollDisplayLeft();  delay(1000);
  myLCD.scrollDisplayLeft();  delay(1000);
  myLCD.scrollDisplayLeft();  delay(1000);
  myLCD.scrollDisplayRight(); delay(1000);  
  myLCD.scrollDisplayRight(); delay(1000);  
  myLCD.scrollDisplayRight(); delay(1000);  
  myLCD.scrollDisplayRight(); delay(1000);  
  myLCD.clear();
  myLCD.home();
  myLCD.setCursor(0,1);
  for(int i=0; i < 15; i++) {
    myLCD.write(0);
  }
  delay(3000);
  myLCD.clear();
  myLCD.home();
  myLCD.setCursor(0,1);
  myLCD.print("Backlight = ");
  for(int i=1; i < 9; i++) {
    myLCD.print(i);
    myLCD.setBacklight(i);
    delay(3000);
    myLCD.backspace();
  }
  myLCD.setBacklight(4); delay(3000);
  myLCD.clear();
  myLCD.home();
  myLCD.print("Serial LCD Test");
  myLCD.setCursor(0,1);
  myLCD.print("uptime: ");
  
}

void loop()
{
  myLCD.setCursor(8,1);
  myLCD.print(millis()/1000);
  delay(1000);
}
