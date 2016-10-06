#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using std::cin;
using std::cout;
using std::vector;

std::ifstream file("input.txt");
std::ofstream outfile("floyd.out");
int n;

int func()
{
	int t;
	file >> t;
	return t;
}

void Floyd_Warshall(vector<int> &map)
{
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (map[i*n + j])
					map[i*n + j] = std::min(map[i*n + j], map[n*k + j] + map[i*n + k]);
}

int main()
{
	int weight;
	file >> n;
	//cin >> n;
	vector<int> map (n * n);
	std::generate(map.begin(), map.end(), func);
	/*int tmp;
	for (int i = 0; i < map.size(); ++i)
	{
		cin >> tmp;
		map[i] = tmp;
	}*/
	Floyd_Warshall(map);

	for (int i = 0; i < n * n; ++i) { 
		if ((!(i % n)) && i != 0 && i)
			outfile << "\n";
			//cout << "\n";
		outfile << map[i] << " ";
		//cout << map[i] << " ";
	}
	//cout << "end";
	return 0;
}
