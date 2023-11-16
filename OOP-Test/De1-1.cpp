#include <bits/stdc++.h>

using namespace std;

class Vecto{
    private:
        int n;
        int *elements;
    public:
        Vecto(){
            n = 0;
            elements = nullptr;
        }
        Vecto(int n){
            this->n = n;
            elements = new int[n];
            for(int i=0 ; i<n ; i++){
                elements[i] = 0;
            }
        }
        friend istream& operator >> (istream &cin , Vecto &elements){
            cin >> elements.n;
            elements.elements = new int[elements.n];
            for(int i=0 ; i<elements.n ; i++){
                cout << "Nhap so phan tu thu[" << i+1 << "] cua vecto: " ;
                cin >> elements.elements[i];
            }
            return cin;
        }
        void display(){
            cout << "(";
            for(int i = 0; i < n - 1; i++){
                cout << elements[i] << ";";
            }
            cout << elements[n - 1] << ")";
        }
        Vecto operator + (Vecto another) {
            int c = max(this->n, another.n);
            Vecto res(c);
            for(int i=0 ; i<min(this->n , another.n) ; i++ )
                res.elements[i] = this->elements[i] + another.elements[i];
            for(int i = min(this->n , another.n) ; i<c ; i++)
                res.elements[i] = another.elements[i];
            return res;
        }
        Vecto(const Vecto &x){
            n = x.n;
            elements = new int[n];
            for(int i=0 ; i<n ; i++ ){
                elements[i] = x.elements[i];
            }
        }
        Vecto &operator = (const Vecto &x){
            if(this != &x){
                delete []elements;
                n = x.n;
                elements = new int[n];
                for(int i=0 ; i<n ; i++){
                    elements[i] = x.elements[i];
                }
            }
            return *this;
        }
        double operator * (Vecto another){
            int n = min(this->n , another.n);
            Vecto ans(n);
            double sum = 0;
            for(int i=0 ; i<n ; i++){
                sum+= this->elements[i] * another.elements[i];
            }
            return sum;
        }
        friend Vecto operator * ( Vecto a , int b){
            Vecto result(a.n);
            for(int i=0 ; i<a.n ; i++){
                result.elements[i] = a.elements[i] * b;
            }
            return result;
        }
        ~Vecto() {
            delete[] elements;
        }
};

int main(){
    // int size;
    // cout << "Nhap so luong vector: ";
    // cin >> size;
    // Vecto *elements;
    // elements = new Vecto[size];
    // for(int i=0 ; i<size ; i++){
    //     cout << "Nhap so chieu cua vector thu[" << i+1 << "]: ";
    //     cin >> elements[i];
    // }
    // cout << "Vecto sau khi nhap!" << endl;
    // for(int i=0 ; i<size ; i++){
    //     cout << "V[" << i+1 << "]: "  ; elements[i].display();
    //     cout << endl;
    // }
    // Vecto b ;
    // for(int i=0 ;i<size ; i++ ){
    //     b = b + elements[i];
    // }
    // cout << "Vecto Res: " ;
    // b.display(); 
    // cout << "\nTich Vo Huong: " << elements[0] * elements[1] << endl;
    // int k;
    // cout << "\nNhap so nguyen k: " ;  cin >> k;
    // Vecto result ;
    // result = elements[0]*k;
    // result.display();
    // delete []elements;
    // Vecto u ;
    // Vecto v;
    // int m , n ;
    // cout << "Nhap Size Vecto U: " ; cin >> u;
    // cout << "\nNhap Size Vecto V: " ; cin >> v;
    // cout << "U[1]: "   ; u.display();
    // cout << endl;
    // cout << "V[1]: "   ; v.display();
    // cout << endl;
    // cout << "Nhap so nguyen m , n : " ; cin >> m >>n;
    // cout << "\nTich vo huong : " << (u*m) * (v*n);
    // cout << endl;
    return 0;

}