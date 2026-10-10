#include <iostream>
using namespace std;

#define MAX 5 // ubah sesuai kebutuhan (misal n = 5)

class Queue
{
private:
    int front, rear;
    int ele[MAX];

public:
    // Konstruktor - Inisialisasi queue
    Queue()
    {
        front = 0;
        rear = -1;
    }

    // Cek antrian penuh
    int isFull()
    {
        int full = 0;
        if (rear == MAX - 1)
            full = 1;
        return full;
    }

    // Cek antrian kosong
    int isEmpty()
    {
        int empty = 0;
        if (front == rear + 1)
            empty = 1;
        return empty;
    }

    // INSERT record ke queue
    void insertQueue(int item)
    {
        if (isFull())
        {
            cout << "Queue OverFlow" << endl;
            return;
        }
        ele[++rear] = item;
        cout << "Nilai yang disisipkan : " << item << endl;
    }
};

int main()
{
    Queue q;
    int i = 1;
    int data;

    cout << "=== PROSES PENGISIAN ANTRIAN (MAX 10 RECORD) ===" << endl;
    cout << "Kapasitas antrian (MAX) = " << MAX << endl
         << endl;

    // Perulangan: selama i <= 10 DAN antrian belum penuh
    while (i <= 10 && q.isFull() == 0)
    {
        cout << "Masukkan record ke-" << i << " : ";
        cin >> data;

        q.insertQueue(data);
        i++;
    }

    // Cek kondisi berhenti
    if (q.isFull() == 1 && i <= 10)
    {
        cout << "\n>> Antrian penuh, proses pengisian dihentikan!" << endl;
        cout << ">> Record yang berhasil diisi: " << (i - 1) << " record" << endl;
    }
    else
    {
        cout << "\n>> Pengisian selesai, 10 record telah dimasukkan." << endl;
    }

    return 0;
}