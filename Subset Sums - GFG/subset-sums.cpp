//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void subSum(int idx , vector<int> arr , int n , int sum , vector<int> &ans){
        // base case 
        if(idx == n){
            ans.push_back(sum);
            return;
        }
        
        // take
        subSum(idx + 1 , arr , n , sum +  arr[idx] , ans);

        //not take
        subSum(idx + 1 , arr , n , sum , ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        subSum(0 , arr , N , 0 , ans);
        sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends