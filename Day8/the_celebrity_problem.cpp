#include<bits/stdc++.h>
using namespace std;

//approach 1: brute force
int celebrity(vector<vector<int>> &M){
    for(int i = 0;i < M.size();i++){
        bool iscelebrity = true;
        for(int j = 0;j < M.size();j++){
            if(i != j && (M[i][j] == 1 || M[j][i] == 0)){
                iscelebrity = false;
                break;
            }
        }
        if(iscelebrity)return i;
    }
    return -1;
}
//approach 2: using stack

int findCelebrity(vector<vector<int>>& mat, int n) {
    stack<int> st;
    for(int i = 0;i < n;i++){
        st.push(i);
    }
    while(st.size() > 1){
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        if(mat[a][b]){
            //it means a cannot be a celebrity since a celebrity doesnt know anyone and b can be a celebrity
            st.push(b);
        }
        else{
            //it means b cant be a celebrity since a celebrity is known by everyone and a can be a celebrity
            st.push(a);
        }
    }
    //the remaining element is our potential candidate but we have to verify
    int c = st.top();
    for(int i = 0;i < n;i++){
        if(i == c)continue;
        if(mat[i][c] == 0 || mat[c][i] == 1)return -1;
    }
    return c;
}

//approach 3: using two pointers

int findCelebrity(vector<vector<int>>& mat, int n) {
    int i = 0, j = n - 1;
    while(i < j){
        if(mat[i][j]){
            i++;
        }
        else{
            j--;
        }
    }
    int c = i;
    for(int i = 0;i < n;i++){
        if(i == c)continue;
        if(mat[i][c] = 0 || mat[c][i] == 1)return -1;
    }
    return c;
}