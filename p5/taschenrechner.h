#ifndef TASCHENRECHNER_H
#define TASCHENRECHNER_H

#include <string>
using namespace std;
class taschenrechner
{
private:
  float result;
  float number1;
  float number2;
  string calcMethode;
  float getNumber1();
  float getNumber2();
  float getResult();
  string getCalcMethode();
  void setNumber1(float);
  void setNumber2(float);
  void setResult(float);
  void setCalcMethode(string);

public:
  taschenrechner();  //(float, float); // Konstruktor
  ~taschenrechner(); // Destruktor, Nutzung für Freigaben von dynamisch
                     // erzeugtem Speicher
  void init();
  float calculate(float, float, string);
  string getCalculation();
};

#endif // !TASCHENRECHNER_H
