//
//  BSTree.h
//  Project6New
//
//  Created by Spencer Bertsch on 3/3/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//

#include <iostream>
#include <string>
#ifndef BSTree_h
#define BSTree_h
using namespace std;

template<class value>
class BSTree
{
private:
    struct BST_node
    {
        value data; //note that value can be any data type becasue it is a template class
        BST_node* left;
        BST_node* right;
    };
    
    BST_node* root; //create a pointer to the root of the binary search tree
public:
    BSTree()
    {
        root = NULL; //initialize the root pointer to NULL, making the tre empty
    }
    
    void insert(value); //declare a fucntion to insert a specified value into the tree
    bool search(value); //declare a function to search for the presence of some input in the tree
    void choose();
};


template <class value>
void BSTree<value>::insert(value V)
{
    BST_node* n = new BST_node; //create a pointer to a new node
    BST_node* parent; //create a pointer to a "parent" node
    n->data = V; //enter the inputed 'data' into the middle of the node 'n'
    n->left = NULL; //'n' will be a leaf, so it will have no left child
    n->right = NULL; //'n' will be a leaf, so it will have no right child
    parent = NULL; //initialize the parent to NULL

    //now we have what we need to add a new node to our tree!
    //but first, we need to test of the tree is currently empty
    //if the tree is indeed empty, the added node will become the root
    
    if ( root == NULL ){ //if the tree is empty, we just set the new node to the root
        root = n;
    } else {
        //Note: ALL insertions are as leaf nodes
        BST_node* temp; //create temporary pointer
        temp = root; //point temp to the root of the tree
        //we need to find the correct parent of the new node
        while(temp)
        {
            parent = temp; //remember that temp = root, so we can start from the root and travel down the tree!
            if(n->data > temp->data){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        //Now we have chosen the appropriate place in the tree to insert our new node!
        //We have found the correct parent, the last step is determining if the new node will
        //be a left child or a right child
        
        if(n->data < parent->data)
            parent->left = n;
        else
            parent->right = n;
    
    }//and with that, we have a new node in the tree!
    
}//end insert function


template <class value>
bool BSTree<value>::search(value V)
{
    bool found = false;//declare a new bool - true if the searched value is in the tree, false if not
     //first we need to test to see if the tree is empty. If yes, we know that found = false
    if(root == NULL)
    {
        cout << "EMPTY TREE - There are no values to search." << endl;
        return false;
    }
    //if there are some values in the tree, then we need to travel down the tree and find the searched key
    
    BST_node* temp; //create a temporary pointer
    BST_node* parent; //create a pointer to parent
    temp = root; //we start searching from the root and travel down to find the key 'v'
    parent = (BST_node*)NULL; // parent = (BST_node*)NULL; <-- Question: whats the difference?
    
    while(temp != NULL)
    {
        if(temp->data == V)
        {
            found = true;
            break; //if the key is found, the while loop breaks and found='true' is returned
        }
        else
        {
            
            parent = temp;
            if(V>temp->data){ //travel down the tree looking for the key value
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
    }
    //now we have searched through the entire tree down to the leaf that is closest or equal to the
    //searched value. Now we simply need to check whether or not we have found the searched value!
    
    if(!found)
    {
        cout<<" Data not found! "<<endl;
    }
    else
    {
        cout<<" Data found! "<<endl;
    }
    
    return found;
}//end search function


template <class value>
void BSTree<value>::choose(){

    BST_node* temp; //create temporary pointer
    temp = root; //point temp to the root of the tree
    
    //20 questions game
    while(temp){
        
        cout << temp->data << "\n" <<endl;
        string user_input = "";
        cin >> user_input;

        //Evaluate the question depending on the answer provided by the user
        if (user_input == "y") {
            temp = temp->right;
        } else {
            temp = temp->left;
        }

    }//end while loop

}

#endif /* BSTree_h */
