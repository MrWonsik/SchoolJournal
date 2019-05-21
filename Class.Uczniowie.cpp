#include "main.h"

using namespace std;

Uczniowie::Uczniowie(string idUcznia, string imieUcznia, string nazwiskoUcznia, string idKlasyUcznia)
		{
			this->idUcznia = idUcznia;
			this->imieUcznia = imieUcznia;
			this->nazwiskoUcznia = nazwiskoUcznia;
			this->idKlasyUcznia = idKlasyUcznia;
		}

Uczniowie::Uczniowie(){

}

Uczniowie::~Uczniowie()
{

}

void Uczniowie::wyswietlInfo(){
			cout << "Id: " << idUcznia << endl;
			cout << "Imie: " << imieUcznia << endl;
			cout << "Nazwisko: " << nazwiskoUcznia << endl;
			cout << "Id Klasy: " << idKlasyUcznia << endl;
		}

string Uczniowie::pokaz_Imie(){
	return imieUcznia;
}

string Uczniowie::pokaz_Nazwisko(){
	return nazwiskoUcznia;
}

string Uczniowie::zwroc_id(){
	return idUcznia;
}

string Uczniowie::zwroc_idKlasyUcznia(){
	return idKlasyUcznia;
}

void Uczniowie::wyswietl_Nauczycieli(Nauczyciele *tablica, int rozmiarTablicy){
	int licznik=0;
	cout << setw(5) << " NR " << setw(15) << " Imie " << setw(15) << " Nazwisko " << setw(15) << " Przedmiot " << endl;
	cout << "______________________________________________________________________________________________" << endl;
	for(int i=0; i<rozmiarTablicy; i++)
	{
		for(int j=0; j<tablica[i].zwroc_iloscKlas(); j++)
		{
			if(tablica[i].zwroc_idKlasy(j) == idKlasyUcznia)
			{
				licznik++;
				cout << setw(5) << licznik << setw(15) << tablica[i].pokaz_imie() << setw(15) << tablica[i].pokaz_nazwisko() << setw(15) << tablica[i].zwroc_Przedmiot();
				cout << endl;
			}
		}
	}
}

int Uczniowie::zwroc_LiczbePrzedmiotowUcznia(Nauczyciele *tablica, int rozmiarTablicy)
{
	int iloscPrzedmiotow = 0;
	for(int i=0; i<rozmiarTablicy; i++)
	{
		for(int j=0; j<tablica[i].zwroc_iloscKlas(); j++)
		{
			if(tablica[i].zwroc_idKlasy(j) == zwroc_idKlasyUcznia())
			{
				iloscPrzedmiotow++;
			}
		}
	}
	return iloscPrzedmiotow;
}

void Uczniowie::zwroc_OtrzymaneOceny(Nauczyciele *tabNauczycieliUczacych, Oceny *tablicaZOcenami,int liczbaPrzedmiotow, int rozmiarTablicyOcen)
{
	for(int i=0; i<liczbaPrzedmiotow; i++)
	{
		cout << "-----------------------" << setw(15) << tabNauczycieliUczacych[i].zwroc_Przedmiot() << " (" << tabNauczycieliUczacych[i].pokaz_imie() << " " << tabNauczycieliUczacych[i].pokaz_nazwisko() << "): " ;
		for(int j=0; j<rozmiarTablicyOcen; j++)
		{
			if(tablicaZOcenami[j].zwroc_idNau()==tabNauczycieliUczacych[i].zwroc_id() and tablicaZOcenami[j].zwroc_idUcz()== zwroc_id())
			{
				if(tablicaZOcenami[j].zwroc_waga() == 3) { cout << "S" << tablicaZOcenami[j].zwroc_ocena() << ", ";}
				if(tablicaZOcenami[j].zwroc_waga() == 2) { cout << "K" << tablicaZOcenami[j].zwroc_ocena() << ", ";}
				if(tablicaZOcenami[j].zwroc_waga() == 1) { cout << "O" << tablicaZOcenami[j].zwroc_ocena() << ", ";}
			}
		}
		cout << endl;
	}
}

