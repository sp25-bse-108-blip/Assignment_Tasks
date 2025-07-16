#include<iostream>
#include<fstream>
using namespace std;
int main(){
	int count=0;
	int alphabets=0;
	
			
	ofstream phantom;
	phantom.open("phantomx.txt");
	
	for(int i=1;i<=5;i++){
		phantom<<i<<" "<<endl;
		
	}

	
	ifstream fin;
	fin.open("phantomx.txt");
	
	int check;
	fin>>check;
	
	while(!fin.eof()){
		cout<<check<<endl;
		
		fin>>check;
		count++;
	}
	
	
	
	cout<<"Total numbers in the given file are:"<<endl;
	cout<<count;

		phantom.close();
}
