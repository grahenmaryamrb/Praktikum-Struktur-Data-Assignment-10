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