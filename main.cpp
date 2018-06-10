#include <iostream>
#define row 4
#define col 4
using namespace std;


int main()
{
int ms[row][col]={
   {-1,-1,0,0},
   {0,0,0,0},
   {0,-1,0,0},
   {0,0,0,0}
};

int rows[]={-1,-1,-1,0,0,1,1,1};
int cols[]={-1,0,1,-1,1,-1,0,1};

for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
if(ms[i][j]==-1)
{
for(int k=0;k<8;k++)
{
if(i+rows[k]>=0 && j+cols[k]>=0 && i+rows[k]<=row && j+cols[k]<=col)
{
if(ms[i+rows[k]][j+cols[k]]!=-1)
{
ms[i+rows[k]][j+cols[k]]+=1;
}
}
}
}
}
}

for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
cout<<ms[i][j]<<" ";
}
cout<<endl;
}
    return 0;
}
