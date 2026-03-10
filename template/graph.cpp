#include<iostream>
#include<queue>
using namespace std;

const int MAXV = 100;

// 边节点
struct EdgeNode{
    int adjvex;
    EdgeNode* next;
};

// 顶点节点
struct VertexNode{
    int data;
    EdgeNode* firstEdge;
};

// 图
struct Graph{
    VertexNode adjList[MAXV];
    int numVertex;
    int numEdge;
};



void bfs(Graph &g,int start){
    bool visited[MAXV];
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){

        int v = q.front();
        q.pop();

        cout << v << " ";

        EdgeNode* p = g.adjList[v].firstEdge;

        while(p != NULL){
            int w = p->adjvex;

            if(!visited[w]){
                visited[w] = true;
                q.push(w);
            }

            p = p->next;
        }
    }
}



void dfs(Graph &g, int v){
    bool visited[MAXV];
    visited[v] = true;
    cout << v << " ";

    EdgeNode* p = g.adjList[v].firstEdge;

    while(p != NULL){

        int w = p->adjvex;

        if(!visited[w]){
            dfs(g, w);
        }

        p = p->next;
    }
}