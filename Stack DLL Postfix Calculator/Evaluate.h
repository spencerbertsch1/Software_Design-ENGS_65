//
//  Evaluate.h
//  ENGS_65_Project_5
//
//  Created by Spencer Bertsch on 2/24/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//

#include <iostream>
#ifndef Evaluate_h
#define Evaluate_h
#include<string>
#include "dll.h"
#include "Stack.h"
using namespace std;

// ********************** Declare Functions ********************************************
// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string input);

// Function to perform an operation and return output.
int PerformOperation(char operation, int operand1, int operand2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is numeric digit.
bool IsNumericDigit(char C);
// *************************************************************************************


int EvaluatePostfix(string input){ ///<----- Note: Logic for this function was largely adapted from: https://gist.github.com/mycodeschool/7702441
    
    //Construct an empty stack - using our dll file
    Stack stack(NULL);
    
    //for loop will run through the entire input - entered postfix expression for calculation
    for(int i = 0; i < input.length();i++) {
        
        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(input[i] == ' ' || input[i] == ',') continue;
        
        else if( IsNumericDigit(input[i]) == true){
            // Extract the numeric operand from the string
            // Keep incrementing i as long as you are getting a numeric digit.
            
            //* Handles the case when inputs are double digits *
            int operand = 0;
            while(i < input.length() && IsNumericDigit(input[i])) {
                // For a number with more than one digits, as we are scanning from left to right.
                // Everytime , we get a digit towards right, we can multiply current total in operand by 10
                // and add the new digit.
                operand = (operand*10) + (input[i] - '0');
                i++;
            }
            
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
            // decrement i because it will be incremented in increment section of loop once again.
            // We do not want to skip the non-numeric character by incrementing i twice.
            i--;
            
            // Push operand on stack.
            //&&&// push(&head, operand);
            stack.Push(operand);
        }
        
        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(input[i]) == true) {
            // Pop two operands
            int x1 = stack.Pop(); //store data from the top node in int x1
            int x2 = stack.Pop(); //store data from the second to top node in int x2
            // Perform operation
            int result = PerformOperation(input[i], x1, x2);
            //Push back result of operation on stack.
            stack.Push(result);
        }
    }
    
    //Now we want to return the only item left in the stack
    int finalNode = stack.Pop();
    
    return finalNode; //test to see if pop works for a stack with 1 thing in it, might nott.
};


// Function to verify whether a character is operator symbol or not
bool IsOperator(char test)
{
    if(test == '+' || test == '-' || test == '*' || test == '/'){
        return true;}
    else{
        return false;
    }
}


// Function to verify whether a character is numeric digit. ///<----- Note: Logic for this function was largely adapted from: https://gist.github.com/mycodeschool/7702441
bool IsNumericDigit(char C)
{
    if(C >= '0' && C <= '9'){ return true; }
    else{
        return false;
    }
}


// Function to perform an operation and return output. ///<----- Note: Logic for this function was largely adapted from: https://gist.github.com/mycodeschool/7702441
int PerformOperation(char operation, int operand1, int operand2)
{
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;
    
    else cout<<"Unexpected Error \n";
    return -1;
}


//This function can simply be used to test the functionality of the dll as a functioning stack
//Here, the only parts of the dll that are used are the "push" and "pop" functions, showing that
//it can function as a stack
int TestStack (){
    
    cout << "TEST - USING DLL AS A STACK **********************************" << endl;
    int x1 = -1;
    
    /* Start with the empty list */
    struct Node* head = NULL;
    
    // Insert 6.  So linked list becomes 6->NULL
    push(&head, 6);
    
    // Uncomment to see that yes, we now have the ability to POP a one-node stack
    //int z1 = pop(&head);
    
    // Push 7 onto the end of the list, so the linked list becomes 6->7->NULL
    push(&head, 7);
    
    // Push 1 onto the end of the list, so the linked list becomes 6->7->1->NULL
    push(&head, 12);
    
    // Pop 1 off the end of the list, so the linked list becomes 6->7->NULL
    x1 = pop(&head);
    
    // Push 4 onto the end of the list, so the linked list becomes 6->7->4->NULL
    push(&head, 4);
    
    // Push 14 onto the end of the list, so the linked list becomes 6->7->4->14->NULL
    push(&head, 14);
    
    // Print the new, updated dll
    printList(head);
    
    cout << "New Value stored in x1: " << x1 << endl; //we can see that we grabbed the data from the tail before we deleted it!
    
    return 0;
};

//This function simply acts as a test for the stack funciton in this program 
void TestNewStack(){
 Stack stack1(NULL);
 
 stack1.Push(1);
 stack1.Push(3);
 stack1.Push(5);
 stack1.Push(18);
 
 int x = stack1.Pop();
 int y = stack1.Pop();
 int z = stack1.Pop();
 
 cout << x << endl;
 cout << y << endl;
 cout << z << endl;

};

#endif /* Evaluate_h */

