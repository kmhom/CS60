#ifndef SPORTSCAR_H
#define SPORTSCAR_H
#include "automobile.h"


class SportsCar : public Automobile
{
private:
    int octane;
    int acceleration_time;

public:
    SportsCar();
    SportsCar(int, int, std::string imake, std::string imodel, int iyear, double iprice, int istall);
    int get_octane();
    int get_acceleration_time();
    bool park(bool lot[], int size);
};

#endif // SPORTSCAR_H
