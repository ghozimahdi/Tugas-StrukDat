#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

int *toArray();

int main()
{
    int arr[5] = toArray();
    for (int i = 0; i < 5; i++)
        cout << arr[i] << '\n';

    return 0;
}

int *toArray()
{
    set<int> s = {1, 2, 3, 4, 5};

    vector<int> v;
    v.reserve(s.size());
    copy(s.begin(), s.end(), back_inserter(v));

    int arr[5];
    copy(v.begin(), v.end(), arr);

    return arr;
}