class Solution {
public:

    bool isCloser(int a, int b, int x){
        if ( abs(a-x) < abs(b-x) ) return true;
        if ( abs(a-x) == abs(b-x) && a<b ) return true;
        return false; 
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0,j=arr.size()-1;
        while( j-i+1!=k ){
            if( isCloser( arr[i], arr[j], x) )
                j--;
            else i++;

            if ( j-i+1 == k ) break;
        }
        vector<int> c;
        for( int l=i;l<=j;l++) c.push_back(arr[l]);
        return c;
    }
};