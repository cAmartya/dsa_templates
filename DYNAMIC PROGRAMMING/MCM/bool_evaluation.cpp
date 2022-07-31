#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define _USE_MATH_DEFINES
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

int dp[1001][1001][2];
int solve(string s, int i, int j, bool val)
{
    if(i>j)
        return 0;
    if(i == j)
    {
        if(val)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    if(dp[i][j][val] != -1)
        return dp[i][j][val];

    int ans=0, LF, LT, RF, RT;
    for(int k=i+1; k<= j-1; k+=2)
    {
        if(dp[i][k-1][false] != -1)    
        LF = solve(s, i, k-1, false);
        else
        LF = dp[i][k-1][false];
        
        if(dp[k+1][j][false] != -1)    
        RF = solve(s, k+1, j, false);
        else
        RF = dp[k+1][j][false];
        
        if(dp[i][k-1][true] != -1)    
        LT = solve(s, i, k-1, true);
        else
        LT = dp[i][k-1][true];
        
        if(dp[k+1][j][true] != -1)    
        RT = solve(s, k+1, j, true);
        else
        RT = dp[k+1][j][true];

        
        if(s[k] == '|')
            if(val)
                ans += LF*RT + LT*RF + LT*RT;
            else
                ans += LF*RF;
        
        else if(s[k] == '&')
            if(!val)
                ans += LF*RT + LT*RF + LF*RF;
            else
                ans += LT*RT;
        
        else
            if(val)
                ans += LF*RT + LT*RF ;
            else
                ans += LT*RT + LF*RF;       
    }

    return dp[i][j][val] = ans;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        string s;
        int l;

        cin >> l;
        cin >> s;
        cout << "Case #" << it << ": ";
        solve(s, 0, l-1, true);
    }
    return 0;
}