#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

// This function takes last element
// as pivot, places
// the pivot element at its correct
// position in sorted array, and 
// places all smaller (smaller than pivot)
// to left of pivot and all greater 
// elements to right of pivot
int partition(vector<int> &arr, int low, int high)
{
	// pivot
	int pivot = arr[high]; 

	// Index of smaller element
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{
		// If current element is smaller
		// than or equal to pivot
		if (arr[j] <= pivot) {
        //     cout << arr[j] << " " << pivot << endl;
			// increment index of 
			// smaller element
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(vector<int> &arr, int low, int high)
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
void quickSort(vector<int> &arr, int low, int high)
{
	if (low < high) {

		/* pi is partitioning index,
		arr[p] is now
		at right place */
		int pi = partition_r(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(vector<int> arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout<<arr[i] << " "; 
}

int lowestDistance(vector<int> v, int n) {
    int max = INT_MAX;
    int a;
    for(int i = 0; i < n -1; i++) {
        a = v[i + 1] - v[i];
        if(a < max)
            max = a;
    }
    return max;
}

void printLowestDistance(vector<int> v, int n) {
    int a = lowestDistance(v, n);
    for(int i = 0; i < n - 1; i++) {
        if(v[i + 1] - v[i] == a) {
            cout << v[i] <<" " << v[i + 1] << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    quickSort(v, 0, n-1);
    printLowestDistance(v, n);
}