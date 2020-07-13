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
int client[N] ;
bool visited[N] ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b ;
    cin >> n ;
    pair<pair<int,int>, int> p[n+3] ;

    for(int i = 0 ;i<n ; i++){
        cin >> a >> b ;
        p[i].first.first = b ;
        p[i].first.second = a ;
        p[i].second = i ;
    }

    sort(p, p+n) ;
    multiset<pair<int,int>> time{{0,1}} ;

    int count = 1 ;

    for(int i = 0 ;i<n ;i++){
        auto it = time.upper_bound({p[i].first.second,INF}) ;
        if(it == time.begin()){
            count++ ;
            client[p[i].second] = count ;
            time.insert({p[i].first.first+1, count}) ;
        }else {
            it-- ;
            client[p[i].second] = it->second ;
            time.insert({p[i].first.first+1, it->second}) ;
            time.erase(it) ;
        }
    }
    cout << count << endl ;
    for(int i = 0 ;i<n ; i++)cout << client[i] << ' ' ;
    

    return 0 ;
}