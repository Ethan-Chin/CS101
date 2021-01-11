#include <vector>
#include <random>
#include <ctime>
#include <iostream>
using namespace std;




int main () {

    default_random_engine defEngine(time(0));
    uniform_int_distribution<int> intDistro(2,6000);
    int n = intDistro(defEngine);

    uniform_int_distribution<int> intDistro1(1,n);

    int m = intDistro1(defEngine);

    cout<<n<<' '<<m<<endl;

    uniform_int_distribution<int> intDistro2(1,(int)1e6);

    for (int i = 0; i < n; ++i)
    {
        cout<<intDistro2(defEngine)<<' '<<intDistro2(defEngine)<<std::endl;
    }

    return 0;
}