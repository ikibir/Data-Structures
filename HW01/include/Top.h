#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
using namespace std;

class Top{
    public:
        Top();
        Top(int x,int *a);        //  get adress
        Top(int x,int *a,int z);  //  get adress and color
        void setValue(int a);
        void setAdress(int *a);
        void setColor(int a);
        void printAdress();
        void printAll();
        int getColor();
        int *getAdress();
        ~Top();
    private:
        int value;
        int *adress;
        int color;
};
