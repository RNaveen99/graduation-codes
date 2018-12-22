#include<cstdlib>
#include<iostream>
using namespace std;
int main(int argc,char** argv)
{
	try
	{
		if(argc!=2)
			throw "INVALID COMMAND LINE ARGUMENT";
	}
	catch(const char* e)
	{
		cout<<endl<<e<<endl<<endl;
		return 1;
	}
	string s(argv[1]);
	system("touch File_Info.txt");
	system("printf \"\n\" > File_Info.txt");
	system(("stat "+s+" | head -8 >> File_Info.txt").c_str());
	system(("ls -l -h "+s+" >> File_Info.txt").c_str());
	system(("file "+s+" >> File_Info.txt").c_str());
	system("printf \"\n\" >> File_Info.txt");
	system("cat File_Info.txt");
	return 0;
}

