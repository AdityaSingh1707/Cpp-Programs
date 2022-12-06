class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.length() != word2.length())
            return false;
        
        vector<int> occurence_w1(26, 0), occurence_w2(26, 0);

        for(auto a : word1)
            occurence_w1[a-'a']++;
        for(auto a : word2)
            occurence_w2[a-'a']++;

        sort(occurence_w1.begin(), occurence_w1.end());
        sort(occurence_w2.begin(), occurence_w2.end());

        vector<int> unique_w1(26, 0), unique_w2(26, 0);

        for(auto a : word1)
            unique_w1[a-'a'] = 1;
        for(auto a : word2)
            unique_w2[a-'a'] = 1;

        return (occurence_w1 == occurence_w2 && unique_w1 == unique_w2);
    }
};
