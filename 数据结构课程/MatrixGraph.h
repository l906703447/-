#pragma once
#include "Queue.h"
#include <vector>

const size_t MAX_SIZE = 100U;

using Vertex = size_t;
using WeightType = int;

// undirected graph
class MatrixGraph
{
public:
	MatrixGraph();
	virtual ~MatrixGraph();
	void insertEdge(Vertex v1, Vertex v2, WeightType weight);
	template <class Op>
	void DFS(Vertex v, Op op);
	template <class Op>
	void BFS(Vertex v, Op op);
	void Dijkstra(Vertex s, int dist[], int path[]); // type of elements in path[] should be Vertex, but here need -1
	void Floyd(WeightType dist[][MAX_SIZE], Vertex path[][MAX_SIZE])const;
	WeightType Prim(MatrixGraph& LST)const; // unfinished
	WeightType Kulskal(MatrixGraph& LST)const; // unfinished
private:
	bool isEdge(Vertex v, Vertex w)const;
	bool isInVerset(Vertex v)const;
	bool isnotVisited(const Vertex v)const;
	// set array visited[] to false 
	void resetVisited();
	void add_AdjVertexs_Into_Queue(const Vertex& v, Queue<Vertex>& que)const;
	Vertex minV(const std::vector<bool>& cllcted, int dist[])const;
	template <class Op>
	// v : the source of adjacency
	// op : operation on Adjs
	// shouldOp : condition to operate, a function which returns bool
	void for_each_Adj_Of(
		const Vertex& v, 
		Op op, 
		ShouldOperate shouldOp = [](Vertex) { return true; } // this parament could be included in the second
	);

	size_t vNo = 0;
	size_t eNo = 0;
	WeightType weightOf[MAX_SIZE][MAX_SIZE] = { 0 };
	bool visited[MAX_SIZE] = { false };
	const int INF = 65535;
};

template<class Op>
inline void MatrixGraph::DFS(Vertex v, Op op)
{
	op(v); // visit w
	visited[v] = true;
	/*
	for (Vertex w = 0; isInVerset(w); ++w) {
		if (isEdge(vrtx, w) && !visited[w]) {
			DFS(w, op);
		}
	}*/

	for_each_Adj_Of(
		v, // object to be operated
		[op](const Vertex& vrtx) { DFS(vrtx, op); }, // operation
		isnotVisited // condition to operate
	);
}

template<class Op>
inline void MatrixGraph::BFS(Vertex v, Op op)
{
	Queue<Vertex> que;
	que.push(v);
	while (!que.empty()) {
		Vertex& w = que.front();
		add_AdjVertexs_Into_Queue(w, que);
		op(w); // operate w
		visited[w] = true;
		que.pop(); // pop w
	}
	resetVisited(); // set array visited[] to false
}

template<class Op, class ShouldOperate>
inline void MatrixGraph::for_each_Adj_Of(
	const Vertex& v, 
	Op op, 
	ShouldOperate shouldOp = [](Vertex w) { return true; })
{
	for (Vertex w = 0; isInVerset(w); ++w) {
		if (isEdge(v, w) && shouldOp(w)) {
			op(w);
		}
	}
}
