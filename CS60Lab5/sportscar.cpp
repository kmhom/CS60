#include "sportscar.h"


SportsCar::SportsCar() : Automobile()
{
    octane = 0;
    acceleration_time = 0;

}

SportsCar::SportsCar(int a, int b,std::string imake, std::string imodel, int iyear, double iprice, int istall) : Automobile(imake,imodel,iyear,iprice,istall){
    octane = a;
    acceleration_time = b;
}

int SportsCar::get_octane(){
    return octane;
}

int SportsCar::get_acceleration_time(){
    return acceleration_time;
}

bool SportsCar::park(bool lot[], int size){
    if(price() >= 50000){

    }
}
