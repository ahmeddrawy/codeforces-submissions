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
int dp[3][N];
ll height ;
ll r , g ;
void up(){
    ll sum = (height*(height+1))/2;
    for (int j = 0; j <=g ; ++j) 
            dp[(height +1)&1][j] = 1;
    for (int H = height; H >=1 ; --H) {
        ll sum = ((H)*(H-1))/2;
        for (int usedGreen = 0; usedGreen <=g ; ++usedGreen) {
            ll usedRed = (sum - usedGreen);
            int &ret = dp[(H&1)][usedGreen] = 0;
            if (usedGreen + H <= g) {
                dp[(H&1)][usedGreen]  = add(dp[(H&1)][usedGreen] , dp[((H+1)&1)][usedGreen+H] );
            }
            if (usedRed + H <= r) 
                ret = add(ret, dp[(H+1)&1][usedGreen]);
        }
    }
    cout << dp[1][0];
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