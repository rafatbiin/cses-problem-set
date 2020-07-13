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


void rebalance(){
    if((int)bottom.size() - (int)top.size() > 1){
        auto p = *--bottom.end() ;
        top.insert(p) ;
        bottom.erase(p) ;
    }
    else if((int)top.size() - (int)bottom.size() >1 || bottom.empty()){
        auto p = *top.begin() ;
        bottom.insert(p) ;
        top.erase(p) ;
    }
}

void add(pii x){
    if(bottom.empty() || x.first < (*--bottom.end()).first){
        bottom.insert(x) ;
    }else{
        top.insert(x) ;
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
    }else top.erase(x) ;

    rebalance() ;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k ;
    cin >> n >> k ;

    for(int i = 0 ;i<n ;i++)cin >> a[i] ;
    if(k == 1){
        for(int i = 0; i<n ;i++){
            cout <<a[i] << ' ' ;
        }
        return 0 ;
    }

    for(int i = 0 ;i<k-1 ;i++){
        add({a[i],i}) ;
    }
    for(int i =k -1 ;i<n ;i++){
        add({a[i],i}) ;
        cout << getMedian() << ' ' ;
        rm({a[i-k+1], i-k+1}) ;
    }

    

    return 0 ;
}