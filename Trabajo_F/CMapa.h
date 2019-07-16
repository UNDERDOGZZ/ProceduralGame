#pragma once
#include<time.h>
#include<iostream>
using namespace std;
using namespace System;

class CMapa
{
public:
	CMapa(int filas,int columnas)
	{
		this->filas = filas;
		this->columnas = columnas;
		Mapa = new int*[filas];
		for (int i = 0; i < filas; i++)
		{
			Mapa[i] = new int[columnas];
		}
	}
	~CMapa()
	{

	}

	int **Crear_Map(int UF,int UC,int UFE,int UCE)
	{
		srand(time(nullptr));

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				if (0<i&&i<filas)
				{
					if (0<j&&j<columnas)
					{
						Mapa[i][j] = rand() % 4;
					}
				}
				Mapa[i][0] = 5;
				Mapa[0][j] = 5;
				Mapa[i][columnas - 1] = 5;
				Mapa[filas - 1][j] = 5;
			}
		}
		Mapa[UF][UC] = 4;
		Mapa = Portal(Mapa, (rand() % 15) + 1, (rand() % 23) + 1);

		return Mapa;
	}

	int **Crear_Map_2P(int UF,int UC,int UF2,int UC2, int UFE, int UCE)
	{

		srand(time(nullptr));

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				if (0<i&&i<filas)
				{
					if (0<j&&j<columnas)
					{
						Mapa[i][j] = rand() % 4;
					}
				}
				Mapa[i][0] = 5;
				Mapa[0][j] = 5;
				Mapa[i][columnas - 1] = 5;
				Mapa[filas - 1][j] = 5;
			}
		}
		Mapa[UF][UC] = 4;
		Mapa[UF2][UC2] = 8;

		Mapa = Portal(Mapa, (rand() % 15) + 1, (rand() % 23) + 1);

		return Mapa;
	}

	int** Portal(int **Mapa,int a,int b)
	{
		if ((Mapa[a][b] != 4) && (Mapa[a + 1][b + 1] != 4) && (Mapa[a + 1][b] != 4) && (Mapa[a][b + 1] != 4)&& (Mapa[a][b] != 8) && (Mapa[a + 1][b + 1] != 8) && (Mapa[a + 1][b] != 8) && (Mapa[a][b + 1] != 8))
		{
			Mapa[a][b] = 6;
			Mapa[a + 1][b + 1] = 6;
			Mapa[a + 1][b] = 6;
			Mapa[a][b + 1] = 6;
			return Mapa;
		}
		else
		{
			srand(time(0));
			Portal(Mapa, (rand() % 23) + 1, (rand() % 23) + 1);
		}
	}

	void Mostrar(int **Mapa,int filas,int columnas,int Nivel)
	{
		Console::BackgroundColor = ConsoleColor::Black;
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				if (Mapa[i][j] == 0)cout << ' ';//probabilidad de 75% d espacios vacios
				if (Mapa[i][j] == 1)cout << ' ';
				if (Mapa[i][j] == 2)cout << ' ';
				if (Mapa[i][j] == 3)//pared
				{
					Console::ForegroundColor = ConsoleColor::Red;
					cout << (char)219;
				}
				if (Mapa[i][j] == 4)//jugador
				{
					Console::ForegroundColor = ConsoleColor::Yellow;
					cout << (char)207;
				}
				if (Mapa[i][j] == 5)//encierro
				{
					Console::ForegroundColor = ConsoleColor::Blue;
					cout << (char)219;
				}
				if (Mapa[i][j] == 6)//teleport
				{
					Console::ForegroundColor = ConsoleColor::Gray;
					cout << (char)219;
				}
				if (Mapa[i][j] == 7)//enemigo
				{
					Console::ForegroundColor = ConsoleColor::White;
					cout << (char)207;
				}
				if (Mapa[i][j]==8)//segJugador
				{
					Console::ForegroundColor = ConsoleColor::Green;
					cout << (char)207;
				}
				if (Mapa[i][j]==9)//Enemigo FANTASMA
				{
					int a = rand() % 2;
					if (a==0)
					{
						Console::ForegroundColor = ConsoleColor::Cyan;
					}
					else if(a==1)
					{
						Console::ForegroundColor = ConsoleColor::DarkMagenta;

					}
					cout << (char)178;
				}
			}
			cout << endl;
		}

		cout << endl;
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "Esta en el mundo: " << Nivel;
	}



private:
	int **Mapa;
	int filas, columnas;
};