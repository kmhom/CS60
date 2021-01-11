#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>


class Rational{
  private:
  int numerator;
  int denominator;
  public:
  Rational();
  Rational(int,int);
  void set_numerator(int n)
  {
    numerator = n;
  }
  void set_denominator(int d)
  {
    denominator = d;
  }
  int get_numerator()
  {
    return numerator;
  }
  int get_denominator()
  {
    return denominator;
  }
  friend std::ostream& operator<<(std::ostream& out, Rational a);
  void operator+=(Rational rhs);


};
bool operator==(Rational lhs, Rational rhs);
bool operator >=(Rational lhs, Rational rhs);
bool operator <=(Rational lhs, Rational rhs);

#endif // RATIONAL_H
