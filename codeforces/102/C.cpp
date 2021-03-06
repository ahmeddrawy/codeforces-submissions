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
ll a , b ;
bool can(ll mid,ll diff){
    ll res = (mid*(mid+1))/2;
    return  res>= diff && diff%2 == res%2 ;
}
void solve(){
     cin >> a >> b;
    ll l = 0 , r= 1e9;
    ll diff = abs(a-b);
    if(diff == 0) {
        cout << 0 << endl;
        return;
    }
    bool yes= false;
    int i = 0;
    for(; i < 1e5 && !yes ; ++i){
        yes |=can(i,diff);
    }
    cout << i-1<< endl;

}
int main() {
    smile();
//    int t ; cin >> t;
//    while(t--)
//        solve();
    string s ; cin >> s;
    int k ; cin >> k;
    map <char, int > mmap ;
    for(auto c : s)
        mmap[c]++;
    vector<pair<int, char> >vec;
    for(auto c : mmap){
        vec.push_back({c.second , c.first});
    }
    sort(vec.begin(), vec.end());
    bool yes = false ;
    for(int  i = 0 ; i < vec.size() && !yes ; ++i){
        if(vec[i].first <= k){
            k-=vec[i].first;
            vec[i].first = 0 ;
        }
        else  {
            yes = true ;
        }
    }
    map <char , bool > mms;
    for(auto c : vec){
        if(c.first !=0)mms[c.second] = 1;

    }
    cout << mms.size() << endl;
    for(int i = 0 ; i < s.size();  ++i){
        if(mms[s[i]]){
            cout<<s[i];
        }
    }
}