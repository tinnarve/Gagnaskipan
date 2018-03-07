#ifndef NODE_H
#define NODE_H
#include "measurement.h"

class EmptyException{};

class Node
{
    public:
        Node(Measurement _data, Node* _next) : _data(_data), _next(_next){};
        virtual ~Node(){};

        Measurement _data;
        Node *_next;

        friend ostream& operator <<(ostream &out, const Node s);

    private:
};

#endif // NODE_H
