#include <iostream>
using namespace std;

int prob3_1() {
    int count,sum=0;
    char tmp;
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>tmp;
        sum+=(int)tmp-48;
    }
    cout << sum << endl;
    return 0;
}