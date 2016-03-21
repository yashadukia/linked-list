//
//  main.cpp
//  linked-list
//
//  Created by Yash Adukia on 10/11/15.
//  Copyright (c) 2015 Yash Adukia. All rights reserved.
//

#include <iostream>
using namespace std;
#define NEWLINE '\n'

void insert_at_start(int info);
void insert_at_end(int info);
void insert_at_pos(int pos, int info);
void display();
void delete_node(char pos);
void reverse();

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    cout<<"INT *a: "<<sizeof(int *) <<NEWLINE;
    
    int selection = 0;
    
    do {
        cout<<NEWLINE<<NEWLINE<<NEWLINE<<NEWLINE<<NEWLINE<<"Welcome!!!";
        cout<<NEWLINE<<"1. Insert at start";
        cout<<NEWLINE<<"2. insert at end";
        cout<<NEWLINE<<"3. Display";
        cout<<NEWLINE<<"4. Delete (s for start, e for end, # for position)";
        cout<<NEWLINE<<"5. Reverse";
        cout<<NEWLINE<<"6. Exit";
        cout<<NEWLINE<<"Enter Selection: ";
        cin>>selection;
        
        if (selection == 1) {
            int value;
            cout<<NEWLINE<<"Enter a value: ";
            cin>>value;
            insert_at_start(value);
        }
        if (selection == 2) {
            int value;
            cout<<NEWLINE<<"Enter a value: ";
            cin>>value;
            insert_at_end(value);
        }
        if (selection == 3) {
            display();
        }
        if (selection == 4) {
            char value;
            cout<<NEWLINE<<"Enter a value: ";
            cin>>value;
            delete_node(value);
        }
        if (selection == 5) {
            reverse();
        }
    } while (selection != 5);
    
//    struct node *list;
//    insert_at_start(40);
//    insert_at_start(30);
//    insert_at_end(50);
//    insert_at_start(20);
//    insert_at_start(10);
//    display();
//    reverse();
//    display();
    return 0;
}

struct node
{
    int data;
    node *next;
} *head = NULL;

void reverse()
{
    node *temp = new node();
    node *cur = new node();
    
    while (head->next != NULL)
    {
        temp = head;
        head = head->next;
        temp->next = cur;
        cur = temp;
    }
    cout<<NEWLINE<<"value of cur: "<<cur;
    head->next = cur;
    display();
}

void insert_at_start(int info)
{
    node *temp = new node();
    cout<<NEWLINE<<"displaying temp : "<<temp<<NEWLINE;
    
    if (temp == NULL)
    {
        perror("Mem not allocated: ");
    }
    
    temp->data = info;
    
    if (head == NULL)
    {
        cout<<"Linked List is empty";
        head = temp;
        cout<<NEWLINE<<"head address: "<<head<<NEWLINE<<"head value: "<<head->data;
    }
    else
    {
        temp->next = head;
//        head->next = NULL;
        head = temp;
        cout<<NEWLINE<<"The number is added";
    }
}

void insert_at_end(int info)
{
    node *temp = new node();

    if (temp == NULL) {
        perror("Mem not allocated: ");
    }
    
    temp->data = info;
    temp->next = NULL;
    
    if (head == NULL) {
        cout<<"Linked list is empty";
        head = temp;
    }
    else
    {
        node *q = new node();
        q = head;
        while (q->next != NULL)
        {
            q = q->next;
            cout<<NEWLINE<<"Inside while";
        }
        q->next = temp;
        cout<<NEWLINE<<"The number is added at END";
    }
}

void display()
{
    cout<<NEWLINE<<NEWLINE<<NEWLINE<<"DISPLAY LINKED LIST";
    node *list = new node();
    
    if (list ==  NULL)
    {
        perror("Mem not allocated: ");
    }
    
    list = head;
//    int count = 1;
    
    while (list->next != NULL)
    {
        cout<<NEWLINE<<"Value: "<<list->data<<NEWLINE<<"Address: "<<list;
//        count++;
        list = list->next;
    }
    cout<<NEWLINE<<"LAST Value: "<<list->data<<NEWLINE<<"Address: "<<list;
}

void delete_node(char pos)
{
    node *temp = new node();
    node *ref = new node();
    
    if (pos == 's')
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else if (pos == 'e')
    {
        temp = head;
        ref = head;
        while (temp->next != NULL)
        {
            ref = temp;
            temp = temp->next;
        }
        free(temp);
        ref->next = NULL;
    }
    else
    {
        int loc = pos - '0';
        cout<<NEWLINE<<"LOCATION ----------- "<<loc;
        temp = head;
        ref = head;
        int count = 1;
        while (temp->next != NULL)
        {
            ref = temp;
            temp = temp->next;
            cout<<NEWLINE<<"REF VALUE: "<<ref->data<<NEWLINE<<"TEMP VALUE: "<<temp->data;
            count++;
            cout<<NEWLINE<<"count: "<<count;
            if(count == loc)
            {
                cout<<NEWLINE<<"inside IF";
                ref->next = temp->next;
                free(temp);
                break;
            }
        }
    }
}







