#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

#include "listnode.h"

using namespace std;

class InvalidPositionException { };

template <class T>

class DoublyLinkedList {
    public:
        DoublyLinkedList() {

            size = 0;
            //make a new instance of head & tail.
            head = new ListNode<T>();
            tail = new ListNode<T>();

            //make sure head and tail point at each other.
            head->next = tail;
            tail->prev = head;

            //make sure the current Node points to tail.
            currNode = tail;
            currentPosition = 0;
        }

        ~DoublyLinkedList() {

            //use existing function to delete list.
            clear();
            // delete rest of the pointers.
            delete head;
            delete tail;
        }

        void clear() {
            //start clearing the List from the beginning
            currNode = head->next;

            //loop goes through the whole list by making head
            //point to the node after the first node and then deleting
            while(currNode != tail)
            {
                head->next = currNode->next;
                delete currNode;
                currNode = head->next;
            }
            //make sure tail points to head.
            tail->prev = head;
            size = 0;
            currentPosition = 0;
        }

        void insert(const T& item) {
            //make a new node with an item and the pointers of currNode
            ListNode<T> *newNode = new ListNode<T>(item, currNode->prev, currNode);
            //make sure the previous node and currNode now point to the new one.
            currNode->prev->next = newNode;
            currNode->prev = newNode;

            size++;
            currentPosition++;
        }

        void append(const T& item) {
            //make a new Node with item and tail.
            ListNode<T> *newNode = new ListNode<T>(item, tail->prev, tail);
            //make sure the previous node and tail point to the new Node
            tail->prev->next = newNode;
            tail->prev = newNode;

            size++;
            if(currNode == tail)
            {   //make sure the current position count only gets higher
                //if currNode points to tail.
                currentPosition++;
            }
        }
        T remove() {

            if(currNode == tail)
            {   //can't remove the tail.
                throw InvalidPositionException();
            }

            if(currentPosition != 0)
            {
                currentPosition--;
            }
            //make a template temp to store the data which will be deleted.
            T returnData = currNode->data;
            //connect the previous and the next node to each other instead of currNode.
            currNode->next->prev = currNode->prev;
            currNode->prev->next = currNode->next;
            //make sure we don't lose the list when we delete currNode.
            ListNode<T> *nextCurr = currNode->next;

            delete currNode;
            //make sure the currNode is now the one after the one we just deleted.
            currNode = nextCurr;

            size--;

            return returnData;
        }

        void move_to_start() {
            //make currNode point to the first node after head (can be tail)
            currNode = head->next;
            currentPosition = 0;
        }

        void move_to_end() {
            currNode = tail;
            currentPosition = size;
        }

        void prev() {
            //while currNode does not point to the first node move it one node back.
            if(currNode != head->next)
            {
                currNode = currNode->prev;
                currentPosition--;
            }
        }

        void next() {
            //while currNode does not point to the tail move it to the next node
            if(currNode != tail)
            {
                currNode = currNode->next;
                currentPosition++;
            }
        }

        int length() const {

            return size;
        }

        int curr_pos() const {

            return currentPosition;
        }

        void move_to_pos(int pos) {
            // check if pos is inside the list.
            if(pos > size || pos < 0)
            {
                throw InvalidPositionException();
            }
            else
            {   // move currNode to pos using a loop.
                currentPosition = pos;
                currNode = head->next;
                for(int i = 0; i < pos; i++)
                {
                    currNode = currNode->next;
                }
            }
        }

        const T& get_value() const {
            if(currNode == tail)
            {   //tail has no data.
                throw InvalidPositionException();
            }
            else
            {
                return currNode->data;
            }
        }

        friend ostream& operator <<(ostream& outs, const DoublyLinkedList& lis) {

            ListNode<T> *tempNode = lis.head->next;
            while(tempNode != lis.tail)
            {
                outs << tempNode->data << " ";
                tempNode = tempNode->next;
            }
            return outs;
        }

    private:

        // head is our preceding node
        // not a data node itself
        ListNode<T> *head;

        // tail is our trailing node
        // not a data node itself
        ListNode<T> *tail;

        //currNode is the node at the current position
        ListNode<T> *currNode;

        int size;
        int currentPosition;
};


#endif // DOUBLY_LINKED_LIST_H
