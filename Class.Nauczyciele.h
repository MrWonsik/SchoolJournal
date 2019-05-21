

#include "main.h"


using namespace std;

#ifndef CLASS_NAUCZYCIELE_H_
#define CLASS_NAUCZYCIELE_H_

class Uczniowie; //rozwiazanie problemu ""Uczniowie" has not been declared"

class Nauczyciele{
	string idNauczyciela;
	string imieNauczyciela;
	string nazwiskoNauczyciela;
	int rozmiarTabKlasa;
	string *idKlasy;
	string Przedmiot;

	friend class odczytywanieDanych;
	friend class Uczniowie;
	friend class Oceny;

public:
	Nauczyciele(string idNauczyciela, string imieNauczyciela, string nazwiskoNauczyciela, int rozmiarTabKlasa, string idKlasa[], string Przedmiot);
	Nauczyciele();
	void menuPoZalogowaniuNauczyciela();
	void wyswietlInfo();
	string pokaz_imie();
	string pokaz_nazwisko();
	string zwroc_id();
	string zwroc_Przedmiot();
	string zwroc_idKlasy(int &index);
	int zwroc_iloscKlas();

	void wyswietlUczniowDanejKlasy(string &wyborKlasy, Uczniowie *tablicaUczniow, int rozmiarTablicy);
	void wyswietlKlasy();
	void wyswietlOcenyDanejKlasy(Uczniowie *tablicaUczniow, Oceny *TablicaOcen, int rozmiarTablicyUcz, int rozmiarTablicyOce, string &wyborKlasy, bool &czyistnieje);
	void wyswietlOcenyKoncowe(Uczniowie *tablicaUczniow, Oceny *tablicaOcen, int rozmiarTablicyUcz, int rozmiarTablicyOce, string &wyborKlasy, bool &czyistnieje);

	void wpisOceny_wyborWagi(int &wyborWagi);
	void wybierzKlase(string &wyborKlasy, Uczniowie *tablicaUczniow, int rozmiarTablicyUczniowie, bool &czyistnieje);
	void wybierzUcznia(string &wyborUcznia, Uczniowie *tablicaUczniow, int rozmiarTablicy, bool &czyistniejeUczen);
	void wybierzOcene(int unsigned &Ocena);
	~Nauczyciele();

};

#endif /* CLASS_NAUCZYCIELE_H_ */
