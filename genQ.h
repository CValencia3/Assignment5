#pragma once
#include "genDLL.h"
#include <iostream>

using namespace std;

////Template GenQueue Class////
template <class T>
class GenQ
{
    public:
        GenQ(); //constructor
        GenQ(int size); //overloaded constructor
        ~GenQ(); // Destructor

        void insert (T d); //enqueue
        T remove(); //dequeue
        T front(); //peek

        bool isFull();
        bool isEmpty();
        int getSize();

        int mSize;
        int head; //front of queue
        int tail; //rear of queue
        int numElements; //number of elements in my queue

        DoublyLinkedList<T>  *myQueue;
};

// Constructor
template <class T>
GenQ<T>::GenQ()
{
    mSize = 128;
    myQueue = new DoublyLinkedList<T>;
    numElements = 0;
}

// Overloaded constructor
template <class T>
GenQ<T>::GenQ(int maxSize)
{
    mSize = maxSize;
    myQueue = new DoublyLinkedList<T>;
    numElements = 0;
}

// Destructor
template <class T>
GenQ<T>::~GenQ()
{
    delete myQueue;
}

// Insert to queue
template <class T>
void GenQ<T>::insert(T d)
{
    myQueue->insertBack(d);

    ++numElements;
}

// Remove from queue and return the value
template <class T>
T GenQ<T>::remove()
{
    if(isEmpty())
        throw out_of_range("The queue is empty");

    numElements--;
    return myQueue->removeFront(); //advance the head
}

// Return the front of the queue without removing it
template <class T>
T GenQ<T>::front()
{
    return myQueue->getHead()->data;
}

// Tells if full
template <class T>
bool GenQ<T>::isFull()
{
    return (numElements == mSize);
}

// Tells if empty
template <class T>
bool GenQ<T>::isEmpty()
{
    return (numElements == 0);
}

// Returns the size
template <class T>
int GenQ<T>::getSize()
{
    return numElements;
}
