#include"array.h"
void Array::inputAnArray(){
    do {
        cout << "Input the size of the array (greater than 0) then input each element respectively : " ; 
        cin >> (*this) ; 
        if (this->size <= 0){
            cout <<"Size invalid !\n" ; 
        }
    } while (this->size <= 0) ; 
}
void Array::outputAnArray(){
    cout << "The array : \n" ; 
    cout <<(*this) ; 
}
int Array::getArraySize(){
    return this->size ; 
}
int Array::getItemByIndex(int index){
    return this->values[index] ; 
}
void Array::findItem(int value){
    bool isExist = false ; 
    int *tmp = new int[this->size] ;
    int cnt = 0 ;  
    for (int i = 0 ; i < this->size ; i++)
        if (this->values[i] == value){
            isExist = true ; 
            tmp[cnt++] = i ; 
        }
    if (!isExist)
        cout <<"This value does not exist in this array !" ; 
    else {
        cout <<"The position(s) : " ; 
        for (int i = 0 ; i < cnt ; i++)
            cout << tmp[i] <<" " ; 
    }
    cout <<endl ; 
    delete[] tmp ; 
}
void Array::sort(){
    QuickSort(0, this->size - 1) ; 
}
void Array::QuickSort(int left, int right){
    int mid = values[(left + right) / 2] ;
    int i = left ; 
    int j = right ;
    while (i <= j){
        while (values[i] < mid) i++ ; 
        while (values[j] > mid) j-- ; 
        if (i <= j){
            int tmp = values[i] ; 
            values[i] = values[j] ; 
            values[j] = tmp; 
            i++ ; 
            j-- ; 
        }
    } 
    if (left < j) Array::QuickSort(left, j) ; 
    if (i < right) Array::QuickSort(i, right) ; 
}