#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
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
/// max 632 level
const int N = 2e5 +1;
int dp[N][3];
ll height ;
ll r , g ;
int solve(int level , int usedGreen , ll sum  = 0 ){
    ll usedRed  = (sum - usedGreen);
    if(usedGreen > g){
        return 0;
    }
    if(level > height){
        return 1 ;
    }
    int &ret = dp[level][usedGreen];
    if(~ret)
        return ret;
    ret = 0 ;
    if(usedGreen + level <= g){
        ret = add(ret, solve(level + 1, usedGreen + level , sum + level));
    }
    if(usedRed + level <= r){
        ret = add(ret,  solve(level +1, usedGreen , sum + level));
    }
    return ret;
}
void up(){
    ll sum = (height*(height+1))/2;

    int k= 0 ;
    dp[0][1] = 1;
    for (int h = 1; h <=height ; ++h) {
        ll currsum = ((h)*(h+1))/2;
        for (int i = 0; i <= g; ++i) {

            ll usedRed  = max ( 0ll , (currsum - i));
            dp[i][k] = 0 ;
            if(h<=i )
                dp[i][k] = add(dp[i][k] , dp[i-h][!k]);
            if(usedRed <= r)
                dp[i][k] = add(dp[i][k], dp[i][!k]);
        }
        k = !k;
    }
    ll a = 0 ;
    for (int j = 0; j <=g ; ++j) {
        a = add( a , dp[j][!k]);
    }
    cout  <<a;
}
int main(){
    smile();
    cin >> r>>g;
    ll a= 1, b= 1, c= -2*(r+g);
    height = max((-b+ sqrt(b*b -4*c*a))/2, (-b- sqrt(b*b -4*a*c)/2));
    memset(dp ,0 , sizeof(dp));
//    cout  << solve(1, 0 , 0 );
    up();
}