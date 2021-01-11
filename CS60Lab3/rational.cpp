#include "rational.h"
#include <iostream>
#include <fstream>

using namespace std;

Rational::Rational()
{
  numerator = 0;
  denominator = 2;
}

Rational::Rational(int x, int y)
{
  numerator = x;
  denominator = y;
}

Rational operator*(Rational lhs, Rational rhs)
{
  Rational newRational;
  int n = 0;
  int d = 0;
  n = lhs.get_numerator() * rhs.get_numerator();
  d = lhs.get_denominator() * rhs.get_denominator();
  newRational.set_denominator(d);
  newRational.set_numerator(n);
  return newRational;
}

Rational operator+(Rational lhs, Rational rhs)
{
  Rational newRational1;
  int n = 0;
  int d = 0;

    d = lhs.get_denominator()*rhs.get_denominator();
    n = (lhs.get_numerator()*rhs.get_denominator())+(rhs.get_numerator()*lhs.get_denominator());



  newRational1.set_denominator(d);
  newRational1.set_numerator(n);
  return newRational1;
}

bool operator==(Rational lhs, Rational rhs)
{

 int n1 = lhs.get_numerator()*rhs.get_denominator();
 int d1 = lhs.get_denominator()*rhs.get_denominator();
 int n2 = rhs.get_numerator()*lhs.get_denominator();
 int d2 = rhs.get_denominator()*lhs.get_denominator();
 if((d2==d1)&&(n2==n1))
 {
   return true;
 }
 else{return false;}
}
ostream& operator<<(ostream& out, Rational a)
{
 out << a.get_numerator() << "/" << a.get_denominator();
 return out;
}
void Rational :: operator+=(Rational rhs)
{
 int n = rhs.get_numerator()+4;
 int d = rhs.get_denominator()+2;
 rhs.set_denominator(d);
 rhs.set_numerator(n);

}
bool operator <=(Rational lhs, Rational rhs){
    int a = lhs.get_numerator() / lhs.get_denominator();
    int b = rhs.get_numerator() / rhs.get_denominator();

    if(b>=a){
        return true;
    }
    else
        return false;
}

bool operator >=(Rational lhs, Rational rhs){
    int a = lhs.get_numerator() / lhs.get_denominator();
    int b = rhs.get_numerator() / rhs.get_denominator();

    if(a>=b){
        return true;
    }
    else
        return false;
}

