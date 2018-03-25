#include "hashfunctions.h"

int char_hash(char c) {

    return int(c);
}

int int_hash(int i) {

    if(i < 0) {
        return -i;
    }
    return i;
}

int string_hash(string s) {

    ///TODO: Implement better hash function here
    return 0;
}
