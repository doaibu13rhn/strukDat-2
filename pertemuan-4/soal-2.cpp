#include <iostream>
using namespace std;

#define MAX 10

int main()
{
    int S[MAX];
    int top = -1; // stack kosong
    int data;

    // Tahap 1: Input dan PUSH
    while (true)
    {
        cout << "Input data: ";
        cin >> data;

        if (data == 999)
        {
            cout << "Input dihentikan (end of data)." << endl;
            break;
        }

        if (top < MAX - 1)
        {
            top++;
            S[top] = data;
            cout << "Data " << data << " berhasil di-PUSH." << endl;
        }
        else
        {
            cout << "Stack Penuh, tidak bisa PUSH lagi." << endl;
            break;
        }
    }

    // Tahap 2: POP semua isi stack sampai kosong
    cout << "\nIsi stack (dari POP satu per satu):" << endl;
    while (top >= 0)
    {
        cout << S[top] << endl;
        top--;
    }
    cout << "Stack Kosong." << endl;

    return 0;
}