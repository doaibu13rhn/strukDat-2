#include <iostream>
#include <iomanip>
using namespace std;

// Indeks linear (row-major) untuk array 1D, 2D, 3D
int indeks1D(int i)
{
    return i;
}

int indeks2D(int i, int j, int kolom)
{
    return i * kolom + j;
}

int indeks3D(int i, int j, int k, int dim2, int dim3)
{
    return i * dim2 * dim3 + j * dim3 + k;
}

// Cetak alamat dalam format hexadecimal huruf besar
void cetak(const string &soal, const string &target, long alamat)
{
    cout << soal << " -> " << target << " = "
         << uppercase << hex << alamat << " H" << dec << endl;
}

int main()
{
    const int UKURAN_CHAR = 1;
    const int UKURAN_INT = 4;
    const int UKURAN_FLOAT = 4;
    const int UKURAN_LONG = 4; // ubah ke 8 jika long dianggap 8 byte (Linux 64-bit)

    // Soal 1: char x[12], &x[0] = 1000 H, ditanya &x[8]
    {
        long dasar = 0x1000;
        long hasil = dasar + (long)(indeks1D(8) - indeks1D(0)) * UKURAN_CHAR;
        cetak("Soal 1", "&x[8]", hasil);
    }

    // Soal 2: int x[15], &x[3] = 1000 H, ditanya &x[9]
    {
        long diketahui = 0x1000;
        long hasil = diketahui + (long)(indeks1D(9) - indeks1D(3)) * UKURAN_INT;
        cetak("Soal 2", "&x[9]", hasil);
    }

    // Soal 3: float x[5][8], &x[0][0] = 1000 H, ditanya &x[2][4]
    {
        long dasar = 0x1000;
        int kolom = 8;
        long hasil = dasar + (long)indeks2D(2, 4, kolom) * UKURAN_FLOAT;
        cetak("Soal 3", "&x[2][4]", hasil);
    }

    // Soal 4: long x[12][14], &x[0][0] = 1000 H, ditanya &x[2][4]
    {
        long dasar = 0x1000;
        int kolom = 14;
        long hasil = dasar + (long)indeks2D(2, 4, kolom) * UKURAN_LONG;
        cetak("Soal 4", "&x[2][4]", hasil);
    }

    // Soal 5: int x[2][3][5], &x[1][1][4] = 12EF H, ditanya &x[0][0][3]
    {
        long diketahui = 0x12EF;
        int dim2 = 3, dim3 = 5;
        int idxDiketahui = indeks3D(1, 1, 4, dim2, dim3); // 24
        int idxDitanya = indeks3D(0, 0, 3, dim2, dim3);   // 3
        long hasil = diketahui + (long)(idxDitanya - idxDiketahui) * UKURAN_INT;
        cetak("Soal 5", "&x[0][0][3]", hasil);
    }

    return 0;
}