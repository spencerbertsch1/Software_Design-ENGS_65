// ******************************************************************
//  main.cpp
//  Project4_MappingFunction
//
//  Created by Spencer Bertsch on 2/6/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//  Worked with: Suchen Shi, Graeme Genreas
// ******************************************************************

// Overloading operators for Array class
#include <iostream>
#include <cstdlib>
#include <string>
#include "ArrayClassV2.h"
#include "IndexingClass.h"
#include "Dictionary.h"
using namespace std;

// Driver program
int main()
{
    cout << "------------------------------- QUESTION 1 -------------------------------" << endl;
    /*
     This section of main is where I started my thinking on this problem. I initially created an "array" object that could take in any length array and the size of that array. However, I was having trouble overloading the [] operator correctly so it would return the same index of the new array as the position of Ai in the old array. The header file ArrayClassV2 and class of Array2 creates objects that contain both the target vectors and the new arrays.
    
    int A[] = {12,8,14,-12,6};
        Array array(A, 5);
    int a[] = {1, 2, 3, 4, 5};
        Array array1(a, 5); //first argument: array, second argument: size
    
    int x;
    x = FindIndex (array, 5, -12);
    
    cout << "Array [A]:" << endl;
    array.print();
    cout << "Index of -12 in [A] is: " << x << endl;
    cout << "And array[3]: " << array1[x] << endl;
    cout << "What we want is to say array[-12] = 4" << endl;
    cout << "\n" << endl;
    
    cout << "Array [array]:" << endl;
    array1.print();

    cout << "array[1] = " << array1[1] << endl;
    cout << "array[2] = " << array1[2] << endl; 
    
    cout << "array2 ------------- ***" << endl;
    */
    
    int ARRAY[] = {12,8,14,-12,6};
    int ARRAY2[] = {1, 2, 3, 4, 5};
    Array2 newArray(ARRAY, ARRAY2, 5);
    
    newArray.PRINT();
    cout << "\n" << endl;
    cout << "Test Output:" << endl;
    cout << "NewArray[12]: " << newArray[12] << endl;
    cout << "NewArray[8]: " << newArray[8] << endl;
    cout << "NewArray[14]: " << newArray[14] << endl;
    cout << "NewArray[-12]: " << newArray[-12] << endl;
    cout << "NewArray[6]: " << newArray[6] << endl;
    
    cout << "\n" << endl;
    cout << "------------------------------- QUESTION 2 -------------------------------" << endl;
    
    //Question 2:
    //User uses index in the form of i*(-1^i) which yeilds the correct index of the array 
    
    //Instantiate an IndexArray object
    int testArray1[] = {0, 1, 2, 3, 4, 5, 6, 7};
    IndexArray arr(testArray1, 8);
    int testArray2[] = {0, 1, 2, 3, 4, 5, 6, 7};
    IndexArray arr1(testArray2, 8);
    
    cout << "Test Output:" << endl;
    //Building the "function" into the operator overlaod
    cout << "arr[1]  = " << arr[1] << endl;
    cout << "arr[-2] = " << arr[-2] << endl;
    cout << "arr[3]  = " << arr[3] << endl;
    cout << "arr[-4] = " << arr[-4] << endl;
    cout << "" << endl;
    //Using a seperate mapping function that get referenced in the operator overload
    //Different methods have the same output
    cout << "arr[1]  = " << arr1[1] << endl;
    cout << "arr[-2] = " << arr1[-2] << endl;
    cout << "arr[3]  = " << arr1[3] << endl;
    cout << "arr[-4] = " << arr1[-4] << endl;
    cout << "Works with the function inside and outside of the operator overload. " << endl;
    cout << "\n" << endl;
    cout << "------------------------------- QUESTION 3 -------------------------------" << endl;
    
    string stringA[] = {"Algorithm", "Land","Animals","Are","Often","Cute"};
    string stringB[] = {"An efficient method to solve a problem","Similar to the ocean, but harder","Like a plant, but cuter","To be or not to be","Oppasite of irregular","Adorable"};
    Dictionary dictionary(stringA, stringB, 6);
    
    cout << "Test Output:" << endl;
    //dictionary.PRINT(); //<----- functions successfully, but clutters up the output.
    cout << "dictionary['algorithm']: " << dictionary["algorithm"] << endl;
    cout << "---" << endl;
    cout << "dictionary['Land']: " << dictionary["Land"] << endl;
    
    return EXIT_SUCCESS;
}

// *** SOURCES ***
// https://www.geeksforgeeks.org/overloading-subscript-or-array-index-operator-in-c/
//
//
