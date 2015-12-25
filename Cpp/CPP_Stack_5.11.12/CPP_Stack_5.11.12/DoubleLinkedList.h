#include <stdio.h>
#include <string>

template <class T>
class DoubleLinkedList {
    
    struct Element {
        
        T data;
        Element* previous;
        Element* next;
        Element (T data):data(data), next(0), previous(0){}
    };
    
    Element* head;
    Element* tail;
    unsigned int size;
    
    Element* find(unsigned int index) {
        
        if (index < 1 || index > size) {
            return NULL;
        }
        else {
            
            Element* current = head;
            for (int i = 1; i < index; ++i) {
                current = current->next;
            }
            return current;
        }
    }
    
public:
    
    DoubleLinkedList():head(0), tail(0), size(0) {}
    
    bool isEmpty();
    int length();
    T getObjectAtIndex(int index);
    void deleteObjectAtIndex(int index);
    void insert(T data, int index);
    
};