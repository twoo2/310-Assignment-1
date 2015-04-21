// Assignment #1
// Name: Tyler Woo
// ASU Email Address: twoo2@asu.edu
// Description: Header file for class LinkedList and class fuctions

#include <iostream> //to use cout
#include <string> //to use strings

using namespace std;
//struct Customer represents some customer information
struct Customer
 {
  string firstName;
  string lastName; 
  double amount;
  struct Customer * next;
 };

//class LinkedList will contains a linked list of customers
class LinkedList
 {
  private:
     struct Customer * head;

  public:
     LinkedList();
     ~LinkedList();
     bool addElement(string firstname, string lastname, double amt, int index);
     bool removeElement(string firstname, string lastname);
     void printList();
 };

//Constructor 
//It sets head to be NULL to create an empty linked list
LinkedList::LinkedList()
 {
   head = NULL;
 }
int custCount; //total customer counter
//Destructor
//removes all elements of the linked list by clearing the head as it moves through the list
LinkedList::~LinkedList()
 {
    struct Customer *temp; //create Customer struct with a temp pointer
    while (head != NULL) //while head pointer is not empty keep removing node elements
    {
      temp = head->next; //sets temp pointer to head->next
      delete head; //removes currect element in head
      head = temp; //sets head to currect temp
    }
    cout << "The number of deleted customers is: " << custCount << "\n"; //display 'remove' message
 }
//addElement
//attempts to add an element into the linked list  using firstname, lastname, amt, and index
//all pertaining variables stored under a new Customer 
bool LinkedList::addElement(string firstname, string lastname, double amt, int index)
 {
    Customer* tempo = new Customer(); //creates tempo pointer as a new Customer
    tempo->firstName = firstname; //sets firstName to firstname
    tempo->lastName = lastname;  //sets lastName to lastname
    tempo->amount = amt; //sets amount to amt
    tempo->next = NULL; //sets next pointer to empty
    if(index < 0) //checks if index is before the starting position or unreadable
    {
      return false; //returns false if index is out of bounds
    }
    if(index == 0) //checks if index is at the first position, adds element
    {
      tempo->next = head; //sets next to head
      head = tempo;  //sets head to tempo
      custCount++; //customer count is iterated by one
      return true; //successfully added an element
    } 
    if(index > 0) //checks if index is after at first position     
    {
      Customer* tempo1 = head;  //another temporary element is set to head
      for(int i = -1; i<index-2; i++) //steps through total index
      {     
            if(tempo1->next == NULL) //if the next element is empty do not add
            {
             return false;
            }
            else //adds element if otherwise
            {
             tempo1 = tempo1->next;
            }
      }
      tempo->next = tempo1->next; //moves node to next spot
      tempo1->next = tempo; 
      custCount++; //customer count is increased
      return true;
    }
 }
//removeElement
//using firstname and lastname this function attempts to remove a person from the list
//true if removed, false if otherwise
bool LinkedList::removeElement(string firstname, string lastname)
 {
    Customer* header = head; //pointer header created and set to head
    Customer* tail = NULL; //pointer tail created and set to NULL
    while(header != NULL) //if header is not NULL, check first and last names
    {
      if(header->firstName == firstname) //checks equality of first name
      {
        if(header->lastName == lastname) //checks equality of last name
        {
          break; //breaks if true
        }
      } 
      else //moves to next node if no match has been found
      {
        tail = header; //sets tail to current header
        header = header->next; //moves header to next node
      }
    } 
    if(header == NULL) //if header is NULL return false, no name in list
    {
      return false;
    } 
    else
    {
      if(head == header) //if head equals header set head to the next node
      {
        head = head->next;
      }
      else //set tail next node to header next node
      {
        tail->next = header->next;
      } 
      delete header; //remove element
      custCount--; //customer count reduced by one
      return true; //successfuly removed element
    }
  }  
//printList
//displays relevant customer information including first, last names and balance amount
//ends with a new line
void LinkedList::printList()
 {
   Customer* prnt = head; //creates new prnt pointer and set to head
   while(prnt != NULL) //while element is not empty print following statements
   {
    cout << "Customer Name: ";
    cout << prnt->firstName;
    cout << " ";
    cout << prnt->lastName;
    cout << "\n";
    cout << "Balance Amount: ";
    cout << prnt->amount << " dollars";
    cout << "\n\n";
    prnt = prnt->next; //sets prnt to the next node
   }
   cout << "\n"; //create new line
 }

