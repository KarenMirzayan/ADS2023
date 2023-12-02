#include <iostream>
#include <stack>
using namespace std;
bool isSameStack(stack<char> stack1, stack<char> stack2)
{
    bool flag = true;
    if (stack1.size() != stack2.size()) {
        flag = false;
        return flag;
    }
    while (stack1.empty() == false) {
        if (stack1.top() == stack2.top()) {
            stack1.pop();
            stack2.pop();
        }
        else {
            flag = false;
            break;
        }
    }
    return flag;
}
int main(){
    string a, b;
    cin >> a >> b;
    stack<char> sta, stb;
    for(auto &ch : a)
    {
        if(!sta.empty() && ch == '#') sta.pop();
        else sta.push(ch);
    }
    for(auto &ch: b)
    {
        if(!stb.empty() && ch == '#') stb.pop();
        else stb.push(ch);
    }
    isSameStack(sta, stb) ? cout << "Yes" : cout << "No";
}