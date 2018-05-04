// ******************************************************************
//  Dictionary.h
//  Project4_TestMappingFunction
//
//  Created by Spencer Bertsch on 2/8/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
// ******************************************************************

#ifndef Dictionary_h
#define Dictionary_h
#include <string>
#include <map>
using namespace std;

// A class to represent an integer array
class Dictionary
{
private:
    
    string *ptr1;
    string *ptr2;
    int length;

public:
    // Array(int *, int);
    // constructor for array class
    Dictionary(string *p = NULL, string *p1 = NULL, int s = 0) // Constructor is passed a sequence (A) and the size of that sequence
    {
        length = s;
        ptr1 = NULL;
        ptr2 = NULL;
        if (s != 0)
        {
            ptr1 = new string[s];
            ptr2 = new string[s];
            for (int i = 0; i < s; i++){
                ptr1[i] = p[i];
                ptr2[i] = p1[i];
            }
        }
    }
    
    //destructor
    // ~Array(){
    //    for(int i = 0; i< size; i++)
    //        delete ptr[i];
    // };
    ~Dictionary() = default;
    
    // Implementation of [] operator.  This function must return a refernce as array element can be put on left side
    // Overloading [] operator to access elements in array style
    string &operator[] (string target)
    {
        int index = 0;
        for (int i = 0; i < length; i++)
        {
            if (target == ptr1[i])
            {
                index = i;
            }
        }
        return ptr2[index];
    
    }
    
    // Utility function to print contents
    void PRINT() const
    {
        cout << "Target Array = " << endl;
        for(int i = 0; i < length; i++){
            cout << ptr1[i] << " ";
        }
        cout << "" << endl;
        cout << "New Array = " << endl;
        for(int i = 0; i < length; i++){
            cout << ptr2[i] << " ";
        }
        cout << "" << endl;
    }
}; //end class

#endif /* Dictionary_h */
