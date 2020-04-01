#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int dataKu[100], dataKu2[100];
int n;

void tukar(int a, int b)
{
    int t;
    t = dataKu[b];
    dataKu[b] = dataKu[a];
    dataKu[a] = t;
}

void bubble_sort()
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (dataKu[j] < dataKu[j - 1])
                tukar(j, j - 1);
        }
    }
    cout << "bubble sort selesai" << endl;
}

void exchange_sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = (i + 1); j < n; j++)
        {
            if (dataKu[i] > dataKu[j])
                tukar(i, j);
        }
    }
    cout << "exchange sort selesai" << endl;
}

void selection_sort()
{
    int pos, i, j;
    for (i = 0; i < n - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (dataKu[j] < dataKu[pos])
                pos = j;
        }
        if (pos != i)
            tukar(pos, i);
    }
    cout << "selection sort selesai" << endl;
}

void insertion_sort()
{
    int temp, i, j;
    for (i = 1; i < n; i++)
    {
        temp = dataKu[i];
        j = i - 1;
        while (dataKu[j] > temp && j >= 0)
        {
            dataKu[j + 1] = dataKu[j];
            j--;
        }
        dataKu[j + 1] = temp;
    }
    cout << "insertion sort selesai" << endl;
}

void quickSort(int l, int r)
{
    int i, j;
    int mid;
    i = l;
    j = r;
    mid = dataKu[(l + r) / 2];
    do
    {
        while (dataKu[i] < mid)
            i++;
        while (dataKu[j] > mid)
            j--;
        if (i <= j)
        {
            tukar(i, j);
            i++;
            j--;
        }
    } while (i < j);
    if (l < j)
        quickSort(l, j);
    if (i < r)
        quickSort(i, r);
}

void input()
{
    cout << "Masukan jumlah data = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Masukan data ke - " << (i + 1) << " = ";
        cin >> dataKu[i];
        dataKu2[i] = dataKu[i];
    }
}

void tampil()
{
    cout << "Data : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << dataKu[i] << " ";
    }
    cout << endl;
}

void acakLagi()
{
    for (int i = 0; i < n; i++)
    {
        dataKu[i] = dataKu2[i];
    }
    cout << "Data sudah teracak!" << endl;
}

int main()
{
    int pil;
    system("cls");

    do
    {
        system("cls");
        system("title program sorting");
        cout << "Menu sorting" << endl;
        cout << "*********************" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Exchange Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Insertion Sort" << endl;
        cout << "6. Quick Sort" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Acak Data" << endl;
        cout << "9. Exit" << endl;
        cout << "   Pilihan Anda = ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            input();
            break;
        case 2:
            bubble_sort();
            break;
        case 3:
            exchange_sort();
            break;
        case 4:
            selection_sort();
            break;
        case 5:
            insertion_sort();
            break;
        case 6:
            quickSort(0, n - 1);
            break;
        case 7:
            tampil();
            break;
        case 8:
            acakLagi();
            break;
        case 9:
            exit(0);
            break;
        }
    } while (pil != 9);

    return 0;
}