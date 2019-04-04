/*
    @BintoText
    @bin to txt and txt to bin
    @Sube 1B
    @HW4
    @21.12.2017
    @b171210372
*/

#include <iostream>
#include <fstream>
#include <dirent.h>
#include <cstdio>
#include <cstring>
#include "../include/Classes.hpp"
using namespace std;


int main()
{
    int choose=-1;
    string FilePath;

    cout<<"1.Dosyayi Sikistir\n2.Dosyayi Ekrana Yaz\n::>";
    cin>>choose;
    if(choose==1){
        cout<<"Dosya yolunu giriniz: ";
        cin>>FilePath;
        Huffman *deneme = new Huffman(FilePath);
        deneme->Kodla();
        cout<<*deneme;
        deneme->makeTable();
        Zipping(FilePath);
    }
    else if(choose==2){
        cout<<"Programin Bu kismini yetistiremedim";
    }
    return 0;

}

