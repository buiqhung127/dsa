#include<iostream>
#include<string>
#define CURRENT_YEAR 2021
using namespace std ;
struct DoB{
    int dd ; 
    int mm ; 
    int yyyy ; 
};
struct StudentRecord{
    string name ; 
    DoB birth; 
}; 
void radixSort(StudentRecord *list, int n){
    // since we cannot access properies easily by string like python, we must consider each 
    // properties separately from least important to most important
    StudentRecord *temp = new StudentRecord[n] ; 
    int * counting = new int[CURRENT_YEAR] ; // choose year for more memory cell

    for (int i = 0 ; i < CURRENT_YEAR ; i++)
        counting[i] = 0 ; 
    for (int i = 0 ; i < n; i++)
        counting[list[i].birth.dd]++ ;   
    for (int i = 1 ; i < CURRENT_YEAR ; i++)
        counting[i] = counting[i-1] + counting[i] ; 
    for (int i = n-1 ; i >= 0 ; i--)
        temp[--counting[list[i].birth.dd]] = list[i] ;   
    for (int i = 0 ; i < n ; i++)
        list[i] = temp[i] ; 


    for (int i = 0 ; i < CURRENT_YEAR ; i++)
        counting[i] = 0 ; 
    for (int i = 0 ; i < n; i++)
        counting[list[i].birth.mm]++ ; 
    for (int i = 1 ; i < CURRENT_YEAR ; i++)
        counting[i] = counting[i-1] + counting[i] ; 
    for (int i = n-1 ; i >= 0 ; i--)
        temp[--counting[list[i].birth.mm]] = list[i] ;   
    for (int i = 0 ; i < n ; i++)
        list[i] = temp[i] ; 

    for (int i = 0 ; i < CURRENT_YEAR ; i++)
        counting[i] = 0 ; 
    for (int i = 0 ; i < n; i++)
        counting[list[i].birth.yyyy]++ ; 
    for (int i = 1 ; i < CURRENT_YEAR ; i++)
        counting[i] = counting[i-1] + counting[i] ; 
    for (int i = n-1 ; i >= 0 ; i--)
        temp[--counting[list[i].birth.yyyy]] = list[i] ;   
    for (int i = 0 ; i < n ; i++)
        list[i] = temp[i] ; 


    delete[] counting; 
    delete[] temp ; 
}
int main(){
    int n ; 
    StudentRecord * list = new StudentRecord[n] ; 
    cin >> n ;
    for (int i = 0 ; i < n ; i++){
        cin.ignore() ; 
        getline(cin, list[i].name) ;
        cin >> list[i].birth.dd ; 
        cin >>  list[i].birth.mm ; 
        cin >> list[i].birth.yyyy ;
    } 
    radixSort(list,n) ; 
    for (int i = 0 ; i < n ; i++)
    cout << list[i].name <<" " <<list[i].birth.dd <<" " <<list[i].birth.mm <<" " <<list[i].birth.yyyy <<endl ; 

    delete[] list  ; 
    return 0 ; 
}