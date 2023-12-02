#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string val){
		this->prev = NULL;
		this->next = NULL;
		this->val = val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    if(head == NULL){
        head = new Node(s);
        tail = head;
    }
    else{
        tail->next = new Node(s);
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void add_front(string s){
    if(head == NULL){
        head = new Node(s);
        tail = head;
    }
    else {
        head->prev = new Node(s);
        head->prev->next = head;
        head = head->prev;
    }
}
bool empty(){
    return head == NULL;
}
void erase_front(){
    if (!empty()) {
        Node* to_delete = head;
        head = head->next;
        head->prev = NULL;
        delete to_delete;
        // if(!empty())
        //     head->prev = NULL;
    }
}
void erase_back(){
    Node* to_delete = head;
    if (!empty()) {
        if (head == tail) {
            head = NULL;
            tail = NULL;
            delete to_delete;
            return;
        }
        Node* to_delete = tail;
        tail = tail->prev;
        delete to_delete;
        if(!empty())     
            tail->next = NULL;
    }
}
string front(){
    if(!empty())
        return head->val;
    return "r";
}
string back(){
    if(!empty())
        return tail->val;
    return "r";
}
void clear(){
    if (!empty()) {
        Node* cur = head;
        Node* to_delete = NULL;
        while (cur != NULL) {
            to_delete = cur;
            cur = cur->next;
            delete to_delete;
        head = NULL;
        tail = NULL;
        }
    }
}

void print() {
    Node* cur = head;
    if(empty()) 
        cout << "empty" << endl;
    else {
        cout << head->prev << " ";
        if (head->next == NULL){
            cout << head->val << " " << head->next << endl;
            return;
        }
        while(cur != NULL){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << tail->next << " " << endl;
    }
}   
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
            //print();
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
            // print();
   		}
   		if(s == "add_back"){
            // print();
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
            // print();
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
                // print();
   				cout << front() << endl;
   				erase_front();
                // print();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
                // print();
   				cout << back() << endl;
   				erase_back();
                // print();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
                // print();
   				cout << front() << endl;
                // print();
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
                // print();
   				cout << back() << endl;
                // print();
   			}
   		}
   		if(s == "clear"){
   			clear();
            // print();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}