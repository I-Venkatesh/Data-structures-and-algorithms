ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *s = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (s != fast)
            {
                s = s->next;
                fast = fast->next;
            }
            return s;
        }
    }
    return NULL;
}