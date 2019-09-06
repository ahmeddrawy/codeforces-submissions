//
// Created by ahmed_drawy on 03/09/19.
/// Educational Codeforces Round 72 (Rated for Div. 2)
#include <bits/stdc++.h>
#include <string.h>
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
//#define dbg (v)    for(auto it : v)cout<<it<<' ';
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
#define endl '\n'
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
vector<pair<int , int> >g[5005];
//bool visited[5005];
int parent[5005] ;
int cnt =0;
vector<int > path(5005);
void dfs(int x ){

    parent[x] = 1;

    for (auto it : g[x]){
        auto v = it.first , indx = it.second;
        if(parent[v] == 1){ /// node opened and not finished

            cnt =1 ;
            path[indx] = 2;
        }
        else if(parent[v]  == 0 ){
            dfs(v);
            path[indx] = 1;
        }
        else {/// visited before and finished
            path[indx] = 1;
        }
    }
    parent[x] = 2; ///finished and no cycle
}
int main() {
    smile();


    int n , m ; cin >> n >> m ;

    lp(i,0,m){
        int u , v ;cin >> u>>v;
        --u , --v;
//        start[u] =1;
        g[u].push_back({v,i});
    }
    int ans = 1;
    lp(i,0,n){

        if(parent[i] == 0 )
            dfs(i);

    }
    if(cnt >0)cout<<2<<endl;
    else cout << 1<<endl;
    for(int i = 0 ; i < m ; ++i)cout << path[i] << " ";

}