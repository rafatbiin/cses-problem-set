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

    ll n, x , curr_sum = 0 , count = 0 ,temp, l ;

    cin >> n >> x ;

    for(int i = 0 ;i<n ;i++)cin >> a[i] ;

    map<ll,ll> mp ;

    for(int i = 0 ;i<n; i++){
        curr_sum = curr_sum + a[i] ;

        if(curr_sum == x)count++ ;
        // if(mp.find(curr_sum -x) != mp.end()) count += mp[curr_sum-x] ;
        auto it = mp.find(curr_sum-x) ;
        if(it!=mp.end()) count+=it->second ;
        mp[curr_sum]++ ;
    }

    cout << count << endl ;
    


    return 0 ;
}