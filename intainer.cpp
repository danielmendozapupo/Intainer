//IntainerProject.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include "intainer.h"
#include <iterator>
using namespace std;



int main()
{
	int Size = 10; intainer IN(Size);
	for (int i = 0; i < Size; ++i) IN.set(i, i + 10);


	for (int i = 0; i < Size; ++i) cout << IN.get(i) << " "; cout << endl;

	for (auto i : IN) cout << i << " "; cout << endl;
	for (auto it = IN.begin(); it != IN.end(); ++it) cout << *it << " "; cout << endl;

	system("pause"); return 0;
}
