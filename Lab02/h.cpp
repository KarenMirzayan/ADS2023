#include <iostream>


using namespace std;

  
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    Node* curr = head;
    Node* temp;
    for(int i = 0; i < p; i++){
            if(i == p - 1){
                temp = curr;
            }
            curr = curr->next;
    }
    if(head){
        if(p == 0){
            node->next = head;
            return node;
        }else{
            temp->next = node;
            node->next = curr;
        }
    }else{
        head = node;
    }
    return head;
}
 
Node* remove(Node* head, int p){
    Node* curr = head;
    Node* start;
    for(int i = 0; i < p; i++){
        if(i == p - 1){
            start = curr;
        }
        curr = curr->next;
    }
    if(p == 0){
        return head->next;
    }else{
        if(curr){
            start->next = curr->next;
        }else{
            start->next = nullptr;
        }
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    Node* curr = head;
    int count = 0;
    while(curr && count != p1){
        curr = curr->next;
        count++;
    }
    Node* newEl = new Node(curr->val);
    head = remove(head, p1);
    head = insert(head, newEl, p2);
    return head;
}
 
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while(curr){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
 
void print(Node* head){
    Node* curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
}
 
Node* cyclic_left(Node* head, int x){
    if(x == 0){
        return head;
    }
    Node* newStart = head;
    Node* sliceEnd;
    for(int i = 0; i < x; i++){
        sliceEnd = newStart;
        newStart = newStart->next;
    }
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    tail->next = head;
    sliceEnd->next = nullptr;
    return newStart;
}
 
Node* cyclic_right(Node* head, int x){
    if(x == 0){
        return head;
    }
    int size = 0;
    Node* curr = head;
    while(curr){
        size++;
        curr = curr->next;
    }
    Node* newStart = head;
    Node* sliceEnd;
    for(int i = 0; i < size - (x); i++){
        sliceEnd = newStart;
        newStart = newStart->next;
    }
    
    Node* tail = newStart;
    while(tail->next){
        tail = tail->next;
    }
    tail->next = head;
    sliceEnd->next = nullptr;
    return newStart;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}