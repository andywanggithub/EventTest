#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <atltrace.h>

#define TRACE ATLTRACE

HANDLE hEvent;
int piao = 100;


DWORD WINAPI SellTicetA(void* arg) {

	while (1) {		

		WaitForSingleObject(hEvent, INFINITE);
			
		if (piao > 0) {
			Sleep(1);
			piao--;
			printf("A ����1��,��ʣ %d ��Ʊ\n", piao);
		}
		else
		{
			break;
		}		

		SetEvent(hEvent);
		
	}

	return 0;
}

DWORD WINAPI SellTicetB(void* arg) {
	
	while (1) {

		WaitForSingleObject(hEvent, INFINITE);

		if (piao > 0) {
			Sleep(1);
			piao--;
			printf("B ����1��,��ʣ %d ��Ʊ\n", piao);
		}
		else
		{
			break;
		}

		SetEvent(hEvent);

	}

	return 0;
}


int main(void) {
	HANDLE hThread_A, hThread_B;
		
	hThread_A = CreateThread(NULL, 0, SellTicetA, NULL, 0, 0);
	hThread_B = CreateThread(NULL, 0, SellTicetB, NULL, 0, 0);

	TRACE("####hThread_A ǰ��");//11111111111111
	CloseHandle(hThread_A);
	TRACE("####hThread_A ����");

	CloseHandle(hThread_B);

	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	SetEvent(hEvent);

	Sleep(8000);

	CloseHandle(hEvent);
	

	system("pause");
	return 0;
}