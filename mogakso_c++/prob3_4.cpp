#include <iostream>
#include<vector>
using namespace std;

int prob3_4() {
    int N,qes;
    vector<vector <int>> A(1025,vector<int> (1025,0));
    cin >> N >> qes;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int tmp;
            cin >> tmp;
            A[i][j] = A[i][j-1]+A[i-1][j]-A[i-1][j-1]+tmp;
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<qes;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << A[x2][y2]-A[x2][y1-1]-A[x1-1][y2]+ A[x1-1][y1-1]<<endl;
    }

    return 0;
}