#include<iostream>
using namespace std;
class MyArray{
	private:
		int *arr;
		int size;
		
	public:
		//Patameterized constr.
		MyArray(int size=0){
			if(size<0){
				throw "Invalid Size:size cannot be negative.";
			}
			this->size=size;
			arr=new int[size];
		}
		//copy constr.	
		MyArray(MyArray& ob){
			size=ob.size;
			arr=new int[size];
			for(int i=0 ; i<size ; i++){
				arr[i]=ob[i];
			}
		}
		//Assignment operator overloaded
		MyArray& operator=(MyArray& ob){
			if(this==&ob){
				return *this;
			}
			if(size!=ob.size){
				delete []arr;
				size=ob.size;
				arr=new int[size];
			}
			for(int i=0 ; i<size ; i++){
				arr[i]=ob[i];
			}
			return *this;
		}
		//square operator overloaded
		int& operator[](int index){
			if(index<0||index>=size){
				throw "Index out of bounds";
			}
			return arr[index];
		}
		//friend function for input redirection operator
		friend istream& operator>>(istream& is,MyArray& ob);
		//friend function for output redirection operator
		friend ostream& operator<<(ostream& os,MyArray& ob);
		//destructor
		~MyArray(){
			delete []arr;
		}
		void resize(int n){
			if(size<0){
				throw "invalid size";
			}
			if(size!=n){
				size=n;
				delete[] arr;
				arr=new int[size];
			}
		}
};
//friend function for input redirection operator
istream& operator>>(istream& is,MyArray& ob){
	for(int i=0 ; i<ob.size ; i++){
		is>>ob[i];
	}
	return is;
}
//friend function for output redirection operator
ostream& operator<<(ostream& os,MyArray& ob){
	for(int i=0 ; i<ob.size ; i++){
		os<<ob[i]<<" ";
	}
	return os;
}
class MyArray2D1D{
	private:
		int rows;
		int cols;
		MyArray *ar;
	public:
		MyArray2D1D(int r=0,int c=0){
			if(r<=0||c<=0){
				throw "Invalid size";
			}
			rows=r;
			cols=c;
			ar=new MyArray[rows];
			for(int i=0 ; i<rows ; i++){
				ar[i].resize(c);
			}
		}
		MyArray2D1D(MyArray2D1D& ob){
			rows=ob.rows;
			cols=ob.cols;
			ar=new MyArray[rows];
			for(int i=0 ; i<rows ; i++){
				ar[i].resize(cols);
			}
			for(int i=0 ; i<rows ; i++){
				for(int j=0 ; j<rows ; j++){
					ar[i][j]=ob.ar[i][j];
				}
			}
		}
		MyArray& operator[](int index){
			if(index<0||index>=rows){
				throw "Invalid index";
			}
			return ar[index];
		}
		MyArray2D1D& operator=(MyArray2D1D& ob){
			if(this==&ob){
				return *this;
			}
			if(rows!=ob.rows||cols!=ob.cols){
				delete []ar;
				rows=ob.rows;
				cols=ob.cols;
				ar=new MyArray[rows];
				for(int i=0 ; i<rows ; i++){
					ar[i].resize(cols);
				}
			}
			for(int i=0 ; i<rows ; i++){
				for(int j=0 ; j<cols ; j++){
					ar[i][j]=ob.ar[i][j];
				}
			}
		}
};
int main(){
	MyArray2D1D a(2,2);
	return 0;
}
