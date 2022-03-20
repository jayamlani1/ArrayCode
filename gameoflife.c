int max(int a , int b)
{
    if(a>b)
        return a;
    
    return b;
}

int min(int a, int b)
{
    if(a<b)
        return a;
     
    return b;
}

int neighbourstatus(int** board, int m, int n, int i, int j)
{
    int count =0;
    
   int mink = min(i+2, m);
    int minl = min(j+2, n);
 // This is important for checking all the surrounding blocks.
  
    for(int k = max(0, i-1); k<mink; k++)
    {
        for(int l = max(0, j-1);l<minl;l++)
        {
            if(!(l==j && k==i) && board[k][l])
            {
                count++;
            }
        }
        
    }
    return count;
}


void gameOfLife(int** board, int boardSize, int* boardColSize){
    int m = boardSize;
    int n = *boardColSize;
    int newboard[m][n];
    int k = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            k = neighbourstatus(board, m, n, i, j);
            if(k<2 || k>3)
            {
                newboard[i][j] = 0;
            }
            else if(k == 3)
            {
                newboard[i][j] = 1;
            }
            else
            {
                newboard[i][j] = board[i][j];
            }
        }
        
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j] = newboard[i][j];
        }
    }
    
}
