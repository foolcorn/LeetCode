#include "utils.h"
// *实现推特，几个api：关注，取消关注，发推特，获取推特：返回自己和关注的人的推特按时间逆序的前10条id
class Twitter {
private:
    struct Msg{
        int msgid;
        int userid;
        Msg(int m, int u):msgid(m), userid(u) {}
    };
    //-思路：用一个vector存所有消息，消息封装成一个类，包含消息id和user_id
    //-每个id映射一个set，set里包含id关注的人
    //-获取新闻的时候，从尾巴开始遍历10个在set里的信息封装成vector返回即可
    //-如果关注某个人，更新set，删除同理
    vector<Msg> mlist;
    unordered_map<int, unordered_set<int>> followList;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        mlist.emplace_back(tweetId,userId);
    }

    vector<int> getNewsFeed(int userId) {
        unordered_set<int> followset = followList[userId];
        vector<int> res;
        int count = 0;
        for(auto it = mlist.rbegin(); it != mlist.rend(); ++it){
            if(it->userid == userId || followset.count(it->userid)>0){
                res.push_back(it->msgid);
                ++count;
                if(count==10){
                    break;
                }
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if(followList.count(followerId) == 0){
            followList[followerId] = unordered_set<int>();
        }
        if(followList[followerId].count(followeeId) > 0){
            return;
        }
        followList[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followList.count(followerId) == 0){
            return;
        }
        if(followList[followerId].count(followeeId) == 0){
            return;
        }
        followList[followerId].erase(followeeId);
    }
};