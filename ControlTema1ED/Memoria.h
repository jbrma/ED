/*
NOMBRE Y APELLIDOS DE LOS COMPONENTES DEL GRUPO QUE HAN
REALIZADO LA PRÁCTICA: Yikang Chen, Jiahao Ji


(si algún componente no ha realizado la práctica,
no debe aparecer)

*/
using namespace std;

#ifndef _MEMORIA_H_
#define _MEMORIA_H_

/// Excepción de direccion invalida
class DireccionInvalida {};


template<class T>
class Memoria {
public:
	/**
	 * crea una memoria
	 * @param defecto valor por defecto de las celdas
	 */
	Memoria(const T& defecto) {
		tam = 2;
		vec = new T[tam];
		defec = defecto;
		for (int i = 0; i < tam; i++) {
			vec[i] = defecto;
		}
	}

	Memoria(const Memoria<T>& m) {
		tam = m.tam;
		defec = m.defec;
		vec = new T[tam];
		for (int i = 0; i < tam; i++) {
			vec[i] = m.vec[i];
		}
	}

	~Memoria() {
		delete[] vec;
	}

	Memoria<T>& operator=(const Memoria<T>& m) {
		if (this != &m) {
			tam = m.tam;
			defec = m.defec;
			delete[] vec;
			vec = new T[tam];
			for (int i = 0; i < tam; i++) {
				vec[i] = m.vec[i];
			}
		}
		return *this;
	}
	/**
	 * Devuelve el contenido de una celda
	 * @param d dirección de la celda
	 */
	const T& fetch(int d) const {
		if (d < tam && d >= 0) {
			return vec[d];
		}
		else if (d >= tam && d >= 0) {
			return defec;
		}
		else throw DireccionInvalida();
	}

	/**
	 * Almacena un valor en una celda
	 * @param d dirección de la celda
	 * @param v valor a almacenar
	 */
	void load(int d, const T& v) {
		if (d >= 0 && v != defec) {
			if (d >= tam) {
				ampliar(d);
			}
			vec[d] = v;
		}
		else {
			throw DireccionInvalida();
		}
	}


	// DEBEN INCLUIRSE E IMPLEMENTARSE 
	// LAS OPERACIONES ADICIONALES
	// NECESARIAS PARA GARANTIZAR EL CORRECTO
	// FUNCIONAMIENTO DEL TAD


private:
	// INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES
	int tam;  //tamaño de la memoria
	T* vec;	 //Array
	T defec; //Valor por defecto

	void ampliar(int t) {
		T* vec1 = vec;
		int tam_aux = tam;
		tam = t+1;
		vec = new T[tam];
		for (int i = 0; i < tam_aux; i++) {
			vec[i] = vec1[i];
		}

		for (int i = tam_aux; i < tam ; i++) {
			vec[i] = defec;
		}
		delete[] vec1;
	}
};


#endif


