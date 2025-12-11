#include <iostream>
using namespace std;

int main() {
    int type;   // Ticket type: 1-First, 2-Business, 3-Economy
    int seats;  // Number of seats to book
    int row, column;

    const int ROWS = 13;
    const int COLS = 6;

    // Create 2D dynamic array for seating
    char** a = new char*[ROWS];
    for (int i = 0; i < ROWS; i++)
        a[i] = new char[COLS];

    // Initialize seats to '*'
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            a[i][j] = '*';

    cout << "Kindly enter your ticket type (1-First, 2-Business, 3-Economy): ";
    cin >> type;

    if (type < 1 || type > 3) {
        cout << "Invalid ticket type!" << endl;
        return 0;
    }

    cout << "Enter the number of seats you require: ";
    cin >> seats;

    if (seats > 12) {
        cout << "Sorry! Only 12 seats are available!" << endl;
        return 0;
    }

    // Booking seats
    for (int s = 0; s < seats; s++) {
        cout << "Enter row (1-13) and column (1-6) for seat " << s + 1 << ": ";
        cin >> row >> column;

        if (row < 1 || row > ROWS || column < 1 || column > COLS) {
            cout << "Invalid row or column! Try again." << endl;
            s--; // redo this seat
            continue;
        }

        if (a[row - 1][column - 1] == '*') {
            a[row - 1][column - 1] = 'X'; // Mark seat as booked
        } else {
            cout << "Seat already booked! Choose another." << endl;
            s--; // redo this seat
        }
    }

    // Print seating chart
    cout << "\nSeating Chart (X = booked, * = available):\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < ROWS; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
