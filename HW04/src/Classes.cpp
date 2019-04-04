#include <iostream>
#include <fstream>
#include <dirent.h>
#include <cstdio>
#include <cstring>
#include "../include/Classes.hpp"
using namespace std;

Dugum::Dugum(char x,int n, Dugum* l,Dugum *r){
    letter=x;
    lFreq=n;
    left=l;
    right=r;
    code="";
}
bool Dugum::isEmpty() const {
    if(left == NULL && right == NULL)
        return 1;
    return 0;
}
alphabet alpCounter(alphabet temp){
    FILE *inp;
    inp=fopen("deneme.txt","r");
    char tmpread;

    while(EOF != fscanf(inp,"%c",&tmpread)){
        switch(tmpread){
            case 'a':
                ++temp.a[0];
                break;
            case 'b':
                ++temp.a[1];
                break;
            case 'c':
                ++temp.a[2];
                break;
            case 'd':
                ++temp.a[3];
                break;
            case 'e':
                ++temp.a[4];
                break;
            case 'f':
                ++temp.a[5];
                break;
            case 'g':
                ++temp.a[6];
                break;
            case 'h':
                ++temp.a[7];
                break;
            case 'i':
                ++temp.a[8];
                break;
            case 'j':
                ++temp.a[9];
                break;
            case 'k':
                ++temp.a[10];
                break;
            case 'l':
                ++temp.a[11];
                break;
            case 'm':
                ++temp.a[12];
                break;
            case 'n':
                ++temp.a[13];
                break;
            case 'o':
                ++temp.a[14];
                break;
            case 'p':
                ++temp.a[15];
                break;
            case 'q':
                ++temp.a[16];
                break;
            case 'r':
                ++temp.a[17];
                break;
            case 's':
                ++temp.a[18];
                break;
            case 't':
                ++temp.a[19];
                break;
            case 'u':
                ++temp.a[20];
                break;
            case 'v':
                ++temp.a[21];
                break;
            case 'x':
                ++temp.a[22];
                break;
            case 'w':
                ++temp.a[23];
                break;
            case 'y':
                ++temp.a[24];
                break;
            case 'z':
                ++temp.a[25];
                break;
            default:
                break;
        }
    }
    fclose(inp);
    return temp;
}
Huffman::Huffman(string dosyaYolu)throw(string){
			words = 256;
			FileInput="";
			try{
				DosyaOku(dosyaYolu);
			}
			catch(string ex){
				throw ex;
			}
			root=NULL;
		}
