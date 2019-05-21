#include "main.h"


using namespace std;

double zaokr(double &srednia)
{
	double ocenaKoncowa=0;
	if(srednia < 2)
	{
		ocenaKoncowa = 1;
	}
	else if(srednia >= 2 and srednia <= 2.25)
	{
		ocenaKoncowa = 2;
	}
	else if (srednia > 2.25 and srednia <= 2.75)
	{
		ocenaKoncowa = 2.5;
	}
	else if (srednia > 2.75 and srednia <= 3.25)
	{
		ocenaKoncowa = 3;
	}
	else if (srednia > 3.25 and srednia <= 3.75)
	{
		ocenaKoncowa = 3.5;
	}
	else if (srednia > 3.75 and srednia <= 4.25)
	{
		ocenaKoncowa = 4;
	}
	else if (srednia > 4.25 and srednia <= 4.75)
	{
		ocenaKoncowa = 4.5;
	}
	else if (srednia > 4.75 and srednia <= 5.5)
	{
		ocenaKoncowa = 5;
	}
	else if (srednia > 5.5)
	{
		ocenaKoncowa = 6;
	}
	return ocenaKoncowa;
}


//funkcja przyjmuje jako argumenty orygina³ - wskaŸniki wskazuj¹ce na tablicê z uczniami, nauczycielami, ocneami oraz ich rozmiary
void Menu(Uczniowie *tabUcz, Nauczyciele *tabNau, Oceny *tabOce, int rozmNau, int rozmUcz, int rozmOce){

	int wybor;

	//menu wywo³ywane w pêtli, a¿ wybor nie bêdzie równy 2
	do
	{
		cout << "-------------------------------------MENU!"<<endl;
		cout << "1. Zaloguj"<<endl;
		cout << "2. WyjdŸ" << endl;
		cout << "Twoj wybor: "; cin >> wybor;

			//Pierwsza petla g³ownego MENU (Obejmuje cala funkcje void Menu)
			switch(wybor)
			{
				case 1: {
						int wybor2;
						cout << endl << endl;
						cout << "-------------------------------------ZALOGUJ" << endl;
						cout << "1. Uczen" << endl;
						cout << "2. Nauczyciel" << endl;
						cout << "Twój wybór: ";
						cin >> wybor2;
						cout << endl << endl;
						string login;
						//jeœli uczeñ to to
						if(wybor2 == 1)
						{
							cout << "Podaj login: ";
							cin >> login;
							cout << endl << endl;

							//Do tymczasowy wskaŸnik klasy Uczniowie wpisywany jest element z tablicy Uczniów do przechowywania zalogowanej osoby
							Uczniowie *zalogowany = nullptr;
							cout << "!==============================Tworze obiekt klasy Uczniowie: zalogowany" << endl;


							//petla z warunkiem sprawdzaj¹cym czy podany przez u¿ytkownika login pojawia siê w tablicy
							for(int i=0; i<rozmUcz; i++)
							{
								if(login == tabUcz[i].zwroc_id())
								{
									zalogowany = &tabUcz[i];
								}
							}
								if(zalogowany != nullptr)
								{
									int wybor3=0;
									do{
										cout << "-------------------------------------Zalogowany jako " << zalogowany->pokaz_Imie() << " " << zalogowany->pokaz_Nazwisko();
										cout << endl;
										cout << "1. Zobacz swoje oceny"<<endl;
										cout << "2. Zobacz swoich nauczycieli" << endl;
										cout << "3. Oceny koncowe" << endl;
										cout << "4. Porownanie z rowiesnikami"<< endl;
										cout << "5. Wyloguj " << endl;
										cout<<"Wybierz: ";
										cin >> wybor3;
										cout << endl << endl;


										if (wybor3 == 1)
										{

											int liczbaPrzedmiotow=0;
											cout << "!==============================Zliczam liczbê przedmiotów Ucznia" << endl;
											liczbaPrzedmiotow = zalogowany->zwroc_LiczbePrzedmiotowUcznia(tabNau,rozmNau);
											cout << "!==============================Tworze tablice obiektow klasy Nauczyciele: NauczycieleUczacy" << endl;
											Nauczyciele *NauczycieleUczacy = new Nauczyciele[liczbaPrzedmiotow];
											cout << "!==============================Uzupelniam tablice obiektow klasy Nauczyciele NauczycieleUczacy" << endl;
											cout << endl << endl;
											cout << "-------------------------------------Moje oceny: " << endl;
											zalogowany->wypelnijTabliceNauczycieliUcznia(tabNau, NauczycieleUczacy, rozmNau);


											zalogowany->zwroc_OtrzymaneOceny(NauczycieleUczacy, tabOce, liczbaPrzedmiotow, rozmOce);
											string kontynuacja;
											do
											{
												cout << "Aby powrocic do menu glownego wpisz 0: ";
												cin >> kontynuacja;
											}while (kontynuacja != "0");

											cout << endl << endl;
											cout << "!==============================Usuwam tablice obiektow klasy Nauczyciele: NauczycieleUczacy" << endl;
											delete [] NauczycieleUczacy;
										}

										else if (wybor3 == 2)
										{
											cout << "-------------------------------------Nauczyciele którzy mnie ucz¹: "<<endl;
											zalogowany->wyswietl_Nauczycieli(tabNau,rozmNau);

											string kontynuacja;
											do
											{
												cout << "Aby powrocic do menu glownego wpisz 0: ";
												cin >> kontynuacja;
											}while (kontynuacja != "0");

											cout <<endl << endl;
										}

										else if (wybor3 == 3)
										{

											int iloscOcen=0;
											iloscOcen = zalogowany->zwroc_LiczbaOcen(tabOce, rozmOce);
											cout << "!==============================Tworze tablice obiektow klasy Oceny: OcenyUcznia" << endl;
											Oceny *OcenyUcznia = new Oceny[iloscOcen];
											cout << "!==============================Uzupelniam tablice OcenyUcznia" << endl;
											zalogowany->wypelnijTabliceOcenUcznia(tabOce, OcenyUcznia, rozmOce);



											int liczbaPrzedmiotow=0;
											liczbaPrzedmiotow = zalogowany->zwroc_LiczbePrzedmiotowUcznia(tabNau,rozmNau);
											cout << "!==============================Tworze tablice obiektow klasy Nauczyciele: NauczycieleUczacy" << endl;
											Nauczyciele *NauczycieleUczacy = new Nauczyciele[liczbaPrzedmiotow];
											cout << "!==============================Uzupelniam tablice NauczycieleUczacy" << endl;
											zalogowany->wypelnijTabliceNauczycieliUcznia(tabNau, NauczycieleUczacy, rozmNau);
											cout << "!==============================Licze srednia z ocen..." << endl << endl;
											cout << "-------------------------------------Œrednia ocen/Oceny koñcowe"<<endl;
											zalogowany->wyliczSredniaOcen(NauczycieleUczacy, OcenyUcznia, liczbaPrzedmiotow, iloscOcen);
											cout << endl;

											string kontynuacja;
											do
											{
												cout << "Aby powrocic do menu glownego wpisz 0: ";
												cin >> kontynuacja;
											}while (kontynuacja != "0");


											cout << "!==============================Usuwam tablice obiektow NauczycieleUczacy oraz OcenyUcznia" << endl;
											delete [] NauczycieleUczacy;
											delete [] OcenyUcznia;
										}

										else if (wybor3 == 4)
										{

											int iloscOcen=0;
											iloscOcen = zalogowany->zwroc_LiczbaOcen(tabOce, rozmOce);
											cout << "!==============================Tworze tablice obiektow klasy Oceny: OcenyUcznia" << endl;
											Oceny *OcenyUcznia = new Oceny[iloscOcen];
											cout << "!==============================Uzupelniam tablice OcenyUcznia" << endl;
											zalogowany->wypelnijTabliceOcenUcznia(tabOce, OcenyUcznia, rozmOce);



											int liczbaPrzedmiotow=0;
											liczbaPrzedmiotow = zalogowany->zwroc_LiczbePrzedmiotowUcznia(tabNau,rozmNau);
											cout << "!==============================Tworze tablice obiektow klasy Nauczyciele: NauczycieleUczacy" << endl;
											Nauczyciele *NauczycieleUczacy = new Nauczyciele[liczbaPrzedmiotow];
											cout << "!==============================Uzupelniam tablice NauczycieleUczacy" << endl;
											zalogowany->wypelnijTabliceNauczycieliUcznia(tabNau, NauczycieleUczacy, rozmNau);
											cout << "!==============================Licze srednia z ocen..." << endl << endl;
											double sredniaOcen = zalogowany->zwroc_srOcen(NauczycieleUczacy,OcenyUcznia,liczbaPrzedmiotow,iloscOcen);
											cout << "Twoja srednia ocen: " << setprecision(3) << sredniaOcen << endl;

											string klasaUcznia = zalogowany->zwroc_idKlasyUcznia();

											cout << "!==============================Licze srednia ocen dla calej klasy..."<<endl;
											zalogowany->porownanieZInnymi(sredniaOcen, klasaUcznia, tabUcz, rozmUcz, tabNau, rozmNau, tabOce, rozmOce);
											cout << endl << endl;
											zalogowany->najlepsiZPrzedmiotow(liczbaPrzedmiotow, klasaUcznia,  tabUcz, rozmUcz, tabNau, rozmNau, tabOce, rozmOce);
											cout << endl;
											string kontynuacja;
											do
											{
												cout << "Aby powrocic do menu glownego wpisz 0: ";
												cin >> kontynuacja;
											}while (kontynuacja != "0");


											cout << "!==============================Usuwam tablice obiektow NauczycieleUczacy oraz OcenyUcznia" << endl;
											delete [] NauczycieleUczacy;
											delete [] OcenyUcznia;
										}
										else if(wybor3 == 5)
										{
											delete zalogowany;
											cout << "!==============================Usuwam obiekt klasy Uczniowie: zalogowany" << endl;
											cout << "Wylogowano!" << endl << endl << endl;
										}
									}while(wybor3 != 5);
								}else
								{
									cout << "Niepoprawny login! " << endl;
								}
						}

						//jesli chce sie zalogowac jako nauczyciel
						else if(wybor2 == 2)
						{

							cout << "Podaj login: ";
							cin >> login;
							cout << endl << endl;

							//Do tymczasowego wskaŸnik klasy Nauczyciele wpisywany jest element z tablicy Nauczycieli do przechowywania zalogowanej osoby
							Nauczyciele *zalogowany = nullptr;
							cout << "!==============================Tworze obiekt klasy Nauczyciele: zalogowany" << endl;

							for(int i=0; i<rozmNau; i++) //petla z warunkiem sprawdzaj¹cym czy podany przez u¿ytkownika login pojawia siê w tablicy
							{
								if(login == tabNau[i].zwroc_id())
								{
									zalogowany = &tabNau[i];
								}
							}
							if(zalogowany != nullptr)
							{

								int wybor3=0; //wybor do interfejsu po zalogowaniu


								do{ //wyswietlany w petli interfejs nauczyciela a¿ do wylogowania
									cout << endl;
									cout << "-------------------------------------Zalogowany jako " << zalogowany->pokaz_imie() << " " << zalogowany->pokaz_nazwisko();
									cout << endl;
									cout << "1. Wpisz ocene"<<endl;
									cout << "2. Zobacz oceny" << endl;
									cout << "3. Œrednia ocen/Oceny koñcowe" << endl;
									cout << "4. Sprawdz swoich uczniow" << endl;
									cout << "5. Moje klasy"<< endl;
									cout << "6. Wyloguj " << endl;
									cout<<"Wybierz: ";
									cin >> wybor3;
									cout << endl << endl;

									if(wybor3 == 1)
									{
										cout << "-------------------------------------Wpisz ocene"<<endl;

										string idNau=zalogowany->zwroc_id(); //idNauczyciela do utworzenia obiektu Oceny;

										string czyWyjsc = "0";


										int wyborWagi; //Waga Oceny
										zalogowany->wpisOceny_wyborWagi(wyborWagi);
										cout << endl << endl;


										if(wyborWagi != 0) //kazdorazowe przejscie menu pozwala na powrot
										{
											bool czyistnieje=0;
											string wyborKlasy;
											zalogowany->wybierzKlase(wyborKlasy, tabUcz, rozmUcz, czyistnieje);

											do
											{

												if(czyistnieje==1)
												{
													zalogowany->wyswietlUczniowDanejKlasy(wyborKlasy, tabUcz, rozmUcz);
													cout << endl << endl;

													string wyborUcznia; //idUcznia
													bool czyistniejeUczen=0; //jw.
													zalogowany->wybierzUcznia(wyborUcznia, tabUcz, rozmUcz, czyistniejeUczen);

													int unsigned Ocena; //Ocena (nie ujemna, sprawdzana nastepnie warunkiem czy wieksza niz 6)

													if(czyistniejeUczen==1)
													{
														zalogowany->wybierzOcene(Ocena);
														cout << "!==============================Tworze tablice obiektow klasy Oceny: nowa" << endl;
														Oceny *nowa = new Oceny(idNau, wyborUcznia, Ocena, wyborWagi);



														char decyzja;

														nowa->wyswietl_ocene();
														cout << "Czy zapisac? (y/n) ";
														cin >> decyzja;

														if (decyzja == 'y')
														{

															Oceny *tabOceBuff = new Oceny[rozmOce]; //bufor na stara tablice
															for (int i=0; i<rozmOce; i++)
															{
																tabOceBuff[i]=tabOce[i]; //przypisanie tablicy do bufora w petli
															}
															tabOce = new Oceny[rozmOce+1]; //powiekszenie tablicy z ocenami o jeden
															for(int i=0; i<rozmOce; i++)
															{
																tabOce[i]=tabOceBuff[i]; //wpisanie z powrotem do tablicy z bufora
															}
															tabOce[rozmOce]=*nowa; //powstawienie nowej wartosci do tablicy wiekszej o jeden
															delete [] tabOceBuff; //usuniecie tablicy buforowej
															rozmOce++; //zwieksznie rozmOce o jeden

															odczytywanieDanych PlikOcen("Oceny.txt", "app"); //obiekt otwierajacy plik do zapisu
															PlikOcen.zapisDanychDoPliku(nowa); //funkcja zapisujaca ocene do pliku
															cout << "Ocena zosta³a zapisana!" << endl; //informacja o zapisie

														}
														else if (decyzja == 'n')
														{
															cout << "Ocena nie zostala zapisana!" << endl;
														}
														cout << "!==============================Usuwam obiekt klasy Oceny: nowa" << endl;
														delete nowa;
													}
												}else cout << "Nie uczysz w takiej klasie!" << endl;
												cout << "Aby powrocic do wyboru ucznia wpisz 1, by wyjsc do menu wpisz 0: ";
												cin >> czyWyjsc;
											}while(czyWyjsc != "0");

										}

									}

									else if(wybor3 == 2){
										cout << "-------------------------------------Zobacz oceny"<<endl;
										bool czyistnieje = 0;
										string wyborKlasy;
										string kontynuacja="0";
										do
										{
										zalogowany->wybierzKlase(wyborKlasy, tabUcz, rozmUcz, czyistnieje);
										if(czyistnieje!=0)
										{
										zalogowany->wyswietlOcenyDanejKlasy(tabUcz, tabOce, rozmUcz, rozmOce, wyborKlasy, czyistnieje);
										}
										else if (wyborKlasy == "0")
										{
											;
										}
										else{ cout << "Nie uczysz w tej klasie!" << endl;}
										cout << endl << "Aby powrocic do wyboru klasy wpisz 1, by wrocic do glownego menu wpisz 0: " ;
										cin >> kontynuacja;
										}while(kontynuacja != "0");
										cout << endl << endl;
									}
									else if(wybor3 == 3){
										cout << "-------------------------------------Œrednia ocen/Oceny koñcowe"<<endl<<endl;
										bool czyistnieje = 0;
										string kontynuacja = "0";
										string wyborKlasy;
										do{
										zalogowany->wybierzKlase(wyborKlasy, tabUcz, rozmUcz, czyistnieje);
										if(czyistnieje!=0)
										{
										zalogowany->wyswietlOcenyKoncowe(tabUcz, tabOce, rozmUcz, rozmOce, wyborKlasy, czyistnieje);
										}
										else if(wyborKlasy == "0")
										{
											;
										}
										else{ cout << "Nie uczysz w tej klasie!" << endl;}
										cout << endl << "Aby powrocic do wyboru klasy wpisz 1, by wrocic do glownego menu wpisz 0: " ;
										cin >> kontynuacja;
										}while(kontynuacja != "0");
										cout << endl << endl;
									}



									//wyswietla uczniow nalezacych do danej klasy - wskazanej przez uzytkownika
									else if(wybor3 == 4)
									{
											cout << "-------------------------------------Sprawdz swoich uczniow" << endl;
											string wyborKlasy;
											bool czyistnieje=0;
											string kontynuacja="0";
											do{
											zalogowany->wybierzKlase(wyborKlasy, tabUcz, rozmUcz, czyistnieje);

											if(czyistnieje != 0)
											{
												zalogowany->wyswietlUczniowDanejKlasy(wyborKlasy, tabUcz, rozmUcz);
											}
											else if(wyborKlasy == "0"){;}
											else{ cout << "Nie uczysz w tej klasie!" << endl;}
											cout << endl << "Aby powrocic do wyboru klasy wpisz 1, by wrocic do glownego menu wpisz 0: " ;
											cin >> kontynuacja;
											}while(kontynuacja != "0");
											cout << endl << endl;
									}

									//wyswietla przedmiot oraz klasy w ktorych uczy aktualnie zalogowany obiekt
									else if(wybor3 == 5){
										string kontynuacja;
										cout << "-------------------------------------Moje klasy" << endl;
										cout << "Uczysz: " << zalogowany->zwroc_Przedmiot() << endl;
										cout << "W klasach: " << endl<<endl;
										zalogowany->wyswietlKlasy();

										do
										{
											cout << "Wpisz 0 by wrocic do glownego menu: ";
											cin >> kontynuacja;
										}while(kontynuacja != "0");
										cout << endl << endl;
										}

									//usuwa obiekt aktualnie zalogowany (w celu zwolnienia pamiêci)
									else if(wybor3 == 6)
									{
									delete zalogowany;
									cout << "!==============================Usuwam obiekt Zalogowany" << endl;
									cout << "Wylogowano!" << endl << endl << endl;
									}
									}while(wybor3 != 6);
								}
								else
								{
									cout << "Niepoprawny login! " << endl;
								}
						}
						else {cout << "Niepoprawny wybor"<<endl; break;}

					}break;

				case 2: cout << "Konczenie pracy... " << endl; break;
				default: {cout << "Zgubiles sie?" << endl << endl; break;}
			};
	}while(wybor != 2);
};


