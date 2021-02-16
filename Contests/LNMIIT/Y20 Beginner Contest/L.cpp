#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int numOfVertices;
    vector<int> *vertices;
    int *nonLoop;
    void loopLengthDFS(int start, vector<bool> visited);
public:
    Graph(int numOfVertices): numOfVertices(numOfVertices)
    {
        this->vertices = new vector<int>[this->numOfVertices];
        this->nonLoop = new int[this->numOfVertices];
    }
    void addEdge(int v, int w) { vertices[v].push_back(w); }
    int* longestLoop();
};

void Graph::loopLengthDFS(int start, vector<bool> visited)
{
    visited[start] = 1;
    int adjacent;
    for(int i = 0; i < this->vertices[start].size(); i++)
    {
        adjacent = this->vertices[start][i];
        if(!visited[adjacent])
        {
            this->loopLengthDFS(adjacent, visited);
        }
        else
        {
            this->nonLoop[start] = 1;
        }
    }
}

int* Graph::longestLoop()
{
    for(int i = 0; i < this->numOfVertices; i++)
    {
        vector<bool> visited(this->numOfVertices + 1, 0);
        this->loopLengthDFS(i, visited);
    }
    return this->nonLoop;
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    Graph *cities = new Graph(n);
    for(int i = 0; i < m; i++)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        cities->addEdge(x - 1, y - 1);
    }
    int *v = cities->longestLoop();
    int count = 0;
    vector<int> ans(0);
    for(int i = 0; i < n; i++)
    {
        if(v[i] == 0)
        {
            count++;
            ans.push_back(i + 1);
        }
    }
    cout << count << "\n";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}