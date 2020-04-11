#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define max 99
using namespace std;

typedef struct
{
    int tgl;
    int bln;
    int thn;

} Tanggal;

typedef struct
{
    char noID[max];
    char nama[max];
    char jenisKelamin; //’L’ atau ‘P’
    Tanggal t;

} KTP;

typedef struct
{
    KTP ktp[max];
    int jml;

} Data_KTP;

Data_KTP data_ktp, *p;

void editData();
int tampilkanData();
void tambahData();
void filterByYear();
void filterByGender();

int main()
{
    int select;

    do
    {
        system("cls");
        cout << "Program KTP" << endl;
        cout << " 1. Data Input " << endl;
        cout << " 2. Filter by Years of birth" << endl;
        cout << " 3. Filter by Gender" << endl;
        cout << " 4. Edit Data" << endl;
        cout << " 5. Show All data" << endl;
        cout << " 6. Exit" << endl
             << endl;

        cout << " Select = ";
        cin >> select;

        switch (select)
        {
        case 1:
            tambahData();
            break;

        case 2:
            filterByYear();
            break;

        case 3:
            filterByGender();
            break;

        case 4:
            editData();
            break;

        case 5:
            tampilkanData();
            cout << "   --done!--\n";
            system("pause");
            break;
        }

    } while (select != 6);

    system("cls");
    cout << " Nama  : Ghozi Mahdi\n";
    cout << " NIM   : 20190801355\n";
    cout << " ----------------------------------\n";
    system("pause");
    return 0;
}

int tampilkanData()
{
    system("cls");
    for (int i = 0; i < (*p).jml; i++)
    {
        cout << "-------------------------------------------------\n";
        cout << " Data " << (i + 1) << endl
             << endl;
        cout << " No.ID              = " << (*p).ktp[i].noID << endl;
        cout << " Nama               = " << (*p).ktp[i].nama << endl;
        cout << " Jenis Kelamin      = " << (*p).ktp[i].jenisKelamin << endl;
        cout << " Tanggal Lahir      = " << (*p).ktp[i].t.tgl << endl;
        cout << " Bulan Lahir        = " << (*p).ktp[i].t.bln << endl;
        cout << " Tahun Lahir        = " << (*p).ktp[i].t.thn << endl;
        cout << "-------------------------------------------------\n";
    }

    return 0;
}

void tambahData()
{
    system("cls");
    p = &data_ktp;

    cout << " Masukan jml data yang ingin diinput = ";
    cin >> (*p).jml;
    (*p).ktp[(*p).jml];
    for (int i = 0; i < (*p).jml; i++)
    {
        cout << "-------------------------------------------------\n";
        cout << " Data " << (i + 1) << endl;
        cout << "Masukan No.ID              = ";
        cin >> (*p).ktp[i].noID;
        cout << "Masukan Nama               = ";
        cin.ignore(10, '\n');
        cin.getline((*p).ktp[i].nama, 30);
        cout << "Masukan Jenis Kelamin      = ";
        cin >> (*p).ktp[i].jenisKelamin;

        (*p).ktp[i].jenisKelamin = toupper((*p).ktp[i].jenisKelamin);

        cout << "Masukan Tanggal Lahir      = ";
        cin >> (*p).ktp[i].t.tgl;
        cout << "Masukan Bulan Lahir        = ";
        cin >> (*p).ktp[i].t.bln;
        cout << "Masukan Tahun Lahir        = ";
        cin >> (*p).ktp[i].t.thn;
        cout << "-------------------------------------------------\n";
    }

    system("cls");
    cout << "   --done!--\n";
    system("pause");
}

void filterByYear()
{
    system("cls");
    int year, *yearptr;
    yearptr = &year;

    tampilkanData();

    cout << " Masukan Tahun kelahiran yang ingin ditampilkan = ";
    cin >> year;
    system("cls");
    for (int i = 0; i < (*p).jml; i++)
    {
        if (*yearptr != (*p).ktp[i].t.thn)
            continue;

        cout << "-------------------------------------------------\n";
        cout << " Data " << (i + 1) << endl
             << endl;
        cout << " No.ID              = " << (*p).ktp[i].noID << endl;
        cout << " Nama               = " << (*p).ktp[i].nama << endl;
        cout << " Jenis Kelamin      = " << (*p).ktp[i].jenisKelamin << endl;
        cout << " Tanggal Lahir      = " << (*p).ktp[i].t.tgl << endl;
        cout << " Bulan Lahir        = " << (*p).ktp[i].t.bln << endl;
        cout << " Tahun Lahir        = " << (*p).ktp[i].t.thn << endl;
        cout << "-------------------------------------------------\n";
    }

    cout << "   --done!--\n";
    system("pause");
}

void filterByGender()
{
    system("cls");
    char genderSelection, *gendPtr;
    gendPtr = &genderSelection;

    cout << " Masukan Jenis Kelamin yang ingin di Filter (L / P) = ";
    cin >> *gendPtr;
    *gendPtr = toupper(*gendPtr);

    system("cls");
    for (int i = 0; i < (*p).jml; i++)
    {
        if (*gendPtr != (*p).ktp[i].jenisKelamin)
            continue;

        cout << "-------------------------------------------------\n";
        cout << " Data " << (i + 1) << endl
             << endl;
        cout << " No.ID              = " << (*p).ktp[i].noID << endl;
        cout << " Nama               = " << (*p).ktp[i].nama << endl;
        cout << " Jenis Kelamin      = " << (*p).ktp[i].jenisKelamin << endl;
        cout << " Tanggal Lahir      = " << (*p).ktp[i].t.tgl << endl;
        cout << " Bulan Lahir        = " << (*p).ktp[i].t.bln << endl;
        cout << " Tahun Lahir        = " << (*p).ktp[i].t.thn << endl;
        cout << "-------------------------------------------------\n";
    }

    cout << "   --done!--\n";
    system("pause");
}

void editData()
{
    system("cls");

    int dataNumber, *dataNumberPtr;
    dataNumberPtr = &dataNumber;

    tampilkanData();

    cout << " Masukan nomor Data yang ingin diubah = ";
    cin >> *dataNumberPtr;
    *dataNumberPtr -= 1;
    cout << "-------------------------------------------------\n";
    cout << " Data " << (*dataNumberPtr + 1) << endl;
    cout << "Masukan No.ID              = ";
    cin >> (*p).ktp[*dataNumberPtr].noID;
    cout << "Masukan Nama               = ";
    cin.ignore(10, '\n');
    cin.getline((*p).ktp[*dataNumberPtr].nama, 30);
    cout << "Masukan Jenis Kelamin      = ";
    cin >> (*p).ktp[*dataNumberPtr].jenisKelamin;

    (*p).ktp[*dataNumberPtr].jenisKelamin = toupper((*p).ktp[*dataNumberPtr].jenisKelamin);

    cout << "Masukan Tanggal Lahir      = ";
    cin >> (*p).ktp[*dataNumberPtr].t.tgl;
    cout << "Masukan Bulan Lahir        = ";
    cin >> (*p).ktp[*dataNumberPtr].t.bln;
    cout << "Masukan Tahun Lahir        = ";
    cin >> (*p).ktp[*dataNumberPtr].t.thn;
    cout << "-------------------------------------------------\n";

    cout << "   --done!--\n";
    system("pause");
}