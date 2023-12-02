#include <iostream>
#include <climits>
using namespace std;
 
struct Node {
    int val;
    Node *next;

    Node() {
        val = 0;
        next = NULL;
    }

};
 
 
 
int findMaxSum(int n, Node *head) {
    int max = INT_MIN, max_temp = 0;
    Node *cur = head;
    for(int i = 0; i < n; i++) {
        max_temp += cur->val;
        if(max < max_temp)
            max = max_temp;
        if (max_temp < 0)
            max_temp = 0;
        cur = cur->next;
    }
    return max;
}

// int maxSubArraySum(int a[], int size)
// {
//     int max_so_far = INT_MIN, max_ending_here = 0;
 
//     for (int i = 0; i < size; i++) {
//         max_ending_here = max_ending_here + a[i];
//         if (max_so_far < max_ending_here)
//             max_so_far = max_ending_here;
 
//         if (max_ending_here < 0)
//             max_ending_here = 0;
//     }
//     return max_so_far;
// }
 
int main() {
    int n;
    cin >> n;
    
    Node *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node *cur = new Node();
        cur -> val = x;
    
        if (i == 1) {
        head = tail = cur;
        } else {
        tail -> next = cur;
        tail = cur;
        }
    }
    
    cout << findMaxSum(n, head) << "\n";
    return 0;
}