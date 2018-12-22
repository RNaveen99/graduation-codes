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

int main(){
	bool flag=true;
	char a;
	int size;
	do{
		try{
			cout<<"Enter size of array:";
			cin>>size;
			if(size==0){
				throw "Invalid size:cannot be zero";
			}
			MyArray a(size);
			cout<<"Enter elements:";
			cin>>a;
			cout<<a;
		}
		catch(char const *s){
			cout<<s<<endl;
		}
		cout<<"\nDo you want to continue...(Y/N):";
		cin>>a;
		if(a=='y'||a=='Y'){
			flag=true;
		}
		else{
			flag=false;
		}
	}while(flag);
	
	
	return 0;
}
