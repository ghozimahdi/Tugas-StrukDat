#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

struct Alamat
{
    string namaJalan, kota, provinsi;
    int nomorRumah;
} alamat;

struct TTL
{
    string tempat, bulan;
    int tgl, tahun;
} ttl;

struct Mhs
{
    string nama, nim;
    Alamat alamatMhs;
    TTL ttlMhs;
} mhs;

void generateLine(int size);

main()
{
    alamat.namaJalan = "Jl.Kesadaran";
    alamat.kota = "Kab. Tangerang";
    alamat.provinsi = "Banten";
    alamat.nomorRumah = 21;

    ttl.tempat = "Brebes";
    ttl.tgl = 23;
    ttl.bulan = "September";
    ttl.tahun = 1998;

    mhs.nama = "Ghozi Mahdi";
    mhs.nim = "20190801355";
    mhs.alamatMhs = alamat;
    mhs.ttlMhs = ttl;

    cout << "Nama Mahasiswa : " << mhs.nama << endl;
    cout << "NIM            : " << mhs.nim << endl
         << endl;
    cout << "Alamat" << endl;
    cout << "Nama Jalan     : " << mhs.alamatMhs.namaJalan << endl;
    cout << "Nomor Rumah    : " << mhs.alamatMhs.nomorRumah << endl;
    cout << "Kota           : " << mhs.alamatMhs.kota << endl;
    cout << "Provinsi       : " << mhs.alamatMhs.provinsi << endl
         << endl;
    cout << "TTL" << endl;
    cout << "Tempat         : " << mhs.ttlMhs.tempat << endl;
    cout << "Tanggal        : " << mhs.ttlMhs.tgl << endl;
    cout << "Bulan          : " << mhs.ttlMhs.bulan << endl;
    cout << "Tahun          : " << mhs.ttlMhs.tahun << endl;

    generateLine(33);

    cout << mhs.nama << '\n'
         << mhs.nim;

    return 0;
}

void generateLine(int size)
{
    for (int i; i < size; i++)
    {
        cout << "=";
    }
    cout << '\n';
}
