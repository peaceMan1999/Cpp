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
        // ���·�������·��
        // int sz = g.size();
        vector<bool> flag(sz, false);
        vector<int> shortPath(sz ,INT_MAX/2);

        shortPath[node1] = 0;
        for (;;){
            //�ȱ���δ������·��
            int x = -1;
            for (int i = 0; i < sz; ++i){
                if (!flag[i] && (x < 0 || (shortPath[i] < shortPath[x]))){
                    x = i;
                }
            }
            // �����ҵ�end��û�ҵ�����ǰ����
            // Ҫ���жϴ������жϽ���
            if (x < 0 || shortPath[x] == INT_MAX/2){
                return -1;
            }
            if (x == node2){
                return shortPath[x];
            }
            // ˵���ҵ���Сδ��ǵ�,�����ڽڵ�
            for (int i = 0; i < sz; ++i){
                // �����������INT_MAX/2�ĺô�
                shortPath[i] = min(shortPath[i], shortPath[x] + g[x][i]);
            }

            // ���
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
