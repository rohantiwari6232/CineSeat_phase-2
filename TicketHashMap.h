#ifndef TICKET_HASH_MAP_H
#define TICKET_HASH_MAP_H

#include "Ticket.h"
#include <unordered_map>
using namespace std;

class TicketHashMap {
private:
    unordered_map<string, Ticket> tickets;

public:
    void addTicket(const Ticket& ticket);
    bool findTicket(const string& pnr, Ticket& ticket) const;
    int size() const;
};

#endif