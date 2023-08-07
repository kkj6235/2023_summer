#include<iostream>
#include<vector>
using namespace std;

int prob61(){

    int n, m,inf=int(1e9);
    cin >> n >> m;
    vector<vector<int>> A(n+1,vector<int>(n+1,inf));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        A[a][b] = min(A[a][b],c);
    }

    for(int i=1;i<n+1;i++){
        A[i][i] = 0;
    }

    for(int k=1;k<n+1;k++){
        for(int s=1;s<n+1;s++){
            for(int e=1;e<n+1;e++){
                A[s][e] = min(A[s][e], A[s][k] + A[k][e]);
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(A[i][j]==inf){
                cout << 0 << " ";
            }
            else{
                cout << A[i][j] << " ";
            }
        }
        cout << "\n";
    }

}