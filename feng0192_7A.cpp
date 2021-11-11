#include <iostream>

using namespace std;

int main(){
    int p1,p2;
    int *po1 = NULL;
    int *po2 = NULL;

    cout<<"How many coefficient in first polynomial?";
    cin >> p1;

    cout <<"What are the coefficient (lowest power first)?";
    po1 = new int[p1];

    for(int i = 0; i < p1; i++){

        cin >> po1[i];

    }

    cout << "How many coefficient in Second polynomial?";
    cin>>p2;
    cout << "What are the coefficient (lowest power first)?";
    po2 = new int[p2];
    
    for(int i = 0; i < p2; i++){

        cin >> po2[i];

    }

    for (int i = 0; i < p1; i++){

        cout << "(" << po1[i] << ")";

        if(i != 0){

            cout << "x^" << i;

        }
        if(i != p1 - 1){

            cout<<" + ";
        }
    }

    cout << endl << "times"<<endl;

    for(int i = 0; i < p2; i++){

        cout << "(" <<po2[i]<< ")";
        if(i != 0)
            cout<< "x^" << i;
        if(i != p2-1)
            cout<< "+";
    }

    cout<<endl<<"-----"<<endl;

    int *mul_p = new int[p1+p2-1];

    for(int i = 0; i < p1; i++){
        for(int j = 0; j < p2; j++){

            mul_p[i+j] += po1[i]*po2[j];
        }
    }

    for(int i = 0; i <(p2+p1-1); i++){
        cout << "(" <<mul_p[i] << ")";
        if(i != 0){
            cout << "x^" << i;

        }
        if(i != (p1+p2 -2)){
            cout << "+";
        }
    }

    delete po1;
    delete po2;
    delete mul_p;
    return 0;

} 
