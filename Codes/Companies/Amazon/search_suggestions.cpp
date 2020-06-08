class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
    sort(products.begin(),products.end());
    vector<vector<string> > res;
    for(int i=1;i<=searchWord.length();i++)
    {
        vector<string> temp;
        string sstr = searchWord.substr(0,i);
        for(int j=0,k=2;j<products.size() && k>=0;j++)
        {
            if(products[j].substr(0,i)==sstr)
            {
                    temp.push_back(products[j]);
                    k--;
            }
        }
        res.push_back(temp);
    }
    return res;
    }
};