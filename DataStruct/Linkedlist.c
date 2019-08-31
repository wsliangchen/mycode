#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1

#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
} LNode, *LinkList;

//��ʼ����������
LinkList InitList()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->data = 0;
    L->next = NULL;
    return L;
}

//������������
Status DestroyList(LNode *L)
{
    if(L == NULL)
        return ERROR;
    LinkList P = L;
    while(P->next != NULL)
    {
        LinkList D = P;
        P=P->next;
        free(D);
    }
    free(P);
    return OK;
}


//��������Ϊ�ձ�
Status ClearList(LNode *L)
{
    if(L->next == NULL||L == NULL)
        return ERROR;
    LinkList P = L->next;
    L->next = NULL;

    while(P->next != NULL)
    {
        LinkList D = P;
        P=P->next;
        free(D);
    }
    free(P);
    return OK;
}

//�жϱ��Ƿ�Ϊ��
Status ListEmpty(LNode *L)
{
    if(L == NULL)
    {
        printf("������\n");
        return FALSE;
    }

    if(L->next != NULL)
        return FALSE;
    return TRUE;
}

//��������ĳ���
int ListLength(LNode *L)
{
    if(L == NULL)
    {
        printf("������\n");
        return ERROR;
    }

    int length = 0;
    while(L->next != NULL)
    {
        L=L->next;
        length++;
    }

    return length;
}

//��ȡ���е�i��Ԫ����e����
Status GetElem(LNode *L, int i, ElemType *e)
{
    LinkList P = L;
    int j = 0;
    while(P->next != NULL && j < i-1)
    {
        P = P->next;
        j++;
    }
    if(P->next == NULL || j > i-1)
        return ERROR;
    P = P->next;
    *e = P->data;
    return OK;
}

//���ر��е�һ����e��ͬ��λ��û���򷵻�0
int LocateElem(LNode *L, ElemType e)
{
    int i = 0;
    int flag = 0;
    if(L->next == NULL || L == NULL)
        return ERROR;
    L=L->next;
    while(L != NULL)
    {
        i++;
        if(L->data == e)
        {
            flag = 1;
            break;
        }
        L=L->next;
    }

    if(flag == 1)
        return i;
    return 0;
}

//�ڱ��еĵ�i��λ�����Ԫ��
Status ListInsert(LNode *L, int i, ElemType e)
{
    if(i > ListLength(L))
        return ERROR;
    LinkList add = (LinkList)malloc(sizeof(LNode));
    if(add == NULL)
        return ERROR;
    add->data = e;//����ռ�

    LinkList P = L;
    int j = 0;
    while(P->next != NULL && j<i-1)
    {
        P = P->next;
        j++;
    }
    LinkList Q = P->next;
    P->next = add;
    add->next = Q;
    return OK;
}

//˳�����Ԫ��
Status AddElem(LNode *L, ElemType e)
{
    LinkList P = (LinkList)malloc(sizeof(LNode));
    if(!P)
        return ERROR;
    P->data = e;
    P->next = NULL;
    while(L->next != NULL)
        L = L->next;
    L->next = P;
    return OK;
}

//ɾ����i��Ԫ�ز����ظ�e
Status ListDelete(LNode *L, int i, ElemType *e)
{
    LinkList P = L;
    int j = 0;
    while(P->next != NULL && j<i-1)
    {
        P = P->next;
        j++;
    }
    if(P->next == NULL || j > i-1)
        return ERROR;
    LinkList Q = P->next;
    P->next = Q->next;
    *e = Q->data;
    free(Q);
    return OK;
}

//��������
Status ListTraverse(LNode *L)
{
    int i = 1;
    if(L->next == NULL)
    {
        printf("��Ϊ��\n");
        return ERROR;
    }

    L=L->next;

    while(1)
    {
        printf("��%d��Ԫ��Ϊ%d\n",i,L->data);
        i++;
        if(L->next == NULL)
            break;
        L=L->next;
    }
    return OK;
}

