//
// Created by ahmed_drawy on 22/08/19.
/// educational contest 71
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
ll mod = 998244353;
void add(long long &x, long long y){
    x += y;
    while(x >= mod)
        x -= mod;
    while(x < 0)
        x += mod;
//    return x;
}
ll multipy(ll x , ll y ){
    return ((x%mod) *(y%mod))%mod;
}

ll fact [300005];
void factorial(ll n ){
    fact[0] = 1;
    for (ll i = 1; i <=n ; ++i) {
        fact[i] = multipy(fact[i-1] , i);
    }
    
}

int main() {
    smile();
    ll n  ; cin >> n ;
    map<int , ll > amap;
    map<int , ll > bmap;
    map<pair<int , int > , ll > pairmap;
    factorial(n);
    vector<pii> mvec;
    lp(i,0,n){
        int x , y;
        cin >> x >> y;
        amap[x]++;
        bmap[y]++;
        pairmap[{x,y}]++;
        mvec.push_back({x,y});
    }
    ll minus1 = 1 ;
    ll minus2 = 1 ;
    for (auto it : amap) {
        minus1 =multipy(minus1 , fact[it.second]);
    }for (auto it : bmap) {
        minus2 =  multipy(minus2 , fact[it.second]);
    }
    ll plus = 1 ;
    for (auto it : pairmap) {
        plus =  multipy(plus , fact[it.second]);
    }
    sort(mvec.begin(), mvec.end());
    bool no = 1;
    lp(i,1,n){  /// if both first and second are sorted  ascending then there's intersection we have to remove it
        if(mvec[i].second< mvec[i-1].second){
            no =0 ;
            break;
        }
    }
    plus *=no;
    ll ans = fact[n];
    add(ans , -minus1);
    add(ans , -minus2);
    add(ans , plus);

    cout<< ans;


}