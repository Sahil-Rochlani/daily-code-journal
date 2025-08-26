#include<bits/stdc++.h>
using namespace std;

class Twitter {
    struct Tweet{
        int tweetId;
        int time;

        Tweet(int id, int t) : tweetId(id), time(t) {}
    };

    class cmp{
        public:
        bool operator()(const Tweet &a, const Tweet &b){
            return a.time > b.time;
        }
    };

    int Time = 0;
    //map userId --> Tweets
    unordered_map<int, vector<Tweet>> tweets;

    //map : userId --> userId(followings)
    unordered_map<int, unordered_set<int>> following;
public:

    Twitter() {
        Time = 0; //Global time init to 0
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, Time));
        Time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        //return tweet Ids of 10 most recent tweeets done by me or my followings
        priority_queue<Tweet, vector<Tweet>, cmp>minHeap;

        // user's own tweets
        if(tweets.find(userId) != tweets.end()){
            auto myTweets = tweets[userId];
            for(auto tweet : myTweets){
                minHeap.push(tweet);
                if(minHeap.size() > 10)minHeap.pop(); //removed the oldest tweet
            }
        }

        if(following.find(userId) != following.end()){
            for(auto followee : following[userId]){
                 if(tweets.find(followee) != tweets.end()){
                    auto followeeTweets = tweets[followee];
                    for(auto tweet : followeeTweets){
                        minHeap.push(tweet);
                        if(minHeap.size() > 10)minHeap.pop(); //removed the oldest tweet
                    }
                }
            }
        }
        //now i will have top 10 most recent tweets done by userId or his followees
        vector<int> newsFeed;
        while(!minHeap.empty()){
            newsFeed.push_back(minHeap.top().tweetId);
            minHeap.pop();
        }
        reverse(newsFeed.begin(), newsFeed.end());
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        following[followerId].insert(followeeId);
        Time++;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.find(followerId) != following.end()){
            following[followerId].erase(followeeId);
        }
    }
};