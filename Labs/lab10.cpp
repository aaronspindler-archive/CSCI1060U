//Description: Create a linked list class that has nodes that contain a name and
  // a value

//Import libraries
#include <sstream>
#include <iostream>
#include <iomanip>
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
    //A function to print the data values and their counts
    friend void printRawData(LinkedList *list);
    //A function to print a histogram of the data
    friend void printHistogram(LinkedList *list);
    //Calculates the mean count for all data elements
    friend float calculateMean(LinkedList *list);

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

void LinkedList::AddData(string name, int count)
{
  //Create a new node based on the parameters in the function
  Node* nodeToAdd = new Node();
  nodeToAdd->element_name = name;
  nodeToAdd->element_count = count;

  //If the list is empty or the first elements name is greater than or equal
   // to the node to adds element name. Set the nodeToAdds next pointer to the
   // front of the list then set the first pointer to the nodeToAdd
	if (first == NULL || first->element_name >= nodeToAdd->element_name){
		nodeToAdd->next = first;
		first = nodeToAdd;
	}else{
    //Create two node pointers to store the current and the previous nodes
     //Set the current node to the front of the list
		Node* prev = NULL;
		Node* current = first;

    //Loop through the linked list while current is not NULL and currents name
     //is less than or equal to the nodeToAdds name
		while (current != NULL && current->element_name <= nodeToAdd->element_name){
      //Set the previous node pointer to current
			prev = current;
      //Change current to current next
			current = current->next;
		}
		nodeToAdd->next = current;
		prev->next = nodeToAdd;
	}
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

//Prints out the linked lists raw data
void printRawData(LinkedList *list){
  //Points to the first node in the list
  Node* current = list->first;
  //Loop through the list until current == NULL
  while(current != NULL){
    //Make a out string stream to convert int to string
    std::ostringstream oss;
    oss << current->element_count;
    //Output string
    cout << current->element_name << ": " << oss.str() << endl;
    oss.str("");
    //Advance loop one
    current = current->next;
  }
}

//Prints a histogram of the data stored in the linked list
void printHistogram(LinkedList *list){
  //Store a pointer to the current node
  Node* current = list->first;
  //Loop through the linked list until the current pointer points to NULL
  while(current != NULL){
    //Setting up output formatting
    cout << setw(10) << left;
    string elementName = current->element_name + ":";
    cout << elementName;
    //Looping through to print the correct number of astericks
    for(int i = 0; i < current->element_count;i++){
      cout << "*";
    }
    cout << endl;
    //Advance loop one position
    current = current->next;
  }
}

//Calculates the mean value for all elements in the list
float calculateMean(LinkedList *list){
  //Declaring variable to store the total element count and the number of
   // elements
  int total = 0, numElements = 0;
  //Store a pointer to the current node
  Node* current = list->first;
  //Loop through until the current node is NULL
  while(current != NULL){
    //Add the element_count of the current element to the total
    total += current->element_count;
    //Increase numElements by one
    numElements++;
    //Advance the loop one position
    current = current->next;
  }
  // Calculate the mean using the data collected above
  float mean = (float) total/numElements;
  //Print the mean
  return mean;
}

int main() {
  //Creating a linkedlist to test
  LinkedList *ll = new LinkedList();
  //Adding nodes to the linked list
  ll->AddData("Fish",5);
  ll->AddData("Dogs",3);
  ll->AddData("Frogs",6);
  ll->AddData("Goats",9);
  ll->AddData("Cats",2);
  //Printing the list
  cout << ll->toString() << endl;
  //Testing printRawData
  printRawData(ll);
  //Testing calculateMean
  cout << calculateMean(ll) << endl;
  //Testing printHistogram
  printHistogram(ll);

  //Testing deletion of a node
  ll->DeleteData("Goats",9);
  cout << ll->toString() << endl;
  //Testing printRawData
  printRawData(ll);
  //Testing calculateMean
  cout << calculateMean(ll) << endl;
  //Testing printHistogram
  printHistogram(ll);
}
