bool search(int* nums, int numsSize, int target)
{
    int mid;
    int high = numsSize -1;
    int low = 0;
    
    while(low<=high)
    {
        mid = (high + low)/2;
        if(nums[mid] == target)
            return true;
        //If there were no repeating elements, this would be easy as instead of checking if here.. you could do nums[low]<=nums[mid] at line 23.
        if(nums[low] == nums[mid])
        {
            low++;
            // because there are repeating elements .. we have to go sequantially when 
            // we are not sure if the mid is in first half or second half.
            
        }
        else 
        {
            // check your mid is in the first half
            if(nums[low]<nums[mid])
            {
            // The equal to is because of the test case, 3,1 and to find 1.
                if(target>= nums[low] && target <nums[mid])
                {
                    high = mid-1;
                }
                else
                {
                    low =  mid+1;
                }
            }
        else
        {
            //your mid is in the second half
            
            if(target<=nums[high] && target > nums[mid])
            {
                low = mid+1;
            }
            else 
            {
                high = mid-1;
            }
        }
        }
        
    }
    return false;
}
