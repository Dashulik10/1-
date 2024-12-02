#include <iostream>
#include <vector>
#include "DSU.h"
#include <string>
#include <unordered_map>
using namespace std;

DSU::DSU(int n)
{
	parent.resize(n);
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	rang.resize(n, 0);
	size.resize(n, 1);
}

int DSU::FindLeader(int element) 
{
	if (parent[element] != element)
	{
		parent[element] = FindLeader(parent[element]);
	}
	return parent[element];
}

string DSU::UnionSet(int set1, int set2)
{
	int Root_1 = FindLeader(set1);
	int Root_2 = FindLeader(set2);

	if (Root_1 != Root_2) 
	{
		if (rang[Root_1] > rang[Root_2])
		{
			parent[Root_2] = Root_1;
			size[Root_1] += size[Root_2];
			return "Set1 is parent of Set2 now";
		}
		else if (rang[Root_2] > rang[Root_1])
		{
			parent[Root_1] = Root_2;
			size[Root_2] += size[Root_1];
			return "Set2 is parent of Set1 now";
		}
		else 
		{
			parent[Root_2] = Root_1;
			rang[Root_1]++;
			return "Set1 and Set2 had equal rank, Set1 is now the parent of Set2";
		}
	}

	return "Set1 and Set2 are already in the same set";
}

string DSU::Statement() 
{
		string result = "Current state of DSU:\n";
		for (size_t i = 0; i < parent.size(); ++i)
		{
			result += "Element " + to_string(i) + " -> Leader " + to_string(FindLeader(i)) + "\n";
		}
		return result;
}

int DSU::GetSize(int element) 
{
	int Root = FindLeader(element);
	return size[Root];
}

void DSU::SetName(int element, const string& Name) 
{
	int Leader = FindLeader(element);
	name[Leader] = Name;
}

string DSU::GetName(int element) {
	int Leader = FindLeader(element);
	if (name.find(Leader) != name.end())
	{
		return name[Leader];
	}
	else
	{
		return "Unnamed Set";
	}
}
