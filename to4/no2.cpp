#include <iostream>
#include <array>
#include <string>
using namespace std;

string charAndNumCounter(string sentences);

void charFind(string sentences);

int main()
{

    string sentences;

    cout << "Masukan Kalimat = ";
    getline(cin, sentences);

    charFind(charAndNumCounter(sentences));

    system("pause");
    return 0;
}

string charAndNumCounter(string sentences)
{
    const string vowel = "aiueoAIUEO",
                 consonant = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ",
                 numeric = "0123456789";

    string lineOfVowel, lineOfcons, lineOfNum;

    int vowelCount = 0,
        consonantCount = 0,
        numericCount = 0;

    for (int i = 0; i < sentences.length(); i++)
    {
        for (int j = 0; j < vowel.length(); j++)
        {
            if (sentences[i] == vowel[j])
            {
                vowelCount += 1;
                lineOfVowel += sentences[i];
            }
        }

        for (int k = 0; k < consonant.length(); k++)
        {
            if (sentences[i] == consonant[k])
            {
                consonantCount += 1;
                lineOfcons += sentences[i];
            }
        }

        for (int l = 0; l < numeric.length(); l++)
        {
            if (sentences[i] == numeric[l])
            {
                numericCount += 1;
                lineOfNum += sentences[i];
            }
        }
    }

    cout << "Jumlah huruf Vokal     = " << vowelCount << " = " << lineOfVowel << endl;
    cout << "Jumlah huruf Konsonan  = " << consonantCount << " = " << lineOfcons << endl;

    if (numericCount != 0)
    {
        cout << "Jumlah Numerik         = " << numericCount << " = " << lineOfNum << endl;
    }
    else
    {
        cout << "Jumlah Numerik         = " << numericCount << endl;
    }

    return sentences;
}

void charFind(string sentences)
{
    char findVal;
    bool found = false;
    int i;
    cout << "Masukan karakter yang ingin dicari = ";
    cin >> findVal;

    for (i = 0; i < sentences.length(); i++)
    {
        if (findVal == sentences[i])
        {
            cout << findVal << " ditemukan pada urutan string ke " << i + 1 << endl;
            found = true;
        }
    }

    if (found == false)
    {
        cout << findVal << " tidak ditemukan \n";
    }
}