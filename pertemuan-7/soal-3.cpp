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

    int isFull()
    {
        return (count == MAX) ? 1 : 0;
    }

    void insertQueue(int item)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        ele[rear] = item;
        count++;
        cout << "Dimasukkan item : " << item << endl;
    }
};

int main()
{
    CirQueue q;
    int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i = 0;

    // Mengisi maksimal 10 record, berhenti jika antrian penuh
    while (i < 10 && !q.isFull())
    {
        q.insertQueue(data[i]);
        i++;
    }

    if (q.isFull())
    {
        cout << ">> Antrian sudah penuh, proses pengisian dihentikan." << endl;
    }
    else
    {
        cout << ">> Pengisian selesai, 10 record telah dimasukkan." << endl;
    }

    return 0;
}