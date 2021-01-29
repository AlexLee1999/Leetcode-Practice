class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        pre = None
        car = 0
        start = None
        while l1 and l2:
            val = l1.val+l2.val+car
            car = val//10
            val %= 10
            node = ListNode(val, None)
            if not pre:
                start = node
            if pre:
                pre.next = node
            pre = node
            l2 = l2.next
            l1 = l1.next
        while l1:
            val = l1.val + car
            car = val // 10
            val = val % 10
            node = ListNode(val, None)
            if not pre:
                start = node
            if pre:
                pre.next = node
            pre = node
            l1 = l1.next
        while l2:
            val = l2.val + car
            car = val//10
            val = val % 10
            node = ListNode(val, None)
            if not pre:
                start = node
            if pre:
                pre.next = node
            pre = node
            l2 = l2.next
        if car != 0:
            node = ListNode(1, None)
            pre.next = node
        return start
            
        