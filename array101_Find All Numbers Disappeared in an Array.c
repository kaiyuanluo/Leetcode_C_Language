/*Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

   Hide Hint #1  
This is a really easy problem if you decide to use additional memory. For those trying to write an initial solution using additional memory, think counters!
   Hide Hint #2  
However, the trick really is to not use any additional space than what is already available to use. Sometimes, multiple passes over the input array help find the solution. However, there's an interesting piece of information in this problem that makes it easy to re-use the input array itself for the solution.
   Hide Hint #3  
The problem specifies that the numbers in the array will be in the range [1, n] where n is the number of elements in the array. Can we use this information and modify the array in-place somehow to find what we need?
*/
//my ans
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int* count = (int*)calloc(numsSize + 1, sizeof(int));
    for(int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int index = 0;
    for(int i = 1; i <= numsSize; i++){
        if(count[i] == 0){
            res[index++] = i;
        }
    }
    *returnSize = index;
    free(count);
    return res;
}

//fast runtime

int *findDisappearedNumbers(int *arr,int arrSize,int *returnSize) {
  int count=0;
  int pos=0;

  int *zeroes=(int *) malloc((arrSize+1)*sizeof(int));

  for (int i=1;i<arrSize+1;i++) {
    zeroes[i]=0;  
  }

  for (int i=0;i<arrSize;i++) {
    int elem=arr[i];
    
    zeroes[elem]=elem;
  } 

  for (int i=1;i<arrSize+1;i++) {
    if (zeroes[i]==0) {
      count++;  
    }
  }

  *returnSize=count;

  int *res=(int *) malloc((*returnSize)*sizeof(int));

  for (int i=1;i<arrSize+1;i++) {
    if (zeroes[i]==0) {
      res[pos]=i;
      pos++;  
    }
  }

  return res;
}
//lowest memory
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    int i = 0;
    while (i < numsSize) {
        int temp = nums[i];
        if (temp != i + 1) {
            if (temp == nums[temp-1]) { // duplicate
                i++;
                continue;
            } else {
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        else i++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) { 
            nums[*returnSize] = i+1;
            (*returnSize)++;
        }
    }
    return nums;
}
