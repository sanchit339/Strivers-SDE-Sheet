/**
 * @file KrushalsAlgo.cpp
 * @author Luv
 * 
 * @brief > Done using DSU 
 *        > Finding MST  
 * @version 0.1
 * @date 2023-08-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int Size[N];

void make_set(int v){
    parent[v] = v;
    Size[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a , int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        if(Size[a] < Size[b]){
            swap(a,b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main(){
    int n , k;
    cin >> n >> k;
    
    for(int i = 1 ; i <= n ; i++){
        make_set(i);
    }

    vector<pair<int , pair<int,int> > > edges;
    for(int i = 0 ; i < k ; i++){
        int u , v , wt;
        cin >> u >> v >> wt;
        edges.push_back({wt , {u , v}});
    }

    sort(edges.begin() , edges.end());

    int total_weight = 0;
    for(auto node : edges){
        int wt = node.first;
        int u = node.second.first;
        int v = node.second.second;

        if(find_set(u) == find_set(v)) continue; // if belong to same tree
        union_set(u , v);
        total_weight += wt;

        cout << u << " " << v << endl;
    }
}