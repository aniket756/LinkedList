#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList
{
private:
    Node *head;

public:
    // Constructor to initialize an empty list
    LinkedList() : head(nullptr) {}

    // Destructor to free memory when the list is destroyed
    ~LinkedList()
    {
        clear();
    }

    // Function to insert a new node at the end of the list
    void append(int);
    // Function to create list
    void createList();
    // function ot insert at beginning
    void atBegin(int);
    // function to add at given position
    void atPos(int, int);
    // Function to print the elements of the list
    void printList();
    // Function to delete all nodes in the list and free memory
    void clear();
    // Function to delete node from list
    void delBeg();
    void delEnd();
    void delPos(int);
    // Function to find length of list
    void getLength();
    // Function to reverse a list
    void reverseList();
};

int main()
{
    // Create a linked list object
    LinkedList myList;

    // Append some elements to the list
    myList.createList();

    // Print the elements of the list
    cout << "Linked List: ";
    myList.printList();
    myList.atBegin(23);
    myList.delEnd();
    myList.printList();
    myList.delPos(3);
    myList.atPos(45, 2);
    myList.delBeg();
    myList.printList();
    myList.getLength();
    myList.reverseList();
    myList.printList();
    return 0;
}
void LinkedList::append(int value)
{
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void LinkedList::createList()
{
    int size;
    cout << "Enter the size of the list:";
    cin >> size;
    while (size--)
    {
        int value;
        cout << "Enter data: ";
        cin >> value;
        append(value);
    }
}
void LinkedList::printList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void LinkedList::clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
void LinkedList::atBegin(int data)
{
    Node *newnode = new Node(data);
    newnode->next = head;
    head = newnode;
}
void LinkedList::atPos(int value, int pos)
{
    Node *newnode = new Node(value);
    Node *temp = head;
    int i = 0;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void LinkedList::delBeg()
{
    Node *temp = head;
    if (temp != nullptr)
    {
        head = head->next;
        delete temp;
    }
    else
        cout << "List is empty";
}
void LinkedList::delEnd()
{
    Node *temp, *prevnode;
    temp = head;

    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head)
        head = 0;
    else
        prevnode->next = 0;
    delete temp;
}
void LinkedList::delPos(int pos)
{
    Node *temp, *nextnode;
    int i = 1;
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    delete nextnode;
}

void LinkedList::getLength()
{
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    cout << "Length of the linked list is " << count << endl;
}
void LinkedList::reverseList()
{
    Node *prevnode, *currentnode, *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}
