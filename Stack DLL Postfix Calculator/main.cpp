//
//  main.cpp
//  ENGS_65_Project_5
//
//  Created by Spencer Bertsch on 2/24/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//


#include <iostream>
#include<string>
#include "dll.h"
#include "Evaluate.h"
#include "Stack.h"
using namespace std;

int main() {

    string input;
    cout << "Please enter an expression for postfix calculation: " << endl;
    //cout << "If you can't think of one, '5 3 +' without the quotes will work just fine. " << endl;
    getline(cin, input); // 'getline (string)' extracts all characters so they can be used as input
    int result = EvaluatePostfix(input);
    cout << "Result of the calculation = " << result << "\n";
    
    // Uncomment 'TestNewStack' to see the functionality of the stack class that uses the dll to build the stack
    //TestNewStack();
    
    // Uncomment 'TestStack' to see the functionality of the dll as a stack.
    //TestStack(); // This is a function that tests all of the functions of the dll - stack and confirms that it works the way that we want
    
    return 0;
}

// *****SOURCES USED***** //
//https://www.youtube.com/watch?v=UU5UhVQhYkY
//https://gist.github.com/mycodeschool/7702441
//https://www.geeksforgeeks.org/doubly-linked-list/
//https://www.thecodingdelight.com/doubly-linked-list/#ftoc-heading-15
//http://www.cplusplus.com/forum/beginner/46864/
//https://en.wikipedia.org/wiki/Doubly_linked_list
//https://stackoverflow.com/questions/19326017/deleting-the-back-element-in-a-linked-list
//http://faculty.cs.niu.edu/~mcmahon/CS241/Notes/doubly_linked.html
//https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_algorithm.htm

