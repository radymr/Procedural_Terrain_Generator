//Custom Random Number Generator. 
#include <windows.h>

using namespace std; 

int Millisecond () {

	SYSTEMTIME time;
	GetSystemTime(&time);
	WORD millis = (time.wSecond * 1000) + time.wMilliseconds;

	return millis;
}
//need to build typecast RND or various different inputs. 

//INTEGER RND
int RND(int min, int max) {

	int RandomNumber = rand() % (max-min) + min;   // v3 in the range 1985-2014	

	return RandomNumber;
}
