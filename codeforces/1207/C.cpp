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
ll dp[200005][3];
ll change , continuev , n;
string arr;
ll a , b;
    /// 1 change , 0 continue
ll solve(int indx , int state){
    if(indx == n-1){
        if(state == 1){
            return b+2*a;
        }
        return  b+a;
    }
    ll &ret = dp[indx][state];
    if(~ret )
        return ret;
    ret = 1ll<<60;
    if(arr[indx] == '0' && state == 0){
        ret = min(solve(indx +1 , 0) + (b+a), ret );
        ret = min(solve(indx +1 , 1) + (2*b + 2*a), ret);
    }
    if(arr[indx] == '0' && state  == 1){
        ret = min(solve(indx +1 , 1) + (2*b + a), ret );
        ret = min(solve(indx +1 , 0) + (b+2*a), ret);
    }
    if(arr[indx] == '1' && state == 0){ /// invalid
        ret = min(solve(indx +1 , 1) + (2*b + 2*a), ret);
        return ret = 1ll<<60;
    }
    if(arr[indx] == '1' && state == 1){
        ret = min(solve(indx +1 , 1) + (2*b + a), ret);
    }
    return ret;
}
int main() {
    smile();
    int t; cin >> t;
    while (t--){

        clr(dp , -1ll);


        cin>>n>>a>>b>>arr;
        cout<<solve(0,0) +b <<'\n';

    }

}