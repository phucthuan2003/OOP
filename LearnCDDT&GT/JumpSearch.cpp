#include <bits/stdc++.h>

using namespace std;

int JumpSearch(int a[] , int k , int n){
    int d = 3 ; // so tu nhien > 1
    int i = 0;
    int j = i + d;
    while( j < n && a[j] < k){ // nhay theo buoc d
        j = j + d ;
        i = i + d ;

    }
}

int main(){

}
