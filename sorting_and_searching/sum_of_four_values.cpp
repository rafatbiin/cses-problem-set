#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x, val) memset((x), (val), sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define N 1111111
#define M 1000000007
#define endl "\n"

const int INF = 1 << 30;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> g[N];
int a[N];
bool visited[N];

bool noCommon(pair<int, pii> &p1,pair<int, pii>&p2){
    if(p1.second.first != p2.second.first && p1.second.first != p2.second.second &&
            p1.second.second != p2.second.first && p1.second.second != p2.second.second){
                return true ;
    }

    return false ;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, sum;
    cin >> n >> x;

    for (int i = 0; i <n; i++)
    {
        cin >> a[i] ;
    }

    int size = (n * (n - 1)) / 2; 

    pair<int, pii> p[size] ;

    int k = 0 ;

    for(int i = 0 ; i<n ;i++){
        for(int j = i+1; j<n ; j++){
            p[k].first = a[i] + a[j] ;
            p[k++].second = {i+1, j+1} ;
        }
    }

    sort(p, p+size) ;

    int i = 0 , j = size -1  ;

    while(i<j){
        if(p[i].first + p[j].first == x && noCommon(p[i], p[j])){
            cout << p[i].second.first << ' ' << p[i].second.second << ' ' << 
            p[j].second.first << ' ' << p[j].second.second << endl ;
            return 0 ;
        }
        else if(p[i].first + p[j].first < x) i++ ;
        else j-- ;
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}