#include<iostream>
#include<conio.h>
#include"CJuego.h"

using namespace std;
using namespace System;


int main()
{
	int num;
	char rpta;
	Console::SetWindowSize(40, 40);
	cout << "Nummero Jugadores:" << endl;
	cin >> num;
	cout << "¿Cargar Partida?(Y/N)" << endl;
	cin >> rpta;
	CJuego*objJuego = new CJuego(num,rpta);
	Console::Clear();
	while (true)
	{
		if (_kbhit())
		{
			Console::Clear();
			char tecla = getch();
			objJuego->mover(tecla);
			objJuego->Imprimir();
			if (objJuego->GameOver() == true)
			{
				getch();
				return 0;
			}
			if (tecla == 'p' || tecla == 'P')
			{
				return 0;
			}
		}
	}
}