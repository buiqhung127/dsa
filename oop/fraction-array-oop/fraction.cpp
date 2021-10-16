#include"fraction.h"
float fraction::getNumerator() const{
    return this->n ; 
}
float fraction::getDenorminator() const{
    return this->d ; 
}
void fraction::setNumerator(float newValue){
    this->n = newValue ; 
}
void fraction::setDenorminator(float newValue){
    this->d = newValue ;
}
fraction fraction::inverse(){
    fraction tmp(false) ; 
    tmp.n = this->d ; 
    tmp.d = this->n ; 
    return tmp; 
}
int fraction::gcd(int a, int b){
    if (b == 0) return a ; 
    return fraction::gcd(b , a%b) ; 
}
void fraction::reduce(){
    while (int(this->n) != this->n)
        this->n *= 10 ; 
    while (int(this->d) != this->d)
        this->d *= 10 ; 
    bool neg = false ; 
    if (this->n * this->d < 0)
        neg = true ;
    if (this->n < 0)
        this->n = -this->n ; 
    if (this->d < 0)
        this->d = -this->d ; 
    int g = (this->n > this->d) ? fraction::gcd(int(this->n), int(this->d)) : fraction::gcd(int(this->d), int(this->n)) ; 
    
    this->n /= g ; 
    this->d /= g ; 
    
    if (neg) this->n = -this->n ; 
}
fraction fraction::operator + (fraction f){
    fraction result(false);
    result.n = this->n * f.d + this->d * f.n ; 
    result.d = this->d * f.d ; 
    result.reduce() ; 
    return result; 
}
fraction fraction::operator - (fraction f){
    fraction result(false); 
    result.n = this->n * f.d - this->d * f.n ; 
    result.d = this->d * f.d ; 
    result.reduce() ; 
    return result; 
}
fraction fraction::operator * (fraction f){
    fraction result(false); 
    result.n = this->n * f.n ; 
    result.d = this->d * f.d ; 
    result.reduce() ; 
    return result; 
}
fraction fraction::operator / (fraction f){
    return (*this) * f.inverse(); 
}
void fraction::performCalculation(fraction f1, fraction f2){
    cout << "("  <<f1  << ") + (" << f2 << ") = " << f1 + f2 <<endl; 
    cout << "("  <<f1  << ") - (" << f2 << ") = " << f1 - f2 <<endl;
    cout << "("  <<f1  << ") * (" << f2 << ") = " << f1 * f2 <<endl;
    cout << "("  <<f1  << ") / (" << f2 << ") = " << f1 / f2 <<endl;
}
