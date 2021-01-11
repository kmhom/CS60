#include <iostream>
#include "rational.h"

using namespace std;

template<typename T,typename T1>
class Point{
private:
    T array[10];
    T dimension;
public:
    Point()
    {
        dimension = 10;
        for(int i = 0; i <dimension; i++)
        {
            array[i] = {};
        }
    }

    Point(T x)
    {
        dimension = x;
     }
    Point (T1 x,T a[])
    {
        for(int i = 0; i < x; i++)
        {
            array[i] == a[i];
        }
    }

    T get_item(T1 x){
        return array[x];
    }
    T get_size(){
        return dimension;
    }
};

//Point<T>::Point operator+()




int main()
{
    Rational a(1,2);
    Rational b(1,3);
    Rational c(5,4);
    Rational d(1,4);
    Rational e(2,3);
    Rational f(1,2);
    Rational g(1,3);
    Rational h(5,4);
    Rational i(1,4);
    Rational j(2,3);

    Rational k[10] = {a,b,c,d,e,f,g,h,i,j};
    int size = 10;
    Point<int>::Point l(size,k);
    cout << l.get_item(2) << endl;






    return 0;
}
