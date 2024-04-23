/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 17:22
 * @Author Kenton
 */
#include "../head/UndirectedGraph_basicOperation.h"

UndirectedGraph_basicOperation::UndirectedGraph_basicOperation(int numVertices) : numVertices(numVertices){
    // ��ʼ���ڽӾ���Ϊȫ��
    adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    // ��ʼ�����������Ϊ false
    vertices.resize(numVertices, false);
}

bool UndirectedGraph_basicOperation::Adjacent(int x, int y) {
    return adjacencyMatrix[x][y] != 0;
}

void UndirectedGraph_basicOperation::Neighbors(int x) {
    std::cout << "���� " << x << " ���ڽӱ�: ";
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencyMatrix[x][i] != 0) {
            std::cout << "(" << x << ", " << i << ") ";
        }
    }
    std::cout << std::endl;
}

void UndirectedGraph_basicOperation::InsertVertex(int x) {
    if (x >= 0 && x < numVertices) {
        vertices[x] = true;
    }
}

void UndirectedGraph_basicOperation::DeleteVertex(int x) {
    if (x >= 0 && x < numVertices) {
        vertices[x] = false;
        // ɾ���붥��x��صı�
        for (int i = 0; i < numVertices; ++i) {
            adjacencyMatrix[x][i] = 0;
            adjacencyMatrix[i][x] = 0;
        }
    }
}

void UndirectedGraph_basicOperation::AddEdge(int x, int y) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices) {
        adjacencyMatrix[x][y] = 1;
        adjacencyMatrix[y][x] = 1;
    }
}

void UndirectedGraph_basicOperation::RemoveEdge(int x, int y) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices) {
        adjacencyMatrix[x][y] = 0;
        adjacencyMatrix[y][x] = 0;
    }
}

int UndirectedGraph_basicOperation::FirstNeighbor(int x) {
    if (x >= 0 && x < numVertices && vertices[x]) {
        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[x][i] != 0) {
                return i;
            }
        }
    }
    return -1;
}

int UndirectedGraph_basicOperation::NextNeighbor(int x, int y) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices && vertices[x]) {
        for (int i = y + 1; i < numVertices; ++i) {
            if (adjacencyMatrix[x][i] != 0) {
                return i;
            }
        }
    }
    return -1;
}

int UndirectedGraph_basicOperation::Get_edge_value(int x, int y) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices) {
        return adjacencyMatrix[x][y];
    }
    return -1;
}

void UndirectedGraph_basicOperation::Set_edge_value(int x, int y, int weight) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices) {
        adjacencyMatrix[x][y] = weight;
        adjacencyMatrix[y][x] = weight;
    }
}
