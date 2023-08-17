#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void inserAtTail( Node* &tail, int d){

    Node* temp = new Node (d);
    tail -> next = temp;
    temp ->prev= tail;
    tail = temp;

}

void insertAtHead (Node* &head , int d){

    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head= temp;
}

void insertAtTail(Node* &tail , int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head){

    if (position == 1){
        Node* temp = head;
        head = head ->next;
        temp-> next =NULL;
        delete temp;
    }

    else
    {

        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt <= position)
        {
            prev = curr;
            curr= curr ->next;
            cnt++;
        }

        prev -> next = curr ->next;
        curr ->next =NULL;
        delete curr;
        
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp !=NULL){
        cout<<temp -> data<<" ";
        temp= temp -> next;
    }
    cout<< endl;
}


int main()
    {   
        Node* node1=  new Node(10);
    cout<<node1 -> data<<endl;
    cout<<node1 -> next<<endl;

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    
    insertAtTail(tail ,12);

    print(head);

    insertAtTail (tail, 15);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail,head, 4, 22);
    print(head); 

    cout<<"head"<<head -> data<< endl;
    cout<<"tail"<<tail -> data<< endl;

    deleteNode (1, head);
    print(head);

    inserAtTail(tail, 25);
    print(head);


    return 0;
}
