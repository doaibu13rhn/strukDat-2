#include <iostream>
using namespace std;

// ==== STRUKTUR NODE ====
struct Node
{
    int data;
    Node *next;
};

// ==== HEAD (node pertama) ====
Node *head = NULL;

// ==== TAMBAH DI DEPAN ====
void tambahDepan(int nilai)
{
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = head;
    head = baru;
}

// ==== TAMBAH DI BELAKANG ====
void tambahBelakang(int nilai)
{
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL)
    {
        head = baru;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = baru;
    }
}

// ==== HAPUS DI DEPAN ====
void hapusDepan()
{
    if (head == NULL)
    {
        cout << "List kosong!\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

// ==== TAMPILKAN LIST ====
void tampilkan()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// ==== MAIN ====
int main()
{
    tambahDepan(10);
    tambahDepan(5);
    tambahBelakang(20);
    tambahBelakang(30);

    cout << "Isi List: ";
    tampilkan();

    hapusDepan();
    cout << "Setelah hapus depan: ";
    tampilkan();

    return 0;
}