#include <iostream>
#include "doublylinkedlist.h"

using namespace std;
#include <string>

int main() {

    cout << endl << "STRING_LIST" << endl << endl;

    DoublyLinkedList<char> charList;

    charList.append('a');
    charList.append('b');
    charList.append('c');
    charList.insert('d');
    charList.insert('e');
    charList.insert('f');
    charList.append('x');
    charList.append('z');

    charList.move_to_pos(2);
    charList.insert('1');
    charList.insert('2');
    charList.insert('3');

    cout << charList << endl;

    charList.move_to_start();
    charList.insert('4');
    charList.insert('5');
    charList.insert('6');

    cout << charList << endl;

    charList.move_to_pos(0);
    charList.insert('C');
    charList.insert('A');
    charList.insert('B');

    cout << charList << endl;


    return 0;
}

