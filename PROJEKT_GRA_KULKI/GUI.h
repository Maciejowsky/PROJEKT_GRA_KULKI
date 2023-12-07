#ifndef GUI
#define GUI

#include <iostream>
#include "cstdlib"
#include "windows.h"
#include "stdlib.h"
#include "conio.h"
#include "iomanip"
#include <thread>
#include <chrono>

using namespace std;

class gui {

public:

    void game_info();
    void pause_system();
    void instrukcja();
};

void gui::game_info() {
    string intro =
        " ______   ______    _______ \n"
        "|      | |    _ |  |   _   |\n"
        "|    __| |   | ||  |  |_|  |\n"
        "|   | __ |   |_||_ |       |\n"
        "|   ||  ||    __  ||       |\n"
        "|   |_| ||   |  | ||   _   |\n"
        "|_______||___|  |_||__| |__|\n"
        " ___   _  __   __  ___      ___   _  ___ \n"
        "|   | | ||  | |  ||   |    |   | | ||   |\n"
        "|   |_| ||  | |  ||   |    |   |_| ||   |\n"
        "|      _||  |_|  ||   |    |      _||   |\n"
        "|     |_ |       ||   |___ |     |_ |   |\n"
        "|    _  ||       ||       ||    _  ||   |\n"
        "|___| |_||_______||_______||___| |_||___|\n";



    for (const auto c : intro) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(10));
    }
    cout << endl;
}
void gui::pause_system() {
    cout << "Press Enter to continue...";
    while (cin.get() != '\n');
}

void gui::instrukcja() {
    string i1 = "Zasady gry:";
    string i2 = "*Na planszy o rozmiarze 8x8 znajduja sie kolorowe kulki.";
    string i3 = "*Twoim celem jest ulozenie jak najwiekszej liczby kulek tego samego koloru w jednym rzedzie, kolumnie lub na skos.";
    string i4 = "*Po rozpoczeciu gry losowo pojawiaja sie 3 kulki na planszy.";
    string i5 = "*Kolejnym ruchem jest przesuniecie jednej kulki przez gracza na inne miejsce.";
    string i6 = "*Po kazdym ruchu, jesli udalo sie ulozyc 5 lub wiecej kulek tego samego koloru w jednym rzedzie, kolumnie lub na skos, zostana one usuniete, a Ty otrzymasz punkty.";
    string i7 = "*Jesli po ruchu nie uda sie ulozyc 5 kulek, zostana dodane 3 nowe kulki na losowych miejscach.";
    string i8 = "*Gra konczy sie, gdy cala plansza zostanie zapelniona kulkami.";
    string i9 = "*Zdobyte punkty zaleza od liczby ulozonych kulek:";
    string i10 = "* 5 kulek: 10 punktow";
    string i11 = "* 6 kulek: 15 punktow";
    string i12 = "* 7 kulek: 20 punktow";
    string i13 = "* 8 kulek: 40 punktow";

    for (const auto c : i1) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i2) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "G - GREEN ";
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "B - BLUE ";

    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "R - RED ";

    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE);
    cout << "V - Violet ";

    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Y - YELLOW " << endl << endl;

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    for (const auto c : i3) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i4) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i5) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i6) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i7) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i8) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i9) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i10) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i11) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i12) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
    for (const auto c : i13) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;

}



#endif // !GUI


