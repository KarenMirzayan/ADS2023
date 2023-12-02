#include <iostream>

using namespace std;

const int N = (int)1e5 + 5;

int n = 0; // size
int a[N]; // storage


void heapify_up(int v) {
	while (v != 1 && a[v/2] > a[v]) {
		swap(a[v/2], a[v]);
		v = v / 2;
	}
}

void push(int x) {
	n++;
	a[n] = x;
	heapify_up(n);
}

int top() {
	if (n == 0) {
		cout << "[Error] Heap is empty\n";
		exit(0);
	}
	return a[1];
}

void print(int cnt) {
    if (cnt == 0) {
        cout << 0 << endl;
        return;
    }
    int sum = 0;
	for(int i = 1; i <= cnt; i++){
        sum += a[i];
    }
    cout << sum << endl;
}

void heapify_down(int v) {
	// find max among v, 2v, 2v+1
	int p = v;
	int l = 2*v;
	int r = 2*v+1;
	if (l <= n && a[l] < a[p]) p = l;
	if (r <= n && a[r] < a[p]) p = r;
	if (p == v) // if v is greater than l&r
		return;
	// p = l or r (left or right son)
	swap(a[p], a[v]);
	heapify_down(p);
}

void pop() {
	swap(a[1],a[n]);
	n--;
	heapify_down(1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int q, k;
    cin >> q >> k;

    string s;
    int a;
    int cnt = 1;
    for(int i = 0; i < q; i++) {
        cin >> s;
        if (s == "insert") {
            cin >> a;
            if(cnt <= k){
                push(a);
                cnt++;
            }
            else{
                if (a > top()){
                    pop();
                    push(a);
                }
            }
        }
        else if (s == "print") {
            print(cnt);
        }
    }
    return 0;
}