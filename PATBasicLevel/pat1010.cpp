#include <stdio.h>

int main()
{
  int n,e,flag = 0;
  while(scanf("%d%d", &n,&e) == 2)
  {
    if(n*e != 0)
    {
      if(flag != 0)
        printf(" ");
      else
        flag = 1;
      printf("%d %d",n*e,e-1);
    }
  }
  if(flag == 0)
    printf("0 0");
  return 0;
}
