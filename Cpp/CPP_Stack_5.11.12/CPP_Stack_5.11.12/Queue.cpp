#include "Queue.h"

template <>
bool Queue<std::string>::isEmpty() {
    
    return head == 0;
}

template <>
std::string Queue<std::string>::pop() {
    
    if (isEmpty()) {
        return 0; //We can throw exception here :)
    }
    else {
        Element* tmpElement = head;
        std::string tmpdData = tmpElement -> data;
        head = tmpElement -> next;
        delete tmpElement;
        
        if(head == NULL) {
            
            tail = NULL;
        }
        return tmpdData;
    }
}

template <>
void Queue<std::string>::push(std::string data) {
    
    Element* tmpElement = tail;
    tail = new Element(data);
    
    if (!head) {
        
        head = tail;
    }
    else {
        
        tmpElement -> next = tail;
    }
}

template <>
std::string Queue<std::string>::back() {
    return tail -> data;
}
