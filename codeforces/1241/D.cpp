/// 147 -uva - by ahmed_drawy 28/09/19
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


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

int MOD ;
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
const int N = 3e5 + 4;
int n ;
int  arr[N];
int dp[N];
int l[N];
int r[N];

int main() {
    smile();
    int q ; cin >> q;
     while(q-- ) {
//         int n;
         cin >> n;
         vector<int > v(n);
         for (int j = 0; j <n ; ++j) {
             l[j] = 1e9 ;
             r[j] = 0 ;
         }
//         memset(dp , 0 , sizeof(dp));
         for (int i = 0; i <n ; ++i) {
             int x ; cin >> x; --x;
             arr[i] = v[i] =x;

             l[arr[i]] = min(i , l[arr[i]]);
             r[arr[i]] = max(r[arr[i]] , i);
         }
         sort(v.begin() , v.end());
         v.erase(unique(v.begin() , v.end()) , v.end());
         int res= n ;
         for(int i = v.size() - 1; i >= 0; --i){
             if(i + 1 ==sz(v) || r[v[i]] >= l[v[i + 1]])
                 dp[i] = 1;
             else
                 dp[i] = 1 + dp[i + 1];
             res = min(res, int(v.size())- dp[i]);
         }
         cout <<  res <<endl;

     }
}