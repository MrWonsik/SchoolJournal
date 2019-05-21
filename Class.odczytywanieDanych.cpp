
#include "main.h"

//vector, odczyt danych do klass uczniowie i nauczyciele i zapis nauczycieli i uczniow do tablic.

using namespace std;


//klasa odczytuj¹ca dane z danego pliku (obiekt ktory przyjmuje jako argument nazwe pliku)
/**
 * w konstruktorze otwierany jest plik do odczytu
 */
odczytywanieDanych::odczytywanieDanych(string nazwaPliku, string type){
		this->nazwaPliku = nazwaPliku;
		if(type == "in")
		{
		Plik.open(nazwaPliku, ios::in);
		cout << "!==============================Otworzono plik: " << nazwaPliku << " do odczytu!" << endl;
		}
		if(type == "app")
		{
		Plik.open(nazwaPliku, ios::app);
		cout << "!==============================Otworzono plik: " << nazwaPliku << " do zapisu!" << endl;
		}
	}

/*
 * w destruktorze plik jest zamykany
 */
odczytywanieDanych::~odczytywanieDanych()
	{
		Plik.close();
		cout << "!==============================Zamkniêto plik: " << nazwaPliku << endl;
	}




//metoda do zliczenia liczby wierszy w tablicy nauczyciele, na podstawie zwracanego rozmiaru tworzona jest tablica nauczycieli o podanej wielkosci
int odczytywanieDanych::zliczenieLiczbyWierszy(int &rozmiarTablicy){
	string linijka;
	while(!Plik.eof())
	{
		getline(Plik,linijka);
		rozmiarTablicy++;
	}
	Plik.clear();
	Plik.seekp(0, ios_base::beg);
	return rozmiarTablicy;
}


//metoda zwracajaca obiekt nauczyciel, po zczytaniu z pliku wartosci
Nauczyciele odczytywanieDanych::ZapisDanychDoTablicyNauczyciele(){

				string odczytanaWartosc;
				string idNauczyciela;
				string imie;
				string nazwisko;
				string Przedmiot;
				int wystapieniaKlas=0;
				//nauczyciel nie moze uczyc wiecej niz 3 klasy (sa tylko 3 1a 2a i 3a)
				string Klasy[3];

				Plik >> idNauczyciela >> imie >> nazwisko >> Przedmiot ;
				cout << "!==============================Odczytywanie z pliku: " << nazwaPliku << endl;
				//petla odczytujaca z pliku klasy a¿ do œrednika
						while(odczytanaWartosc != ";")
						{
							Plik >> odczytanaWartosc;
							if (odczytanaWartosc == ";" )
							{
								break;
							}
							Klasy[wystapieniaKlas]=odczytanaWartosc;
							wystapieniaKlas++;
						};

				//dekrementacja by nie wrzuca³ srednika na ostatni element tablicy.

				Nauczyciele nowy(idNauczyciela, imie, nazwisko, wystapieniaKlas, Klasy, Przedmiot);
				cout << "!==============================Utworzono obiekt klasy Nauczyciele!" << endl;
				return nowy;
}

Uczniowie odczytywanieDanych::ZapisDanychDoTablicyUczniowie(){
				string idUcznia;
				string imie;
				string nazwisko;
				string idKlasy;
				cout << "!==============================Odczytywanie z pliku: " << nazwaPliku << endl;
				Plik >> idUcznia >> imie >> nazwisko >> idKlasy;
				Uczniowie nowy(idUcznia, imie, nazwisko, idKlasy);
				cout << "!==============================Utworzono obiekt klasy Uczniowie!" << endl;
				return nowy;
}

Oceny odczytywanieDanych::ZapisDanychDoTablicyOcen(){
				string idNauczyciela;
				string idUcznia;
				int ocena;
				int waga;
				string data;
				cout << "!==============================Odczytywanie z pliku: " << nazwaPliku << endl;
				Plik >> idNauczyciela >> idUcznia >> ocena >> waga >> data;
				Oceny nowa(idNauczyciela, idUcznia, ocena, waga, data);
				cout << "!==============================Utworzono obiekt klasy Oceny!" << endl;
				return nowa;
}

void odczytywanieDanych::zapisDanychDoPliku(Oceny *doZapisu){
	//cout << doZapisu.idNauczyciela << " " << doZapisu.idUcznia << " " << doZapisu.ocena << " " << doZapisu.waga << " " << doZapisu.data << endl;
	//this->Plik << doZapisu.zwroc_idNau() << " " << doZapisu.zwroc_idUcz() << " " << doZapisu.zwroc_ocena() << " " << doZapisu.zwroc_waga() << " " << doZapisu.zwroc_data() << endl;
	this->Plik << endl << doZapisu->zwroc_idNau() << " " << doZapisu->zwroc_idUcz() << " " << doZapisu->zwroc_ocena() << " " << doZapisu->zwroc_waga() << " " << doZapisu->zwroc_data();
	cout << "!==============================Zapisano w pliku: " << nazwaPliku << endl;
}
