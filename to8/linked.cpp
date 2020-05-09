#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct Buku
{
    int id;
    string nama;
    int harga;
    Buku *next;
} Buku;

Buku *head;
Buku *tail;
Buku *baru;
Buku *hapus;
Buku *bantu;

int isEmpty();
void tambahbelakang(Buku databaru);
void cetak();
void hapusbelakang();
void editData(int id, int hargaBaru);

int main()
{
    head = new Buku;
    head = NULL;

    int input;
    do
    {
        system("cls");
        printf("Tugas Perkuliahan Sesi 8\n");
        printf("Menu : \n");
        printf("1. Tambah Buku \n");
        printf("2. Ubah Harga Buku \n");
        printf("3. Tampilkan Semua Buku \n");
        printf("4. Keluar \n");
        printf("Pilih Menu : ");
        cin >> input;

        char jwb;
        switch (input)
        {
        case 1:
            printf("Anda di menu Tambah Buku  \n");
            do
            {
                system("cls");
                Buku buku;
                printf("Masukan id : ");
                cin >> buku.id;
                printf("Masukan nama : ");
                cin >> buku.nama;
                printf("Masukan harga : ");
                cin >> buku.harga;
                system("cls");
                tambahbelakang(buku);
                printf("Ingin tambah buku lagi? (y/n) : ");
                cin >> jwb;
            } while (jwb != 'n');
            break;
        case 2:
            if (isEmpty())
            {
                cout << "Daftar buku masih kosong" << endl;
            }
            else
            {

                printf("Anda di menu ubah harga buku  \n");
                do
                {
                    system("cls");
                    int id;
                    int newHarga;
                    printf("Masukan id : ");
                    cin >> id;
                    printf("Masukan harga baru : ");
                    cin >> newHarga;

                    system("cls");
                    editData(id, newHarga);
                    printf("Ingin ubah harga buku lagi? (y/n) : ");
                    cin >> jwb;
                } while (jwb != 'n');
            }
            break;
        case 3:
            cetak();
            break;
        case 4:
            system("cls");
            printf("Keluar Aplikasi\n");
            exit(0);
            break;
        default:
            printf("Pilihan Menu Tidak Tersedia!\n");
            system("pause");
            break;
        }
    } while (input != 4);

    return 0;
}

void tambahbelakang(Buku databaru)
{
    baru = new Buku;

    baru->id = databaru.id;
    baru->nama = databaru.nama;
    baru->harga = databaru.harga;

    baru->next = baru;
    if (isEmpty())
    {
        head = tail = baru;
        head->next = head;
        tail->next = tail;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    printf("buku berhasil ditambahkan\n");
}

void printBuku(Buku buku)
{
    cout << "Buku [ id = " << buku.id << ", nama = " << buku.nama << ", harga = " << buku.harga << " ]\n";
}

void cetak()
{
    if (!isEmpty())
    {
        bantu = head;
        printBuku(*bantu);
        bantu = bantu->next;
        while (bantu != head)
        {
            printBuku(*bantu);
            bantu = bantu->next;
        }
        printf("\n");
    }
    else
    {
        cout << "Data kosong !" << endl;
    }
}

void editData(int id, int hargaBaru)
{
    if (!isEmpty())
    {
        bantu = head;
        if (bantu->id == id)
        {
            bantu->harga = hargaBaru;
        }
        bantu = bantu->next;
        while (bantu != head)
        {
            if (bantu->id == id)
            {
                bantu->harga = hargaBaru;
            }
            bantu = bantu->next;
        }
        cout << "harga buku " << id << " berhasil di ubah\n";
    }
    else
    {
        printf("Data kosong !\n");
    }
}

int isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}