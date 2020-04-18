#include <stdio.h>
#include <stdlib.h>
#define SHELLSCRIPT "\
sed -i '' 's/Elizabeth/AgenteG/g' prideandprejudice.txt\
sed -i '' 's/Charles/Dr.Malito/g' prideandprejudice.txt\
sed -i '' 's/Pemberley/40.6782° N, 73.9442° W/g' prideandprejudice.txt\
sed -i '' 's/Pemberley/LaBarca/g' prideandprejudice.txt\
sed -i '' 's/carriage/04-09-2020/g' prideandprejudice.txt\
"
int main(int argc, char const *argv[])
{
    system("bash m2.sh");
    return 0;
}
