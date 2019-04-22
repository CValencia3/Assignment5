
#include <iostream>
#include <string>

using namespace std;

template <class T>
class GenStack{
public:
    // Constructors
    GenStack();
    GenStack(int maxSize);
    // Destructor
    ~GenStack();

    // Add to stack
    void push(T item);
    // Remove top of stack
    T pop();
    // View top of stack
    T peek();

    bool isFull();
    bool isEmpty();

    //Variables
    int size;
    int top;

    T* myArray;
};

// Default constructor
template <class T>
GenStack<T>::GenStack(){
    myArray = new T[128];
    size = 128;
    top = -1; // empty
}

// Overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize){
    myArray = new T[maxSize];
    size = maxSize;
    top = -1; // empty
}

// Destructor
template <class T>
GenStack<T>::~GenStack(){
    if(myArray)
        delete[] myArray;
}

// Add to top of stack
template <class T>
void GenStack<T>::push(T d){
    // If array is full
    if(top == (size-1)){
        // Create a new array
        T* tempArray = new T[size+32];
        // Copy everything over
        for(int i = 0; i < size; ++i)
            tempArray[i]=myArray[i];

        // Switch around pointers
        T* tempPointer = myArray;
        myArray = tempArray;
        tempArray = tempPointer;
        delete[] tempArray;
        size = size+32;
    }
    // Assign new element
    myArray[++top] = d;
}

// Remove top of stack and return the value
template <class T>
T GenStack<T>::pop(){
    if(top == -1)
        throw out_of_range("Your stack is empty.");
    return myArray[top--];
}

// Return the element from the top of the stack
template <class T>
T GenStack<T>::peek(){
    if(top == -1)
        throw out_of_range("Your stack is empty.");
    return myArray[top];
}

// Determines if the stack is full. Returns a bool
template <class T>
bool GenStack<T>::isFull(){
    return (top == size-1);
}

// Determines if the stack is empty. Returns a bool
template <class T>
bool GenStack<T>::isEmpty(){
    return (top == -1);
}

#endif
