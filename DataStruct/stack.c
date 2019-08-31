#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1

#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct {
    Node *base;
    Node *top;
    int stackSize;
} SqStack;

//初始化栈
SqStack *InitStack() {
    SqStack *S = (SqStack *)malloc(sizeof(SqStack));
    if (!S) {
        printf("栈初始化失败\n");
        return NULL;
    }
    S->top = S->base = NULL;
    S->stackSize = 0;
    return S;
}

//判断栈是否为空
Status StackEmpty(SqStack *S) {
    if (!S) {
        printf("栈未初始化\n");
        return ERROR;
    }

    if (NULL == S->top || S->stackSize == 0) {
        return TRUE;
    }
    return FALSE;
}

//返回栈的大小
int StackLength(SqStack *S) {
    if (!S) {
        printf("栈未初始化\n");
        return ERROR;
    }
    if (StackEmpty(S) == TRUE)
        return 0;
    return S->stackSize;
}
//入栈
Status Push(SqStack *S, ElemType e) {
    if (!S) {
        printf("栈未初始化\n");
        return ERROR;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
        return NULL;
    node->data = e;
    node->next = S->top;
    S->top = node;
    if (S->base == NULL)
        S->base = node;
    S->stackSize++;
    return OK;
}

//出栈
Status Pop(SqStack *S, ElemType *e) {
    if (!S) {
        printf("栈未初始化\n");
        return ERROR;
    }
    if (StackEmpty(S) == TRUE || S->stackSize == 0) {
        return ERROR;
    }

    Node *p = S->top;
    *e = p->data;
    S->top = p->next;
    free(p);
    S->stackSize--;
    return OK;
}

//获取栈顶元素
Status GetTop(SqStack *S, ElemType *e) {
    if (!S) {
        printf("栈未初始化\n");
        return ERROR;
    }
    if (StackEmpty(S) == TRUE || S->stackSize == 0) {
        printf("栈为空\n");
        return ERROR;
    }

    *e = S->top->data;
    return OK;
}

//销毁栈
Status Destroy(SqStack *S) {
    if (!S) {
        printf("栈未初始化\n");
        return ERROR;
    }
    S->top = S->base = NULL;
    S->stackSize = 0;
    free(S);
    return OK;
}

//清空栈
Status ClearStack(SqStack *S) {
    if (!S) {
        printf("栈未初始化\n");
        return ERROR;
    }
    if (StackEmpty(S) == TRUE)
        return OK;
    while (1) {
        Node *p = S->top;
        S->top = p->next;
        free(p);
        S->stackSize--;
        if (StackEmpty(S) == TRUE || S->stackSize == 0)
            break;
    }
    return OK;
}

//遍历栈
Status StackTraverse(SqStack *S) {
    if (!S) {
        printf("栈未初始化\n");
        return ERROR;
    }
    if (StackEmpty(S) == TRUE || S->stackSize == 0) {
        printf("栈为空\n");
        return ERROR;
    }

    int i = S->stackSize;
    Node *n = S->top;
    while (1) {
        Node *p = n;
        ElemType e = p->data;
        n = p->next;
        printf("栈的第%d个元素为%d\n", i, e);
        i--;
        if (i == 0)
            break;
    }
    return OK;
}

//打印栈操作菜单
void ListMenu() {
    printf("-----------------------------------\n");
    printf("1.初始化栈.\n");
    printf("2.查看栈是否为空.\n");
    printf("3.入栈.\n");
    printf("4.获取栈顶元素.\n");
    printf("5.查看栈的大小\n");
    printf("6.出栈\n");
    printf("7.清空栈\n");
    printf("8.遍历栈\n");
    printf("9.销毁栈\n");
    printf("0.退出程序\n");
    printf("-----------------------------------\n");
    printf("请输入您需要进行的操作编号:");
}

int main() {
    SqStack *s = NULL;
    int op;
    while (1) {
        ListMenu();
        scanf("%d", &op);
        switch (op) {
        case 1: {
            s = InitStack();
            if (s != NULL)
                printf("栈初始化成功\n");
            else
                printf("栈初始化失败\n");
            break;
        }
        case 2: {
            Status temp = StackEmpty(s);
            if (temp != TRUE)
                printf("栈不为空.\n");
            else
                printf("栈为空\n");
            break;
        }
        case 3: {
            printf(
                "请输入要入栈的数据（末尾不能有空格，每条数据用空格隔开）：");
            ElemType e;
            int i = 0;
            while (1) {
                scanf("%d", &e);
                Push(s, e);
                i++;
                if (getchar() == '\n')
                    break;
            }

            if (i != 0)
                printf("插入数据成功,插入了%d条数据！\n", i);
            else
                printf("插入数据失败！\n");
            break;
        }
        case 4: {
            ElemType e;
            Status st = GetTop(s, &e);
            if (st != ERROR)
                printf("栈顶元素数据为%d\n", e);
            else
                printf("栈顶没有数据\n");
            break;
        }
        case 5: {
            printf("栈的大小为%d\n", StackLength(s));
            break;
        }
        case 6: {
            printf("出栈:\n");
            while (1) {
                ElemType e;
                Status st = Pop(s, &e);
                if (st == ERROR)
                    break;
                printf("%d ", e);
            }
            printf("\n");
            break;
        }
        case 7: {
            Status st = ClearStack(s);
            if (st == ERROR)
                printf("清空栈失败\n");
            else
                printf("清空栈成功\n");
            break;
        }
        case 8: {
            Status st = StackTraverse(s);
            if (st == ERROR) {
                printf("遍历栈失败\n");
            } else
                printf("遍历栈成功\n");
            break;
        }
        case 9: {
            Status st = Destroy(s);
            if (st == OK)
                printf("销毁成功\n");
            else
                printf("销毁失败,栈为空或不存在\n");
            break;
        }
        case 0:
            return 0;
        default:
            printf("输入错误\n");
            break;
        }
    }
    return 0;
}
