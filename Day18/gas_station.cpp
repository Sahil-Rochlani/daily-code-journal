#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0;
    int deficit = 0;
    int balance = 0;
    for(int i = 0;i < gas.size();i++){
        //ya toh aage jaa paaunga ya nahi jaa paaunga
        if(balance + gas[i] < cost[i]){
            //matlab aage nahi jaa paaunga
            deficit += balance + gas[i] - cost[i];
            //agar main start se leke i tak nahi pahunch paya toh start + 1, or uske aage se bhi i tak nahi pahunch paaunga, toh mujhe phir se start + 1 se loop chalane ki zarurat nahi hai, isliye start ko i + 1 set kar dunga aur balance restart kar dunga
            start = i + 1;
            balance = 0;
        }
        else{
            //matlab aage jaa paaunga
            balance += gas[i] - cost[i];
        }
    }
    //agar 0 se start tak tak ka deficit agar hamara end balance kar sakta hai toh matlab hum full circle travel kar paaynege isliye mujhe after reaching end phir se 0 se traverse nahi karna padega
    if(balance + deficit >= 0)return start;
    return -1;
}