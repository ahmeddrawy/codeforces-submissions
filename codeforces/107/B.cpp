/// ACM-ICPC-Swiss-Subregional 2017 - by ahmed_drawy 16/10/19
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
template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}
long long power(long long base, ll exp)
{
    if (!exp)
        return 1LL;
    ll sq = power(base, exp/2);
    sq = multipy(sq , sq);
    if (exp&1)
        sq = multipy(sq , base);
    return sq;
}
double distance (ll x , ll y  , ll z){

    return sqrt(x*x + y*y + z*z);
}
struct point{
    int x = 0 , y= 0 , z = 0 ;
    point(int _x= 0   , int _y = 0  , int _z = 0){
        x =_x;
        y =_y;
        z =_z;
    }

};
bool sortfunction1( const pair <int, pair <int , int >> &a ,const pair <int, pair <int , int >>&b){
    return a.second.first != b.second.first? a.second.first< b.second.first : a.second.second!=b.second.second? a.second.second<b.second.second: a.first<b.first;
}
bool sortfunction2(pair <int, pair <int , int >> &a , pair <int, pair <int , int >>&b){
    return  a.second.second!= b.second.second? a.second.second< b.second.second :a.second.first!=b.second.first?a.second.first<b.second.first: a.first <b.first ;
}
//int n ,  p ;
long double ncr[1000*100][100];
long double binomial_coefficient(int n,int r)
{
    if (n<r)return 0;
    if (r==0)return 1;
    if (ncr[n][r]==ncr[n][r])return ncr[n][r];
    return ncr[n][r]=binomial_coefficient(n-1,r-1)+binomial_coefficient(n-1,r);
}
int main() {
    smile();
    int n , m ,h  ;cin >> n >> m >> h;
    h--;
    vector<int >mvec(m);
    long double p = 0 ;
    ll total = 0 ;
    for (int i = 0; i <m ; ++i) {
        int &it = mvec[i];
        cin >> it;
        if(h==i)
            it--;
        else
            total +=it;
    }
    n--;
    if(mvec[h ] + total <n ) {
        cout << -1;
        return 0;
    }
    memset(ncr , -1, sizeof ncr);
    long double ret = binomial_coefficient(total + mvec[h] , n);

    cout << 1.0  - binomial_coefficient(total , n)/ret;

}