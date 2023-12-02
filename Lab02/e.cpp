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

    void push(string x) {
        if (nxt == NULL) {
            nxt = new node(x);
        }
        else
            nxt->push(x);
    }

    void print() {
        cout << "[" << data << "]";
        if (nxt != NULL) {
            cout << "->";
            nxt->print();
        }
    }
};

struct Stack {
    node* top = NULL;
    node* bot = NULL;
    bool is_empty() {
        return top == NULL;
    }

    void push(string x) {
        if (is_empty()) {
            top = new node(x);
            bot = top;
        }
        else {
            node* new_top = new node(x, top);
            top = new_top;
        }
    }

    void pop() {
        if(is_empty()){
            cerr << "Stack ERROR: can not pop NULL!";
            exit(0);
        }
        else {
            node* to_delete = top;
            top = top->nxt;
            delete to_delete;
        }
    }

    int length() {
        node* cur = top;
        int i = 0;
        while(true){
            if (cur == NULL) return i;
            cur = cur->nxt;
            i++;
        }
    }

    string topp() {
        return top->data;
    }
};
int main()
{
    int n;
    cin >> n;
    Stack st;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(st.is_empty())
            st.push(s);
        else{
            if(st.topp() != s){
                st.push(s);
            }
        }
    }
    int l = st.length();
    cout << "All in all: " << l << endl <<"Students:\n";
    for(int i = 0; i < l; i++){
        cout << st.topp() << endl;
        st.pop();
    }
}