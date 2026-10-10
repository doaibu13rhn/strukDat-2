#include <iostream>
using namespace std;

#define MAX 10

class CirQueue
{
private:
    int front;
    int rear;
    int count;
    int ele[MAX];

public:
    CirQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    int isEmpty()
    {
        return (count == 0) ? 1 : 0;
    }

    void insertQueue(int item)
    {
        if (count == MAX)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        ele[rear] = item;
        count++;
    }

    int deleteQueue(int *item)
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        *item = ele[front];
        front = (front + 1) % MAX;
        count--;
        return 0;
    }
};

int main()
{
    CirQueue q;
    int item;

    // Isi antrian terlebih dahulu (misal 7 record)
    for (int i = 1; i <= 7; i++)
    {
        q.insertQueue(i * 10);
    }

    cout << "===== Proses Delete 10 Record =====" << endl;
    int j = 0;

    // Mendelete maksimal 10 record, berhenti jika antrian kosong
    while (j < 10 && !q.isEmpty())
    {
        if (q.deleteQueue(&item) == 0)
        {
            cout << "Item dihapus : " << item << endl;
        }
        j++;
    }

    if (q.isEmpty())
    {
        cout << ">> Antrian sudah kosong, proses delete dihentikan." << endl;
    }
    else
    {
        cout << ">> Proses delete selesai, 10 record telah dihapus." << endl;
    }

    return 0;
}