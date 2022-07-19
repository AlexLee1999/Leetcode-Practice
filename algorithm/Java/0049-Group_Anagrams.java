class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List> myMap = new HashMap<String, List>();
        for (int i=0; i<strs.length; ++i) {
            char[] c_array = strs[i].toCharArray();
            Arrays.sort(c_array);
            String str = String.valueOf(c_array);
            if (!myMap.containsKey(str)) {
                myMap.put(str, new ArrayList());
            }
            myMap.get(str).add(strs[i]);
        }
        return new ArrayList(myMap.values());
    }
}
// Time : O(nklogk)
// Space : O(nk)