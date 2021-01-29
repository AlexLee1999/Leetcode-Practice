func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var pre *ListNode
    var car = 0
    var start *ListNode
    for (l1 != nil && l2 != nil) {
        val := l1.Val + l2.Val + car
        car = val / 10
        val = val % 10
        var node *ListNode
        node = &ListNode{val, nil}
        if (pre == nil){
            start = node
        }
        if (pre != nil){
            pre.Next = node
        }
        pre = node
        l1 = l1.Next
        l2 = l2.Next
    }
    for (l1 != nil){
        val := l1.Val + car
        car = val / 10
        val = val % 10
        var node *ListNode
        node = &ListNode{val, nil}
        if (pre == nil){
            start = node
        }
        if (pre != nil){
            pre.Next = node
        }
        pre = node
        l1 = l1.Next
    }
    for (l2 != nil){
        val := l2.Val + car
        car = val / 10
        val = val % 10
        var node *ListNode
        node = &ListNode{val, nil}
        if (pre == nil){
            start = node
        }
        if (pre != nil){
            pre.Next = node
        }
        pre = node
        l2 = l2.Next
    }
    if (car == 1){
        var node *ListNode
        node = &ListNode{1, nil}
        pre.Next = node
    }
    return start
}