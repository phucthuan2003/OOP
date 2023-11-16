#include <bits/stdc++.h>

using namespace std;

class NumberSeries{
    private:
        int n;
        int *elem;
    public:
        NumberSeries(){
            n = 0;
            elem = nullptr;
        }
        NumberSeries(int n , int *elem){
            this->n = n;
            elem = new int[n];
        }
        NumberSeries(const NumberSeries &x){
            n = x.n;
            elem = new int[n];
            for(int i=0 ; i<n ; i++){
                elem[i] = x.elem[i];
            }
        }
        NumberSeries &operator = (const NumberSeries &x){
            if(this != &x){
                n = x.n;
                elem = new int[n];
                for(int i=0 ; i<n ; i++){
                    elem[i] = x.elem[i];
                }
            }
            return *this;
        }
        friend istream& operator >> (istream &cin , NumberSeries &a){
            cout << "Import List: " ; cin >> a.n;
            a.elem = new int[a.n];
            for(int i=0 ; i<a.n ; i++){
                cin >> a.elem[i];
            }
            return cin;
        }
        friend ostream& operator << (ostream &cout , NumberSeries a){
            for(int i=0 ; i<a.n ; i++){
                cout << a.elem[i] << "   ";
            }
            return cout;
        }
        long long Res(){
            long long s = 0;
            for(int i=0 ; i<n ; i++){
                s+= elem[i];
            }
            return s;
        }
        double Average(){
            return 1.0*Res()/n;
        }
};

int main(){
    NumberSeries a;
    cin >> a;
    cout << a;
    long long res = a.Res();
    cout << "\nRes of Number Series: " << res << endl;
    double average = a.Average();
    cout << "\nAverage of Number Series: " << average << endl;
}