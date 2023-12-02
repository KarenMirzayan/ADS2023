#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack<char> st;
    for(auto &ch: s) {
        if (st.empty()) st.push(ch);
        else if (st.top() == ch) st.pop();
        else st.push(ch);
    }
    st.empty() ? cout << "YES" : cout << "NO";
    return 0;
}