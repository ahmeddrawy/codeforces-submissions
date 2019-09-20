#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
const int N = 3e5 +3 ;
ll dp[N][11];
int  visited[N][10];
int id = 0 ;
ll a[N];
ll price[N];
int n ;
ll solve(int indx , ll prev = 0  ){
    if(indx == n ) {
        return 0;
    }
    ll &ret = dp[indx][prev];
    if(visited[indx][prev] == id)
        return ret;
    visited[indx][prev] = id ;
    ret=  (ll)1e18 -1;
    ll temp = 0 ;
    if(indx )
        temp = a[indx-1] + prev;
    for (ll i = 0; i <10 ; ++i) {
        if(a[indx]  + i != temp )
            ret = min(ret , price[indx] * i + solve(indx +1 ,i));
    }
    return ret;

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///
//    freopen("/home/tw3/Desktop/Desktop/training/in.txt" , "rt" , stdin);///
    int q ; cin >> q;
    while(q--){
      cin >> n;
        for (int i = 0; i <n ; ++i) {
            cin >> a[i] >> price[i];
        }
        id++;
//        memset(dp , -1 , sizeof dp );
        cout << solve(0 , 0 )<<endl;

    }
}