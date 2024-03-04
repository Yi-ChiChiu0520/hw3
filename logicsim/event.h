#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
    bool operator()(const Event* lhs, const Event* rhs) const {
        // Compare Events by time to sort them in ascending order
        return lhs->time < rhs->time;
    }
} EventLess;
	
#endif
