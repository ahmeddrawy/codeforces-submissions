/// by ahmed_drawy 15/03/20
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
#define vi vector<int>
#define   endl '\n'
#define debug(x) cerr << x<<endl;
const double EPS = (1e-7);
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}

ll MOD =(ll) 1e9 +7 ;
int mod(ll x){
    return (x%MOD + MOD)%MOD;
}
long long add(long long x, long long y){
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
long long power(long long base, int exp){
    if (!exp)
        return 1LL;
    ll sq = power(base, exp/2);
    sq = (sq * sq)%MOD;
    if (exp&1)
        sq = (sq * base)%MOD;
    return sq;
}
bool compareT(pair<int , int > & a , pair<int  ,int > &b){
    if(a.first != b.first)
        return a.first <b.first ;
    return a.second< b.second ;
}
double dist(int x , int y , int a , int b) {
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));

}
int dp[200005][10];
int visited[200005][10];
int arr[200005];
int ans[200005];
int turn = 1 ;
int n ;
int solve(int indx , bool color){
    if(indx == n ){
        return color + 1 == 2  && arr[0] !=arr[n-1];/// because first one will always colored in 2
    }
    int &ret = dp[indx][color];
    if(visited[indx][color] == turn)
        return ret;
    visited[indx][color] = turn;
    ret= INT_MAX ;
    ret= min(ret , solve(indx+1 , !color));
    if(arr[indx]==arr[indx-1]){
        ret = min(ret , solve(indx+1 , color));
    }
    return ret;


}
void build(int indx , bool color){
    if(indx == n ){
        if(color + 1 == 2 && arr[0] != arr[n-1]){
            ans[n-1] = 3;
        }
        return  ;/// because first one will always colored in 2
    }
    if(arr[indx] !=arr[indx-1]){
        ans[indx] = !color  +1;
        build(indx+1, !color);
    }
    else {
        int mn1 = solve(indx+1 , !color);
        int mn2 = solve(indx+1 , color);
        if(mn1 < mn2){
            ans[indx] = !color+1;
            build(indx +1 , !color);
        }
        else{
            ans[indx] = color+1;
            build(indx+ 1 , color);
        }
    }


}

void solve(){
    cin >> n ;
    set<int> mset;
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
        mset.insert(arr[i]);
    }
    if(mset.size() == 1){
        cout << 1 << endl;
        for (int i = 0; i <n ; ++i) {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else {
        //clr(dp , -1 );
        cout <<2+ solve(1, 1)<<endl;
        ans[0] = 2;
        build(1,1);
        for (int i = 0; i <n ; ++i) {
            cout << ans[i] << " ";
        }
        cout  << endl;
        turn++;
    }
}
int main() {
    smile();
    int t ; cin >> t;
    while(t--)
        solve();
}