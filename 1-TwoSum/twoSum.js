var twoSum = function(nums, target) {
  // 特殊条件
  if (nums.length < 2) return [];
  let temp = 0;
  let res = [];
  for (let i = 0; i< nums.length; i ++) {
    let otherVal = target - nums[i];
    
      for (let j = i + 1; j < nums.length; j ++) {
        if (nums[j] === otherVal) {
          res.push(i);
          res.push(j)
          break;
        }
      }
   }
  return res;
};


var twoSum = function(nums, target) {
  // 特殊条件
  if (nums.length < 2) return [];
  let hashmap = {};
  for (let i = 0; i< nums.length; i ++) {
    let otherVal = target - nums[i];
    if (otherVal in hashmap) {
      return [hashmap[otherVal],i]
    }
    hashmap[nums[i]] = i
  }
};
