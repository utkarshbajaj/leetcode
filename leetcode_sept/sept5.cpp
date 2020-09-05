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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    void inorder(TreeNode *root, vt<int> &v){
        
        if(root == NULL){
            return;
        }
        
        inorder(root -> left, v);
        v.pb(root -> val);
        
        inorder(root -> right, v);
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vt<int> t1, t2, res;
        
        inorder(root1, t1);
        
        inorder(root2, t2);
        
        int i = 0, j = 0;
        
        while(i < t1.size() && j < t2.size()){
            if(t1[i] < t2[j]){
                res.pb(t1[i++]);
            } else {
                res.pb(t2[j++]);
            }
        }
        
        while(i < t1.size()){
            res.pb(t1[i++]);
        }
        
        while(j < t2.size()){
            res.pb(t2[j++]);
        }
        
        
        return res;
        
        
    }
};