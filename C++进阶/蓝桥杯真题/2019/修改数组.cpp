#include <iostream>
using namespace std;
int main()
{
    int n;
    int a[100005]={0}, b[1000005] = { 0 };
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (b[a[i]] != 0)
        {
            b[a[i]]++;
            a[i]+=(b[a[i]]-1);
        }
        b[a[i]]++;
        cout << a[i] << ' ';
    }
    return 0;
}

