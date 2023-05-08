/*
input
9
insert 5
insert 2
insert 3
insert 1
delete 3
insert 6
delete 5
deleteFirst
deleteLast

output
1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  Node *NodePointer;

// 連結リストの要素
struct Node {
    int key;
    NodePointer next;
    NodePointer prev;
};

// headとtailを保持する構造体
struct Link {
    NodePointer head;
    NodePointer tail;
};

struct Link LinkEntity = {NULL, NULL};

struct Link *link = &LinkEntity;

// ノードを作成する関数
NodePointer makeOneNode(int x) {
    NodePointer n = (NodePointer)malloc(sizeof(struct Node));
    n->key = x;
    return n;
}

// 引数に与えた数字と同じkeyを持つ最初のノードを検索する関数
NodePointer find(int x) {
    NodePointer n;
    for (n = link->head ; n != NULL ; n = n->next) {
        if (n->key == x)
            return n;
    }

    return NULL;
}

// command insert
void insert(int x) {
    NodePointer new = makeOneNode(x);
    //ノード繋ぎ変え
    if (link->head == NULL && link->tail == NULL) {
        //newからのびる手
        new->next = NULL;
        new->prev = NULL;
        //newへのびる手

        //headとtailを更新
        link->head = new;
        link->tail = new;

    } else {
        //newからのびる手
        new->next = link->head;
        new->prev = NULL;
        //newへのびる手
        link->head->prev = new;
        //headとtailを更新
        link->head = new;
    }
}

// command deleteFirst
void deleteFirst(void) {
    //freeするために保持する
    NodePointer first = link->head;

    // 要素が１個しか無い時
    if (link->head->next == NULL) {
        link->head = NULL;
        link->tail = NULL;
    } else {
        link->head->next->prev = NULL;
        link->head = link->head->next;
    }

    free(first);
}

// command deleteLast
void deleteLast(void) {
    // freeする為に保持する
    NodePointer last = link->tail;

    // 要素が１個しか無い時
    if (link->tail->prev == NULL) {
        link->tail = NULL;
        link->head = NULL;
    // 要素が複数ある時
    } else {
        link->tail->prev->next = NULL;
        link->tail = link->tail->prev;
    }

    free(last);
}

// keyを順番に出力する関数
void printList() {
    NodePointer n;
    for (n = link->head ; n != NULL ; n = n->next) {
        printf("%d", n->key);
        if (n->next != NULL) printf(" ");
    }
    printf("\n");
}

// command delete
void delete(int x) {
    NodePointer beErased = find(x);
    // もしキーxを持つNodeが存在しなかったら
    if (beErased == NULL) return;
    else {
        if (beErased->prev == NULL) deleteFirst();
        else if (beErased->next == NULL) deleteLast();
        // 消す対象がheadでもtailでもなかったら
        else {
            beErased->next->prev = beErased->prev;
            beErased->prev->next = beErased->next;
            free(beErased);
        }
    }

}

int main() {
    // 命令数
    int n;
    scanf("%d", &n);
    // 最大文字数は"deleteFirst\0"で12
    char commands[12];
    int key;

    // 命令の実行
    for (int i = 0 ; i < n ; i++) {
        // 命令の読み込み
        scanf("%s", commands);

        // insert
        if(commands[0] == 'i' ) {
            scanf("%d", &key);
            insert(key);
        }

        // delete
        else if (commands[6] == '\0') {
            scanf("%d", &key);
            delete(key);
        }

        // deleteFirst
        else if (commands[6] == 'F') deleteFirst();

        // deleteLast
        else if (commands[6] == 'L') deleteLast();

    }

    printList();

    return 0;
}
