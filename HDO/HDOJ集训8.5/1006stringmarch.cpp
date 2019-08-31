#include<iostream>
#include<cstring>
using namespace std;
const int MAX=1000100;
int Next[MAX],extend[MAX];
char s1[MAX],s2[MAX];
void getNext(char str[])
{
    int i=0,j,po,len=strlen(str);
    Next[0]=len;
    while(str[i]==str[i+1] && i+1<len) i++; Next[1]=i;
    po=1;
    for(i=2;i<len;i++)
    {
        if(Next[i-po]+i < Next[po]+po)
            Next[i]=Next[i-po];
        else
        {
            j = Next[po]+po-i;
            if(j<0) j=0;
            while(i+j<len && str[j]==str[j+i]) j++; Next[i]=j;
            po=i; 
        }
    }
}
void EXKMP(char s1[],char s2[])
{
    int i=0,j,po,len=strlen(s1),l2=strlen(s2);
    getNext(s2);
    while(s1[i]==s2[i] && i<l2 && i<len) i++; extend[0]=i;
    po=0;
    for(i=1;i<len;i++)
    {
        if(Next[i-po]+i < extend[po]+po)
            extend[i]=Next[i-po];
        else
        {
            j = extend[po]+po-i;
            if(j<0) j=0; //如果i>extend[po]+po则要从头开始匹配
            while(i+j<len && j<l2 && s1[j+i]==s2[j]) j++; extend[i]=j;
            po=i; //更新po的位置
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--)
    {   
        getchar();
        scanf("%s",s1);
        for(int i=0;s1[i]!='\0';i++)s2[i]=s1[i];
        getNext(s1);
        EXKMP(s1,s2);
        long long ans=0;
        int h=strlen(s1);
        h--;
        for(int i=1;i<=h;i++)
        {
            ans+=extend[i];
            if(extend[i]<h-i+1)ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
