#include <iostream>
#include <vector>
using namespace std;

int partition(vector<char> &arr, int low, int high)
{
	char pivot = arr[high]; 

	int i = low; 

	for (int j = low; j < high; j++) 
	{
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i], arr[high]);
	return i;
}

int partition_r(vector<char> &arr, int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);

	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}

void quickSort(vector<char> &arr, int low, int high)
{
	if (low < high) {

		int pi = partition_r(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(vector<char> &arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout<<arr[i]; 
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<char> vowels, consonants;
    for(auto &ch: s) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowels.push_back(ch);
        else
            consonants.push_back(ch);
    }
    int vs = vowels.size(), cs = consonants.size();
    quickSort(vowels, 0, vs - 1);
    quickSort(consonants, 0, cs - 1);
    printArray(vowels, vs);
    printArray(consonants, cs);
}