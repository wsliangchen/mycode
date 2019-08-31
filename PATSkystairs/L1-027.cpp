#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int tel[11], arrs[10] = {0};
    char temp[20];
    scanf("%s", temp);
    for(int i = 0; i < strlen(temp); i++)
    {
        tel[i] = temp[i] - '0';
        arrs[tel[i]]++;
    }
    
    vector<int> arr, index;
    for(int i = 9; i >= 0; i--)
    {
        if (arrs[i] != 0) {
            arr.push_back(i);
        }
    }
    
    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            if (tel[i] == arr[j]) {
                index.push_back(j);
            }
        }
    }
    
    printf("int[] arr = new int[]{");
    for(int i = 0; i < arr.size(); i++)
    {
        printf("%s%d", i==0?"":",",arr[i]);
    }
    printf("};\nint[] index = new int[]{");
    for(int i = 0; i < index.size(); i++)
    {
        printf("%s%d", i==0?"":",",index[i]);
    }
    printf("};");
    return 0;
}
