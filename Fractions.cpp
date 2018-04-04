//------------------------------------------------------------
//  main.cpp
//  ENGS 65 PROJECT 2 ABSTRACT DATA TYPES - FRACTIONS
//
//  Created by Spencer Bertsch on 1/25/18.
//  Copyright © 2018 Spencer Bertsch. All rights reserved.
//------------------------------------------------------------

#include<iostream> // include necessary package
using namespace std; //for printing

class fraction { //create fractions class
private: //private section of class
        int num; //declare numerator
        int denom; //declare denominator
public: //declare public section of class
    fraction(int x1, int y1) { //construct fraction
        num = x1; //construct numerator
        denom = y1; // construct denominator
    }// close curly
    ~fraction() = default; //Destructor

    void reduce(){ //declare function to reduce a fraction
        int new_num = 0, new_denum = 0; //create two new variables that will be changed in the for loop
        for (int i = 1; i < denom * num; i++) { //initiale for loop - might run a lot of time depending on the fraction
            if ((denom % i == 0) && (num % i == 0)) { //if both are divisible by the same number, divide by that number
                new_denum = (denom / i); //divide temp denomenator by i
                new_num = (num / i); //divide temp numerator by i
            }// close curly
        }// close curly
        num = new_num; // assign num to reduced num
        denom = new_denum; // assign denom to rediced denom
    }// close curly
    
    //Operator overload (+) //<--- ideas for this operater overload were adapted from www.daniweb.com
    fraction operator + (fraction &fraction2) { //declare operator overload for (+) addition
        int n1 = num; //create new int equal to numerator
        int d1 = denom; //create new int equal to denominator
        int n2 = fraction2.num; //create new int from memory location of second numerator
        int d2 = fraction2.denom; //create new int from memory location of second denominator
        int TempDenominator = d1 * d2; // create new int as the product of the denominators
        fraction f( (d2 * n1) + (d1 * n2) ,TempDenominator); // use fraction math to add fractions
        f.reduce(); // reduce the new fraction
        return f; //return the new fraction
    }// close curly
    
    //Operator overload (-)
    fraction operator - (fraction &fraction2) { //declare operator overload for (+) addition
        int n1 = num; //create new int equal to numerator
        int d1 = denom; //create new int equal to denominator
        int n2 = fraction2.num; //create new int from memory location of second numerator
        int d2 = fraction2.denom; //create new int from memory location of second denominator
        int TempDenominator = d1 * d2; // create new int as the product of the denominators
        fraction f( (d2 * n1) - (d1 * n2) ,TempDenominator ); // use fraction math to subtract fractions
        //f.reduce(); ///<--- NOTE if we use the "reduce" function on a negative fraction, it returns (0/0)
        return f; //return the new fraction
    }// close curly
    
    //Operator overload (*)
    fraction operator * (fraction &fraction2) { //declare operator overload for (+) addition
        int n1 = num; //create new int equal to numerator
        int d1 = denom; //create new int equal to denominator
        int n2 = fraction2.num; //create new int from memory location of second numerator
        int d2 = fraction2.denom; //create new int from memory location of second denominator
        int TempDenominator = d1 * d2; // create new int as the product of the denominators
        fraction f( ((d2 * n1) * (d1 * n2)) ,(TempDenominator * TempDenominator) ); // use fraction math to multiply fractions
        f.reduce(); // reduce the new fraction
        return f; //return the new fraction
    }// close curly
    
    //Operator overload (/)
    fraction operator / (fraction &fraction2) { //declare operator overload for (+) addition
        int n1 = num; //create new int equal to numerator
        int d1 = denom; //create new int equal to denominator
        int d2 = fraction2.num; //create new int from memory location of second numerator
        int n2 = fraction2.denom; //create new int from memory location of second denominator
        int TempDenominator = d1 * d2; // create new int as the product of the denominators
        fraction f( ((d2 * n1) * (d1 * n2)) ,(TempDenominator * TempDenominator) ); // use fraction math to divide fractions
        f.reduce(); // reduce the new fraction
        return f; //return the new fraction
    }// close curly
    
