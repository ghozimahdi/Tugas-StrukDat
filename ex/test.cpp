#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define max 99
using namespace std;

typedef struct
{
    int tanggal;
    int bulan;
    int tahun;

} TanggalLahir;

typedef struct
{
    char noID[max];
    char nama[max];
    char jenisKelamin; //’L’ atau ‘P’
    TanggalLahir tanggalLahir;

} ResidentId;

typedef struct
{
    ResidentId ktp[max];
    int jumlah;

} IdData;

IdData data_ktp, *dataptr;

int printAll()
{
    system("cls");
    for (int i = 0; i < (*dataptr).jumlah; i++)
    {
        cout << "-------------------------------------------------\n";
        cout << " Data " << (i + 1) << endl
             << endl;
        cout << " No.ID              = " << (*dataptr).ktp[i].noID << endl;
        cout << " Nama               = " << (*dataptr).ktp[i].nama << endl;
        cout << " Jenis Kelamin      = " << (*dataptr).ktp[i].jenisKelamin << endl;
        cout << " Tanggal Lahir      = " << (*dataptr).ktp[i].tanggalLahir.tanggal << endl;
        cout << " Bulan Lahir        = " << (*dataptr).ktp[i].tanggalLahir.bulan << endl;
        cout << " Tahun Lahir        = " << (*dataptr).ktp[i].tanggalLahir.tahun << endl;
        cout << "-------------------------------------------------\n";
    }

    return 0;
}

void tambahData()
{
    system("cls");
    dataptr = &data_ktp;

    cout << " Masukan jumlah data yang ingin diinput = ";
    cin >> (*dataptr).jumlah;
    (*dataptr).ktp[(*dataptr).jumlah];
    for (int i = 0; i < (*dataptr).jumlah; i++)
    {
        cout << "-------------------------------------------------\n";
        cout << " Data " << (i + 1) << endl;
        cout << "Masukan No.ID              = ";
        cin >> (*dataptr).ktp[i].noID;
        cout << "Masukan Nama               = ";
        cin.ignore(10, '\n');
        cin.getline((*dataptr).ktp[i].nama, 30);
        cout << "Masukan Jenis Kelamin      = ";
        cin >> (*dataptr).ktp[i].jenisKelamin;

        (*dataptr).ktp[i].jenisKelamin = toupper((*dataptr).ktp[i].jenisKelamin);

        cout << "Masukan Tanggal Lahir      = ";
        cin >> (*dataptr).ktp[i].tanggalLahir.tanggal;
        cout << "Masukan Bulan Lahir        = ";
        cin >> (*dataptr).ktp[i].tanggalLahir.bulan;
        cout << "Masukan Tahun Lahir        = ";
        cin >> (*dataptr).ktp[i].tanggalLahir.tahun;
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

    printAll();

    cout << " Masukan Tahun kelahiran yang ingin ditampilkan = ";
    cin >> year;
    system("cls");
    for (int i = 0; i < (*dataptr).jumlah; i++)
    {
        if (*yearptr != (*dataptr).ktp[i].tanggalLahir.tahun)
            continue;

        cout << "-------------------------------------------------\n";
        cout << " Data " << (i + 1) << endl
             << endl;
        cout << " No.ID              = " << (*dataptr).ktp[i].noID << endl;
        cout << " Nama               = " << (*dataptr).ktp[i].nama << endl;
        cout << " Jenis Kelamin      = " << (*dataptr).ktp[i].jenisKelamin << endl;
        cout << " Tanggal Lahir      = " << (*dataptr).ktp[i].tanggalLahir.tanggal << endl;
        cout << " Bulan Lahir        = " << (*dataptr).ktp[i].tanggalLahir.bulan << endl;
        cout << " Tahun Lahir        = " << (*dataptr).ktp[i].tanggalLahir.tahun << endl;
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
    for (int i = 0; i < (*dataptr).jumlah; i++)
    {
        if (*gendPtr != (*dataptr).ktp[i].jenisKelamin)
            continue;

        cout << "-------------------------------------------------\n";
        cout << " Data " << (i + 1) << endl
             << endl;
        cout << " No.ID              = " << (*dataptr).ktp[i].noID << endl;
        cout << " Nama               = " << (*dataptr).ktp[i].nama << endl;
        cout << " Jenis Kelamin      = " << (*dataptr).ktp[i].jenisKelamin << endl;
        cout << " Tanggal Lahir      = " << (*dataptr).ktp[i].tanggalLahir.tanggal << endl;
        cout << " Bulan Lahir        = " << (*dataptr).ktp[i].tanggalLahir.bulan << endl;
        cout << " Tahun Lahir        = " << (*dataptr).ktp[i].tanggalLahir.tahun << endl;
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

    printAll();

    cout << " Masukan nomor Data yang ingin diubah = ";
    cin >> *dataNumberPtr;
    *dataNumberPtr -= 1;
    cout << "-------------------------------------------------\n";
    cout << " Data " << (*dataNumberPtr + 1) << endl;
    cout << "Masukan No.ID              = ";
    cin >> (*dataptr).ktp[*dataNumberPtr].noID;
    cout << "Masukan Nama               = ";
    cin.ignore(10, '\n');
    cin.getline((*dataptr).ktp[*dataNumberPtr].nama, 30);
    cout << "Masukan Jenis Kelamin      = ";
    cin >> (*dataptr).ktp[*dataNumberPtr].jenisKelamin;

    (*dataptr).ktp[*dataNumberPtr].jenisKelamin = toupper((*dataptr).ktp[*dataNumberPtr].jenisKelamin);

    cout << "Masukan Tanggal Lahir      = ";
    cin >> (*dataptr).ktp[*dataNumberPtr].tanggalLahir.tanggal;
    cout << "Masukan Bulan Lahir        = ";
    cin >> (*dataptr).ktp[*dataNumberPtr].tanggalLahir.bulan;
    cout << "Masukan Tahun Lahir        = ";
    cin >> (*dataptr).ktp[*dataNumberPtr].tanggalLahir.tahun;
    cout << "-------------------------------------------------\n";

    cout << "   --done!--\n";
    system("pause");
}

int main()
{
    int select;

    do
    {
        system("cls");
        cout << "-------- Pointer to Struct data Manipulation --------" << endl;
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
            printAll();
            cout << "   --done!--\n";
            system("pause");
            break;
        }

    } while (select != 6);

    system("cls");
    cout << " Nama  : Aulia Ilham Zukri\n";
    cout << " NIM   : 20190801368\n";
    cout << " ----------------------------------\n";
    cout << "           -Terimakasih- " << endl;
    system("pause");
    return 0;
}