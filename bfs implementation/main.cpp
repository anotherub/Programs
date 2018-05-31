#include <iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int edges,a,b;
    vector<int> nodes[1000];
    cout<<"Enter the no of edges "<<endl;
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
    cout<<"Enter the edge "<<i+1<<endl;
    cin>>a>>b;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
    }
    cout<<endl;
    for(int i=0;i<1000;i++)
    {
    if(!nodes[i].empty())
    {
    cout<<"["<<i<<"]-->";
    vector <int >::iterator itr;
    for(itr=nodes[i].begin();itr<nodes[i].end();itr++)
    {
    cout<<*itr<<"-->";
    }
    cout<<"NULL"<<endl;
    }
    }
    queue<int> que;
    bool visited[1000];
    //std::fill(visited,visited+1000,0);
    for(int i=0;i<1000;i++)
    {
    visited[i]=false;
    }
    int start;
    cout<<"\n\nEnter the starting node"<<endl;
    cin>>start;
    que.push(start);
    visited[start]=true;
    cout<<"\nBFS Traversal starts from "<<start<<" node"<<endl;
    while(!que.empty())
    {
    int front=que.front();
    cout<<front<<" ";
    que.pop();
    vector<int>::iterator j;
    for(j=nodes[front].begin();j<nodes[front].end();j++)
    {
    if(visited[*j]==false)
    {
    visited[*j]=true;
    que.push(*j);
    }
    }
    }


    return 0;
}
