#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa
{
    string nama;
    string nim;
    string gender;
    float nilai;
};

// Struktur untuk Node pada Linked List
struct Node
{
    Mahasiswa data;
    Node *next;
};

// Deklarasi pointer depan (front/head) dan belakang (rear/tail)
Node *front = NULL;
Node *rear = NULL;

// Fungsi untuk mengecek apakah antrian kosong
bool isEmpty()
{
    return front == NULL;
}

// Operasi enQueue: Menambahkan data ke belakang antrian
void insertData(Mahasiswa mhs)
{
    Node *newNode = new Node;
    newNode->data = mhs;
    newNode->next = NULL;

    if (isEmpty())
    {
        // Jika antrian kosong, front dan rear menunjuk ke node baru
        front = rear = newNode;
    }
    else
    {
        // Jika tidak kosong, tambahkan di belakang dan pindahkan rear
        rear->next = newNode;
        rear = newNode;
    }
    cout << "\n[+] Data " << mhs.nama << " berhasil dimasukkan ke dalam antrian.\n";
}

// Operasi deQueue: Menghapus data dari depan antrian
void hapusData()
{
    if (isEmpty())
    {
        cout << "\n[-] Antrian kosong! Tidak ada data yang bisa dihapus.\n";
        return;
    }

    Node *temp = front;
    front = front->next; // Geser front ke node berikutnya

    // Jika setelah dihapus antrian menjadi kosong, rear juga harus NULL
    if (front == NULL)
    {
        rear = NULL;
    }

    cout << "\n[-] Data " << temp->data.nama << " (NIM: " << temp->data.nim << ") telah dihapus dari antrian.\n";
    delete temp; // Hapus memori
}

// Operasi tampil/cetak: Menampilkan seluruh data antrian dari depan ke belakang
void cetakData()
{
    if (isEmpty())
    {
        cout << "\n[!] Antrian kosong.\n";
        return;
    }

    cout << "\n===============================================================\n";
    cout << "| No | Nama                 | NIM        | Gender | Nilai      |\n";
    cout << "===============================================================\n";

    Node *current = front;
    int no = 1;
    while (current != NULL)
    {
        cout << "| " << setw(2) << left << no++ << " | "
             << setw(20) << left << current->data.nama << " | "
             << setw(10) << left << current->data.nim << " | "
             << setw(6) << left << current->data.gender << " | "
             << setw(10) << left << current->data.nilai << " |\n";
        current = current->next;
    }
    cout << "===============================================================\n";
}

int main()
{
    int pilihan;
    char ulang;

    do
    {
        cout << "\n================================\n";
        cout << "     MENU ANTRIAN MAHASISWA     \n";
        cout << "================================\n";
        cout << "1. INSERT DATA (Enqueue)\n";
        cout << "2. HAPUS DATA (Dequeue)\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "--------------------------------\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer enter setelah input angka

        switch (pilihan)
        {
        case 1:
        {
            Mahasiswa mhs;
            cout << "\n--- INPUT DATA MAHASISWA ---\n";
            cout << "Masukkan Nama               : ";
            getline(cin, mhs.nama);
            cout << "Masukkan NIM                : ";
            getline(cin, mhs.nim);
            cout << "Masukkan Gender (L/P)       : ";
            getline(cin, mhs.gender);
            cout << "Masukkan Nilai Struktur Data: ";
            cin >> mhs.nilai;
            cin.ignore();
            insertData(mhs);
            break;
        }
        case 2:
            hapusData();
            break;
        case 3:
            cetakData();
            break;
        case 4:
            cout << "\nKeluar dari program. Terima kasih!\n";
            break;
        default:
            cout << "\n[!] Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);

    // Membersihkan sisa memori sebelum program berakhir
    while (!isEmpty())
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    return 0;
}