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
    int compareVersion(string version1, string version2) {
        
        stringstream st1(version1), st2(version2);
        
        string str;
        vt<int> v1, v2;
        while(getline(st1, str, '.')){
            v1.pb(stoi(str));
        }
        while(getline(st2, str, '.')){
            v2.pb(stoi(str));
        }
        
        if(v1.size() > v2.size()){
            v2.resize(v1.size());
        } else {
            v1.resize(v2.size());
        }
        
        rep(i, v1.size()){
            if(v1[i] > v2[i]){
                return 1;
            } else if(v1[i] < v2[i]){
                return -1;
            }
        }
            
        return 0;
        
    }
};