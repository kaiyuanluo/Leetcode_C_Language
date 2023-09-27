/*Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Can you find an O(n) solution?
*/
//my ans
int thirdMax(int* nums, int numsSize){
    long max1 = LONG_MIN;
    long max2 = LONG_MIN;
    long max3 = LONG_MIN;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == max1 || nums[i] == max2 || nums[i] == max3) continue;
        if(nums[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if(nums[i] > max2){
            max3 = max2;
            max2 = nums[i];
        } else if(nums[i] > max3){
            max3 = nums[i];
        }
    }
    return max3 == LONG_MIN ? max1 : max3;
}
//fast runtime
int thirdMax(int* a, int n)
{
int big,big2,big3,i;
big=a[0];
for(i=0;i<n;i++)
if(a[i]>big)
big=a[i];
for(i=0;i<n;i++)
if(a[i]<big)
{
big2=a[i];
break;
}
for(i=0;i<n;i++)
if(a[i]>big2&&a[i]<big)
big2=a[i];
for(i=0;i<n;i++)
if(a[i]<big2)
{
big3=a[i];
break;
}
for(i=0;i<n;i++)
if(a[i]>big3&&a[i]<big2)
big3=a[i];
if(big2!=big3&&big!=big2)
return big3;
else
return big;
}
//best memory
typedef struct {
    int value;
    bool used;
}maxArr;

int thirdMax(int* nums, int numsSize){

 //Approach 5 is the best

 maxArr first = {0};
 maxArr sec = {0};
 maxArr third = {0};

 for (int i = 0; i < numsSize; i++)
 {
    // If current number is already stored, skip it.
    if ((first.used && first.value == nums[i]) || 
        (sec.used && sec.value == nums[i]) || 
        (third.used && third.value == nums[i])) {
        continue;
    }

     if (first.used == 0 || first.value <= nums[i])
     {
         if (sec.used == 1)
         {
             third.used = 1;
         }
        if (first.used == 1)
         {
             sec.used = 1;
         }
         first.used = 1;
         
         third.value = sec.value;
         sec.value  = first.value;
         first.value = nums[i];
     }
     else if (sec.used == 0 || sec.value <= nums[i])
     {
         if (sec.used == 1)
         {
             third.used = 1;
         }
         sec.used = 1;
         
         third.value = sec.value;
         sec.value  = nums[i];
     }
     else if (third.used == 0 || third.value <= nums[i])
     {
         third.used = 1;
         
         third.value = nums[i];
     }
 }
 if (third.used)
    return third.value;
else
    return first.value;

}
