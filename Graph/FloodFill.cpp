/**
 * @file FloodFill.cpp
 * @author Luv
 * 
 * @brief > Mark Visited as Final Colour
 * 
 * @version 0.1
 * @date 2023-08-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // here vertex is replced by i , j
    void dfs(int i , int j , int initialColor ,int finalColor , vector<vector<int>>& image){
        int n = image.size();
        int m = image[0].size();
        if(i < 0 || j < 0) return; // invalid nodes eliminate
        if(i >= n || j >= m) return;
        if(image[i][j] != initialColor)return; // elminate if the invalid node

        image[i][j] = finalColor;
        dfs(i-1 , j , initialColor , finalColor , image);
        dfs(i+1 , j , initialColor , finalColor , image);
        dfs(i , j+1 , initialColor , finalColor , image);
        dfs(i , j-1 , initialColor , finalColor , image);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initailColor = image[sr][sc]; // row , col
        if(initailColor != color) // just normal edge case is same then dont dfs
            dfs(sr, sc , initailColor ,color , image);
        
        return image;
            
    }
};