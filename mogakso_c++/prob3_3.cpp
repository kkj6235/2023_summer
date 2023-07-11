#include <iostream>

using namespace std;

int prob3_3() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count,qes;
    int A[100001]={};
    cin>>count>>qes;

    for(int i=1;i<=count;i++){
        int tmp;
        cin>>tmp;
        A[i]=A[i-1]+tmp;
    }
    for(int i=0;i<qes;i++){
        int a,b;
        cin>>a>>b;
        cout<<A[b]-A[a-1]<<endl;
    }
    return 0;
}