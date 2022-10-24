/*
当 k 个日程安排有一些时间上的交叉时（例如 k 个日程安排都在同一时间内），就会产生 k 次预订。

给你一些日程安排 [start, end) ，请你在每个日程安排添加后，返回一个整数 k ，表示所有先前日程安排会产生的最大 k 次预订。

实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。

MyCalendarThree() 初始化对象。
int book(int start, int end) 返回一个整数 k ，表示日历中存在的 k 次预订的最大值。
 
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/my-calendar-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class MyCalendarThree {
    map<int, int> mp;
public:
    MyCalendarThree() {
        mp.clear();
    }

    int book(int startTime, int endTime) {
        int mx = 1, sum = 0;
        mp[startTime]++;
        mp[endTime]--;
        for (auto e : mp)
        {
            sum += e.second;
            mx = max(sum, mx);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */