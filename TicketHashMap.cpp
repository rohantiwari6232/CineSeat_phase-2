#include "TicketHashMap.h"

void TicketHashMap::addTicket(const Ticket& ticket) {
    tickets[ticket.pnr] = ticket;
}

bool TicketHashMap::findTicket(const string& pnr, Ticket& ticket) const {
    auto it = tickets.find(pnr);

    if (it == tickets.end()) {
        return false;
    }

    ticket = it->second;
    return true;
}

int TicketHashMap::size() const {
    return tickets.size();
}