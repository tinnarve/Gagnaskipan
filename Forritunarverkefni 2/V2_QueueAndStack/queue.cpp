#include "queue.h"

Queue::Queue()
{
    head = NULL;
    tail = NULL;
    queue_counter = 0;
}
Queue::~Queue()
{
    Node *node = head;
    while(node != NULL)
    {
        head = node;
        node = node->_next;
        delete head;
        head = NULL;
        delete tail;
        tail = NULL;
    }
}

void Queue::add(Measurement data)
{
    if(head == NULL)
    {
        Node *node = new Node(data, head);
        tail = node;
        head = node;
    }
    else{

        Node *node = new Node(data, NULL);

        tail->_next = node;
        tail = node;
    }

    queue_counter++;
}
Measurement Queue::remove()
{
    if(isEmpty())
    {
        throw EmptyException();
    }
    else
    {
        Node *node = head;
        head = head->_next;

        if(head == NULL)
        {
            tail = NULL;
        }
        queue_counter--;

        return node->_data;
    }

}
int Queue::size()
{
    return queue_counter;
}
bool Queue::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    return false;
}
ostream& operator <<(ostream &out, const Queue& que)
{
        Node *node = que.head;
        while(node != NULL)
        {
            out << node->_data << " ";
            node = node->_next;
        }
        delete node;
        return out;

}

