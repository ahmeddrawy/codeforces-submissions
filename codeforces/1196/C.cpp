
//
// Created by ahmed_drawy on 31/07/19.
//  #575 div3 upsolve B

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
struct dir{
    bool left = 0 ;
    bool right = 0 ;
    bool up = 0 ;
    bool down = 0 ;
};
int main() {
    smile();
    int q ;cin >> q;
    while(q--) {
        int n ; cin >> n  ;
        vector<pair <pii , int> >pt(n);
        map<int , dir> mmap;
        lp(i,0,n){
            int x , y ;cin >> x >> y;
            pt[i].first.first = x;
            pt[i].first.second = y;
            pt[i].second = i;
            cin>> mmap[i].left >>mmap[i].up>>mmap[i].right>>mmap[i].down;
        }
        sort(pt.begin() , pt.end());
        bool breaked= 0;
        int lx = pt[n-1].first.first;
        lp(i,0,n){
            if(!mmap[pt[i].second].right){
                for (int j = i+1; j <n ; ++j ) {
                    if(!mmap[pt[j].second].left){

                        breaked=1;
                        break;
                    }
                }
                if(pt[i].first.first == lx)breaked=0;
                lx = pt[i].first.first;
                break;
            }
        }
        if(breaked){
            cout<<"0"<<endl;
            continue;
        }
        lp(i,0,n){
            swap(pt[i].first.first ,pt[i].first.second);
        }
        sort(pt.begin() , pt.end());
        breaked= 0;
        int ly = pt[n-1].first.first;
        lp(i,0,n){
            if(!mmap[pt[i].second].up){
                for (int j = i+1; j <n ; ++j ) {
                    if(!mmap[pt[j].second].down){

                        breaked=1;
                        break;
                    }
                }
                if(pt[i].first.first == ly)breaked=0;
                ly =pt[i].first.first;
                break;
            }
        }
        if(breaked){
            cout<<"0"<<endl;
            continue;
        }
        cout<<"1 " <<lx <<" " << ly<<endl;



    }

}
