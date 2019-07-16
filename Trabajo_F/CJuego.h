#include<iostream>
#include"CMapa.h"
#include"CPersonaje.h"
#include"CPersonajes.h"
#include"CRegistra.h"
#include"CColision.h"
#include<fstream>
#include<string>
#include <stdlib.h>

class CJuego
{
public:
	CJuego(int NumJugador, char respuesta)
	{
		this->pasa = false;
		this->retrocede = false;
		this->filas = 25;
		this->columnas = 40;
		Nivel = 1;
		this->rpta = respuesta;
		this->NumJug = NumJugador;
		this->UF = 1 + (rand() % 20);
		this->UC = 1 + (rand() % 30);
		if (respuesta == 'y'&& NumJugador == 1) {
			ifstream archivo;
			archivo.open("Mapa.txt", ios::out);
			string temp;
			for (int i = 0; i < filas; i++)
			{
				for (int j = 0; j < columnas; j++)
				{
					if (j < columnas - 1) {
						getline(archivo, temp, ',');
					}
					else {
						getline(archivo, temp);
					}
					Mapa[i][j] = atoi(temp.c_str());
				}
			}
			objPersonaje = new CPersonaje(UF, UF, filas, columnas);
			this->Mapa = objPersonaje->Generar_Map();
		}
		if (respuesta == 'y'&& NumJugador == 2) {
			ifstream archivo;
			archivo.open("Mapa.txt", ios::out);
			string temp;
			for (int i = 0; i < filas; i++)
			{
				for (int j = 0; j < columnas; j++)
				{
					if (j < columnas - 1) {
						getline(archivo, temp, ',');
					}
					else {
						getline(archivo, temp);
					}
					Mapa[i][j] = atoi(temp.c_str());
				}
			}
			objPersonajes = new CPersonajes(UF, UC, UF + 1, UC + 1, filas, columnas);
			this->Mapa = objPersonajes->Generar_Map();
		}
			
			this->objRegistra = new CRegistra();
			this->objRegistra->guardarEnPila(this->Mapa, filas, columnas, UF, UC);

			if (NumJug == 3)
			{

			}
			objColision = new CColision(filas, columnas);


		}
		else
		{
			if (NumJugador == 1)
			{
				objPersonaje = new CPersonaje(UF, UF, filas, columnas);
				this->Mapa = objPersonaje->Generar_Map();
			}
			if (NumJugador == 2)
			{
				objPersonajes = new CPersonajes(UF, UC, UF + 1, UC + 1, filas, columnas);
				this->Mapa = objPersonajes->Generar_Map();
			}
			this->objRegistra = new CRegistra();
			this->objRegistra->guardarEnPila(this->Mapa, filas, columnas, UF, UC);

			if (NumJug == 3)
			{

			}
			objColision = new CColision(filas, columnas);

			/*objRegistra->GuardarCSV(Mapa, filas, columnas);*/
		}
		if (NumJugador == 1)
		{
			objPersonaje = new CPersonaje(UF, UF, filas, columnas);
			this->Mapa = objPersonaje->Generar_Map();
		}
		if (NumJugador == 2)
		{
			objPersonajes = new CPersonajes(UF, UC, UF + 1, UC + 1, filas, columnas);
			this->Mapa = objPersonajes->Generar_Map();
		}
		this->objRegistra = new CRegistra();
		this->objRegistra->guardarEnPila(this->Mapa, filas, columnas, UF, UC);

		if (NumJug == 3)
		{

		}
		objColision = new CColision(filas, columnas);

