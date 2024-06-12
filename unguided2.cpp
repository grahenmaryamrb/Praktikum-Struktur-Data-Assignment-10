#include <iostream>
using namespace std;

int Grahen_2311110062;

// Definisi struktur pohon
struct pohon {
    pohon* kiri;
    pohon* kanan;
    char data;
};

// Fungsi untuk membuat simpul baru
pohon* buatSimpul(char data) {
    pohon* baru = new pohon();
    baru->data = data;
    baru->kiri = baru->kanan = NULL;
    return baru;
}

// Fungsi untuk menambahkan simpul ke pohon
pohon* tambahSimpul(pohon* root, char data) {
    if (root == NULL) {
        return buatSimpul(data);
    } else {
        char arah;
        cout << "Tambahkan " << data << " ke kiri (l) atau kanan (r) dari " << root->data << "? (l/r): ";
        cin >> arah;
        if (arah == 'l') {
            root->kiri = tambahSimpul(root->kiri, data);
        } else {
            root->kanan = tambahSimpul(root->kanan, data);
        }
    }
    return root;
}

// Fungsi untuk traversal pre-order
void preOrder(pohon* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

// Fungsi untuk traversal in-order
void inOrder(pohon* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

// Fungsi untuk traversal post-order
void postOrder(pohon* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

// Fungsi utama
int main() {
    pohon* root = NULL;
    int pilihan;
    char data;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah Simpul\n";
        cout << "2. Tampilkan Pre-order\n";
        cout << "3. Tampilkan In-order\n";
        cout << "4. Tampilkan Post-order\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan karakter: ";
                cin >> data;
                if (root == NULL) {
                    root = buatSimpul(data);
                } else {
                    tambahSimpul(root, data);
                }
                break;
            case 2:
                cout << "Pre-order: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-order: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-order: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
    return 0;
}