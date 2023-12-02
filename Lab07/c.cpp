#include <bits/stdc++.h>
using namespace std;

vector <string> getString(string s){
    vector <string> qwe;
    s += " ";
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            temp += s[i];
        }
        else{
            qwe.push_back(temp);
            temp = "";
        }
    }
    return qwe;
}
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

void merge(vector<int> &v, int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = v[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = v[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
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
 
void mergeSort(vector<int> &v, int const begin, int const end)
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
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    mergeSort(a, 0, n-1);
    mergeSort(b, 0, m-1);
    printSame(a, b, n, m);
}