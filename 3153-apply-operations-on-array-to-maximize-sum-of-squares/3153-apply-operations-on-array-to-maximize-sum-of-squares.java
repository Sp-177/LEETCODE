import java.util.Collections;
import java.util.List;

class Solution {
    public int maxSum(List<Integer> nums, int k) {
        int[] arr = new int[32]; // Array to store binary representation
        
        // Sort the list in reverse order
        Collections.sort(nums, Collections.reverseOrder());

        // Convert each number to binary and store in the array
        for (int i : nums) {
            int x = i;
            int ind = 31;
            while (x > 0) {
                if ((x & 1) == 1) {
                    arr[ind] ++;
                }
                ind--;
                x = x >> 1;
            }
        }

        // Print array using Arrays.toString
        long ans=0;
        long mod=1000000000+7;
        while(k>0){
            long num=0,po=0;
            for(int i=31;i>=0;i--){
            if(arr[i]>=1){
                arr[i]--;
                num+=1<<po;

            }
                po++;
            }
            // System.out.println(num);/
            k--;
            
            ans+=num*num;
            ans=ans%mod;
        }
        
        // Example return statement; you need to replace this with actual logic
        return (int)ans;
    }
}
