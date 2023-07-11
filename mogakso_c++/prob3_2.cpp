#include <iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int prob3_2() {
    vector<double> A;
    int count;
    double tmp;
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>tmp;
        A.push_back(tmp);
    }
    double max = *max_element(A.begin(), A.end());
    for(int i=0;i<count;i++){
        A[i] = (A[i] / max) * 100;
    }
    cout<<accumulate(A.begin(),A.end(),0.0)/A.size()<<endl;
    return 0;
}
