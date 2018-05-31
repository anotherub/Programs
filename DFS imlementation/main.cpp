#include <iostream>
#include<vector>
using namespace std;
 vector<int>nodes[100];
 bool visited[100];

 void dfs(int start)
 {
 cout<<start<<"-->";
 visited[start]=true;
 vector<int>::iterator itr;
 for(itr=nodes[start].begin();itr<nodes[start].end();itr++)
 {
 if(visited[*itr]==false)
 {
 dfs(*itr);
 }
 }
 }


int main()
{
    int v,i,start,e;
    cout<<"Enter the number of vertex and  edges\n";
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
    cout<<"\nEnter the edge pair\n";
    int a,b;
    cin>>a>>b;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
    }
    cout<<"The adjancy content is \n";
    vector<int>::iterator itr;
    for(i=0;i<v;i++)
    {
   cout<<"VERTEX:"<<i<<"-->"<<endl;
    for(itr=nodes[i].begin();itr<nodes[i].end();itr++)
    {
    cout<<*itr<<"-->";
    }
    cout<<endl;
    }
    cout<<"\nEnter the starting vertices for DFS traversal\n";
    cin>>start;
    std::fill(visited,visited+100,false);
    dfs(start);
    for(i=0;i<v;i++)
    {
    if(visited[i]==false)
    {
    dfs(i);
    }
    }
    cout<<"\n BFS Traversal Complete";



       return 0;
}
