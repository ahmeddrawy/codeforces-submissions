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
bool can(int arr[3][3] , int res[3] , int c[3] , int d1 , int d2){

    int r1= res[0] + arr[0][0];
    int r2 =r1- res[1];
    int r3 =r1- res[2];
    if(r1 < 0 || r2 < 0)
        return false ;

    set<int > mset;
    mset.insert(r1);
    mset.insert(r2 + res[1]);
    mset.insert(r3 + res[2]);
    mset.insert(d1+ arr[0][0] + r2  + r3);
    mset.insert(d2+ r2);
    if(mset.size() == 1){
        arr[1][1] = r2 ;
        arr[2][2] = r3;

        return true;
    }
    return false;
}
int main() {
    smile();
    int arr[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> arr[i][j];
        }
    }
    int res[3], c[3];
    for(int i = 0 ; i < 3 ;++i)c[i] = 0, res[i] = 0  ;
    int d1= 0 , d2 = arr[0][2] + arr[2][0]  + arr[1][1];
    for (int i = 0; i < 3; ++i) {
        d1+=arr[i][i];
        for (int j = 0; j <3 ; ++j) {
            res[i] +=arr[i][j];
            c[j] +=arr[j][i];
        }
    }
    for (int mid = 1; mid <= 1e5; ++mid) {
        arr[0][0] = mid;
        if (can(arr, res , c , d1, d2)) {
            break;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}