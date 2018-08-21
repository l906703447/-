#include "MatrixGraph.h"
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <exception>
#include <assert.h>

MatrixGraph::MatrixGraph()
{
	std::cout << "input vNo : ";
	std::cin >> vNo;
	std::cout << "input(j k weight) : " << std::endl;
	for (size_t i = 0; i < vNo; i++) {
		int tmp;
		size_t j, k;
		WeightType weight;
		std::cin >> j >> k >> weight;
		insertEdge(j, k, weight);
	}
}


MatrixGraph::~MatrixGraph()
{
}

void MatrixGraph::insertEdge(Vertex v1, Vertex v2, WeightType weight)
{
	weightOf[v1][v2] = weightOf[v2][v1] = weight;
	eNo++;
}

void MatrixGraph::Dijkstra(Vertex s, int dist[], int path[])
{
	std::vector<bool> collected(vNo);// to record Vertexs that be collected
	// initialization
	for (Vertex v = 0; isInVerset(v); ++v) { 
		if (isEdge(s, v)) {
			dist[v] = weightOf[s][v];
			path[v] = s;
		}
		else {
			dist[v] = INF;
			path[v] = -1;
		}
	}
	dist[s] = 0;
	collected[s] = true;

	// find the vertex which has min weight with vertexs collected in every cycle of loop
	Vertex v ;// uncollected vertex which has min distance
	while (-1 != (v = minV(collected, dist))) { // minV is exist
		WeightType minDist = INF;

		collected[v] = true;
		for_each_Adj_Of( // update distance of collected vertexs 
			v,
			[=](Vertex w) {
				dist[w] = dist[v] + weightOf[v][w];
				path[w] = v;
			},
			[=](const Vertex& w) {
				if (weightOf[v][w] < 0) {
					throw std::invalid_argument("Here is a negative weight edge, and Dijkstra can't handle it.");
				}
				if (dist[v] + weightOf[v][w] < dist[w]) {
					return true;
				}
				else {
					return false;
				}
			}
		);
	}
}

void MatrixGraph::Floyd(WeightType dist[][MAX_SIZE], Vertex path[][MAX_SIZE]) const
{
	for (Vertex v = 0; isInVerset(v); ++v) {
		for (Vertex w = 0; isInVerset(w); ++w) {
			if (weightOf[v][w] == 0) {
				dist[v][w] = INF;
			}
			else {
				dist[v][w] = weightOf[v][w];
			}
			path[v][w] = -1;
		}
	}

	for(Vertex k = 0; isInVerset(k); ++k)
		for(Vertex i = 0; isInVerset(i); ++i)
			for (Vertex j = 0; isInVerset(j); ++j) {
				assert(!(dist[i][j] < 0)); // 此算法要求无“负权值边”
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
}

bool MatrixGraph::isEdge(Vertex v, Vertex w) const
{
	return weightOf[v][w] != 0;
}

bool MatrixGraph::isInVerset(Vertex v) const
{
	return v < vNo;
}

bool MatrixGraph::isnotVisited(const Vertex v) const
{
	return !visited[v];
}

void MatrixGraph::resetVisited()
{
	for (size_t i = 0; i < MAX_SIZE; ++i) {
		visited[i] = false;
	}
}

void MatrixGraph::add_AdjVertexs_Into_Queue(const Vertex& v, Queue<Vertex>& que) const
{
	for (Vertex w = 0; isInVerset(w); ++w) {
		if (!visited[w] && isEdge(v, w)) {
			que.push(w);
		}
	}
}

Vertex MatrixGraph::minV(const std::vector<bool>& cllcted, int dist[]) const
{
	int minDist = INF;
	Vertex ret = 0;
	for (Vertex v = 0; isInVerset(v); ++v) {
		if (!cllcted[v] && dist[v] < minDist) {
			ret = v;
			minDist = dist[v];
		}
	}
	if (minDist == INF) {
		ret = -1;
	}
	return ret;
}
