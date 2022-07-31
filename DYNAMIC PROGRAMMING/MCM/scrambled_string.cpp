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

unordered_map<string, bool> m;
bool solve(string a, string b)
{
    if(a.length() != b.length())
    return false;
    if(a.compare(b) == 0)
    return true;

    string key = a + "#" + b;
    if(m.find(key) != m.end())
        return m[key];
    
    int n = a.length();
    bool no_swap_ff ,no_swap_ss, swap_ff, swap_ss, ans;
    ans = false;

    string temp;
    for(int k=1; k<= n-1; k++)
    {
        // no_swap = solve(a.substr(0, k), b.substr(0, k)) && solve(a.substr(k, n-k), b.substr(k, n-k));
        // swap = solve(a.substr(0, k), b.substr(k, n-k)) && solve(a.substr(k, n-k), b.substr(0, k));
        temp = a.substr(0, k) + "#" + b.substr(0, k);
        if(m.find(temp) != m.end())
        no_swap_ff =  m[temp];
        else
        no_swap_ff = solve(a.substr(0, k), b.substr(0, k));
        
        temp = a.substr(k, n-k) + "#" + b.substr(k, n-k);
        if(m.find(temp) != m.end())
        no_swap_ss =  m[temp];
        else
        no_swap_ss = solve(a.substr(k, n-k), b.substr(k, n-k));

        temp = a.substr(0, k) + "#" + b.substr(k, n-k);
        if(m.find(temp) != m.end())
        swap_ff =  m[temp];
        else
        swap_ff = solve(a.substr(0, k), b.substr(k, n-k));
        
        temp = a.substr(k, n-k) + "#" + b.substr(0, k);
        if(m.find(temp) != m.end())
        swap_ss =  m[temp];
        else
        swap_ss = solve(a.substr(k, n-k), b.substr(0, k));


        if((swap_ff && swap_ss) || (no_swap_ff && no_swap_ss))
            ans = true;
    }
    
    return m[key] = ans;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        m.clear();
        string a, b;
        cin >> a >> b;
        cout << "Case #" << it << ": ";
        solve(a, b);
    }
    return 0;
}