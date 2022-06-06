//Student attendance program by Stefan Markovski
#include <stdio.h>
#include <stdint.h>
int main(){
    uint32_t attendance;
    int option, student_num;
    unsigned int bit;
    while(1){
        printf("\n");
        printf("CHOOSE AN ACTION TO PERFORM:\n");
        printf("1. Set attendance, starting from student 1\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");
        scanf("%d", &option);
        //Setting the attendance for each student starting from 1 and going to 32
        if(option == 1){
            student_num = 32;
            bit = bit;
            if(bit >= 0 && bit <= 32){
                attendance = attendance | (1 << bit);
                for(int bit = sizeof(attendance) * __CHAR_BIT__ - 1; bit >= 0; bit--){
                    printf("Student number %d attending: %d\n", student_num, !!(attendance & (1 << bit)));
                    //Count the students
                    student_num--;
                }
                //Switch to the next student automatically
                bit++;
            }else{
                printf("Invalid student number! Please try again.\n");
            }
        }
        //Clearing attendance by choosing which student's attendance to remove
        if(option == 2){
            student_num = 32;
            printf("Which student's attendance do you want to clear: \n");
            scanf("%d", &bit);
            bit = bit - 1;
            if(bit >= 0 && bit <= 32){
                attendance = attendance & ~ (1 << bit);
                for(int bit = sizeof(attendance) * __CHAR_BIT__ - 1; bit >= 0; bit--){
                    printf("Student number %d attending: %d\n", student_num, !!(attendance & (1 << bit)));
                    //Count the students
                    student_num--;
                }
            }else{
                printf("Invalid student number! Please try again.\n");
            }
        }
        //Attendance info
        if(option == 3){
            student_num = 32;
            for(int bit = sizeof(attendance) * __CHAR_BIT__ - 1; bit >= 0; bit--){
                printf("Student number %d attending: %d\n", student_num, !!(attendance & (1 << bit)));
                //Count the students
                student_num--;
            }
        }
        //Change attendance by choosing which student's attendance to change
        if(option == 4){
            student_num = 32;
            printf("Which student's attendance do you want to change: \n");
            scanf("%d", &bit);
            bit = bit - 1;
            if(bit >= 0 && bit <= 32){
                attendance = attendance ^ (1 << bit);
                for(int bit = sizeof(attendance) * __CHAR_BIT__ - 1; bit >= 0; bit--){
                    printf("Student number %d attending: %d\n", student_num, !!(attendance & (1 << bit)));
                    //Count the students
                    student_num--;
                }
            }else{
                printf("Invalid student number! Please try again.\n");
            }
        }
        //End the program
        if(option == 5){
            break;
        }
    }
    return 0;
}