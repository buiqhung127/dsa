#ifndef _FRACTION_H_
#define _FRACTION_H_

#include<iostream>
#define numerator n 
#define denorminator d 
using namespace std ;
class fraction{
    private : 
        float numerator;
        float denorminator; 
    public : 
        fraction(bool invoke = false){
            if (invoke == false){
                this->numerator = 0 ;
                this->denorminator = 1 ;  
            } else {
                do {
                    cout << "Input the numerator and denorminator, respectively: " ; 
                    cin >> (*this); 
                    if (getDenorminator() == 0)
                        cout <<"Invalid !\n" ; 
                } while (getDenorminator() == 0) ; 
                reduce() ;
            } 
        }
        float getNumerator() const;
        float getDenorminator() const;
        void setNumerator(float newValue);
        void setDenorminator(float newValue) ;   

        void reduce(); 
        void printFraction() ; 
        fraction inverse() ; 
        fraction operator + (fraction f);
        fraction operator - (fraction f);
        fraction operator * (fraction f);
        fraction operator / (fraction f);

        friend istream& operator >> (istream &is, fraction &f);
        friend ostream& operator << (ostream &os, const fraction& f);

        static int gcd(int a, int b); 
        static void performCalculation(fraction f1, fraction f2) ; 
};



#endif