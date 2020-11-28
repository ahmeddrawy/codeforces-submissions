/// by ahmed_drawy 19/11/2020
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
//    freopen("out.txt" , "w" , stdout);
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
bool isPal (string s,int l , int sz) {
//    int sz = r-l +1 ;
    int r = l + sz ;
    for (int i = 0; i <sz/2 ; ++i) {
        if(s[i+ l] != s[(sz - 1 - i)+l]){
            return false;
        }
    }
    return true ;
}
bool solve(string s , int len ){
    string tmp ="";
    int l = 0 , r = len -1 ;
    for (int i = 0; i <s.size() ; ++i) {
        if(tmp.size() <len){
            tmp+=s[i];
            continue;
        }
        if(isPal(tmp,l,len) && len%2==0){
//            string t = tmp.substr(i-len +1 ,len);
//            cout << isPal(t,0,len) << endl;
//            cout << t << endl;
            return false ;
        }
        tmp+=s[i];
        l++;

    }
    return true ;
}
bool hasZero(int n ){
    while(n){
        if(n%10 ==0 ){
            return 1;
        }
        n/=10;
    }
    return 0 ;
}
//int k , p ,x ;
//double calcualate(int m){
//    return x*m + ((k*1.0)/m *p);
//}
//int n ;
//void gen(int x, int y){
//    cin >> n ;
//    int r= 0 ,c = 0 ;
//
//    for (int i = n; i >0 ; ) {
//        for (int j = 0; j < x && i>0; ++j,i--) {
//            if(j==0)r++;
//        }
//        for (int j = 0; j < y && i>0; ++j,i--) {
//            if(j==0)c++;
//        }
//    }
//    cout << r << " " << c << endl;
//}
vector<int > factors(int n ){
    vector<int >ret ;
    for (int i = 1; i*i <=n ; ++i) {
        if(n%i == 0 ){
            ret.push_back(i);
            if(n/i != i)
                ret.push_back(n/i);
        }
    }
    return ret;
}
void printVec(vector<int >vec){
    for(auto it : vec)
        cout << it << " ";
    cout << endl;
}

void solve(){
  int n ; cin >> n ;
  int print = 0 ;
    for (int i = n , j = 1 ; i >0 ; --i, j++) {
        if(i == j ){
            cout << i-1 << " ";
            print = 1;
            continue ;
        }
        if(print == 1 ){
            cout << i+print << " ";
            print = 0 ;     
        }
        else
        cout << i << " ";
    }cout << endl;
}
int main() {
    smile();
    int t  =1;
    cin >> t;
    while(t--)
        solve();

}