class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<List<Integer>>();
        triangle.add(new ArrayList<Integer>());
        triangle.get(0).add(1);
        for (int i=1; i<numRows; ++i) {
            List<Integer> row = new ArrayList<>();
            List<Integer> prev = triangle.get(i - 1);
            for (int j=0; j<=i; ++j) {
                if (j == 0) {
                    row.add(1);
                } else if (j == i) {
                    row.add(1);
                } else {
                    row.add(prev.get(j) + prev.get(j - 1));
                }
            }
            triangle.add(row);
        }
        return triangle;
    }
}
// Time : O(n^2)
// Space : O(n^2)