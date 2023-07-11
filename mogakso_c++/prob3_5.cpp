#include <iostream>
#include <vector>
using namespace std;

int prob3_5() {
    long count=0;
    long n,m;
    vector<long> A(n+1, 0);
    vector<long> B(m+1, 0);
    long sum=0;
    cin >> n >> m;

    cin >> A[0];
    for(int i=1;i<n;i++){
        int tmp;
        cin >> tmp;
        A[i] = A[i-1]+tmp;

    }
    for(int i=0;i<n;i++){
        int rem = A[i] % m;
        if(rem==0){
            count++;
        }
        B[rem]++;
    }
    for(int i=0;i<m;i++){
        if(B[i]>1){
            cout << B[i] << i<<endl;
            count = count + (B[i] * (B[i]-1) / 2);
        }
    }


    cout << count << endl;

    return 0;
}