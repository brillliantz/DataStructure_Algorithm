


Node *Reverse(Node *head) {

Node *left, *mid, *right;
left = nullptr;
mid = head;

    while (mid != nullptr) {
        // left->next is set in last loop
        // therefore the connection between left and mid is broken
        right = mid->next; // store the right node
        mid->next = left; // set mid->next
        // use next 2 lines to get left and mid ready for next loop
        left = mid;
        mid = right;
    }

    return left;
}
