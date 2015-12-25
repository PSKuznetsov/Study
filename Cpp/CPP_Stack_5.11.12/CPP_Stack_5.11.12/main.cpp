#include <iostream>
#include <string>
#include <fstream>

#include "Stack.h"
#include "Queue.h"
#include "List.h"
#include "DoubleLinkedList.h"

using namespace std;

Stack<string> solveTaskWithStackFromFile(Stack<string> stack, ifstream& in, int& count) {
    
    string currentWord, tmp;
    
    while (in >> tmp) {
        
        stack.push(tmp);
    }
    
    currentWord = stack.pop();
    
    Stack<string> resultStack;
    resultStack.push(currentWord);
    
    count = 1;
    
    while (!stack.isEmpty()) {
        
        tmp = stack.pop();
        
        if (tmp == currentWord) {
            
            count++;
        }
        else {
            
            resultStack.push(tmp);
        }
    }
    return resultStack;
    
}

Queue<string> solveTaskWithQueueFromFile(Queue<string> queue, ifstream& in, int& count) {
    
    Queue<string> resultQueue;
    string currentWord, tmp;
    
    count = 1;
    
    while (in >> tmp) {
        
        queue.push(tmp);
    }
    
    currentWord = queue.back();
    
    while (!queue.isEmpty()) {
        
        tmp = queue.pop();
        if (tmp == currentWord) {
            count ++;
        }
        else {
            resultQueue.push(tmp);
        }
    }
    
    if (count > 1) {
        count --;
    }
    resultQueue.push(currentWord);
    
    return resultQueue;
}

void solveTaskWithListFromFile(List<string>& list, ifstream& in, int& count) {
    
    string currentWord, tmp;
    count = 0;
    
    while (in >> tmp) {
        
        list.insert(tmp, list.length() + 1);
        
    }
    
    currentWord = list.getObjectAtIndex(list.length());
    
    for (int i = 1; i < list.length(); ++i) {
        for (int j = i + 1; j <=list.length(); ++j) {
        
            if (list.getObjectAtIndex(j) == currentWord) {
                count++;
                list.deleteObjectAtIndex(j);
            }
        }
    }
    list.insert(currentWord, list.length() + 1);
}

void solveTaskWithDoubleLinkedListFromFile(DoubleLinkedList<string>& list, ifstream& in, int& count) {
    
    string currentWord, tmp;
    count = 0;
    
    while (in >> tmp) {
        
        list.insert(tmp, list.length());
        
    }
    
    currentWord = list.getObjectAtIndex(list.length());
    
    for (int i = 1; i <= list.length();) {
        
        if (list.getObjectAtIndex(i) == currentWord) {
            list.deleteObjectAtIndex(i);
            count++;
        }
        else {
            i++;
        }
    }
    list.insert(currentWord, list.length());
    
}

int main() {
    
    ifstream in ("/Users/NSCoder/Documents/Xcode/C++/CPP_Stack_5.11.12/CPP_Stack_5.11.12/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Xcode/C++/CPP_Stack_5.11.12/CPP_Stack_5.11.12/output.txt");
    
    Stack<string> stack;
    Queue<string> queue;
    List<string>  list;
    DoubleLinkedList<string> doubleLinkedList;
    
    
    out << "–––––––––––Stack–––––––––––" << endl;
    int stackCount = 0;
    
    stack = solveTaskWithStackFromFile(stack, in, stackCount);
    
    while (!stack.isEmpty()) {
        
        out << stack.pop() << endl;
    }
    
    out << "Words count: " << stackCount << endl;
    in.close();
    
    
    out << "–––––––––––Queue–––––––––––" << endl;
    
    in.open("/Users/NSCoder/Documents/Xcode/C++/CPP_Stack_5.11.12/CPP_Stack_5.11.12/input.txt");
    
    int queueCount = 0;
    
    queue = solveTaskWithQueueFromFile(queue, in, queueCount);
    
    while (!queue.isEmpty()) {
        
        out << queue.pop() << endl;
    }
    out << "Words count: " << queueCount << endl;
    in.close();
    
    
    out << "–––––––––––List–––––––––––" << endl;
    
    in.open("/Users/NSCoder/Documents/Xcode/C++/CPP_Stack_5.11.12/CPP_Stack_5.11.12/input.txt");
    
    int listCount = 0;
    
    solveTaskWithListFromFile(list, in, listCount);
    
    for (int i = 1; i <= list.length(); ++i) {
        out << list.getObjectAtIndex(i) << endl;
    }
    
    out << "Words count: " << listCount << endl;
    in.close();
    
   
    out << "–––––––––––Double linked list–––––––––––" << endl;
    
    in.open("/Users/NSCoder/Documents/Xcode/C++/CPP_Stack_5.11.12/CPP_Stack_5.11.12/input.txt");
    
    int doubleLinkedListCount = 0;
    
    solveTaskWithDoubleLinkedListFromFile(doubleLinkedList, in, doubleLinkedListCount);
    
    for (int i = 1; i <= list.length(); ++i) {
        string tmp = doubleLinkedList.getObjectAtIndex(i);
        out << tmp << endl;
        
    }
    
    out << "Words count: " << doubleLinkedListCount << endl;
    in.close();
    out.close();
    
    stack.~Stack();
    queue.~Queue();
    list.~List();
    doubleLinkedList.~DoubleLinkedList();
    
    return 0;
}
