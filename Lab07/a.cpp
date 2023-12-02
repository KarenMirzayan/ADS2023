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

void merge(vector<string> &v, int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    auto *leftArray = new string[subArrayOne],
         *rightArray = new string[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = v[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = v[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne].size()
            <= rightArray[indexOfSubArrayTwo].size()) {
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
 
void mergeSort(vector<string> &v, int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = (end + begin) / 2;
    mergeSort(v, begin, mid);
    mergeSort(v, mid + 1, end);
    merge(v, begin, mid, end);
}

int main()
{
    int n;
    cin >> n;
    vector <string> v;
    for(int i = 0; i < n + 1; i++){
        string s; 
        getline(cin, s);
        if(i == 0){continue;}
        auto v = getString(s);
        mergeSort(v, 0, v.size() - 1);
        for(auto ss : v){
            cout << ss << " ";
        }
        cout << "\n";
    }
}