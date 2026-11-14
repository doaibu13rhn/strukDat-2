#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // Untuk system("cls")

using namespace std;

// Struktur data mahasiswa
struct Mahasiswa
{
    string nama;
    string nim;
    string gender;
    float nilai;
};

// Struktur Node untuk Circular Doubly Linked List
struct Node
{
    Mahasiswa data;
    Node *next;
    Node *prev;
};

// Inisialisasi head dan tail
Node *head = nullptr;
Node *tail = nullptr;

// Fungsi untuk mengecek apakah list kosong
bool isEmpty()
{
    return head == nullptr;
}

// Fungsi untuk menyisipkan data secara terurut berdasarkan NIM
void insertData()
{
    Node *newNode = new Node;

    cout << "\n--- TAMBAH DATA MAHASISWA ---\n";
    cout << "Nama   : ";
    cin.ignore();
    getline(cin, newNode->data.nama);
    cout << "NIM    : ";
    cin >> newNode->data.nim;
    cout << "Gender : ";
    cin >> newNode->data.gender;
    cout << "Nilai  : ";
    cin >> newNode->data.nilai;

    // Cek duplikasi NIM
    if (!isEmpty())
    {
        Node *temp = head;
        do
        {
            if (temp->data.nim == newNode->data.nim)
            {
                cout << "\n[ERROR] NIM " << newNode->data.nim << " sudah ada dalam database!\n";
                delete newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    // Jika list kosong
    if (isEmpty())
    {
        head = tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    // Jika data baru lebih kecil dari head (Insert di awal)
    else if (newNode->data.nim < head->data.nim)
    {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    // Jika data baru lebih besar dari tail (Insert di akhir)
    else if (newNode->data.nim > tail->data.nim)
    {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
    // Jika data baru berada di tengah-tengah
    else
    {
        Node *curr = head;
        // Cari posisi yang tepat
        while (curr->next != head && curr->next->data.nim < newNode->data.nim)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }
    cout << "\n[SUKSES] Data berhasil ditambahkan!\n";
}

// Fungsi untuk menghapus data berdasarkan NIM
void hapusData()
{
    if (isEmpty())
    {
        cout << "\n[INFO] Linked List kosong. Tidak ada data yang bisa dihapus.\n";
        return;
    }

    string targetNIM;
    cout << "\n--- HAPUS DATA MAHASISWA ---\n";
    cout << "Masukkan NIM yang ingin dihapus: ";
    cin >> targetNIM;

    Node *curr = head;
    bool found = false;

    // Mencari node yang akan dihapus
    do
    {
        if (curr->data.nim == targetNIM)
        {
            found = true;
            break;
        }
        curr = curr->next;
    } while (curr != head);

    if (!found)
    {
        cout << "\n[ERROR] NIM " << targetNIM << " tidak ditemukan!\n";
        return;
    }

    // Kasus 1: Hanya ada satu data di list
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    // Kasus 2: Menghapus Head
    else if (curr == head)
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    // Kasus 3: Menghapus Tail
    else if (curr == tail)
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
    // Kasus 4: Menghapus di tengah
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    delete curr;
    cout << "\n[SUKSES] Data dengan NIM " << targetNIM << " berhasil dihapus.\n";
}

// Fungsi untuk mencetak seluruh data
void cetakData()
{
    if (isEmpty())
    {
        cout << "\n[INFO] Linked List kosong.\n";
        return;
    }

    cout << "\n=================================================================\n";
    cout << "| " << setw(5) << left << "No"
         << "| " << setw(25) << left << "Nama"
         << "| " << setw(15) << left << "NIM"
         << "| " << setw(10) << left << "Gender"
         << "| " << setw(10) << left << "Nilai" << "|\n";
    cout << "=================================================================\n";

    Node *curr = head;
    int no = 1;
    do
    {
        cout << "| " << setw(5) << left << no++
             << "| " << setw(25) << left << curr->data.nama
             << "| " << setw(15) << left << curr->data.nim
             << "| " << setw(10) << left << curr->data.gender
             << "| " << setw(10) << left << curr->data.nilai << "|\n";
        curr = curr->next;
    } while (curr != head);

    cout << "=================================================================\n";
}

// Fungsi utama
int main()
{
    int pilihan;
    do
    {
        system("cls"); // Bersihkan layar (Gunakan "clear" jika di Linux/Mac)

        cout << "          CIRCULAR          DOUBLY          LINKED          LIST\n";
        cout << "================================================================\n";
        cout << "  1. INSERT DATA\n";
        cout << "  2. HAPUS DATA\n";
        cout << "  3. CETAK DATA\n";
        cout << "  4. EXIT\n";
        cout << "================================================================\n";
        cout << "  Pilihan (1 - 4) : ";
        cin >> pilihan;

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
            cout << "\n[ERROR] Pilihan tidak valid. Silakan coba lagi.\n";
        }

        if (pilihan != 4)
        {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 4);

    return 0;
}