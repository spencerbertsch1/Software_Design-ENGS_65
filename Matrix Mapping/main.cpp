//
//  main.cpp
//  MatrixAssignment1
//
//  Created by Spencer Bertsch on 1/28/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//  Working copy - without enums OR symmetric matrix class
//

#include <iostream>
#include <array>
#include "MappingFunction.h"
#include "SymmetricMatrix.h"
using namespace std;
enum City {Atlanta = 0, Boston = 1, Chicago = 2, Detroit = 3, New_York = 4, Los_Angeles = 5}; //starting index is 0


int main() // DRIVER PROGRAM
{
    /*  CONSTRUCT MILAGE MATRIX  */
    //Row Major Form - Upper Triangular
    int MileageMatrix1[15] = {1108, 708, 756, 2191, 854, 994, 1753, 3017, 222, 279, 2048, 809, 2288, 649, 2794};
    string CityMatrix [6] = {"Atlanta" ,  "Boston" , "Chicago" , "Detroit" , "Los_Angeles" , "New_York"};
    
    //Create Matrix Object
    int m1[]{1108, 708, 994, 756, 1753, 279, 2191, 3017, 2048, 2288, 854, 222, 809, 649, 2794}; //Create a symmetric matrix object

    SymmetricMatrix newArray(m1, 15);
    
    /*   USE SETTERS AND GETTERS TO CHANGE AND RETRIEVE INFORMATION IN THE PRIVATE SECTION OF THE SYMMETRIC_MATRIx CLASS   */
    
    //cout << "* SETTER TEST * Use setter to change the distance between Atlanta and Boston to 10,000 miles. " << endl;
    //Test setter
    //int aa = 10000;//Just as a test, let's set distance to 10 thousand miles - distance between atlanta and boston
    //m1.set_a(aa);
    
    //void SymmetricMatrix::set_distance(int h)
    // {
    //    health = h;
    //}
    
    //Test Getter
    //cout << "* GETTER TEST * Using the getter, first element of matrix : " << m1.get_distance_a() << endl;
    
    //setter and getter using map function
    
    //Test enums
    //cout<< "The element that corresponds to Atlanta is: " << Atlanta << endl; //prints 0
    
    int i;
    int j;
    int index = 0;
    
        cout << "Welcome to your trip advisor!" << endl;
        cout << "" << endl;
        cout << "Please enter a starting city number from the following options: " << endl;
        cout << " (0)Atlanta \n (1)Boston \n (2)Chicago \n (3)Detroit \n (4)Los_Angeles \n (5)New_York" << endl;
        cin >> i;
        cout << "Please enter a destination number from the following options: " << endl;
        cout << " (0)Atlanta \n (1)Boston \n (2)Chicago \n (3)Detroit \n (4)Los_Angeles \n (5)New_York" << endl;
        cin >> j;
        
          index = map(i,j);
        //index = m1.map1(i,j);
        
        if (i == j) {
            cout << "You entered the same city! There is no distance between those points." << endl;
        } else {
            cout << "The number of miles between " << CityMatrix[i] << " and " << CityMatrix[j] << " is: " << MileageMatrix1[index] << endl;
        }

    return 0;

}

// *** SOURCES ***
// https://stackoverflow.com/questions/27086195/linear-index-upper-triangular-matrix



