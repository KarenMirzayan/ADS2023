#include <iostream>

using namespace std;

const long long N = (long long)1e5 + 5;

long long n; // size of heap
long long a[N]; // storage


void heapify_up(long long v) {
	// until I didn't reach root
	// and parent's value is smaller than min
	// I swap my content with parent and go to parent
	while (v != 1 && a[v/2]<a[v]) {
		swap(a[v/2],a[v]);
		v = v / 2;
	}
}

void push(long long x) {
	n++;
	a[n] = x;
	heapify_up(n);
}

long long top() {
	if (n == 0) {
		cout << "[Error] Heap is empty\n";
		exit(0);
	}
	return a[1];
}

void print(long long v = 1, long long tab = 0) {
	if (v == 1)
		cout << "-----\n";

	if (v > n)
		return;
	
	print(2 * v + 1, tab + 1);

	for (long long i = 0; i < tab; i++) cout << "| ";
	cout << a[v] << "\n";
	
	print(2 * v, tab + 1);
}

void heapify_down(long long v) {
	long long p = v;
	long long l = 2*v;
	long long r = 2*v+1;

	if (l <= n && a[l] > a[p]) p = l;
	if (r <= n && a[r] > a[p]) p = r;
	if (p == v)
		return;
	
	swap(a[p], a[v]);
	heapify_down(p);
}

void pop() {
	swap(a[1], a[n]);
	n--;
	heapify_down(1);
}

void build() { // works in O(n), not O(nlogn)
	for (long long i = n/2; i >= 1; i--) { // O(n)
		heapify_down(i); // O(log(n))
	}
}

int main() {
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
    build();
    while (n > 1) {
        long long y = top();
        pop();
        long long x = top();
        pop();
        long long dy = y - x;
        if (dy != 0) {
            push(dy);
        }
        // print();
    }

    cout << (n == 1 ? a[1] : 0) << endl;
    return 0;
}