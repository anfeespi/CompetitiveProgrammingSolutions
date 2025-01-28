#include<bits/stdc++.h>
const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;

using namespace std;

double log_a_to_base_b(int a, int b){
    return log2(a) / log2(b);
}

int FindDigits(int n, int b) {
    if (n < 0) 
        return 0;
    if (n == 1)
        return 1;
        
    double digits = 0;
    for (int i = 2; i <= n; i++)
        digits += (log_a_to_base_b(i, b));
        
    return (int) (floor(digits)) + 1;
}

int main() {
    int n, cases = 1, num, base;
    cin>>n;
    
    while(n--){
        cin>>num>>base;
        
        cout<<"Case "<<cases++<<": "<<FindDigits(num, base)<<endl;
    }
}
