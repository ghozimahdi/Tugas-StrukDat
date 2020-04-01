#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int reverseNumber(int bil, int reverse = 0);

int main()
{
    int bil;
    cout << "Input Bilangan : ";
    cin >> bil;

    cout << "Bilangan = " << bil << endl;
    system("pause");
    cout << "Jika dibalik adalah = " << reverseNumber(bil);
    return 0;
}

int reverseNumber(int bil, int reverse)
{
    int myReverse = reverse;
    if (bil != 0)
    {
        myReverse = myReverse * 10;
        myReverse = myReverse + bil % 10;
        bil /= 10;
        return reverseNumber(bil, myReverse);
    }
    return myReverse;
}