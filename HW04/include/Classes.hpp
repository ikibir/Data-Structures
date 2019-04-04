
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <cstdio>
#include <cstring>

using namespace std;

class alphabet{
    public:
        alphabet(){
            for(int i=0;i<26;i++)
                a[i]=0;
        }
        int a[26];
};

class Dugum{
    public:
		char letter;
		int lFreq;
		string code;
		Dugum* left;
		Dugum* right;
		Dugum(char x,int n, Dugum* l=NULL,Dugum *r=NULL);
		bool isEmpty() const;

};

class Huffman{
    private:
		int words;  			// harflerin ASCII karþýlýklarý
		string FileInput;			// dosyadan okunan girdi
		Dugum *root;

		Dugum* AgacOlustur(int frek[]);
		void KodOlustur(Dugum*,string);
		int MinDugumIndeks(Dugum* dugumler[]);
		void DosyaOku(string)throw(string);
		void inorder(Dugum*);
		void SilDugum(Dugum*);
	public:
		Huffman(string)throw(string);
		void Kodla();
		friend ostream& operator<<(ostream&,Huffman&);
		void makeTable();
        void TableHelper(Dugum*);

		~Huffman();
};

void printBin(string FilePath);
string findCode(char x);
char findWord(string kod);
void Zipping(string dosyaYolu);
