#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution {
private:
    const int INF = 1e9;
    const int N = 1e5;

private:
    int dijkstra(int V, vector<pair<int, int>> graph[], int S , int end) {
        vector<int> dist(N + 1, INF);

        set<pair<int, int>> st;
        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty()) {
            auto top = *st.begin();
            int node = top.second;

            st.erase(st.begin());

            for (auto child : graph[node]) {
                int child_v = child.first;
                int child_dist = child.second;

                if (dist[node] + child_dist < dist[child_v]) {
                    dist[child_v] = dist[node] + child_dist;
                    st.insert({dist[child_v], child_v});
                }
            }
        }
        int ans = dist[end];
        return ans;
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k , int end) {
        // convert to adj
        vector<pair<int, int>> graph[N + 1];
        for (auto vec : times) {
            graph[vec[0]].push_back({vec[1], vec[2]});
        }
        return dijkstra(n, graph, k, end);
    }
};

int main() {
    Solution solution;

    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
    }

    int connections;
    cin >> connections;

    vector<vector<int>> times(connections , vector<int>(3));
    for(auto &it : times){
        cin >> it[0] >> it[1] >> it[2];
    }

    int start, end;
    cin >> start;
    cin >> end;

    int result = solution.networkDelayTime(times, n , start , end);
    cout << result << "\n";

    return 0;
}
