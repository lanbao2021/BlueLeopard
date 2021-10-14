#include <iostream>
using namespace std;

int main() {
    int x[6] = {2,4,6,8,5,7};
    int *p=x;
    int i;
    for(i=0; i<6; i++)
        cout << (*p)++ << endl;
    return 0;
}
