#include <bits/stdc++.h>
#include "DJS.h"

using namespace std;

#ifndef MAZE_H_
#define MAZE_H_

class Maze
{
private:
	int n, m, sz;
	DJS djs;
	pair <int,int> *edge;
	bool *is;

public:
	Maze(int x, int y);
	void Init();
	void MapEdgeToNodes();
	void Solve();
	void Print();
	virtual ~Maze();
};

#endif /* MAZE_H_ */
