
#include "main.h"


using namespace std;

Oceny::Oceny(string idNauczyciela, string idUcznia, int ocena, int waga, string data)
: idNauczyciela(idNauczyciela), idUcznia(idUcznia), ocena(ocena), waga(waga){
	// TODO Auto-generated constructor stub
	char bufor[ 64 ];
	    time_t czas;
	    time( & czas );
	    tm czasTM = * localtime( & czas );

	    strftime( bufor, sizeof( bufor ), "%x-%H:%M:%S", & czasTM );
	    this->data=bufor;
}


Oceny::~Oceny() {
	// TODO Auto-generated destructor stub
}

void Oceny::wyswietl_ocene(){
	cout << setw(7) << "Ocena" << setw(7) << "Waga" << setw(15) << "Data" << endl;
	cout << setw(7) << ocena << setw(7) << waga << setw(20) << data <<  endl;
}

std::string Oceny::zwroc_idNau(){return idNauczyciela;}
std::string Oceny::zwroc_idUcz(){return idUcznia;}
int Oceny::zwroc_ocena(){return ocena;}
int Oceny::zwroc_waga(){return waga;}
string Oceny::zwroc_data(){return data;}
