#include <iostream>
using namespace std;
#define MAX 10000

/// Classes ------------------------------------------------
class Dugum{
      private:
        int sayi;
      public:
        Dugum *sonraki;
        Dugum(){};
        Dugum(int a);
        int sayiDondur();

};

class Liste
{
    public:
        Dugum *bas;
        Dugum *son;
        Liste();
        Liste(int a);
    int i;
    void ekle(int a);
    int say(int x);
    void yazdir();
    void sil(int a);

};

class Sayi{
    private:
        int range;
        int num[2500];
    public:
        Sayi();
        void setNum(int sayi, int i);
        int getNum(int i);
};

class yigit {

    private:
        int rear;
        int data;
        int *dizi;
        int size;

    public:
    yigit(int boy);
    void ekle(int x);
    int say();
    void listele();
    void getir();

};

/// Functions ----------------------------------------------

int multiply(int x, int result[], int res_size);
void factorial(int n, Liste *mylist);
void printArr(int x[500]);
