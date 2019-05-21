
#include "main.h"

#ifndef CLASS_OCENY_H_
#define CLASS_OCENY_H_

class Oceny {
	std::string idNauczyciela;
	std::string idUcznia;
	int ocena;
	int waga;
	std::string data;

	friend class odczytywanieDanych;
	friend class Uczniowie;
	friend class Nauczyciele;

public:
	Oceny(std::string idNauczyciela="N", std::string idUcznia="U", int=0, int waga=0, std::string data = "");
	void wyswietl_ocene();
	std::string zwroc_idNau();
	std::string zwroc_idUcz();
	int zwroc_ocena();
	int zwroc_waga();
	std::string zwroc_data();

	virtual ~Oceny();
};

#endif /* CLASS_OCENY_H_ */
