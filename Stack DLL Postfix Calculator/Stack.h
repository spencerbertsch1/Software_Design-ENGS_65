//
//  Stack.h
//  ENGS_65_Project_5
//
//  Created by Spencer Bertsch on 2/24/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//

#include "dll.h"
#include "Evaluate.h"
#ifndef Stack_h
#define Stack_h
using namespace std;

//Construct an empty stack - using our dll file
//struct Node* head = NULL;

class Stack {
private:

public:
    struct Node* head = NULL;
    
    //Construct an empty stack - using our dll file
    Stack(Node* head1) { Node* head = head1; }
    
    //struct Node* head = NULL;
    
    // Default Destructor
    ~Stack() { }; 

    // *** PUSH - create a function that uses the PUSH function from our dll class *** //
    // *** so we can simply say stack.push(5); and 5 will be added to the top of the stack //
    
    // *** PUSH ***
    //push(&head, operand);
    void Push(int data) {
               push(&head, data);
    }
    
    // *** POP - create a function that uses the POP function from our dll class *** //
    // *** so we can simply say stack.pop() and it will pop the top of the stack and return //
    // *** any data that was stored in the top node *** //
    
    // *** POP ***
    //push(&head, operand);
    int Pop() {
         int x1 = pop(&head);
        return x1;
    }
};

#endif /* Stack_h */
    
    
    
    
    
    
    
    
    
    
