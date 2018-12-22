#include <iostream>
#incldue <ctime>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <cstring>
using namespace std;
int main(int argc, char * argv[]) {
	if (argc != 2) {
		cout << "Please specify the file name as '. /a.out filename'" << endl;
		return 1;
	}
	struct stat buf;
	if (stat(argv[1], & buf) != 0) {
		cout << "FAiled to get file statistics" << endl;
		return 1;
	}
	cout << "Devise Identifier: " << buf.st_dev << endl;
	cout << "Inode number: " << buf.st_ino << endl;
	cout << "Protection mode: " << oct << buf.st_mode << endl;
	cout << "Number of Hard Links: " << dec << buf.st_nlink << endl;
	cout << "User Identifier: " << getpwuid(buf.st_uid) -> pw_name << endl;
	cout << "Group number: " << getgrgid(buf.st_gid) -> gr_name << endl;
	cout << "Total File size in bytes: " << buf.st_size << endl;
	cout << "Block size for IO: " << buf.st_blksize << endl;
	cout << "Number of blocks allocated: " << buf.st_blocks << endl;
	cout << "Time of last access: " << ctime(& buf.st_atime) << endl;
	cout << "Time of last Modification: " << ctime(& buf.st_mtime) << endl;
	cout << "Time of last Status change: " << ctime(& buf.st_ctime) << endl;
	return 0;
}
