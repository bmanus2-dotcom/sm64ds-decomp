typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

struct Node {
    void* x0;
    struct Node* next;  /* 0x4 */
    int* x8;            /* 0x8 */
};

struct Node* func_02043f98(struct Node** head, int key) {
    struct Node* node = *head;
    while (node != 0) {
        int b = (int)(node->x8[1] != key);
        if (b == 0) return node;
        node = node->next;
    }
    return 0;
}
