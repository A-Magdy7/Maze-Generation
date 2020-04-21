#include "DJS.h"

DJS::DJS()
{

}

void DJS::Init (int x)
{
	parent = new int[x];
	size = new int [x];

	for(int i=0 ; i<x ; i++)
		parent[i]=i, size[i]=1;
}

int DJS::Find (int x)
{
	return parent[x] = (x==parent[x] ? x : Find(parent[x]));
}

void DJS::Union (int x, int y)
{
	x = Find(x), y = Find(y);

	if(size[x] > size[y])
		parent[y] = x, size[x] += size[y];
	else
		parent[x] = y, size[y] += size[x];
}

DJS::~DJS()
{
	delete []parent;
	delete []size;
}

