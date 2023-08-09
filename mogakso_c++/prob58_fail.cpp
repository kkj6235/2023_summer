#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

int prob58() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector <int>> A(n+1,vector<int> (n+1,0));
    vector<priority_queue <int>> B(n+1);
    vector<int> queue(n + 1,6000);
    vector<bool> flag(n + 1, false);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        A[a][b] = c;
    }

    int i=1,sum=0;
    while(1){
        flag[i] = true;
        for(auto it = A[i].begin()+1;it!=A[i].end();it++){
            if(*it!=0){
                int idx = it - A[i].begin();
                if(i==1){
                    B[idx].push(*it);
                    queue[idx] = *it;
                    continue;
                }
                if((sum+*it)<queue[idx]){
                    queue[idx] = (sum + *it);
                }
                if(B[idx].size()!=k){
                    B[idx].push(sum+*it);
                }
                else if((sum+*it)<B[idx].top()){
                    B[idx].pop();
                    B[idx].push(sum+*it);
                }
            }

        }
        auto min = min_element(queue.begin()+1, queue.end());
        check : i = min - queue.begin();
        if(flag[i]){
            if(find(flag.begin()+1,flag.end(),false)==flag.end()){
                break;
            }
            min=queue.begin();
            for(auto j=queue.begin()+1;j!=queue.end();j++){
                if(sum<=*j and *j<*min){
                    if(!flag[j-queue.begin()]){
                        min = j;
                    }
                }
            }
            goto check;
        }
        else{
            sum = *min;
        }
    }

    for(int i=1;i<=n;i++){
        if(B[i].size()!=k){
            if(k==1){
                cout << 0 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            cout << B[i].top() << endl;
        }
    }
    return 0;
}