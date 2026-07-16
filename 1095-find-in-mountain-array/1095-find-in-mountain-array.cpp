/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(int n,MountainArray &nums){
        int i=0;
        int j=n-1;
        int ans=-1;
        while(j>=i){
            int mid=i+(j-i)/2;
            int currnum=nums.get(mid);
            int nextEle=nums.get(mid+1);
            if(currnum>nextEle){
                ans=mid;
                j=mid-1;
            } 
            else{
                i=mid+1;
            }
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &nums) {
        int n=nums.length();

        int peakIdx=findPeak(n,nums);

        int i=0;
        int j=peakIdx-1;
        while(j>=i){
            int mid=i+(j-i)/2;
            int currnum=nums.get(mid);
            if(currnum>target){
                j=mid-1;
            }
            else if(currnum==target) return mid;
            else{
                i=mid+1;
            }
        }

        i=peakIdx;
        j=n-1;

        while(j>=i){
            int mid=i+(j-i)/2;
            int currnum=nums.get(mid);
            if(currnum<target){
                j=mid-1;
            }
            else if(currnum==target) return mid;
            else{
                i=mid+1;
            }
        }
        return -1;
    }
};