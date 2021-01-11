#ifndef DBIGUINT_H
#define DBIGUINT_H
#include <cstdlib>
#include <string>

class dbiguint
{
public:
    // pre: none
    // post: creates a dynamic bigint with given initial value
    //       (default = 0)
    dbiguint(int = 0);

    // pre: s[0] is either +, - or a digit
    //      s[1], ..., s[s.size()-1] are digits
    // post: creates a dbiguint whose digits are given in s
    dbiguint(const std::string & s);

    // pre:  none    //NEW
    // post: copy constructor: creates a new dynamic bigint which is
    //                         a copy of given dynamic bigint
    dbiguint(const dbiguint &);

    // pre: none    //NEW
    // post: returns dynamically allocated memory to heap
    ~dbiguint();

    // pre: none    //NEW
    // post: makes this dynamic bigint a copy of given dynamic bigint
    void operator =(const dbiguint &);

    // pre: none    //NEW
    // post: returns the size of the memory block of this dbiguint
    std::size_t size() const;

    // pre: none
    // post: returns the digit at given pos (0 if does not exist)
    //       pos 0 is the least significant (units) digit
    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 0 if this dbiguint equals given dbiguint
    //               1 if this dbiguint >      given dbiguint
    //              -1 otherwise
    int compare(const dbiguint &) const;

    // pre: none
    // post: returns a string containing the digits and sign of this dbiguint
    std::string toStdString() const;

    // pre: none
    // post: adds/subtracts given dbiguint to this dbiguint
    void operator +=(const dbiguint &);
    void operator -=(const dbiguint &);
    void operator *=(const dbiguint &);

    // pre: none
    // post: if new_capacity <= _capacity then do nothing (cannot shrink)
    //       else allocate a new block with size new_capacity
    //       copy existing digits and fill the rest with 0
    void reserve(std::size_t new_capacity);


private:
    unsigned short *_data;
    std::size_t _capacity;
    bool _neg;

    // INVARIANTS:
    //    _data points to (has the address of) a dynamic array
    //    of _capacity digits
    //    _data[0] = least significant (units) digits
    //    _data[k] = digit at position k (or 0 if not used)
    //    _neg = true if this dbiguint is negative
    //         = false if this dbiguint is nonnegative (including 0)
};

dbiguint operator -(const dbiguint& a, const dbiguint& b);
dbiguint operator +(const dbiguint& a, const dbiguint& b);
bool operator <(const dbiguint& a, const dbiguint& b);
bool operator <= (const dbiguint & b1, const dbiguint & b2);
bool operator >(const dbiguint& a, const dbiguint& b);
bool operator >= (const dbiguint & b1, const dbiguint & b2);
bool operator == (const dbiguint & b1, const dbiguint & b2);
bool operator != (const dbiguint & b1, const dbiguint & b2);

#endif // DBIGUINT_H
