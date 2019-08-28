#ifndef ST_H
#define ST_H

#include <QString>

class ST
{
    public:
        QString stroka;
        //QString sign;


        int* divide(QString str,const int max_length);
        int comparison(QString first_str, QString second_str);
        int* difference(int *first_array, int *second_array, int length);
        int* dropping_zeros(int *array, int &length);
        int* dropping_zeros_2(int* array, int &length);
        QString operator+(ST myClass);
        QString operator-(ST myClass);
        QString operator*(ST myClass);
        QString operator/(ST myClass);

};

#endif // ST_H
