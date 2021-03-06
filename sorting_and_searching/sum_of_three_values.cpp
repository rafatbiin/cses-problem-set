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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x ;
    
    pair<ll, ll> p[n+3] ;

    for(int i = 0 ;i<n ; i++){
        cin >> p[i].first ;
        p[i].second = i+1 ;
    }

    sort(p, p+n) ;

    for(int i = 0 ; i<n ;i++){
        ll temp = x - p[i].first ;
        int k = i+1, j = n-1 ;
        while(k<j){
            if(p[k].first + p[j].first == temp){
                cout << p[i].second << ' ' << p[k].second << ' ' << p[j].second << endl ;
                return 0 ;
            }
            if(p[k].first+p[j].first>temp)j-- ;
            else k++ ;
        }
    }

    cout <<"IMPOSSIBLE"<<endl;

    return 0 ;
}