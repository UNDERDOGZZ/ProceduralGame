#pragma once
class CColision
{
public:
	CColision(int filas,int columnas)
	{
		this->filas = filas;
		this->columnas = columnas;
		this->Colision = false;
	}
	~CColision()
	{

	}

	bool GameOver_PorColision_Ene(int **Mapa)
	{
		Colision = verifica_Colision_Enemigo(Mapa);
		if (Colision==true)
		{
			Console::Clear();
			Console::ForegroundColor = ConsoleColor::Red;
			cout << " Game Over!!";
			return true;
		}
	}


	bool verifica_Colision_Enemigo(int **Mapa)
	{
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				int a = Mapa[i][j];
				if (a==4)
				{
					int b = Mapa[i - 1][j];
					if (b == 9)
					{
						return true;
					}
					int c = Mapa[i + 1][i];
					if (c == 9)
					{
						return true;
					}
					int d = Mapa[i][j - 1];
					if (d == 9)
					{
						return true;
					}
					int e = Mapa[i][j + 1];
					if (e == 9)
					{
						return true;
					}
				}
				if (a==8)
				{
					int b = Mapa[i - 1][j];
					if (b == 9)
					{
						return true;
					}
					int c = Mapa[i + 1][i];
					if (c == 9)
					{
						return true;
					}
					int d = Mapa[i][j - 1];
					if (d == 9)
					{
						return true;
					}
					int e = Mapa[i][j + 1];
					if (e == 9)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	bool verifica_Colision_Teleport(int **Mapa)
	{
		
	}
private:
	int filas, columnas;
	bool Colision;
};