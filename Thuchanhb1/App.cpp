
#include "Hinhtron.cpp"
class App{
    private:    
        int n;
        Hinhtron *h;
    public:
        App(){
            n = 0;
            h = nullptr;
        }
        ~App(){
            if(h) delete(h);
        }
        void nhap();
        void sapxep();
        void in();
        void thongke();
        void Sredmax();
        void search();
};
void App::nhap(){
    do{
        cout << "Nhap so hinh tron >0 : " ;
        cin >> n;
    }while(n<=0);
    h = new Hinhtron[n+1];
    for(int i=0 ; i<n ; i++ ){
        cout << "Nhap h[" << i+1 << "]" << endl;
        h[i].nhap();
    }
}
void App::sapxep(){
    for(int i=0 ; i < n-1 ; i++ ){
        for(int j=i+1 ; j < n ; j++ ){
            if(dientich(h[i]) < dientich(h[j])){
                Hinhtron t = h[i];
                h[i] = h[j];
                h[j] = t;
            }
        }
    }
}
void App::in(){
    for(int i=0 ; i < n ; i++ ){
        cout << h[i] << endl ;
    }
}
void App::thongke(){
    int d=0 ; 
    for(int i=0 ; i<n ; i++ ){
        if(h[i].getX() < 0 && h[i].getY() > 0 && h[i].getR() < min((float)fabs(h[i].getX()) , h[i].getY())){
            d++;
            cout << h[i] << "  ";
        }
    }
    cout << "\nCo " << d << " Hinh tron nam trong goc phan tu 2"; 
}
void App::Sredmax(){
    Hinhtron hMax;
    int check = 0;
    for(int i=0 ; i < n ; i++ ){
        if(h[i].getMau() == 1 && dientich(h[i]) > dientich(hMax)){
            hMax = h[i];
            check = 1;
        }
    }
    if(check == 0){
        cout << "\nKhong co diem do! " << endl;
    } else cout << "\nĐiểm Đỏ có S max: " << hMax << endl ;
}
void App::search(){
    int dem1 = 0;
    int dem2 = 0;
    for(int i = 0 ; i<n ; i++ ){
        if(h[i].getMau() == 2 ){
            dem1++;
        }
        if(h[i].getMau() == 3){
            dem2++;
        }
    }
    if(dem1 > dem2 ){
        cout << "So hinh mau xanh nhieu hon mau vang" << endl;
    }else cout << "So hinh mau xanh khong nhieu hon mau vang" << endl;
}
