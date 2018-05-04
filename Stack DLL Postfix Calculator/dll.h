//
//  dll.h
//  ENGS_65_Project_5
//
//  Created by Spencer Bertsch on 2/24/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//

#include<string>
#ifndef dll_h
#define dll_h
using namespace std;

// Here we construct a single node for the dll
struct Node
{
    int data; //we can store data in the node
    struct Node *next; // we need a pointer to the next node in the list
    struct Node *prev; // and we need a pointer to the next node in the list
};

//
// DLLs have a lot of inherant functionality (Adding a new head, adding a new node after or before a given node, etc.), but becasue
// we are implementing this as a STACK, we simply need to be able to do two things:
// 1. Add a new node to the end of the list - [PUSH]
// 2. Remove the node from the end of the list - [POP]
//

// function POP goes to the end of the dll, stores the data in the last node as an int, and then removes the node and returns the data.
int pop(struct Node** head_ref)
{
    //initialize this variable so we can store the last node's data in here
    int node_data = 0;
    //create a new node called tail
    struct Node *tail = nullptr; //we set this as the tail later
    //struct a new node that we will use later on
    struct Node *node = *head_ref;
    
    
    /* 1. If the Linked List is empty, then state that there are no nodes to pop */
    if (*head_ref == NULL)
    {
        cout << "Cannot pop a node from an empty stack, sorry!" << endl;
    }
    
    /* 2. Use the tail node we constructed and find the end of the DLL */
    while (node != NULL)
    {
        tail = node;
        node = node->next;
    }
    
    /* 3. Handle the case when there is only one node in the list and we try to pop it */
    if (tail->prev == NULL) //when there's one node in the list, the POP function simply returns a copy of the data found in that node
    {
        node_data = tail->data;
        
    } else {
        
        /* 4. travel to the end of the linked list and store data in the tail into node_data */
        node_data = tail->data;//store the data that was in the tail in node_data so it can be returned later
        
        /* 5. Set new tail to the previous node */
        tail = tail->prev;
        
        /* 6. Set the next node after the tail to NULL */
        tail->next = NULL;
        
    }
    
    /* 7. Return the data that was stored in the original tail so it can be used for calculation */
    return node_data;
}

//PUSH takes in a reference to the head of a dll and some new int as the data for the new node
void push(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    struct Node *last = *head_ref;  /* used in step 5*/
    
    /* 2. put in the data  */
    new_node->data  = new_data;
    
    /* 3. This new node is going to be the last node, so
     make next of it as NULL*/
    new_node->next = NULL;
    
    /* 4. If the Linked List is empty, then make the new
     node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
    
    /* 6. Change the next of last node */
    last->next = new_node;
    
    /* 7. Make last node as previous of new node */
    new_node->prev = last;
    
    return;
}

// This function prints contents of linked list starting from the given node
void printList(struct Node *node)
{
    struct Node *last = nullptr;
    
    //We need to get to the end of the dll so we can print backwards (Bottom of the stack should be on the bottom, it's more visually appealing in my opinion).
    while (node != NULL)      //
    {                         //
        last = node;          // <----- This piece of code was very helpful whenever I needed to access the tail
        node = node->next;    //
    }                         //
    
    cout << "\nCurrent Stack: " << endl;
    while (last != NULL)
    {
        cout << " " << last->data << endl;
        last = last->prev;
    }
}








/*
 .
 .
 .
 .
 .                           The follofing methods are not used in this problem, but are
 .                           important when considering the full functionality of a dll.
 .
 .
 .
 .
 .
 .
 */


// ************ other parts of the dll class that will not be used for stack functionality ************ //

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(struct Node* prev_node, int new_data) ///<----- Note: Logic for this function was largely adapted from:https://www.geeksforgeeks.org/doubly-linked-list/
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL" << endl;
        return;
    }
    
    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    
    /* 3. put in the data  */
    new_node->data  = new_data;
    
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
    
    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;
    
    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;
    
    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
 and an int, inserts a new node on the front of the list. */
void AddToFront(struct Node** head_ref, int new_data) ///<----- Note: Logic for this function was largely adapted from:https://www.geeksforgeeks.org/doubly-linked-list/
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    /* 2. put in the data  */
    new_node->data  = new_data;
    
    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    
    /* 4. change prev of head node to new node */
    if((*head_ref) !=  NULL)
        (*head_ref)->prev = new_node ;
    
    /* 5. move the head to point to the new node */
    (*head_ref)    = new_node;
}



#endif /* dll_h */


// SOURCES //
// https://www.geeksforgeeks.org/doubly-linked-list/
// https://www.thecodingdelight.com/doubly-linked-list/#ftoc-heading-15


