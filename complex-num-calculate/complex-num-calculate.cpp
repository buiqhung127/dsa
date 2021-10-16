#include<iostream>
#include<cmath>
#define real r 
#define imaginary i 
using namespace std ;
struct complex{
    float real ; 
    float imaginary ; 
} ; 
void printComplex(complex c) {
    if (c.i == 0)
        cout << c.r ; 
    else if (c.r == 0)
        cout << c.i <<'i';  
    else 
        cout << c.r << ((c.i > 0) ? " + " : " ") << c.i <<'i' ;  
} 
complex _addition(complex c1, complex c2){
    return  {c1.r + c2.r, c1.i + c2.i} ; 
}
complex _subtract(complex c1, complex c2){
    return  {c1.r - c2.r, c1.i - c2.i} ; 
}
complex _multiply(complex c1, complex c2){
    return {c1.r * c2.r - c1.i * c2.i, c1.r * c2.i + c2.r * c1.i} ; 
}
float distance(complex c){
    return c.i * c.i + c.r * c.r ; 
}
complex _divide(complex c1, complex c2){
    return {(c2.r * c1.r + c2.i * c1.i) / distance(c2), (c2.r * c1.i - c2.i * c1.r) / distance(c2)} ;  
}
float moduleOfComplex(complex c){
    return sqrt(c.i * c.i + c.r * c.r) ; 
}
void performCalculation(complex c1, complex c2){
    char op[4] = {'+', '-', '*', '/'} ; 
    complex (*func[4])(complex c1, complex c2) = {_addition, _subtract, _multiply, _divide} ; 
    for (int i = 0 ; i < 4 ; i++){
        cout << "("  ; 
        printComplex(c1)  ;
        cout << ") " << op[i] <<" ("  ;
        printComplex(c2) ;  
        cout << ") = " ; 
        if (i == 3 && c2.i == 0 && c2.r == 0)
            cout <<"Invalid !" ; 
        else 
            printComplex((*func[i])(c1, c2)) ; 
        cout << endl ; 
    }

}
int main(){
    complex c1, c2 ; 
    cout <<"Input the real part of the first complex number: "; 
    cin >> c1.r ; 
    cout <<"Input the imaginary part of the first complex number: "; 
    cin >> c1.i ; 

    cout <<"Input the real part of the second complex number: "; 
    cin >> c2.r ; 
    cout <<"Input the imaginary part of the second complex number: "; 
    cin >> c2.i ; 

    cout <<"The module of first complex number : " << moduleOfComplex(c1) <<endl;     
    cout <<"The module of second complex number : " << moduleOfComplex(c2) <<endl;

    performCalculation(c1, c2) ; 

    return 0 ; 
}