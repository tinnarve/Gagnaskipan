#ifndef STACK_H
#define STACK_H
#include "measurement.h"
#include "Node.h"
#include <iostream>
using namespace std;

class Stack
{
    public:
        Stack();
        virtual ~Stack();

        void push(Measurement data);
        Measurement pop();
        int size();
        bool isEmpty();

        friend ostream& operator <<(ostream &out, const Stack& s);

    protected:

    private:
        Node *head;
        Node *tail;
        int stack_counter;
};
#endif // STACK_h
