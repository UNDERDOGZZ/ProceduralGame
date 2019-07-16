#ifndef __REGISTRA_H__
#define __REGISTRA_H__
#include<fstream>
#include<stack>
using namespace std;

class CRegistra
{
public:
	CRegistra()
	{

	}
	~CRegistra()
	{

	}

	void GuardarCSV(int**Mapa,int filas,int columnas)
	{
		ofstream archivo;
		archivo.open("Mapa.txt", ios::out);
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				archivo << Mapa[i][j]<<",";
			}
			archivo << endl;
		}
	}


	void LeerCSv()
	{

	}


	void guardarEnPila(int**Mapa, int filas, int columnas, int UF, int UC) {
		int **aux;

		aux = new int*[filas];

		for (unsigned int i = 0; i < filas; i++)
			aux[i] = new int[columnas];

		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++)
				aux[i][j] = Mapa[i][j];
		}

		aux[UF][UC] = 1;

		this->historialMapas.push(aux);
	}

	int** obtenerMapaAnterior() {
		this->historialMapas.pop();
		return this->historialMapas.top();
	}

	int size() { return this->historialMapas.size(); }

private:
	stack<int**> historialMapas;
};

#endif