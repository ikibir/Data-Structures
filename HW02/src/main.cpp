#include<iostream>
#include <ctime>
#include "../include/Classes.hpp"
using namespace std;


int main()
{
    double start=clock();
    long int temp;
    int range=0;
    Liste liste;

    cout<<"Faktoryeli alinacak sayiyi giriniz(Cikis icin -1): ";
    cin>>temp;
    do{
        if(temp>0)
            factorial(temp,&liste);
            cout<<"Calculate time:"<<( clock() - start ) <<" milisaniye"<<endl;
        cout<<"Faktoryel alincak sayiyi giriniz(Cikis -1, HepsiniYazdir 0) :";
        cin>>temp;
        start=clock();
        if(temp==0)
            liste.yazdir();

    }while(temp>=0);

    for(int i=liste.i; i>=0; i--)
        liste.sil(i);
    return 0;


}


