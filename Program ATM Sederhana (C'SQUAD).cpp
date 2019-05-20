#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
using namespace std;

void garis(){
    cout<<"========================================================================\n";
}
void header(){
    garis();
    cout<<"\t            Bank C'Squad dengan Bahasa C++\n";
    garis();
    cout<<"    Nama Kelompok\t: C'Squad\n"
        <<"    Anggota Kelompok\t: - Abyan Rasyid Aryadi    (1810631170081)\n"
        <<"                          - Reza Satria Pamungkas  (1810631170242)\n"
        <<"    Kelas\t\t: 2-F\n"
        <<"    Mata Kuliah\t\t: Algoritma dan Pemrograman\n\n";
    garis();cout<<endl<<endl;
}
struct nasabah
{
    char nama[50];
    char alamat[30];
    int norek;
    double saldo;
};
class pin{
private :
    int kode(){
        return 123;
    }
public :
    int kode_pin(){
        return kode();
    }
};
int main()
{
    nasabah nas[50];
    int n=0;
    int i,pil,x,pos,pin_input;
    int no;
    double setor,tarik;
    bool ketemu=false;
    pin kode;
    header();
    cout<<"Masukkan Kode Pin Anda\t: ";cin>>pin_input;
    sub_menu:
    if (pin_input==kode.kode_pin())
    {
        menu:
        system("cls");
            header();
            garis();
            cout<<"I----------------------------------------------------I"<<endl;
            cout<<"|                   Bank C'Squad                     |"<<endl;
            cout<<"|----------------------------------------------------|"<<endl;
            cout<<"|-------------------Menu Transaksi-------------------|"<<endl;
            cout<<"|                                                    |"<<endl;
            cout<<"|    1. Pendaftaran Nasabah                          |"<<endl;
            cout<<"|    2. Menabung                                     |"<<endl;
            cout<<"|    3. Penarikan                                    |"<<endl;
            cout<<"|    4. Cetak Daftar Nasabah                         |"<<endl;
            cout<<"|    5. Cari Nasabah                                 |"<<endl;
            cout<<"|    6. Keluar                                       |"<<endl;
            cout<<"|                                                    |"<<endl;
            cout<<"|                                    (0)Back To Menu |"<<endl;
            cout<<"I----------------------------------------------------I"<<endl;
            cout<<" \n Masukkan Pilihan Anda : "; cin>>pil;
            if(pil==1)
                {
                    lagi:
                    cout<<endl;
                    garis();
                    cout<<" Masukan Nomer Rekening : "; cin>>no;
                    for(i=0; i<n; i++)
                        {
                            if(no==nas[i].norek)
                            ketemu=true;
                            else
                            ketemu=false;
                        }
                            if(ketemu)
                            {
                                cout<<" Nomer Rekening Tersebut Sudah Ada, Ulangi Lagi"<<endl;
                                goto lagi;
                            }
                            else
                                {
                                    garis();
                                    cout<<" Masukan Nama Anda      : "; cin>>nas[n].nama;
                                    cout<<" Masukan Alamat         : "; cin>>nas[n].alamat;
                                    cout<<" Masukan Saldo Awal     : Rp."; cin>>nas[n].saldo;
                                }
                                    n=n+1;
                                    nas[i].norek=no;
                                garis();
                                cout<<" Masukkan Angka 0 Untuk Kembali Ke Menu Utama : "; cin>>x;
                                goto menu;
                    }
                else if(pil==2)
                    {
                        cout<<endl;
                        cout<<"======================================================"<<endl;
                        cout<<" Masukan Nomer Rekening  : "; cin>>no;
                        for(i=0; i<n; i++)
                            {
                                if(no==(nas[i].norek))
                                    {
                                        pos=i;
                                        ketemu=true;
                                        break;
                                    }
                                else
                                    ketemu=false;
                            }
                        if(ketemu)
                            {
                                garis();
                                cout<<" Masukan Nominal Setoran : Rp."; cin>>setor;
                                nas[pos].saldo=nas[pos].saldo+setor;
                                cout<<"\n Setoran Berhasil\n"<<endl;
                                cout<<" Jumlah Saldo Anda       : Rp."<<nas[pos].saldo<<endl;
                                cout<<endl;
                            }
                        else
                            cout<<" Nomer Rekening Tidak Ditemukan"<<endl<<endl;
                            cout<<" Masukkan Angka 0 Untuk Kembali Ke Menu Utama : "; cin>>x;
                            goto menu;
                    }
                else if(pil==3)
                    {
                        cout<<endl;
                        garis();
                        cout<<" Masukan Nomer Rekening   : "; cin>>no;
                        for(i=0; i<n; i++)
                            {
                                if(no==(nas[i].norek))
                                    {
                                        pos=i;
                                        ketemu=true;
                                        break;
                                    }
                                else
                                    ketemu=false;
                            }
                                if(ketemu)
                                    {
                                        garis();
                                        cout<<" Masukan Jumlah Penarikan : Rp."; cin>>tarik;
                                        if(tarik<(nas[pos].saldo))
                                            {
                                                nas[pos].saldo=nas[pos].saldo-tarik;
                                                cout<<" \nPenarikan Berhasil\n"<<endl;
                                                cout<<" Sisa Saldo Anda          : Rp."<<nas[pos].saldo<<endl;
                                                cout<<endl;
                                            }
                                        else
                                            cout<<" Maaf Saldo Anda Tidak Mencukupi"<<endl;
                                    }
                                else
                                    cout<<" Nomer Rekening Tidak Ditemukan"<<endl<<endl;
                                    cout<<" Masukan Angka 0 Untuk Kembali Ke Menu Utama : "; cin>>x;
                                    goto menu;
                    }
                else if(pil==4)
                    {
                        cout<<endl;
                        cout<<"I======================================================================I"<<endl;
                        cout<<"|                            DAFTAR NASABAH BANK                       |"<<endl;
                        cout<<"|====|=================|==============|==============|=================|"<<endl;
                        cout<<"| No |   No Rekening   |     Nama     |    Alamat    |   Total Saldo   |"<<endl;
                        cout<<"|====|=================|==============|==============|=================|"<<endl;
                        for(i=0; i<n; i++)
                            {
                                cout<<setw(4)<<i+1;;
                                cout<<setw(12)<<nas[i].norek;
                                cout<<setw(17)<<nas[i].nama;
                                cout<<setw(16)<<nas[i].alamat;
                                cout<<setw(16)<<(nas[i].saldo+10000)<<endl;
                            }
                                cout<<"I====I=================I==============I==============I=================I"<<endl<<endl;
                                cout<<" Jumlah Total Saldo Diatas Setelah Ditambah Bunga Rp10000"<<endl<<endl;
                                cout<<" Masukan Angka 0 Untuk Kembali Ke Menu Utama : "; cin>>x;
                                goto menu;
                    }
                else if(pil==5)
                    {
                        cout<<endl;garis();
                        cout<<" Masukan Nomer Rekening Yang Akan Dicari : "; cin>>no;
                        cout<<endl;
                        for(i=0; i<n; i++)
                            {
                                if(no==(nas[i].norek))
                                    {
                                        pos=i;
                                        ketemu=true;
                                        break;
                                    }
                                else
                                    ketemu=false;
                            }
                                if(ketemu)
                                    {
                                        cout<<" Nomer Rekening             : "<<nas[pos].norek<<endl;
                                        cout<<" Nama Nasabah               : "<<nas[pos].nama<<endl;
                                        cout<<" Alamat                     : "<<nas[pos].alamat<<endl;
                                        cout<<" Saldo                      : Rp."<<nas[pos].saldo<<endl;
                                        cout<<" Total Saldo Setelah Bunga  : Rp."<<(nas[i].saldo+10000)<<endl<<endl;
                                    }
                                else
                                    cout<<" Nomer Rekening Tidak Ditemukan"<<endl<<endl;
                                    cout<<" Masukan Angka 0 Untuk Kembali Ke Menu Utama : "; cin>>x;
                                    goto menu;
                    }
                else
                    {
                        cout<<endl<<" Terima Kasih Telah Menggunakan Bank Kami......"<<endl<<endl;
                    }
    }
        else
        {
            garis();
            cout<<"Pin Yang Anda Masukkan Salah!!!\n";
            garis();
        }
    getch();
}
