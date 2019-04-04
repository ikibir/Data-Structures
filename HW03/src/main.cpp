/*
    @KlasorOku
    @Read a directory reads all txt files
    @Sube 1B
    @HW3
    @7.12.2017
    @b171210372
*/

#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include "../include/Classes.hpp"
using namespace std;


int main()
{
    DIR* dirp;
    Liste fileList;
    struct dirent * dp;
    char basepath[100];
    char mypath[100];
    char output[100];
    char userWord[100];
    char slash='/';
    int choose=0;
    int numb=0, i=0;
    int isOut=1,isFound=0;

    ifstream myfile;
    cout<<"Enter The Path: ";
    cin>>basepath;
    StrtoStr(mypath,basepath);

    dirp = opendir(mypath);
    while((dp=readdir(dirp)) != NULL)
        ++numb;
    closedir(dirp);
    if(!numb)
    {
        cout<<"Klasor bulunamadi!"<<endl;
        return 0;
    }

    dirp = opendir(mypath);
    Tree words[numb];
    numb=0;
    while ((dp = readdir(dirp)) != NULL) {              // Klasordeki butun dosyalarý okur
        if(dp->d_name != "." && dp->d_name != "..")     // . veya .. ise girmez
            if(isTxt(dp->d_name)){                      // txt kontrolu
                mergePath(mypath,dp->d_name);
                fileList.ekle(mypath);
                myfile.open(mypath);
                if(myfile.is_open()){
                    while (!myfile.eof()) {
                        myfile >> output;
                        words[numb].ekle(output);
                    }
                }
                myfile.close();
                ++numb;
            StrtoStr(mypath,basepath);
            }
    }

    closedir(dirp);
    while(isOut)
    {
        cout<<"\n1.Search Yap\n2. List\n3. Exit\n:> ";
        cin>>choose;
        switch(choose){
            case 1:
                    cout<<"Enter the Word: ";
                    cin>>userWord;
                    for(i=0;i<numb;i++){
                        if(words[i].searchWord(userWord)){
                            cout<<"\nAranan: "<<userWord<<endl;
                            cout<<"Aranan kelime ";
                            fileList.yazdir(i);
                            cout<<" dosyasinin icinde.";
                            isFound=1;
                        }
                    }
                    if(isFound==0){
                        cout<<"Can't found the word"<<endl;
                        isFound=0;
                    }

                break;
            case 2:
                for(i=0;i<numb;i++){
                    cout<<endl;
                    fileList.yazdir(i);
                    cout<<":"<<endl;
                    words[i].yazdir();
                    cout<<endl;
                }
                break;
            case 3:
                isOut=0;
                break;
            default:
                cout<<"Wrong Value!"<<endl;
                break;

        }
    }


}


