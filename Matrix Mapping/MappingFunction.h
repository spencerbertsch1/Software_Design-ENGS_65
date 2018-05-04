//
//  MappingFunction.h
//  ENGS_65_Project3_new
//
//  Created by Spencer Bertsch on 2/7/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//

#ifndef MappingFunction_h
#define MappingFunction_h

int map (int i, int j){ //function that takes in i and j values and returns correct index of the linear matrix
    
    int index;
    int n = 6; // is there any way to make this dynamic? Or should we hard code it?
    if (i < j) {
        index = ( (n*(n-1)/2) - (n-i)*((n-i)-1)/2 + j - i - 1  ); //this mapping function is used then (i<j)
    } else if (j < i) {
        index = ( (n*(n-1)/2) - (n-j)*((n-j)-1)/2 + i - j - 1  ); //this mapping function is used then (j<i)
    } else {
        index = 0; // this index will never get used, so we can just set it to zero
    }
    return index;
}

#endif /* MappingFunction_h */
