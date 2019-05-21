#ifndef ODCZYTYWANIEDANYCH_H_
#define ODCZYTYWANIEDANYCH_H_

#include "main.h"
//#include "Class.Oceny.h"

using namespace std;

class odczytywanieDanych{
	string nazwaPliku;
	string type;
	fstream Plik;

	friend class Uczniowie;
	friend class Nauczyciele;
	friend class Oceny;
public:
	odczytywanieDanych(string nazwaPliku, string type);

	~odczytywanieDanych();

	void wyszukajIdRekorduUczen(string login);

	void wyszukajIdRekorduNauczyciel(string login);

	void wczytajPrzedmiotyNauczyciela(string idNauczyciela);

	Nauczyciele ZapisDanychDoTablicyNauczyciele();

	Uczniowie ZapisDanychDoTablicyUczniowie();

	Oceny ZapisDanychDoTablicyOcen();

	void zapisDanychDoPliku(Oceny *doZapisu);

	int zliczenieLiczbyWierszy(int &rozmiarTablicy);
};

#endif /*ODCZYTYWANIEDANYCH_H_*/
