#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int deretKasus1(int n);
int deretKasus2(int n);
int deretKasus3(int n);
long fungsiPangkat(long bil, int pangkat);

int main()
{
    int pilih;
    do
    {
        system("cls");
        cout << "Tugas Rekursif" << endl;
        cout << "1. Kasus 1" << endl;
        cout << "2. Kasus 2" << endl;
        cout << "3. Kasus 3" << endl;
        cout << "4. Kasus 4" << endl;
        cout << "5. Keluar" << endl;
        cout << "pilih : ";
        cin >> pilih;

        int n;

        switch (pilih)
        {
        case 1:
            system("cls");
            cout << "Deret S=1+2+3+4+5+...+n \n";
            cout << "Masukan n = ";
            cin >> n;
            cout << "Jumlah deret S = " << deretKasus1(n) << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Deret S = 2+4+6+8+10+...+2n \n";
            cout << "Masukan n = ";
            cin >> n;
            cout << "Jumlah deret S = " << deretKasus2(n) << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Deret S = 1+3+5+7+9+...+n \n";
            cout << "Masukan n = ";
            cin >> n;
            cout << "Jumlah deret S = " << deretKasus3(n) << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            int pangkat;
            int bil;
            cout << "Fungsi Pangkat \n";
            cout << "Masukan bil = ";
            cin >> bil;
            cout << "Masukan pangkatnya = ";
            cin >> pangkat;
            cout << "Hasil dari " << bil << " Pangkat " << pangkat << " adalah " << fungsiPangkat(bil, pangkat) << endl;
            system("pause");
            break;
        case 5:
            cout << "GoodBye \n";
            exit(0);
            break;

        default:
            break;
        }
    } while (pilih != 5);
}

int deretKasus1(int n)
{
    if (n == 1)
    {
        return n;
    }
    else
    {
        return (n + deretKasus1(n - 1));
    }
}

int deretKasus2(int n)
{
    if (n == 1)
    {
        return 2;
    }
    else
    {
        return (2 * n + deretKasus2(n - 1));
    }
}

int deretKasus3(int n)
{
    if (n == 1)
    {
        return n;
    }
    else
    {
        return (n + (n - 1) + deretKasus3(n - 1));
    }
}

long fungsiPangkat(long bil, int pangkat)
{
    if (pangkat == 0)
    {
        return 1;
    }
    else
    {
        return bil * fungsiPangkat(bil, pangkat - 1);
    }
}