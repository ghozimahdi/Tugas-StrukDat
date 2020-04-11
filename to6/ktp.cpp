#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int tgl;
    int bln;
    int th = 0;
} Tanggal;

typedef struct
{
    string noID;
    string nama;
    string jenis_kelamin; //’L’ atau ‘P’
    Tanggal t;
} KTP;

typedef struct
{
    KTP *ktp;
    int jml;
} Data_KTP;

Data_KTP data_ktp;
//Data_KTP *p = &data_ktp;
KTP b;
KTP *k = &b;

void tambahData();
void cariDataByTahun();
void showDataByGender();
void editData();
Tanggal splitTgl(string tgl);

int main()
{
    char pilih;
    do
    {
        system("cls");
        cout << "Program KTP" << endl;
        cout << "1. Menambah Data" << endl;
        cout << "2. Mencari Data by Tahun" << endl;
        cout << "3. Menampilkan Data by L/P" << endl;
        cout << "4. Edit Data" << endl;
        cout << "5. Exit" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case '1':
            tambahData();

            for (int i = 0; i < data_ktp.jml; i++)
            {
                cout << k->nama << endl;
                k++;
            }
            break;
        case '2':
            cariDataByTahun();
            break;
        case '3':
            showDataByGender();
            break;
        case '4':
            editData();
            break;
        case '5':
            exit(0);
            break;

        default:
            system("cls");
            cout << "Pilihan Tidak tersedia" << endl;
            break;
        }
    } while (pilih != 5);

    return 0;
}

void tambahData()
{
    system("pause");
    cout << "Masukan Jumlah Data yang diinput : ";
    cin >> data_ktp.jml;

    KTP ktp[data_ktp.jml];
    data_ktp.ktp = ktp;
    k = ktp;

    int i = 0;
    do
    {
        string tgl;

        cout << "Masukan No ID : ";
        cin >> ktp[i].noID;
        cout << "Masukan Nama : ";
        cin >> ktp[i].nama;
        cout << "Masukan Jenis Kelamin (L/P) : ";
        cin >> ktp[i].jenis_kelamin;
        cout << "Masukan Tanggal Lahir (tgl/bln/thn)/(01/02/2022) : ";
        cin >> tgl;

        ktp[i].t = splitTgl(tgl);
        system("cls");
        i++;
    } while (i < data_ktp.jml);

    system("pause");
}

void cariDataByTahun()
{
    system("pause");

    KTP *ktp = data_ktp.ktp;

    char jawaban;
    do
    {
        system("cls");
        int tahun;
        cout << "Masukan Tahun : ";
        cin >> tahun;
        bool found = false;

        for (int i = 0; i < data_ktp.jml; i++)
        {
            Tanggal tgl = ktp->t;
            cout << tgl.tgl << endl;
            cout << ktp->nama << endl;
            cout << ktp->t.th << endl;
            // if (tahun == thn)
            // {
            //     found = true;
            //     cout << "Data di temukan : " << endl;
            //     //printf("Nomor Induk : %d\n", p->ktp->noID);
            //     //printf("Nama : %d\n", p->ktp->nama);

            //     if (p->ktp->jenis_kelamin == "L")
            //     {
            //         //printf("Jenis Kelamin : %d\n", "Laki - Laki");
            //     }
            //     else if (p->ktp->jenis_kelamin == "P")
            //     {
            //         //printf("Jenis Kelamin : %d\n", "Perempuan");
            //     }
            //     cout << "Tanggal Lahir : " << p->ktp->t.tgl << "/" << p->ktp->t.bln << "/" << p->ktp->t.th << endl;
            //     break;
            // }

            // cout << p->ktp->nama << endl;

            ktp++;
        }

        if (found)
            cout << "Data tidak ditemukan." << endl;

        cout << "Cari lagi gak ? (y/n) : ";
        cin >> jawaban;

    } while (jawaban != 'n');
    system("pause");
}

void showDataByGender()
{
}

void editData()
{
}

Tanggal splitTgl(string tgl)
{
    Tanggal tanggal;
    string delimiter = "/";

    size_t pos = 0;
    string t;
    int i = 0;
    while ((pos = tgl.find(delimiter)) != string::npos)
    {
        t = tgl.substr(0, pos);

        if (i == 0)
        {
            tanggal.tgl = stoi(t);
        }
        else if (i == 1)
        {
            tanggal.bln = stoi(t);
        }

        tgl.erase(0, pos + delimiter.length());
        i++;
    }
    tanggal.th = stoi(tgl);
    return tanggal;
}