class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;
        Node* anss = head;
        Node* ans = anss;
        Node* neeche = flatten(head->child);
        Node* aage = flatten(head->next);
        if (neeche) {
            ans->next = neeche;
            neeche->prev = ans; 
            while (ans->next) {
                ans = ans->next;
            }
        }
        ans->next = aage;
        if (aage) {
            aage->prev = ans; 
        }
        head->child = NULL;
        return anss;
    }
};
