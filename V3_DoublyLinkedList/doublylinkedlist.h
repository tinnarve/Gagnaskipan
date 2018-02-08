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
            head = new ListNode<T>();
            tail = new ListNode<T>();

            head->next = tail;
            tail->prev = head;
            currNode = tail;
            currentPosition = 0;
        }

        ~DoublyLinkedList() {

            clear();

            delete head;
            delete tail;
        }

        // Clear contents from the list, to make it empty.
        // Worst-case time complexity: Linear
        void clear() {

            currNode = head->next;

            while(currNode->next != tail)
            {
                head->next = currNode->next;
                delete currNode;
                currNode = head->next;
            }
            tail->prev = head;
            size = 0;
            currentPosition = 0;
        }

        // Insert an element at the current location.
        // item: The element to be inserted
        // Worst-case time complexity: Constant
        void insert(const T& item) {

            if(currNode->prev == head)
            {
                ListNode<T> *newNode = new ListNode<T>(item, head, tail);
                head->next = newNode;
                tail->prev = newNode;
            }
            else
            {
                ListNode<T> *newNode = new ListNode<T>(item, currNode->prev, currNode);
                currNode->prev->next = newNode;
                currNode->prev = newNode;
            }
            size++;
        }

        // Append an element at the end of the list.
        // item: The element to be appended.
        // Worst-case time complexity: Constant
        void append(const T& item) {

            if(size == 0)
            {
                ListNode<T> *newNode = new ListNode<T>(item, head, tail);
                head->next = newNode;
                tail->prev = newNode;
            }
            else
            {
                ListNode<T> *newNode = new ListNode<T>(item, tail->prev, tail);
                tail->prev->next = newNode;
                tail->prev = newNode;
                currNode = newNode;
            }
            size++;
        }

        // Remove and return the current element.
        // Return: the element that was removed.
        // Worst-case time complexity: Constant
        // Throws InvalidPositionException if current position is
        // behind the last element
        T remove() {

            T temp;
            temp = currNode.data;
            currNode = currNode->prev;

            return temp;

        }

        // Set the current position to the start of the list
        // Worst-case time complexity: Constant
        void move_to_start() {
            currNode = head->next;
            currentPosition = 1;
        }

        // Set the current position to the end of the list
        // Worst-case time complexity: Constant
        void move_to_end() {
            currNode = tail;
            currentPosition = size;
        }

        // Move the current position one step left. No change
        // if already at beginning.
        // Worst-case time complexity: Constant
        void prev() {

            if(currentPosition > 0)
            {
                currNode = currNode->prev;
                currentPosition--;
            }
        }

        // Move the current position one step right. No change
        // if already at end.
        // Worst-case time complexity: Constant
        void next() {

            if(currentPosition == size)
            {

            }
            else
            {
                currNode = currNode->next;
                currentPosition++;
            }
        }

        // Return: The number of elements in the list.
        // Worst-case time complexity: Constant
        int length() const {

            return size;
        }

        // Return: The position of the current element.
        // Worst-case time complexity: Constant
        int curr_pos() const {

            return currentPosition;
        }

        // Set current position.
        // pos: The position to make current.
        // Worst-case time complexity: Linear
        // Throws InvalidPositionException if 'pos' is not a valid position
        void move_to_pos(int pos) {

            ///TODO: Implement
        }

        // Return: The current element.
        // Worst-case time complexity: Constant
        // Throws InvalidPositionException if current position is
        // behind the last element
        const T& get_value() const {

            ///TODO: Implement
            ///remember to return a value
        }


        // Outputs the elements of 'lis' to the stream 'outs', separated
        // by a single space.
        friend ostream& operator <<(ostream& outs, const DoublyLinkedList& lis) {

            ///TODO: Implement
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
