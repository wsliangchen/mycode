#include <cstdio>
#include <cstring>

using namespace std;
int main() {
    int h, s;
    scanf("%d:%d", &h, &s);

    if (h > 12) {
        int temp = h;
        if (s > 0) {
            temp++;
        }
        for(int i = 0; i < temp-12; i++)
        {
            printf("Dang");
        }
        return 0;
    }
    

    printf("Only %02d:%02d.  Too early to Dang.", h,s);

    return 0;
}
