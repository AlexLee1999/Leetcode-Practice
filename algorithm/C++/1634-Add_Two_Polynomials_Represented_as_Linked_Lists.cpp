/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* dummy = new PolyNode();
        PolyNode* ptr = dummy;
        while (poly1 != nullptr && poly2 != nullptr) {
            if (poly1->power < poly2->power) {
                ptr->next = new PolyNode(poly2->coefficient, poly2->power);
                ptr = ptr->next;
                poly2 = poly2->next;
            } else if (poly1->power > poly2->power) {
                ptr->next = new PolyNode(poly1->coefficient, poly1->power);
                ptr = ptr->next;
                poly1 = poly1->next;
            } else {
                if (poly1->coefficient + poly2->coefficient != 0) {
                    ptr->next = new PolyNode(poly1->coefficient + poly2->coefficient, poly1->power);
                    ptr = ptr->next;
                    poly1 = poly1->next;
                    poly2 = poly2->next;
                } else {
                    poly1 = poly1->next;
                    poly2 = poly2->next;
                }
            }
        }
        while (poly1 != nullptr) {
            ptr->next = new PolyNode(poly1->coefficient, poly1->power);
            ptr = ptr->next;
            poly1 = poly1->next;
        }
        while (poly2 != nullptr) {
            ptr->next = new PolyNode(poly2->coefficient, poly2->power);
            ptr = ptr->next;
            poly2 = poly2->next;
        }
        return dummy->next;
    }
};
// Time : O(n)
// Space : O(n)