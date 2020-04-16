#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);
int knapSack(int W, int wt[], int p[], int n);

int main()
{
    int wt[] = {6, 5, 10, 5};
    int p[] = {12, 15, 50, 10};
    int W = 16;
    int n = sizeof(p) / sizeof(p[0]);
    cout << "Total Keuntungan = " << knapSack(W, wt, p, n);
    return 0;
}

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int p[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
    {
        return knapSack(W, wt, p, n - 1);
    }
    else
    {
        return max(p[n - 1] + knapSack(W - wt[n - 1], wt, p, n - 1),
                   knapSack(W, wt, p, n - 1));
    }
}