#include <cstdio>

int main()
{
    FILE *fp;
    fp = fopen("example.txt","w");
    char lang[5][20] = {"C","C++","Java","Python","PHP"};

    fprintf(fp,"Top 5 programming language\n");
    for (int i=0; i<5; i++)
        fprintf(fp, "%d. %s\n", i+1, lang[i]);

    fclose(fp);
    return 0;
}
