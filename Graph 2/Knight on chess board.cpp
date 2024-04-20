int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int sourceX=C-1;
    int sourceY=D-1;
    int destX=E-1;
    int destY=F-1;
    if(sourceX==destX && sourceY==destY)return 0;
    
    vector<vector<int>> visited(A,vector<int> (B,0));
	    queue< pair<pair<int,int>,int>> q;
	    q.push({{sourceX,sourceY},0});
	    visited[sourceX][sourceY]=1;
	    int delrow[]={-2,-2,-1,-1,1,1,2,2};
	    int delcol[]={-1,1,-2,2,-2,2,1,-1};
	    while(!q.empty()){
	        int r=q.front().first.first;
	        int c=q.front().first.second;
	        int d=q.front().second;
	        q.pop();
	        if(r==destX && c==destY)return d;
	        for(int i=0;i<8;i++){
	            int nrow=r+delrow[i];
	            int ncol=c+delcol[i];
	            if(nrow>=0 && nrow<A && ncol>=0 && ncol<B && !visited[nrow][ncol]){
	                visited[nrow][ncol]=1;
	                q.push({{nrow,ncol},d+1});
	            }
	        }
	    }
	    return -1;
}
