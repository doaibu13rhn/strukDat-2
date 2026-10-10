#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Buku {
    string judul;
    string penulis;
    int jumlah;
};

// 1. Menampilkan informasi buku
void tampilkanBuku(const Buku &buku) {
    cout << "\n--- Informasi Buku ---\n";
    cout << "Judul   : " << buku.judul << endl;
    cout << "Penulis : " << buku.penulis << endl;
    cout << "Jumlah  : " << buku.jumlah << endl;
}

// 2. Menambahkan buku baru
void tambahBuku(vector<Buku> &perpustakaan) {
    Buku bukuBaru;

    cin.ignore();

    cout << "\n--- Tambah Buku ---\n";

    cout << "Judul buku   : ";
    getline(cin, bukuBaru.judul);

    cout << "Penulis buku : ";
    getline(cin, bukuBaru.penulis);

    cout << "Jumlah buku  : ";
    cin >> bukuBaru.jumlah;

    perpustakaan.push_back(bukuBaru);

    cout << "\nBuku berhasil ditambahkan!\n";
}

// 3. Menampilkan semua buku dari penulis tertentu
void tampilkanBukuPenulis(const vector<Buku> &perpustakaan) {
    string penulis;

    cin.ignore();

    cout << "\n--- Cari Buku Berdasarkan Penulis ---\n";
    cout << "Nama penulis : ";
    getline(cin, penulis);

    bool ditemukan = false;

    for (const Buku &buku : perpustakaan) {
        if (buku.penulis == penulis) {
            cout << "\nJudul  : " << buku.judul << endl;
            cout << "Jumlah : " << buku.jumlah << endl;

            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "\nBuku dari penulis tersebut tidak ditemukan.\n";
    }
}

// 4. Menampilkan jumlah buku dengan judul tertentu
void cariJumlahBuku(const vector<Buku> &perpustakaan) {
    string judul;

    cin.ignore();

    cout << "\n--- Cari Jumlah Buku ---\n";
    cout << "Judul buku : ";
    getline(cin, judul);

    int total = 0;

    for (const Buku &buku : perpustakaan) {
        if (buku.judul == judul) {
            total += buku.jumlah;
        }
    }

    cout << "Jumlah buku \"" << judul << "\" : " << total << endl;
}

// 5. Menampilkan jumlah total buku
void tampilkanTotalBuku(const vector<Buku> &perpustakaan) {
    int total = 0;

    for (const Buku &buku : perpustakaan) {
        total += buku.jumlah;
    }

    cout << "\nTotal buku di perpustakaan: " << total << endl;
}

// 6. Terbitkan / keluarkan buku
void terbitkanBuku(vector<Buku> &perpustakaan) {
    string judul;

    cin.ignore();

    cout << "\n--- Terbitkan Buku ---\n";
    cout << "Judul buku : ";
    getline(cin, judul);

    for (Buku &buku : perpustakaan) {
        if (buku.judul == judul) {

            if (buku.jumlah > 0) {
                buku.jumlah--;

                cout << "\nBuku berhasil diterbitkan/dipinjam.\n";
                cout << "Sisa buku: " << buku.jumlah << endl;
            } else {
                cout << "\nStok buku sedang habis.\n";
            }

            return;
        }
    }

    cout << "\nBuku tidak ditemukan.\n";
}

int main() {

    vector<Buku> perpustakaan = {
        {"Laskar Pelangi", "Andrea Hirata", 5},
        {"Bumi", "Tere Liye", 3},
        {"Negeri 5 Menara", "Ahmad Fuadi", 4}
    };

    int pilihan;

    do {
        cout << "\n==============================\n";
        cout << "     SISTEM PERPUSTAKAAN\n";
        cout << "==============================\n";
        cout << "1. Menampilkan informasi buku\n";
        cout << "2. Tambahkan buku baru\n";
        cout << "3. Tampilkan semua buku penulis tertentu\n";
        cout << "4. Menampilkan jumlah buku dengan judul tertentu\n";
        cout << "5. Menampilkan jumlah total buku\n";
        cout << "6. Terbitkan buku\n";
        cout << "0. Keluar\n";
        cout << "==============================\n";

        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1: {
                string judul;
                cin.ignore();

                cout << "\nJudul buku: ";
                getline(cin, judul);

                bool ditemukan = false;

                for (const Buku &buku : perpustakaan) {
                    if (buku.judul == judul) {
                        tampilkanBuku(buku);
                        ditemukan = true;
                        break;
                    }
                }

                if (!ditemukan) {
                    cout << "\nBuku tidak ditemukan.\n";
                }

                break;
            }

            case 2:
                tambahBuku(perpustakaan);
                break;

            case 3:
                tampilkanBukuPenulis(perpustakaan);
                break;

            case 4:
                cariJumlahBuku(perpustakaan);
                break;

            case 5:
                tampilkanTotalBuku(perpustakaan);
                break;

            case 6:
                terbitkanBuku(perpustakaan);
                break;

            case 0:
                cout << "\nProgram selesai. 👋\n";
                break;

            default:
                cout << "\nPilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}