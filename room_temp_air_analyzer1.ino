
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int i;
float temp;
float Te;
float tempPRINT;
int pin13 = 13;
int sensor = A1;
int sensorValue=0;
void setup()
{
	pinMode(pin13,OUTPUT);
	Serial.begin(9600);
	lcd.begin(16,2);
	pinMode(6,OUTPUT);
	pinMode (7, OUTPUT); // define port 7 as an output port
	pinMode (8, OUTPUT); // define port 8 as an output port
	lcd.print("   HELLO USER!");
	delay(5000);
	lcd.clear();
}
  


void loop()
{
	sensorValue = analogRead(sensor);
	temp = analogRead(A0);
	tempPRINT = (temp*4.8828125-500)/10;
	Serial.println(sensorValue, DEC);

   
	if(tempPRINT >= 25.00 && tempPRINT <= 30.00)
	{
	    lcd.print("Temp: ");
	    lcd.print(tempPRINT);
	    lcd.print(" Cel");
	    delay(100);
	    lcd.setCursor(0,1);
	    lcd.print(sensorValue);
	    lcd.print("  PPM");
	    delay(1000);
	    lcd.clear();
	      
	    if(sensorValue > 750)
		{
	        digitalWrite(pin13,HIGH);
	        lcd.setCursor(0,0);
	        lcd.print("AIR POLLUTED !");
	        lcd.setCursor(3,1);
	        lcd.print("VENTILATE !");
	        delay(500);
	        for (i = 0; i <350; i ++)
	  		{
				    digitalWrite (7, HIGH); // activate the sound
				    delay (1); 
				    digitalWrite (7, LOW); // turn off the sound
				    delay (1);
			}
		  	delay (50); 
		  	for (i = 0; i <150; i ++) 
		    {
			    digitalWrite (7, HIGH); // activate the sound
			    delay (2); // wait 2 milliseconds (repeats the sound every 4 milliseconds and then
			    digitalWrite (7, LOW); // turn off the sound
			    delay (2); // wait 2 milliseconds and repeat the cycle 150 times
		    }
	           lcd.clear();
		}
      	else
	  		digitalWrite(pin13,LOW);
    }
    else
	{
	    lcd.print("Temp: ");
	  
	    lcd.print(tempPRINT);
	    lcd.print(" Cel");
	    delay(100);
	    lcd.setCursor(0,1);
	    lcd.print(sensorValue);
	    lcd.print("  PPM");
	    delay(1000);
	    lcd.clear();
        for (i = 0; i <350; i ++) 
  		{
		    digitalWrite (7, HIGH); // activate the sound
		    delay (1);
		    digitalWrite (7, LOW); // turn off the sound
		    delay (1); 
  		}
  		delay (50); // wait 50 milliseconds before launching the second sound cycle
  		for (i = 0; i <150; i ++) // defines the duration of the second sound (150 cycles of 4 milliseconds)
		{
		    digitalWrite (7, HIGH); // activate the sound
		    delay (2); 
		    digitalWrite (7, LOW); // turn off the sound
		    delay (2); // wait 2 milliseconds and repeat the cycle 150 times
		}
        
        lcd.setCursor(0,0);
        lcd.print("ALERT!!");
        lcd.clear();
        lcd.print("UNSUITABLE TEMP");
        delay(1000);
        lcd.clear();
         
        if(sensorValue > 750)
		{
           digitalWrite(pin13,HIGH);
           lcd.setCursor(0,0);
           lcd.print("AIR POLLUTED !");
           lcd.setCursor(3,1);
           lcd.print("VENTILATE !");
           delay(500);
           lcd.clear();
		}
        else
			digitalWrite(pin13,LOW);
    }
    
	Serial.print("TEMPARATURE : ");
	Serial.print(tempPRINT);
	Serial.print(" *C");
	Serial.println();
    delay(100); 
}
  




 