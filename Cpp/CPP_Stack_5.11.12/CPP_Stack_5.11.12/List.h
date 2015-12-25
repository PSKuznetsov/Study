#include <stdio.h>
#include <string>

template <class T>
class List {
    
    struct Element {
        
        T data;
        Element* next;
        Element(T data):data(data), next(0){}
        
    };
    
    Element* head;
    unsigned int size;
    
    Element* find(unsigned int index) {
        if (index < 1 || index > size) {
            return NULL;
        }
        else {
            
            Element* currentElement = head;
            
            for (int i = 1; i < index; ++i) {
                currentElement = currentElement -> next;
            }
            return currentElement;
        }
    }
    
public:
    
    List():head(0), size(0){}
    
    bool isEmpty();
    unsigned int length();
    T getObjectAtIndex(unsigned int index);
    void deleteObjectAtIndex(unsigned int index);
    void insert(T data, int index);
};