#include <iostream>
#include <algorithm>
using namespace std;
int parent[100];
int height[100];

void inserttree(int n)
{
    std::fill_n(parent, 100, -1);
    std::fill_n(height, 100, 0 );
    int a[n][2];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i][1];
        cin>>a[i][2];
        parent[a[i][1]]=i;
        parent[a[i][2]]=i;
        if(a[i][1]!=-1)
        {
            height[a[i][1]] = height[parent[a[i][1]]]+1;
        }
        if(a[i][2]!=-1)
        {
            height[a[i][2]] =  height[parent[a[i][2]]]+1;        }
    }
}

double findavg(int n1,int n2)
{
    double avg;
    double count1 = 0;
    double count2 = 0;
    double counter = 0;
    double sum = 0;
    while(n1!=n2)
    {
        if(height[n1] > height[n2])
        {
            sum = sum + n1;
            n1 = parent[n1];
            count1++;
        }
        else if(height[n1] < height[n2])
        {
            sum = sum + n2;
            n2 = parent[n2];
            count2++;
        }
        else
        {
            sum = sum + n1 + n2;
            n1 = parent[n1];
            n2 = parent[n2];
            count1++;
            count2++;
        }
    }
    sum = sum + n1;
    counter = count1 + count2 + 1;
    avg = sum / counter;
    return avg;
}

int main()
{
    int N;
    cin>>N;
    inserttree(N);
    int x,y;
    int Q;
    int z[10];
    int v[10];
    cin>>Q;
    for(int j=0;j<Q;j++)
    {
    cin>>z[j]>>v[j];
    }
    for(int i=0;i<Q;i++)
    {
    cout.precision(1);
    cout<<fixed<<findavg(z[i],v[i])<<endl;
    }
    return 0;
}
