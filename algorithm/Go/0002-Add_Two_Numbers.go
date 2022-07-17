/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{}
    ptr := dummy
    carry := 0
    for l1 != nil && l2 != nil {
        sum := carry + l1.Val + l2.Val
        ptr.Next = &ListNode{Val:sum % 10}
        carry = sum / 10
        ptr = ptr.Next
        l1 = l1.Next
        l2 = l2.Next
    }
    for l1 != nil {
        sum := carry + l1.Val
        ptr.Next = &ListNode{Val:sum % 10}
        carry = sum / 10
        ptr = ptr.Next
        l1 = l1.Next
    }
    for l2 != nil {
        sum := carry + l2.Val
        ptr.Next = &ListNode{Val:sum % 10}
        carry = sum / 10
        ptr = ptr.Next
        l2 = l2.Next
    }
    if carry != 0 {
        ptr.Next = &ListNode{Val:carry}
    }
    return dummy.Next
}
// Time : O(m + n)
// Space : O(1)