#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > graph;
queue<int> s1;
vector<int> input;
bool *visited;

void bfs(int start) {
	bool *visit = new bool[graph.size()];
	for (int i = 0; i < graph.size(); i++) {
		visit[i] = false;
	}
	visit[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		s1.push(graph[start][i]);
	}
	input.push_back(start);

	while (!s1.empty()) {
		int visit_node = s1.front();
		s1.pop();
		if (!visit[visit_node]) {
			visit[visit_node] = true;
			input.push_back(visit_node);
			for (int i = 0; i < graph[visit_node].size(); i++) {
				if (!visit[graph[visit_node][i]]) {
					s1.push(graph[visit_node][i]);
				}
			}
		}

	}
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << " ";
	}
}

int main() {
	int v1 = 0, v2 = 0;
	int number, start;
	cin >> number >> start;
	for (int i = 0; i <= number; i++) {
		vector<int> element;
		graph.push_back(element);
	}

	while (true) {
		cin >> v1 >> v2;
		if (v1 == -1 && v2 == -1) {
			break;
		}
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	bfs(start);
}
