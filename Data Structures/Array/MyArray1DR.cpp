#include<iostream>
using namespace std;
class MyArray1DR{
	private:
		int *arr;
		int rows;
		int cols;
		
	public:
		//Patameterized constr.
		MyArray1DR(int r=0,int c=0){
			if(r<=0||c<=0){
				throw "Invalid Size:size cannot be negative.";
			}
			rows=r;
			cols=c;
			arr=new int[rows*cols];
		}
		//copy constr.	
		MyArray1DR(MyArray1DR& ob){
			rows=ob.rows;
			cols=ob.cols;
			arr=new int[rows*cols];
			for(int i=0 ; i<rows*cols ; i++){
				arr[i]=ob[i];
			}
		}
		//Assignment operator overloaded
		MyArray1DR& operator=(MyArray1DR& ob){
			if(this==&ob){
				return *this;
			}
			if(rows*cols!=ob.rows*ob.cols){
				delete []arr;
				rows=ob.rows;
				cols=ob.cols;
				arr=new int[rows*cols];
			}
			for(int i=0 ; i<rows*cols ; i++){
				arr[i]=ob[i];
			}
			return *this;
		}
		//square operator overloaded
		int& operator[](int index){
			if(index<0||index>=rows*cols){
				throw "Index out of bounds";
			}
			return arr[index];
		}
		//parenthesis operator overloaded
		int& operator()(int i,int j){
			if(i<=0||i>=rows*cols||j<=0||j>=rows*cols){
				throw "Index out of bounds";
			}
			return arr[i*rows+j];
		}
		//friend function for input redirection operator
		friend istream& operator>>(istream& is,MyArray1DR& ob);
		//friend function for output redirection operator
		friend ostream& operator<<(ostream& os,MyArray1DR& ob);
		//destructor
		~MyArray1DR(){
			delete []arr;
		}
};
//friend function for input redirection operator
istream& operator>>(istream& is,MyArray1DR& ob){
	for(int i=0 ; i<ob.rows*ob.cols ; i++){
		is>>ob[i];
	}
	return is;
}
//friend function for output redirection operator
ostream& operator<<(ostream& os,MyArray1DR& ob){
	for(int i=0 ; i<ob.rows*ob.cols ; i++){
		os<<ob[i]<<" ";
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
			MyArray1DR a(i,j);
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
