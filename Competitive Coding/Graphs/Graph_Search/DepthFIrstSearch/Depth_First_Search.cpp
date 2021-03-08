#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int u,int v)
{
	//For undirected graph
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void DFSUtil(int u,vector<int>adj[],vector<bool>&visited)
{
	visited[u]=true;
	cout<<u<<" ";
	for(int i=0;i<adj[u].size();i++)
	{
		if(visited[adj[u][i]]==false)
			DFSUtil(adj[u][i],adj,visited);
	}
}

void DFS(vector<int>adj[],int V)
{
	vector<bool>visited(V,false);
	for(int u=0;u<V;u++)
	{
		if(visited[u]==false)
		{
			DFSUtil(u,adj,visited);
		}
	}
}

vector<string> split (const string& line, const string& delimiters) {
   vector<string> words;
   size_t end = 0;

   // Loop over the string, splitting out words, and for each word
   // thus found, append it to the output wordvec.
   for (;;) {
      size_t start = line.find_first_not_of (delimiters, end);
      if (start == string::npos) break;
      end = line.find_first_of (delimiters, start);
      words.push_back (line.substr (start, end - start));
   }
   return words;
}

int main()
{
	int V = 524288;
  vector<int> adj[V];
  cout << "made vectors and V" << endl;
  string filename = "k19.el";
  fstream edgelist (filename, ios::in);
  cout << "opened file" << endl;
  string edge;
  while (getline(edgelist, edge)) {
    auto verts = split(edge, " "); 
    //cout << stoi(verts[0]) << " " << stoi(verts[1]) << endl;
		addEdge(adj, stoi(verts[0]), stoi(verts[1]));
  }
  edgelist.close();
  cout << "added edges" << endl;
  DFS(adj, V);
  cout<<"\n";
  return 0;
}
