#include <vector>
using std::vector;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        Node* origin = new Node(1);
        if (!node->neighbors.empty())
        {
            // 첫번째 노드랑 마지막 노드가 반드시 연결되어있는지;
            // 간선 수가 첫번째가 가장 많은지 모르겠음;;;;
            int numEdge = node->neighbors.size();
            int endVal = node->neighbors[numEdge - 1]->val;

            Node** nodeList = new Node * [endVal];
            nodeList[0] = origin;
            for (int i = 1; i < endVal; i++)
            {
                nodeList[i] = new Node(i + 1);
            }

            Node* curr_origin = node;
            for (int i = 0; i < endVal; i++)
            {
                for (int j = 0; j < curr_origin->neighbors.size(); j++)
                {
                    // visit 여부를 확인해서 추가해야함;;;;;
                    nodeList[i]->neighbors.push_back(nodeList[curr_origin->neighbors[j]->val - 1]);
                }
            }

            delete[] nodeList;
        }

        return origin;
    }
};

int main()
{
    Solution s;

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n3);
    n2->neighbors.push_back(n1);
    n3->neighbors.push_back(n1);

    s.cloneGraph(n1);

    delete n1, n2, n3;

    return 0;
}