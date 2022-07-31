#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define rep(i, s, e) for (ll i = s; i < e; i++)
#define rrep(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 2e18
ll mod = 1e+9 + 7;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int l = nums.size();
        for(int i=0; i<l; i++)
        {
            if(i<k)
            {
                pair<int, int> t;
                t.first = nums[i];
                t.second = i;
                pq.push(t);
            }                
            else
                if(pq.top() < nums[i])
                {
                    pq.pop();
                    pair<int, int> t;
                    t.first = nums[i];
                    t.second = i;
                    pq.push(t);
                }
        }
        
        while(!pq.empty()){
            
            cout << pq.top().ff << " " << pq.top().ss << "\n";
            pq.pop();
        }
        
}
int main()
{
    fast_cin();
    solve();
    return 0;
}