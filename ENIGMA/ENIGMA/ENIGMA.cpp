#include <iostream>

using namespace std;

struct Rotor{
	int* alfabet;
	int* alfabet_odwrotny;
	int* notche;
	int ilosc_notchy = 0;
	int pozycja = 1;
	bool czy_moze_sie_obracac = false;
};
struct Reflektor {
	int* alfabet;
};

void wczytaj_rotory(Rotor* rotory,int wielkosc_alfabetu,int ilosc_rotorow) {
	int i, j, numer_litery;
	for (j = 0; j < ilosc_rotorow; j++) {
		int* tablica_z_alfabetem = new int[wielkosc_alfabetu];
		int* tablica_z_alfabetem_odwrotnym = new int[wielkosc_alfabetu];
		for (i = 0, numer_litery = 1; i < wielkosc_alfabetu; i++, numer_litery++) {
			int wczytana_litera;
			cin >> wczytana_litera;
			tablica_z_alfabetem[i] = wczytana_litera - numer_litery;
			tablica_z_alfabetem_odwrotnym[wczytana_litera-1] = i - wczytana_litera + 1 ;
		}
		rotory[j].alfabet = tablica_z_alfabetem;
		rotory[j].alfabet_odwrotny = tablica_z_alfabetem_odwrotnym;
		cin >> rotory[j].ilosc_notchy;

		if (rotory[j].ilosc_notchy != 0) {
			int* tablica_z_notchami = new int[rotory[j].ilosc_notchy];
			for (i = 0; i < rotory[j].ilosc_notchy; i++) {
				cin >> tablica_z_notchami[i];
			}

			rotory[j].notche = tablica_z_notchami;
		}
		
	}
}
void wczytaj_reflektory(Reflektor* reflektory, int wielkosc_alfabetu, int ilosc_reflektorow) {
	int i, j, numer_litery;
	for (j = 0; j < ilosc_reflektorow; j++) {
		int* tablica_z_alfabetem = new int[wielkosc_alfabetu];
		for (i = 0, numer_litery = 1; i < wielkosc_alfabetu; i++, numer_litery++) {
			int wczytana_litera;
			cin >> wczytana_litera;
			tablica_z_alfabetem[i] = wczytana_litera - numer_litery;
		}
		reflektory[j].alfabet = tablica_z_alfabetem;
	}
}

void wczytaj_rotory_do_wiadomosci(Rotor* rotory,Rotor* rotory_w_wiadomosci, int ilosc_rotorow_w_wiadomosci) {
	int numer_indeksu_rotora, pozycja_poczatkowa;
	for (int i = 0; i < ilosc_rotorow_w_wiadomosci; i++) {
		
		cin >> numer_indeksu_rotora;

		rotory_w_wiadomosci[i] = rotory[numer_indeksu_rotora];


		cin >> pozycja_poczatkowa;
		rotory_w_wiadomosci[i].pozycja = pozycja_poczatkowa;
	}
	
}

bool pozycja_notcha(Rotor rotor, int wielkosc_alfabetu) {
	for (int i = 0; i < rotor.ilosc_notchy; i++) {
		int pomocnicza = rotor.notche[i] - 1;
		if (pomocnicza == 0) pomocnicza = wielkosc_alfabetu;
		if ((pomocnicza) == rotor.pozycja) return true;
	}
	return false;
}


void obrot_rotorow(Rotor* rotory_w_wiadomosci,int ilosc_rotorow_w_wiadomosci, int wielkosc_alfabetu) {
	if (ilosc_rotorow_w_wiadomosci == 1) {
		rotory_w_wiadomosci[0].pozycja = (rotory_w_wiadomosci[0].pozycja + 1) % (wielkosc_alfabetu + 1);
		if (rotory_w_wiadomosci[0].pozycja == 0) rotory_w_wiadomosci[0].pozycja++;
	}
	else if (ilosc_rotorow_w_wiadomosci == 2) {
		if (pozycja_notcha(rotory_w_wiadomosci[0], wielkosc_alfabetu) && rotory_w_wiadomosci[1].czy_moze_sie_obracac) {
			rotory_w_wiadomosci[1].pozycja = (rotory_w_wiadomosci[1].pozycja + 1) % (wielkosc_alfabetu + 1);
			if (rotory_w_wiadomosci[1].pozycja == 0) rotory_w_wiadomosci[1].pozycja++;
		}
		rotory_w_wiadomosci[0].pozycja = (rotory_w_wiadomosci[0].pozycja + 1) % (wielkosc_alfabetu + 1);
		if (rotory_w_wiadomosci[0].pozycja == 0) rotory_w_wiadomosci[0].pozycja++;

		rotory_w_wiadomosci[1].czy_moze_sie_obracac = true;
		
	}
	else if (ilosc_rotorow_w_wiadomosci > 2) {
		int pomocnicza = 1;
		
		if (pozycja_notcha(rotory_w_wiadomosci[1], wielkosc_alfabetu) && rotory_w_wiadomosci[2].czy_moze_sie_obracac) {
			rotory_w_wiadomosci[2].pozycja = (rotory_w_wiadomosci[2].pozycja + 1) % (wielkosc_alfabetu + 1);
			if (rotory_w_wiadomosci[2].pozycja == 0) rotory_w_wiadomosci[2].pozycja++;
			rotory_w_wiadomosci[1].pozycja = (rotory_w_wiadomosci[1].pozycja + 1) % (wielkosc_alfabetu + 1);
			if (rotory_w_wiadomosci[1].pozycja == 0) rotory_w_wiadomosci[1].pozycja++;
			pomocnicza = 0;

		}
		if (pozycja_notcha(rotory_w_wiadomosci[0], wielkosc_alfabetu) && rotory_w_wiadomosci[1].czy_moze_sie_obracac) {
			if(pomocnicza == 1){
				rotory_w_wiadomosci[1].pozycja = (rotory_w_wiadomosci[1].pozycja + 1) % (wielkosc_alfabetu + 1);
				if (rotory_w_wiadomosci[1].pozycja == 0) rotory_w_wiadomosci[1].pozycja++;
			}
			
			rotory_w_wiadomosci[2].czy_moze_sie_obracac = true;
		}

		rotory_w_wiadomosci[0].pozycja = (rotory_w_wiadomosci[0].pozycja + 1) % (wielkosc_alfabetu + 1);
		if (rotory_w_wiadomosci[0].pozycja == 0) rotory_w_wiadomosci[0].pozycja++;

		rotory_w_wiadomosci[1].czy_moze_sie_obracac = true;
	}
	
}

