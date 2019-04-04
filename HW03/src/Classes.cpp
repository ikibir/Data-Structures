#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include "../include/Classes.hpp"
using namespace std;

/// Functions ----------------------------------------------
void mergePath(char arr1[100], char arr2[100])
{
    string a,b;
    a=arr1;
    b=arr2;
    a=a+"/"+b;
    strcpy(arr1,a.c_str());
}

void StrtoStr(char arr1[100], char arr2[100])
{
    int i=0;
    while(arr2[i]!= '\0' && i<100){
        arr1[i]=arr2[i];
        ++i;
    }
    arr1[i]='\0';

}

int isTxt(char filename[50])
{

    for(int i=0;i<47;i++)
    {
        if(filename[i]=='.' && filename[i+1]=='t' && filename[i+2]=='x' && filename[i+3]=='t')
            return 1;
    }
    return 0;
}

int strCompare(char arr1[100], char arr2[100])
{
    int i=0;
    while(arr1[i] != '\0' && arr2[i] != '\0' && i<100){
        if((int) arr1[i] <  (int) arr2[i])
            return 0; // this mean left
        else if((int) arr1[i] > (int) arr2[i])
            return 1; // this mean right
        else
            ++i;
    }
    return 1; // this mean they are same
}

void printArr(char arr[100])
{
    int i=0;
    while(i<100 && arr[i]!='\0'){
        cout<<arr[i];
    }
    cout<<endl;
}

int isSameStr(char arr1[100], char arr2[100])
{
    int i=0;
    while(i<100 && arr1[i]!='\0' && arr2[0]!='\0' && arr1[i]!=' ' && arr2[i]!=' '){
        if(arr1[i] != arr2[i])
            return 0;
        ++i;
    }
    return 1;
}



/// Classes ------------------------------------------------

Tree::Tree()
{
    root = NULL;
}
void Tree::ekle(char a[100])
{
    Dugum* t = new Dugum;
    Dugum* parent;
    StrtoStr(t->Name,a);
    t->sol = NULL;
    t->sag = NULL;
    parent = NULL;
    int x;

    if(isEmpty())
        root = t;
    else
    {
        Dugum* curr;
        curr = root;
        while(curr)
        {
            parent = curr;
            if(strCompare(parent->Name, a)){
                curr = curr->sol;
            }
            else{
                curr = curr->sag;
            }
        }

        if(strCompare(parent->Name, a))
           parent->sol = t;
        else
           parent->sag = t;
    }

}

void Tree::yazdir()
{
    inorder(root);
}

void Tree::inorder(Dugum* p)
{
    if(p != NULL)
    {
        if(p->sol)
            inorder(p->sol);
        cout<<" "<<p->Name<<" ";
        if(p->sag)
            inorder(p->sag);
    }

}

int Tree::searchWord(char WordS[100])
{
    return inorderSearch(root,WordS);
}

int Tree::inorderSearch(Dugum* p,char WordS[100])
{
    int i=0;
    if (isSameStr(p->Name,WordS))
       return 1;

    while(p != NULL){
        if (isSameStr(p->Name,WordS))
            return 1;
        else if (!strCompare(p->Name,WordS))
            p=p->sag;
        else
            p=p->sol;
    }

    return 0;

}


Dugum::Dugum(char a[100])
{
    int i=0;
    while(i<150 && a[i]!='\0'){
        Name[i] = a[i];
        ++i;
    }
    Name[i]='\0';
    sonraki=0;
}

Liste::Liste()
{
    bas=0;
    son=0;
    i=0;
}

Liste::Liste(char a[100])
{
    Dugum *p = new Dugum(a);
    bas = son = p;
    i=0;
}

void Liste::ekle(char a[100])
{
    if(bas == 0)
    {
        bas = new Dugum(a);
        son = bas;
        ++i;
    }
    else
    {
        Dugum *yeniDugum = new Dugum(a);
        (*son).sonraki = yeniDugum;
        son = yeniDugum;
        ++i;
    }
}

void Liste::yazdir(int x)
{
    Dugum *temp;
    temp = bas;
    int counter =0;
    if( bas!= 0 )
    {
        while( temp != 0 )
        {
            if(counter++ < i)
                if(counter == x+1)
                    cout<<(*temp).Name;

            temp = (*temp).sonraki;
        }
    }
    else
        cout<<"listede eleman bulunmamaktadir.";
}

void Liste::sil(int a)
{
    Dugum *temp = 0;
    Dugum *birOnceki = 0;

    if( bas != 0 )
    {
        temp = bas;

        while( (*temp).sonraki != 0 && i > a )
        {
            birOnceki = temp;
            temp = (*temp).sonraki;
        }

        if( i == a )
        {
            if( bas == son )
            {
                bas = son = 0;
            }

            else if(birOnceki == 0)
            {
                bas = (*bas).sonraki;
            }

            else
            {
                (*birOnceki).sonraki = (*temp).sonraki;
            }

            if ( temp == son )
            {
                son = birOnceki;
            }

        }


    }

}

