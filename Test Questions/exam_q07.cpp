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
    friend bool operator==(Stack &left, Stack &right);

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

      int value = temp->data;
      delete(temp);
      return value;
    }

    //return 0;
}


bool Stack::isEmpty() {
    return (top==NULL);
}


void Stack::displayStack() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    }
    else {
        Node *current;
        current = top;
        cout << "--TOP--" << endl;
        while (current != NULL) {
            cout << current->data << endl;
            current = current->next;
        }
        cout << "--BOTTOM--" << endl;
    }
}

bool operator==(Stack &left, Stack &right) {
  if (left.isEmpty() && right.isEmpty()) {
    return true;
  }
  //PART B
  Node* lCurrent = left.top;
  Node* rCurrent = right.top;
  while((lCurrent != NULL)||(rCurrent != NULL)){
    if(lCurrent == rCurrent){
      lCurrent = lCurrent->next;
      rCurrent = rCurrent->next;
    }else{
      return false;
    }
  }
  return true;
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

    Stack *s2 = new Stack(); //don't need "new" for ordinary variables!
    s2->displayStack();
    s2->push(20);

    if (*s == *s2) {
        cout << "the stacks are the same!" << endl;
    }
    else{
      cout << "The stacks are different" << endl;
    }

    s->pop();
    s->displayStack();
    s->pop();
    s->displayStack();
    s->pop();
    //delete s;
    //delete s2;

    return 0;
}
