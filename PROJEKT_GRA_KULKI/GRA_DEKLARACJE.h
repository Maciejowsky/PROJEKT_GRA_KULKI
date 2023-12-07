#ifndef GAME1
#define GAME1
#include <iostream>
#include "cstdlib"
#include "windows.h"
#include "stdlib.h"
#include "conio.h"
#include "iomanip"
#include "fstream"
#include "vector"
#include "algorithm"
using namespace std;
class gra {
public:

	struct Gracz {
		string nazwa_gracza;
		int wynik;
		Gracz(const string& n_g, int w) : nazwa_gracza(n_g), wynik(w) {}
	};

	vector<Gracz>tablica_wynikow;

	void dodaj_Wynik(const string& nazwa_gracza, int wynik);
	void zapisz_nick();
	void AktualizujWynikGracza(int count);
	void wczytajUstawienie();
	void losujKulki();
	void wypisz_plansze();
	bool sprawdzRzad(int startRow, int startCol, int deltaRow, int deltaCol, int count);
	void usunKulki(int startRow, int startCol, int deltaRow, int deltaCol, int count);
	bool sprawdz_ile_w_rzedzie();
	void playGame();
	void wyswietl_tablica_wynikow();
};

#endif // !GAME


