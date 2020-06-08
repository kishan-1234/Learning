#include<bits/stdc++.h>

using namespace std;

bool cmp(string s1,string s2)
{
    return s1<s2;
}

struct compare{
    bool operator()(pair<int,string> p1,pair<int,string> p2){
        if(p1.first==p2.first)
            return p1.second>p2.second;
        return p1.first<p2.first;
    }
};

vector<string> count(vector<string> keywords,vector<string> reviews,int N)
{
    map<string,int> m;
    map<string,int>::iterator mit;
    priority_queue<pair<int,string>,vector<pair<int,string> >,compare > hp;
    for(int i=0;i<keywords.size();i++)
    {
        m[keywords[i]] = 0;
    }
    // for(mit=m.begin();mit!=m.end();mit++)
    // {
    //     cout << mit->first << " " << mit->second << endl;
    // }
    regex re("[^a-zA-Z]");
    for(int i=0;i<reviews.size();i++)
    {
        set<string> s;
        set<string>::iterator it;
        reviews[i] = regex_replace(reviews[i],re," ");
        stringstream ss(reviews[i]);
        string temp;
        while(ss>>temp)
        {
            s.insert(temp);
        }
        // for(it=s.begin();it!=s.end();it++)
        // {
        //     cout << *it << " ";
        // }
        // cout << endl;
        for(it=s.begin();it!=s.end();it++)
        {
            mit = m.find(*it);
            if(mit!=m.end())
                m[*it]++;
        }
    }
    for(mit=m.begin();mit!=m.end();mit++)
    {
        cout << mit->first << " " << mit->second << endl;
    }
    for(mit=m.begin();mit!=m.end();mit++)
    {
        hp.push(make_pair(mit->second,mit->first));
    }

    vector<string> res;
    for(int i=0;i<N;i++)
    {
        pair<int,string> temp = hp.top();
        hp.pop();
        res.push_back(temp.second);
    }
    return res;
}

int main()
{
    vector<string> keywords = {"anacell", "cetracular", "betacellular"};
    int n;
    cin >> n;
    sort(keywords.begin(),keywords.end(),cmp);
    vector<string> reviews = {
        "anacell provides the best services in the city",
        "betacellular has awesome services",
        "Best services provided by anacell, everyone should use anacell"
    };
    vector<string> res = count(keywords,reviews,n);
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] <<endl;
    }
}