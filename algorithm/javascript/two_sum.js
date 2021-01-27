var twoSum = function(nums, target) {
    for(var i = 0; i < nums.length; i = i + 1){
        for (var j = i + 1 ; j < nums.length ; j = j + 1){
            if (nums[i] + nums[j] == target) {
                return [i, j];
            }
        }
    }
};