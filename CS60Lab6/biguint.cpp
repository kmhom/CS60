 #include "dbiguint.h"

#include <cassert>
#include <sstream>

 dbiguint::dbiguint(int n){
    _capacity=0;
    double x=n;
    while(x>1){
        x=x/10.0;
        _capacity++;
    }
    _data = new unsigned short[_capacity];

     for(std::size_t i = 0; i<_capacity; i++){
         if(n==0) _data[i] = 0;
         else{
             _data[i] = n%10;
             n=n/10;
         }
     }

 }
 dbiguint::dbiguint(const std::string & s)
 {
     int _capacity=s.length();
     _data = new unsigned short[_capacity];
     for (int i = 0; i < _capacity; ++i)
         _data[i] = 0;

     if (s.size() == 0)
         return;

     char c = s[0];
     int j(0);
     for (int i = s.size()-1; j < _capacity && i >= 0; --i)
     {
         assert(isdigit(s[i]));
         _data[j] = s[i] - '0';
         ++j;
     }
 }

 dbiguint::dbiguint(const dbiguint &a){
     _capacity=a._capacity;
     _data=new unsigned short[_capacity];
     std::copy(a._data, a._data+_capacity,_data);
 }

 dbiguint::~dbiguint(){
    _capacity=0;
    delete[]_data;
    _data=nullptr;
 }


 unsigned short dbiguint::operator [](std::size_t pos) const
 {
     assert(pos < _capacity);
     return _data[pos];
 }



 int dbiguint::compare(const dbiguint & b) const{
     for(std::size_t i =_capacity-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
 }

void dbiguint::operator=(const dbiguint &b){
    unsigned short *new_array;
    if(this == &b){
       return;
    }
    if(_capacity != b._capacity){
       new_array = new unsigned short[b._capacity];
       delete [] _data;
       _data = new_array;
       _capacity = b._capacity;
    }

    std::copy(b._data, b._data+_capacity,_data);
}

void dbiguint::reserve(std::size_t new_capacity){
    unsigned short *new_array;
    if(new_capacity == _capacity){
        return;
    }
    new_array = new unsigned short[new_capacity];
    std::copy(_data, _data+_capacity,new_array);
    delete []_data;
    _data = new_array;
    _capacity = new_capacity;


}

void dbiguint::operator -=(const dbiguint &b){
    for(std::size_t i = 0; i < _capacity;++i){
       if(_data[i] - b._data[i] < 0){
           _data[i]=10+_data[i]-b._data[i];
           _data[i+1]= _data[i] - 1;

       }
       else
           _data[i] = _data[i] - b._data[i];
    }
}
 void dbiguint::operator += (const dbiguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<_capacity; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
 std::string biguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
 std::ostream & operator << (std::ostream & os, const dbiguint & b)
 {

     for (int i = dbiguint::_capacity - 1; i >= 0; --i)
         os << b[i];
     return os;
 }

 std::istream & operator >> (std::istream & is, biguint & b)
 {
     std::string s;
     is >> s;
     b = biguint(s);
     return is;


 }

 dbiguint operator +(const dbiguint& a, const dbiguint& b){
          dbiguint k(0);
          k.operator+=(a);
          k.operator +=(b);
          return k;
 }

 dbiguint operator -(const dbiguint& a, const dbiguint& b){
          dbiguint k(0);
          k.operator-=(a);
          k.operator +=(b);
          return k;
 }

 bool operator <(const dbiguint& a, const dbiguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator >(const dbiguint& a, const dbiguint& b){
     return (a.compare(b)==1);
 }

 bool operator >= (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) >= 0);
 }

 bool operator == (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) != 0);
 }

//You do > and >=
