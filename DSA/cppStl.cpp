#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


int main(){

    vector<int> A = {1,6,3,11,0,4,7};
    sort(A.begin(), A.end());
    
    for(int i = 0; i<7; i++){
        //cout << A[i] << " ";
        
    }
    //cout<< endl;

    A.push_back(100);
    bool present = binary_search(A.begin(), A.end(),4);
    //cout << present << endl;
    bool pre = binary_search(A.begin(), A.end(),5);
    //cout << pre << endl;






    map<int,int> M;
    M[1] = 100;
    M[2] = -1;
    M[3] = 300;
    M[1] = 100;
    M[1000023] = 1;


    
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(10);
    s.insert(0);
    for(int x: s){
        //cout << x << " ";
    }
    cout << s[2];

    return 0;
}