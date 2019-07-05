//
//  main.cpp
//  179
//
//  Created by 小尹 on 2019/7/5.
//  Copyright © 2019 小尹. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cmp(string a, string b) {
    return a+b > b+a;
}

int main() {
    int n; cin>>n;
    vector<string> v;
    for (int i = 0; i < n; i ++) {
        string a;
        cin>>a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end(), cmp);
    if(v[0][0]=='0') {
        puts("0");
    }
    else {
        for(int i = 0; i < n; i++)
            cout<<v[i];
        puts("");
        
    }
    
    
    return 0;
}
