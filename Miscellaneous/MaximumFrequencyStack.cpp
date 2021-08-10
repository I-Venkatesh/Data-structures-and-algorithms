class FreqStack {
public:
    unordered_map<int,stack<int>> mp;
    unordered_map<int,int> freq;
    int maxf;
    FreqStack() {
        maxf=0;
    }
    
    void push(int val) {
        freq[val]++;
        mp[freq[val]].push(val);
        maxf=max(maxf,freq[val]);
    }
    
    int pop() {
       int val=mp[maxf].top();
        freq[val]--;
        mp[maxf].pop();
        if(mp[maxf].empty())
        {
            maxf--;
        }
        return val;
    }
};