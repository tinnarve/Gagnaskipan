#ifndef KEYDATALISTNODE_H
#define KEYDATALISTNODE_H


class KeyDataListNode
{
    public:
        KeyDataListNode(K key, T data, KeyDataList* next = NULL)
        : key(key), data(data), next(next) {};
        virtual ~KeyDataListNode() {}

    protected:

    private:
        K key;

        KeyDataList* next;
};

#endif // KEYDATALISTNODE_H
