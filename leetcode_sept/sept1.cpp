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

bool comp(vt<int> a, vt<int> b){
    rep(i, 4){
        if(a[i] > b[i]){
            return true;
        } else if(a[i] < b[i]){
            return false;
        }
    }
    return false;
}

class Solution {
public:
    vector<vector<int>> res;
    
    char toChar(int a){
        return '0' + a;
    }
    
    void permute(vector<int> nums, int l, int r){
        if(l == r){
            res.pb(nums);
            return;
        }
        
        repeb(i, l, r){
            int temp = nums[i];
            nums[i] = nums[l];
            nums[l] = temp;
            
            permute(nums, l + 1, r);
            
            temp = nums[i];
            nums[i] = nums[l];
            nums[l] = temp;
        }
        
    }
    
    
    
    bool check(vector<int> nums){
        
        if(nums[0] > 2){
            return false;
        } 
        
        if((nums[0] == 2 && nums[1] > 3) || (nums[1] > 9)) {
            return false;
        }
        
        if(nums[2] > 5){
            return false;
        }
        
        return true;
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        
        permute(A, 0, A.size() - 1);
        
        sort(res.begin(), res.end(), ::comp);
        
        rep(i, res.size()){
            if(check(res[i])){
                string s;
                rep(j, res[i].size()){
                    s = s + toChar(res[i][j]);
                }
                s = s.substr(0, 2) + ':' + s.substr(2);
                return s;
            }
        }
        
        return "";
        
        
    }
};