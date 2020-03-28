#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int l, int r, int x);

void sequentialSearch(int arr1[], int req);

void showArray(int arr[], int n);

vector<int> getRandom();

int main()
{
    int pilih;
    int req;

    int arr[5];
    vector<int> v = getRandom();
    copy(v.begin(), v.end(), arr);

    // cout << "Enter 5 numbers in array: " << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cin >> arr[i];
    // }

    cout << endl;
    cout << "Masukan nilai yang ingin dicari :";
    cin >> req;
    cout << endl;
    cout << "Nilai yang dicari = " << req << endl;
    system("cls");

    cout << "Silahkan pilih methode pencarian" << endl;
    cout << "1. BinarySearch" << endl;
    cout << "2. SequentialSearch" << endl;
    cout << "#contoh input 1/2..." << endl;
    cout << "pilih : ";
    cin >> pilih;
    cout << endl;

    if (pilih == 1)
    {
        int n = sizeof(arr) / sizeof(arr[0]);
        //sort(arr, arr + n);
        //showArray(arr, n);
        int result = binarySearch(arr, 0, n - 1, req);
        (result == -1) ? cout << "Number tidak ditemukan"
                       : cout << "Number ditemukan di urutan ke : " << result + 1;
    }
    else if (pilih == 2)
    {
        sequentialSearch(arr, req);
    }
    else
    {
        cout << "Pilihan tidak tersedia";
    }
    return 0;
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }
    return -1;
}

void sequentialSearch(int arr1[], int req)
{
    int location = -5;

    for (int w = 0; w < 5; w++)
    {
        if (arr1[w] == req)
            location = w;
    }
    if (location != -5)
    {
        cout << "Number ditemukan di urutan ke : " << location + 1;
        cout << endl;
    }
    else
        cout << "Number tidak ditemukan";
}

void showArray(int arr[], int n)
{
    cout << "Array di sorting menjad : ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

vector<int> getRandom()
{
    srand(time(NULL));
    set<int> arr;

    for (int i = 0; i < 5; i++)
    {
        arr.insert(rand() % 100 + 1);
    }

    cout << "Data Random : ";

    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout << ' ' << *i;
    }
    cout << endl;

    vector<int> v;
    v.reserve(arr.size());
    copy(arr.begin(), arr.end(), back_inserter(v));
    return v;
}