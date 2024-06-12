# <h1 align="center">Laporan Praktikum Modul Graph & Tree</h1>
<p align="center">Grahen Maryam Rompas Basiran</p>
<p align="center">2311110062</p>

## Dasar Teori
### GRAPH
Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan [1].

### TREE 
Tree adalah tipe struktur data yang sifatnya non-linier dan berbentuk hierarki.
Hierarki pada struktur tree dapat diibaratkan seperti sebuah pohon keluarga di mana terdapat hubungan antara orang tua dan anak. Titik yang lebih atas disebut simpul induk sedangkan simpul di bawahnya adalah simpul anak.

Struktur data tree terdiri atas kumpulan simpul atau node dimana tiap-tiap simpul dari tree digunakan untuk menyimpan nilai dan sebuah list rujukan ke simpul lain yang disebut simpul anak atau child node.

Tiap-tiap simpul dari tree akan dihubungkan oleh sebuah garis hubung yang dalam istilah teknis disebut edge. Biasanya diimplementasikan menggunakan pointer [2].
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
1. **Array `simpul`**: Ini adalah array string yang menyimpan nama-nama simpul atau node pada graf. Simpul-simpul ini adalah kota-kota di Indonesia, seperti Ciamis, Bandung, Bekasi, dll.

2. **Array `busur`**: Ini adalah matriks 2 dimensi (array 2D) yang menyimpan informasi tentang keberadaan dan bobot busur atau edge antara simpul-simpul. Nilai di matriks menunjukkan bobot dari busur tersebut, yang menggambarkan, misalnya, jarak atau biaya untuk berpindah dari satu kota ke kota lain. Nilai `0` menunjukkan tidak adanya langsung hubungan antara dua simpul.

3. **Fungsi `tampilGraph()`**: Fungsi ini digunakan untuk menampilkan graf yang direpresentasikan oleh matriks adjacency. Fungsi ini melintasi matriks `busur` untuk setiap simpul. Jika terdapat busur antara dua simpul (nilai tidak sama dengan `0`), maka ia akan mencetak nama simpul tujuan dan bobot busur tersebut. Penggunaan `if` di dalam loop `for` mengecek apakah ada busur antara simpul yang diperiksa; jika ada, maka informasi tersebut ditampilkan.

4. **Fungsi `main()`**: Fungsi utama ini memanggil `tampilGraph()` untuk menampilkan graf pada console.

Secara keseluruhan, program ini memberikan representasi visual yang sederhana untuk melihat bagaimana berbagai kota (simpul) terhubung satu sama lain dan bobot (misalnya jarak) yang terkait dengan setiap koneksi tersebut. Ini berguna, misalnya, untuk aplikasi yang memerlukan pemodelan dan analisis jaringan transportasi.


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
Program di atas merupakan implementasi struktur data pohon biner (binary tree).

Program dimulai dengan mengimpor library 'iostream' untuk operasi input/output. Selanjutnya, program mendefinisikan struktur data 'pohon' yang terdiri dari tiga anggota: 'kanan' (pointer ke simpul kanan), 'data' (data yang disimpan dalam simpul), dan 'kiri' (pointer ke simpul kiri). Program ini juga menyediakan beberapa variabel global untuk menyimpan pointer ke simpul-simpul tertentu dalam pohon, seperti 'root' (simpul akar), 'simpul' (simpul saat ini), dan 'alamat' (array untuk menyimpan alamat simpul-simpul sementara).

Fungsi 'inisialisasi()' digunakan untuk menginisialisasi 'root' dengan nilai NULL. Fungsi 'simpulBaru(char dataMasukkan)' digunakan untuk membuat simpul baru dengan data yang diberikan, dan menginisialisasi pointer 'kanan' dan 'kiri' dengan nilai NULL. Fungsi 'simpulAkar()' digunakan untuk membuat simpul akar jika 'root' masih NULL. Fungsi ini meminta pengguna untuk memasukkan data, kemudian membuat simpul baru dengan data tersebut sebagai akar.

Fungsi 'tambahSimpul()' digunakan untuk menambahkan simpul-simpul baru ke dalam pohon. Fungsi ini menggunakan array 'alamat' untuk menyimpan alamat simpul-simpul sementara, dan meminta pengguna untuk memasukkan data simpul kiri dan kanan secara bergantian. Jika pengguna memasukkan '0', maka tidak ada simpul yang ditambahkan di sisi tersebut.

Fungsi 'bacaPohon()' digunakan untuk mencetak data simpul-simpul dalam pohon secara level-order (level per level dari kiri ke kanan).

Akhirnya, fungsi utama 'main()' didefinisikan. Dalam fungsi 'main()', program memanggil 'inisialisasi()' untuk menginisialisasi 'root', 'simpulAkar()' untuk membuat simpul akar, 'tambahSimpul()' untuk menambahkan simpul-simpul baru, dan 'bacaPohon()' untuk mencetak data simpul-simpul dalam pohon.

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
Program di atas adalah program graf yang menggunakan input dari pengguna untuk menghitung jarak antara kota-kota.

Program dimulai dengan mengimpor beberapa library: `iostream` untuk input/output, `vector` untuk mengimplementasikan struktur data vektor, `string` untuk tipe data string, dan `iomanip` untuk pengaturan lebar tampilan output. 

Berikut langkah-langkah yang dilakukan program:

