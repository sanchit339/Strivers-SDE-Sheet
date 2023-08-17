/**
 * @file CityAndCampers.cpp
 * @author Luv
 * 
 * @brief 
 * 
 * @date 2023-08-17
 * 
 * @copyright HackerEarth
 * 
 */

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int Size[N];

multiset<int> ms;

void make_set(int v){
    parent[v] = v;
    Size[v] = 1;
    ms.insert(1);
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void merge(int a , int b){
    // erase previous 
    ms.erase(ms.find(Size[a]));
    ms.erase(ms.find(Size[b]));

    ms.insert(Size[a] + Size[b]);
}

void union_set(int a , int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(Size[a] < Size[b]){
            swap(a , b);
        }
        parent[b] = a;
        merge(a , b);
        Size[a] += Size[b];
    }
}

int main(){
    int n , k;
    cin >> n >> k;

    for(int i = 1 ; i <= n ; i++){
        make_set(i);
    }

    while(k--){
        int a , b;
        cin >> a >> b;
        union_set(a , b);
        if(ms.size() == 1){ // after merge 2 we get 1 so size also becomes 1
            cout << 0 << endl;
        }
        else{
            int a = *(ms.begin());
            int b = *(--ms.end()); // .end() is outer itr so --itr

            cout << b - a << endl;
        }
    }
}