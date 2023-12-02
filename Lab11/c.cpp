#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

vector <pair<int, pair<int, int>>> edges;
vector <int> parent;

int get(int v){
    if (parent[v] == v){
        return v;
    } else {
        return parent[v] = get(parent[v]);
    }
}

void unite (int a, int b){
    a = get(a);
	b = get(b);
    if (a != b){
        if (rand() % 2 == 1)
            parent[a] = b;
        else
            parent[b] = a;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    int big, small, both;
    cin >> big >> small;

    if (small > big)
        both = big;
    else
        both = small;
    
    for (int i=0; i<m; i++){
        string type;
        cin >> type;
        int a, b, cost;
        cin >> a >> b >> cost;
        a--;
        b--;
        if (type == "both"){
            cost *= both;
        } else if (type == "small"){
            cost *= small;
        } else {
            cost *= big;
        }
        edges.push_back(make_pair(cost, make_pair(a, b)));
    }
    sort(edges.begin(), edges.end());

    parent.resize(n);
    for (int i = 0; i < n; i++){
        parent[i] = i;
    }

    int total_cost = 0;
    for (int i = 0; i < m; i++){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int cost = edges[i].first;
        if (get(a) != get(b)){
            total_cost += cost;
            unite(a, b);
        }
    }

    cout << total_cost;
    return 0;



}