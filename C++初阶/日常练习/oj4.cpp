#define _CRT_SECURE_NO_WARNINGS 1

/*  1

ţţ�ٰ���һ�α�̱���,�μӱ�������3*n��ѡ��,ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������,һ�����n������,��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
����:
һ������������Ա��ˮƽֵ�ֱ���3,3,3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���3,2,3.��ô�����ˮƽֵ��3
һ������������Ա��ˮƽֵ�ֱ���1,5,2.��ô�����ˮƽֵ��2
Ϊ���ñ������п���,ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
��������ʾ:
���ţţ��6����Ա���ֵ���������
�������Ϊ:
team1:{1,2,5}, team2:{5,5,8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
���������Ϊ:
team1:{2,5,8}, team2:{1,5,5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
û�б��ܺ�Ϊ10����ķ���,�������10.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int sz;
    cin >> sz;
    vector<int> vv;
    vv.resize(3 * sz);

    for (int i = 0; i < 3 * sz; i++)
    {
        cin >> vv[i];
    }
    sort(vv.begin(), vv.end());
    long long sum = 0;
    for (int i = 0; i < sz; i++)
    {
        sum += vv[sz + 2 * i];
    }
    cout << sum << endl;
    return 0;
}


/*  2
���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?page=1&onlyReference=false
��Դ��ţ����

ţţ��������������Ϊһ��������һ��������������,��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A,��������һ�������ǰ�����A��Ϊ���ɶ�����������,ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ,ţţ���԰�����A����Ϊ[1,2,3]��[2,2,1]��������������,������Ҫ����Ϊ2������������,�������2
*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> vv;
    vv.resize(n + 1);//���������ж�[n+1]
    for (int i = 0; i < n; i++)
    {
        cin >> vv[i];
    }
    int i = 0, count = 0;

    while (i < n)
    {
        //�ǵ���
        if (vv[i] < vv[i + 1])
        {
            while (i < n && vv[i] <= vv[i + 1])
            {
                i++;
            }
            count++;
            i++;
        }
        //���
        else if (vv[i] == vv[i + 1])
            i++;
        //�ǵݼ�
        else
        {
            while (i < n && vv[i] >= vv[i + 1])
            {
                i++;
            }
            count++;
            i++;
        }
    }
    cout << count << endl;

    return 0;
}

/*  3
��һ������Ϊ n �����飬��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������[1,2,3,2,2,2,5,4,2]����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��

���ݷ�Χ��n \le 50000n��50000��������Ԫ�ص�ֵ 0 \le val \le 100000��val��10000
Ҫ�󣺿ռ临�Ӷȣ�O(1)O(1)��ʱ�临�Ӷ� O(n)O(n)
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int sz = numbers.size();
        sort(numbers.begin(), numbers.end());
        int count = 0, x = numbers[0];
        for (int i = 0; i < sz; i++)
        {
            if (numbers[i] == x)
                count++;
            else
                count--;
            if (count < 0)
            {
                count = 0;
                x = numbers[i];
            }
        }
        return x;
    }
};

/*  4

���ӣ�https://www.nowcoder.com/questionTerminal/02d8d42b197646a5bbd0a98785bb3a34
��Դ��ţ����

A,B,C�������Ǻ�����,ÿ�������ﶼ��һЩ�ǹ�,���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�,��������֪�����µ���Ϣ��
A - B, B - C, A + B, B + C. ���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�,��A,B,C�����ﱣ֤���ֻ��һ������A,B,C������������������

���Ϊһ�У�����������������A��B��C��˳�����A��B��C���ÿո��������ĩ�޿ո� �������������������A��B��C�������No
*/

#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    int A, B1, B2, C;
    cin >> a >> b >> c >> d;
    A = (a + c) / 2;
    B1 = (d + b) / 2;
    B2 = (c - a) / 2;
    C = (d - b) / 2;

    if (B1 != B2)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << A << " " << B1 << " " << C << endl;
    }

    return 0;
}


/*   5

����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int m, m1, n;
    cin >> m >> n;
    m1 = m;
    bool flag = false;
    if (m < 0)
    {
        flag = true;
        m = -m;
    }
    string s = "0123456789ABCDEF";
    string nums;
    while (m > 0)
    {
        nums += s[m % n];
        m /= n;
    }
    if (flag)
        nums += '-';
    reverse(nums.begin(), nums.end());
    if (m1 == 0)
        cout << '0' << endl;
    else
        cout << nums << endl;

    return 0;
}