int Uczniowie::zwroc_LiczbaOcen(Oceny *tablica, int rozmiarTablicy)
{
	int iloscOcen = 0;
	for (int i=0; i<rozmiarTablicy; i++)
	{
		if(zwroc_id() == tablica[i].zwroc_idUcz())
		{
			iloscOcen++;
		}
	}
	return iloscOcen;
}

void Uczniowie::wypelnijTabliceOcenUcznia(Oceny *tablicaWszystkichOcen, Oceny *tablicaOcenUcznia, int rozmiarTablicyWszystkich)
{
	int licznik=0;
	for(int i=0; i<rozmiarTablicyWszystkich;i++)
	{
		if(tablicaWszystkichOcen[i].zwroc_idUcz() == zwroc_id())
		{
			tablicaOcenUcznia[licznik]=tablicaWszystkichOcen[i];
			licznik++;
		}
	}
}

void Uczniowie::wypelnijTabliceNauczycieliUcznia(Nauczyciele *tablicaWszystkichNauczycieli, Nauczyciele *tablicaNauczycieliUcznia, int rozmiarTablicyWszystkich)
{
	int licznik=0;
	for(int i=0; i<rozmiarTablicyWszystkich; i++)
	{
		for(int j=0; j<tablicaWszystkichNauczycieli[i].zwroc_iloscKlas(); j++)
		{
			if(tablicaWszystkichNauczycieli[i].zwroc_idKlasy(j) == zwroc_idKlasyUcznia())
			{

				tablicaNauczycieliUcznia[licznik] = tablicaWszystkichNauczycieli[i];
				licznik++;
			}
		}
	}

}

void Uczniowie::wyliczSredniaOcen(Nauczyciele *tablicaNauczycieliUczacych, Oceny *tablicaZOcenami, int liczbaPrzedmiotow, int iloscOcen)
{
	double ocenyRazyWagi=0;
	double sumaWag=0;
	double srednia=0;
	double ocenaKoncowa=0;
	double sumaWszystkichOcen=0;
	double sredniaWszystkichOcen=0;

	for(int i=0; i<liczbaPrzedmiotow; i++)
	{
		sumaWag=0;
		ocenyRazyWagi=0;
		cout << "-----------------------" << setw(15) << tablicaNauczycieliUczacych[i].zwroc_Przedmiot() << " (" << tablicaNauczycieliUczacych[i].pokaz_imie() << " " << tablicaNauczycieliUczacych[i].pokaz_nazwisko() << "): " ;
		for(int j=0; j<iloscOcen; j++)
		{
			int ocena=tablicaZOcenami[j].zwroc_ocena();
			int waga=tablicaZOcenami[j].zwroc_waga();
			if(tablicaNauczycieliUczacych[i].zwroc_id() == tablicaZOcenami[j].zwroc_idNau())
			{
				sumaWag=sumaWag+waga;
				ocenyRazyWagi=ocenyRazyWagi+(ocena*waga);
			}
		}
		if(sumaWag != 0)
		{
			srednia = ocenyRazyWagi/sumaWag;
			ocenaKoncowa = zaokr(srednia);
			cout << ocenaKoncowa << endl;
			sumaWszystkichOcen=(sumaWszystkichOcen+ocenaKoncowa);
		}
		else
		{
			cout << "Brak ocen!" << endl;
		}
	}
	sredniaWszystkichOcen = sumaWszystkichOcen / liczbaPrzedmiotow;
	cout << endl;
	cout << "Srednia ocen: " << setprecision(3) << sredniaWszystkichOcen;

}

