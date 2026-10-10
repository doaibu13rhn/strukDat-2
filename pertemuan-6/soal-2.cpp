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
    }

    // DELETE record dari queue
    int deleteQueue(int *item)
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        *item = ele[front++];
        return 0;
    }
};

int main()
{
    Queue q;
    int item = 0;
    int i = 1;

    // --- Isi antrian terlebih dahulu ---
    cout << "=== PERSIAPAN: MENGISI ANTRIAN ===" << endl;
    for (int j = 10; j <= 50; j += 10)
    {
        q.insertQueue(j);
        cout << "Nilai yang disisipkan : " << j << endl;
    }
    cout << endl;

    // --- Proses DELETE sebanyak 10 record ---
    cout << "=== PROSES DELETE ANTRIAN (MAX 10 RECORD) ===" << endl;

    // Perulangan: selama i <= 10 DAN antrian belum kosong
    while (i <= 10 && q.isEmpty() == 0)
    {
        if (q.deleteQueue(&item) == 0)
        {
            cout << "Record ke-" << i << " dihapus : " << item << endl;
        }
        i++;
    }

    // Cek kondisi berhenti
    if (q.isEmpty() == 1 && i <= 10)
    {
        cout << "\n>> Antrian kosong, proses delete dihentikan!" << endl;
        cout << ">> Record yang berhasil dihapus: " << (i - 1) << " record" << endl;
    }
    else
    {
        cout << "\n>> Delete selesai, 10 record telah dihapus." << endl;
    }

    return 0;
}