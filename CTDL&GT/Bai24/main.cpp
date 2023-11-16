#include <bits/stdc++.h>
#include "Doubly_Linked_List.cpp"

using namespace std;

void transform(int &x){
    x = (x * x - 7 * x + 3) % 100;
}

int main(){
    Doubly_Linked_List<int> myList;
    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Import Elements: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        myList.push_back(x);
    }
    // Xóa đi những phần tử trùng nhau
    myList.sortAscending();
    myList.traverseForward();
    myList.removeDuplicates();
    myList.traverseForward();

    myList.applyFunction(transform);
    myList.traverseForward();
    myList.removeDuplicates();
    myList.traverseForward();
    //Sắp xếp
    myList.sortAscending();
    myList.traverseForward();
    // Nhap x
    int k;
    cout << "Import Elments add: " ;
    cin >> k;
    myList.insertAndMaintainSorted(k);
    cout << "List End!\n";
    myList.traverseForward();
    cout << "List Reverse End!\n";
    //xuất theo chiều ngược 
    myList.traverseBackward();

    return 0;
}

