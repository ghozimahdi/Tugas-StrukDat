#include <iostream>
#include <string>
#include <iterator>
using namespace std;

bool check_number(string str)
{
  for (int i = 0; i < str.length(); i++)
    if (isdigit(str[i]) == false)
      return false;
  return true;
}

int main()
{
  int n;
  cout << "Masukan jumlah Nilai : ";
  cin >> n;

  int nilai[n] = {};
  double rata2 = 0;

  int index = 0;
  string value;

  do
  {
    cout << "Masukan nilai ke " << index + 1 << " : ";
    cin >> value;

    if (check_number(value))
    {
      nilai[index] = stoi(value);
      index = index + 1;
    }else{
      cout << "Tolong masukan angka yaa!!";
    }

  } while (index < n);

  for (int i = 0; i < n; i++)
  {
    rata2 = rata2 + nilai[i];
  }

  double rataAkhir = rata2 / n;
  cout << "Nilai Rata-Rata Adalah : " << rataAkhir;

  return 0;
}