#include<bits/stdc++.h>
using namespace std;
class DSU
{
    public:
        vector<int>rank,parent,size;
        
        DSU(int n)
        {
            rank.resize(n+1);
            parent.resize(n+1);
            size.resize(n+1);
            int i;
            
            for(i=0;i<=n;i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        
        int findUpar(int node)
        {
            if(parent[node]==node)
                return node;
            
            return parent[node]=findUpar(parent[node]);    
        }
        
        void unionByrank(int u,int v)
        {
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);
            
            if(ulp_u==ulp_v)
                return;
            
            if(rank[ulp_u]<rank[ulp_v])
                parent[ulp_u]=ulp_v;
                
            else if(rank[ulp_u]>rank[ulp_v])
                parent[ulp_v]=ulp_u;
            
            else
            {
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
        
        void unionBysize(int u,int v)
        {
            int ulp_u=findUpar(u);
            int ulp_v=findUpar(v);
            
            if(ulp_u==ulp_v)
                return;
            
            if(size[ulp_u]<size[ulp_v])
            {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else
            {
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};

int main()
{
    int t;
    cin>>t;
    return 0;
}
