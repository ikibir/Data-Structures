#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include "../include/Top.h"

using namespace std;

HANDLE hCon;
enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void SetColor(Color c){
        if(hCon == NULL)
                hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hCon, c);
}

//  CLASS FUNCTIONS
Top::Top(){}
Top::Top(int x,int *a){value=x; adress=a; color=1;}
Top::Top(int x,int *a,int z){value=x; adress=a; color=z;}  // Value Adress NexTop Color
void Top::setValue(int a){value=a;}
void Top::setAdress(int *a){adress=a;}
void Top::setColor(int a){color=a;}
void Top::printAll(){cout<<"Value: "<<value<<"\nAdress: "<<adress<<"\nColor: "<<color<<endl;}
int* Top::getAdress(){return adress;}
int Top::getColor(){return color;}
void Top::printAdress(){

    if(color==0)
        SetColor(GREEN);
    else if(color == 1)
        SetColor(BLUE);
    else if(color == 2)
        SetColor(RED);
    else if(color == 3)
        SetColor(PINK);
    else if(color == 4)
        SetColor(YELLOW);
    else
        SetColor(WHITE);
    cout<<adress;
    SetColor(WHITE);
    }
Top::~Top(){
    delete adress;
}
