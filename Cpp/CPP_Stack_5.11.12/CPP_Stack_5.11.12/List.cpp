#include "List.h"

template <>
bool List<std::string>::isEmpty() {
    return head == 0;
}

template <>
unsigned int List<std::string>::length() {
    return size;
}

template <>
void List<std::string>::insert(std::string data, int index) {
    
    if (index < 1 || index > size + 1) {
        
        return;//exception
    }
    else {
        
        Element* newElement = new Element(data);
        size = length() + 1;
        if (index == 1) {
            
            newElement -> next = head;
            head = newElement;
            
        }
        else {
            
            Element* previous = find(index - 1);
            newElement -> next = previous -> next;
            previous -> next = newElement;
            
        }
        
    }
}

template <>
std::string List<std::string>::getObjectAtIndex(unsigned int index) {
    
    if (index < 1 || index > size) {
        return 0;//Here we can throw exception;
    }
    else {
        Element* tmpElem = find(index);
        std::string tmpData = tmpElem -> data;
        return tmpData;
    }
}

template <>
void List<std::string>::deleteObjectAtIndex(unsigned int index) {
    
    if (index < 1 || index > size) {
        return; //Here we can throw exception, too
    }
    
    Element* currentElement;
    --size;
    
    if (index == 1) {
        currentElement = head;
        head = head -> next;
    }
    else {
        Element* previousElement = find(index - 1);
        currentElement = previousElement->next;
        previousElement -> next = currentElement -> next;
    }
    currentElement -> next = NULL;
    delete currentElement;
}





