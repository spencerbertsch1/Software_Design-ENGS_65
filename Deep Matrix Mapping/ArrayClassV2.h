//
//  ArrayClassV2.h
//  Project4_TestMappingFunction_2
//
//  Each Array2 object will contain two vectors of the same length. These two vectors will be fundamentally joined within in the object.
//
//
//  Created by Spencer Bertsch on 2/10/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//

#ifndef ArrayClassV2_h
#define ArrayClassV2_h
using namespace std;

// A class to represent an integer array
class Array2
{
private:
    
    int *ptr1;
    int *ptr2;
    int length;

public:
    // Array(int *, int);
    // constructor for array class
    Array2(int *p = NULL, int *p2 = NULL, int s = 0) // Constructor is passed a sequence (A) and the size of that sequence
    {
        length = s;
        ptr1 = NULL;
        ptr2 = NULL;
        if (s != 0)
        {
            ptr1 = new int[s]; //must be an int
            ptr2 = new int[s];
            for (int i = 0; i < s; i++){
                ptr1[i] = p[i];
                ptr2[i] = p2[i];
            }
        }
    }
    
    //destructor
    // ~Array(){
    //    for(int i = 0; i< size; i++)
    //        delete ptr[i];
    // };
    ~Array2() = default; //Shouldnt have default destructor
    
    // Implementation of [] operator.  This function must return a refernce as array element can be put on left side
    // Overloading [] operator to access elements in array style
    int &operator[] (int target)
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
    
    int FindIndex (Array2 A, int size, int target){
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (target == A[i])
            {
                index = i;
            }
        }
        return index;
    }
};

#endif /* ArrayClassV2_h */
