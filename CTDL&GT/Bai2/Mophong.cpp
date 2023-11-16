#include <bits/stdc++.h>
#include "Stack_for_Array.cpp"
#include "Stack_for_Node.cpp"

using namespace std;

void ProcessQueries1(int T , ArrayStack<int> &stack){
    for(int i=0 ; i < T ; i++){
        int query , num ;
        cin >> query;
        if(query == 1){
            cin >> num ;
            if(num >= -1e9 && num <= 1e9){
                stack.push(num);
            }
        }else if(query == 2){
            if(!stack.empty()){
                stack.pop();
            }
        }else if(query == 3){
            if(stack.empty()){
                cout << "Empty!" << endl;
            }else {
                cout << stack.top() << endl;
            }
        }
    }
}

void ProcessQueries2(int T , LinkedStack<int> &stack){
    for(int i=0 ; i < T ; i++){
        int query , num ;
        cin >> query;
        if(query == 1){
            cin >> num ;
            if(num >= -1e9 && num <= 1e9){
                stack.push(num);
            }
        }else if(query == 2){
            if(!stack.empty()){
                stack.pop();
            }
        }else if(query == 3){
            if(stack.empty()){
                cout << "Empty!" << endl;
            }else {
                cout << stack.top() << endl;
            }
        }
    }
}

int main (){
    int n ;
    do{
        cout << "Import Stack for Array or Linked: " ;
        cin >> n;
    }while(n != 1 && n != 2);
    int T ; 
    cin >> T;
    ArrayStack<int> stack_array;
    LinkedStack<int> stack_node;
    if(n == 1){
        ProcessQueries1(T , stack_array);
    }
    if(n == 2){
        ProcessQueries2(T , stack_node);
    }
    return 0;
}