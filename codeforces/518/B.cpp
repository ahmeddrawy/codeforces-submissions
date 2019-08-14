//
// Created by ahmed_drawy on 14/08/19.
// 108 uva- dp  sheet
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

int main() {
    smile();
    string s , ns ; cin >> s >>ns ;
    map<char , int > newsmap ;
    map<char , int > resultmap ;
    lp(i,0,ns.size()){
        newsmap[ns[i]]++;
    }
    lp(i,0,s.size()){
        resultmap[s[i]]++;

    }
    int y = 0 , ops = 0 ;
    for (auto it  = resultmap.begin() ; it != resultmap.end() ; ++it) {
        int ans = min(newsmap[it->first] , it->second);
        y+=ans;

        newsmap[it->first] -=ans;
        it->second -=ans;

    }
    for (auto it  = resultmap.begin() ; it != resultmap.end() ; ++it) {
        if(it->second != 0 ) {
            if (it->first <= 'Z') {
                char curr = tolower(it->first);
                ops += min(resultmap[it->first], newsmap[curr]);
//                newsmap[curr] -= min(resultmap[curr], newsmap[curr]);
            } else {
                char curr = toupper(it->first);

                ops += min(resultmap[it->first],newsmap[curr]);
//                newsmap[curr] -= min(resultmap[curr], newsmap[curr]);
            }
        }

    }
    cout  << y << " "<< ops;


}