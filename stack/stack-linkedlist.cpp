#include<iostream>  
using namespace std ;
struct node {
    int value ; 
    node * next ; 
} ; 
struct stack{
    node * top ; 
}; 
node* newNode(int val){
    node * p = new node ; 
    p->next = nullptr ; 
    p->value = val ;
    return p ;      
}
void pushTop(stack &st, int val){
    node *p = newNode(val) ; 
    p->next = st.top ; 
    st.top = p ; 
}
node* popTop(stack &st){
    if (st.top){
        node *p = st.top ; 
        st.top = p->next ; 
        return p ; 
    } 
    else 
        return nullptr ; 
}
bool isEmpty(stack st){
    if (!st.top)
        return true ; 
    else
        return false ;  
}
int main(){
    int n, x;
    stack st ; 
    st.top = nullptr ;   
    cin >> n ; 
    for (int i = 0 ; i < n ; i++){
        //cout <<isEmpty(st) <<endl; 
        cin >> x ; 
        pushTop(st, x) ; 
    }
    cout <<"Inside the stack : \n" ; 
    while (!isEmpty(st)){
        cout << popTop(st)->value <<endl ; 
    }

    return 0 ; 
}