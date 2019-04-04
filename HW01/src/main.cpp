/*
* @file Veri Yapilari HW01
* @description Program top nesnelerinin siralama ve yazdirma gibi islemlerini test eder.
* @course Orgun Ogretim B Grubu
* @assignment Odev 01
* @date 12.10.2017
* @author Muhammet Rasit Tosun
*/


#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include "../include/Top.h"

using namespace std;

void printDizi(Top *Gosterici[], int len, int val[]);
void reverseDizi(Top *Gosterici[], int len, int val[]);

int main()
{
    int lenofDizi=0;  // dizinin boyutu
    int choose=0;     // menu secenekleri
    int i=0;           // counter
    int *gost;
    // Dizinin Boyutunu al //////////////////////////////////////////////////
    do{
        cout<<"Dizinin Boyutu: ";
        cin>>lenofDizi;
    }while(lenofDizi<1  || lenofDizi>1000);
    // Boyut adetince Dizi olusturur ///////////////////////////////////////
    Top *myDizi = new Top[lenofDizi];
    int val[lenofDizi];
    // Nesnelerin Iclerini Doldurur ///////////////////////////////////////
    for(i=0; i<lenofDizi; i++){
        val[i]=i;
        myDizi[i].setValue(i);
        myDizi[i].setAdress(&val[i]);
        myDizi[i].setColor(i%5);
    }
    // Dizilerin adreslerini Göstericilere Kopyalar ///////////////////////
    Top *Gosterici[lenofDizi];
    for(i=0; i<lenofDizi; i++){
        Gosterici[i]=&myDizi[i];
    }
    cout<<"\x01"<<endl;
    // Menu ///////////////////////////////////////////////////////////
    do{
        cout<<"\n1- Diziyi Ters Cevir\n"<<"2- Diziyi Yazdir\n"<<"3- Cikis\n::>";
        cin>>choose;
        if(choose<1 || choose>3)
            cout<<"Yanlis Bir Giris Yaptiniz Tekrar Deneyin!\n";
        else if(choose == 3)
            return 0;
        else{
            switch(choose){
                case 1:
                    reverseDizi(Gosterici,lenofDizi,val);
                    break;
                case 2:
                    printDizi(Gosterici,lenofDizi,val);
                    break;
                case 3:
                    return 0;
                    break;
                default:
                    cout<<"Bir seyler Yanlis Gitti..\nProgramdan Cikiliyor..\n";
                    return 0;
                    break;

            }
        }
    }while(true);

    // Program sonlandirilmadan heapi temizler ///////////////////////////////////
    delete myDizi;
    for(i=0;i<lenofDizi;i++){
        delete Gosterici[i];
    }

    return 0;

}

void printDizi(Top *Gosterici[], int len, int val[])
{
    for(int i=0; i<len; i++)
    {
        cout<<i+1<<". ";
        Gosterici[val[i]]->printAdress();
        cout<<endl;
    }

}

void reverseDizi(Top *Gosterici[], int len, int val[])
{
    int mylen=len-1;
    int temp ;
    for(int i=0; i<len/2; i++,mylen--)
    {
        temp=val[i];
        val[i]=val[mylen];
        val[mylen]=temp;
    }
}
