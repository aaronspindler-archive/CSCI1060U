#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};

class Stack {
public:
    Stack(); //constructor
    ~Stack(); //destructor
    void push(int d); //pushes node onto top of stack
    int pop(); //pops top node off of stack -- returns integer popped
    bool isEmpty(); //checks if stack is empty
    void displayStack(); //display contents of stack
                         //from top to bottom
private:
    Node *top; //points to top node in stack
};

Stack::Stack() {
    top = NULL;
}

Stack::~Stack() {
  while (!isEmpty())
    pop();
}

void Stack::push(int d) {
    Node *temp = new Node;
    temp->data = d;
    temp->next = top;
    top = temp;

}

int Stack::pop() {
    if (isEmpty()) {
        cout << "ERROR: Can't pop from empty stack"
             << endl;
        return -1; //error
    }
    else {
      Node* temp = top;
      top = top->next;
      return temp->data;
    }
}


bool Stack::isEmpty() {
    return (top==NULL);
}

void Stack::displayStack() {
  if(!isEmpty()){
    cout << "[" << top->data << ",";
    Node* temp = new Node;
    temp = top->next;
    cout << temp->data << ",";
    while(temp != NULL){
      temp = temp->next;
      cout << temp->data << ",";
    }
    cout << "]";
  }
  else{
    cout << "[]";
  }
}

int main(){
    Stack *s = new Stack(); //don't need "new" for ordinary variables!
    s->displayStack();
    s->push(20);
    s->push(30);
    s->displayStack();
    s->push(40);
    s->push(12);
    s->displayStack();
    s->pop();
    s->displayStack();
    s->pop();
    s->displayStack();
    s->pop();
    delete s;

    return 0;
}
