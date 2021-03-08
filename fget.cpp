#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int count = 10;
    char str[10];
    FILE *fp;

    fp = fopen("file.txt","a+");
    fputs("An example file\n", fp);
    fputs("Filename is file.txt\n", fp);




cout << fp;
    rewind(fp);






    while(feof(fp) == 0)
    {
        fgets(str,count,fp);
        cout << str << endl;
    }


    fclose(fp);
    return 0;
}
