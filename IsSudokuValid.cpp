/*
Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix (mat[][]) the task to check if the configuration has a solution or not. 

Example:
Input:
2
3 0 6 5 0 8 4 0 0 5 2 0 0 0 0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0
3 6 7 5 3 5 6 2 9 1 2 7 0 9 3 6 0 6 2 6 1 8 7 9 2 0 2 3 7 5 9 2 2 8 9 7 3 6 1 2 9 3 1 9 4 7 8 4 5 0 3 6 1 0 6 3 2 0 6 1 5 5 4 7 6 5 6 9 3 7 4 5 2 5 4 7 4 4 3 0 7 

Output:
1
0
*/

#include <vector>
#include <iostream>

using namespace std;

int checkrow(vector<vector<int> > &v, int num, int r){
    for(int c=0; c<9; c++){
        if(num==v[r][c]){
            return 0;
        }
    }
    return 1;
}

int checkcol(vector<vector<int> > &v, int num, int c){
    for(int r=0; r<9; r++){
        if(num==v[r][c]){
            return 0;
        }
    }
    return 1;
}

int checksq(vector<vector<int> > &v, int num, int str, int stc){
    for(int i=str; i<str+3; i++){
        for(int j=stc; j<stc+3; j++){
            if(num==v[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

int checkvalid(vector<vector<int> > &v, int num, int i, int j){
    if( checkrow(v, num, i)==0){
        return 0;
    }
    if (checkcol(v, num, j)==0){
        return 0;
    }
    if(checksq(v, num, 3*(i/3), 3*(j/3))==0){ 
        return 0;
    }
    return 1;
}
int isvalid(vector<vector<int> > &v, vector<int>& keys, int ind){
    if(ind==keys.size()){
        return 1;
    }
    for(int i=1; i<=9; i++){
        if( checkvalid(v, i, keys[ind]/10, keys[ind]%10) ){
            v[keys[ind]/10][keys[ind]%10]=i;
            if (isvalid(v, keys, ind+1)){
                return 1;
            }else{
                v[keys[ind]/10][keys[ind]%10]=0;
            }
        }
    }
    return 0;
}

int main() {
	//code
	int n;
	cin>>n;
	vector<vector<int> > v(9, vector<int>(9));
	for(int i=0; i<n; i++){
	    vector<int>keys;
	    for(int j=0; j<9; j++){
	        for(int k=0; k<9; k++){
	            cin>>v[j][k];
	            if(v[j][k]==0){
	                keys.push_back(10*j+k);
	            }
	        }
	    }
	    
	    cout<<isvalid(v, keys, 0)<<endl;
	}
	return 0;
}
