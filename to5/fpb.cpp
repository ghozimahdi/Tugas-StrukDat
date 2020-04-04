#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int calcFPB(int bil1, int bil2);

int main()
{
    int bil1, bil2;

    cout << "Masukan Bilangan 1 : ";
    cin >> bil1;

    cout << "Masukan Bilangan 2 : ";
    cin >> bil2;

    system("pause");

    cout << "FPB bilangan 1 dan 2 adalah: " << calcFPB(bil1, bil2) << endl;
    return 0;
}

int calcFPB(int bil1, int bil2)
{
    int r = bil1 % bil2;
    if (r != 0)
    {
        bil1 = bil2;
        bil2 = r;
        r = bil1 % bil2;
        return calcFPB(bil1, bil2);
    }
    return bil2;
}