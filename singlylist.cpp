//add a node at  front

#include<iostream>
#include<stdio.h>

using namespace std;

class Node {
    
    public:
        int data;
        Node *next;

   
};

void push (Node** head, int new_data)
{

    Node* new_node = new Node();
    new_node -> next = (*head);
    (*head) = new_node;
}

void printList (Node *node)
{
    while (node !=NULL)
    {
        cout<<" "<< node -> data;
        node = node -> next;
    }
}

int main()
{
    Node* head = NULL;
    //append (%head, 6)

    push(&head, 4);
    
    push(&head, 1);

    cout<<"Created linked list is: ";
    printList(head);

    return 0;
}