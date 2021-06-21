#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <MHZ19.h>                                       
#include <SoftwareSerial.h>                                // Remove if using HardwareSerial
#include <dht11.h>

dht11 DHT11;


#define RX_PIN 8                                          // Rx pin which the MHZ19 Tx pin is attached to
#define TX_PIN 9                                          // Tx pin which the MHZ19 Rx pin is attached to
#define BAUDRATE 9600                                      // Device to MH-Z19 Serial baudrate (should not be changed)
#define DHT11PIN 7
  
MHZ19 myMHZ19;                                             // Constructor for library
SoftwareSerial mySerial(RX_PIN, TX_PIN);                   // (Uno example) create device to MH-Z19 serial
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 40 chars and 4 line display

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup()
{
  //Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.createChar(0, smiley);
  lcd.clear();
  // Print a message to the LCD.
  //lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("CO2 Sensor");
  //lcd.setCursor(1,1);
  //lcd.print("(By _______)");
  //lcd.setCursor(18,1);
  //lcd.write(byte(0));
  lcd.setCursor(0,2);
  lcd.print("");
  lcd.setCursor(2,3);
  lcd.print("Initializing....");
  
  mySerial.begin(BAUDRATE);                               // (Uno example) device to MH-Z19 serial start   
  myMHZ19.begin(mySerial);                                // *Serial(Stream) refence must be passed to library begin(). 
  myMHZ19.autoCalibration();     
}


void loop()
{
  int16_t CO2; 
  CO2 = myMHZ19.getCO2();                             // Request CO2 (as ppm)       
  int8_t chk = DHT11.read(DHT11PIN);
  int8_t Temp2 = DHT11.temperature;
  int8_t hum = DHT11.humidity;
  int8_t Temp;
  if (myMHZ19.errorCode == RESULT_OK && CO2>0 && CO2<5000) {
    Temp = myMHZ19.getTemperature();                     // Request Temperature (as Celsius)     
    lcd.setCursor(1,2);
    char line1[20]="";
    sprintf(line1,"T: %d/%d (Celsius)",Temp,Temp2);
    lcd.print(line1);
    lcd.setCursor(0,3);
    char line2[20]="";
    sprintf(line2,"CO2:%4dppm Hum: %2d%%",CO2,hum);
    lcd.print(line2);  
  } else {
    Temp = 0;
    lcd.setCursor(0,2);
    char line1[20]="";
    sprintf(line1,"T: %d, Hum: %2d%%",Temp2,hum);
    lcd.print(line1);
    lcd.setCursor(0,3);
    lcd.print("Initializing CO2...");  
  }

  delay(1000);
}
