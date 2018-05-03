#ifndef KEYDATALISTNODE_H
#define KEYDATALISTNODE_H

using namespace std;

template <class K, class T>
class KeyDataListNode
{
    public:
        KeyDataListNode(K key, T data, KeyDataListNode* next = NULL)
            : key(key), data(data), next(next) {};
        virtual ~KeyDataListNode() {};

        K key;
        T data;
        KeyDataListNode* next;

};

#endif // KEYDATALISTNODE_H
