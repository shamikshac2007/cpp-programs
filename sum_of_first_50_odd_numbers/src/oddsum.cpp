#include <iostream>
using namespace std;



int main() {
    const int x = 25;
    int oddNumbers[x], sum = 0, i= 0;

    for (int n = 1; n <= 50; n++) {
        if (n % 2 != 0) {
            oddNumbers[i++] = n;
            sum = sum + n;
        }
    }

    cout << "Sum of odd numbers from 1 to 50: " << sum << endl;
    return 0;
}


// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     int oddsum=0;
//     cout<<"n: ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         if(i%2!=0){
//             oddsum +=i;
//         }
//     }
//     cout<<"sum of odd sum: "<<oddsum<<endl;
//     return 0;
// }