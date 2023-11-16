#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node *node;

//Cap phat dong 1 node moi voi du lieu la so nguyen x
node makeNode(int x){
    node tmp = new Node();
    tmp ->data = x;
    tmp ->next = NULL;
    return tmp;
}

//Kiem tra rong

bool empty(node a){
    return a == NULL;
}
//

int Size(node a){
    int cnt = 0;
    while(a != NULL){
        ++cnt;
        a = a ->next; // gan dia chi cua not tiep theo cho node hien tai
        //cho not hien tai nhay sang not tiep theo
    }
    return cnt;
}
// them 1 phan tu vao dau danh sach lien ket

void insertFirst(node &a , int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    } else {
        tmp ->next = a;
        a = tmp;
    }
}

// Them 1 phan tu vao cuoi danh sach

void insertLast(node &a , int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    } else {
        node p = a;
        while( p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}

// Them 1 phan tu nao giua

void insertMiddle(node &a , int x , int pos){
    int n = Size(a);
    if(pos <=0 || pos > n + 1){
        cout << "Vi Tri chen khong hop le !\n";
    }
    if(n == 1){
        insertFirst(a , x) ;
        return ;
    } else if(n == pos + 1){
        insertLast(a , x );
        return ;
    }
    node p = a;
    for(int i=1 ; i < pos - 1 ; i++){
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp ->next = p->next;
    p->next = tmp;
}

// xoa phan tu o dau

void deleteFisrt(node &a ){
    if(a == NULL) return ;
    a = a->next;
}

// xoa phan tu ow cuoi

void deleteLast(node &a){
    if(a == NULL) return ;
    node truoc = NULL ;
    node sau = a;
    while (sau->next != NULL){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        a = NULL;
    } else {
        truoc ->next = NULL;
    }
}

// xoa phan tu o giua

void deleteMidddle(node &a , int pos){
    if(pos <=0 || pos > Size(a)) return ;
    node truoc = NULL;
    node sau = a;
    for(int i=1 ; i < pos ; i++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL) {
        a = a->next;
    } else {
        truoc->next = sau->next;
    }
}

void in(node a){
    cout << "-------------------------------------\n";
    cout << "Danh Sach Cac Phan Tu: \n";
    while (a != NULL){
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n";
}

void sapxep(node &a){
    for(node p = a ; p->next != NULL ; p = p->next ){
        node min = p;
        for(node q = p->next ; q != NULL ; q = q->next){
            if(q->data < min->data){
                min = q;

            }
        }
        int tmp = min->data;
        min ->data = p->data;
        p->data = tmp;
    }
}


int main(){
    node head = NULL;
    while(1){
        cout << "-----------------MENU--------------------\n";
        cout << "1. Chen phan tu vao dau danh sach\n";
        cout << "2. Chen phan tu vao cuoi danh sach\n";
        cout << "3. Chen phan tu vao giua danh sach\n";
        cout << "4. Xoa phan tu o dau\n";
        cout << "5. Xoa phan tu o cuoi\n";
        cout << "6. Xoa phan tu o giua\n";
        cout << "7. Duyet danh sach lien ket\n";
        cout << "8. Sap xep cac phan tu DSLK\n";
        cout << "9. Ket Thuc\n";
        cout << "-------------------------------------\n";
        cout << "Nhap lua chon :";
        int lc ;
        cin >> lc;
        if(lc == 1){
            int x;
            cout << "Nhap gia tri can chen : ";
            cin >> x;
            insertFirst(head, x);
        }
        else if(lc == 2){
            int x;
            cout << "Nhap gia tri can chen : ";
            cin >> x;
            insertLast(head, x);
        }
        else if(lc == 3){
            int x;
            cout << "Nhap gia tri can chen : ";
            cin >> x;
            int pos ;
            cout << "Nhap vi tri can chen : ";
            cin >> pos;
            insertMiddle(head, x, pos);
        }
        else if(lc == 4){
            deleteFisrt(head);
        }
        else if(lc == 5){
            deleteLast(head);
        }
        else if(lc == 6 ){
            int pos ;
            cout << "Nhap vi tri can xoa : ";
            cin >> pos;
            deleteMidddle(head, pos);
        }
        else if(lc == 7){
            in(head);
        }
        else if(lc == 8 ){
            sapxep(head);
        }
        else if(lc == 9){
            break;
        }
        
    }
    return 0;
}
