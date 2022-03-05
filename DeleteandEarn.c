/*
 * You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
 * Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
 * Return the maximum number of points you can earn by applying the above operation some number of times.
*/

int deleteAndEarn(int* nums, int numsSize){
    int n = 10002;
    // This is a sought of hash map that is created, where the position 4 would hold the total points earned when
    // you deleted 4, this is because 4 could be repeated number of time.
    
    int arr[10002]={0};
    
    for(int i=0;i<numsSize;i++)
    {
        arr[nums[i]] = arr[nums[i]] + nums[i];    
    }
    
    for(int i=2;i<n; i++)
    {
        // Store the max of {current + (current - 2)} or )Current - 1) 
        arr[i] = arr[i-1] > (arr[i-2] + arr[i]) ? arr[i-1] : (arr[i-2]+arr[i]);
    }
    
    
    return arr[n-1];
}
