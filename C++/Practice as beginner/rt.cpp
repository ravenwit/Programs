#include <iostream>
using namespace std;

enum Connection{
    Series,
    Parallel
};

double calcEquiResistor(double resistor_values[], int res_count, Connection Connect);

int main(){
    int i,res_count;

    cout << "How many resistors do you have? : ";
    cin >> res_count;
    cout << "\n" << endl;
    double res_value[res_count-1];
    for(i=1;i<=res_count;i++){
        cout << "\nValue of resistor number " << i << ": ";
        cin >> res_value[i-1];
    }

    cout << "\n\n\n\tThe equivalent resistor : " << calcEquiResistor(res_value,res_count,Series) << "  (Connected in series). " << endl;
    cout << "\n\tThe equivalent resistor : " << calcEquiResistor(res_value,res_count,Parallel) << "  (Connected in parallel). \n\n" << endl;
    return 0;
}

double calcEquiResistor(double resistor_values[], int res_count, Connection Connect){
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

