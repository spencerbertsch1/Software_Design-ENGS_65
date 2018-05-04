//
//  main.cpp
//  Project6New
//  
//  Created by Spencer Bertsch on 3/3/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//

#include <iostream>
#include <string>
#include "BSTree.h"
#include <cstdlib>
using namespace std;

int main()
{
     //Uncomment to see anwser to Question 2 from Project 6
    
    BSTree<int> tree;
    int user_in;
    int temp_data;
    while(1)
    {
        cout<<endl<<endl;
        cout<<"    Please Enter an Option     "<<endl;
        cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<<endl;
        cout<<" 1. Insertion/Creation "<<endl;
        cout<<" 2. Search "<<endl;
        cout<<" 3. Exit "<<endl;
        cout<<" Enter your choice : ";
        cin >> user_in;
        
        switch(user_in)
        {
            case 1 : cout<<" Please enter data to be inserted : ";
                cin.ignore(1);
                cin>>temp_data;
                tree.insert(temp_data);
                break;
                
            case 2 : cout<<" Please enter data to be searched : ";
                cin.ignore(1);
                cin>>temp_data;
                tree.search(temp_data);
                break;
                
            case 3 : return 0;
                break;
        }
     }
    
}

// SOURCES
// https://www.youtube.com/watch?v=COZK7NATh4k <-- this guy rocks. very helpful
//
//
//
//
//
