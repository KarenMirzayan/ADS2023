#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> a) {
    int res = 0;
    for(auto &i: a) {
        res += i;
    }
    return res;
}
bool comparator(const vector<int>& a, const vector<int>& b) {
    if (sum(a) == sum(b)) {
        for (int j = 0; j < a.size(); j++) {
            if (a[j] <= b[j]) {
                return true;
            }
            return false;
        }
    }
    return sum(a) > sum(b);
}

void merge(vector<vector<int>> &v, int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
   vector<vector<int>> leftArray(subArrayOne), rightArray(subArrayTwo);
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = v[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = v[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (comparator(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo])) {
            v[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            v[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayOne < subArrayOne) {
        v[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayTwo < subArrayTwo) {
        v[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 
void mergeSort(vector<vector<int>> &v, int const begin, int const end)
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
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}