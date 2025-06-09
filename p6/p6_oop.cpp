#include "komplexeZahl.h"
#include <iostream>
#include <stdio.h>

int main(void)
{

    string input;
    string yes = "y";
    string no = "n";
    bool status = false;
    cout << "Moechtest du eine Berechnung von zwei komplexen Zahlen durchfuehren? "
         << yes << " / " << no << endl;
    cin >> input;
    cin.clear();

    if (input == yes)
    {
        status = true;

        while (status == true)
        { // mehrfache Ausführung von Berechnungen möglich
            // Programmstart implementieren

            cout << "Moechtest du erneut eine Berechnung vornehmen? " << yes << " / "
                 << no << endl;
            cin >> input;
            if (input == no)
            {
                status = false;
                cout << "Alles klar, Tschuess!" << endl;
                getchar();
                return (0);
            }
        }
    }
    else if (input == no)
    {
        cout << "Alles klar, Tschuess!" << endl;
        getchar();
        return (0);
    }
    else
    {
        cout << "Keine gueltige Eingabe, starte das Programm erneut." << endl;
        getchar();
        return (0);
    }
}