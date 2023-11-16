#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *makeNode(int x){
    Node *newNode = new Node;
    newNode ->data = x;
    newNode ->next = NULL;
    newNode ->prev = NULL;
    return newNode;
}

void duyet(Node *head){
    while (head != NULL){
        cout << head ->data << " ";
        head = head ->next;
    }
    cout << endl;
}
int sz(Node *head){
    int count = 0;
    while(head != NULL){
        ++count;
        head = head->next;
    }
    return count;
}
void themdau1(Node **head , int x){
    Node *newNode = makeNode(x);
    newNode->next = (*head); // Cho Phan next cua node moiw tro vao node dau tien
    if(*head != NULL){
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}
void themdau2(Node *&head , int x){
    Node *newNode = makeNode(x);
    newNode ->next = head;
    if(head != NULL){
        head ->prev = newNode;
    }
    head = newNode;
}
void themcuoi1(Node **head , int x){
    Node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return ;
    }
    Node *temp = *head;
    while (temp->next != NULL){
        temp = temp ->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void themcuoi2(Node *&head , int x){
    Node *newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
        return ;
    }
    Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void themgiua1(Node **head , int x , int k){
    int n = sz(*head);
    if(k < 1 || k > n + 1){
        return ;
    }
    if(k == 1){
        themdau1(head, x);
    }
    Node *temp = *head;
    for(int i = 1 ; i <= k - 1 ; i++){
        temp = temp->next;
    }
    Node *newNode = makeNode(x);
    newNode ->next = temp;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode; 
}
void themgiua2(Node *&head , int x , int k){
    int n = sz(head);
    if(k < 1 || k > n + 1){
        return ;
    }
    if(k == 1 ){
        themdau2(head , x);
    }
    Node *temp = head;
    for(int i = 1 ; i <= k + 1 ; i++){
        temp = temp ->next;
    }
    Node *newNode = makeNode(x);
    newNode->next = temp;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode;
}
int main(){
	Node *head = NULL;
	while(1){
		cout << "---------------DSLK---------------\n";
		cout << "1. Them node vao dau\n";
		cout << "2. Them node vao cuoi\n";
		cout << "3. Them node vao giua\n";
		cout << "4. Duyet\n";
		cout << "5. Thoat !\n";
		cout << "----------------------------------\n";
		cout << "Nhap lua chon :"; int lc; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap x : ";
			cin >> x;
			themdau1(&head, x); // themdau2(head, x);
		}
		else if(lc == 2){
			int x; cout << "Nhap x : ";
			cin >> x;
			themcuoi1(&head, x); // themcuoi2(head, x);
		}
		else if(lc == 3){
			int x; cout << "Nhap x : ";
			cin >> x;
			int k; cout << "Nhap vi tri chen :";
			cin >> k;
			themgiua1(&head, x, k); // themgiua2(head, x, k);
		}
		else if(lc == 4){
			duyet(head);
		}
		else{
			break;
		}
 
	}
	return 0;
}
