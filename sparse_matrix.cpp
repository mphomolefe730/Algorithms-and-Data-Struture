#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
	vector<vector<int>> matrix = {{0,0,0},{0,3,0},{5,0,6},{0,0,8}};
	vector<vector<int>> sp = {} ;
	int row=matrix.size(),col=matrix[0].size(),count=0,k=1;

	cout<<"Matrix: "<<endl;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col;j++){
			cout<<setw(4)<<matrix[i][j];
			if(matrix[i][j] != 0){
				count++;
			}
		} 
		cout<<endl;
	}
	
	cout<<"Sparse matrix: "<<endl;
	sp.resize(count + 1, vector<int>(3));
	sp[0][0] = row;
	sp[0][1] = col;
	sp[0][2] = count;
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(matrix[i][j] != 0){
				sp[k][0] = i;
				sp[k][1] = j;
				sp[k][2] = matrix[i][j];
				k++;
			}
		}
	}
	for(int i = 0; i <= count; i++){
		for(int j = 0; j < 3; j++){
			cout<<setw(4)<<sp[i][j];
		}
		cout<<endl;
	}
}