1. Meminta input jumlah simpul dari pengguna dengan menampilkan "Silakan masukan jumlah simpul: " dan menyimpan input tersebut dalam variabel `numNodes`.
2. Membuat vektor dinamis untuk menyimpan nama-nama simpul sebanyak `numNodes` dan menyimpannya dalam vektor `nodes`.
3. Membuat vektor dua dimensi untuk menyimpan matriks jarak dengan ukuran `numNodes` x `numNodes` dan menyimpannya dalam vektor `distanceMatrix`.
4. Meminta input nama-nama simpul dari pengguna. Program melakukan iterasi dari `i = 0` hingga `numNodes - 1`, pada setiap iterasi menampilkan "Simpul i + 1: " dan menyimpan input nama simpul dalam `nodes[i]`.
5. Meminta input jarak antara setiap pasangan simpul. Program melakukan iterasi bersarang dari `i = 0` hingga `numNodes - 1` (untuk baris) dan `j = 0` hingga `numNodes - 1` (untuk kolom). Untuk setiap pasangan `(i, j)`:
   - Jika `i == j` (simpul yang sama), jarak ditetapkan sebagai 0.
   - Jika `i != j` (simpul yang berbeda), program menampilkan "Silakan masukkan bobot antar simpul nodes[i] --> nodes[j]: " dan menyimpan input jarak dalam `distanceMatrix[i][j]`.
6. Mencetak header matriks dengan menampilkan spasi, diikuti dengan nama-nama simpul dengan lebar 6 karakter.
7. Melakukan iterasi dari `i = 0` hingga `numNodes - 1` (untuk baris):
   - Mencetak nama simpul `nodes[i]` dengan lebar 6 karakter.
   - Melakukan iterasi dari `j = 0` hingga `numNodes - 1` (untuk kolom): Mencetak nilai `distanceMatrix[i][j]` dengan lebar 6 karakter.
   - Mencetak baris baru setelah selesai mencetak baris tersebut.

Program ini memberikan tampilan matriks jarak antara setiap pasangan kota yang diinput oleh pengguna.

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
Program di atas adalah program pohon (tree) yang memungkinkan pengguna untuk memasukkan data pohon melalui menu dan menampilkan hasil traversal pre-order, in-order, dan post-order.

Berikut adalah langkah-langkah yang dilakukan oleh program:

1. Mengimpor library `iostream` untuk operasi input/output.
2. Mendefinisikan struktur `pohon` yang terdiri dari tiga anggota: `kiri` dan `kanan` (pointer ke simpul lain), dan `data` (karakter yang disimpan di simpul).
3. Fungsi `buatSimpul` membuat simpul baru dengan data yang diberikan, serta menginisialisasi `kiri` dan `kanan` sebagai NULL.
4. Fungsi `tambahSimpul` menambahkan simpul baru ke dalam pohon dengan data yang diberikan. Jika pohon masih kosong, simpul baru menjadi akar. Jika tidak, program meminta pengguna untuk memilih apakah simpul baru akan ditambahkan ke kiri atau kanan dari simpul tertentu.
5. Terdapat tiga fungsi traversal: `preOrder`, `inOrder`, dan `postOrder`, yang mencetak data simpul sesuai dengan urutan traversal yang bersesuaian:
   - `preOrder`: mencetak data simpul sebelum mengunjungi simpul kiri dan kanan.
   - `inOrder`: mencetak data simpul setelah mengunjungi simpul kiri dan sebelum mengunjungi simpul kanan.
   - `postOrder`: mencetak data simpul setelah mengunjungi simpul kiri dan kanan.

Terakhir, fungsi utama `main()` menampilkan menu pilihan kepada pengguna dengan opsi-opsi berikut:

1. Tambah Simpul
2. Tampilkan Pre-order
3. Tampilkan In-order
4. Tampilkan Post-order
5. Keluar

Program ini memungkinkan pengguna untuk membangun pohon biner secara interaktif dan melihat hasil traversal dalam tiga urutan yang berbeda.

## Kesimpulan
#### Hasil praktikum: 
Pada kesempatan praktikum ini, saya belajar dua materi baru yaitu graph dan tree. Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan. Sedangkan Tree adalah tipe struktur data yang sifatnya non-linier dan berbentuk hierarki. Hierarki pada struktur tree dapat diibaratkan seperti sebuah pohon keluarga di mana terdapat hubungan antara orang tua dan anak. Titik yang lebih atas disebut simpul induk sedangkan simpul di bawahnya adalah simpul anak.

#### Pelajaran yang didapat
Graph dan tree adalah dua jenis struktur data non-linier yang berbeda dalam hal organisasi dan penggunaan.

**Graph** adalah struktur data yang terdiri dari kumpulan simpul berhingga yang dihubungkan oleh relasi saling keterkaitan antar simpul. Ini memungkinkan representasi hubungan yang kompleks dan saling berhubungan antara data. Graph sering digunakan dalam berbagai aplikasi seperti jaringan komputer, representasi sosial, dan jalur transportasi.

**Tree** adalah struktur data hierarkis yang terdiri dari simpul-simpul yang dihubungkan oleh garis hubung atau edge. Setiap simpul dalam tree dapat memiliki simpul anak, menciptakan hubungan antara simpul induk dan anak. Tree biasanya digunakan untuk mewakili data yang memiliki sifat hirarkis, seperti struktur organisasi, sistem file, dan pohon keluarga. Implementasi tree sering menggunakan pointer untuk menghubungkan simpul-simpulnya.

Secara umum, kedua struktur data ini digunakan untuk memodelkan data yang kompleks dan saling terkait, tetapi dengan pendekatan yang berbeda sesuai dengan kebutuhan aplikasi spesifik.

## Referensi
[1] Trivusi, “Struktur Data Graph”, 2022.

[2] Trivusi, "Struktur Data Tree", 2022.
