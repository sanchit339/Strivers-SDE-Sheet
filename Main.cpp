#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    void cnt(int arr[] , int n , int &cnt){
        int maxi = INT_MIN;
        int local = 0;
        int i = 0;
        while(i < n){
            if(arr[i] == 1){
                local++;
                i++;
            } 
            else{
                break;
            }
        }
        while(i < n){
            local++;
            if(arr[i] == 1){
                maxi = max(maxi , local);
                local = 0;
            } 
            i++;
        }
        cnt = maxi;
    }
public:
    int maxOnes(int a[], int n){
        int maxi = 0;
        cnt(a , n , maxi);
        return maxi;
    }
};