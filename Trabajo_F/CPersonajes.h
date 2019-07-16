#pragma once
#include"CEnemigos.h"
class CPersonajes
{
public:
	CPersonajes(int UF, int UC,int UF2,int UC2, int filas, int columnas)
	{
		this->UF = UF;
		this->UC = UC;
		this->UF2 = UF2;
		this->UC2 = UC2;
		objEnemigos = new CEnemigos(UF, UC, UF2, UC2, filas, columnas);
		this->Mapa = objEnemigos->get_Map();
	}
	~CPersonajes()
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
			if (Mapa[UF - 1][UC] == 6)
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
			if (Mapa[UF + 1][UC] == 6)
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
		//Jugador2
		if (movimiento == 5)
		{
			if (Mapa[UF2 - 1][UC2] == 0 || Mapa[UF2 - 1][UC2] == 1 || Mapa[UF2 - 1][UC2] == 2)
			{
				Mapa[UF2][UC2] = 0;
				UF2--;
				Mapa[UF2][UC2] = 8;
				return false;
			}
			if (Mapa[UF2 - 1][UC2] == 6)
			{
				Mapa[UF2][UC2] = 0;
				UF2--;
				Mapa[UF2][UC2] = 8;
				return true;
			}
		}
		if (movimiento == 6)
		{
			if (Mapa[UF2 + 1][UC2] == 0 || Mapa[UF2 + 1][UC2] == 1 || Mapa[UF2 + 1][UC2] == 2)
			{
				Mapa[UF2][UC2] = 0;
				UF2++;
				Mapa[UF2][UC2] = 8;
				return false;
			}
			if (Mapa[UF2 + 1][UC2] == 6)
			{
				Mapa[UF2][UC2] = 0;
				UF2++;
				Mapa[UF2][UC2] = 8;
				return true;
			}
		}
		if (movimiento == 7)
		{
			if (Mapa[UF2][UC2 - 1] == 0 || Mapa[UF2][UC2 - 1] == 1 || Mapa[UF2][UC2 - 1] == 2)
			{
				Mapa[UF2][UC2] = 0;
				UC2--;
				Mapa[UF2][UC2] = 8;
				return false;
			}
			if (Mapa[UF2][UC2 - 1] == 6)
			{
				Mapa[UF2][UC2] = 0;
				UC2--;
				Mapa[UF2][UC2] = 8;
				return true;
			}
		}
		if (movimiento == 8)
		{
			if (Mapa[UF2][UC2 + 1] == 0 || Mapa[UF2][UC2 + 1] == 1 || Mapa[UF2][UC2 + 1] == 2)
			{
				Mapa[UF2][UC2] = 0;
				UC2++;
				Mapa[UF2][UC2] = 8;
				return false;
			}
			if (Mapa[UF2][UC2 + 1] == 6)
			{
				Mapa[UF2][UC2] = 0;
				UC2++;
				Mapa[UF2][UC2] = 8;
				return true;
			}
		}
		//saltos de J1
		if (movimiento == 9)
		{
			if (Mapa[UF - 2][UC] == 0 || Mapa[UF - 2][UC] == 1 || Mapa[UF - 2][UC] == 2)
			{
				Mapa[UF][UC] = 0;
				UF = UF - 2;
				Mapa[UF][UC] = 4;
			}
		}
		if (movimiento == 10)
		{
			if (Mapa[UF + 2][UC] == 0 || Mapa[UF + 2][UC] == 1 || Mapa[UF + 2][UC] == 2)
			{
				Mapa[UF][UC] = 0;
				UF = UF + 2;
				Mapa[UF][UC] = 4;
			}
		}
		if (movimiento == 11)
		{
			if (Mapa[UF][UC - 2] == 0 || Mapa[UF][UC - 2] == 1 || Mapa[UF][UC - 2] == 2)
			{
				Mapa[UF][UC] = 0;
				UC = UC - 2;
				Mapa[UF][UC] = 4;
			}
		}
		if (movimiento == 12)
		{
			if (Mapa[UF][UC + 2] == 0 || Mapa[UF][UC + 2] == 1 || Mapa[UF][UC + 2] == 2)
			{
				Mapa[UF][UC] = 0;
				UC = UC + 2;
				Mapa[UF][UC] = 4;
			}
		}
		//saltos J2
		if (movimiento == 13)
		{
			if (Mapa[UF2 - 2][UC2] == 0 || Mapa[UF2 - 2][UC2] == 1 || Mapa[UF2 - 2][UC2] == 2)
			{
				Mapa[UF2][UC2] = 0;
				UF2 = UF2 - 2;
				Mapa[UF2][UC2] = 8;
			}
		}
		if (movimiento == 14)
		{
			if (Mapa[UF2 + 2][UC2] == 0 || Mapa[UF2 + 2][UC2] == 1 || Mapa[UF2 + 2][UC2] == 2)
			{
				Mapa[UF2][UC2] = 0;
				UF2 = UF2 + 2;
				Mapa[UF2][UC2] = 8;
			}
		}
		if (movimiento == 15)
		{
			if (Mapa[UF2][UC2 - 2] == 0 || Mapa[UF2][UC2 - 2] == 1 || Mapa[UF2][UC2 - 2] == 2)
			{
				Mapa[UF2][UC2] = 0;
				UC2 = UC2 - 2;
				Mapa[UF2][UC2] = 8;
			}
		}
		if (movimiento == 16)
		{
			if (Mapa[UF2][UC2 + 2] == 0 || Mapa[UF2][UC2 + 2] == 1 || Mapa[UF2][UC2 + 2] == 2)
			{
				Mapa[UF2][UC2] = 0;
				UC2 = UC2 + 2;
				Mapa[UF2][UC2] = 8;
			}
		}
		objEnemigos->Mover();
		return false;
	}

private:
	int UF, UC;
	int UF2, UC2;
	int **Mapa;
	CEnemigos*objEnemigos;
};