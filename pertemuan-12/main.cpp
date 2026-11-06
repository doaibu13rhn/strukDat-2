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

// Struktur Node untuk Doubly Linked List
struct Node
{
    Mahasiswa data;
    Node *left;  // Pointer ke simpul sebelumnya
    Node *right; // Pointer ke simpul berikutnya
};

// Deklarasi pointer global
Node *FIRST = NULL;
Node *LAST = NULL;

// Fungsi untuk mengecek apakah list kosong
bool isEmpty()
{
    return FIRST == NULL;
}

// Fungsi INSERT DATA (Terurut naik berdasarkan NIM)
void insertData()
{
    Mahasiswa mhs;
    cout << "\n--- INSERT DATA MAHASISWA ---\n";
    cout << "Masukkan Nama   : ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM    : ";
    getline(cin, mhs.nim);
    cout << "Masukkan Gender : ";
    getline(cin, mhs.gender);
    cout << "Masukkan Nilai  : ";
    cin >> mhs.nilai;
    cin.ignore();

    Node *newNode = new Node;
    newNode->data = mhs;
    newNode->left = NULL;
    newNode->right = NULL;

    if (isEmpty())
    {
        // Kasus 1: List kosong
        FIRST = LAST = newNode;
        cout << "[+] Data berhasil ditambahkan sebagai simpul pertama.\n";
    }
    else if (mhs.nim < FIRST->data.nim)
    {
        // Kasus 2: Insert di kiri (awal)
        newNode->right = FIRST;
        FIRST->left = newNode;
        FIRST = newNode;
        cout << "[+] Data berhasil ditambahkan di awal (kiri).\n";
    }
    else if (mhs.nim >= LAST->data.nim)
    {
        // Kasus 3: Insert di kanan (akhir)
        newNode->left = LAST;
        LAST->right = newNode;
        LAST = newNode;
        cout << "[+] Data berhasil ditambahkan di akhir (kanan).\n";
    }
    else
    {
        // Kasus 4: Insert di tengah
        Node *curr = FIRST;
        // Cari posisi yang tepat (NIM curr < NIM baru)
        while (curr != NULL && curr->data.nim < mhs.nim)
        {
            curr = curr->right;
        }

        Node *prev = curr->left;

        // Sambungkan newNode
        newNode->right = curr;
        newNode->left = prev;

        // Perbarui pointer sekitar
        prev->right = newNode;
        curr->left = newNode;
        cout << "[+] Data berhasil disisipkan di tengah.\n";
    }
}

// Fungsi HAPUS DATA berdasarkan NIM
void hapusData()
{
    if (isEmpty())
    {
        cout << "\n[!] List kosong! Tidak ada data yang bisa dihapus.\n";
        return;
    }

    string nimCari;
    cout << "\n--- HAPUS DATA MAHASISWA ---\n";
    cout << "Masukkan NIM yang akan dihapus: ";
    getline(cin, nimCari);

    Node *curr = FIRST;
    // Cari node dengan NIM yang sesuai
    while (curr != NULL && curr->data.nim != nimCari)
    {
        curr = curr->right;
    }

    if (curr == NULL)
    {
        cout << "[!] Data dengan NIM " << nimCari << " tidak ditemukan.\n";
    }
    else
    {
        // Data ditemukan, lakukan penghapusan
        if (curr == FIRST && curr == LAST)
        {
            // Kasus 1: Hanya ada 1 simpul
            FIRST = LAST = NULL;
        }
        else if (curr == FIRST)
        {
            // Kasus 2: Hapus kiri (awal)
            FIRST = FIRST->right;
            FIRST->left = NULL;
        }
        else if (curr == LAST)
        {
            // Kasus 3: Hapus kanan (akhir)
            LAST = LAST->left;
            LAST->right = NULL;
        }
        else
        {
            // Kasus 4: Hapus tengah
            curr->left->right = curr->right;
            curr->right->left = curr->left;
        }
        delete curr;
        cout << "[-] Data dengan NIM " << nimCari << " berhasil dihapus.\n";
    }
}

// Fungsi CETAK DATA (Traversal maju dan mundur)
void cetakData()
{
    if (isEmpty())
    {
        cout << "\n[!] List kosong.\n";
        return;
    }

    cout << "\n========================================================================\n";
    cout << "| No | Nama                 | NIM        | Gender | Nilai              |\n";
    cout << "========================================================================\n";

    // Traversal Maju (FIRST ke LAST)
    Node *curr = FIRST;
    int no = 1;
    while (curr != NULL)
    {
        cout << "| " << setw(2) << left << no++ << " | "
             << setw(20) << left << curr->data.nama << " | "
             << setw(10) << left << curr->data.nim << " | "
             << setw(6) << left << curr->data.gender << " | "
             << setw(18) << left << curr->data.nilai << " |\n";
        curr = curr->right;
    }
    cout << "========================================================================\n";
    cout << "(Traversal Maju: FIRST -> LAST)\n\n";

    // Traversal Mundur (LAST ke FIRST) - Kelebihan Doubly Linked List
    cout << "========================================================================\n";
    cout << "| No | Nama                 | NIM        | Gender | Nilai              |\n";
    cout << "========================================================================\n";
    curr = LAST;
    no = 1;
    while (curr != NULL)
    {
        cout << "| " << setw(2) << left << no++ << " | "
             << setw(20) << left << curr->data.nama << " | "
             << setw(10) << left << curr->data.nim << " | "
             << setw(6) << left << curr->data.gender << " | "
             << setw(18) << left << curr->data.nilai << " |\n";
        curr = curr->left;
    }
    cout << "========================================================================\n";
    cout << "(Traversal Mundur: LAST -> FIRST)\n";
}

int main()
{
    int pilihan;

    do
    {
        cout << "\nLIN. DOUBLY LINKED LIST\n";
        cout << "=======================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1 - 4) : ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer newline

        switch (pilihan)
        {
        case 1:
            insertData();
            break;
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

    // Membersihkan sisa memori sebelum keluar
    Node *curr = FIRST;
    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->right;
        delete temp;
    }

    return 0;
}