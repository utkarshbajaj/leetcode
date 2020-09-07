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
    bool wordPattern(string pattern, string str) {
        
        unordered_map<string, char> seen;
        unordered_map<char, string> revseen;
        
        int c = 0;
        int start = 0;
        
        rep(i, str.size()){
            if(str[i] == ' '){
                c++;
            }
        }
        
        if(c + 1 != pattern.size()){
            return false;
        }
        
        c = 0;
        
        rep(i, str.size()){
            if(str[i] == ' '){
                string toPut = str.substr(start, i - start);
        
                char curr = pattern[c];
                
                if(revseen.count(curr)){
                    if(toPut != revseen[curr]){
                        return false;
                    }
                } 
                
                if(seen.count(toPut)){
                    if(curr != seen[toPut]){
                        return false;
                    }
                } 
                else {
                    seen[toPut] = curr;
                    revseen[curr] = toPut;
                }
                start = i + 1;
                c++;
            }
        }
        
        string toPut = str.substr(start);
        char curr = pattern[c];
        
        if(revseen.count(curr)){
            if(toPut != revseen[curr]){
                return false;
            }
        } 

        if(seen.count(toPut)){
            if(curr != seen[toPut]){
                return false;
            }
        } 
        
        return true;
        
        
    }
};