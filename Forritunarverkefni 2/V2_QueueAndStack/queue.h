#ifndef QUEUE_H
#define QUEUE_H
#include "measurement.h"

using namespace std;

class EmptyException();

class Queue
{
    public:
        Queue();
        virtual ~Queue();

        void add(Measurement data);
        Measurement remove();
        int size();
        bool isEmpty();
        friend ostream &operator << (ostream&, const Queue q);

    private:
};



#endif // QUEUE_h

