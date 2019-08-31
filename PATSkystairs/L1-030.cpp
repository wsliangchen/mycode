#include <cstdio>
#include <cstring>

using namespace std;

struct student
{
    int gender;
    char name[10];
    bool visited;
};


int main()
{
    int n;
    scanf("%d", &n);
    student stu[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d%s", &stu[i].gender, stu[i].name);
        stu[i].visited = false;
    }
    
    for(int i = 0; i < n; i++)
    {
        if (stu[i].visited == true) {
            continue;
        }
        int highgender = stu[i].gender;
        printf("%s ", stu[i].name);
        stu[i].visited = true;
        for(int j = n-1; j >= 0; j--)
        {
            if (stu[j].visited == false && stu[j].gender != highgender) {
                printf("%s\n", stu[j].name);
                stu[j].visited = true;
                break;
            }
        }
    }
    
    return 0;
}
