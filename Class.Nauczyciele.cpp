//plik klasy Nauczyciele

#include "main.h"
#include "Class.Nauczyciele.h"
#include "Class.Uczniowie.h"

using namespace std;
// konstruktor klasy nauczyciele
Nauczyciele::Nauczyciele(string idNauczyciela, string imieNauczyciela, string nazwiskoNauczyciela, int rozmiarTabKlasa, string idKlasy[], string Przedmiot){
		this->idNauczyciela=idNauczyciela;
		this->imieNauczyciela=imieNauczyciela;
		this->nazwiskoNauczyciela=nazwiskoNauczyciela;
		this->Przedmiot=Przedmiot;
		this->rozmiarTabKlasa=rozmiarTabKlasa;

		//alokowanie pamieci dla tablicy która przechowuje stringi
		this->idKlasy= new string[rozmiarTabKlasa];

		//wstawienie do tablicy obiektu wszystkich klas ktorych uczy dany nauczyciel
		for(int i=0;i<rozmiarTabKlasa;i++)
				{
					this->idKlasy[i]=idKlasy[i];
				}
}


Nauczyciele::Nauczyciele()
{


}

//metoda ktora wyswietla informacje obiektu klasy Nauczyciele
void Nauczyciele::wyswietlInfo(){
	cout << "Id: " << idNauczyciela << endl;
	cout << "Imie: " << imieNauczyciela << endl;
	cout << "Nazwisko: " << nazwiskoNauczyciela << endl;
	cout << "Przedmiot: " << Przedmiot << endl;
	cout << "Klasy w ktorych ucze: ";
	for (int i=0;i<rozmiarTabKlasa;i++)
	{
		cout << idKlasy[i] << ", ";
	}
	cout << endl;
}

void Nauczyciele::wyswietlKlasy(){
	if(rozmiarTabKlasa > 0)
	{
	cout << "Klasa" << endl;
	cout << "____________" << endl;
	for (int i=0;i<rozmiarTabKlasa;i++)
		{
			cout << idKlasy[i] << endl;
		}
	}
}

void Nauczyciele::wyswietlUczniowDanejKlasy(string &wyborKlasy, Uczniowie *tablicaUczniow, int rozmiarTablicy)
{
	int licznik=0;
	cout << endl;
	cout << "---------------------Klasa: " << wyborKlasy << endl<<endl;
	cout << setw(5) << "NR" << setw(15) << "Imie" << setw(15) << "Nazwisko" << setw(15) << "idUcznia" << endl;
	cout << "___________________________________________________" << endl;
	for (int i=0; i < rozmiarTablicy; i++)
	{
		if(wyborKlasy == tablicaUczniow[i].zwroc_idKlasyUcznia())
		{
		licznik++;
		cout << setw(5) << licznik << setw(15) << tablicaUczniow[i].pokaz_Imie() << setw(15) << tablicaUczniow[i].pokaz_Nazwisko() << setw(15) << tablicaUczniow[i].zwroc_id();
		cout << endl;
		}
	}
}

void Nauczyciele::wyswietlOcenyDanejKlasy(Uczniowie *tablicaUczniow, Oceny *tablicaOcen, int rozmiarTablicyUcz, int rozmiarTablicyOce, string &wyborKlasy, bool &czyistnieje)
{
	int licznik=0;
	if(czyistnieje==1)
	{
		cout << endl;
		cout << "--------------PRZEDMIOT: " << zwroc_Przedmiot() << "--------------Klasa: " << wyborKlasy << endl << endl;
		cout << setw(5) << "NR" << setw(15) << "Imie" << setw(15) << "Nazwisko" << setw(15) << "idUcznia" << setw(10) << "Oceny" << endl;
		cout << "_______________________________________________________________________" << endl;
		for (int i=0; i < rozmiarTablicyUcz; i++)
		{
			if(wyborKlasy == tablicaUczniow[i].zwroc_idKlasyUcznia())
			{
			licznik++;
			cout << setw(5) << licznik << setw(15) << tablicaUczniow[i].pokaz_Imie() << setw(15) << tablicaUczniow[i].pokaz_Nazwisko() << setw(15) << tablicaUczniow[i].zwroc_id() << setw(6);
			for (int j=0; j < rozmiarTablicyOce; j++)
			{
				if(tablicaOcen[j].zwroc_idUcz() == tablicaUczniow[i].zwroc_id() and tablicaOcen[j].zwroc_idNau() == zwroc_id())
				{
					if(tablicaOcen[j].zwroc_waga() == 3) { cout << "S" << tablicaOcen[j].zwroc_ocena() << ", ";}
					if(tablicaOcen[j].zwroc_waga() == 2) { cout << "K" << tablicaOcen[j].zwroc_ocena() << ", ";}
					if(tablicaOcen[j].zwroc_waga() == 1) { cout << "O" << tablicaOcen[j].zwroc_ocena() << ", ";}
				}
			}
			cout << endl;
			}
		}
	}
}

