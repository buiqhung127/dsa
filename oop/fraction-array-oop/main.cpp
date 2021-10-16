#include"fraction.h"
#include"array.h"
istream& operator >> (istream &is, fraction &f){
    float nor, den ;
    is >> nor  >> den ; 
    f.setNumerator(nor) ; 
    f.setDenorminator(den) ; 
    return is ; 
}
ostream& operator << (ostream &os, const fraction& f){
    float nor = f.getNumerator() ;
    float den = f.getDenorminator() ;  
    if (nor == 0)
        os << 0 ; 
    else if (den == 1)
        os << nor ;  
    else if (den == 0)
        os << "Invalid !" ; 
    else 
        os << int(nor) << '/' << int(den) ; 
    return os  ; 
}
istream& operator >> (istream& is, Array &arr){
    int size ; 
    is >> size ; 
    arr.size = size ; 
    if (size <= 0)
        return is; 
    arr.values = new int[size] ; 
    for (int i = 0 ; i < size ; i++)
        is >> arr.values[i] ; 
    return is ; 
}
ostream& operator <<(ostream &os, Array &arr){
    for (int i = 0 ; i < arr.size ; i++){
        os << arr.values[i] <<" " ; 
    }
    return os ; 
}
int main(){

    // Assigment 1
    cout <<"Input for the first fraction\n" ;  
    fraction f1(true) ; 
    cout <<"Input for the second fraction\n" ; 
    fraction f2(true) ; 
    cout <<"\nThe first fraction after reducing : " ;     
    cout << f1 ;
    cout <<"\nThe second fraction after reducing : " ; 
    cout << f2; 

    cout <<"\nThe first fraction after inversing : " ;     
    cout << f1.inverse() ;
    cout <<"\nThe second fraction after inversing : " ; 
    cout << f2.inverse() ; 
    cout <<endl ;  
    fraction::performCalculation(f1, f2) ; 

    // Assignment 5
    Array arr ; // constructor've called the input array already
    cout <<"The size of the array : " <<arr.getArraySize() <<endl; 
    arr.outputAnArray() ; 
    int x ; 
    cout <<"\nInput the value that you want to find : " ; 
    cin >> x ; 
    arr.findItem(x) ; 

    cout <<"The array after sorting :\n" ; 
    arr.sort() ; 
    arr.outputAnArray() ; 

    return 0 ; 
}