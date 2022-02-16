class Solution {
public:

    int nthUglyNumber(int n) {
        
        vector <long long> ugly;
        int i = 0;
        
        priority_queue <long long, vector <long long> , greater<long long> > pq;
        set <long long> st;
        
        pq.push(1);
        
        while(1)
        {
            long long int mini = pq.top();
            pq.pop();
            
            if(st.count(mini) == 0)
            {
                ugly.push_back(mini);
                st.insert(mini);
                
                pq.push(mini*2);
                pq.push(mini*3);
                pq.push(mini*5);
            }
            
            if(ugly.size() > n)
                break;

        }

        return ugly[n-1];
     
    }
};