# <h1 align="center">Laporan Praktikum Modul Graph & Tree</h1>
<p align="center">Grahen Maryam Rompas Basiran</p>
<p align="center">2311110062</p>

## Dasar Teori
### GRAPH
Graph adalah 

### TREE 
Tree adalah 

## Guided
### 1. Program Graph
```C++
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int numNodes;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> numNodes;

    vector<string> nodes(numNodes);
    vector<vector<int>> distanceMatrix(numNodes, vector<int>(numNodes));

    // Input node names
    for (int i = 0; i < numNodes; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // Input distances between nodes
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (i == j) {
                distanceMatrix[i][j] = 0;
            } else {
                cout << "Silakan masukkan bobot antar simpul " << nodes[i] << "-->" << nodes[j] << ": ";
                cin >> distanceMatrix[i][j];
            }
        }
    }

    // Print distance matrix
    cout << "\n      "; // Adjust spacing for header
    for (const auto& node : nodes) {
        cout << setw(6) << node; // Right align node names in the header
    }
    cout << endl;

    for (int i = 0; i < numNodes; ++i) {
        cout << setw(6) << nodes[i]; // Left align node names in the row labels
        for (int j = 0; j < numNodes; ++j) {
            cout << setw(6) << distanceMatrix[i][j]; // Align distance values
        }
        cout << endl;
    }

    return 0;
}
```
### Penjelasan



### 2. Program Tree
```C++
#include <iostream>
using namespace std;

// Definisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// Deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

// FUngsi untuk simpul baru
void simpulBaru(char dataMasukkan){
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// Fungsi untuk membuat simpul akar
void simpulAkar(){
    if (root == NULL){
        char dataAnda;
        cout << "Silahkan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk...." << endl;
    } else {
        cout << "Root sudah ada...." << endl;
    }
}

void tambahSimpul(){
    if (root != NULL){
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 and j < 256){
            cout << "Masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0'){
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0){
                cout << "Masukkan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0'){
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

void bacaPohon(){
    if (root != NULL){
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL){
            saatIni = alamat[i];
            cout << saatIni->data << " ";
            pencacah++;
            if (pencacah == n){
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}
// Fungsi utama
int main(){
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```
### Penjelasan
 

## Unguided
### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
```C++
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int Grahen_2311110062;

int main() {
    int numNodes;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> numNodes;

    vector<string> nodes(numNodes);
    vector<vector<int>> distanceMatrix(numNodes, vector<int>(numNodes));

    // Input node names
    for (int i = 0; i < numNodes; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // Input distances between nodes
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (i == j) {
                distanceMatrix[i][j] = 0;
            } else {
                cout << "Silakan masukkan bobot antar simpul " << nodes[i] << "-->" << nodes[j] << ": ";
                cin >> distanceMatrix[i][j];
            }
        }
    }

    // Print distance matrix
    cout << "\n      "; // Adjust spacing for header
    for (const auto& node : nodes) {
        cout << setw(6) << node; // Right align node names in the header
    }
    cout << endl;

    for (int i = 0; i < numNodes; ++i) {
        cout << setw(6) << nodes[i]; // Left align node names in the row labels
        for (int j = 0; j < numNodes; ++j) {
            cout << setw(6) << distanceMatrix[i][j]; // Align distance values
        }
        cout << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot]

### Penjelasan


### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!
```C++
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
```
#### Output
![Screenshot]
### Penjelasan


## Kesimpulan
#### Hasil praktikum: 
Pada kesempatan praktikum ini, saya belajar dua materi baru yaitu graph dan tree. 

#### Pelajaran yang didapat
Berdasarkan penjelasan yang diberikan, dapat disimpulkan beberapa poin penting sebagai berikut:


## Referensi
[1] Bondan Himawan, “IMPLEMENTASI GRAF DALAM PENYIMPANAN DATA STRUKTUR BANGUNAN”, 2008.

[2] Dena Djayusman, "IMPLEMENTASI STRUKTUR DATA TREE PADA GAME SNAKE DENGAN C", 2021.