#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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

/*Prints same numbers within 2 vectors*/
void printSame(vector<int> v1, vector<int> v2, int n, int m) {
    int i = 0, j = 0;
    while(i < n && j < m) {
        if (v1[i] < v2[j]) {
            i++;
        }
        else if(v1[i] > v2[j]) {
            j++;
        }
        else {
            cout << v1[i] << " ";
            i++;
            j++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    quickSort(v1, 0, n - 1);
    quickSort(v2, 0, m - 1);
    // printArray(v1, n);
    // cout << endl;
    // printArray(v2, m);
    printSame(v1, v2, n, m);
}