#include<iostream>
#include <vector>

using namespace std;

int prob87(){
    int n;
    cin >> n;
    vector<int> v(n+1);

    v[1] = 1;
    v[2] = 2;

    for(int i=3;i<n+1;i++){
        v[i] = (v[i - 1] + v[i - 2])%10007;
    }

    cout << v[n] << "\n";
}