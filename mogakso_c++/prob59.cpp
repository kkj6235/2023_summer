#include <iostream>
#include <vector>
#include<tuple>
using namespace std;
typedef tuple <int,int,int> edge;
int prob59() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long inf=100000*6001;
    int n,E;
    cin >> n >> E;
    vector<edge> edges;
    vector<long long> v(n + 1, inf);

    for(int i=0;i<E;i++){
        long long a,b,c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    v[1] = 0;
    for(int cnt=0;cnt<n-1;cnt++){
        for(int j=0;j<E;j++){
            long long s = get<0>(edges[j]);
            if(v[s]!=inf){
                long long e = get<1>(edges[j]);
                long long w = get<2>(edges[j]);
                if(v[e]>v[s]+w){
                    v[e] = v[s] + w;
                }
            }
        }
    }

    bool flag=false;
    for(int j=0;j<E;j++){
        long long s = get<0>(edges[j]);
        if(v[s]!=inf){
            long long e = get<1>(edges[j]);
            long long w = get<2>(edges[j]);
            if(v[e]>v[s]+w){
                flag=true;
                v[e] = v[s] + w;
            }
        }
    }
    if(flag){
        cout << -1 << "\n";
    }
    else{
        for(int i=2;i<=n;i++){
            if(v[i]==inf){
                cout << -1 << "\n";
            }
            else{
                cout << v[i] << "\n";
            }
        }
    }

    return 0;
}