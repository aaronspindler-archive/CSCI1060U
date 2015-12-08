//Description: Create a linked list class that has nodes that contain a name and
  // a value

//Import libraries
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

//Use the std namespace
using namespace std;

//Declaration of node struct
struct Node {
  string element_name;
  int element_count;
  Node* next;
};

//Declaration of LinkedList class
class LinkedList {
  //Public Declaration
  public:
    //Constructor
    LinkedList();
    //Deconstructor
    ~LinkedList();
    //A function to add a node to the list
    void AddData(string name, int count);
    //Delete a node out of the linkedlist
    void DeleteData(string name, int count);
    //Returns the contents of the linked list
    string toString();
    //A function to determine whether or not the list is empty
    bool isEmpty();

  //Private Declaration
  private:
    Node *first;
    Node *last;
};

LinkedList::LinkedList() {
    //initalize LinkedList to be empty
    first = NULL;
    last = NULL;
}

LinkedList::~LinkedList() {
  //Create a node pointing to the oldTop
  Node *oldTop = first;
  //Create a current node
  Node *current = NULL;
    //While the oldTop is not NULL continue
    while(oldTop){
        //Set the current node to the oldTOp
        current = oldTop;
        //Change oldTop to the next node
        oldTop=oldTop->next;
        //Delete the current node
        delete(current);
    }
}

void LinkedList::AddData(string name, int count) {
  //Create a tempourary node
  Node *temp = new Node;
  //Set the element name to the name passed by the function
  temp->element_name = name;
  //Set the element count to the count passed by the function
  temp->element_count = count;
  //Set the temp node's next pointer to the front of the linked list
  temp->next = first;
  //Set the first node pointer to the temp node
  first = temp;
}

void LinkedList::DeleteData(string name, int count) {
  //Store the current node and the node before the current node
  Node *previous = NULL;
  Node *current = first;

  //If the node you want to delete is the first node you must change the first
  // pointer to first's next node
  if((first->element_name == name)&&(first->element_count == count)){
    Node* oldFirst = first;
    first = first->next;
    delete oldFirst;
  }

  //Loop through the linkedlist until current is empty
  while(current != NULL){
    //If the current node fields are the same as the ones you want to delete
    // set the previous next to the current next then delete current
    if((current->element_name == name)&&(current->element_count == count)){
      previous->next = current->next;
      delete current;
    }
    //Increase your position in the list by one
    previous = current;
    current = current->next;
  }
}

string LinkedList::toString() {
  //Create a stream to convert ints to strings
  std::ostringstream oss;

  //Create a variable to store the result so that it can be returned
  string result = "";
  //If the linkedlist is empty return the result with a null array
  if(isEmpty()){
    result = "[NULL]";
    return result;
  }else{
    //Make a Node pointer to the first position in the linked list
    Node *current = first;
    //Write the element count of the current node to the stream
    oss << current->element_count;
    //Add the string to the result
    result = "[" +current->element_name + ", " + oss.str() + "]";
    //Change the current node pointer to the next node
    current = current->next;
    //Loop through the linked list until the current node pointer is null
    while(current != NULL){
      //Clear the outstring stream
      oss.str("");
      //Write the element for the current node to the string stream
      oss << current->element_count;
      //Add the current node to the result string
      result = result + " -> [" + current->element_name + ", " + oss.str() + "]";
      //Change the current node to the next node
      current = current->next;
    }
    //Finally return the string
    return result;
  }
}

bool LinkedList::isEmpty() {
  //If the first and last pointers are null then the linked list is empty
  return ((first == NULL)&&(last == NULL));
}

int main() {
  //Creating a linkedlist to test
  LinkedList *ll = new LinkedList();
  //Adding nodes to the linked list
  ll->AddData("Fish",12);
  ll->AddData("Dogs",13);
  ll->AddData("Frogs",13337);
  ll->AddData("Goats",909);
  ll->AddData("Cats",0);
  //Printing the list
  cout << ll->toString() << endl;

  //Testing deletion of a node
  ll->DeleteData("Goats",909);
  cout << ll->toString() << endl;
}
