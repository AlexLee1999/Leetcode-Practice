class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> myHeap = new PriorityQueue<Integer>((n1, n2) -> n2 - n1);
        for (int i=0; i<nums.length; ++i) {
            myHeap.add(nums[i]);
        }
        for (int i=0; i<k - 1; ++i) {
            myHeap.poll();
        }
        return myHeap.poll();
    }
}
