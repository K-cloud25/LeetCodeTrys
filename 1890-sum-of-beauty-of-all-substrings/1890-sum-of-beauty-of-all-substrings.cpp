class Solution {
public:

    int beautySum(string s) {
        int n = s.length();
        int total = 0;
        for ( int i=0; i<n; i++){
            vector<int> freq(26 ,0);

            for( int j=i; j<n;j++){

               int index = s[j] - 'a';
               freq[index]++;

                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;
               for ( int k=0; k<26; k++ ){

                if ( freq[k] > 0 ){
                    if ( freq[k] > maxFreq ){
                        maxFreq = freq[k];
                    }
                    if ( freq[k] < minFreq){
                        minFreq = freq[k];
                    }
                }
               } 
                total += maxFreq - minFreq;
            }
        }

        return total;
    }

};