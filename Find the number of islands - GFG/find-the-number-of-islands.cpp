//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // replace vis by setting it to zero
    void dfs(int i , int j , vector<vector<char>>& grid){
        int n = grid.size() , m = grid[0].size();
        if(i < 0 || j < 0) return; // invalid nodes eliminate
        if(i >= n || j >= m) return;
        if(grid[i][j] == '0') return;

        grid[i][j] = '0'; // mark visited , dfs all the other
        dfs(i+1 , j , grid);
        dfs(i-1 , j , grid);
        dfs(i , j+1 , grid);
        dfs(i , j-1 , grid);
        
        dfs(i + 1 , j + 1 , grid);
        dfs(i - 1 , j + 1 , grid);
        dfs(i - 1 , j - 1 , grid);
        dfs(i + 1 , j - 1 , grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        // dfs( 0 , 0  , grid)
        int n = grid.size() , m = grid[0].size();
        int count = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i , j ,grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends