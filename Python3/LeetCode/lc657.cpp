class Solution {
public:

    int count(string s, char c) {
        int count = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == c) count++;
        }
        return count;
    }
    bool judgeCircle(string moves) {
        return (count(moves, 'D') == count(moves, 'U')) && (count(moves, 'L') == count(moves, 'R'));
    }
};