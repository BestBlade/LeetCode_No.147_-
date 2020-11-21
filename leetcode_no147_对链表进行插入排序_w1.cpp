/* ------------------------------------------------------------------|
对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：48 ms, 在所有 C++ 提交中击败了48.21%的用户
*	内存消耗：9.7 MB, 在所有 C++ 提交中击败了36.80%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    ListNode* dummyHead = new ListNode(0);

    ListNode* pre = dummyHead;
    ListNode* now = head;

    while (now) {
        while (pre->next && now->val > pre->next->val) {
            pre = pre->next;
        }

        ListNode* next = now->next;
        now->next = pre->next;
        pre->next = now;

        now = next;
        pre = dummyHead;
    }
    return dummyHead->next;
}

int main() {
    ListNode* head = new ListNode(4);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(3);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;

    ListNode* res = insertionSortList(head);
}
