#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


bool isPossible(int Node,bool graph[101][101],int n,int color[],int m)
{

    for(int k=0;k<n;k++)
    {
        if(k!=Node && graph[k][Node]==1 && color[k]==m)
        {
            return false;
        }
    }
    return true;
}


bool color_graph(int Node,bool graph[101][101],int color[], int m, int N)
{    
      if(Node==N)
         return true;
       

       for(int i=1;i<=m;i++)
       {
              if(isPossible(Node,graph,N,color,i))
              {
                    color[Node]=i;

                    if(color_graph(Node+1,graph,color,m,N))
                        return true;
                    else
                       color[Node]=0;    
              }
       }
       return false;
}


bool graphColoring( bool graph[101][101], int m, int N)
{  
    int color[N]={0};
    if(color_graph(0,graph, color,m,N))
    {
        return true;
    }
    return false;
       
}



int main() {
  int N = 4;
  int m = 3;

  bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);

}
