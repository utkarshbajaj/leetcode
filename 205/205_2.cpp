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
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        int count = 0;
        
        unordered_map<ll, ll> s1, s2;
        
        rep(i, nums1.size()){
            repb(j, i + 1, nums1.size()){
                if(!s1.count(((ll)nums1[i] * (ll)nums1[j]) % MOD)){
                    s1[((ll)nums1[i] * (ll)nums1[j]) % MOD] = 1;
                } else {
                    s1[((ll)nums1[i] * (ll)nums1[j]) % MOD]++;
                }
                
            }
        }
        
        rep(i, nums2.size()){
            if(s1.count(((ll)nums2[i] * (ll)nums2[i]) % MOD)){
                count += s1[((ll)nums2[i] * (ll)nums2[i]) % MOD];
            }
        }
        
        rep(i, nums2.size()){
            repb(j, i + 1, nums2.size()){
                if(!s2.count(((ll)nums2[i] * (ll)nums2[j]) % MOD)){
                    s2[((ll)nums2[i] * (ll)nums2[j]) % MOD] = 1;
                } else {
                    s2[((ll)nums2[i] * (ll)nums2[j]) % MOD]++;
                }
                
            }
        }
        
        rep(i, nums1.size()){
            if(s2.count(((ll)nums1[i] * (ll)nums1[i]) % MOD)){
                count += s2[((ll)nums1[i] * (ll)nums1[i]) % MOD];
            }
        }
        
        
        return count;
    }
};