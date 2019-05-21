#include "main.h"

using namespace std;


#ifndef CLASS_UCZNIOWIE_H_
#define CLASS_UCZNIOWIE_H_

//plik nag³owkowy klasy Uczniowie, deklaracja zmiennych i metod

class Uczniowie{
	string idUcznia;
	string imieUcznia;
	string nazwiskoUcznia;
	string idKlasyUcznia;

	friend class odczytywanieDanych;
	friend class Nauczyciele;
	friend class Oceny;
public:
	Uczniowie(string idUcznia, string imieUcznia, string nazwiskoUcznia, string idKlasyUcznia);
	Uczniowie();

	void wyswietlInfo();

	string pokaz_Imie();

	string pokaz_Nazwisko();

	//void menuPoZalogowaniuUcznia();

	string zwroc_idKlasyUcznia();

	string zwroc_id();

	void wyswietl_Nauczycieli(Nauczyciele *tablica, int rozmiarTablicy);

	int zwroc_LiczbePrzedmiotowUcznia(Nauczyciele *tablica, int rozmiarTablicy);

	int zwroc_LiczbaOcen(Oceny *tablica, int rozmiarTablicy);



	void wypelnijTabliceOcenUcznia(Oceny *tablicaWszystkichOcen, Oceny *tablicaOcenUcznia, int rozmiarTablicyWszystkich);

	void wypelnijTabliceNauczycieliUcznia(Nauczyciele *tablicaWszystkichNauczycieli, Nauczyciele *tablicaNauczycieliUcznia, int rozmiarTablicyWszystkich);

	void wyliczSredniaOcen(Nauczyciele *tablicaNauczycieliUczacych, Oceny *tablicaZOcenami, int liczbaPrzedmiotow, int iloscOcen);

	void zwroc_OtrzymaneOceny(Nauczyciele *tabNauczycieliUczacych, Oceny *tablicaZOcenami, int liczbaPrzedmiotow, int rozmiarTablicyOcen);

	double zwroc_srOcen(Nauczyciele *tablicaNauczycieliUczacych, Oceny *tablicaZOcenami, int liczbaPrzedmiotow, int iloscOcen);

	double zwroc_OcenaKoncowa(string Przedmiot, Oceny *tablicaZOcenami, int iloscOcen);

	void porownanieZInnymi(double &sredniaOcen, string &klasaUcznia, Uczniowie *tablicaUczniow,
			int rozmiarTabUcz, Nauczyciele *tablicaNauczycieli, int rozmiarTabNau, Oceny *tablicaOcen, int rozmiarTabOce);

	void najlepsiZPrzedmiotow(int liczbaPrzedmiotow, string &klasaUcznia, Uczniowie *tablicaUczniow,
			int rozmiarTabUcz, Nauczyciele *tablicaNauczycieli, int rozmiarTabNau, Oceny *tablicaOcen, int rozmiarTabOce);

	~Uczniowie();


};


#endif /*CLASS_UCZNIOWIE_H_*/
