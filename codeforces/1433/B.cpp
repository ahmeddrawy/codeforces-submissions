/// by ahmed_drawy 29/06/2020
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
    freopen("in.txt", "r", stdin);
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
ll multipy(ll x , ll y  , ll mod){
    return ((x%mod) *(y%MOD))%mod;
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
bool compareT(pair<pair<int , int > ,int>  & a , pair <pair<int  ,int > , int > &b){
    if(a.first.first != b.first.first)
        return a.first.first >b.first.first ;
    return a.first.second< b.first.second ;
}
double dist(int x , int y , int a , int b) {
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
int countD(int n ){
    if(n== 0)
        return 0 ;
    return 1 + countD(n/10);
}

void solve(){
   int n ; cin >> n ;
   vector<int >vec(n);
   int fst = -1 , lst = -1 ;
    for (int i = 0; i <n ; ++i) {
        cin >> vec[i];
        if(fst == -1 && vec[i] ){
            fst = i ;
        }
        else if(vec[i]){
            lst = i;
        }
    };
    int cnt = 0;
    if(lst == -1){
         cout << 0 << endl;
        return;
    }
    for (int i = fst; i <lst ; ++i) {
        cnt += vec[i]==0;
    }
    cout << cnt << endl;

}

int main() {
    smile();
    int t  =1;
    cin >>  t;
    while(t--)
        solve();

}