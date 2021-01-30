func lengthOfLongestSubstring(s string) int {
    var count = 0
    var max_count = 0
    var tmp []string
    for i := 0; i < len(s) ; i++ {
        is_in := false
        for j := 0 ; j < len(tmp) ; j++ {
            if tmp[j] == string(s[i]){
                count = count - j
                tmp = tmp[j+1:]
                tmp = append(tmp, string(s[i]))
                is_in = true
                break
            }
        }
        if is_in == false{
            count ++
            if max_count < count{
                max_count = count
            }
            tmp = append(tmp, string(s[i]))
        }
        
    }
    return max_count
}