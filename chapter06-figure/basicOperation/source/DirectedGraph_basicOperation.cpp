/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/4/18 17:31
 * @Author Kenton
 */
#include "../head/DirectedGraph_basicOperation.h"

DirectedGraph_basicOperation::DirectedGraph_basicOperation(int numVertices) : numVertices(numVertices) {
    // ��ʼ���ڽӾ���Ϊȫ��
    adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    // ��ʼ�����������Ϊ false
    vertices.resize(numVertices, false);
}

bool DirectedGraph_basicOperation::Adjacent(int x, int y) {
    return adjacencyMatrix[x][y] != 0;
}

void DirectedGraph_basicOperation::Neighbors(int x) {
    std::cout << "���� " << x << " ���ڽӱ�: ";
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencyMatrix[x][i] != 0) {
            std::cout << "(" << x << ", " << i << ") ";
        }
    }
    std::cout << std::endl;
}

void DirectedGraph_basicOperation::InsertVertex(int x) {
    if (x >= 0 && x < numVertices) {
        vertices[x] = true;
    }
}

void DirectedGraph_basicOperation::DeleteVertex(int x) {
    if (x >= 0 && x < numVertices) {
        vertices[x] = false;
        // ɾ���붥��x��صı�
        for (int i = 0; i < numVertices; ++i) {
            adjacencyMatrix[x][i] = 0;
        }
    }
}

void DirectedGraph_basicOperation::AddEdge(int x, int y) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices) {
        adjacencyMatrix[x][y] = 1;
    }
}

void DirectedGraph_basicOperation::RemoveEdge(int x, int y) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices) {
        adjacencyMatrix[x][y] = 0;
    }
}

int DirectedGraph_basicOperation::FirstNeighbor(int x) {
    if (x >= 0 && x < numVertices && vertices[x]) {
        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[x][i] != 0) {
                return i;
            }
        }
    }
    return -1;
}

int DirectedGraph_basicOperation::NextNeighbor(int x, int y) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices && vertices[x]) {
        for (int i = y + 1; i < numVertices; ++i) {
            if (adjacencyMatrix[x][i] != 0) {
                return i;
            }
        }
    }
    return -1;
}

int DirectedGraph_basicOperation::Get_edge_value(int x, int y) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices) {
        return adjacencyMatrix[x][y];
    }
    return -1;
}

void DirectedGraph_basicOperation::Set_edge_value(int x, int y, int weight) {
    if (x >= 0 && x < numVertices && y >= 0 && y < numVertices) {
        adjacencyMatrix[x][y] = weight;
    }
}
