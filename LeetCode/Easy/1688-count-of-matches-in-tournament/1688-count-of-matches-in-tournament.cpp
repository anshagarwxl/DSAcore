class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};

//logical approach with time complexity : O(log n)

// int numberOfMatch(int n){
//     int matches = 0;
//     while(n>1){
//         if(n%2==0){ //even
//             matches +=n/2;
//             n=n/2;
//         }
//         else{
//             matches +=(n-1)/2;
//             n = (n-1)/2+1;
//         }
//     }
//     return matches;
// }