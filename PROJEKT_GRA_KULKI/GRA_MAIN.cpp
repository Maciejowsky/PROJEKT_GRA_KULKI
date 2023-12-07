#include "gui.h"
#include "Gra_deklaracje.h"
#include <string>

string choice;

void korekta3() {
    do {
        cin >> choice;
        if (choice != "1" && choice != "2" && choice != "3")
            cout << "Wpisz jeszcze raz : ";
    } while (choice != "1" && choice != "2" && choice != "3");
}
void korekta4() {
    do {
        cin >> choice;
        if (choice != "1" && choice != "2" && choice != "3" && choice != "4")
            cout << "Wpisz jeszcze raz : ";
    } while (choice != "1" && choice != "2" && choice != "3" && choice != "4");
}

void entry_screen() {
    gui show;
    gra gra;
    do {
        system("cls");
        show.game_info();
        cout << "1 - Wyswietl Instrukcje" << endl;
        cout << "2 - Zacznij Gre" << endl;
        cout << "3 - Tabela Wynikow " << endl;
        cout << "4 - Wyjdz z Gry " << endl;
        korekta4();
        switch (stoi(choice)) {
        case 1:
            system("cls");
            show.instrukcja();
            cout << "1 - wroc do menu" << endl;
            cout << "2 - zacznij gre" << endl;
            cout << "3 - wyjdz z gry" << endl;
            korekta3();
            if (choice == "2") {
                do {
                    gra.playGame();
                    cout << "1 - wroc do menu" << endl;
                    cout << "2 - zagraj jeszcze raz" << endl;
                    cout << "3 - wyjdz z gry" << endl;
                    korekta3();
                } while (choice != "2");
            }
            break;
        case 2:
            system("cls");
            do {
                gra.playGame();
                cout << "1 - wroc do menu" << endl;
                cout << "2 - zagraj jeszcze raz" << endl;
                cout << "3 - wyjdz z gry" << endl;
                korekta3();
            } while (choice == "2");
            break;
        case 3:
            gra.wyswietl_tablica_wynikow();
            cout << "1 - wroc do menu" << endl;
            cout << "2 - zacznij gre" << endl;
            cout << "3 - wyjdz z gry" << endl;
            korekta3();
            if (choice == "2") {
                do {
                    gra.playGame();
                    cout << "1 - wroc do menu" << endl;
                    cout << "2 - zagraj jeszcze raz" << endl;
                    cout << "3 - wyjdz z gry" << endl;
                    korekta3();
                } while (choice == "2");
            }

            break;
        case 4:
            break;

        }
    } while (choice != "4");
}

int main()
{
    entry_screen();
    return 0;
}