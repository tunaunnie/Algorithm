#include <stdio.h>

int main()
{

    int num;
    scanf("%d", &num);

    int wordcount = 0;

    for (int i = 0; i < num; i++)
    {
        char string[101];
        scanf("%s", string);

        int appeared[26];
        for (int i = 0; i < 26; i++)
        {
            appeared[i] = 0;
        }

        int flag = 0;

        for (int j = 0; string[j] != '\0';)
        {
                char temp = string[j];       // 지금 나온 알파벳 저장
                int index = string[j] - 97; // 지금 나온 알파벳의 고유숫자

                // 처음 나온 알파벳이면, 1로 바꾸고 그룹 단어 전부 건너뛰기
                if (appeared[index] == 0)
                {
                    appeared[index] = 1;
                    
                    while (string[j] == temp)
                    {
                        j++;
                    }
                }
                else
                {
                    flag = 1;
                    j++;
                }
        }

        if (flag == 0){
            wordcount += 1;
        }
    }

    printf("%d", wordcount);

    return 0;
}