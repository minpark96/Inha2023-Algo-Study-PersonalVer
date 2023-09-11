class Solution {
	struct Graph
	{
		vector<vector<int>> adjList;

		Graph(vector<vector<int>> const& edges, int n)
		{
			adjList.resize(n);

			for (int i = 0; i < edges.size(); i++)
			{
				adjList[edges[i][1]].push_back(edges[i][0]);
			}
		}
	};

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// �׷��� ����
		Graph graph(prerequisites, numCourses);

		// ��尡 �߰ߵǾ����� ���� ����
		vector<bool> discovered(numCourses);

		// DFS���� ����� ��� �ð� ����
		vector<int> departure(numCourses);

		int time = 0;

		// �߰ߵ��� ���� ��� ��忡�� DFS ��ȸ ����
		// �׷����� ����� ��� ���� ��Ҹ� �湮
		for (int i = 0; i < numCourses; i++)
		{
			if (!discovered[i])
			{
				DFS(graph, i, discovered, departure, time);
			}
		}

		// �־��� ���� �׷����� DAG���� Ȯ��
		for (int u = 0; u < numCourses; u++)
		{
			// (u, v)�� �� ������ �����ϴ��� Ȯ��
			for (int i = 0; i < graph.adjList[u].size(); i++)
			{
				int v = graph.adjList[u][i];

				// ��� 'v'�� ��� �ð��� ��� 'u' ��� �ð����� ũ�ų� ������ �� ������ �����Ѵ�.
				// departure[u] <= departure[v] �̸� ����Ŭ ����
				if (departure[u] <= departure[v])
				{
					return false;
				}
			}
		}

		// ����Ŭ ����
		return true;
	}

	// �׷����� DFS�� �����ϰ� ��� ����� ��� �ð��� ����
	void DFS(Graph const& graph, int v, vector<bool>& discovered, vector<int>& departure, int& time)
	{
		// ���� ��带 �߰ߵ� ������ ǥ��
		discovered[v] = true;

		// ��� ����(v, u)�� ���� ����
		for (int i = 0; i < graph.adjList[v].size(); i++)
		{
			int u = graph.adjList[v][i];

			// 'u'�� ���� �߰ߵ��� ���� ���
			if (!discovered[u])
			{
				DFS(graph, u, discovered, departure, time);
			}
		}

		// ������ �غ�
		// ��� 'v'�� ��� �ð� ����
		departure[v] = time++;
	}
};