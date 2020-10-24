#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace :: std;


//利用双map映射，将单词对应字符，字符对应单词，只需要查看两个map与单词是否一致就可以了。

    bool wordPattern(string pattern, string s) {


        unordered_map<char,string> PtoS; 
        unordered_map<string,char> StoP;


        vector<string> words;
        string word;
        stringstream out(s);
        while(out>>word){
            words.push_back(word);
        }

        if(words.size() != pattern.size()){
            return false;
        }

        for(int i = 0; i < words.size(); i++){
            PtoS[pattern[i]] = words[i];
            StoP[words[i]] = pattern[i];
        }

        for(int i = 0; i < words.size(); i++){
            if(PtoS[pattern[i]] != words[i]  || StoP[words[i]]!=pattern[i] ){
                return false;
            }
        }

        return true;
    }


int main(){

    if(wordPattern("abba","dog dog dog dog")){
        cout << "true" << endl;
    }

    else{
        cout << "false" << endl;
    }
    return 0;
}