#include<bits/stdc++.h>
using namespace std;

#define ROW 6
#define COL 6


int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};
typedef pair<int,int> Pair;

struct cell{
  int parent_i ,parent_j;
  double f,g,h;
};

bool valid(int row, int col){
  return (row >= 0) && (row < ROW) && (col >= 0 && col < COL);
}

bool  notBlocked(int grid[][COL],int r,int c){
  if(grid[r][c] == 1){
    return true;
  }
  else{
    return false;
  }
}
double Hvalue(int r, int c, Pair dest){
  return ((double) sqrt((r-dest.first)*(r-dest.first) + (c-dest.second)*(c-dest.second)));
}

void findPath(cell cellValues[][COL],Pair dest){
  cout<<"The path is "<<endl;
  int r = dest.first;
  int c = dest.second;
  stack <Pair> st;

  while(!(cellValues[r][c].parent_i == r && cellValues[r][c].parent_j == c)){
 // 	cout<<"hey"<<endl;
    st.push(make_pair(r,c));
    int row1 = cellValues[r][c].parent_i;
    int col1 = cellValues[r][c].parent_j;
    r = row1;
    c = col1;
  }

  st.push(make_pair(r,c));
  while(!st.empty()){
   //cout<<he5y<<endl;
    pair<int,int> p = st.top();
    st.pop();
    cout<<"-> "<<p.first<<" "<<p.second;
  }
  return ;
}

void aStarSearch(int grid[][COL], Pair src, Pair dest){
  if(notBlocked(grid,src.first,src.second) == false || notBlocked(grid,dest.first,dest.second) == false){
    cout<<"You can not be here"<<endl;
  }
  if(src.first == dest.first && src.second == dest.second){
    cout<<"Destination Reached"<<endl;
  }

  bool list1[ROW][COL];
  memset(list1, false,sizeof(list1));
  cell cellValues[ROW][COL];
  int i ;
  int j ;
  for(int i = 0; i < ROW ;i++){
    for(int j = 0; j < COL;j++){
      cellValues[i][j].f = FLT_MAX;
      cellValues[i][j].g = FLT_MAX;
      cellValues[i][j].h = FLT_MAX;
      cellValues[i][j].parent_i = -1;
      cellValues[i][j].parent_j = -1;
    }
  }
  i = src.first;
  j = src.second;
  cellValues[i][j].f = 0.0;
  cellValues[i][j].g = 0.0;
  cellValues[i][j].h = 0.0;
  cellValues[i][j].parent_i = i;
  cellValues[i][j].parent_j = j;

  set < pair < double, pair<int,int> > > list0;
  list0.insert(make_pair(0.0,make_pair(i,j)));
  bool flag = false;
  while(!list0.empty()){
    pair<double , pair<int,int> > p = *list0.begin();
    list0.erase(list0.begin());
    i = p.second.first;
    j = p.second.second;
    list1[i][j] = true;

    ///Now i need to check for all the 8 childern from the current cellValues

    double gn,hn,fn;
    for(int k = 0; k < 8;k++){
      int xx = i + dx[k];
      int yy = j + dy[k];
    if(valid(xx,yy)){
      if(xx == dest.first && yy == dest.second){
        cellValues[xx][yy].parent_i = i;
        cellValues[xx][yy].parent_j = j;
        cout<<"Destination found"<<endl;
        flag = true;
        findPath(cellValues,dest);
        return ;
      }
      else if( list1[xx][yy] == false && notBlocked(grid,xx,yy) == true){
        gn = cellValues[i][j].g + 1.0;
        hn = Hvalue(xx,yy,dest);
        fn = gn+hn;
        if(cellValues[xx][yy].f == FLT_MAX || cellValues[xx][yy].f > fn){
          list0.insert(make_pair(fn,make_pair(xx,yy)));
          cellValues[xx][yy].f = fn;
          cellValues[xx][yy].g = gn;
          cellValues[xx][yy].h = hn;
          cellValues[xx][yy].parent_i = i;
          cellValues[xx][yy].parent_j = j;
        }
      }
    }
  }
}
  if(flag == false){
    cout<<"Destination can not be reached"<<endl;
  }
  return ;
}


int main(){
  int grid[ROW][COL] = {
        { 1, 0, 1, 1, 1, 1},
        { 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1 },
        { 0, 0, 1, 0, 1, 0 },
        { 1, 1, 1, 0, 1, 1 },
        { 1, 0, 1, 1, 1, 1 }
  };
  Pair src = make_pair(5,0);
  Pair dest = make_pair(0,0);
  aStarSearch(grid,src,dest);
  return 0;
}
