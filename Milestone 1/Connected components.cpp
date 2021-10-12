#include<bits/stdc++.h>

using namespace std;

vector<int> arr[1001];

   int vis[1001]={0};

   void dfs(int n)

 {

     vis[n]=1;

     for(int i=0;i<arr[n].size();i++)

   {

       if(vis[arr[n][i]]==0)

       dfs(arr[n][i]);

   }

 }

 

 int main()

 {

   int n,e;

   cin>>n>>e;

 int a,b;

 

 for(int i=0;i<e;i++)

 {

   cin>>a>>b;

   arr[a].push_back(b);

   arr[b].push_back(a);

  }

  int count=0;

  for(int i=1;i<=n;i++)

  {

    if(vis[i]==0)

    {

     dfs(i);

     count++;

    }

  }

   cout<<count<<endl;

return 0;

}