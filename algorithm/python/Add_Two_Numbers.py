class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sum1 = 0
        count1 = 0
        while l1:
            sum1 += l1.val* (10**count1)
            l1 = l1.next
            count1 += 1
        print(sum1)
        sum2 = 0
        count2 = 0
        while l2:
            sum2 += l2.val* (10**count2)
            l2 = l2.next
            count2 += 1
        print(sum2)
        su = sum1 + sum2
        pre = None
        st = str(su)
        
        for i in range(len(st)):
            node = ListNode(int(st[i]), pre)
            pre = node
        return pre
            
            
        