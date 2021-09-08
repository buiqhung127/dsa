// https://leetcode.com/problems/find-the-duplicate-number/
#include<iostream>
using namespace std ; 
int main(){
    int n ; 
    cin >> n ; 
    int * nums = new int[n] ; 
    for (int i = 0 ; i < n ; i++)
        cin >>nums[i] ; 
    int tortoise = nums[0]; 
    int hare = nums[0] ; 
    do {
        hare = nums[nums[hare]] ; 
        tortoise = nums[tortoise] ; 
    } while (tortoise != hare) ; 
    hare = nums[0] ; 
    while (hare != tortoise){
        hare = nums[hare] ; 
        tortoise = nums[tortoise] ; 
    }
    cout <<hare <<endl ; 
    
    delete[] nums ; 
    return 0 ; 
}