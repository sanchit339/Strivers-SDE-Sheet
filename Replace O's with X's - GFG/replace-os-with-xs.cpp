//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
private:
    void dfs(int i , int j , vector<vector<char>> &mat , vector<vector<char>> &ans , vector<vector<int>> &vis){
        int n = mat.size() , m = mat[0].size();
        if(i < 0 || j < 0) return;
        if(i >= n || j >= m) return;
        if(mat[i][j] == 'X' || vis[i][j]) return;

        ans[i][j] = 'O';
        vis[i][j] = 1;

        dfs(i + 1 , j , mat , ans , vis);
        dfs(i - 1 , j , mat , ans , vis);
        dfs(i , j + 1 , mat , ans , vis);
        dfs(i , j - 1 , mat , ans , vis);

    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        vector<vector<char>> ans (n , vector<char>(m , 'X'));
        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i = 0 ; i < m ; i++){
            if(mat[0][i] == 'O' && !vis[0][i]){
                dfs(0 , i , mat , ans , vis);
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(mat[i][m - 1] == 'O' && !vis[i][m - 1]){
                dfs( i , m - 1 , mat , ans , vis);
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(mat[n - 1][i] == 'O' && !vis[n - 1][i]){
                dfs( n - 1 , i , mat , ans , vis);
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(mat[i][0] == 'O' && !vis[i][0]){
                dfs( i , 0 , mat , ans , vis);
            }
        }
        return ans;
    }
};







//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends