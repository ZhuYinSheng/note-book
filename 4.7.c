#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define ADDNUM 9
#define ADDPOS 3
#define DELPOS 3
#define SEARCHNUM 4
#define MODIFYNUM 27

typedef struct {
    int *head;       //顺序表指针变量
    int length;      //记录当前顺序表的长度
    int capacity;    //记录顺序表分配的存储容量
    
} SeqList;

/*初始化顺序表*/
SeqList initSeqList() {
    SeqList list;
    list.head = (int *)malloc(SIZE * sizeof(int));
    
    if (!list.head) {
        printf("初始化失败！\n");
        exit(0);
    }
    
    list.length = 0;
    list.capacity = SIZE;
    return list;
}

/*显示顺序表*/
void displayList(SeqList list) {
    for (int i = 0; i < list.length; i++) {
        printf("%d  ", list.head[i]);
    }
    
    printf("\n");
}

/*增*/
SeqList add(SeqList list, int elem, int pos) {
    //插入位置判断，取值范围为0～length
    if (pos > list.length  || pos < 0) {
        printf("插入位置有误\n");
        return list;
    }
    
    //重新分配内存
    if (list.length == list.capacity) {
        int *temp = (int *)realloc(list.head, (list.capacity <<= 1) * sizeof(int));
        
        if (!temp) {
            printf("内存分配失败！\n");
            return list;
        }
        
        list.head = temp;
        list.capacity += 1;
    }
    
    //插入位置及以后的元素依次后移一位
    for (int i = list.length - 1; i >= pos ; i--) {
        list.head[i + 1] = list.head[i];
    }
    
    list.head[pos] = elem;//元素插入空出的位置
    
    list.length++;//表长度+1
    return list;
}

/*删*/
SeqList delete(SeqList list , int pos) {
    //删除位置判断，取值范围为0～length-1
    if (pos >= list.length || pos < 0) {
        printf("删除位置有误\n");
        return list;
    }
    
    //将删除位置后续元素依次前移
    for (int i = pos ; i < list.length - 1 ; i++) {
        list.head[i] = list.head[i + 1];
    }
    
    list.length--;//表长度-1
    
    if (list.length <= (list.capacity >> 1)){
        int new_capacity = list.capacity >> 1;
        int* temp = realloc(list.head, new_capacity * sizeof(int));
        if (temp == NULL){
            printf("realloc is failed\n");
        } else {
            list.head = temp;
            list.capacity = new_capacity;
        }
    }
    
    return list;
}

/*查*/
int search(SeqList list , int elem) {
    //顺序查找
    for (int i = 0; i < list.length; i++) {
        if (list.head[i] == elem) {
            return i ;
        }
    }
    
    return -1;
}

/*改*/
SeqList modify(SeqList list , int elem, int val) {
    int pos = search(list, elem);
    list.head[pos] = val;
    return list;
}

int main(void) {
    SeqList list = initSeqList();
    
    for (int i = 0; i < SIZE; i++) {
        list.head[i] = i + 1;
        list.length++;
    }
    
    printf("顺序表中存储的元素分别是：\n");
    displayList(list);
    
    printf("在顺序表的第%d个位置插入元素：%d\n", ADDPOS, ADDNUM);
    list = add(list, ADDNUM, ADDPOS);
    displayList(list);
    
    printf("删除第%d个元素\n", DELPOS);
    list = delete(list, DELPOS);
    displayList(list);
    
    printf("查找元素为%d的位置\n", SEARCHNUM);
    int pos = search(list, SEARCHNUM);
    printf("元素%d的位置为第%d个\n", SEARCHNUM, pos);
    
    printf("将%d修改为%d\n", SEARCHNUM, MODIFYNUM);
    list = modify(list, SEARCHNUM, MODIFYNUM);
    displayList(list);
    
    printf("内存空间为%d  数组长度为%d\n", list.capacity, list.length);
    
    free(list.head);
    list.head = NULL;
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define ADDNUM 9
#define ADDPOS 3
#define DELPOS 3
#define SEARCHNUM 3
#define MODIFYPOS 3
#define MODIFYNUM 27

typedef struct node {
    int elem;
    struct node *next;
} Node;

/*创建一个结点*/
Node *initNode(Node *pre, int elem) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->elem = elem;
    node->next = NULL;
    pre->next = node;
    return node;
}

/*显示链表*/
void display(Node *p) {
    Node *temp = p;
    printf("共%d个元素：", temp->elem);
    
    while (temp->next) {
        temp = temp->next;//跳过头结点
        printf("  %d", temp->elem);
    }
    
    printf("\n");
}

/*增*/
void add(Node *p, int elem, int pos) {
    //插入位置判断，取值范围为0～length
    int length = p->elem;//传入的是头结点，直接取链表长度值
    
    if (pos > length   || pos < 0) {
        printf("插入位置有误\n");
        return;
    }
    
    //找到需要插入位置的上一个结点
    Node *temp = p;
    
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    
    //新建一个结点
    Node *add = (Node *)malloc(sizeof(Node));
    add->elem = elem;
    add->next = temp->next;//将新结点的next指向上一个结点原来的next
    temp->next = add;//将上一个结点指向新结点
    
    p->elem ++;//表长度+1
}

/*删*/
void delete(Node *p, int pos) {
    //删除位置判断，取值范围为0～length-1
    int length = p->elem;//传入的是头结点，直接取链表长度值
    
    if (pos >= length || pos < 0) {
        printf("删除位置有误\n");
        return;
    }
    
    //找到需要删除位置的上一个结点
    Node *temp = p;
    
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    
    Node *del = temp->next;//需要删除的结点
    temp->next = del->next;//将上一个结点的指针指向删除结点的后一个结点
    free(del);//释放内存
    del = NULL;
    
    p->elem --;//表长度-1
}

/*查*/
int search(Node *p , int elem) {
    int i = 0;
    Node *temp = p;
    
    while (temp->next) {
        temp = temp->next;
        
        if (temp->elem == elem) {
            return i;
        }
        
        i++;
    }
    
    return -1;
}

/*改*/
void modify(Node *p, int pos, int val) {
    Node *temp = p;
    
    for (int i = 0; i < pos + 1 ; i++) {
        temp = temp->next;
    }
    
    temp->elem = val;
}

void freeNode(Node *p) {
    Node *cur = p;
    Node *next;
    
    while (cur->next) {
        next = cur->next;
        free(cur);
        cur = NULL;
        cur = next;
    }
}

int main(void) {
    Node *head = (Node *)malloc(sizeof(Node));//创建头结点
    head ->elem = 0;
    head ->next = NULL;
    
    for (int i = 0; i <100; i++) {
        add(head, i, 0);
        display(head);
    }
    for (int i = 0; i <100; i++) {
        add(head, 0);
        display(head);
    }
    return 0;
}
