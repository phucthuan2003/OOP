#include <bits/stdc++.h>
#include "Stack_for_Array.cpp"
#include "Stack_for_Node.cpp"

using namespace std;

void findMatchingParentheses(const string& parenthese){
    ArrayStack<int> indices;
    vector< pair<int , int > > matchingPairs;
    for(int i=0 ; i < parenthese.size() ; i++){
        if(parenthese[i] == '(' ) {
            indices.push(i + 1 );
        }else if(parenthese[i] == ')'){
            if(!indices.empty()){
                int openIndex = indices.top();
                indices.pop();
                int closeIndex = i + 1;
                matchingPairs.push_back(pair<int , int>(openIndex , closeIndex));
            }
        }
    }
    for(const auto& pair : matchingPairs ){
        cout << pair.first << "   " << pair.second << endl;
    }
}
int main (){
    string input;
    cin >> input;
    findMatchingParentheses(input);
    return 0;
}