#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//create a node struct
struct Node {
  string data;
  Node *next;
};

class Stack {
  public:
    Stack(); //constructor
    ~Stack(); //deconstructor
    void push(string d); //pushes a node onto top of Stack
    string pop(); //pop top node off of the stack
    string toString(); //display the stack's contents as
                       //a string (top->bottom)
    bool isEmpty();
  private:
    Node *top;
};

Stack::Stack() {
    //initalize stack to be empty
    top = NULL;
}

Stack::~Stack() {
  //deconstructor to delete all of the dynamic variables
  while (!isEmpty())
    pop();
}

void Stack::push(string d) {
  //Need a new node to store d in
  Node *temp = new Node;
  temp->data = d;
  temp->next = top; //point the new node's next to the
                    //old top of the stack
  top = temp; //point top to the new top of the stack

}

string Stack::pop() {
  if (!isEmpty()) {
    string value = top->data;
    Node *oldtop = top;
    top = oldtop->next;
    delete oldtop;
    return value;
  } else {
    //can't pop from empty stack!
    cout << "You can't pop from an empty stack!" << endl;
    exit(1);
  }
}

string Stack::toString() {
  string result = "(top) -> ";
  if (isEmpty()) {
    result = result + "NULL";
    return result;
  } else {
    Node *current = top;
    while (current != NULL) {
      result = result + current->data + " -> ";
      current = current->next;
    }
    result = result + "(END)";
    return result;
  }
}

bool Stack::isEmpty() {
  return (top == NULL);
}

int main() {
  Stack *s = new Stack();
  cout << "Output when empty: " << endl
       << s->toString() << endl;
  s->push("Cheeseburger");
  s->push("Pizza");
  s->push("Large coffee");
  s->pop();
  cout << "Output when not empty: " << endl
       << s->toString() << endl;

  delete s;
  return 0;
}
