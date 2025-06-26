#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
        // Placeholder for collision logic
        vector<int> st;
        int i = 0;
        while(i < asteroids.size()){
            bool destroyed = false;
            while(i < asteroids.size() && !st.empty() && st.back() > 0 && asteroids[i] < 0){
                if(abs(st.back()) < abs(asteroids[i]))st.pop_back();
                else if(abs(st.back()) == abs(asteroids[i])){
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                st.push_back(asteroids[i]);
            }
            i++;
        }
        
        return st;
    }