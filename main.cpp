/*
2022-10-26 videolock - 1.0.0
2022-11-10 lock - 1.2.0
2022-11-22 file_lock - 1.3.0
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int read_write_data(string RFileName,
                  string WFileName,
                  int passwd);

int main(int argc,char *argv[])
{
    string RFileName,WFileName;
    int passwd = atoi(argv[1]);
    RFileName = argv[2];
    WFileName = argv[3];
    cout<<"init_over"<<endl;
	cout<< passwd<<endl;
    read_write_data(RFileName,WFileName,passwd);
    return 0;
}
//read_write_data method
int read_write_data(string RFileName,string WFileName,int passwd){
    char data[255],test[255];
    int i;
    fstream read_file(RFileName,ios::in|ios::binary);
    fstream write_lock_file(WFileName,ios::out|ios::binary);
    cout << "ing . . ."<<endl;
    while(read_file)
    {
        for(i=0;i<=sizeof(data);i++)
        {
            data[i] = 0;
        }
        read_file.read(data,sizeof(data));
        for(i =0; i <= sizeof(data); i++)
        {
            data[i] ^= passwd;
        }
        cout << data <<endl;
        write_lock_file.write(data,sizeof(data));
    }
    write_lock_file.close();
    read_file.close();
    cout<<"over"<<endl;
    return 0;
}
