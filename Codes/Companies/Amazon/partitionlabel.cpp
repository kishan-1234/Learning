class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        vector<int> v(26,0);
        for(int i=0;i<S.length();i++)
        {
            v[S[i]-'a'] = i;
        }
        
        int j=0,si=-1;
        vector<int> res;
        for(int i=0;i<S.length();i++)
        {
            j = max(j,v[S[i]-'a']);
            if(j==i)
            {
                res.push_back(j-si);
                si = i;
            }
        }
        return res;
    }
};