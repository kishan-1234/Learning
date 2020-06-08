bool cmp(string a,string b)
    {
        stringstream sa(a),sb(b);
        string tempa,tempb,firstworda,firstwordb;
        int i=0;
        while(sa>>tempa && sb>>tempb)
        {
            if(i==0)
            {
                firstworda = tempa;
                firstwordb = tempb;
            }
            else
            {
                if(tempa!=tempb)
                {
                    return tempa<tempb;
                }
            }
            i++;
        }
        return firstworda<firstwordb;
    }
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
    
        vector<string> letterlogs;
        vector<string> digilogs;
        vector<string> res;
        for(int i=0;i<logs.size();i++)
        {
            stringstream ss(logs[i]);
            string temp;
            int j=0;
            while(ss>>temp)
            {
                if(j==1)
                {
                    if(temp[0]-'a'<=25 && temp[0]-'a'>=0)
                    {
                        letterlogs.push_back(logs[i]);
                    }
                    else
                    {
                        digilogs.push_back(logs[i]);
                    }
                    break;
                }
                j++;
            }
        }
        sort(letterlogs.begin(),letterlogs.end(),cmp);
        // return letterlogs;
        for(int i=0;i<letterlogs.size();i++)
        {
            res.push_back(letterlogs[i]);
        }
        for(int i=0;i<digilogs.size();i++)
        {
            res.push_back(digilogs[i]);
        }
        return res;
    }
};