    int getNumerator() {  return num; } // declare the Get Numerator function
    int getDenominator() {  return denom; } // declare the Get Denominator function
    
    void IsEqual (fraction F1, fraction F2){ //create is equal function
        F1.reduce(); //reduce first fraction
        F2.reduce(); // reduce second fraction
        if (F1.getNumerator() == F2.getNumerator() && F1.getDenominator() == F2.getDenominator()) { // compare fractions for equality
            cout << "Yes, fractions are equal. " << endl; // print that the fractions are equal
        } else { // else statement
            cout << "No, fractions are not equal. " << endl; // print out that the fractions arent equal
        } // close curly
    } // close curly
    
    void IsLarger (fraction F1, fraction F2){ // declare is larger function
        fraction a1 = F1; //copy first fraction for later printing
        fraction a2 = F2; //copy first fraction for later printing
        F1.reduce(); // reduce first fraction
        F2.reduce(); // reduce second fraction
        int size1 = F1.getNumerator() * F2.getDenominator(); // find the comparative size of the first fraction
        int size2 = F2.getNumerator() * F1.getDenominator(); // find the comparative size of the second fraction
        if (F1.getNumerator() == F2.getNumerator() && F1.getDenominator() == F2.getDenominator()) { // test whether the two fractions are equal
            cout << "The fractions you entered are equal. " << endl; // if the fractions are equal, say they're equal
        } else if (size1 < size2) { // compare the relative size of the two fractions
            cout << "Looks like (" << a1.getNumerator() << "/" << a1.getDenominator() << ") is smaller than (" << a2.getNumerator() << "/" << a2.getDenominator() << ")";// if first fraction is larger, say it's larger
        } else { // else statement
            cout << "Looks like (" << a2.getNumerator() << "/" << a2.getDenominator() << ") is smaller than (" << a1.getNumerator() << "/" << a1.getDenominator() << ")"; //if first fraction is smaller, say it's smaller
        } //close curley
    } //close curley
    
}; // end of fractions class