//��ӡ������˵�
void ListMenu()
{
    printf("-----------------------------------\n");
    printf("1.��ʼ�����Ա�.\n");
    printf("2.�鿴���Ƿ�Ϊ��.\n");
    printf("3.˳�����Ԫ��.\n");
    printf("4.�鿴���е�i��Ԫ��.\n");
    printf("5.�鿴��ĳ���.\n");
    printf("6.���ҵ�һ������������e��ͬ������λ��.\n");
    printf("7.�ڵ�i��λ�ò�������e\n");
    printf("8.ɾ��ָ��λ�õ�����\n");
    printf("9.��ձ�\n");
    printf("10.������\n");
    printf("11.���ٱ�\n");
    printf("0.�˳�����\n");
    printf("-----------------------------------\n");
    printf("����������Ҫ���еĲ������:");
}

int main()
{
    int op;
    LNode *list = NULL;
    while(1)
    {
        ListMenu();
        scanf("%d", &op);
        switch(op)
        {
        case 1:
        {
            list = InitList();
            if(list != NULL)
                printf("���ʼ���ɹ�\n");
            else
                printf("���ʼ��ʧ��\n");
            break;
        }
        case 2:
        {
            Status temp = ListEmpty(list);
            if(temp != TRUE)
                printf("��Ϊ��.\n");
            else
                printf("��Ϊ��\n");
            break;
        }
        case 3:
        {
            printf("������Ҫ��������ݣ�ĩβ�����пո�ÿ�������ÿո��������");
            ElemType e;
            int i = 0;
            while(1)
            {
                scanf("%d", &e);
                AddElem(list, e);
                i++;
                if(getchar() == '\n')
                    break;
            }

            if(i != 0)
                printf("�������ݳɹ�,������%d�����ݣ�\n", i);
            else
                printf("��������ʧ�ܣ�\n");
            break;
        }
        case 4:
        {
            int i;
            printf("������Ҫ�鿴�ڼ������ݣ�");
            scanf("%d", &i);
            ElemType e;
            Status st = GetElem(list, i, &e);
            if(st != ERROR)
                printf("��%d������Ϊ%d\n", i, e);
            else
                printf("û���ҵ���%d������\n", i);
            break;
        }
        case 5:
        {
            printf("��ĳ���Ϊ%d\n", ListLength(list));
            break;
        }
        case 6:
        {
            int i;
            printf("������Ҫ�鿴λ�õ����ݣ�");
            scanf("%d", &i);
            int e = LocateElem(list, i);
            if(e != ERROR)
                printf("��һ�������ݵ�λ��Ϊ%d.\n", e);
            else
                printf("���в����ڸ�����.\n");
            break;
        }
        case 7:
        {
            printf("������Ҫ�������ݵ�λ�ã�");
            int i;
            scanf("%d", &i);
            printf("������Ҫ��������ݣ�");
            ElemType e;
            scanf("%d", &e);
            Status st = ListInsert(list, i, e);
            if(st == ERROR)
                printf("��������ʧ��\n");
            else
                printf("�������ݳɹ�\n");
            break;
        }
        case 8:
        {
            printf("������Ҫɾ�����ݵ�λ�ã�");
            int i;
            scanf("%d", &i);
            ElemType e;
            ListDelete(list, i, &e);
            if(e == ERROR)
                printf("ɾ������ʧ��!\n");
            else
                printf("�ɹ�ɾ����%d������%d\n", i, e);
            break;
        }
        case 9:
        {
            Status st = ClearList(list);
            if(st != ERROR)
                printf("��ձ�ɹ�\n");
            else
                printf("��ձ�ʧ��\n");
            break;
        }
        case 10:
        {
            Status st = ListTraverse(list);
            if(st == ERROR)
                printf("������ʧ��\n");
            else
                printf("������ɹ�\n");
            break;
        }
        case 11:
        {
            Status st = DestroyList(list);
            if(st == ERROR)
                printf("���ٱ�ʧ��\n");
            else
                printf("���ٱ�ɹ�\n");
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