int main(int argc, char *argv[]){
	int rozmiarTablicyNauczyciele=0;
	int rozmiarTablicyUczniowie=0;
	int rozmiarTablicyOceny=0;



	odczytywanieDanych PlikNauczycieli("Nauczyciele.txt", "in");

	//do zmiennej ponizej wstawiana jest ilosc wierszy zczytana z pliku Nauczyciele.txt
	rozmiarTablicyNauczyciele = PlikNauczycieli.zliczenieLiczbyWierszy(rozmiarTablicyNauczyciele);

	//alokacja pamiêci typu Nauczyciele, na podstawie liczby wystapieñ wierszy w pliku
	Nauczyciele* tablicaNauczycieli = new Nauczyciele[rozmiarTablicyNauczyciele];

	odczytywanieDanych PlikUczniowie("Uczniowie.txt", "in");
	rozmiarTablicyUczniowie = PlikUczniowie.zliczenieLiczbyWierszy(rozmiarTablicyUczniowie);
	Uczniowie* tablicaUczniow = new Uczniowie[rozmiarTablicyUczniowie];

	odczytywanieDanych PlikOcen("Oceny.txt", "in");
	rozmiarTablicyOceny = PlikOcen.zliczenieLiczbyWierszy(rozmiarTablicyOceny);
	Oceny *tablicaOcen= new Oceny[rozmiarTablicyOceny];


	//petla która wpisuje do tablicy nauczycieli kolejnych obiekty odczytywane z pliku;
	for (int i=0; i<rozmiarTablicyNauczyciele;i++)
	{

		tablicaNauczycieli[i] = PlikNauczycieli.ZapisDanychDoTablicyNauczyciele();
	}

	//jw.
	for (int i=0; i<rozmiarTablicyUczniowie;i++)
	{
		tablicaUczniow[i] = PlikUczniowie.ZapisDanychDoTablicyUczniowie();
	}

	for (int i=0; i<rozmiarTablicyOceny;i++)
	{
		tablicaOcen[i] = PlikOcen.ZapisDanychDoTablicyOcen();
	}

	Menu(tablicaUczniow, tablicaNauczycieli, tablicaOcen, rozmiarTablicyNauczyciele, rozmiarTablicyUczniowie, rozmiarTablicyOceny);


	//po zakoñczeniu programu tablice uczniów i nauczycieli s¹ usuwane
	cout << "!==============================Usuwam tablice: tablicaOcen, tablicaUczniow, tablicaNauczycieli..."<< endl;
	delete [] tablicaNauczycieli;
	delete [] tablicaUczniow;
	delete [] tablicaOcen;
}
