#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){

    string subject;
    float num;
    string grade;

    float total_sum = 0;
    float num_sum = 0;

    for(int i = 0; i<20; i++){
        std::cin >> subject >> num >> grade;



        int isP = grade.compare("P");
        if (isP != 0){

            num_sum += num;
            
            if(grade == "A+"){
                total_sum += 4.5 * num;
            } else if (grade == "A0"){
                total_sum += 4.0 * num;
            } else if (grade == "B+"){
                total_sum += 3.5 * num;
            } else if (grade == "B0"){
                total_sum += 3.0 * num;
            } else if (grade == "C+"){
                total_sum += 2.5 * num;
            } else if (grade == "C0"){
                total_sum += 2.0 * num;
            } else if (grade == "D+"){
                total_sum += 1.5 * num;
            } else if (grade == "D0"){
                total_sum += 1.0 * num;
            } else if (grade == "F") {
                total_sum += 0.0 * num;
            }
        } 
    }

    printf("%f", total_sum/num_sum);

    return 0;
}