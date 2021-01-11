#include <iostream>
#include "rational.h"

using namespace std;

template<typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(a[i] == find){
            count++;
        }
    }
    return count;
}

template<typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high){
    int count = 0;
    for(T2 i = 0; i < size; i++){
        if(a[i] >= low && a[i] <= high){
            count++;
        }
    }
    return count;
}


int main()
{
    Rational a(1,2);
    Rational b(1,3);
    Rational c(5,4);
    Rational test(1,4);
    Rational high (2,3);


    Rational r[3] = {a,b,c};

    int arr[6] = {6, 2, 3, 2, 6, 2};

    //T1 and T2 need to support ints and arrays in this case
    //cout << count_exact(r, 3, test) << endl;
    cout << count_range(r, 3, test, high) << endl;


    return 0;
}
