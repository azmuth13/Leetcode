class RLEIterator {
public:
    stack < pair <int, int> > stRev, st;
    RLEIterator(vector<int>& enc) {
        int n = enc.size();
        
        int i = 0;
        while(i < n)
        {
            if(enc[i] == 0)
            {
                i+=2;
            }
            else
            {
                stRev.push({enc[i], enc[i+1]});
                i+=2;
            }
        }
        
        while(stRev.size() > 0)
        {
            st.push(stRev.top());
            stRev.pop();
        }
    }
    
    int next(int n) {
        
//         auto pp = st.top();
//         st.pop();
        
//         int freq = pp.first;
//         int val = pp.second;
        
//         if(n <= freq)
//         {
//             freq-=n;
            
//             if(freq > 0)
//                 st.push({freq, val});
            
//             return val;
//         }
//         else
//         {
//             return -1;
//         }
        
        while(n > 0)
        {
            if(st.size() == 0)
                return -1;
            
            auto pp = st.top();
            st.pop();

            int freq = pp.first;
            int val = pp.second;
            
            if(n <= freq)
            {
                freq-=n;

                if(freq > 0)
                    st.push({freq, val});

                return val;
            }
            else
            {
                n -= freq;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */