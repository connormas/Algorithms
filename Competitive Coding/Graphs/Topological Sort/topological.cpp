#include<stdio.h>
#include<stdlib.h>
#include<iostream> 
#include<fstream>
#include<string>
#include<vector>
#define MAX 1024

using namespace std;

void create_graph(const string filename);
void add(int vertex);
int del();
int isEmpty();
int find_indegree_of_vertex(int vertex);
 
int total_vertices;
int adjacent_matrix[MAX][MAX];
int queue[MAX];
int front = -1;
int rear = -1;
 
int main()
{
	int i, count, topological_sort[MAX], indegree[MAX];
	string filename = "k10.el";  // hardcoded because I don't know how to
                               // specify CLI args for esesc
  create_graph(filename);
	//calculating the in-degree for all vertices.
	for(i = 0; i < total_vertices; i++)
	{
		indegree[i] = find_indegree_of_vertex(i);
		if(indegree[i] == 0)
		{
			add(i);
		}
	}
	count = 0;
	while(!isEmpty() && count < total_vertices)
	{
		int vertex = del();
    		topological_sort[++count] = vertex;
		for(i = 0; i < total_vertices; i++)
		{
			if(adjacent_matrix[vertex][i] == 1)
			{
				adjacent_matrix[vertex][i] = 0;
				indegree[i] = indegree[i] - 1;
				if(indegree[i] == 0)
				{
					add(i);
				}
			}
		}
	}
	//count < number of vertices implies all vertices could not be covered as there exists a cycle.
	if(count < total_vertices)
	{
		printf("Graph is Cyclic. Therefore, Topological Ordering Not Possible\n");
		exit(1);
	}
	printf("Topological Order of Vertices\n");
	for(i = 1; i <= count; i++)
	{
		printf("%3d", topological_sort[i]);
	}
	printf("\n");
	return 0;
}
// Function to add a vertex in the queue 
void add(int vertex)
{
	if(rear == MAX - 1)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		if (front == -1) 
		{
			front = 0;
		}
		rear = rear + 1;
		queue[rear] = vertex ;
	}
}
//Queue is empty or not 
int isEmpty()
{
	if(front == -1 || front > rear )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//Delete the front element of the queue 
int del()
{
	
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	else
	{
		int element = queue[front];
		front = front+1;
		return element;
	}
}
//Calculate the in-degree of the vertex
int find_indegree_of_vertex(int vertex)
{
	int count, total_indegree = 0;
	for(count = 0; count < total_vertices; count++)
	{
		if(adjacent_matrix[count][vertex] == 1)
		{
			total_indegree++;
		}
	}
	return total_indegree;
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


//Generate the required graph 
void create_graph(const string filename)
{
	int count, maximum_edges, origin_vertex, destination_vertex;
  total_vertices = 1024;
	maximum_edges = total_vertices * (total_vertices - 1);
  cout << "opening file called " << filename << endl;
  fstream edgelist (filename, ios::in);
  string edge;
  while (getline(edgelist, edge)) {
    auto verts = split(edge, " "); 
    //cout << stoi(verts[0]) << " " << stoi(verts[1]) << endl;
		adjacent_matrix[stoi(verts[0])][stoi(verts[1])] = 1;
  }
  edgelist.close();
}
