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
    void pushA(int item);
    int popA(int *item);
};

// Inisialisasi
DStack::DStack()
{
    top1 = -1;
    top2 = MAX;
}

// PUSH Stack1
void DStack::pushA(int item)
{
    if (top2 == top1 + 1)
    {
        cout << "Stack Overflow Stack1" << endl;
        return;
    }

    top1++;
    ele[top1] = item;
}

// POP Stack1
int DStack::popA(int *item)
{
    if (top1 == -1)
    {
        return -1;
    }

    *item = ele[top1--];
    return 0;
}

int main()
{
    int item;
    DStack s;

    // Mengisi Stack1
    s.pushA(10);
    s.pushA(20);
    s.pushA(30);

    cout << "Isi Stack1:" << endl;

    // Mengambil dan mencetak isi Stack1
    while (s.popA(&item) == 0)
    {
        cout << item << endl;
    }

    return 0;
}