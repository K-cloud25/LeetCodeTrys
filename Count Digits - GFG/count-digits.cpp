//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        int counter = 0;
        int t = N;
        while(t > 0){
            int lastDigit = t % 10; 
            if(lastDigit != 0){
                if(N%lastDigit == 0){
                    counter += 1;
                }
            }
            t = t / 10;
        }
        
        return counter;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends