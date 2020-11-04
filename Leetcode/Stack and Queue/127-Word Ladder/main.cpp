#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_set>

using namespace std;


class Solution {

public:
    //利用BFS思想
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        //将所有单词列表里的单词存入set
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // bfs
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        if(wordSet.find(beginWord) != wordSet.end())
            wordSet.erase(beginWord);

        vector<string> visited;

        while(!q.empty()){
            string curWord = q.front().first;
            int curStep = q.front().second;
            q.pop();

            visited.clear();
            for(string word: wordSet)
                if(similar(word, curWord)){
                    if(word == endWord)
                        return curStep + 1;
                    q.push(make_pair(word, curStep + 1));
                    visited.push_back(word);
                }
            //避免二次访问
            for(string word: visited)
                wordSet.erase(word);
        }

        return 0;
    }

private:
    bool similar(const string& word1, const string& word2){

        assert(word1 != "" && word1.size() == word2.size() && word1 != word2);

        int diff = 0;
        for(int i = 0 ; i < word1.size() ; i ++)
            if(word1[i] != word2[i]){
                diff ++;
                if(diff > 1)
                    return false;
            }
        return true;
    }
};