#include <iostream>
#define ROW 5
#define COL 5
int mat[ROW][COL]={
    {1,1,0,0,0},
    {0,1,1,0,0},
    {0,0,1,1,0},
    {1,0,1,0,1},
    {0,1,1,0,1}
    },result,visited[ROW][COL]={0};
using namespace std;
int issafe(int row,int col)
{
if(visited[row][col]==0 && mat[row][col]==1 && (row >= 0 && row < ROW) && (col >=0 && col < COL))
{
return 1;
}
else return 0;
}

int dfs(int row,int col,int &count)
{
    static int rownbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colnbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    visited[row][col]=1;

    for(int k=0;k<8;k++)
    {
    if(issafe(row+rownbr[k],col+colnbr[k]))
    {
    count++;
    dfs(row+rownbr[k],col+colnbr[k],count);
    }
    }
    return count;

}

int main()
{
    int i,j;
    cout<<"\nGiven Island is \n";
    for(i=0;i<ROW;i++)
    {
    for(j=0;j<COL;j++)
    {
    cout<<mat[i][j]<<"\t";
    }
    cout<<endl;
    }
    for(i=0;i<ROW;i++)
    {
    for(j=0;j<COL;j++)
    {
    if(mat[i][j]==1 && visited[i][j]==0)
    {
    int count=1;
    dfs(i,j,count);
    result=max(count,result);
    }
    }
    }
    cout<<"The longest island path is "<<result;
    return 0;
}
