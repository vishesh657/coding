class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(); int ml=1; int start=0;
        bool arr[n][n];
        memset(arr,false,sizeof(arr));
        for(int i=0;i<n;i++){
            arr[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                arr[i][i+1]=true;
                ml=2;
                start=i;
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(arr[i+1][j-1] && s[i]==s[j]){
                    arr[i][j]=true;
                    if(len>ml){
                        ml=len;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,ml);
    }
};
