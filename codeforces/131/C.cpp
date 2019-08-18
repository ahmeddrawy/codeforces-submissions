//
// Created by ahmed_drawy on 17/08/19.
// virtual contest Educational Codeforces Round 70
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))

#define inf 0x3f3f3f3f
typedef long long               ll;
//typedef first                    ft;
//typedef second                   sd;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;
ll mod(ll x) {
    return (x%modul + modul)%modul;
}
//       6 - seive - prime factorization
const int N = 100;
ll factor[N];
/**
 * power in O(log p)
 * 10^16 = 10^8 * 10^8
 * 10^17 = 10^8 * 10^8 * 10
 */
ll power (ll b , int p ){
    if(p == 0 )return  1;
    int sq = pow(b , p/2);
    sq *=sq;

    if(p&1 )sq *=b; /// if odd

    return  sq ;

}
void sieve() {
    for (ll i = 2; i * i < N; ++i) {
        if (factor[i])
            continue;
        for (ll j = i * i; j < N; j += i)
            factor[j] = i;
    }
}
void factorize(ll x , map<ll , int > & mmap) {

    while (x > 1) {
        if (factor[x] == 0)
            factor[x] = x;
        mmap[factor[x]]++;

        x /= factor[x];
    }

}
void ncr(ll x, ll n , map<ll , int > &upmap, map<ll , int > &downmap ){
    for (ll i = n; i >0 ; --i) {    /// n!
        factorize(i , upmap);
    }
    for (ll i = x; i >0 ; --i) {    /// x!
        factorize(i ,downmap);
    }
    for (ll i = n-x; i >0 ; --i) {    ///( n-x)!
        factorize(i ,downmap);
    }
}
void avoidoverflowutility(map<ll , int > &upmap, map<ll , int > &downmap){
    for (auto it = upmap.begin() ; it!=upmap.end() ; ++it){
        if(downmap[it->first]){
            if(upmap[it->first]<=downmap[it->first]){
                downmap[it->first] -= it->second    ;
                it->second = 0;
            }
            else {
                it->second -=downmap[it->first];
                downmap[it->first] = 0 ;
            }

        }

    }
}
ll solve (map<ll , int > &upmap, map<ll , int > &downmap){
    ll num = 1 , denum  = 1;
    avoidoverflowutility(upmap , downmap);
    for( auto it : upmap)
        num *= power(it.first , it.second);
    for( auto it : downmap)
        denum *=power(it.first , it.second);
     return num/denum;

}
ll binomialCoeff(int n, int k)
{
    ll res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
int main() {
    smile();
    ll n , m , t; cin >> n >> m >> t;
    /// solve nCx * mCy for all x and y
    ll ans = 0;
    map<ll , int> upmap;
    map<ll , int> downmap;
    sieve ();
     ll ans2 = 0 ;
    for (int x = 4; x <= min( n , t-1)  ; ++x) {
        int y = t - x;
        if (y > m) continue;

        ncr(x, n, upmap, downmap);
        ncr(y, m, upmap, downmap);
        ans2 += solve(upmap, downmap);
//            ans+=(binomialCoeff(n,x) *binomialCoeff(m,y));
        upmap.clear();
        downmap.clear();
    }
    cout<<ans2;
//    cout<<ans;

}