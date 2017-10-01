// Zadanie1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //cin, cout
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iterator> // istream_iterator

using namespace std;

template <typename T>
size_t counter(istream &str) //pocitadlo
{
	return distance(istream_iterator<T>(str), istream_iterator<T>());
}


class line : public string {};

istream &operator>>(istream &str, line &line)
{
	getline(str, line);
	return str;
}

int main(int argc, char * argv[]) // argumenty prikazoveho riadku
{
	istream *pVstup = nullptr;
	ifstream subor;

	if (argc < 2 || argc > 3) return -1;

	else if (argc == 3)
	{
		subor.open(argv[2], fstream::in);
		if (!subor.is_open()) return -1;
		pVstup = &subor;
	}

	else
	{
		cout << "Zadaj text:" << endl;
		pVstup = &cin;
	}
	
	if (argv[1] == string("-c"))
		cout << "Pocet znakov je: " << counter<char>(*pVstup) << endl;

	else if (argv[1] == string("-w"))
		cout << "Pocet slov je: " << counter<string>(*pVstup) << endl;

	else if (argv[1] == string("-l"))
		cout << "Pocet riadkov je: " << counter<line>(*pVstup) << endl;
	
	else return -1;

	if (pVstup != &cin)
		subor.close();

	return 0;
}