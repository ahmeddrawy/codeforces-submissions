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
    //freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
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
set<int > factors(int n ){
    set<int >ret;
//    ret.insert(n);
    for(int i = 1; i *i<=n; ++i)
        if(n%i ==0 ) {
            ret.insert(i);
            ret.insert(n/i);
        }
    return ret;
}
int n ;
const int N = 1e5+ 4;
int factor[N];
int sieve() {

    for (int i = 2; i * i < N; ++i) {
        if (factor[i])
            continue;
        for (int j = i * i; j < N; j += i)
            factor[j] = i;
    }
}
set<int> factorize(int x) {
    set<int> ret;
    int prev = -1;
    while (x > 1) {
        if (factor[x] == 0)
            factor[x] = x;
        ret.insert(factor[x]);
        x /= factor[x];
    }
    ret.insert(1);
    if(ret.find(2) !=ret.end())
        ret.insert(4);
    return ret;
}
bool can[N];
bool check (int indx,int step, int start){
    if(indx%n == start && indx>=n)
        return can[indx%n];
    if(can[indx])
        return check(indx+step , step, start);
    else return false ;

}
int chtoint(char c){
    return (10)+ c-'0' - 9 ;
}
int main() {
    smile();
    ll s2;
    string s1 ;cin >> s1  >> s2;
    reverse(s1.begin() , s1.end());
    ll cnt = 0 ;
    ll carry = 0 ;
    string res = "";
    for (int i = 0; i <sz(s1) ; ++i) {
        if(s1[i] !='9')
            cnt+=chtoint(s1[i] - carry)*pow(10,i);
        else cnt +=9*pow(10,i);
        if(cnt >s2){
            for (int j = i; j <sz(s1) ; ++j) {
                if(carry){
                    if(((char) s1[j] ) != '0'  ){
                        if(j==sz(s1) -1 ) {
                            if (s1[j] - 1 != '0')
                                res += s1[j] - 1;
                        }
                        else {
                            res += s1[j] - 1;
                        }
                        carry = 0 ;


                    }
                    else {
                        if(j!=sz(s1) -1)
                            res+='9';
                    }
                }
                else res+=s1[j];
            }
            break;
        }
        else {
            res =res+'9';
        }
        if(s1[i] !='9')
        carry = 1;
    }
    reverse(res.begin() , res.end());
    cout <<res;

}