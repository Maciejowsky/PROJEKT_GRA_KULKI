#include "Gra_deklaracje.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "windows.h"
#include <conio.h>
#include <iomanip>
#include <thread>
#include <chrono>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int Rozmiar_Planszy = 8;
const char Puste_Pole = '.';

char plansza[Rozmiar_Planszy][Rozmiar_Planszy];
int wynikGracza = 0;
string nazwaGracza;

map<int, int> pointsMap = {
    {5, 10},
    {6, 15},
    {7, 20},
    {8, 30}
};


// Funkcja aktualizuj¹ca wynik gracza na podstawie liczby u³o¿onych kulkek
void gra::zapisz_nick() {
    cout << "Podaj nick" << endl;
    cin >> nazwaGracza;

}
//Funkcja dodajaca punkty do konta garcza
void gra::AktualizujWynikGracza(int count)
{
    wynikGracza += pointsMap[count];
}
//Funkcja do testów wczytuj¹ca ustawienie
void gra::wczytajUstawienie()
{
    for (int y = 0; y < Rozmiar_Planszy - 5; y++)
    {
        for (int x = 0; x < Rozmiar_Planszy - 5; x++)
        {
            plansza[y][x] = 'G';
        }
    }
}

// Funkcja losuj¹ca kulki na planszy
void gra::losujKulki()
{
    char kolory[] = { 'G', 'B', 'R', 'V', 'O' };
    int numkolory = sizeof(kolory) / sizeof(kolory[0]);

    srand(static_cast<unsigned int>(time(nullptr)));

    int count = 0;
    while (count < 3)
    {
        int row = rand() % Rozmiar_Planszy;
        int col = rand() % Rozmiar_Planszy;

        if (plansza[row][col] == Puste_Pole)
        {
            plansza[row][col] = kolory[rand() % numkolory];
            count++;
        }
    }
}

// Funkcja wyœwietlaj¹ca planszê
void gra::wypisz_plansze()
{
    HANDLE hOut;
    for (int i = 0; i < Rozmiar_Planszy + 2; i++)
    {


        for (int j = 0; j < Rozmiar_Planszy + 2; j++)
        {
            if (i == Rozmiar_Planszy && j < Rozmiar_Planszy) {
                cout << "__";
            }
            if (i == Rozmiar_Planszy + 1 && j < Rozmiar_Planszy) {
                cout << j << " ";
            }
            if (j == Rozmiar_Planszy && i < Rozmiar_Planszy) {
                cout << "|";
            }
            if (j == Rozmiar_Planszy + 1 && i < Rozmiar_Planszy) {
                cout << i;
            }


            if (i < Rozmiar_Planszy && j < Rozmiar_Planszy) {
                if (plansza[i][j] == 'G') {
                    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << plansza[i][j] << " ";
                }
                else if (plansza[i][j] == 'B') {
                    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    cout << plansza[i][j] << " ";
                }
                else if (plansza[i][j] == 'R') {
                    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    cout << plansza[i][j] << " ";
                }
                else if (plansza[i][j] == 'V') {
                    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE);
                    cout << plansza[i][j] << " ";
                }
                else if (plansza[i][j] == 'O') {
                    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << plansza[i][j] << " ";
                }
                else {
                    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                    cout << plansza[i][j] << " ";
                }
                hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            }




        }
        cout << '\n';
    }

    cout << '\n';
    cout << "Wynik gracza: " << wynikGracza << '\n';
    cout << '\n';
}

// Funkcja sprawdzaj¹ca, czy jest 5 kulek w rzêdzie
bool gra::sprawdzRzad(int startRow, int startCol, int deltaRow, int deltaCol, int count)
{
    char color = plansza[startRow][startCol];
    for (int i = 1; i < count; ++i)
    {
        int row = startRow + deltaRow * i;
        int col = startCol + deltaCol * i;
        if (row < 0 || row >= Rozmiar_Planszy || col < 0 || col >= Rozmiar_Planszy || plansza[row][col] != color)
        {
            return false;
        }
    }
    return true;
}
//Funkcja usuwajaca kulki
void gra::usunKulki(int startRow, int startCol, int deltaRow, int deltaCol, int count)
{
    
    for (int i = 0; i < count; ++i)
    {
        plansza[startRow + deltaRow * i][startCol + deltaCol * i] = Puste_Pole;
    }
}

