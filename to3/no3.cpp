#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

struct Alamat{
    string namaJalan, kota, provinsi;
    int nomorRumah;
};

struct TTL{
    string tempat, bulan;
    int tgl, tahun;
};


struct Mhs{
    string nama, nim;
    Alamat alamatMhs;
    TTL ttlMhs;
}mhs[5];

main(){
    Alamat alamat;
    TTL ttl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Mahasiswa " <<i+1 <<endl;
        cout << "Masukkan Nama Mahasiswa : ", cin.ignore(1), getline(cin, mhs[i].nama);
        cout << "Masukkan NIM            : ", cin >> mhs[i].nim, cout <<endl;
        cout << "Alamat" <<endl;
        cout << "Masukkan Nama Jalan     : ", cin.ignore(1,'\n'),getline(cin, mhs[i].alamatMhs.namaJalan);
        cout << "Masukkan Nomor Rumah    : ", cin >> mhs[i].alamatMhs.nomorRumah;
        cout << "Masukkan Kota           : ", cin.ignore(1,'\n'),getline(cin, mhs[i].alamatMhs.kota);
        cout << "Masukkan Provinsi       : ", getline(cin, mhs[i].alamatMhs.provinsi), cout <<endl;
        cout << "TTL" <<endl;
        cout << "Masukkan Tempat Lahir   : ", getline(cin, mhs[i].ttlMhs.tempat);
        cout << "Masukkan Tanggal        : ", cin >> mhs[i].ttlMhs.tgl;  
        cout << "Masukkan Bulan          : ", cin >> mhs[i].ttlMhs.bulan;
        cout << "Masukkan Tahun          : ", cin >> mhs[i].ttlMhs.tahun, cout <<endl;

        system("cls");
    }

    
    
    for (int i = 0; i < 3; i++)
    {  
        cout << "Mahasiswa " <<i+1 <<endl;
        cout << "Nama Mahasiswa : " <<mhs[i].nama <<endl;
        cout << "NIM            : " <<mhs[i].nim <<endl <<endl;
        cout << "Alamat"<<endl;
        cout << "Nama Jalan     : " <<mhs[i].alamatMhs.namaJalan <<endl;
        cout << "Nomor Rumah    : " <<mhs[i].alamatMhs.nomorRumah <<endl;
        cout << "Kota           : " <<mhs[i].alamatMhs.kota <<endl;
        cout << "Provinsi       : " <<mhs[i].alamatMhs.provinsi <<endl <<endl;
        cout << "TTL" <<endl;
        cout << "Tempat         : " <<mhs[i].ttlMhs.tempat <<endl;
        cout << "Tanggal        : " <<mhs[i].ttlMhs.tgl <<endl;  
        cout << "Bulan          : " <<mhs[i].ttlMhs.bulan <<endl;
        cout << "Tahun          : " <<mhs[i].ttlMhs.tahun <<endl;
        cout << "====================================" <<endl;
    }

    cout << "Ghozi Mahdi \n 20190801355 \n";
    
    system("pause");
    return 0;  
}
