//  Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
/*
    In a rotated sorted array the pivot element is the only one who has a smaller element to its right
*/
private:
    int findPivot(vector<int> &nums){
        int start=0, end=nums.size()-1;
        
        while(start<=end){
            if(start==end)
                return start;
            int mid=start+(end-start)/2;
            
            if(mid<end && nums[mid]>nums[mid+1])
                return mid;
            if(mid>start && nums[mid]<nums[mid-1])
                return mid-1;
            
            if(nums[start]>=nums[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        
        return -1;
    }
    
    int binarySearch(vector<int> &nums, int start, int end, int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }    
        
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target){
        int pivot=findPivot(nums);
        
        if(pivot==-1)
            return binarySearch(nums,0,nums.size()-1,target);
        if(nums[pivot]==target)
            return pivot;
        
        if(nums[0]<=target)
            return binarySearch(nums,0,pivot-1,target);
        return binarySearch(nums,pivot+1,nums.size()-1,target);
    }
};
