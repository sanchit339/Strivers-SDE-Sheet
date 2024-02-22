/**
 * @file FloydWrshall.cpp
 * @author your name (you@domain.com)
 * @brief  > All Node shortest distance
 *         > 
 * @version 0.1
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<bits/stdc++.h>
using namespace std;

const int N = 510;
const int INF = 1e9 + 10;
int dist[N][N];

int main(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(i == j) dist[i][j] = 0; 
            else dist[i][j] = INF;
        }
    }

    int n , m; // N nodes M edges
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int x , y , wt ;
        cin >> x >> y >> wt ;
        dist[x][y] = wt;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
}