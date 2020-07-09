#include<iostream> 
#include<string>
#include<vector>
using namespace std; 

int c=0 ; 
bool ispathsafe(vector<vector<int> >& board , int i , int j )
{  	
if(i<0 || i>=board.size() || j<0 || j>=board.size()){
return false; 
 	}  
 	return true;
}
int multimazepath(vector<vector<int> >& board, int sr,int sc,int dr,int dc,string psf) 
{    
if(sr==board.size()*board.size() && sc==board.size()*board.size()) 
{ 
c++;
cout<<psf<<endl ;
return 0; 
}  
    for(int i=0 ; i<board.size()* board.size(); i++)	
{	 
int row=i/board.size();
int col=i%board.size();

if(board[row][col]!=-1 && ispathsafe(board,row,col))
{  
multimazepath(board ,sr,sc+row ,dr,dc, psf+ "H");
multimazepath(board ,sr+col,sc ,dr,dc, psf+ "V"); 
} 
} 
return c; 
}

int main()
{ 
freopen("/Users/rishabhsingh/Documents/Sublime c++/input.txt","r",stdin);
freopen("/Users/rishabhsingh/Documents/Sublime c++/output.txt","w",stdout);
 

int arr[][4]=  {{0, 0, 0, 0},
{0, -1, 0, 0},
{-1, 0, 0, 0},
{0,  0, 0, 0}};

vector<vector<int> > board; 

for(int i=0 ; i<4; i++){ 
vector<int> row; 
for(int j=0 ; j<4; j++){ 
row.push_back(arr[i][j]);
}
board.push_back(row);
}   

cout<<multimazepath(board,0,0,3,3,"");

}