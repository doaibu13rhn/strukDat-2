#include <iostream>
using namespace std;

#define n 10

int Q[n]; // array antrian
int L, R; // penunjuk kiri dan kanan
int x;    // penampung data

// Proses AWAL (inisialisasi)
void AWAL(void)
{
    L = 0;
    R = -1;
}

// Menampilkan isi antrian dari L sampai R
void TAMPIL(void)
{
    if (L < R + 1)
    {
        cout << "Isi antrian (L=" << L << ", R=" << R << ") : ";
        for (int i = L; i <= R; i++)
            cout << Q[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "Antrian kosong (L=" << L << ", R=" << R << ")" << endl;
    }
}

// SOAL 3
// Isi antrian dari kanan record per record sampai penuh kanan
void ISI_KANAN_SAMPAI_PENUH(void)
{
    while (R < n - 1) // masih bisa insert kanan
    {
        cout << "Masukkan data ke-" << (R + 2) << " : ";
        cin >> x;
        Q[++R] = x; // insert kanan
    }
    cout << "Antrian penuh kanan" << endl; // R = n - 1
}

// SOAL 4
// Hapus isi antrian dari kanan record per record sampai kosong
void HAPUS_KANAN_SAMPAI_KOSONG(void)
{
    while (L < R + 1) // antrian masih ada isinya
    {
        x = Q[R--]; // delete kanan
        cout << "Data dihapus : " << x << endl;
    }
    cout << "Antrian kosong" << endl; // L = R + 1
}

int main()
{
    AWAL();

    cout << "=== Soal 3: Isi antrian dari kanan sampai penuh ===" << endl;
    ISI_KANAN_SAMPAI_PENUH();
    TAMPIL();

    cout << endl;
    cout << "=== Soal 4: Hapus antrian dari kanan sampai kosong ===" << endl;
    HAPUS_KANAN_SAMPAI_KOSONG();
    TAMPIL();

    return 0;
}