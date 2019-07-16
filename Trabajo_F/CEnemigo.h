#pragma once
#include"CMapa.h"
class CEnemigo //FANTASMA
{
public:
	CEnemigo(int UF,int UC,int filas,int columnas)
	{
		this->UFE = 1 + (rand() % 20);
		this->UCE = 1 + (rand() % 30);
		objMapa = new CMapa(filas, columnas);
		this->Mapa = objMapa->Crear_Map(UF, UC, UFE, UCE);
	}
	~CEnemigo()
	{

	}
	int** get_Map()
	{
		return Mapa;
	}

	void Mover()
	{
		srand(time(nullptr));
		int mov = rand() % 4;
		//mov random
		if (mov == 0)
		{
			int a = Mapa[UFE - 1][UCE];
			if (a <= 3)
			{
				Mapa[UFE][UCE] = 3;
				UFE--;
				Mapa[UFE][UCE] = 9;
			}
		}
		if (mov==1)
		{
			int b = Mapa[UFE + 1][UCE];
			if (b <= 3)
			{
				Mapa[UFE][UCE] = 3;
				UFE++;
				Mapa[UFE][UCE] = 9;
			}
		}
		if (mov==2)
		{
			int c = Mapa[UFE][UCE - 1];
			if (c <= 3);
			{
				Mapa[UFE][UCE] = 3;
				UCE--;
				Mapa[UFE][UCE] = 9;
			}
		}
		if (mov==3)
		{
			int d = Mapa[UFE][UCE + 1];
			if (d <= 3)
			{
				Mapa[UFE][UCE] = 3;
				UCE++;
				Mapa[UFE][UCE] = 9;
			}
		}
	}
private:
	int UFE, UCE;
	int **Mapa;
	CMapa*objMapa;
};