#include<iostream>
#include<vector>
#include <queue>
using namespace std;
typedef pair<int, int> Node;
int prob58_exam(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    int v[1001][1001]={0};
    priority_queue<int> queue[1001];
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a][b] = c;
    }

    priority_queue<Node,vector<Node>,greater<>>pq;

    pq.emplace(0, 1);
    queue[1].push(0);

    while(!pq.empty()){
        Node u=pq.top();
        pq.pop();
        for(int j=1;j<=n;j++){
            if(v[u.second][j]!=0){
                if(queue[j].size()<k){
                    queue[j].push(u.first+v[u.second][j]);
                    pq.emplace(u.first + v[u.second][j], j);
                }
                else if(queue[j].top()>(u.first+v[u.second][j])){
                    queue[j].pop();
                    queue[j].push(u.first+v[u.second][j]);
                    pq.emplace(u.first + v[u.second][j], j);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(queue[i].size()==k){
            cout << queue[i].top() << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }


}