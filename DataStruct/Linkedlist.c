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

//初始化线性链表
LinkList InitList()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->data = 0;
    L->next = NULL;
    return L;
}

//销毁线性链表
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


//将链表置为空表
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

//判断表是否为空
Status ListEmpty(LNode *L)
{
    if(L == NULL)
    {
        printf("表不存在\n");
        return FALSE;
    }

    if(L->next != NULL)
        return FALSE;
    return TRUE;
}

//返回链表的长度
int ListLength(LNode *L)
{
    if(L == NULL)
    {
        printf("表不存在\n");
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

//获取表中第i个元素用e返回
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

//返回表中第一个与e相同的位置没有则返回0
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

//在表中的第i个位置添加元素
Status ListInsert(LNode *L, int i, ElemType e)
{
    if(i > ListLength(L))
        return ERROR;
    LinkList add = (LinkList)malloc(sizeof(LNode));
    if(add == NULL)
        return ERROR;
    add->data = e;//申请空间

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

//顺序添加元素
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

//删除第i个元素并返回给e
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

//遍历链表
Status ListTraverse(LNode *L)
{
    int i = 1;
    if(L->next == NULL)
    {
        printf("表为空\n");
        return ERROR;
    }

    L=L->next;

    while(1)
    {
        printf("第%d个元素为%d\n",i,L->data);
        i++;
        if(L->next == NULL)
            break;
        L=L->next;
    }
    return OK;
}

//打印表操作菜单
void ListMenu()
{
    printf("-----------------------------------\n");
    printf("1.初始化线性表.\n");
    printf("2.查看表是否为空.\n");
    printf("3.顺序插入元素.\n");
    printf("4.查看表中第i个元素.\n");
    printf("5.查看表的长度.\n");
    printf("6.查找第一个与输入数据e相同的数据位置.\n");
    printf("7.在第i个位置插入数据e\n");
    printf("8.删除指定位置的数据\n");
    printf("9.清空表\n");
    printf("10.遍历表\n");
    printf("11.销毁表\n");
    printf("0.退出程序\n");
    printf("-----------------------------------\n");
    printf("请输入您需要进行的操作编号:");
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
                printf("表初始化成功\n");
            else
                printf("表初始化失败\n");
            break;
        }
        case 2:
        {
            Status temp = ListEmpty(list);
            if(temp != TRUE)
                printf("表不为空.\n");
            else
                printf("表为空\n");
            break;
        }
        case 3:
        {
            printf("请输入要插入的数据（末尾不能有空格，每条数据用空格隔开）：");
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
                printf("插入数据成功,插入了%d条数据！\n", i);
            else
                printf("插入数据失败！\n");
            break;
        }
        case 4:
        {
            int i;
            printf("请输入要查看第几个数据：");
            scanf("%d", &i);
            ElemType e;
            Status st = GetElem(list, i, &e);
            if(st != ERROR)
                printf("第%d个数据为%d\n", i, e);
            else
                printf("没有找到第%d个数据\n", i);
            break;
        }
        case 5:
        {
            printf("表的长度为%d\n", ListLength(list));
            break;
        }
        case 6:
        {
            int i;
            printf("请输入要查看位置的数据：");
            scanf("%d", &i);
            int e = LocateElem(list, i);
            if(e != ERROR)
                printf("第一个该数据的位置为%d.\n", e);
            else
                printf("表中不存在该数据.\n");
            break;
        }
        case 7:
        {
            printf("请输入要插入数据的位置：");
            int i;
            scanf("%d", &i);
            printf("请输入要插入的数据：");
            ElemType e;
            scanf("%d", &e);
            Status st = ListInsert(list, i, e);
            if(st == ERROR)
                printf("插入数据失败\n");
            else
                printf("插入数据成功\n");
            break;
        }
        case 8:
        {
            printf("请输入要删除数据的位置：");
            int i;
            scanf("%d", &i);
            ElemType e;
            ListDelete(list, i, &e);
            if(e == ERROR)
                printf("删除数据失败!\n");
            else
                printf("成功删除第%d个数据%d\n", i, e);
            break;
        }
        case 9:
        {
            Status st = ClearList(list);
            if(st != ERROR)
                printf("清空表成功\n");
            else
                printf("清空表失败\n");
            break;
        }
        case 10:
        {
            Status st = ListTraverse(list);
            if(st == ERROR)
                printf("遍历表失败\n");
            else
                printf("遍历表成功\n");
            break;
        }
        case 11:
        {
            Status st = DestroyList(list);
            if(st == ERROR)
                printf("销毁表失败\n");
            else
                printf("销毁表成功\n");
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
