#include "Stack.h"

template <>
bool Stack<std::string>::isEmpty() {
    return head == 0;
}

template <>
std::string Stack<std::string>::pop() {
    
    if (isEmpty()) {
        return 0;//Also we can generate exception here...
    }
    
    Element* tmpElement = head;
    std::string tmpData = tmpElement -> data;
    head = tmpElement -> next;
    
    delete tmpElement;
    
    return tmpData;
}

template <>
void Stack<std::string>::push(const std::string data) {
    
    head = new Element(data, head);
}

template <>
std::string Stack<std::string>::top() {
    
    if (isEmpty()) {
        
        return 0;//So, here we can throw exception, too...
    }
    else {
        
        return head -> data;
    }
}