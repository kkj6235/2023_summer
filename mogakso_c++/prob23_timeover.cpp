#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> A(1001);
vector<int> stack;
void search(vector<vector <int>> A,vector<int> *stack,int i){
    auto j = A[i].begin();
    stack->push_back(i);
    for(int k=0;k<A[i].size();k++){
        if(find(stack->begin(), stack->end(), *(j+k))==stack->end()){
            search(A, stack, *(j + k));
        }
    }
}

int prb23_timeover() {
    int count=0;
    int v, e;
    cin >> v >> e;


    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }

    for(int i=0;i<v;i++){
        auto it = find(stack.begin(), stack.end(), i);
        if(it!=stack.end()){
            continue;
        }
        search(A, &stack, i);
        count++;
        if(stack.size()==v){
            break;
        }
    }
    cout << count << endl;

    return 0;
}


