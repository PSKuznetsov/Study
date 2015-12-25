#include "DoubleLinkedList.h"

template <>
bool DoubleLinkedList<std::string>::isEmpty() {
    
    return head == 0;
}

template <>
int DoubleLinkedList<std::string>::length() {
    
    return size;
}

template <>
std::string DoubleLinkedList<std::string>::getObjectAtIndex(int index) {
    
    if (index < 1 || index > size) {
        return 0;//throw exception here
    }
    else {
        Element* tmpElement = find(index);
        std::string tmpData = tmpElement -> data;
        return tmpData;
    }
}

template <>
void DoubleLinkedList<std::string>::deleteObjectAtIndex(int index) {
    
    if (index < 1 || index > size) {
        return;//throw exception here
    }
    else {
        
        Element* current = find(index);
        --size;
        
        if (size == 0) {
            head = NULL;
            tail = NULL;
        }
        else if (current == head) {
            head = head -> next;
            head -> previous = NULL;
        }
        else if (current == tail) {
            
            tail = tail -> previous;
            tail -> next = NULL;
        }
        else {
            
            current -> previous -> next = current -> next;
            current -> next -> previous = current -> previous;
            
        }
        
        current -> next = NULL;
        current -> previous = NULL;
        delete current;
    }
    
}

template <>
void DoubleLinkedList<std::string>::insert(std::string data, int index) {
    
    if ((index < 1 && head != NULL)||(index > size + 1)) {
        return;//exception
    }
    else {
        
        Element* newElement = new Element(data);
        size = length() + 1;
        
        Element* current = find(index);
        
        if (current == NULL) {
            head = newElement;
            tail = newElement;
        }
        else {
            
            newElement->next = current->next;
            newElement->previous = current;
            current->next = newElement;
            
            if (current == tail) {
                
                tail = newElement;
            }
            else {
                
                newElement->next->previous = newElement;
                
            }
            
        }
        
    }
}


