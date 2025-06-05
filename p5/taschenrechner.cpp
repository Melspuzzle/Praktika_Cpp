#include "taschenrechner.h"
#include <sstream> //string stream
#include <iomanip> // fuer setprecision(2)
taschenrechner::taschenrechner(/* args */) { init(); }

taschenrechner::~taschenrechner() {}

void taschenrechner::setNumber1(float num) { number1 = num; }
void taschenrechner::setNumber2(float num) { number2 = num; }
void taschenrechner::setResult(float num) { result = num; }
void taschenrechner::setCalcMethode(string mathOperator)
{
  calcMethode = mathOperator;
}

float taschenrechner::getNumber1() { return number1; }
float taschenrechner::getNumber2() { return number2; }
float taschenrechner::getResult() { return result; }
string taschenrechner::getCalcMethode() { return calcMethode; }

void taschenrechner::init()
{
  setNumber1(0);
  setNumber2(0);
  setResult(0);
}

float taschenrechner::calculate(float number1, float number2,
                                string calcMethode)
{

  setNumber1(number1);
  setNumber2(number2);
  setCalcMethode(calcMethode);
  float result = 0;
  if (calcMethode == "+")
  {
    result = number1 + number2;
  }
  else if (calcMethode == "-")
  {
    result = number1 - number2;
  }
  else if (calcMethode == "*")
  {
    result = number1 * number2;
  }
  else if (calcMethode == "/")
  {
    result = number1 / number2;
  }

  setResult(result);
  return result;
}
string taschenrechner::getCalculation()
{
  string calculate;
  string number;
  number = to_string(getNumber1());
  calculate += number;
  number = getCalcMethode();
  calculate += number;
  number = to_string(getNumber2());
  calculate += number;

  return calculate;
  ostringstream stream;
  stream << fixed << setprecision(2); // Format auf 2 Nachkommastellen

  stream << getNumber1();
  stream << getCalcMethode();
  stream << getNumber2();

  return stream.str();
}
