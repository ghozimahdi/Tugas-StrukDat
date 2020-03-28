#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

struct Gaji
{
    string nama;
    int jamKerja, jamLembur;
    const int gajiPerjam = 50000;
    const int gajiLemburPerjam = 15 * gajiPerjam;

} gaji;

void generateLine(int size);

int main()
{
    int totalGaji, gajiNormal, gajiLembur;

    cout << "Masukkan Nama Karyawan : ";
    getline(cin, gaji.nama);

    cout << "Masukkan Jam Kerja     : ";
    cin >> gaji.jamKerja;

    if (gaji.jamKerja <= 7)
    {
        totalGaji = gaji.jamKerja * gaji.gajiPerjam;
    }
    else
    {
        gaji.jamLembur = gaji.jamKerja - 7;
        gajiNormal = 7 * gaji.gajiPerjam;
        gajiLembur = gaji.jamLembur * gaji.gajiLemburPerjam;
        totalGaji = gajiNormal + gajiLembur;
    }

    system("cls");
    system("pause");

    cout << "Nama Karyawan  : " << gaji.nama << "\n";
    cout << "Jam Kerja      : " << gaji.jamKerja << "\n";
    cout << "Jam Lembur     : " << gaji.jamLembur << "\n";
    cout << "Total Gaji     : " << totalGaji << "\n";
    generateLine(33);
    cout << "Ghozi Mahdi \n"
            "20190801355 \n";

    return 0;
}

void generateLine(int size)
{
    for (int i; i < size; i++)
        cout << "=";
    cout << '\n';
}
