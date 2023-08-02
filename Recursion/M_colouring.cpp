/**
 * @file M_colouring.cpp
 * @author Striver
 * @brief  TC (N nodes M colour  ==   N^M) calculation
 * @version 0.1
 * @date 2023-08-01 
 */
#include <bits/stdc++.h>
using namespace std;

class solution{
    private:
    bool isSafe(int node , bool graph[101][101] , int col , vector<int> &colour , int n){
        // iterate all the other nodes
        for(int k = 0 ; k < n ; k++){ // 0 ... n - 1 nodes // traveling all the adj nodes
            if(k != col && graph[k][node] == 1 && colour[k] == col){  // 1 skip for kth node . 2. check if its adj
                return false;
            }
        }
        return true;
    }
    private:
    bool solve(int node , bool graph[101][101], int m, int n , vector<int> &colour){
        if(node == n){  // start from 0 node
            return true;
        }

        for(int i = 0 ; i < n ; ++i){//loop all nodes
            if(isSafe(node , graph , i , colour , n)){

                colour[node] = i; // choosen from i colour for the node
                solve(node + 1 , graph , m , n , colour);
                colour[node] = 0; // while backtack
            }
        }
        return true;
    }
    public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> colour(n , 0); // colour hash
        if(solve(0 ,graph , m , n , colour) == true) return true;
        return false;
    }
};