void Huffman::DosyaOku(string dosyaYolu)throw(string){
	string satir;
	ifstream dosya(dosyaYolu.c_str());
	if (dosya.is_open())
	{
		while (getline(dosya,satir))
		{
			FileInput+=satir;
			FileInput+='\n';
		}
		dosya.close();
	}
	else throw "Dosya acilamadi";
}
void Huffman::Kodla(){
	char karakterler[FileInput.size()-1];

	strcpy(karakterler, FileInput.c_str());

	///Frekanslarý say
	int frek[words];
	/// frekanslarý sýfýrla
	for(int i=0;i<words;i++)frek[i] = 0;

	for (int i = 0; i < FileInput.size()-1; i++)
		frek[karakterler[i]]++;

	/// Huffman aðacýný oluþtur
	root = AgacOlustur(frek);

	/// 01 kodlar oluþturuluyor
	KodOlustur(root, "");
}
Dugum* Huffman::AgacOlustur(int frek[]){
	// dosyada var olan karakterler için düðüm oluþtur.
	Dugum* dugumler[words];
	for(int i=0;i<words;i++){
		if(frek[i]>0){
			dugumler[i] = new Dugum((char)i,frek[i]);
		}
		else{
			dugumler[i] = NULL;
		}
	}
	while(true){
		int ilkIndeks = MinDugumIndeks(dugumler);
		Dugum *min1 = dugumler[ilkIndeks];
		dugumler[ilkIndeks] = NULL;
		int ikinciIndeks = MinDugumIndeks(dugumler);
		if(ikinciIndeks == -1){
			return min1;
		}
		Dugum *min2 = dugumler[ikinciIndeks];
		dugumler[ikinciIndeks] = NULL;
		dugumler[ilkIndeks] = new Dugum(0,min1->lFreq+min2->lFreq,min1,min2);
	}
}
int Huffman::MinDugumIndeks(Dugum* dugumler[]){
	Dugum* minx;
	int minIndeks=-1;

	// ilk null olmayan düðümü min al
	for(int i=0;i<words;i++){
		if(dugumler[i] != NULL){
			minx = dugumler[i];
			minIndeks = i;
			break;
		}
	}

	for(int i=0;i<words;i++)
	{
		if(dugumler[i] == NULL) continue;

		if(minx->lFreq > dugumler[i]->lFreq) {
			minx = dugumler[i];
			minIndeks = i;
		}
	}
	return minIndeks;
}
void Huffman::KodOlustur(Dugum* alt_dugum,string kod){
	if(!alt_dugum->isEmpty()){
		KodOlustur(alt_dugum->left,kod+'0');
		KodOlustur(alt_dugum->right,kod+'1');
	}
	else{
		alt_dugum->code = kod;
	}
}
ostream& operator<<(ostream& ekran,Huffman& right){
	ekran<<"Huffman Agacindaki Karakterler ve Kodlari:"<<endl;
	right.inorder(right.root);
	return ekran;
}
void Huffman::inorder(Dugum* alt_dugum){
	if(alt_dugum != NULL){
		inorder(alt_dugum->left);
		if(alt_dugum->isEmpty()) cout<<alt_dugum->letter<<":"<<alt_dugum->code<<endl;
		inorder(alt_dugum->right);
	}
}
void Huffman::makeTable(){
	this->TableHelper(this->root);
}
void Huffman::TableHelper(Dugum* myC){
    ofstream ofs;
    ofs.open("Table.txt",fstream::app);
    if(myC != NULL){
		TableHelper(myC->left);
		if(myC->isEmpty()){
            ofs<<myC->letter<<":"<<myC->code<<endl;
        }
		TableHelper(myC->right);
	}
    ofs.close();
}
void Huffman::SilDugum(Dugum* alt_dugum){
	if(alt_dugum == NULL) return;
	SilDugum(alt_dugum->left);
	SilDugum(alt_dugum->right);
	delete alt_dugum;
	alt_dugum = NULL;
}
Huffman::~Huffman(){
	// Çöp oluþmamasý için aðaç temizleniyor.
	SilDugum(root);
}
string findCode(char x){
    string satir;
    char mycode[50];
	int i,j=0,isOk=0;
	ifstream dosya("Table.txt");

	if (dosya.is_open()){
        while(getline(dosya,satir) && !isOk){
            if(satir[0] == x){
                for(i=2; satir[i]=='0' || satir[i]=='1'; i++){
                    mycode[j]=satir[i];
                    ++j;
                }
                j=0;
                isOk=1;
            }
        }
	}
    for(i=0;'\0'!=mycode[i];i++)
        if(mycode[i]!='0' && mycode[i]!='1')
            mycode[i]='\0';
    dosya.close();
    return (string)mycode;
}
void Zipping(string dosyaYolu){

    char x;
	ifstream dosya(dosyaYolu.c_str());
    ofstream ofs;
    ofs.open("bit.dat",ios::out | ios::binary);
    string bindosya;
    int counter=0;

	if (dosya.is_open())
	{
		while (dosya.get(x))
		{
			findCode(x);
			if(x==' ')
                bindosya.append("@");
            else if(x=='\n')
                bindosya.append(">");
            else
                bindosya.append(findCode(x));
            ++counter;
		}
	}
    ofs.write(bindosya.c_str(),counter);
    dosya.close();
    ofs.close();
}
void printBin(string FilePath){
    char buffer[10000];
    char somekode[1000];
    int j=0;
    ifstream myFile (FilePath.c_str(), ios::in | ios::binary);
    myFile.read (buffer, 10000);
    for(int i=0; buffer[i]!='\n'; i++){

        if(buffer[i]=='@' || buffer[i]=='>'){
            j=0;
            findWord((string)somekode);
            if(buffer[i]=='@')
                cout<<" ";
            else if(buffer[i]=='>')
                cout<<"\n";
            somekode[0]='\0';
        }
        else{
            somekode[j]=buffer[i];
            ++j;
        }
    }
    myFile.close();
}
char findWord(string kod){
    char arr[100];
    char temp[100];
    int x=0,i=0,j=0,t=0,isOk=0;
    string satir;
    string Alltable;
    ifstream dosya("Table.txt");

	if (dosya.is_open())
	{
        while(getline(dosya,satir)){
            Alltable += satir;
            Alltable += '\n';
        }
        i=0;

        for(t=0;Alltable[t]!='\0';t++){

            while(Alltable[t]!='\n'){
                satir[i]=Alltable[t];
                i++;
                t++;
            }
            i=0;
            for(i=2; satir[i]!='\n'; i++){
                if(satir[i]==kod[j]){
                    ++j;
                    isOk=1;
                }
                else{
                    j=x;
                    isOk=0;
                }
            }
            if(isOk==1){
                j=i;
                x=i;
                isOk=0;
                cout<<satir[0];
                satir[0]='\0';
            }
        }


	}
    return 'a';
}
