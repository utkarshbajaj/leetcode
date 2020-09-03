#include <iostream>
#include <deque>
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
    int getWinner(vector<int>& arr, int k) {
        
        deque<int> dq;
        
        int top = arr[0];
        
        repb(i, 1, arr.size()){
            dq.pb(arr[i]);  
        }
        
        int count = 0;
        while(count < k && count < arr.size() - 1){
            if(top > dq.front()){
                int temp = dq.front();
                dq.pop_front();
                dq.pb(temp);
                count++;
            } else {
                int temp = top;
                top = dq.front();
                dq.pop_front();
                dq.pb(temp);
                count = 1;
            }
        }
        
        return top;
        
    }
};