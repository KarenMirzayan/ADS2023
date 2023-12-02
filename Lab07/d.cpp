#include <bits/stdc++.h>
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

void merge(vector<Student> &v, int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    auto *leftArray = new Student[subArrayOne], *rightArray = new Student[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = v[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = v[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (comparator(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo])) {
            v[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            v[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayOne < subArrayOne) {
        v[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayTwo < subArrayTwo) {
        v[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void mergeSort(vector<Student> &v, int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = (end + begin) / 2;
    mergeSort(v, begin, mid);
    mergeSort(v, mid + 1, end);
    merge(v, begin, mid, end);
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
    mergeSort(v, 0, n-1);
    for(int i = 0; i < n; i++) {
        cout << v[i].firstName << " " << v[i].secondName << " " << fixed << setprecision(3) << v[i].GPA << "\n";
    }
}