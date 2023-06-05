#include <iostream>
#include<string>
#include<stdlib.h>
//#include<ctime>
//#include<time.h>
//#include<new>
using namespace std;

void copy() {
	int v[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//int v2[10];
	for (auto x : v)
		cout << x << '\n';

	for (auto x : { 10,21,32,43,54,65 })
		cout << x << '\n';
}


void increment() {
	int v[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (auto& x : v) {
		v[x]++;
		++x;
	
	}
	for (auto x : v)
		cout << x << endl;

}


int count_x(const char* p, char x) { // count x in the char* p
	if (p == nullptr) return 0;
	int count = 0;
	for (; *p != '\0'; ++p)
		if (*p == x)
			++count;
	return count;
}

char* NewCharArr(int x) { //creat a char arrary which has x items but need "delete[] y" in the end
	char* y = new char[x];
	char a = 'A';
	for (int i = 0; i < x; ++i) {
		a = 'A' + rand() % 60;
		if (a >= 'A' && a <= 'Z')
			y[i] = a;
		else if (a >= 'a' && a <= 'z')
			y[i] = a;
		else if (a > 'Z' && a < 'a')
			y[i] = a - 10;
		else
			y[i] = a - 20;

		cout << y[i] << ' ';
	}
		
	return y;

}










