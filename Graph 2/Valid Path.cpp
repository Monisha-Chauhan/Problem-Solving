string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> mat(A+1,vector<bool> (B+1));
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            bool flag=false;
            for(int k=0;k<E.size();k++)
            {
              if((E[k]-i)*(E[k]-i)+(F[k]-j)*(F[k]-j)<=D*D)
              {
                  flag=true;
                  break;
              }
            }
           mat[i][j]=flag; 
        }
    }
    if(mat[0][0]==true)return "NO";
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty())
    {
       int r=q.front().first;
       int c=q.front().second;
       q.pop();
       if(r==A && c==B)return "YES";
       for(int i=-1;i<=1;i++)
       {
           for(int j=-1;j<=1;j++)
           {
               int nrow=r+i;
               int ncol=c+j;
               if(nrow>=0 && nrow<=A && ncol>=0 && ncol<=B && mat[nrow][ncol]==false )
               {
                   q.push({nrow,ncol});
                   mat[nrow][ncol]=true;
               }
           }
       } 
    }
    return "NO";
}
