#ifndef DSU_H
#define DSU_H
#include <string>

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class DSU 
{
private:
	vector <int> parent;
	vector <int> rang;
	vector <int> size;
	unordered_map <int, string> name;
public:
	DSU(int n);
	int FindLeader(int element);
	string UnionSet(int set1, int set2);
	string Statement();
	int GetSize(int element);
	void SetName(int element, const string& Name);
	string GetName(int element);
};
#endif 