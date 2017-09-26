// Zadanie2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;



int main(int argc, char * argv[])
{
	ifstream subor;
	istream *pVstup = nullptr;

	for (int i = 0; i < argc; ++i)
		cout << argv[i] << endl;

	if (argc < 2 || argc > 3)
		return -1;

	if (argc == 3)
	{
		//subor
		subor.open(argv[0],fstream::in);
		if (!subor.is_open())
			return -1;
		pVstup = &subor;
	}

	else
	{
		pVstup = &cin;
	}

    return 0;
}

