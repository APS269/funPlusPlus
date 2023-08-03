#include <bits/stdc++.h>
using namespace std;
int main()
{
    int flag = 0;
    vector<int> b{12, 4, 2, 14, 5};
    for (int count = 1; count <= b.size() - 1; count++)
    {

        for (int j = 0; j <= b.size() - 2; j++)
        {

            if (b[j] > b[j + 1])
            {

                swap(b[j], b[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }

    for (int i = 0; i < b.size(); i++)
    {

        cout << b[i] << " ";
    }

    return 0;
}
