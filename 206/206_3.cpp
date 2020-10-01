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
    
   

    int prims(int **admat, int v, int *weights, bool *visited, int *parents){

        int curr = 0;
        int ans = 0;

        rep(i, v - 1){
            visited[curr] = true;

            rep(j, v){
                if(admat[curr][j] && !visited[j]){
                    if(weights[j] > admat[curr][j]){
                        weights[j] = admat[curr][j];
                        parents[j] = curr;
                    }
                }
            }

            curr = -1;

            rep(j, v){
                if(!visited[j] && (curr == -1 || weights[j] < weights[curr])){
                    curr = j;
                }
            }

        }

        repb(i, 1, v){
            ans += weights[i];
        }

        return ans;

    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        int E = V * V;
        
        int **admat = new int*[V];
        for(int i = 0 ; i < V ; i++){
            admat[i] = new int[V];
            for(int j = 0 ; j < V ; j++){
                admat[i][j] = 0;
            }
        }
        
        int k = 0;
        rep(i, points.size()){
            rep(j, points.size()){
                
                admat[i][j] = admat[j][i] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
        
        bool *visited = new bool[V];
    
        for(int i = 0 ; i < V ; i++){
            visited[i] = false;
        }

        int *parents = new int[V];
        for(int i = 0 ; i < V ; i++){
            parents[i] = -1;
        }

        int *weights = new int[V];
        for(int i = 0 ; i < V ; i++){
            weights[i] = INT_MAX;
        }
        
        int res = prims(admat, V, weights, visited, parents);
        return res;
        
    }
};