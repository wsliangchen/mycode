#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    string fname, fid, mid, mname;
    int mlow = 101, fhigh = -1;

    for (int i = 0; i < n; i++)
    {
        string tname, tid;
        char gender;
        int s;
        cin >> tname >> gender >> tid >> s;
        if (gender == 'M' && s <= mlow)
        {
            mname = tname;
            mid = tid;
            mlow = s;
        }
        else if (gender == 'F' && s >= fhigh)
        {
            fname = tname;
            fid = tid;
            fhigh = s;
        }
    }
    

    if (fhigh != -1)
        cout << fname << " " << fid << endl;
    else
        cout << "Absent" << endl;
    if (mlow != 101)
        cout << mname << " " << mid << endl;
    else
        cout << "Absent" << endl;
    
    if (mlow != 101 && fhigh != -1)
        cout << fhigh - mlow;
    else
        cout << "NA";


    return 0;
}