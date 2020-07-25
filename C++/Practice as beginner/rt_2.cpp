#include <iostream>
using namespace std;

enum Connection{
    Series,
    Parallel
};

double calcEquiResistor(double *resistor_values, int res_count, Connection Connect);

int main(){
    int i,res_count;
    cout << "\n\nHow many resistors do you have? : ";
    while(!(cin >> res_count)){
        cout << "\n\n\t\tInvalid input. Try again." << endl;
        cout << "\n\nHow many resistors do you have? : ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    cout << "\n" << endl;
    if(!cin){return -1;}
    double *res_value = new double[res_count];
    for(i=1;i<=res_count;i++){
        cout << "\n\nValue of resistor no. " << i << ": ";
        while(!(cin >> res_value[i-1])){
            cout << "\n\n\t\tInvalid input. Try again." << endl;
            cout << "\n\nValue of resistor no. " << i << ": ";
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }

    cout << "\n\n\n\n\t\tThe equivalent resistor : " << calcEquiResistor(res_value,res_count,Series) << "  (Connected in series). " << endl;
    cout << "\n\t\tThe equivalent resistor : " << calcEquiResistor(res_value,res_count,Parallel) << "  (Connected in parallel). \n\n" << endl;

    delete[] res_value;
    return 0;
}

double calcEquiResistor(double *resistor_values, int res_count, Connection Connect){
            int i;double result=0;
            switch(Connect){
            case Parallel:
                for(i=1;i<=res_count;i++){
                    result+=1/double(resistor_values[i-1]);
                }
                result=1/result;
                break;
            case Series:
                for(i=1;i<=res_count;i++){
                    result+=double(resistor_values[i-1]);
                }
                break;
            default:
                cout << "There's  nothing to do. Sorry! :( " << endl;
                return -1;
            }
            return result;
}
