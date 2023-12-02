#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct Student {
    string firstName;
    string secondName;
    double GPA;
    Student() {}
    Student (string a, string b, double g) {
        firstName = a;
        secondName = b;
        GPA = g;
    }
};

bool comparator(Student a, Student b) {
    if(a.GPA == b.GPA) {
        if(a.firstName == b.firstName) {
            return a.secondName < b.secondName;
        }
        return a.firstName < b.firstName;
    }
    return a.GPA < b.GPA;
}
int partition(vector<Student> &arr, int low, int high)
{
	Student pivot = arr[high]; 

	int i = (low - 1); 

	for (int j = low; j <= high; j++) 
	{
		if (comparator(arr[j], pivot)) {
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

int partition_r(vector<Student> &arr, int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);

	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}

void quickSort(vector<Student> &arr, int low, int high)
{
	if (low < high) {

		int pi = partition_r(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(vector<Student> &arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i].firstName << " " << arr[i].secondName << " " << arr[i].GPA << endl; 
}

int main() {
    int n, m;
    cin >> n;
    vector<Student> v;
    for(int i = 0; i < n; i++){
        string f, l;
        cin >> f >> l;
        cin >> m;
        double top = 0, bot = 0;
        for(int j = 0; j < m; j++) {
            string a;
            int k;
            cin >> a >> k;
            double t;
            if(a == "A+") t = 4;
            else if(a == "A") t = 3.75;
            else if(a == "B+") t = 3.5;
            else if(a == "B") t = 3;
            else if(a == "C+") t = 2.5;
            else if(a == "C") t = 2;
            else if(a == "D+") t = 1.5;
            else if(a == "D") t = 1;
            else t = 0;
            top += t * k;
            bot += k;
            
        }
        Student s(f, l, top/bot);
        v.push_back(s);
    }
    quickSort(v, 0, n-1);
    for(int i = 0; i < n; i++) {
        cout << v[i].firstName << " " << v[i].secondName << " " << fixed << setprecision(3) << v[i].GPA << "\n";
    }
}