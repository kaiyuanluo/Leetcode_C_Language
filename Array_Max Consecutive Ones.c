/**Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*//
//my Ans:
 int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int maxCount = 0;   // Maximum consecutive 1's count
    int currentCount = 0;  // Current consecutive 1's count

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            currentCount++;  // Increment the current count if the current element is 1
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;  // Update maxCount if necessary
            }
            currentCount = 0;  // Reset the current count when we encounter a 0
        }
    }

    // Handle the case where the array ends with consecutive 1's
    if (currentCount > maxCount) {
        maxCount = currentCount;
    }

    return maxCount;
}
//Fast Runtime
int findMaxConsecutiveOnes(int* nums, int n)
{
    int count=0;
    int maxcount=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==1)
        count++;
        else
        count=0;
        if(count>maxcount)
        maxcount=count;
    }
    return maxcount;

}
// Best Memory
int findMaxConsecutiveOnes(int* nums, int numsSize){
    int maxOnes = 0;
    int tempCnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if(nums[i] != 1) {
            tempCnt = 0;
        }
        else{
            tempCnt++;
        }
        if(tempCnt > maxOnes) {
            maxOnes = tempCnt;
        }
       // maxOnes = tempCnt > maxOnes ? tempCnt : maxOnes;
    }
    return maxOnes;
}
