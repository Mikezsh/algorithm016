int removeDuplicates(int* nums, int numsSize){
    int j = 1;
    if(numsSize == 0){
        return 0;
    }
    for(int i = 1;i < numsSize;i++){
        if(nums[i-1] == nums[i]){
           continue;
        } else {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}