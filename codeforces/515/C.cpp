
//
// Created by ahmed_drawy on 02/08/19.
//  515C

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
//typedef first                    ft;
//typedef second                   sd;
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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE

    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}
///max +ve number by factorize what can be factorized to make a larger number
vector<int > fact(int x) {
    vector<int >ret;
    for (int i = 2; i*i <=x ; ++i) {
        if(x%i == 0 )ret.push_back(i),ret.push_back(x/i);
    }
    return ret;
}
int main() {
    smile();
    int n ; cin >> n ;
    map<int , int> mmap;
    string s ; cin >> s;
    lp(i,0,n){
        for (int j = s[i]- '0'; j >1 ; --j) {///getting factorial
            mmap[j]++;
        }
    }

    for(int k  = 9 ; k > 1 ; ) {
        if(!mmap[k]){
            k--;
            continue;
        }
        vector<int > r = fact(k);
        if(r.size() == 0) {
            cout<<k ;
            for (int j = k; j >1 ; --j) {///getting factorial
                mmap[j]--;
            }
        }
        else{
            mmap[k]--;
            for (auto itt : r) {
                mmap[itt]++;

            }
        }
    }
}
