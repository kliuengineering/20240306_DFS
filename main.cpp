#include <iostream>

class Graph 
{
private:
    int** adjacencyMatrix;
    int vertexCount;

public:
    Graph(int vertexCount) 
    {
        this->vertexCount = vertexCount;
        adjacencyMatrix = new int* [vertexCount];
        for (int i = 0; i < vertexCount; ++i) 
        {
            adjacencyMatrix[i] = new int[vertexCount];
            for (int j = 0; j < vertexCount; ++j)
                adjacencyMatrix[i][j] = 0;
        }
    }

    void addEdge(int i, int j, int weight = 1) 
    {
        if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) 
        {
            adjacencyMatrix[i][j] = weight;
            adjacencyMatrix[j][i] = weight; // For undirected graph
        }
    }

    void removeEdge(int i, int j) 
    {
        if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) 
        {
            adjacencyMatrix[i][j] = 0;
            adjacencyMatrix[j][i] = 0; // For undirected graph
        }
    }

    bool isEdge(int i, int j) 
    {
        if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount)
            return adjacencyMatrix[i][j] != 0;
        else
            return false;
    }

    void display() 
    {
        for (int i = 0; i < vertexCount; ++i) 
        {
            for (int j = 0; j < vertexCount; ++j)
                std::cout << adjacencyMatrix[i][j] << " ";
            std::cout << std::endl;
        }
    }

    ~Graph() 
    {
        for (int i = 0; i < vertexCount; ++i)
            delete[] adjacencyMatrix[i];
        delete[] adjacencyMatrix;
    }
};

int main() 
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.display();

    return 0;
}