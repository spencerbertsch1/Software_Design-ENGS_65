//
//  main.cpp
//  Project6New_V2
//
//  Created by Spencer Bertsch on 3/6/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//

#include <iostream>
#include <string>
#include "BSTree.h"
#include <cstdlib>
using namespace std;

int main()
{
    
    BSTree<string> QuestionTree; //define QuestionsTree
    
    /* 1. Level One: First Question  */
    string Q1 = "K  QUESTION 1: Is it alive?"; //root node
    
    /* 2. Level Two: Second Question  */
    string Q2 = "F  QUESTION 2: Is is larger than a loaf of bread?"; //#2 node - left child of root
    string Q3 = "S  QUESTION 2: Does it walk on two legs?"; //#3 node - right child of root
    
    /* 3. Level Three: Third Question  */
    string Q4 = "C  QUESTION 3: Do you use it to write code?"; //#4 node - left child of node #2
    string Q5 = "I  QUESTION 3: Do you use it to drive?"; //#5 node - right child of node #2
    
    //  Answers on Level Three
    string A1 = "Q  ANSWER: You're thinking of a Tree Frog!"; //#6 node - left child of node #3
    string A2 = "V ANSWER: You're thinking of a Penguin!"; //#7 node - right child of node #3
    
    /* 4. Level Four: Answers  */
    string A3 = "A  ANSWER: You're thinking of a Samsung Galaxy S9!"; //#8 node - left child of node #4
    string A4 = "D  ANSWER: You're thinking of a Computer!"; //#9 node - right child of node #4
    string A5 = "G  ANSWER: You're thinking of a Television!"; //#10 node - left child of node #5
    string A6 = "J  ANSWER: You're thinking of a Car!"; //#11 node - right child of node #5
    
    //How do I order these properly to make it a complete binary tree??
    QuestionTree.insert(Q1); //Is it alive?
    QuestionTree.insert(Q2); //Larger than a loaf of bread?
    QuestionTree.insert(Q3); //Does it walk on two legs?
    QuestionTree.insert(Q4); //
    QuestionTree.insert(Q5); //
    QuestionTree.insert(A1); //Tree Frog
    QuestionTree.insert(A2); //Penguin
    QuestionTree.insert(A3); //
    QuestionTree.insert(A4); //
    QuestionTree.insert(A5); //
    QuestionTree.insert(A6); //
    
    
    cout << "   20 Questions   " << endl;
    cout << "------------------" << endl;
    cout << "Please think of a single object and answer the following questions!" << endl;
    cout << "Enter responses as 'y' or 'n'" << endl;
    
    QuestionTree.choose();
    
    
    
    
    
    
    
    //Uncomment to see anwser to Question 2 from Project 6
    /*
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
     }*/
    
}

// SOURCES
// https://www.youtube.com/watch?v=COZK7NATh4k <-- this guy rocks. very helpful
//
//
//
//
//

