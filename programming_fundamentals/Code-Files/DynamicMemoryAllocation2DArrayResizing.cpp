#include <iostream>
using namespace std;

void AddColumns(int**& p, int rows, int& cols)
{
    int newCols = cols + 1;

    for (int i = 0; i < rows; i++)
    {
        int* newRow = new int[newCols];

        // Copy old data
        for (int j = 0; j < cols; j++)
            newRow[j] = p[i][j];

        // Initialize new column
        newRow[newCols - 1] = 0;

        // Delete old row
        delete[] p[i];

        // Assign new row
        p[i] = newRow;
    }

    cols = newCols;
}

void RowWiseInput(int* p, int cols)
{
    for (int i = 0; i < cols; i++)
        cin >> p[i];
}

void RowWisePrint(int* p, int cols)
{
    for (int i = 0; i < cols; i++)
        cout << p[i] << " ";
}

int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // Create 2D dynamic array
    int** p = new int*[rows];
    for (int i = 0; i < rows; i++)
        p[i] = new int[cols];

    // Input
    cout << "\nEnter matrix values row-wise:\n";
    for (int i = 0; i < rows; i++)
    {
        RowWiseInput(p[i], cols);
    }

    // Print before adding columns
    cout << "\nMatrix before adding a new column:\n";
    for (int i = 0; i < rows; i++)
    {
        RowWisePrint(p[i], cols);
        cout << endl;
    }

    // Add a new column
    AddColumns(p, rows, cols);

    // Print after adding columns
    cout << "\nMatrix after adding a new column:\n";
    for (int i = 0; i < rows; i++)
    {
        RowWisePrint(p[i], cols);
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < rows; i++)
        delete[] p[i];

    delete[] p;

    return 0;
}