int kodowanie(Rotor rotor, int wielkosc_alfabetu, int wczytywana_litera) {
	wczytywana_litera += rotor.alfabet[((rotor.pozycja - 1) + (wczytywana_litera - 1)) % wielkosc_alfabetu];
	if (wczytywana_litera < 1) wczytywana_litera = wielkosc_alfabetu + wczytywana_litera;
	else if (wczytywana_litera > wielkosc_alfabetu) wczytywana_litera -= wielkosc_alfabetu;
		return wczytywana_litera;
}
int odwracanie(Reflektor reflektor, int kodowana_litera) {
	kodowana_litera += reflektor.alfabet[kodowana_litera-1];
	return kodowana_litera;
}
int odwrotne_kodowanie(Rotor rotor, int wielkosc_alfabetu, int wczytywana_litera) {
	wczytywana_litera += rotor.alfabet_odwrotny[((rotor.pozycja - 1) + (wczytywana_litera - 1)) % wielkosc_alfabetu];
	if (wczytywana_litera < 1) wczytywana_litera = wielkosc_alfabetu + wczytywana_litera;
	else if (wczytywana_litera > wielkosc_alfabetu) wczytywana_litera -= wielkosc_alfabetu;
	return wczytywana_litera;
}

int kodowanie_litery(Rotor* rotory_w_wiadomosci,int ilosc_rotorow_w_wiadomosci,Reflektor* reflektory, int indeks_reflektora, int wczytywana_litera, int wielkosc_alfabetu) {
	int i, kodowana_litera = wczytywana_litera;
	obrot_rotorow(rotory_w_wiadomosci, ilosc_rotorow_w_wiadomosci, wielkosc_alfabetu);
	for (i = 0; i < ilosc_rotorow_w_wiadomosci; i++) {
		kodowana_litera = kodowanie(rotory_w_wiadomosci[i], wielkosc_alfabetu, kodowana_litera);
	}

	kodowana_litera = odwracanie(reflektory[indeks_reflektora], kodowana_litera);

	for (i--; i >= 0; i--) {
		kodowana_litera = odwrotne_kodowanie(rotory_w_wiadomosci[i], wielkosc_alfabetu, kodowana_litera);
	}

	return kodowana_litera;
}

int main()
{
	int wielkosc_alfabetu, ilosc_rotorow, i, ilosc_wiadomosci, ilosc_reflektorow;

	cin >> wielkosc_alfabetu >> ilosc_rotorow;

	Rotor* rotory = new Rotor[ilosc_rotorow];

	wczytaj_rotory(rotory, wielkosc_alfabetu, ilosc_rotorow);
	
	cin >> ilosc_reflektorow;
	Reflektor* reflektory = new Reflektor[ilosc_reflektorow];
	wczytaj_reflektory(reflektory, wielkosc_alfabetu, ilosc_reflektorow);

	for (i = 0; i < ilosc_reflektorow; i++) {
	}

	cin >> ilosc_wiadomosci;

	for (i = 0; i < ilosc_wiadomosci; i++) {
		int ilosc_rotorow_w_wiadomosci, indeks_reflektora, wczytywana_litera = 1;
		cin >> ilosc_rotorow_w_wiadomosci;
		Rotor* rotory_w_wiadomosci = new Rotor[ilosc_rotorow_w_wiadomosci];

		wczytaj_rotory_do_wiadomosci(rotory, rotory_w_wiadomosci, ilosc_rotorow_w_wiadomosci);
		
		cin >> indeks_reflektora;
		while (wczytywana_litera != 0) {
			scanf_s("%i", &wczytywana_litera);
				if(wczytywana_litera != 0) {
					int kodowana = kodowanie_litery(rotory_w_wiadomosci, ilosc_rotorow_w_wiadomosci, reflektory, indeks_reflektora, wczytywana_litera, wielkosc_alfabetu);
					printf("%i ", kodowana);
					//cout << kodowana << " ";
				}
		}
		printf(" ");
		delete[] rotory_w_wiadomosci;
	}
	delete[] rotory;
	delete[] reflektory;
}

