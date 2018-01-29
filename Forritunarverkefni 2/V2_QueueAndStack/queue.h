#ifndef QUEUE_H
#define QUEUE_H
#include "measurement.h"
#include "Node.h"

using namespace std;

class Queue
{
    public:
        Queue();
        virtual ~Queue();

        void add(Measurement data);
        Measurement remove();
        int size();
        bool isEmpty();

        friend ostream& operator <<(ostream& out, const Queue& que);

    private:
        Node *head;
        Node *tail;
        int queue_counter;
};
#endif // QUEUE_h

