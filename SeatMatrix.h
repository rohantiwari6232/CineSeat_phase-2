#ifndef SEAT_MATRIX_H
#define SEAT_MATRIX_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SeatMatrix {
private:
    int rows;
    int cols;
    vector<vector<bool>> seats;

public:
    SeatMatrix(int r, int c);

    void displaySeats() const;
    bool bookSeat(int row, int col);
    bool isAvailable(int row, int col) const;
};

#endif