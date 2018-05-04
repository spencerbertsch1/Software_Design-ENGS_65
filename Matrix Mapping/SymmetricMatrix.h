//
//  SymmetricMatrix.h
//  ENGS_65_Project3_new
//
//  Created by Spencer Bertsch on 2/12/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//

#ifndef SymmetricMatrix_h
#define SymmetricMatrix_h


class SymmetricMatrix{
private:
    
    int *ptr;
    int size;
    
public:
    // Array(int *, int);
    // constructor for array class
    SymmetricMatrix(int *p = NULL, int s = 0) // Constructor is passed a sequence (A) and the size of that sequence
    {
        size = s;
        ptr = NULL;
        if (s != 0)
        {
            ptr = new int[s]; //must be an int
            for (int i = 0; i < s; i++)
                ptr[i] = p[i];
        }
    }
    
    ~SymmetricMatrix() = default; //Destructor - How do we destroy pointers to pieces of memory?
    
    int map1 (int i, int j){ //function that takes in i and j values and returns correct index of the linear matrix
        
        int index;
        int n = 6;
        if (i < j) {
            index = ( (n*(n-1)/2) - (n-i)*((n-i)-1)/2 + j - i - 1  ); //this mapping function is used then (i<j)
        } else if (j < i) {
            index = ( (n*(n-1)/2) - (n-j)*((n-j)-1)/2 + i - j - 1  ); //this mapping function is used then (j<i)
        } else {
            index = 0; // this index will never get used, so we can just set it to zero
        }
        return index;
    }
};


#endif /* SymmetricMatrix_h */
