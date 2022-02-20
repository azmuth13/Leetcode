// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
            
        int d[101] = {};
        
        sort(arr, arr + n, comp);
        
        for(int i = 0; i < n; i++)
        {
            int deadline = arr[i].dead;
            
            int j = deadline;
            
            while(j > 0 && d[j] != 0)
            {
                j--;
            }
            
            if(j > 0)
            d[j] = arr[i].profit;
        }
        
        int sum = 0;
        int cnt = 0;
        
        for(int i = 1; i < 101; i++)
        {
            sum += d[i];
            if(d[i] != 0)
            {
                cnt++;
            }
        }
        
        return {cnt,sum};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends