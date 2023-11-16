//Demo slist
#include <bits/stdc++.h>
#include "slist.cpp"
using namespace std;
int main ()
{
	slist<int> L(9,2);
	for(auto x:L) 
        cout<<x<<" ";  
	slist<int>::iterator it;
	cout<<"\nDuyet bo lap xuoi: "; 
    for(it=L.begin();it!=L.end();it++) 
        cout<<*it<<" ";
	int k=0; 
    for(slist<int>::iterator z=L.begin();z!=L.end();z++) 
        *z=++k;
	cout<<"\nDuyet auto: "; 
    for(auto x:L) 
        cout<<x<<" ";
	L.pop_back();//xoa duoi
	L.pop_back();//xoa duoi
	L.pop_front();//xoa dau
	L.pop_front();//xoa dau
	cout<<"\nDuyet auto: "; 
    for(auto x:L) 
        cout<<x<<" ";  
	L.push_front(12);
	L.push_back(35);
	cout<<"\nDuyet auto: "; 
    for(auto x:L) 
        cout<<x<<" ";  
    cout << endl;
    return 0;
}
