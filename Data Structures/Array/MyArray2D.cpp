#include<iostream>
using namespace std;
class MyArray2D{
	private:
		int **arr;
		int rows;
		int cols;
		
	public:
		//Patameterized constr.
		MyArray2D(int r=0,int c=0){
			if(r<=0||c<=0){
				throw "Invalid Size:size cannot be negative.";
			}
			rows=r;
			cols=c;
			arr=new int*[rows];
			for(int i=0 ; i<rows ; i++){
				arr[i]=new int[cols];
			}
		}
		//copy constr.	
		MyArray2D(MyArray2D& ob){
			rows=ob.rows;
			cols=ob.cols;
			arr=new int*[rows];
			for(int i=0 ; i<rows ; i++){
				arr[i]=new int[cols];
			}
			for(int i=0 ; i<rows ; i++){
				for(int j=0 ; j<cols ; j++){
					arr[i][j]=ob.arr[i][j];
				}
			}
		}
		//Assignment operator overloaded
		MyArray2D& operator=(MyArray2D& ob){
			if(this==&ob){
				return *this;
			}
			if(rows!=ob.rows||cols!=ob.cols){
				delete []arr;
				rows=ob.rows;
				cols=ob.cols;
				arr=new int*[rows];
				for(int i=0 ; i<rows ; i++){
					arr[i]=new int[cols];
				}
			}
			for(int i=0 ; i<rows ; i++){
				for(int j=0 ; j<cols ; j++){
					arr[i][j]=ob(i,j);
				}
			}
			return *this;
		}
		//square operator overloaded
		/*int& operator[](int index){
			if(index<0||index>=rows*cols){
				throw "Index out of bounds";
			}
			return arr[index];
		}*/
		//parenthesis operator overloaded
		int& operator()(int i,int j){
			if(i<0||i>=rows||j>=cols||j<0){
				throw "Index out of bounds";
			}
			return arr[i][j];
		}
		//friend function for input redirection operator
		friend istream& operator>>(istream& is,MyArray2D& ob);
		//friend function for output redirection operator
		friend ostream& operator<<(ostream& os,MyArray2D& ob);
		//destructor
		~MyArray2D(){
			for(int i=0 ; i<rows ; i++){
				delete []arr[i];
			}
			delete []arr;
		}
};
//friend function for input redirection operator
istream& operator>>(istream& is,MyArray2D& ob){
	cout<<"Inside cin";
	for(int i=0 ; i<ob.rows ; i++){
		for(int j=0 ; j<ob.cols ; j++){
			is>>ob(i,j);
		}
	}
	return is;
}
//friend function for output redirection operator
ostream& operator<<(ostream& os,MyArray2D& ob){
	for(int i=0 ; i<ob.rows ; i++){
		for(int j=0 ; j<ob.cols ; j++){
			os<<ob(i,j)<<"\t";
		}
		os<<endl;
	}
	return os;
}

int main(){
	bool flag=true;
	char a;
	int i,j;
	do{
		try{
			cout<<"Enter no. of rows of 2D-array:";
			cin>>i;
			cout<<"Enter no.of cols of 2D-array:";
			cin>>j;
			if(i==0||j==0){
				throw "Invalid size:cannot be zero";
			}
			MyArray2D a(i,j);
			cout<<"Enter elements:";
			cin>>a;
			cout<<a;
		}
		catch(char const *s){
			cout<<s<<endl;
		}
		cout<<"\nDo you want to continue...(Y/N):";
		cin>>a;
		if(a=='N'||a=='n'){
			flag=false;
		}
	}while(flag);
	
	
	return 0;
}
