/********************************************************************************* 
* Diwa Ashwini Vittala, dashwini
* 2022 Spring CSE101 PA5
* Shuffle.cpp
* Main executable, shuffles list until it is back to original list
**********************************************************************************/

#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include "List.h"

using namespace std;

// shuffle(): splits then merges a list
void shuffle(List &orig) {
    List second;
    int num = orig.length();

    orig.moveFront();
    int one = num / 2;
    for (int i = 0; i < one; i += 1) {
        orig.moveNext();
    } 

    for (int i = one; i < num; i += 1) {
        second.insertBefore(orig.moveNext());
        orig.eraseBefore();
    } 

    orig.moveFront();
    second.moveFront();
    for (int i = 0; i < one; i += 1) {
        orig.insertBefore(second.moveNext());
        orig.moveNext();
    }
    if ((num % 2) != 0) {
        orig.insertBefore(second.moveNext());
    }
}


// print(): print function for debugging
void print(List &orig) {
    orig.moveFront();
    while (orig.position() < orig.length()) {
        cout << "\nposition: " << orig.position();
        cout << " - data: " << orig.peekNext();
        orig.moveNext();
    }
    cout << "\n";
}

int main(int argc, char *argv[]){
    int num = stoi(argv[1]);
    if (argc < 2) {
        throw std::logic_error("We need more arguments.\n");
    }

    // print out the deck
    cout << "deck size\tshuffle count\n";
    cout << "------------------------------";
    int s;
    for (int iters = 1; iters <= num; iters += 1) {
        s = 1; // counter
        List orig, comp;
        for (int i = 1; i <= iters; i += 1) {
            orig.insertBefore(i);
        }
        comp = orig; // comparable copy of original
        shuffle(orig);
        while (!comp.equals(orig)) {
            shuffle(orig);
            s = s + 1;
        }
        cout << "\n " << iters << "\t\t" << s;
    }

    cout << "\n";
    return 0;
}
