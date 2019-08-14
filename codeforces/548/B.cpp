//
// Created by ahmed_drawy on 14/08/19.
// 548B - c1  sheet
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
int arr[505][505];
int ans[505];
int main() {
    smile();
    int n , m , q ; cin >> n >> m>>q ;
    lp(i,0,n){
        int curr = 0 ;
        lp(k,0,m){
            cin >> arr[i][k];
            if(arr[i][k]){
                curr++;
                ans[i] = max(curr , ans[i]);
            }
            else
                curr = 0 ;

        }

    }
    lp(i,0,q){
        int x , y; cin >> x >>y;
        x-- , y--;

        arr[x][y] = !arr[x][y];
        int curr = 0  ;
        ans[x] = 0 ;
        lp(k,0,m){

            if(arr[x][k]){
                curr++;
                ans[x] = max(curr , ans[x]);
            }
            else
                curr = 0 ;

        }

        int ret = 0;
        lp(j,0,n)ret = max(ret , ans[j]);

        cout << ret<<"\n";
    }
}