#include "Maze.h"

Maze::Maze(int x, int y)
{
	n=x, m=y;
	djs.Init(n*m);
	sz = n*(m-1)+m*(n-1);
	edge = new pair<int,int> [sz];
	is = new bool [sz];

	Init();
}

void Maze::Init()
{
	for(int i=0 ; i<sz ; i++)
		is[i]=0;

	MapEdgeToNodes();
}

void Maze::MapEdgeToNodes()
{
	for(int i=0, j=0, node=1 ; i<n ; i++, node++)
	{
		for(int k=0 ; k<m-1 ; k++, j++, node++)
			edge[j].first = node-1, edge[j].second = node;

		node-=m;
		for(int k=0 ; k<m && j<sz ; k++, j++, node++)
			edge[j].first = node, edge[j].second = node+m;
	}

	Solve();
}

void Maze::Solve()
{
	int r, cnt=n*m-1;

	srand (time(NULL));

	while (cnt--)
	{
		do
		{
			r = rand()%sz;
		}
		while(djs.Find(edge[r].first) == djs.Find(edge[r].second));

		is[r]=1;
		djs.Union(edge[r].first,edge[r].second);
	}

	Print();
}

void Maze::Print()
{
	cout << "Goal : move form $ to E passing through the *\n\n";

	int cnt=0;

	cout << "    ";

	for(int i=1 ; i<m ; i++)
		cout << " ---";

	for(int i=0 ; i<n ; i++)
	{
		cout << "\n| " << (i ? "* " : "$ ");

		for(int j=0 ; j<m-1 ; j++, cnt++)
			cout << (is[cnt] ? "  " : "| ") << (i==n-1 && j==m-2 ? "E " : "* ");

		cout << "|\n";

		for (int j=0 ; j<m && i!=n-1 ; j++, cnt++)
			cout << (is[cnt] ? "    " : " ---");

	}

	for(int i=0 ; i<m-1 ; i++)
		cout << " ---";
}

Maze::~Maze()
{
	delete []edge;
	delete []is;
}