		/*objRegistra->GuardarCSV(Mapa, filas, columnas);*/
	}
	~CJuego()
	{

	}

	void mover(char tecla)
	{

		if (NumJug == 1)
		{
			if (tecla == 'w' || tecla == 'W')pasa = objPersonaje->Mover(1);
			if (tecla == 's' || tecla == 'S')pasa = objPersonaje->Mover(2);
			if (tecla == 'a' || tecla == 'A')pasa = objPersonaje->Mover(3);
			if (tecla == 'd' || tecla == 'D')pasa = objPersonaje->Mover(4);
			if (tecla == 'f' || tecla == 'F')pasa = objPersonaje->Mover(5);
			if (tecla == 'c' || tecla == 'C')pasa = objPersonaje->Mover(6);
			if (tecla == 'x' || tecla == 'X')pasa = objPersonaje->Mover(7);
			if (tecla == 'v' || tecla == 'V')pasa = objPersonaje->Mover(8);
			Teleport();
		}
		if (NumJug == 2)
		{
			if (tecla == 'w' || tecla == 'W')pasa = objPersonajes->Mover(1);
			if (tecla == 's' || tecla == 'S')pasa = objPersonajes->Mover(2);
			if (tecla == 'a' || tecla == 'A')pasa = objPersonajes->Mover(3);
			if (tecla == 'd' || tecla == 'D')pasa = objPersonajes->Mover(4);
			if (tecla == 'f' || tecla == 'F')pasa = objPersonajes->Mover(9);
			if (tecla == 'c' || tecla == 'C')pasa = objPersonajes->Mover(10);
			if (tecla == 'x' || tecla == 'X')pasa = objPersonajes->Mover(11);
			if (tecla == 'v' || tecla == 'V')pasa = objPersonajes->Mover(12);
			//jugador2
			if (tecla == 'i' || tecla == 'I')objPersonajes->Mover(5);
			if (tecla == 'k' || tecla == 'K')objPersonajes->Mover(6);
			if (tecla == 'j' || tecla == 'J')objPersonajes->Mover(7);
			if (tecla == 'l' || tecla == 'L')objPersonajes->Mover(8);
			if (tecla == 'h' || tecla == 'H')objPersonajes->Mover(13);
			if (tecla == 'n' || tecla == 'N')objPersonajes->Mover(14);
			if (tecla == 'b' || tecla == 'B')objPersonajes->Mover(15);
			if (tecla == 'm' || tecla == 'M')objPersonajes->Mover(16);


		}
		if (tolower(tecla) == 'o')
			this->retrocederNivel();
		if (tolower(tecla) == 'g'){
			ofstream archivo;
			archivo.open("Mapa.txt", ios::out);
			for (int i = 0; i < filas; i++)
				{
					for (int j = 0; j < columnas; j++)
						{
							archivo << Mapa[i][j];
						}
							archivo << endl;
				}
		}
	}

	bool GameOver()
	{
		return objColision->GameOver_PorColision_Ene(Mapa);
	}

	void Teleport()
	{
		if (pasa)
		{
			this->UF = 1 + (rand() % 20);
			this->UC = 1 + (rand() % 30);
			if (NumJug == 1)
			{
				Nivel++;
				objPersonaje = new CPersonaje(UF, UC, filas, columnas);
				this->Mapa = objPersonaje->Generar_Map();

			}
			if (NumJug == 2)
			{
				Nivel++;
				objPersonajes = new CPersonajes(UF, UC, UF + 1, UC + 1, filas, columnas);
				this->Mapa = objPersonajes->Generar_Map();
			}
			objRegistra->guardarEnPila(Mapa, filas, columnas, UF, UC);
			pasa = false;
		}

		if (retrocede) {
			this->Mapa = objRegistra->obtenerMapaAnterior();
			this->objPersonaje->setMapa(Mapa);
			retrocede = false;
			Nivel--;
		}
	}

	void Imprimir()
	{
		objMapa->Mostrar(Mapa, filas, columnas, Nivel);
	}

	void retrocederNivel() {
		if (objRegistra->size() > 1) {
			retrocede = true;
			Teleport();
		}
	}


private:
	int **Mapa;
	int filas, columnas;
	int UF, UC, UFE, UCE;
	int NumJug;
	char rpta;
	bool pasa, retrocede;
	int Nivel;
	CPersonaje*objPersonaje;
	CPersonajes*objPersonajes;
	CMapa*objMapa;
	CRegistra*objRegistra;
	CColision*objColision;
};