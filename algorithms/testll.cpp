#include <iostream>
#include <math.h>
#include "linkedlist.hpp"

using namespace std;

void test_append(void) {
    cout << "Append to the tail of the linkedlist:" << endl;
    yaal::LinkedList<int> ll;
    for(int i=1; i<=10; ++i) {
        ll.append(i);
    }
    cout << ll;

    for (int i = 5; i<=10; ++i) {
        ll.erase(i);
        cout << "Erase " << i << ": " << ll;
    }
}

void test_insert(void) {
    cout << "Insert to the head of the linkedlist:" << endl;
    yaal::LinkedList<int> ll;
    for(int i=1; i<=10; ++i) {
        ll.insert(i);
    }
    cout << ll;

    cout << "Reverse the linkedlist:" << endl;
    ll.reverse();
    cout << ll;
}

void test_lliter() {
    cout << "Insert to the head of the linkedlist:" << endl;
    yaal::LinkedList<float> ll;
    for(int i=1; i<=10; ++i) {
        ll.insert(sqrt(i));
    }

    yaal::LinkedListIter<float> *ll_iter = ll.createIter();
    do {
       cout << ll_iter->current() << "->";
    }
    while(ll_iter->next());
    cout << endl;
}

int main(void) {
    test_append();
    test_insert();
    test_lliter();
}
