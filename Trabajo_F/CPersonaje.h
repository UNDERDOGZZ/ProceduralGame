#pragma once
#include"CEnemigo.h"
class CPersonaje
{
public:
	CPersonaje(int UF,int UC,int filas,int columnas)
	{
		this->UF = UF;
		this->UC = UC;
		objEnemigo = new CEnemigo(UF, UC, filas, columnas);
		this->Mapa = objEnemigo->get_Map();
	}
	~CPersonaje()
	{

	}

	int** Generar_Map()
	{
		return Mapa;
	}

	bool Mover(int movimiento)
	{
		if (movimiento == 1)
		{
			if (Mapa[UF - 1][UC] == 0 || Mapa[UF - 1][UC] == 1 || Mapa[UF - 1][UC] == 2)
			{
				Mapa[UF][UC] = 0;
				UF--;
				Mapa[UF][UC] = 4;
				return false;
			}
			if (Mapa[UF-1][UC]==6)
			{
				Mapa[UF][UC] = 0;
				UF--;
				Mapa[UF][UC] = 4;
				return true;
			}
		}
		if (movimiento == 2)
		{
			if (Mapa[UF + 1][UC] == 0 || Mapa[UF + 1][UC] == 1 || Mapa[UF + 1][UC] == 2)
			{
				Mapa[UF][UC] = 0;
				UF++;
				Mapa[UF][UC] = 4;
				return false;
			}
			if (Mapa[UF+1][UC]==6)
			{
				Mapa[UF][UC] = 0;
				UF++;
				Mapa[UF][UC] = 4;
				return true;
			}
		}
		if (movimiento == 3)
		{
			if (Mapa[UF][UC - 1] == 0 || Mapa[UF][UC - 1] == 1 || Mapa[UF][UC - 1] == 2)
			{
				Mapa[UF][UC] = 0;
				UC--;
				Mapa[UF][UC] = 4;
				return false;
			}
			if (Mapa[UF][UC - 1] == 6)
			{
				Mapa[UF][UC] = 0;
				UC--;
				Mapa[UF][UC] = 4;
				return true;
			}
		}
		if (movimiento == 4)
		{
			if (Mapa[UF][UC + 1] == 0 || Mapa[UF][UC + 1] == 1 || Mapa[UF][UC + 1] == 2)
			{
				Mapa[UF][UC] = 0;
				UC++;
				Mapa[UF][UC] = 4;
				return false;
			}
			if (Mapa[UF][UC + 1] == 6)
			{
				Mapa[UF][UC] = 0;
				UC++;
				Mapa[UF][UC] = 4;
				return true;
			}
		}
		//saltos
		if (movimiento == 5)
		{
			if (Mapa[UF - 2][UC] == 0 || Mapa[UF - 2][UC] == 1 || Mapa[UF - 2][UC] == 2)
			{
				Mapa[UF][UC] = 0;
				UF = UF - 2;
				Mapa[UF][UC] = 4;
				return false;
			}
		}
		if (movimiento == 6)
		{
			if (Mapa[UF + 2][UC] == 0 || Mapa[UF + 2][UC] == 1 || Mapa[UF + 2][UC] == 2)
			{
				Mapa[UF][UC] = 0;
				UF = UF + 2;
				Mapa[UF][UC] = 4;
				return false;
			}
		}
		if (movimiento == 7)
		{
			if (Mapa[UF][UC - 2] == 0 || Mapa[UF][UC - 2] == 1 || Mapa[UF][UC - 2] == 2)
			{
				Mapa[UF][UC] = 0;
				UC = UC - 2;
				Mapa[UF][UC] = 4;
				return false;
			}
		}
		if (movimiento == 8)
		{
			if (Mapa[UF][UC + 2] == 0 || Mapa[UF][UC + 2] == 1 || Mapa[UF][UC + 2] == 2)
			{
				Mapa[UF][UC] = 0;
				UC = UC + 2;
				Mapa[UF][UC] = 4;
				return false;
			}
		}
		objEnemigo->Mover();
		return false;
	}


	void setUF(int UF) {
		this->UF = UF;
	}

	void setUC(int UC) {
		this->UC = UC;
	}

	void setMapa(int **Mapa) {
		this->Mapa = Mapa;
	}

private:
	int UF, UC;
	int **Mapa;
	CEnemigo*objEnemigo;
};