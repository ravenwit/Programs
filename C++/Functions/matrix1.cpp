#include <iostream>
#include <vector>

using namespace std;

void show_matrix(vector<int> matrix, int column);
vector<int> matrix_clock(vector<int> matrix, int row, int column);
vector<int> matrix_cclock(vector<int> matrix);
vector<int> matrix_trans(vector<int> matrix);

int main(){
	vector<int> matrix; int row, col;
	cout << "Dimension: ";
	cin >> row >> col;
	cout <<"\nEnter Matrix Data: " << endl;
	for(int i = 0; i < row*col; i++)
		{int tmp; cin >> tmp; matrix.push_back(tmp);}
	show_matrix(matrix, col);
	show_matrix(matrix_clock(matrix, row, col), row);
	return 0;

}

void show_matrix(vector<int> matrix, int column){
	cout << "\n\nMatrix: " << endl;
	for(int i = 0; i < matrix.size(); i++){
		cout << matrix[i] << " ";
		if((i+1)%column==0) cout << endl;
	}
}

vector<int> matrix_clock(vector<int> matrix, int row, int column){
	vector<int> res; bool idk=0;
	for(int i = matrix.size()-1; i >= 0; i--){
		if((i*column)%(row*column - 1) == 0){
			if(idk) res.push_back(matrix[(row*column - 1)]);
			else res.push_back(matrix[(i*column)%(row*column - 1)]);
			continue;
		}
		res.push_back(matrix[(i*column)%(row*column - 1)]);
		idk = 1;
	}
	return res;
}