#include "SeatMatrix.h"

SeatMatrix::SeatMatrix(int r, int c) {
    rows = r;
    cols = c;

    seats.resize(rows, vector<bool>(cols, false));
}

void SeatMatrix::displaySeats() const {
    cout << "\n=== Theater Seat Layout ===\n";
    cout << "O = Available | X = Booked\n\n";

    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";

        for (int j = 0; j < cols; j++) {
            if (seats[i][j]) {
                cout << "X ";
            } else {
                cout << "O ";
            }
        }

        cout << endl;
    }
}

bool SeatMatrix::bookSeat(int row, int col) {
    if (row < 1 || row > rows || col < 1 || col > cols) {
        return false;
    }

    if (seats[row - 1][col - 1]) {
        return false;
    }

    seats[row - 1][col - 1] = true;
    return true;
}

bool SeatMatrix::isAvailable(int row, int col) const {
    if (row < 1 || row > rows || col < 1 || col > cols) {
        return false;
    }

    return !seats[row - 1][col - 1];
}