#include <iostream>
#include "../include/Classes.hpp"
using namespace std;

/// Functions ----------------------------------------------
void factorial(int n,Liste *mylist)
{
    int res[MAX],cnt,sFcnt,x;

    res[0] = 1;
    int res_size = 1;

    /// x 2'den kucukse hic girmez buyukse klasik faktoriyel uygulamasi
    for (x=2; x<=n; x++){
        res_size = multiply(x, res, res_size);

       for(cnt=res_size-1,sFcnt=0;cnt>-1;cnt--,sFcnt++)   /// hesaplanan faktoriyelleri kaydet
              mylist->ekle(res[cnt]);

        mylist->ekle(-1);


    }

    /// Sayiyi yazdirma
    cout <<n<<"!: ";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
    cout<<endl;

}

int multiply(int x, int result[], int res_size)
{
    int carry = 0;

    /// res[] her basamagini carp
    for (int i=0; i<res_size; i++)
    {
        int prod = result[i] * x + carry;
        result[i] = prod % 10;                 /// son elemanini resulta yaziyor
        carry  = prod/10;                     /// son elemani cikarilmis sekilde tasiyiciya yaziyor

    }

    /// son basamagi arraye basar ve boyutunu bir artir
    while (carry)
    {
        result[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}




/// Classes ------------------------------------------------

Sayi::Sayi()
{
    range =0;
}
void Sayi::setNum(int sayi, int i)
{
    if(sayi<2500)
        num[i]=sayi;
    ++range;
}
int Sayi::getNum(int i)
{
    if(i<range)
        return num[i];
}

Dugum::Dugum(int a)  /// ilk elemani ekler
{
    sayi = a;
    sonraki=0;
}
int Dugum::sayiDondur()
{
    return sayi;
}

Liste::Liste()
{
    bas=0;
    son=0;
    i=0;
}

Liste::Liste(int a)
{
    Dugum *p = new Dugum(a); /// ilk d���m olu�turulur. bu d���m�n verisi a'd�r.
    bas = son = p;   /// ilk d���m ve son d���m p'dir.
    i=0;
}

void Liste::ekle(int a)
{
    if(bas == 0) /// liste bos ise
    {
        bas = new Dugum(a);
        son = bas;
        ++i;
    }
    else /// e�er listede d���m var ise
    {
        Dugum *yeniDugum = new Dugum(a);
        (*son).sonraki = yeniDugum;
        son = yeniDugum;
        ++i;
    }
}

int Liste::say(int x)
{
    Dugum *temp;
    temp = bas;
    int i=1;
    int counter=0;
    long int myNum=0;
    if( bas!= 0 )  /// liste dolu mu kontorlu
    {
        while( temp != 0 )  /// liste bitene kadar
        {
            if((*temp).sayiDondur() != -1){
                myNum= myNum*i+(*temp).sayiDondur(); /// -1 de�ilse d���mdeki say�y� dondur.
                i=10;
            }
            else{
                ++counter;
            if(counter==x)
                break;
            myNum=0;
            i=1;
            }
            temp = (*temp).sonraki;        /// sonraki d���me ge�

        }
    }
    return myNum;
}

void Liste::yazdir()
{
    Dugum *temp;
    temp = bas;

    if( bas!= 0 )
    {
        while( temp != 0 )
        {
            if((*temp).sayiDondur() != -1)
                cout<<(*temp).sayiDondur();
            else
                cout<<endl;
            temp = (*temp).sonraki;
        }
        cout<<endl;
    }
    else
        cout<<"listede eleman bulunmamaktadir.";
}

void Liste::sil(int a)
{
    Dugum *temp = 0;
    Dugum *birOnceki = 0;

    if( bas != 0 )  // e�er liste bo� de�ilse
    {
        temp = bas;  // aramaya ba�tan ba�lanarak ilerlenir.

        while( (*temp).sonraki != 0 && (*temp).sayiDondur() != a ) // liste sonuna kadar VE sayi bulunana kadar
        {
            birOnceki = temp;  //  silinecek d���mden �nceki d���m�
            temp = (*temp).sonraki; //  ve silinecek d���mden sonraki d���m� al.
        }

        if( (*temp).sayiDondur() == a ) // e�er silinecek eleman listede bulunuyorsa
        {
            if( bas == son )   // listede tek eleman varsa
            {
                bas = son = 0;  // liste bo�alt�ld�.
            }

            else if(birOnceki == 0) // silinecek eleman en ba�ta ise   if ( temp == bas ) �eklinde de yaz�labilir.
            {
                bas = (*bas).sonraki;
            }

            else // silinecek eleman arada ise
            {
                (*birOnceki).sonraki = (*temp).sonraki;
            }

            if ( temp == son ) // silinecek eleman en sonda ise
            {
                son = birOnceki;
            }

        }


    }

}

yigit::yigit(int boy)
{
    rear=0;
    size=boy;
    dizi = new int [boy];
}

void yigit::ekle(int x)
{
    if(rear==size)
        cout<<"yiginda yeterli alan yoktur..."<<endl;
    else
    {
        dizi[rear]=x;
        rear=rear+1;
    }
}

int yigit::say()
{
    return rear;
}

void yigit::listele()
{
    if(rear==0)
        cout<<"yigin bos ..."<<endl;
    else{
        int i;
        for(i=0;i<rear;i++)
            cout<<i+1<<". eleman : "<<dizi[i]<<endl;
    }
}

void yigit::getir()
{
    if(rear== 0)
        cout<<"yiginda eleman yoktur.."<<endl;
    else{
        cout<<"ilk elemen :"<<dizi[rear-1]<<endl;
        rear=rear-1;
    }
}
