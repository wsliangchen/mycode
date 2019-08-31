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

//��ʼ��ջ
SqStack *InitStack() {
    SqStack *S = (SqStack *)malloc(sizeof(SqStack));
    if (!S) {
        printf("ջ��ʼ��ʧ��\n");
        return NULL;
    }
    S->top = S->base = NULL;
    S->stackSize = 0;
    return S;
}

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack *S) {
    if (!S) {
        printf("ջδ��ʼ��\n");
        return ERROR;
    }

    if (NULL == S->top || S->stackSize == 0) {
        return TRUE;
    }
    return FALSE;
}

//����ջ�Ĵ�С
int StackLength(SqStack *S) {
    if (!S) {
        printf("ջδ��ʼ��\n");
        return ERROR;
    }
    if (StackEmpty(S) == TRUE)
        return 0;
    return S->stackSize;
}
//��ջ
Status Push(SqStack *S, ElemType e) {
    if (!S) {
        printf("ջδ��ʼ��\n");
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

//��ջ
Status Pop(SqStack *S, ElemType *e) {
    if (!S) {
        printf("ջδ��ʼ��\n");
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

//��ȡջ��Ԫ��
Status GetTop(SqStack *S, ElemType *e) {
    if (!S) {
        printf("ջδ��ʼ��\n");
        return ERROR;
    }
    if (StackEmpty(S) == TRUE || S->stackSize == 0) {
        printf("ջΪ��\n");
        return ERROR;
    }

    *e = S->top->data;
    return OK;
}

//����ջ
Status Destroy(SqStack *S) {
    if (!S) {
        printf("ջδ��ʼ��\n");
        return ERROR;
    }
    S->top = S->base = NULL;
    S->stackSize = 0;
    free(S);
    return OK;
}

//���ջ
Status ClearStack(SqStack *S) {
    if (!S) {
        printf("ջδ��ʼ��\n");
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

//����ջ
Status StackTraverse(SqStack *S) {
    if (!S) {
        printf("ջδ��ʼ��\n");
        return ERROR;
    }
    if (StackEmpty(S) == TRUE || S->stackSize == 0) {
        printf("ջΪ��\n");
        return ERROR;
    }

    int i = S->stackSize;
    Node *n = S->top;
    while (1) {
        Node *p = n;
        ElemType e = p->data;
        n = p->next;
        printf("ջ�ĵ�%d��Ԫ��Ϊ%d\n", i, e);
        i--;
        if (i == 0)
            break;
    }
    return OK;
}

//��ӡջ�����˵�
void ListMenu() {
    printf("-----------------------------------\n");
    printf("1.��ʼ��ջ.\n");
    printf("2.�鿴ջ�Ƿ�Ϊ��.\n");
    printf("3.��ջ.\n");
    printf("4.��ȡջ��Ԫ��.\n");
    printf("5.�鿴ջ�Ĵ�С\n");
    printf("6.��ջ\n");
    printf("7.���ջ\n");
    printf("8.����ջ\n");
    printf("9.����ջ\n");
    printf("0.�˳�����\n");
    printf("-----------------------------------\n");
    printf("����������Ҫ���еĲ������:");
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
                printf("ջ��ʼ���ɹ�\n");
            else
                printf("ջ��ʼ��ʧ��\n");
            break;
        }
        case 2: {
            Status temp = StackEmpty(s);
            if (temp != TRUE)
                printf("ջ��Ϊ��.\n");
            else
                printf("ջΪ��\n");
            break;
        }
        case 3: {
            printf(
                "������Ҫ��ջ�����ݣ�ĩβ�����пո�ÿ�������ÿո��������");
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
                printf("�������ݳɹ�,������%d�����ݣ�\n", i);
            else
                printf("��������ʧ�ܣ�\n");
            break;
        }
        case 4: {
            ElemType e;
            Status st = GetTop(s, &e);
            if (st != ERROR)
                printf("ջ��Ԫ������Ϊ%d\n", e);
            else
                printf("ջ��û������\n");
            break;
        }
        case 5: {
            printf("ջ�Ĵ�СΪ%d\n", StackLength(s));
            break;
        }
        case 6: {
            printf("��ջ:\n");
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
                printf("���ջʧ��\n");
            else
                printf("���ջ�ɹ�\n");
            break;
        }
        case 8: {
            Status st = StackTraverse(s);
            if (st == ERROR) {
                printf("����ջʧ��\n");
            } else
                printf("����ջ�ɹ�\n");
            break;
        }
        case 9: {
            Status st = Destroy(s);
            if (st == OK)
                printf("���ٳɹ�\n");
            else
                printf("����ʧ��,ջΪ�ջ򲻴���\n");
            break;
        }
        case 0:
            return 0;
        default:
            printf("�������\n");
            break;
        }
    }
    return 0;
}
