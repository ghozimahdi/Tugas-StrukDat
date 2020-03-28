#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));
    set<int> arr;

    for (int i = 0; i < 5; i++)
    {
        arr.insert(rand() % 100 + 1);
    }

    system("cls");

    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout << ' ' << *i;
    }

    system("cls");

    return 0;
}