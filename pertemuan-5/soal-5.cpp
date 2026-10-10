#include <iostream>
using namespace std;

#define MAX 5

class DStack
{
private:
    int top1;
    int top2;
    int ele[MAX];

public:
    DStack();
    void pushB(int item);
    int popB(int *item);
};

// Inisialisasi
DStack::DStack()
{
    top1 = -1;
    top2 = MAX;
}

// PUSH Stack2
void DStack::pushB(int item)
{
    if (top2 == top1 + 1)
    {
        cout << "Stack Overflow Stack2" << endl;
        return;
    }

    top2--;
    ele[top2] = item;
}

// POP Stack2
int DStack::popB(int *item)
{
    if (top2 == MAX)
    {
        return -1;
    }

    *item = ele[top2++];
    return 0;
}

int main()
{
    int item;
    DStack s;

    // Mengisi Stack2
    s.pushB(40);
    s.pushB(50);
    s.pushB(60);

    cout << "Isi Stack2:" << endl;

    // Mengambil dan mencetak isi Stack2
    while (s.popB(&item) == 0)
    {
        cout << item << endl;
    }

    return 0;
}