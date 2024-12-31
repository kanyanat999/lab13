#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double arr[], int size, double result[]) {
    double sum = 0, sum_squares = 0, product = 1, harmonic_sum = 0;
    double max_value = arr[0], min_value = arr[0];
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        sum_squares += arr[i] * arr[i];
        product *= arr[i];
        harmonic_sum += 1.0 / arr[i];
        
        if (arr[i] > max_value) max_value = arr[i];
        if (arr[i] < min_value) min_value = arr[i];
    }
    result[0] = sum / size;
    result[1] = sqrt((sum_squares / size) - (result[0] * result[0]));

    if (product > 0) {
        result[2] = pow(product, 1.0 / size);
    } else {
        result[2] = 0; 
    }
    result[3] = size / harmonic_sum;
    result[4] = max_value;
    result[5] = min_value;
}