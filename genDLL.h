#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

////Template ListNode Class////
template <class T>
class ListNode
{
    public:
        ListNode();
        ListNode(T d);
        ~ListNode();
        T data;
        ListNode *next;
        ListNode *prev;
};

////Implementation////
template <class T>
ListNode<T>::ListNode()
{
    data = NULL;
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d)
{
    data = d;
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{

}

////Template Doubly Linked List Class////
template <class T>
class DoublyLinkedList
{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        // Add to the front of the list
        void insertFront(T data);
        // Add to the back of the list
        void insertBack(T data);
        // Remove the front of the list and return the data
        T removeFront();
        // Remove the back of the list and return the data
        T removeBack();
        // Remove specific data from the list and return it
        T remove(T key);

        // Accessor method: get the front of the list
        ListNode<T>* getHead() {return front;}

        void printList();
        int find(T val); //search()

        bool isEmpty();
        unsigned int getSize();
        // Delete the element at the given index
        T deletePos(int position);
};

////implementation////
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    size = 0;
    front = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    ListNode<T> *current = front;
    ListNode<T> *next = front;

    while (size > 0)
    {
        // Rearrange pointers
        next = current->next;
        if(next!=NULL) next->prev = NULL;
        current->next = NULL;

        delete current;
        current = next;
        size--;
    }
}

// Insert to the front of the list
template <class T>
void DoublyLinkedList<T>::insertFront(T data)
{
    ListNode<T> *node = new ListNode<T>(data);
    if(isEmpty())
    {
        back = node;
    }
    else //not an empty list
    {
        node->next = front;
        front->prev = node;
    }
    front = node;
    size++;
}

// Insert to the back of the list
template <class T>
void DoublyLinkedList<T>::insertBack(T data)
{
    ListNode<T> *node = new ListNode<T>(data);
    if(isEmpty())
    {
        front = node;
    }
    else //not an empty list
    {
        back->next = node;
        node->prev = back;
    }
    back = node;
    size++;
}

// Remove the front of the list and return the value
template <class T>
T DoublyLinkedList<T>::removeFront()
{
    //check if empty
    if(isEmpty())
    {
        throw out_of_range("The List is Empty");
    }

    ListNode<T> *node = front;

    //check if there is only one element
    if(front->next == NULL) // there is only one element in the list
    {
        back = NULL;
    }
    else //more than one element
    {
        //set the prev of the next node to null
        front->next->prev = NULL;
    }

    // Rearrage pointers
    front = front->next;
    T temp = node->data;
    node->next = NULL;

    delete node;
    size--;

    return temp;
}

// Remove the back of the list and return the value
template <class T>
T DoublyLinkedList<T>::removeBack()
{
    //check if empty
    if(isEmpty())
    {
        throw out_of_range("The List is Empty");
    }

    ListNode<T> *node = front;
    //check if there is only one element
    if(front->next == NULL) // there is only one element in the list
    {
        back = NULL;
    }
    else //more than one element
    {
        //set the prev of the next node to null
        front->next->prev = NULL;
    }
    front = front->next;
    T temp = node->data;
    node->next = NULL;

    delete node;
    size--;

    return temp;
}

// Remove a specific element from the list and return the value
template <class T>
T DoublyLinkedList<T>::remove(T key)
{
    //check if empty
    if(isEmpty())
        throw out_of_range("The List is Empty");

    ListNode<T> *current = front;

    while(current->data != key)
    {
        current=current->next;
        if(current == NULL)
            return NULL;
    }

    if(current == front)//front node
        front = current->next;
    else
        current->prev->next = current->next;

    if(current == back)
        back = current->prev;
    else
        current->next->prev = current->prev;

    current->next = NULL;
    current->prev = NULL;

    size--;

    return current->data;

}

// Print the values in the list
template <class T>
void DoublyLinkedList<T>::printList()
{
    ListNode<T> *current = front;

    if(isEmpty())
    {
        cout << "There is nothing here" << endl;
    }
    else
    {
        while(current)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
}

// Find a specific value and return the index
template <class T>
int DoublyLinkedList<T>::find(T val)
{
    int idx = -1;

    ListNode<T> *current = front;
    while(current != NULL)
    {
        ++idx;
        if (current->data == val) //we found it
            break;
        else
            current = current->next;
    }

    if (current == NULL)
        idx = -1;

    return idx;
}

// Tell if the list is empty
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (size == 0);
}

// Return the size
template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
    return size;
}

// Delete a node in a certain index and return the value in that index
template <class T>
T DoublyLinkedList<T>::deletePos(int position)
{
    if (position > size)
        throw out_of_range("Given position was out of range of the list");

    int idx = 0;

    ListNode<T> *current = front;
    ListNode<T> *prev = front;

    while(idx =! position)
    {
        prev = current; //stay back
        current = current->next;
        ++idx;
    }

    //when we find the correct position, update pointers
    prev->next = current->next;
    current->next = NULL;
    int temp = current->data;
    delete current;
    size--;

    return temp;
}
