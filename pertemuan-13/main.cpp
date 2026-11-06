#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    char gender;
    float nilai;
    Mahasiswa *next;
};

Mahasiswa *head = nullptr;
Mahasiswa *tail = nullptr;

bool insertData(string nama, string nim, char gender, float nilai)
{
    Mahasiswa *baru = new Mahasiswa{nama, nim, gender, nilai, nullptr};

    // Jika list masih kosong
    if (head == nullptr)
    {
        head = tail = baru;
        baru->next = head;
        return true;
    }

    Mahasiswa *prev = nullptr;
    Mahasiswa *curr = head;

    // Cari posisi insert sekaligus cek NIM duplikat
    do
    {
        if (curr->nim == nim)
        {
            delete baru;
            return false; // NIM sudah ada
        }
        if (curr->nim > nim)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    // Insert di depan
    if (prev == nullptr)
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
    else
    {
        // Insert di tengah atau di akhir
        prev->next = baru;
        baru->next = curr;

        if (prev == tail)
        {
            tail = baru;
            tail->next = head;
        }
    }

    return true;
}

bool hapusData(string nim)
{
    if (head == nullptr)
    {
        return false;
    }

    Mahasiswa *prev = tail;
    Mahasiswa *curr = head;

    do
    {
        if (curr->nim == nim)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    // Tidak ditemukan
    if (curr->nim != nim)
    {
        return false;
    }

    // Jika hanya satu simpul
    if (head == tail)
    {
        delete curr;
        head = tail = nullptr;
    }
    // Hapus simpul awal
    else if (curr == head)
    {
        head = curr->next;
        tail->next = head;
        delete curr;
    }
    // Hapus simpul akhir
    else if (curr == tail)
    {
        prev->next = head;
        tail = prev;
        tail->next = head;
        delete curr;
    }
    // Hapus simpul tengah
    else
    {
        prev->next = curr->next;
        delete curr;
    }

    return true;
}

void cetakData()
{
    if (head == nullptr)
    {
        cout << "\nLinked List masih kosong.\n";
        return;
    }

    cout << "\n=== DATA MAHASISWA (CIRCULAR LINKED LIST) ===\n";
    cout << left
         << setw(15) << "NIM"
         << setw(25) << "NAMA"
         << setw(10) << "GENDER"
         << setw(10) << "NILAI" << endl;
    cout << "-----------------------------------------------------------\n";

    Mahasiswa *curr = head;
    do
    {
        cout << left
             << setw(15) << curr->nim
             << setw(25) << curr->nama
             << setw(10) << curr->gender
             << fixed << setprecision(2)
             << setw(10) << curr->nilai << "\n";
        curr = curr->next;
    } while (curr != head);

    cout << "-----------------------------------------------------------\n";
    cout << "Data melingkar kembali ke simpul pertama.\n";
}

int main()
{
    int pilihan;

    do
    {
        cout << "\nCIRCULAR LINKED LIST\n";
        cout << "==========================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1 - 4): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            string nama, nim;
            char gender;
            float nilai;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Nama Mahasiswa : ";
            getline(cin, nama);

            cout << "NIM            : ";
            getline(cin, nim);

            cout << "Gender (L/P)   : ";
            cin >> gender;

            cout << "Nilai          : ";
            cin >> nilai;

            if (insertData(nama, nim, gender, nilai))
            {
                cout << "Data berhasil ditambahkan.\n";
            }
            else
            {
                cout << "Gagal: NIM sudah terdaftar.\n";
            }
            break;
        }

        case 2:
        {
            string nim;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "NIM yang akan dihapus: ";
            getline(cin, nim);

            if (hapusData(nim))
            {
                cout << "Data dengan NIM " << nim << " berhasil dihapus.\n";
            }
            else
            {
                cout << "Data tidak ditemukan.\n";
            }
            break;
        }

        case 3:
            cetakData();
            break;

        case 4:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    return 0;
}