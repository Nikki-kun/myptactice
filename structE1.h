#include <string>

struct Data {
    char str[100];
    int number;    
};

struct StackNode {
    Data data;          
    StackNode* next;
};

class Stack {
    private:
    StackNode* top;   
    public:
     Stack();           
     ~Stack();          
     void push(Data value);   
     Data pop();                     
     Data peek();             
     bool isEmpty();
     void sort();
};