double Uczniowie::zwroc_srOcen(Nauczyciele *tablicaNauczycieliUczacych, Oceny *tablicaZOcenami, int liczbaPrzedmiotow, int iloscOcen)
{
	{
		double ocenyRazyWagi=0;
		double sumaWag=0;
		double srednia=0;
		double ocenaKoncowa=0;
		double sumaWszystkichOcen=0;
		double sredniaWszystkichOcen=0;

		for(int i=0; i<liczbaPrzedmiotow; i++)
		{
			sumaWag=0;
			ocenyRazyWagi=0;
			for(int j=0; j<iloscOcen; j++)
			{
				int ocena=tablicaZOcenami[j].zwroc_ocena();
				int waga=tablicaZOcenami[j].zwroc_waga();
				if(tablicaNauczycieliUczacych[i].zwroc_id() == tablicaZOcenami[j].zwroc_idNau())
				{
					sumaWag=sumaWag+waga;
					ocenyRazyWagi=ocenyRazyWagi+(ocena*waga);
				}
			}
			if(sumaWag != 0)
			{
				srednia = ocenyRazyWagi/sumaWag;
				ocenaKoncowa = zaokr(srednia);
				sumaWszystkichOcen=(sumaWszystkichOcen+ocenaKoncowa);
			}
		}
		sredniaWszystkichOcen = sumaWszystkichOcen / liczbaPrzedmiotow;
		return sredniaWszystkichOcen;
	}
}


void Uczniowie::porownanieZInnymi(double &sredniaOcen, string &klasaUcznia, Uczniowie *tablicaUczniow,
		int rozmiarTabUcz, Nauczyciele *tablicaNauczycieli, int rozmiarTabNau, Oceny *tablicaOcen, int rozmiarTabOce)
{
	int licznikUczniowtejSamejklasy = 0;
	double sumaWszystkichSr=0;
	double sredniaSr =0;

	for(int i=0; i<rozmiarTabUcz ; i++)
	{
		if(tablicaUczniow[i].zwroc_idKlasyUcznia() == klasaUcznia)
		{
			licznikUczniowtejSamejklasy++;
		}
	}

	Uczniowie *taSamaKlasa = new Uczniowie[licznikUczniowtejSamejklasy];

	int licznik =0;
	for(int i=0; i<rozmiarTabUcz; i++)
	{
		if(tablicaUczniow[i].zwroc_idKlasyUcznia() == klasaUcznia)
		{
			taSamaKlasa[licznik] = tablicaUczniow[i];
			licznik++;
		}
	}

	double *srWszystkichUcz = new double[licznikUczniowtejSamejklasy];

	for(int i=0; i<licznikUczniowtejSamejklasy;i++)
	{

		int iloscOcen=0;
		iloscOcen = taSamaKlasa[i].zwroc_LiczbaOcen(tablicaOcen, rozmiarTabOce);
		Oceny *OcenyUcznia = new Oceny[iloscOcen];
		taSamaKlasa[i].wypelnijTabliceOcenUcznia(tablicaOcen, OcenyUcznia, rozmiarTabOce);



		int liczbaPrzedmiotow=0;
		liczbaPrzedmiotow = taSamaKlasa[i].zwroc_LiczbePrzedmiotowUcznia(tablicaNauczycieli,rozmiarTabNau);
		Nauczyciele *NauczycieleUczacy = new Nauczyciele[liczbaPrzedmiotow];
		taSamaKlasa[i].wypelnijTabliceNauczycieliUcznia(tablicaNauczycieli, NauczycieleUczacy, rozmiarTabNau);


		srWszystkichUcz[i] = taSamaKlasa[i].zwroc_srOcen(NauczycieleUczacy,OcenyUcznia,liczbaPrzedmiotow,iloscOcen);
		sumaWszystkichSr=sumaWszystkichSr+srWszystkichUcz[i];
	}
	sredniaSr= sumaWszystkichSr / licznikUczniowtejSamejklasy;
	cout << "Srednia klasy: " << setprecision(3) << sredniaSr << endl;

	double roznica = sredniaOcen - sredniaSr;
	if(roznica > 0 )
	{
		cout << "Poprawiasz srednia klasy! " << endl;
	}
	else
	{
		cout << "Zanizasz srednia klasy!" << endl;
	}

	double odIlulepszy=0;
	for (int i=0; i<licznikUczniowtejSamejklasy;i++)
	{
		if(sredniaOcen > srWszystkichUcz[i])
		{
			odIlulepszy++;
		}
	}

	cout << (odIlulepszy/(licznikUczniowtejSamejklasy-1))*100 << "%  osob ma mniejsza srednia niz TY!" << endl;
	delete [] taSamaKlasa;
	delete [] srWszystkichUcz;
}

