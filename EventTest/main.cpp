#include <windows.h>
#include <stdio.h>
#include <process.h>

int piao = 100;

unsigned long WINAPI SellTicetA(void* arg) {

	return 0;
}

unsigned long WINAPI SellTicetB(void* arg) {

	return 0;
}


int main(void) {
	HANDLE hEvent ,hThread_A, hThread_B;
	
	hEvent = CreateEvent(NULL, FALSE, FALSE, 0);

	hThread_A = CreateThread(NULL, 0, SellTicetA, NULL, 0, 0);
	hThread_B = CreateThread(NULL, 0, SellTicetB, NULL, 0, 0);

	int a;

	system("pause");
	return 0;
}