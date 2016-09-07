#ifndef motor_h
#define motor_h

#include <Arduino.h>

class BluetoothClass
{
	public:
		BluetoothClass();
		void init(int rx,int tx, String name, int code);
		void bluetoothLoop();
		boolean dataLineAvailable(void);
		int readDataLine(void);
	private:
		int level;
		boolean stringComplete;
};

#endif