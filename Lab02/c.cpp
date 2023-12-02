#include <iostream>
using namespace std;

struct node {
    string data;
    node* nxt;
    node() {
        this->data = "";
        this->nxt = NULL;
    }
    node(string data) {
        this->data = data;
        this->nxt = NULL;
    }
    node(string data, node* nxt) {
        this->data = data;
        this->nxt = nxt;
    }

    // void push_back(string x) {
    //     if (nxt == NULL) {
    //         nxt = new node(x);
    //     }
    //     else
    //         nxt->push_back(x);
    // }

    void print() {
        cout << data;
        if (nxt != NULL) {
            cout << " ";
            nxt->print();
        }
    }
};

struct  linked_list {
    node* head = NULL;
    node* tail = NULL;
    bool is_empty() {
        return head == NULL;
    }

    // void push_back(string x) {
    //     if (is_empty())
    //         head = new node(x);
    //     else
    //         head->push_back(x);
    // }

    void push_back(string x){
        if (is_empty()){
            head = new node(x);
            tail = head;
        }
        else {
                tail->nxt = new node(x);
                tail = tail->nxt;
            }
    }

    void push_front(string x) {
        if (is_empty())
            head = new node(x);
        else {
            node *v = new node(x, head);
            head = v;
        }
    }

    void pop_back() {
        if (is_empty())
        {
            cerr << "LinkedList ERROR: list is empty!";
            exit(0);
        }
        if (head->nxt == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        node *cur = head;
        while(cur->nxt->nxt != NULL){
            cur = cur->nxt;
        }
        node *to_delete = cur->nxt;
        cur->nxt = NULL;
        delete to_delete;
    }

    void pop_front() {
        if (is_empty())
        {
            cerr << "LinkedList ERROR: list is empty!";
            exit(0);
        }
        node* new_head = head->nxt;
        delete head;
        head = new_head;
        head->print();
    }

    void print() {
        if (is_empty())
            cout << " ";
        else {
            head->print();
        }
        cout << endl;
    }

    int find(string x) {
        node* cur = head;
        int i = 0;
        while(cur != NULL) {
            if(cur->data == x) return i;
            cur = cur->nxt;
            i++;
        }
        return -1;
    }

    int length(){
        node* cur = head;
        int i = 0;
        while(true){
            if (cur == NULL) return i;
            cur = cur->nxt;
            i++;
        }
    }

    void delete_pos(int k) {
        if (k < 0){
            cerr << "LinkedList ERROR: position can't be negative!";
            exit(0);
        }
        if(k == 0) {
                node* cur = head;
                head = head->nxt;
                delete cur;
                return;
            }
        if (k < this->length()) {
            int i = 0;
            node* cur = head;
            node* prev = NULL;
            while(i != k) {
                prev = cur;
                cur = cur->nxt;
                i++;
            }
            prev->nxt = cur->nxt;
            delete cur;
        }
    }

    void insert(string x, int k) {
        int i = 0;
        node* cur;
        if (k == 0){
            cur = new node(x);
            cur->nxt = head;
            head = cur;
            return;
        }
        cur = head;
        node* prev = NULL;
        if (k < this->length()) {
            while(i != k){
                prev = cur;
                cur = cur->nxt;
                i++;
            }
            node* to_insert = new node(x);
            prev->nxt = to_insert;
            to_insert->nxt = cur;
            return;
        }
        else if (k == length()){
            this->push_back(x);
            return;
        }
        cerr << "LinkedList ERROR: position is too big.";
        exit(0);
    }

    void cyclic_shift(int k) {
        int i = 0;
        if (k == 0 || length() <= 1) {
            return;
        }
        node* cur = tail;
        while(i != k){
            cur->nxt = head;
            head = head->nxt;
            cur->nxt->nxt = NULL;
            cur = cur->nxt;
            // this->print();
            i++;
        }
    }

    void delete_second() {
        node* cur = head;
        node* prev = NULL;
        int r = length();
        int i = 0;
        while(i != r) {
            if(i % 2 == 1) {
                cur = cur->nxt;
                delete prev->nxt;
                prev->nxt = cur;
            }
            else{
                if (i != r - 1) {
                    prev = cur;
                    cur = cur->nxt;
                }
                else
                    return;
            }
            i++;
        }
    }
};

int main() {
    int n;
    linked_list l;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        l.push_back(s);
    }
    l.delete_second();
    l.print();
}