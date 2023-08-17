/**
 * @file DSU.cpp
 * @author Luv
 * 
 * @brief > MakeParent
 *        > Find_Set
 *        > Union (after finding parent)
 *        > Can find distinct connected components  
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
    if(v == parent[v]){
        return v;
    }
    // path compression
    return parent[v] = find_set(parent[v]); // assign to same parent
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a; // connect b to parent of a
        Size[a] += Size[b];
    }
}

int main(){
    int n , k;
    cin >> n >> k;
    while(k--){
        int a , b;
        union_sets(a , b); // created union 
    }

    int connected_comp = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(find_set(i) == i){ // 1 - 2 - 3 ... 5 - 6 ( 1 , 5 )
            connected_comp++;
        }
    }

    cout << connected_comp << endl;
}