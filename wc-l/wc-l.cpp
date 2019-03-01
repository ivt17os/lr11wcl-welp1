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
    long long t1, t2, freq;
	string str;
	long long count = 0;
	
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	ifstream f("a.txt");
	
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек


	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	while (!f.eof()) {
	  getline(f, str);
	  count++;
	}
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла

	cout << count << "\n Time spent:" << (t2-t1)/(1.*freq);
	return 0;
}