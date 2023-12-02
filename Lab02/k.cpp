#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node {
    string val;
    Node* next;
    Node* prev;
    Node(string s) {
        val = s;
        next = NULL;
        prev = NULL;
    }
};

struct Vector {
    Node* head = NULL;
    Node* tail = NULL;

    void push(string s) {
        if(head == NULL){
            head = new Node(s);
            tail = head;
        }
        else{
            tail->next = new Node(s);
            tail = tail->next;
        }
    }
};

void repeat(map<string, int> m, Node* head, int n){
    Node* cur = head;
    while(cur != NULL) {
        if (m[cur->val] == 1) {
            cout << cur->val << " ";
            return;
        }
        cur = cur->next;
    }
    cout << "-1 ";
}

int main() {
    int n;
    cin >> n;
    int a;
    map<string, int> m;
    for (int j = 0; j < n; j++){
        cin >> a;
        Vector v;
        string b;
        for(int i = 0; i < a; i++){
            cin >> b;
            v.push(b);
            m[v.tail->val]++;
            repeat(m, v.head, a);
        }
        cout << endl;
        m.clear();
    }
}   