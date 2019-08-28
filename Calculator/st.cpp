#include "st.h"
#include <cstdlib>
//#include <QString>

using namespace std;

int* ST::divide(QString str,const int max_length)
{
    int *array=new int[max_length];
    for (int i=0;i<max_length;i++)
        array[i]=0;
    QString one;

    for (int i=1;i<=str.length();i++)
    {
        one=str[str.length()-i];
        array[max_length-i]=one.toInt();
    }

    return array;
}

int ST::comparison(QString first_str, QString second_str)
{                                                                   //0-числа равны
    QString one,two;                                                //1-первое число больше второго
    if(first_str.length()>second_str.length())                      //2-второе число больше первого
        return 1;
    else if(first_str.length()<second_str.length())
        return 2;
    else
    {
        for (int i=0;i<first_str.length();i++)
        {
            one=first_str[i];
            two=second_str[i];
            if(one.toInt()>two.toInt())
                return 1;
            else if(one.toInt()<two.toInt())
                return 2;
        }
        return 0;
     }
}

int* ST::difference(int *first_array, int *second_array, int length)
{
    for (int i=1;i<=length;i++)
    {
       if(first_array[length-i]>=second_array[length-i])
           first_array[length-i]-=second_array[length-i];
       else
       {
          first_array[length-i-1]--;
          first_array[length-i]=(10+first_array[length-i])-second_array[length-i];
       }
    }
    return first_array;
}

int* ST::dropping_zeros(int *array, int &length)
{
    bool condition=true;
    int i=0;

    while(condition)
        if (array[i]==0)
            i++;
        else
            condition=false;

    int *new_array=new int[length-i];

    for (int b=1;b<=(length-i);b++)
        new_array[(length-i)-b]=array[length-b];

    length-=i;

    return new_array;
}

int* ST::dropping_zeros_2(int *array, int &length)
{
    int i=1;
    bool condition=true;
    if(condition)
    {
        if((array[length-i]==0)&&(i<=length))
            i++;
        else
            condition=false;
    }

    length=length-i+1;
    int* new_array=new int[length];

    for(int j=0;j<length;j++)
        new_array[j]=array[j];

    return new_array;
}

QString ST::operator+(ST myClass)
{
    int max_length,beg=0;

    if(stroka.length()>=myClass.stroka.length())
        max_length=stroka.length()+1;
    else
        max_length=myClass.stroka.length()+1;

    int *first_array=ST::divide(stroka,max_length);
    int *second_array=ST::divide(myClass.stroka,max_length);

    for (int i=1;i<max_length;i++)
    {
        first_array[max_length-i]+=second_array[max_length-i];
        first_array[max_length-i-1]+=(first_array[max_length-i]/10);
        first_array[max_length-i]%=10;
    }

    if (first_array[0]==0)
        beg=1;

    QString str;

    for (int i=beg;i<max_length;i++)
    {
        str+=QString::number(first_array[i]);
    }

    return str;
}

QString ST::operator-(ST myClass)
{
    int max_length,beg;
    int *third_array;

    if(stroka.length()>=myClass.stroka.length())
        max_length=stroka.length();
    else
        max_length=myClass.stroka.length();

    int *first_array=ST::divide(stroka,max_length);
    int *second_array=ST::divide(myClass.stroka,max_length);

    int resul=ST::comparison(stroka,myClass.stroka);

    if(resul==1)
    {
        third_array=ST::difference(first_array,second_array,max_length);
        third_array=ST::dropping_zeros(third_array,max_length);
    }
    else if (resul==2)
    {
        third_array=ST::difference(second_array,first_array,max_length);
        third_array=ST::dropping_zeros(third_array,max_length);
        third_array[0]*=(-1);
    }
    else
        return (QString::number(0));

    QString str;
    for (int i=0;i<max_length;i++)
    {
        str+=QString::number(third_array[i]);
    }

    return str;
}

QString ST::operator*(ST myClass)
{
    int beg=1;
    int *first_array=ST::divide(stroka,stroka.length());
    int *second_array=ST::divide(myClass.stroka,myClass.stroka.length());

    int max_length=stroka.length()+myClass.stroka.length();

    int *third_array=new int[max_length];
    for(int i=0;i<max_length;i++)
        third_array[i]=0;

    for (int i=1;i<=stroka.length();i++) {
        for (int j=1;j<=myClass.stroka.length();j++) {
            third_array[i+j-2]+=(first_array[stroka.length()-i]*second_array[myClass.stroka.length()-j]);
            third_array[i+j+1-2]+=(third_array[i+j-2]/10);
            third_array[i+j-2]%=10;
        }
    }

    third_array=ST::dropping_zeros_2(third_array,max_length);

    QString str;
    if (third_array[0]==0)
        beg=2;
    for (int i=beg;i<=max_length;i++)
    {
        str+=QString::number(third_array[max_length-i]);
    }

    return str;
}

QString ST::operator/(ST myClass)
{
    int beg=1;
    int max_length;

    if(stroka.length()>=myClass.stroka.length())
        max_length=stroka.length();
    else
        max_length=myClass.stroka.length();

    int *first_array=ST::divide(stroka,max_length);
    int *second_array=ST::divide(myClass.stroka,max_length);

    for (int i=1;i<stroka.length();i++)
    {
        for (int j=1;j<myClass.stroka.length();j++)
        {

        }
    }
}



