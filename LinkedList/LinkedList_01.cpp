/*
    Learning LinkedList in C++ 
    This is Lecture 1 of LinkedList
*/

// Revising OOPs Concepts in C++
// 1. Class and Object
// 2. Constructor and Destructor
// 3. Access Modifiers

// #include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// using namespace std;
// class student {
// public:
//     int rollNo;
//     string name;
//     float percentage;

//     student(int rollNo, string name, float percentage) {
//         this->rollNo = rollNo;
//         this->name = name;
//         this->percentage = percentage;
//     }
// };

// int main() {
//     // Creating a student object
//     student s1(101, "Raghav", 85.5);
//     student s2(102, "Ravi", 90.0);
//     student s3(103, "Riya", 95.0);

//     // Creating a vector of student objects
//     vector<student> students;
//     students.push_back(s1);
//     students.push_back(s2);
//     students.push_back(s3);

//     // Displaying the student details
//     for (int i = 0; i < students.size(); i++) {
//         cout << "Roll No: " << students[i].rollNo << endl;
//         cout << "Name: " << students[i].name << endl;
//         cout << "Percentage: " << students[i].percentage << "%" << endl;
//         cout << endl;
//     }

//     return 0;
// }

// // creating node class
// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
//     // Constructor
//     Node(int value)
//     {
//         data = value;
//         next = NULL;
//     }
// };
// int main()
// {
//     // Creating a node object
//     // Node a;
//     // a.data = 10;
//     // Node b;
//     // b.data = 20;
//     // Node c;
//     // c.data = 30;

//     // Creating nodes using constructor
//     Node a(10);
//     Node b(20);
//     Node c(30);

//     // Linking the nodes
//     a.next = &b;
//     b.next = &c;
//     c.next = NULL;

//     // Displaying the node data
//     Node temp = a;
//     while(1){
//         cout << temp.data << " ";
//         if(temp.next == NULL){
//             break;
//         }
//         temp = *(temp.next);
//     }
//     return 0;
// }

// Implementing some of basic operations on linked list
// 1. display
// 2. length
// 3. display using recursion
// 4. reverse display
// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
//     // Constructor
//     Node(int value)
//     {
//         data = value;
//         next = NULL;
//     }
// };

// // function to display the linked list
// void display(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
//     return;
// }

// // function to calculate the length of the linked list
// int length(Node *head)
// {
//     int count = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         count++;
//         temp = temp->next;
//     }
//     cout << endl;
//     return count;
// }

// // function to display the linked list using recursion
// void displayRecursion(Node *head)
// {
//     if (head == NULL)
//     {
//         return;
//     }
//     cout << head->data << " ";
//     displayRecursion(head->next);
//     return;
// }

// // function to display the linked list using recursion
// void reverseDisplayRecursion(Node *head)
// {
//     if (head == NULL)
//     {
//         return;
//     }
//     reverseDisplayRecursion(head->next);
//     cout << head->data << " ";

//     return;
// }
// int main()
// {
//     // Creating nodes using constructor
//     Node *a = new Node(10);
//     Node *b = new Node(20);
//     Node *c = new Node(30);
//     Node *d = new Node(40);
//     Node *e = new Node(50);
//     // Linking the nodes
//     a->next = b;
//     b->next = c;
//     c->next = d;
//     d->next = e;
//     e->next = NULL;

//     // // Displaying the node data
//     // Node *temp = a;
//     // while (1)
//     // {
//     //     cout << temp->data << " ";
//     //     if (temp->next == NULL)
//     //     {
//     //         break;
//     //     }
//     //     temp = temp->next;
//     // }
//     // cout << endl;
//     // // Displaying the node data using pointer
//     // Node *temp1 = a;
//     // while (temp1 != NULL)
//     // {
//     //     cout << temp1->data << " ";
//     //     temp1 = temp1->next;
//     // }

//     // cout << endl;

//     // Displaying the linked list using function
//     display(a);
//     // printing the length of the linked list
//     cout << "Length of the linked list is: " << length(a) << endl;
//     // Displaying the linked list using recursion
//     cout << "Displaying the linked list using recursion: "<<endl;
//     displayRecursion(a);

//     cout << endl;
//     // Displaying reverse the linked list using recursion
//     cout << "Displaying the linked list using recursion in reverse order: "<<endl;
//     reverseDisplayRecursion(a);
//     return 0;
// }






// Implementing LinkedList class as a data Structure

#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node *head;
    Node *tail;
    int length;
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
        }
// function to insert node at end of linked list method 01
    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // function to insert node at end of linked list method 02
    void insertAtEnd_02(Node* head , int data){
        Node* newNode = new Node(data);
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }   
        temp->next = newNode;
        length++;
        return;
    }


// insert at start of linkedlist
void insertAtStart(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
        }
        length++;
    }


    // insert at any position of linkedlist
    void insertAtPosition(int data, int position) {
        if (position < 0 || position > length) {
            cout << "Invalid position" << endl;
            return;
        }else if(position == 0){
            insertAtStart(data);
            return;
            }else if(
                position == length){
                insertAtEnd(data);
                return;
            } else{
                Node* newNode = new Node(data);
                Node* temp = head;
                for (int i = 0; i < position - 1; i++) {
                    temp = temp->next;
                }   
                newNode->next = temp->next;
                temp->next = newNode;
                length++;
            }

            return;
    }


    // function to get value of node at any position
    int getValueAtPosition(int position) {
        if (position < 0 || position >= length) {
            cout << "Invalid position" << endl;
            return -1;
        } else if (position == 0) {
            return head->data;
        } else if( position == length - 1){
            return tail->data;

        }else {
            Node *temp = head;
            for (int i = 0; i < position; i++) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    // function to delete at head
    void deleteAtHead() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        } else{
             Node *temp = head;
             head = head->next;
             delete temp;
             length--;
        }
        return;
       
    }


    // function to delete at tail
    void deleteAtTail() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node *temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            tail = temp;
        }
        length--;
        return;
    }

// function to delete node of a linkedlist 
void deleteNode(int position) {
    if (position < 0 || position >= length) {
        cout << "Invalid position" << endl;
        return;
    } else if (position == 0) {
        deleteAtHead();
    }else if(position == length-1){
        deleteAtTail();
    } else {
        Node *temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
         temp->next = temp->next->next;
        
    }
    length--;
    return;
    }

// function to insert node at end of linked list method 03
    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.display();
    list.insertAtEnd(20);
    list.display();
    list.insertAtEnd(30);
    list.display();
    list.insertAtEnd(40);
    list.display();
    list.insertAtEnd(50);
    list.display();
    list.insertAtEnd(60);
    list.display();
    cout<<list.length;

    cout<<endl;
    list.insertAtEnd_02(list.head , 100);
    list.display();
    cout<<list.length;

    cout<<endl;
    list.insertAtStart(5);
    list.display();
    cout<<list.length;

    cout<<endl;
    list.insertAtPosition(25, 2);
    list.display();
    cout<<list.length;


    cout<<endl;
    cout << "Value at position 2: " << list.getValueAtPosition(2) << endl;
    cout << "Value at position 4: " << list.getValueAtPosition(4) << endl;

    cout<<"\n"  
    << "Deleting node at position 2" << endl;
    list.deleteAtHead();
    list.display();
    cout<<list.length;

    cout<<"\n";
    cout << "Deleting node at position 2" << endl;
    list.deleteAtTail();
    list.display();
    cout<<list.length;

    cout<<"\n";
    cout << "Deleting node at position 2" << endl;
    list.deleteNode(2);
    list.display();
    cout<<list.length;
    cout<<"\n";


    return 0;
}
