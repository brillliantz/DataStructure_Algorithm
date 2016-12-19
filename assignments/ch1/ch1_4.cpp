template<class T>
int LenOfLinkedlist(T *head) {
    if (!(head->next)) {
        return 1;
    }
    return (1 + LenOfLinkedlist(head->next));
}
