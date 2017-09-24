// Zadanie1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	string nazov_suboru, riadky, *text = new string[20];
	int pocet_riadkov = 0, pocet_slov = 0, pocet_znakov = 0;
	char prepinac, posledny;

	cout << "Zadaj nazov suboru (bez .txt): ";
	getline(cin,nazov_suboru);

	nazov_suboru = nazov_suboru + ".txt";
	fstream subor(nazov_suboru.c_str(), fstream::in);
	if (!subor.is_open())
	{
		cout << "Nepodarilo sa otvorit subor!" << endl;
		cout << "\nZadaj text: **Posledny riadok skonci bodkou.**\n";

		do
		{
			getline(cin,text[pocet_riadkov]);
			if (text[pocet_riadkov].size() != 0)
			{
				posledny = text[pocet_riadkov][text[pocet_riadkov].size() - 1];
				pocet_riadkov++;
			}
		} while (posledny != '.');
	}

	cout << "\nPrepinace:\n-c - spocitanie znakov\n-w - spocitanie slov\n-l - spocitanie riadkov\nZadaj prepinac c/w/l: ";
	cin >> prepinac;

	if (prepinac == 'c')		
	{
		if (subor.is_open())
		{
			while (!subor.eof())
			{
				getline(subor, riadky);
				for (int i = 0; i < riadky.size(); i++)
				{
					if (riadky[i] != ' ')
						pocet_znakov++;
				}
			}
			cout << "\nPocet znakov v " << nazov_suboru << " je: " << pocet_znakov << endl << endl;
		}

		else
		{
			for (int i=0; i<text->size(); i++)
			{
				for (int j = 0; j < text[i].size(); j++)
				{
					if (text[i][j] != ' ')
						pocet_znakov++;
				}
			}
			cout << "\nPocet znakov je " << pocet_znakov << endl << endl;
		}
	}

	if (prepinac == 'w')
	{
		
	}

	if (prepinac == 'l')
	{
		if (subor.is_open())
		{
			while (!subor.eof())
			{
				getline(subor, riadky);
				if (riadky.size() != 0)
					pocet_riadkov++;
			}
			cout << "\nPocet riadkov v " << nazov_suboru << " je: " << pocet_riadkov << endl << endl;
		}
		
		else
			cout << "\nPocet riadkov je " << pocet_riadkov << endl << endl;
	}

	subor.close();
	delete[] text;
	return 0;
}