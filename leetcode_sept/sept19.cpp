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
    
    void seqHelper(int curr, int low, int high, vt<int> &ans){
        if(curr >= low && curr <= high){
            ans.pb(curr);
        }
        
        if(curr > high){
            return;
        }
        
        int rem = curr % 10;
        if(rem != 9){
            int next = curr * 10 + rem + 1;
            seqHelper(next, low, high, ans);
        }
        
    }
    vector<int> sequentialDigits(int low, int high) {
        vt<int> res;
        
        repeb(i, 1, 9){
            seqHelper(i, low, high, res);
        }
        
        sortv(res);
        return res;
    }
};