// https://leetcode.cn/problems/design-graph-with-shortest-path-calculator/

class Graph {
private:
    vector<vector<int>> g;
    int sz;
public:
    Graph(int n, vector<vector<int>>& edges) {
        g = vector<vector<int>>(n, vector<int>(n, INT_MAX/2));
        for (auto& e : edges){
            g[e[0]][e[1]] = e[2];
        }
        sz = n;
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        // 标记路径和最短路径
        // int sz = g.size();
        vector<bool> flag(sz, false);
        vector<int> shortPath(sz ,INT_MAX/2);

        shortPath[node1] = 0;
        for (;;){
            //先遍历未标记最短路径
            int x = -1;
            for (int i = 0; i < sz; ++i){
                if (!flag[i] && (x < 0 || (shortPath[i] < shortPath[x]))){
                    x = i;
                }
            }
            // 可能找到end或没找到，提前结束
            // 要先判断错误，再判断结束
            if (x < 0 || shortPath[x] == INT_MAX/2){
                return -1;
            }
            if (x == node2){
                return shortPath[x];
            }
            // 说明找到最小未标记点,找相邻节点
            for (int i = 0; i < sz; ++i){
                // 这里表现了用INT_MAX/2的好处
                shortPath[i] = min(shortPath[i], shortPath[x] + g[x][i]);
            }

            // 标记
            flag[x] = true;
        }

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
