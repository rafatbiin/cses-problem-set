#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 1111111
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

vector<int> g[N] ;
int a[N] ;
bool visited[N] ;

set<pii> top, bottom ;
ll sum_top = 0LL, sum_bottom = 0LL ;


void rebalance(){
    if((int)bottom.size() - (int)top.size() > 1){
        auto p = *--bottom.end() ;
        top.insert(p) ;
        sum_top+=p.first ;
        bottom.erase(p) ;
        sum_bottom-=p.first ;
    }
    else if((int)top.size() - (int)bottom.size() >1 || bottom.empty()){
        auto p = *top.begin() ;
        bottom.insert(p) ;
        sum_bottom+=p.first ;
        top.erase(p) ;
        sum_top-=p.first ;
    }
}

void add(pii x){
    if(bottom.empty() || x.first < (*--bottom.end()).first){
        bottom.insert(x) ;
        sum_bottom+=x.first ;
    }else{
        top.insert(x) ;
        sum_top+=x.first ;
    }

    rebalance() ;
}


int getMedian(){
    if((int)bottom.size() >= (int)top.size()){
        return (*--bottom.end()).first ;
    }
    return (*top.begin()).first ;
}

void rm(pii x){
    if((*--bottom.end()) >= x){
        bottom.erase(x) ;
        sum_bottom-=x.first ;
    }else{
        top.erase(x) ;
        sum_top-=x.first ;
    }

    rebalance() ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k , median;
    cin >> n >> k ;

    for(int i = 0 ;i<n ;i++)cin >> a[i] ;
    if(k == 1){
        for(int i = 0; i<n ;i++){
            cout <<0 << ' ' ;
        }
        return 0 ;
    }

    for(int i = 0 ;i<k-1 ;i++){
        add({a[i],i}) ;
    }
    for(int i =k -1 ;i<n ;i++){
        add({a[i],i}) ;
        median = getMedian() ;
        cout << abs(sum_bottom - (ll)bottom.size()*median) +
            abs(sum_top - (ll)top.size()*median) << ' ' ;
        rm({a[i-k+1], i-k+1}) ;
    }
    return 0 ;
}