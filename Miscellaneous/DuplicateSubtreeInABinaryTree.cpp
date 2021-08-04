class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    map<string,int> mp;
    string identical(Node* root)
    {
        if(!root)
        {
            return "$";  
        }
        string s="";
        if(!root->left&&!root->right)
        {
            return s=to_string(root->data);
        }
        s=s+to_string(root->data);
        s=s+identical(root->left);
        s=s+identical(root->right);
        mp[s]++;
        return s;
    }
    int dupSub(Node *root) {
         // code here
        identical(root);
        for(auto i:mp)
        {
            if(i.second>1)
            {
                return true;
            }
        }
        return false;
    }
};