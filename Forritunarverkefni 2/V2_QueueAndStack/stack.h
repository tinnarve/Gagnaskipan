#ifndef STACK_H
#define STACK_H
#include "measurement.h"
using namespace std;

class Stack
{
    public:
        Stack(){};
        virtual ~Stack(){};

        void push(Measurement data);
        Measurement pop();
        int size();
        bool isEmpty();

        friend ostream& operator <<(ostream &out, const Stack s){//held �a� s� Stack ekki viss
            //�tf�rsla
            return out;
        };

    protected:

    private:
};



#endif // STACK_h
