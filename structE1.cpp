#include "structE1.h"
#include <cstring>      
#include <stdexcept> 

struct Data;

class Stack;

Stack::Stack() {
  top=nullptr;
}


Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}


void Stack::push(Data value) {
    StackNode* newNode = new StackNode();
    std::strcpy(newNode->data.str, value.str);
    newNode->data.number = value.number;
    newNode->next = top;
    top = newNode;
}


Data Stack::pop() {
    if (isEmpty()) {throw std::runtime_error("стек пуст");}
    StackNode* tempNode = top;
    Data poppedValue = top->data;
    top = top->next;
    delete tempNode;
    return poppedValue;
}

Data Stack::peek(){
    if (isEmpty()) {throw std::runtime_error("стек пуст");}
    return top->data;
}

bool Stack::isEmpty(){
    return top == nullptr;
}

void Stack::sort() {
    Stack tempStack;
    while (!isEmpty()) {
        Data temp = pop();
        while (!tempStack.isEmpty() && std::strlen(tempStack.peek().str)<std::strlen(temp.str)) {
            push(tempStack.pop());
        }
        tempStack.push(temp);
    }
    while (!tempStack.isEmpty()) {
        push(tempStack.pop());
    }
}
