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

template <typename T>
inline void readArray(vector<T>& arr, int n) {
  arr.resize(n);
  for (auto& element : arr) {
    cin >> element;
  }
}

template <typename T>
inline void printArray(const vector<T>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << arr[n - 1] << endl;
}


/*------------------------------------------------------------*/


class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        
        if(s.size() == 1){
            return 0;
        }
        
        int sum = 0;
        
        stack<pair<char, int>> st;
        
        st.push(make_pair(s[0], cost[0]));
        
        repb(i, 1, s.size()){
            
            pair<char, int> temp = st.top();
            
            if(s[i] == temp.fi){
                
                if(cost[i] > temp.se){
                    
                    sum += temp.se;
                    st.pop();
                    st.push(make_pair(s[i], cost[i]));
                    
                } else {
                    
                    sum += cost[i];
                    
                }
                
            } else {
                st.push(make_pair(s[i], cost[i]));
            }
            
        }
        
        return sum;
        
    }
};