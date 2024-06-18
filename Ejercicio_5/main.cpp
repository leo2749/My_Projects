#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

int main(){

    vector <string>v;

    v.push_back("Echar agua al mar");
    v.push_back("Costar un ojo de la cara");
    v.push_back("Pan comido");
    v.push_back("Salirse con la suya");
    v.push_back("Dejar en la estacada");

    sort(v.begin(), v.end());


    for(int i = 0; i < int(v.size()); i++){
       cout << v.at(i) << endl;
    }


    return 0;
}
