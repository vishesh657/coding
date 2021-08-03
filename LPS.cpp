class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            int l1=pal(s,i,i);
            int l2=pal(s,i,i+1);
            int max_len=max(l1,l2);
            if(max_len > end-start){
                start=i-(max_len-1)/2;
                end=i+max_len/2;
            }
        }
        return s.substr(start, end-start+1);
    }
    int pal(string &s, int l, int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--; r++;
        }
        return r-l-1;
    }
};