void Nauczyciele::wyswietlOcenyKoncowe(Uczniowie *tablicaUczniow, Oceny *tablicaOcen, int rozmiarTablicyUcz, int rozmiarTablicyOce, string &wyborKlasy, bool &czyistnieje)
{
	if(czyistnieje==1)
	{
		int licznik=0;
		cout << endl;
		cout << "--------------PRZEDMIOT: " << zwroc_Przedmiot() << "--------------Klasa: " << wyborKlasy << endl << endl;
		cout << setw(5) << "NR" << setw(15) << " imie" << setw(15) << " nazwisko" << setw(15) << " idUcznia" << setw(15) << " Œrednia" << setw(20) << " Ocena koñcowa" << endl;
		cout << "______________________________________________________________________________________" << endl;
		for (int i=0; i < rozmiarTablicyUcz; i++)
		{
			if(wyborKlasy == tablicaUczniow[i].zwroc_idKlasyUcznia())
			{

				licznik++;

				cout << setw(5) << licznik << setw(15) << tablicaUczniow[i].pokaz_Imie() << setw(15) << tablicaUczniow[i].pokaz_Nazwisko() << setw(15) << tablicaUczniow[i].zwroc_id() << setw(15);


				double ocenyRazyWagi=0;
				double sumaWag= 0;
				double srednia= 0;
				double ocenaKoncowa= 0;

				for (int j=0; j < rozmiarTablicyOce; j++)
				{
					if(tablicaOcen[j].zwroc_idUcz() == tablicaUczniow[i].zwroc_id() and tablicaOcen[j].zwroc_idNau() == zwroc_id())
					{
						int ocena = tablicaOcen[j].zwroc_ocena();
						int waga = tablicaOcen[j].zwroc_waga();
						sumaWag=sumaWag+waga;
						ocenyRazyWagi=ocenyRazyWagi+(ocena*waga);
					}
				}


				if(sumaWag != 0)
				{
					srednia = ocenyRazyWagi/sumaWag;
					ocenaKoncowa = zaokr(srednia);
					cout << srednia << setw(20) << ocenaKoncowa;
				}
				else cout << "Brak ocen!" << setw(20) << 0;
				cout << endl;
			}
		}
	}

}



//destuktor
Nauczyciele::~Nauczyciele()
{

}

string Nauczyciele::pokaz_imie(){
	return imieNauczyciela;
}


string Nauczyciele::pokaz_nazwisko(){
	return nazwiskoNauczyciela;
}

string Nauczyciele::zwroc_id(){
	return idNauczyciela;
}

int Nauczyciele::zwroc_iloscKlas(){
	return rozmiarTabKlasa;
}

string Nauczyciele::zwroc_Przedmiot(){
	return Przedmiot;
}

string Nauczyciele::zwroc_idKlasy(int &index){
	return idKlasy[index];
}


void Nauczyciele::wpisOceny_wyborWagi(int &wyborWagi)
{
	cout << "Wybierz rodzaj oceny (1-3): "<<endl;
	cout << "1. OdpowiedŸ (waga 1)" << endl;
	cout << "2. Kartkowka (waga 2)" << endl;
	cout << "3. Sprawdzian (waga 3)" << endl;
	cout << "Wybor (wpisz 0 by powrocic): ";
	cin >> wyborWagi;
}

void Nauczyciele::wybierzKlase(string &wyborKlasy, Uczniowie *tablicaUczniow, int rozmiarTablicyUczniowie, bool &czyistnieje)
{
	do
	{
		cout << "Wybierz klasê: " << endl << endl;
		wyswietlKlasy();
		cout << endl;
		cout << "Podaj klase (lub wpisz 0 by wyjsc): ";
		cin >> wyborKlasy;
		cout << endl << endl;
		if(wyborKlasy == "0") {czyistnieje=0; break;} //mozliwosc powrotu
		else
		{
			for (int i=0; i < rozmiarTablicyUczniowie; i++) //petla sprwadzajaca czy istnieje klasa wskazana przez u¿ytkownika
			{
				if(wyborKlasy == tablicaUczniow[i].zwroc_idKlasyUcznia())
				{
					czyistnieje = 1; //jesli istnieje flaga ustawiana na 1
				}
			}
			if (czyistnieje == 0) cout << "Nie uczysz w takiej klasie! " << endl;
		}
	}while(czyistnieje!=1);
}

void Nauczyciele::wybierzUcznia(string &wyborUcznia, Uczniowie *tablicaUczniow, int rozmiarTablicy, bool &czyistniejeUczen)
{
	do
	{
		cout << "Podaj idUcznia (lub 0 by wyjsc): ";
		cin >> wyborUcznia;
		if(wyborUcznia == "0") break;
		else
			{
			for (int i=0; i < rozmiarTablicy; i++)
			{
				if(wyborUcznia == tablicaUczniow[i].zwroc_id())
				{
					czyistniejeUczen=1;
				}
			}
		}
	}while(czyistniejeUczen!=1);
}

void Nauczyciele::wybierzOcene(int unsigned &Ocena)
{
do{
	cout << "Podaj ocene: ";
	cin >> Ocena;
	if(Ocena > 6 or Ocena==0)
	{
		cout << "B³¹d! Nie ma takiej oceny! " << endl;
	}
}while(Ocena > 6 or Ocena<=0);
}
