#include <iostream>
#include <string>
#include <vector>

#include "Trie.h"
#include "TicketHashMap.h"
#include "SeatMatrix.h"

using namespace std;

int main() {

    Trie movieSearch;

    movieSearch.insert("Avengers");
    movieSearch.insert("Avatar");
    movieSearch.insert("Animal");
    movieSearch.insert("Dangal");
    movieSearch.insert("Drishyam");
    movieSearch.insert("Brahmastra");

    cout << "=== CineSeat Phase-II Demo ===\n\n";

    // Movie Search
    string prefix;

    cout << "Enter movie prefix: ";
    cin >> prefix;

    vector<string> suggestions = movieSearch.autocomplete(prefix);

    cout << "\nMovie Suggestions:\n";

    if (suggestions.empty()) {
        cout << "No movies found.\n";
    } else {
        for (string movie : suggestions) {
            cout << "- " << movie << endl;
        }
    }

    // Seat Matrix
    SeatMatrix theater(5, 10);

    theater.displaySeats();

    int row, col;

    cout << "\nEnter seat row (1-5): ";
    cin >> row;

    cout << "Enter seat column (1-10): ";
    cin >> col;

    if (theater.bookSeat(row, col)) {

        cout << "\nSeat booked successfully!\n";

    } else {

        cout << "\nSeat is already booked or invalid!\n";
    }

    theater.displaySeats();

    // Ticket and PNR
    TicketHashMap ticketMap;

    Ticket t1;

    t1.pnr = "CIN1001";
    t1.passengerName = "Rohan";
    t1.movieName = "Avengers";

    // Store selected seat in ticket
    t1.seatNumber = "R" + to_string(row) +
                    "C" + to_string(col);

    ticketMap.addTicket(t1);

    // PNR Verification
    string pnr;

    cout << "\nEnter PNR to verify: ";
    cin >> pnr;

    Ticket result;

    if (ticketMap.findTicket(pnr, result)) {

        cout << "\nTicket Found!\n";
        cout << "PNR: " << result.pnr << endl;
        cout << "Passenger: " << result.passengerName << endl;
        cout << "Movie: " << result.movieName << endl;
        cout << "Seat: " << result.seatNumber << endl;

    } else {

        cout << "\nTicket Not Found!\n";
    }

    return 0;
}