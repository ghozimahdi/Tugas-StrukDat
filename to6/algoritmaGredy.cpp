#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

void Koin(int x[], int i);

int main()
{
    cout << "======================== \n";
    cout << "Ghozi Mahdi \n20190801355 \n";
    cout << endl;

    int x[100], i, koin, n, hasil[100];
    cout << "Masukkan Banyak Koin : ";
    cin >> n;
    cout << endl;

    for (i = 1; i <= n; i++)
    {
        cout << "Masukkan Koin " << i << " : ";
        cin >> x[i];
    }
    cout << endl;

    system("cls");
    Koin(x, n);
    cout << "Koin Yang Tersedia : " << endl;

    for (i = 1; i <= n; i++)
    {
        cout << x[i];
        cout << endl;
    }
    cout << endl;
    cout << "Masukkan Koin Yang Ingin Ditukar : ";
    cin >> koin;
    cout << endl;

    for (i = 1; i <= n; i++)
    {
        hasil[i] = koin / x[i];
        koin = koin % x[i];
    }

    for (i = 1; i <= n; i++)
    {
        cout << "Koin " << x[i];
        cout << " sebanyak : " << hasil[i];
        cout << endl;
    }

    system("pause");
    return 0;
}

void Koin(int x[], int i)
{
    int a, b, j;
    for (a = 1; a <= i - 1; a++)
    {
        for (j = 0; j <= i - 2; j++)
        {
            if (x[j + 1] < x[j + 2])
            {
                b = x[j + 1];
                x[j + 1] = x[j + 2];
                x[j + 2] = b;
            }
        }
    }
}