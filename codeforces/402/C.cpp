/// 147 -uva - by ahmed_drawy 28/09/19
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v));
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
#define debug(x) cerr << x<<endl;
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}
int MOD = 1e9 +7;
int mod(ll x){
    return (x%MOD + MOD)%MOD;
}
long long add(long long x, long long y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}
ll multipy(ll x , ll y ){
    return ((x%MOD) *(y%MOD))%MOD;
}
//const int N = 10 + 3;
//ll dp[N][N];
//int row[N];
//int col[N];
//int n ;
//ll solve (int s , int e ){
//    if(s==e)
//        return 0 ;
//    ll &ret = dp[s][e];
//    if(~ret)
//        return ret;
//    ret = LONG_LONG_MAX;
//    for (int i = s+1; i <e ; ++i) {
//        if(col[i+1] == row[e] && row[s]==col[i])
//            ret = min(ret , solve(i+1,e) + solve(s, i) + (row[i]*col[s] *col[i])  + (row[i+1]*col[e]*row[e]));
//    }
//
//
//}
//void build(int s, int e){
//    if(s==e)
//        return  ;
//    ll &ret = dp[s][e];
//    if(~ret)
////        return ret;
//    ret = LONG_LONG_MAX;
//    for (int i = s; i <e ; ++i) {
//        if(col[i+1] == row[e] && row[s]==col[i])
//            ret = min(ret , solve(i+1,e) + solve(s, i) + (row[i]*col[s] *col[i])  + (row[i+1]*col[e]*row[e]));
//    }
//
//
//
//}
int main() {
    smile();
    int t;  cin >> t;
    while (t--){
        int n , p ; cin >> n >> p ;

        for (int i = 1 , cnt = 0 ; i <=n && cnt <2*n + p; ++i) {
            for (int j = i+1  ; j <=n && cnt <2*n + p; ++j, cnt++) {
                cout << i << " "<<j<<endl;

            }
        }

    }
}
