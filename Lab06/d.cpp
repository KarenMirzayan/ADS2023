#include <iostream>
#include <vector>
using namespace std;

struct date {
	int d, m, y;
	date(string s) {
		string a = "";
		for(int i = 0; i < 2; i++) {
			a += s[i];
		}
		d = stoi(a);
		a = "";
		for(int i = 3; i < 5; i++) {
			a += s[i];
		}
		m = stoi(a);
		a = "";
		for(int i = 6; i < 10; i++) {
			a += s[i];
		}
		y = stoi(a);
	}
};

bool comparator(string s, string a) {
	date d1(s), d2(a);
	if(d1.y < d2.y) return true;
	if(d1.y == d2.y) {
		if (d1.m < d2.m)
			return true;
		if(d1.m == d2.m){
			if(d1.d < d2.d)
				return true;
		}
	}
	return false;
}

// This function takes last element
// as pivot, places
// the pivot element at its correct
// position in sorted array, and 
// places all smaller (smaller than pivot)
// to left of pivot and all greater 
// elements to right of pivot
int partition(vector<string> &arr, int low, int high)
{
	string pivot = arr[high]; 

	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{
		if (comparator(arr[j], pivot)) {
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(vector<string> &arr, int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);

	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}

/* The main function that implements
QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(vector<string> &arr, int low, int high)
{
	if (low < high) {

		int pi = partition_r(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(vector<string> &arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout<<arr[i] << endl; 
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
	quickSort(s, 0, n - 1);
	printArray(s, n);
}