#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define nl cout << endl
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define popb pop_back()
#define pii pair<int,int> 
#define pll pair < long long, long long >
#define vt vector
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());
const int d4i[4] = {0, -1, 0, 1}, d4j[4] = {1, 0, -1, 0};
const int d8i[8] = {0, 1, 1, 1, 0, -1, -1, -1}, d8j[8] = {1, 1, 0, -1 , -1, -1, 0, 1};

/*------------------------------------------------------------*/


class Solution {
public:
    
    void sumHelper(int *arr, int n, int k, int sum, vt<int> input, vt<vt<int>> &v){
        if(sum == 0){
            if(input.size() == k){
                v.pb(input);
            }
            return;
        }
        if(n == 0){
            return;
        }
        
        if(sum - arr[0] >= 0){
            input.pb(arr[0]);
            sumHelper(arr + 1, n - 1, k, sum - arr[0], input, v);
            input.popb;
        }
        
        sumHelper(arr + 1, n - 1, k, sum, input, v);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        int *arr = new int[9];
        
        rep(i, 9){
            arr[i] = i + 1;
        }
        
        vt<int> input;
        vt<vt<int>> result;
        
        sumHelper(arr, 9, k, n, input, result);
        
        return result;
        
        
    }
};