#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq, count=0;
	char str[4096];
	DWORD nread=1;
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	HANDLE f = CreateFile(L"a.txt", GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	if(f==INVALID_HANDLE_VALUE)
		cout << "Error opening a.txt!";
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек


	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	BOOL bResult = TRUE;
	while (!(bResult && nread == 0)) {
	  bResult=ReadFile(f, str, 4096, &nread, 0);
	  for (DWORD i=0; i<nread; i++){
		if(str[i]=='\n')
			count++;
	  }
	}
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла
	
	CloseHandle(f);

	cout << count << "\n Time spent:" << (t2-t1)/(1.*freq);
	return 0;
}