#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Struktur Node Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi Insert
Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    // Jika key == root->data, tidak melakukan apa-apa (mencegah duplikasi)
    return root;
}

// Fungsi Mencari Nilai Terkecil
Node *findMin(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

// Fungsi Delete
Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Traversal Inorder (Kiri, Root, Kanan) -> Menghasilkan urutan Ascending
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Traversal Preorder (Root, Kiri, Kanan)
void preorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Traversal Postorder (Kiri, Kanan, Root)
void postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Fungsi untuk mencetak visualisasi Tree (diputar 90 derajat)
void printTree(Node *root, int space = 0, int COUNT = 5)
{
    if (root == nullptr)
        return;

    space += COUNT;

    printTree(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
    {
        cout << " ";
    }
    cout << root->data << "\n";

    printTree(root->left, space);
}

// Fungsi Utama
int main()
{
    Node *root = nullptr;
    int pilihan, data;

    do
    {
        cout << "\n====================================\n";
        cout << "       SIMULASI BINARY SEARCH TREE  \n";
        cout << "====================================\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Cetak Traversal (In/Pre/Post)\n";
        cout << "4. Visualisasi Tree\n";
        cout << "5. Exit\n";
        cout << "====================================\n";
        cout << "Pilihan (1-5): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nilai yang ingin di-insert: ";
            cin >> data;
            root = insert(root, data);
            cout << "[SUKSES] Node " << data << " ditambahkan.\n";
            break;

        case 2:
            if (root == nullptr)
            {
                cout << "[INFO] Tree kosong.\n";
                break;
            }
            cout << "Masukkan nilai yang ingin dihapus: ";
            cin >> data;
            root = deleteNode(root, data);
            cout << "[PROSES] Penghapusan node " << data << " selesai.\n";
            break;

        case 3:
            if (root == nullptr)
            {
                cout << "[INFO] Tree kosong.\n";
                break;
            }
            cout << "Inorder   : ";
            inorder(root);
            cout << endl;
            cout << "Preorder  : ";
            preorder(root);
            cout << endl;
            cout << "Postorder : ";
            postorder(root);
            cout << endl;
            break;

        case 4:
            if (root == nullptr)
            {
                cout << "[INFO] Tree kosong.\n";
            }
            else
            {
                cout << "Visualisasi Tree (Rotated 90 deg):\n";
                printTree(root);
            }
            break;

        case 5:
            cout << "Keluar dari program. Terima kasih!\n";
            break;

        default:
            cout << "[ERROR] Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}