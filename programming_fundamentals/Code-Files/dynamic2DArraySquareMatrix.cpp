#include <iostream>
using namespace std;

// Function to convert a square matrix
void convert_matrix(int** p, int row) {
    // Example logic: set all non-diagonal elements to 1
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (i != j) {
                p[i][j] = 1; // convert non-diagonal elements
            }
        }
    }

    // Print the converted matrix
    cout << "\nConverted Matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row;
    cout << "Enter the order of square matrix: ";
    cin >> row;

    // Allocate memory for square matrix
    int** p = new int*[row];
    for (int i = 0; i < row; i++)
        p[i] = new int[row];

    // Input matrix elements
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
            cin >> p[i][j];

    // Convert the matrix
    convert_matrix(p, row);

    // Free memory
    for (int i = 0; i < row; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}
