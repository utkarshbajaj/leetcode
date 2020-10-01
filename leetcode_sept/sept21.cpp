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

bool comp(pii v1, pii v2){
    return v1.fi < v2.fi;
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vt<pii> in;
        vt<pii> out;
        
        rep(i, trips.size()){
            in.pb(make_pair(trips[i][1], trips[i][0]));
            out.pb(make_pair(trips[i][2], trips[i][0]));
        }
        
        sort(in.begin(), in.end(), ::comp);
        sort(out.begin(), out.end(), ::comp);
        
        
        int i = 0, j = 0;
        
        int curr = 0;
        
        while(j < trips.size() && i < trips.size()){
            if(out[j].fi > in[i].fi){
                curr += in[i++].se;
            } else if(out[j].fi < in[i].fi){
                curr -= out[j++].se;
            } else {
                curr += in[i++].se;
                curr -= out[j++].se;
            }
            if(curr > capacity){
                return false;
            }
        }
        
        return true;
        
    }
};