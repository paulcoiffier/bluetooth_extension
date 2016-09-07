#include "bluetooth.h"
#include <SoftwareSerial.h>

int rxPin = 10;
int txPin = 11;
SoftwareSerial blueToothSerial(0,0);

int inputString = 0;
boolean stringComplete = false;

BluetoothClass::BluetoothClass(){
  level = 0;
  stringComplete = false;
}


void BluetoothClass::init (int rx,int tx, String name, int code)
{
	rxPin = rx;
	txPin = tx;
	
	pinMode(rxPin, INPUT);
	pinMode(txPin, OUTPUT);

	blueToothSerial = SoftwareSerial(rxPin, txPin);
	
	String codePin = String(code);
	
	blueToothSerial.begin(38400); 
	blueToothSerial.print("\r\n+STWMOD=0\r\n"); 
	blueToothSerial.print("\r\n+STNA="+name+"\r\n"); 
	blueToothSerial.print("\r\n+STOAUT=1\r\n"); 
	blueToothSerial.print("\r\n+STAUTO=0\r\n"); 
	blueToothSerial.print("\r\n+STPIN="+codePin+"\r\n");
	delay(2000); 
	blueToothSerial.print("\r\n+INQ=1\r\n");
	//Serial.println("The slave bluetooth is inquirable!");
	delay(2000); 
	blueToothSerial.flush();
	

}

void BluetoothClass::bluetoothLoop() {

  
  int  recvChar;

if (blueToothSerial.available()) { 
      recvChar = blueToothSerial.read();	  
      inputString = recvChar;
      stringComplete = true;
    }
    
}

boolean BluetoothClass::dataLineAvailable(void)
{
  if(stringComplete==true)
  {
    stringComplete = false;
	return true;
  } else {
	return false;
  }
}

int BluetoothClass::readDataLine(void)
{
  stringComplete = false;
  return inputString;
}

