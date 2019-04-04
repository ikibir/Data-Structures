#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

/// Classes ------------------------------------------------
class Dugum{
    public:
        char Name[100];
        Dugum *sonraki;
        Dugum *sag;
        Dugum *sol;
        Dugum(){};
        Dugum(char a[100]);

};

class Liste
{
    public:
        Dugum *bas;
        Dugum *son;
        Liste();
        Liste(char a[100]);
    int i;
    void ekle(char a[100]);
    int say(int x);
    void yazdir(int x);
    void sil(int a);

};

class Tree
{
    public:
        char FileName[100];
        Dugum* root;
        Tree();
        bool isEmpty() const { return root==NULL; }
        void inorder(Dugum*);
        int inorderSearch(Dugum*,char WordS[100]);
        void ekle(char a[100]);
        void yazdir();
        int searchWord(char WordS[100]);

};

/// Functions ----------------------------------------------


int isTxt(char filename[50]);
void mergePath(char arr1[100], char arr2[100]);
void StrtoStr(char arr1[100], char arr2[100]);
int strCompare(char arr1[100], char arr2[100]);
int isSameStr(char arr1[100], char arr2[100]);
void printArr(char arr[100]);
