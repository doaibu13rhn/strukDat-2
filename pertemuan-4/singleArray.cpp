#include <iostream>
using namespace std;

#define MAX 10

int main()
{
    int S[MAX];
    int top = -1; // stack kosong
    int data;

    while (true)
    {
        cout << "Input data: ";
        cin >> data;

        // Kondisi selesai
        if (data == 999)
        {
            break;
        }

        if (data >= 60)
        {
            // Cek apakah stack masih bisa diisi
            if (top < MAX - 1)
            {
                top++;
                S[top] = data;
                cout << "Data " << data << " berhasil di-PUSH ke stack." << endl;
            }
            else
            {
                cout << "Stack Penuh" << endl;
                break;
            }
        }
        else
        {
            // data < 60, lakukan POP
            if (top >= 0)
            {
                cout << "Data yang di-POP: " << S[top] << endl;
                top--;
            }
            else
            {
                cout << "Stack Kosong" << endl;
                break;
            }
        }
    }

    cout << "Proses selesai." << endl;
    return 0;
}