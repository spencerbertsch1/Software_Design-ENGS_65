// ******************************************************************
//  IndexingClass.h
//  Project4_TestMappingFunction
//
//  Created by Spencer Bertsch on 2/8/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
// ******************************************************************

#include <math.h>
#ifndef IndexingClass_h
#define IndexingClass_h
using namespace std;

//if statements - make two sections to deal with cyclic pattern

// A class to represent an integer array
class IndexArray
{
private:
    
    int *ptr;
    int size;
    
public:
    // Array(int *, int);
    // constructor for array class
    IndexArray(int *p = NULL, int s = 0)
    {
        size = s;
        ptr = NULL;
        if (s != 0)
        {
            ptr = new int[s]; //must be an
            for (int i = 0; i < s; i++)
                ptr[i] = p[i];
        }
    }
    
    //destructor
    ~IndexArray() = default;
    
        //QUESTION 2
       //Create another array class where the method indexing elements is based on a function.  In this case, to access the ith element of the array, the user would use the index i*(-1)i.  So for an array arr, to access slot 1 you would use arr[-1], to access slot 2 you would use arr[2], etc.
    
    int &operator[] (int i)
    {
        if (i < 0)
        {
            i = i * (-1);
            return ptr[i];
        } else {
            return ptr[i];
        }
    }
    
    // Utility function to print contents
    void print() const
    {
        for(int i = 0; i < size; i++)
            cout << ptr[i] << " ";
        cout<<"\n"<<endl;
    }
};

#endif /* IndexingClass_h */
