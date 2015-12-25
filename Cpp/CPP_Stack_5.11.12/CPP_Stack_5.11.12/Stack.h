#pragma once
#include <stdio.h>
#include <string>

template <class T>
class Stack {
    
    struct Element {
        
        T data;
        Element* next;
        Element(T data, Element* elem):data(data),next(elem){}
    };
    
    Element* head;
    
public:

    Stack():head(0){}//?
    
    bool isEmpty();
    T pop();
    void push(const T data);
    T top();
};

