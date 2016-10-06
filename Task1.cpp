//Нахождение арбитража на матрице обменных курсов
//Применён алгоритм Беллмана- Форда.
//Если алг. зациклевается, значит никак не достигается 
//наибольшее значение => сущ-ет цикл, проходя по которому 
//можно увеличивать кол-во денег.

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using std::vector;
using std::cin;
using std::cout;

struct edge {
	int a, b;
	double cost;
};

double maxim = 0;
int count;

const double INF = 1000;

void show(vector<double> &d) {
	for (int i = 0; i < count; ++i)
	{
		if (i % count == 0)
			cout << std::endl;
		cout << d[i] << " ";
	}
}

void solve(vector<edge> e, vector<double> &d) {
	for (int i = 0; i < count - 1; ++i)		//n-1 (т.е. кол-во вершин - 1) раз
		for (int j = 0; j < e.size(); ++j)  //перебираем все ребра
			if ((d[e[j].a] < INF) && (e[j].cost != 0) && (e[j].cost != -1))	//если ребро есть
				d[e[j].b] = std::min(d[e[j].b], d[e[j].a] + e[j].cost);		
	show(d);
}



int main()
{
	vector<edge> e;
	//std::ifstream file("input.txt");
	//file >> count;
	cin >> count;
	int shift = count;

	for (int i = 0; i < count; ++i)
	{
		edge tmp;
		for (int j = 0; j < count; ++j)
		{
			tmp.a = i;
			tmp.b = j;
			if (shift == count) {
				tmp.cost = 1;
				e.push_back(tmp);
				shift = 0;
				continue;
			}

			//file >> tmp.cost;
			cin >> tmp.cost;
			if (maxim < tmp.cost)
				maxim = tmp.cost;

			e.push_back(tmp);
			++shift;
		}
	}

	vector<double> d;
	d.reserve(count);

	solve(e, d) ? cout << "YES": cout << "NO";
return 0;
}
