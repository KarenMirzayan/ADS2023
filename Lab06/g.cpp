#include <iostream>
#include <vector>
using namespace std;

bool comp(pair<string, string> v1, pair<string, string> v2){
    return v1.first < v2.first;
}

int partition(vector<pair<string, string>> &arr, int low, int high)
{
	pair<string, string> pivot = arr[high]; 

	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{
		if (comp(arr[j], pivot)) {
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

int partition_r(vector<pair<string, string>> &arr, int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);

	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}

void quickSort(vector<pair<string, string>> &arr, int low, int high)
{
	if (low < high) {
		int pi = partition_r(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(vector<pair<string, string>> arr, int size)
{
	int i;
    cout << size << endl;
	for (i = 0; i < size; i++)
		cout<<arr[i].first << " " << arr[i].second << endl; 
}

int main() {
    int n;
    cin >> n;
    string fname, lname;
    vector<pair<string, string>> v;
    for(int i = 0; i < n; i++) {
        cin >> fname >> lname;
        bool f = false;
        for(int i = 0; i < v.size(); i++){
            if(fname == v[i].second){
                v[i].second = lname;
                f = true;
                break;
            }
        }
        if(!f) v.push_back(pair(fname, lname));
    }
    quickSort(v, 0, v.size()-1);
    printArray(v, v.size());

}