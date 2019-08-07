//
// Created by ahmed_drawy on 07/08/19.
// 651 C- c1 sheet
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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE

    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}
int n ;
int main() {
    smile();

    cin >> n;

    map <pii ,ll > pmap;
    map<int , ll > xmap;
    map<int , ll > ymap;
    lp(i,0,n){
        int x ,y;
        cin >> x;
        cin >> y;
        xmap[x]++;
        ymap[y]++;
        pmap[{x,y}]++;
//       mset.insert({x , y});
    }
    ll ans = 0 ;
    for(pii it : xmap){
        ans += (it.second*(it.second -1LL))/2LL;
    }
    for(pii it : ymap){
        ans += (it.second*(it.second -1LL))/2LL;
    }
    for(auto it : pmap){
        ans -= (it.second*(it.second -1LL))/2LL;
    }


    cout << ans ;
}