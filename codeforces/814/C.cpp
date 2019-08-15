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

int main() {
    smile();
    int n , q ; cin >> n ;
    string s ; cin >>s;
    map <char , vector <int  > >mmap ;
    map <char , vector <int  > >ansmap ;
    lp(i,0, n){
        mmap[s[i]].push_back(i);
    }

    for(auto it : mmap){ /// n*n only because if we have n in the map we will have 1s in every vector in map

        auto curr = it.second;
        if(curr.size( ) == 1){
//            cout << min(m + 1 , n )<<endl;
            continue;
        }
        for (int i = 1; i <=n ; ++i) {
            int mx = 0 ;

            for (int j = 0; j < curr.size(); ++j) {
                int temp = i;
                for (int k = j + 1; k < curr.size();++k) {
                    int diff = curr[k] - curr[k - 1] - 1;
                    if (temp >= diff) {
                        /// take the diff -1 and +1 then add 1 in the last

                        temp -= diff;
                        mx = max(mx, min(n, i + (k - j) + 1));
                    } else {
                        mx = max(mx, min(n, i + (k - j)));
                        break;
                    }

                }


            }
            ansmap[it.first].push_back(mx);
        }

    }
    cin >> q;
    lp(i,0,q){
        int m ; char c ; cin >> m >> c ;
        if(mmap[c].size() == 0 ){
            cout << min(m, n) << "\n";
            continue ;
        }
        else  {

            int mx = 0 ;
            auto curr = mmap[c];
            if(curr.size( ) == 1){
                cout << min(m + 1 , n )<<endl;
                continue;
            }
            cout<<ansmap[c][m-1]<<"\n";
        }
    }
}