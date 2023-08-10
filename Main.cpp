#include<bits/stdc++.h>
using namespace std;

int solve(int N, int K , vector<int> &v){
    int result = 0;
    for(int i = 0 ; i < N ; i++){
        vector<pair<int,int>> temp;
        for(int j = 0 ; j < 3 ; j++){
            temp.push_back({v[i + j] , i + j});
        }
        auto it = max_element(temp.begin() , temp.end());
        // result += max(0 , it.first);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int N , K;
        cin >> N >> K;
        vector<int>v;
        for(auto &i:v) cin >> i;
        solve(N , K , v);
    }
}
