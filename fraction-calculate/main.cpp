#include<iostream>
#define numerator n 
#define denorminator d 
using namespace std ;
struct fraction{
    float numerator ; 
    float denorminator ; 
} ; 
fraction inverse(fraction f){
    return {f.d, f.n}; 
}
int gcd(int a, int b){
    if (b == 0) return a ; 
    return gcd(b , a%b) ; 
}
fraction reduce(fraction f){
    while (int(f.n) != f.n){
        f.n *= 10 ; 
    }
    while (int(f.d) != f.d){
        f.d *= 10 ; 
    } 
    bool neg = false ; 
    if (f.n * f.d < 0)
        neg = true ;
    if (f.n < 0)
        f.n = -f.n ; 
    if (f.d < 0)
        f.d = -f.d ; 
    int g = (f.n > f.d) ? gcd(int(f.n), int(f.d)) : gcd(int(f.d), int(f.n)) ; 
    
    f.n /= g ; 
    f.d /= g ; 
    
    if (neg) f.n = -f.n ; 
    return f ; 
}
void printFraction(fraction f) {
    if (f.n == 0)
        cout << 0 ; 
    else if (f.d == 1)
        cout << f.n ;  
    else if (f.d == 0)
        cout << "Invalid !" ; 
    else 
        cout << int(f.n) << '/' << int(f.d) ; 
} 
fraction _addition(fraction f1, fraction f2){
    fraction ft = {f1.n * f2.d + f1.d * f2.n, f1.d * f2.d} ; 
    return reduce(ft) ; 
}
fraction _subtract(fraction f1, fraction f2){
    fraction ft = {f1.n * f2.d - f1.d * f2.n, f1.d * f2.d} ; 
    return reduce(ft) ; 
}
fraction _multiply(fraction f1, fraction f2){
    fraction ft = {f1.n * f2.n, f1.d * f2.d} ; 
    return reduce(ft) ; 
}
fraction _divide(fraction f1, fraction f2){
    return _multiply(f1, inverse(f2)) ; 
}
void performCalculation(fraction f1, fraction f2){
    char op[4] = {'+', '-', '*', '/'} ; 
    fraction (*func[4])(fraction f1, fraction f2) = {_addition, _subtract, _multiply, _divide} ; 
    for (int i = 0 ; i < 4 ; i++){
        cout << "("  ; 
        printFraction(f1)  ;
        cout << ") " << op[i] <<" ("  ;
        printFraction(f2) ;  
        cout << ") = " ; 
        printFraction((*func[i])(f1, f2)) ; 
        cout << endl ; 
    }

}
int main(){
    fraction f1, f2 ; 
    cout <<"Input the numerator of the first fraction: "; 
    cin >> f1.n ; 
    do {
         cout <<"Input the denorminator of the first fraction: "; 
        cin >> f1.d ; 
    } while (f1.d == 0) ; 

    cout <<"Input the numerator of the second fraction: " ; 
    cin >> f2.n ; 
    do {
         cout <<"Input the denorminator of the first fraction: " ; 
        cin >> f2.d ; 
    } while (f2.d == 0) ; 

    f1 = reduce(f1) ; 
    f2 = reduce(f2) ; 
    cout <<"\nThe first fraction after reducing : " ;     
    printFraction(f1) ;
    cout <<"\nThe second fraction after reducing : " ; 
    printFraction(f2) ; 

    cout <<"\nThe first fraction after inversing : " ;     
    printFraction(inverse(f1)) ;
    cout <<"\nThe second fraction after inversing : " ; 
    printFraction(inverse(f2)) ; 
    cout <<endl ;  
    performCalculation(f1, f2) ; 

    return 0 ; 
}