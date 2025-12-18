#include <bits/stdc++.h>
using namespace std;

int kargerMinCut(int V, vector<vector<int>> edges)
{
    random_device rd;
    mt19937 gen(rd());

    while (V > 2)
    {
     uniform_int_distribution<> distrib(0, edges.size() - 1);
        int index = distrib(gen);
        int u = edges[index][0];
        int v = edges[index][1];

        for (auto &e : edges)
        {
            if (e[0] == v) e[0] = u;
            if (e[1] == v) e[1] = u;
        }

    vector<vector<int>> newEdges;
        for (auto &e : edges)
        {
            if (e[0] != e[1])
                newEdges.push_back(e);
        }

        edges.swap(newEdges);
        V--;
    }
    return edges.size();
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int V, E;
    fin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    for (int i = 0; i < E; i++) fin >> edges[i][0] >> edges[i][1];
    fout << kargerMinCut(V, edges) << endl;
    fin.close();
    fout.close();

    return 0;
}