int main() { // open main
    cout << "********** FRACTIONS OUTPUT **********" << endl; //start output
   
    // ********** DECLARE FRACTIONS ********** //
    fraction f1(1, 3);        //instantiate new fraction object
    fraction f2(4, 5);        //instantiate new fraction object
    fraction f3 = f1 + f2;    //instantiate new fraction object using the (+) operator
    fraction f4(100, 450);    //instantiate new fraction object
    fraction f5(10, 11);      //instantiate new fraction object
    fraction f6(13,10);       //instantiate new fraction object
    fraction f7(4,7);         //instantiate new fraction object
    fraction f8 = f6 - f7;    //instantiate new fraction object using the (-) operator
    fraction f9(50,33);       //instantiate new fraction object
    fraction f10(100,101);    //instantiate new fraction object
    fraction f11(4,6);        //instantiate new fraction object
    fraction f12(5,8);        //instantiate new fraction object
    fraction f13 = (f11 * f12); //instantiate new fraction object using the (*) operator
    fraction f14(1,3);        //instantiate new fraction object
    fraction f15(4,5);        //instantiate new fraction object
    fraction f16 = (f14 / f15); //instantiate new fraction object
    fraction f17(3,10);       //instantiate new fraction object
    fraction f18 = (f11 * f12); //instantiate new fraction object using the (*) operator
    fraction f19 = f17 - f18; //instantiate new fraction object using the (-) operator
    fraction f20(1,2);        //instantiate new fraction object
    fraction f21(2,4);        //instantiate new fraction object
    fraction f22(4,100);      //instantiate new fraction object
    fraction f23(39,342);     //instantiate new fraction object
    
    // ********** ADDITION OUTPUT ********** //
    cout << f1.getNumerator() << "/" << f1.getDenominator() << " + " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << f3.getNumerator() << "/" << f3.getDenominator() << endl; // print addition output
    cout << "" << endl; // Blank line
    
    // ********** SUBRTACTION OUTPUT ********** //
    cout << f6.getNumerator() << "/" << f6.getDenominator() << " - " << f7.getNumerator() << "/" << f7.getDenominator() << " = " << f8.getNumerator() << "/" << f8.getDenominator() << endl; // print subtraction output
    cout << "" << endl; // Blank line
    
    // ********** MULTIPLICATION OUTPUT ********** //
    cout << f11.getNumerator() << "/" << f11.getDenominator() << " * " << f12.getNumerator() << "/" << f12.getDenominator() << " = " << f13.getNumerator() << "/" << f13.getDenominator() << endl; // print multiplication output
    cout << "" << endl; // Blank line

    // ********** DIVISION OUTPUT ********** //
    cout << f14.getNumerator() << "/" << f14.getDenominator() << " / " << f15.getNumerator() << "/" << f15.getDenominator() << " = " << f16.getNumerator() << "/" << f16.getDenominator() << endl; // print division output
    cout << "" << endl; // Blank line
    
    // ********** MULTIPLE OPERATOR OUTPUT ********** //
    cout << f17.getNumerator() << "/" << f17.getDenominator() << " - " << f11.getNumerator() << "/" << f11.getDenominator() << " * " << f12.getNumerator() << "/" << f12.getDenominator()<< " = " << f19.getNumerator() << "/" << f19.getDenominator() << " <--- Unreduced form" << endl; // print multiple operation output
    cout << "" << endl; // Blank line
    
    // ********** RETURN DENOMENATOR OUTPUT ********** //
    cout << "Denomenator of (" << f10.getNumerator() << "/" << f10.getDenominator() << ") is: " << f10.getDenominator() << endl; // print denominator of input fraction

    // ********** RETURN NUMERATOR OUTPUT ********** //
    cout << "Numerator of (" << f9.getNumerator() << "/" << f9.getDenominator() << ") is: " << f9.getNumerator() << endl; // print numerator of input fraction
        cout << "" << endl; // Blank line
    
    
    // ********** REDUCE OUTPUT ********** //
    cout << "f4 UnReduced = " << f4.getNumerator() << "/" << f4.getDenominator() << "\n";//output initial fraction
    f4.reduce(); // reduce f4
    cout << "f4 Reduced = " << f4.getNumerator() << "/" << f4.getDenominator() << "\n"; //output rediced fraction
    cout << "f5 UnReduced = " << f5.getNumerator() << "/" << f5.getDenominator() << "\n"; //output initial fraction
    f5.reduce(); //reduce f5
    cout << "f5 Reduced = " << f5.getNumerator() << "/" << f5.getDenominator() << "\n"; //output rediced fraction
    cout << "" << endl; // Blank line
    
    // ********** TEST FOR EQUALITY OUTPUT ********** //
     cout << "Are (" << f20.getNumerator() << "/" << f20.getDenominator() << ") and (" << f21.getNumerator() << "/" << f21.getDenominator() << ") equal?" << endl;
    f20.IsEqual(f20, f21); // output for equality test
    cout << "" << endl; // Blank line
    
    // ********** TEST FOR COMPARITIVE FRACTION SIZE OUTPUT ********** //
    cout << "Which is larger? (" << f22.getNumerator() << "/" << f22.getDenominator() << ") or (" << f23.getNumerator() << "/" << f23.getDenominator() << ")?" << endl;
    f22.IsLarger(f22, f23); // output for comparitive size
    cout << "" << endl; // Blank line
    cout << "" << endl; // Blank line
    
    return 0;
}

// *** SOURCES ***
// https://www.daniweb.com/programming/software-development/threads/121962/c-fraction-calculator-output-problem
// http://www.cplusplus.com/forum/beginner/126405/
// https://www.geeksforgeeks.org/copy-constructor-in-cpp/
// https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/
