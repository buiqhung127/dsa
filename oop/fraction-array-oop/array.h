#ifndef _ARRAY_H_
#define _ARRAY_H_
#include<iostream>
using namespace std ; 
class Array{
    private :
        int * values ; 
        int size ; 
    public : 
        Array() {
            inputAnArray() ; 
        }
        ~Array(){
            delete[] values ; 
            values = nullptr ; 
        }
        void inputAnArray(); 
        void outputAnArray(); 
        int getArraySize() ; 
        int getItemByIndex(int index) ; 
        void findItem(int value) ; 
        void QuickSort(int left, int right); 
        void sort() ; 

        friend istream& operator >> (istream& is, Array &arr) ; 
        friend ostream& operator << (ostream& is, Array &arr) ; 
};
#endif