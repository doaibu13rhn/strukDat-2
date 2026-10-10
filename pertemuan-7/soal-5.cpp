#include <iostream>
using namespace std;

#define MAX 10

// Fungsi untuk menghitung jumlah elemen yang ada isinya
// Hanya menggunakan nilai F (front), R (rear), dan n (MAX)
int hitungJumlahIsi(int F, int R, int n)
{
    int jumlah;

    // Asumsi: antrian tidak kosong.
    // Jika F <= R, maka data terurut normal
    if (F <= R)
    {
        jumlah = R - F + 1;
    }
    // Jika F > R, terjadi wrap around
    else
    {
        jumlah = (n - F) + (R + 1);
    }

    return jumlah;
}

int main()
{
    int F, R, n = MAX;

    // Contoh 1: F = 3, R = 6
    F = 3;
    R = 6;
    cout << "Contoh 1: F=" << F << ", R=" << R
         << " -> Jumlah isi = " << hitungJumlahIsi(F, R, n) << endl;

    // Contoh 2: F = 8, R = 2 (wrap around)
    F = 8;
    R = 2;
    cout << "Contoh 2: F=" << F << ", R=" << R
         << " -> Jumlah isi = " << hitungJumlahIsi(F, R, n) << endl;

    // Contoh 3: F = 0, R = 0 (hanya 1 elemen)
    F = 0;
    R = 0;
    cout << "Contoh 3: F=" << F << ", R=" << R
         << " -> Jumlah isi = " << hitungJumlahIsi(F, R, n) << endl;

    return 0;
}