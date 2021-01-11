#ifndef POINT_H
#define POINT_H


template<typename T>
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
    Point (T a[])
    {
        for(int i = 0; i < 10; i++)
        {
            array[i] == a[i];
        }
    }

    T get_item(T x){
        return array[x];
    }
    T get_size(){
        return dimension;
    }
};



#endif // POINT_H
