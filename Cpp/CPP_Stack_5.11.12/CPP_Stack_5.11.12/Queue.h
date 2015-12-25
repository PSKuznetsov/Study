#include <stdio.h>
#include <string>

template <class T>
class Queue {
    
    struct Element {
        
        T data;
        Element* next;
        Element(T data):data(data), next(0){}
    };
    
    Element* head;
    Element* tail;
    
public:
    
    Queue():head(0), tail(0){}
    
    bool isEmpty();
    T pop();
    void push(T data);
    T back();
    
};