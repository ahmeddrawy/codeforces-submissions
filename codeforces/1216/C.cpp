///Codeforces Round #587 (Div. 3)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
struct Point {
    ll x, y;
    Point(){
        x = 0 , y= 0 ;
    }
};
ll overlapping(Point l1, Point r1,Point l2, Point r2 , Point & p5 , Point &p6){
    if((min(r1.x, r2.x) -max(l1.x, l2.x)) <= 0 )
        return 0 ;
    if (min(r1.y, r2.y) - max(l1.y, l2.y)<= 0 )
        return 0 ;
    ll areaI = (min(r1.x, r2.x) -max(l1.x, l2.x)) *
                (min(r1.y, r2.y) - max(l1.y, l2.y));
    p5.x = max(l1.x , l2.x);
    p6.x = min(r1.x , r2.x);
    p5.y = max(l1.y , l2.y);
    p6.y = min(r1.y , r2.y);
    if(areaI <=0 )
        return 0 ;
    return areaI;
}
int main(){
    smile();
    Point  p1,p2 ,p3,p4,p5,p6;
    cin >> p1.x>>p1.y;
    cin >> p2.x>>p2.y;
    cin >> p3.x>>p3.y;
    cin >> p4.x>>p4.y;
    cin >> p5.x>>p5.y;
    cin >> p6.x>>p6.y;
    ll area = abs(p1.x - p2.x) *abs(p2.y - p1.y);
    Point p7 , p8 ;
    Point p9 , p10 ;
    ll over1 = overlapping(p1,p2, p3,p4, p7 , p8);
    ll over2 = overlapping(p1,p2, p5,p6, p9 , p10);
    ll over3 = 0 ;
    if(over1 != 0 && over2 != 0)
        over3 = overlapping(p7,p8, p9,p10, p5 , p6);
    if(over1 + over2 - over3 < area){
        cout << "YES"<<endl;
    }
    else cout <<"NO"<<endl;
}