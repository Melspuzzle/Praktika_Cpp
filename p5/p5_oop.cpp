#include "taschenrechner.h"
#include <iostream>
#include <stdio.h>
using namespace std;
#include <string>
#include <iomanip> // fuer setprecision(2)

void calculator(string input);
bool checkIfFloat(string *p_input);

int main(void)
{
  string input;
  string yes = "y";
  string no = "n";
  bool status = false;
  cout << "Dies ist ein Taschenrechner, moechtest du eine Berechnung vornehmen? "
       << yes << " / " << no << endl;
  cin >> input;
  cin.clear();

  if (input == yes)
  {
    status = true;

    while (status == true)
    { // mehrfache Ausführung von Berechnungen möglich

      calculator(input);
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
void calculator(string input)
{
  // initialisiere Objekt
  taschenrechner KonsolenTaschenrechner;
  float number1 = 0, number2 = 0, result = 0;
  string calculate, calcMethode, message;
  string *p_input = &input;
  cout << "Gebe die erste Zahl fuer die Berechnung ein" << endl;
  while (!checkIfFloat(p_input))
  {
  }
  number1 = stof(*p_input);
  cout << "Gebe die zweite Zahl fuer die Berechnung ein" << endl;
  while (!checkIfFloat(p_input))
  {
  }
  number2 = stof(*p_input);
  cout << "Mit welchem Operator moechtest du rechnen? + - / * " << endl;
  cin >> input;
  calcMethode = input;
  if (calcMethode == "/" && number2 <= 0)
  {
    cout << "Bitte gebe als zweite Zahl eine Zahl groesser 0 ein.";
    while (!checkIfFloat(p_input))
    {
    }
    number2 = stof(*p_input);
  }

  result = KonsolenTaschenrechner.calculate(number1, number2, calcMethode);
  calculate = KonsolenTaschenrechner.getCalculation();
  cout << fixed << setprecision(2);
  cout << "Deine Berechnung: " << calculate << " Das Ergebnis lautet: " << result
       << endl;
  return;
};

bool checkIfFloat(string *p_input)
{
  try
  {
    cin >> *p_input;
    float tmpFloat = stof(*p_input);
    return true;
  }
  catch (const invalid_argument)
  {
    cout << "Bitte gebe eine gueltige Zahl ein" << endl;
    return false;
  }
};