bool gra::sprawdz_ile_w_rzedzie()
{
    for (int i = 0; i < Rozmiar_Planszy; ++i)
    {
        for (int j = 0; j < Rozmiar_Planszy; ++j)
        {
            if (plansza[i][j] != Puste_Pole)
            {
                for (int d = Rozmiar_Planszy; d > 4; d--)
                {
                    // Sprawdzanie poziomo
                    if (j + 4 < Rozmiar_Planszy && sprawdzRzad(i, j, 0, 1, d))
                    {
                        usunKulki(i, j, 0, 1, d);
                        AktualizujWynikGracza(d);
                        return true;
                    }
                    // Sprawdzanie pionowo
                    if (i + 4 < Rozmiar_Planszy && sprawdzRzad(i, j, 1, 0, d))
                    {
                        usunKulki(i, j, 1, 0, d);
                        AktualizujWynikGracza(d);
                        return true;
                    }
                    // Sprawdzanie po skosie "/"
                    if (i + 4 < Rozmiar_Planszy && j + 4 < Rozmiar_Planszy && sprawdzRzad(i, j, 1, 1, d))
                    {
                        usunKulki(i, j, 1, 1, d);
                        AktualizujWynikGracza(d);
                        return true;
                    }
                    // Sprawdzanie po skosie "\"
                    if (i + 4 < Rozmiar_Planszy && j - 4 >= 0 && sprawdzRzad(i, j, 1, -1, d))
                    {
                        usunKulki(i, j, 1, -1, d);
                        AktualizujWynikGracza(d);
                        return true;
                    }
                }
            }
        }
    }

    return false;
}



// G³ówna pêtla gry
void gra::playGame()
{
    string nazwa_gracza;
    cout << "Podaj nazwe gracza" << endl;
    cout << " Nazwa gracza : ";
    cin >> nazwa_gracza;
    system("cls");
    for (int i = 0; i < Rozmiar_Planszy; ++i)
    {
        for (int j = 0; j < Rozmiar_Planszy; ++j)
        {
            plansza[i][j] = Puste_Pole;
        }
    }
    //wczytajUstawienie();
    losujKulki();
    wypisz_plansze();

    while (true)
    {

        while (true)
        {
            int startRow, startCol, targetRow, targetCol;
            cout << "Podaj numer wiersza, z ktorego chcesz ruszyc kulke: ";
            cin >> startRow;
            cout << "Podaj numer kolumny, z ktorego chcesz ruszyc kulke: ";
            cin >> startCol;
            cout << "Podaj numer wiersza, na ktory chcesz przelozyc kulke: ";
            cin >> targetRow;
            cout << "Podaj numer kolumny, na ktora chcesz przelozyc kulke: ";
            cin >> targetCol;

            if (startRow >= 0 && startRow < Rozmiar_Planszy &&
                startCol >= 0 && startCol < Rozmiar_Planszy &&
                targetRow >= 0 && targetRow < Rozmiar_Planszy &&
                targetCol >= 0 && targetCol < Rozmiar_Planszy &&
                plansza[startRow][startCol] != Puste_Pole &&
                plansza[targetRow][targetCol] == Puste_Pole)
            {
                swap(plansza[startRow][startCol], plansza[targetRow][targetCol]);
                break;
            }
            else
            {
                cout << "Niepoprawny ruch! Sprobuj ponownie.\n";
            }
        }
        system("cls");
        // Sprawdzenie, czy jest piêæ kulek w rzêdzie
        if (sprawdz_ile_w_rzedzie())
        {
            wypisz_plansze();
            cout << "Udalo sie ulozyc! Dodano punkty do konta gracza!\n";
            Sleep(1000);
            system("cls");
        }

        // Dodanie nowych kulek
        losujKulki();
        wypisz_plansze();

        // Sprawdzenie, czy plansza jest pelna
        bool planszaPelna = true;
        for (int i = 0; i < Rozmiar_Planszy; ++i)
        {
            for (int j = 0; j < Rozmiar_Planszy; ++j)
            {
                if (plansza[i][j] == Puste_Pole)
                {
                    planszaPelna = false;
                    break;
                }
            }
            if (!planszaPelna)
            {
                break;
            }
        }

        if (planszaPelna)
        {
            cout << "Koniec gry! Plansza jest pe³na.\n";
            break;
        }

    }

    cout << "Twój ostateczny wynik: " << wynikGracza << '\n';
    dodaj_Wynik(nazwa_gracza, wynikGracza);

}
//dodanie wyniku gracza do tablicy wynikow
void gra::dodaj_Wynik(const string& nazwa_gracza, int wynik) {
    Gracz gracz(nazwa_gracza, wynik);
    this->tablica_wynikow.push_back(gracz);
}
//wyswietlanie tablicy wynikow
void gra::wyswietl_tablica_wynikow() {
    string tablica =
        " _     _  __   __  __    _  ___   ___   _  __ \n"
        "| | _ | ||  | |  ||  |  | ||   | |   | | ||  |\n"
        "| || || ||  |_|  ||   |_| ||   | |   |_| ||  |\n"
        "|       ||       ||       ||   | |      _||  |\n"
        "|       ||_     _||  _    ||   | |     |_ |  |\n"
        "|   _   |  |   |  | | |   ||   | |    _  ||  |\n"
        "|__| |__|  |___|  |_|  |__||___| |___| |_||__|\n";
    system("cls");
    cout << tablica << endl;
    cout << endl;
    for (const auto& gracz : this->tablica_wynikow) {
        cout << "Gracz: " << gracz.nazwa_gracza << "| Wynik: " << gracz.wynik << endl;
    }
}

