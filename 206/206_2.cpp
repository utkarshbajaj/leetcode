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
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        
        unordered_map<int, vt<int>> pref;
        
        rep(i, pairs.size()){
            rep(j, 2){
                int curr = pairs[i][j];
                int toGet = pairs[i][j ^ 1];
                vt<int> list;
                int k = 0;
                while(preferences[curr][k] != toGet){
                    list.pb(preferences[curr][k++]);
                }
                pref[curr] = list;
            }
        }
        
        int ans = 0;
        
        rep(i, preferences.size()){
            rep(j, pref[i].size()){
                int flag = 0;
                rep(k, pref[pref[i][j]].size()){
                    if(pref[pref[i][j]][k] == i){
                        ans++;
                        flag = 1;
                    }
                    if(flag){
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
        }
        return ans;
    }
};