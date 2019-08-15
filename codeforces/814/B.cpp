//
// Created by ahmed_drawy on 15/08/19.
// virtual contest sheet
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
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}
int a[1001], b[1001] , ans[1001];
int main() {
    smile();
    int n ; cin >> n ;
    inN(a , n );
    inN(b , n );
    map<int , int > mmap;
    int left = 0 ;
    lp(i,0,n){
        if(a[i] == b[i] ){
            ans[i] = a[i];
            mmap[a[i]]++;
        }
        else left++;

    }
    lp(i,0,n){
        if(a[i] != b[i]){
            if(mmap[a[i]] && !mmap[b[i]]){
                ans[i] = b[i];
                mmap[b[i]]++;
                left--;
            }
            else if(mmap[b[i]] && !mmap[a[i]]) {
                ans[i] = a[i];
                mmap[a[i]]++;
                left--;
            }
        }
    }

    vector <int > lvec;
    for (int j = 1; j <=n ; ++j) {
        if(!mmap[j])
            lvec.push_back(j);
    }
    if(left) {
        int j = 0;
        lp(i, 0, n) {
            if (a[i] != b[i] && left) {
                ans[i] = lvec[j++]; left-- ;
            }
        }
    }


    for (int k = 0; k <n ; ++k) {
        cout <<ans[k]<<" ";
    }
}