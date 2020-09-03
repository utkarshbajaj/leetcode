#include <iostream>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define popb pop_back()
#define pii pair<int,int> 
#define pll pair < long long, long long >
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sortv(v) sort(v.begin(),v.end())
#define rsortv(v) sort(v.begin(),v.end(), greater<>());

/*------------------------------------------------------------*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        fastio;
        
        int ans = 0;
        int n = grid.size();
        int found = 0;
        int count = n - 1;
        
        
        while(count){
            int r = 0;
            found = 0;
            rep(i, n + 1){
                if(i == n){
                    return -1;
                }
                if(grid[i][0] == -1){
                    continue;
                } 
                int temp = 0;
                rfor(j, n - 1, 0){
                    if(temp == count){
                        found = 1;
                        break;
                    }
                    if(grid[i][j] == 0){
                        temp++;
                    } else {
                        break;
                    }
                }
                if(found){
                    rep(j, n){
                        grid[i][j] = -1;
                    }
                    ans += r;
                    break;
                } else {
                    r++;
                }
            }
            count--;
        }
        
        return ans;
        
    }
};