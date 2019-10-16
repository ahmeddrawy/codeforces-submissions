///codeforces global round 5 - by ahmed_drawy 16/10/19
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
///ceil and floor in negatives are reversed
/// -5/2 is ceiled to -2 , we can -1 if we want to adjust it

int main() {
    smile();
    int n ; cin >> n;
    ordered_set<int>  s ;
    map <int ,  int >mmap;
    for (int i = 0; i <n ; ++i) {
        int x ; cin >> x;
        mmap[x] = i;
    }
    vector<int >q(n);
    for (int j = 0; j < n; ++j) {
        int x ; cin >> x;
        q[j]= mmap[x];
    }
    int cnt = 0 ;
    for (int k = n-1; k >=0 ; --k) {
        int y = s.order_of_key(q[k]);
        if(y>0)
            cnt++;
        s.insert(q[k]);
        cerr<< y <<endl;
    }
    cout << cnt << endl;
}