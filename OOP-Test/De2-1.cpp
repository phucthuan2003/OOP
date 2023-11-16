#include <bits/stdc++.h>

using namespace std;

class Point{
    private:
        int x , y;
    public:
        Point(){}
        Point(int x , int y){
            this->x = x;
            this->y = y;
        }  
        friend istream& operator >> (istream &cin , Point &p){
            cout << "Import x: " ; cin >> p.x;
            cout << "Import y: " ; cin >> p.y;
            return cin;
        }
        friend ostream& operator << (ostream &cout , Point p){
            cout << "(" << p.x << " ; " << p.y << ")" << endl;
            return cout;
        }
        double Distance(){
            return sqrt(x*x + y*y);
        }
};
class List{
    private:
        int n; 
        Point *pt;
    public:
        List(){}
        List(int n , Point *pt){
            this->n = n;
            pt = new Point[n];
            for(int i=0 ; i<n ; i++){
                this->pt[i] = pt[i];
            }
        }
        List(const List &x){
            n = x.n;
            pt = new Point[n];
            for(int i=0 ; i<n ; i++){
                pt[i] = x.pt[i];
            }
        }
        List &operator = (const List &x){
            if(this != &x){
                delete [] pt;
                n = x.n;
                pt = new Point[n];
                for(int i=0 ; i<n ;i++){
                    pt[i] = x.pt[i];
                }
            }
            return *this;
        }
        friend istream& operator >> (istream &cin , List &l){
            cout << "Import List: "; cin >> l.n;
            l.pt = new Point[l.n];
            for(int i=0 ; i<l.n ; i++ ){
                cin >> l.pt[i];
            }
            return cin;
        }
        friend ostream& operator << (ostream &cout , List l){
            for(int i=0 ; i<l.n ; i++ ){
                cout << l.pt[i];
            }
            return cout;
        }
        double Res(){
            double S = 0;
            for(int i=0 ; i<n ; i++){
                S+= pt[i].Distance();
            }
            return S;
        }
        void Min(){
            double max = -1;
            for(int i=0 ; i<n ; i++){
                if(pt[i].Distance() > max)
                    max = pt[i].Distance();
            }
            double min = max;
            int k = -1;
            for(int i=0 ; i<n ; i++){
                if(pt[i].Distance() < min ){
                    min = pt[i].Distance();
                    k = i;
                }
            }
            if(k != 1){
                cout << "Point Min Distance !\n" ; cout << pt[k];
            }else cout << "Not Found Point!";
        }
};

int main(){
    List l;
    cin >> l; 
    cout << l;
    double res = l.Res();
    cout << "\nRes_All: " << res << endl;
    l.Min();
}