double Uczniowie::zwroc_OcenaKoncowa(string Przedmiot, Oceny *tablicaZOcenami, int iloscOcen)
{
	double ocenyRazyWagi=0;
	double sumaWag=0;
	double srednia=0;
	double ocenaKoncowa=0;

		sumaWag=0;
		ocenyRazyWagi=0;
		for(int j=0; j<iloscOcen; j++)
		{
			int ocena=tablicaZOcenami[j].zwroc_ocena();
			int waga=tablicaZOcenami[j].zwroc_waga();
			if(Przedmiot == tablicaZOcenami[j].zwroc_idNau())
			{
				sumaWag=sumaWag+waga;
				ocenyRazyWagi=ocenyRazyWagi+(ocena*waga);
			}
		}
		if(sumaWag != 0)
		{
			srednia = ocenyRazyWagi/sumaWag;
			ocenaKoncowa = zaokr(srednia);
		}
	return ocenaKoncowa;
}

void Uczniowie::najlepsiZPrzedmiotow(int liczbaPrzedmiotow, string &klasaUcznia, Uczniowie *tablicaUczniow,
		int rozmiarTabUcz, Nauczyciele *tablicaNauczycieli, int rozmiarTabNau, Oceny *tablicaOcen, int rozmiarTabOce)
{
	cout << "------------Najlepsi uczniowie z danych przedmiotow: " << endl;
	int licznikUczniowtejSamejklasy = 0;

	for(int i=0; i<rozmiarTabUcz ; i++)
	{
		if(tablicaUczniow[i].zwroc_idKlasyUcznia() == klasaUcznia)
		{
			licznikUczniowtejSamejklasy++;
		}
	}

	Uczniowie *taSamaKlasa = new Uczniowie[licznikUczniowtejSamejklasy];

	int licznik =0;
	for(int i=0; i<rozmiarTabUcz; i++)
	{
		if(tablicaUczniow[i].zwroc_idKlasyUcznia() == klasaUcznia)
		{
			taSamaKlasa[licznik] = tablicaUczniow[i];
			licznik++;
		}
	}

	string *Przedmiot = new string[liczbaPrzedmiotow];
	string *idPrzedmiot = new string[liczbaPrzedmiotow];
	double *srZPrzedmiotu = new double[licznikUczniowtejSamejklasy];

	int licznikPrzedmiotow=0;
	for(int i=0; i<rozmiarTabNau; i++)
	{
		for(int j=0; j<tablicaNauczycieli[i].zwroc_iloscKlas(); j++)
		{
			if(tablicaNauczycieli[i].zwroc_idKlasy(j)==klasaUcznia)
			{
				Przedmiot[licznikPrzedmiotow] = tablicaNauczycieli[i].zwroc_Przedmiot();
				idPrzedmiot[licznikPrzedmiotow] = tablicaNauczycieli[i].zwroc_id();
				licznikPrzedmiotow++;
			}
		}
	}

	for(int j=0; j<liczbaPrzedmiotow; j++)
	{
		cout << Przedmiot[j] << ": ";
		int najwyzszyindex=0;
		double temp=0;
		for(int i=0; i<licznikUczniowtejSamejklasy;i++)
		{
			int iloscOcen=0;
			iloscOcen = taSamaKlasa[i].zwroc_LiczbaOcen(tablicaOcen, rozmiarTabOce);
			Oceny *OcenyUcznia = new Oceny[iloscOcen];
			taSamaKlasa[i].wypelnijTabliceOcenUcznia(tablicaOcen, OcenyUcznia, rozmiarTabOce);

			srZPrzedmiotu[i]=taSamaKlasa[i].zwroc_OcenaKoncowa(idPrzedmiot[j], OcenyUcznia, iloscOcen);

			if(temp < srZPrzedmiotu[i])
			{
				temp=srZPrzedmiotu[i];
				najwyzszyindex=i;
			}
		}
		cout << taSamaKlasa[najwyzszyindex].pokaz_Imie() << " " << taSamaKlasa[najwyzszyindex].pokaz_Nazwisko() << endl;
	}

	delete [] taSamaKlasa;
	delete [] srZPrzedmiotu;
}

