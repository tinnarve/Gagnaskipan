#include "stack.h"

Stack::Stack()
{
    head = NULL;
    tail = NULL;
    stack_counter = 0;
}

Stack::~Stack()
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

void Stack::push(Measurement data)
{
     if(head == NULL)
    {
        Node *node = new Node(data, head);
        tail = head;
        head = node;
    }
    else{

        Node *temp = new Node(data, head);
        temp ->_data = data;
        temp ->_next = head;
        head = temp;
    }
    stack_counter++;

}
Measurement Stack::pop()
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
        stack_counter--;

        return node->_data;
    }

    /*if(isEmpty())
    {
        throw EmptyException();
    }
    else
    {
        if (head->_next == NULL) {
            Measurement m = head->_data;
            delete head;
            head = NULL;
        }
        else {
            Measurement m = tail->_data;
            Node *prevTail = head;
            Node *tail2 = head->_next;
            while (tail2->_next != NULL) {
                prevTail = tail2;
                tail2 = tail2->_next;
            }
            delete tail2;
            prevTail->_next = NULL;
            return m;
        Measurement m = tail->_data;
        Node* temp_node = tail->_next;
        delete tail;
        tail = temp_node;
        return m;
        Node *node = tail->_next;
        tail = NULL;

        if(head == NULL)
        {
            tail = NULL;
        }
        stack_counter--;

        return node->_data;
    }*/
}
int Stack::size()
{
    return stack_counter;
}
bool Stack::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    return false;
}

ostream& operator <<(ostream &out, const Stack& s)
{
        Node *node = s.head;
        while(node != NULL)
        {
            out << node->_data << " ";
            node = node->_next;
        }
        return out;
}
