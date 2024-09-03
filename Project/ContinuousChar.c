#include <stdio.h>
#include <string.h>

int fun(char *t)
{
    int len = strlen(t);
    int i;
    char before = t[0];
    char current;
    int flag = 1;
    if (len < 2)
    {
        return 0;
    }
    for (i = 1; t[i] != '\0'; i++)
    {
        current = t[i];
        if (before != current - 1)
        {
            flag = 0;
            break;
        }
        before = current;
    }
    return flag;
}

int main()
{
    char s[100];
    printf("������һ���ַ�:");
    if (fgets(s, sizeof(s), stdin) != NULL)
    {
        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n')
        {
            s[len - 1] = '\0';
        }

        if (fun(s))
            printf("\n%s��������,1\n", s);
        else
            printf("\n%s����������,0\n", s);
    }
    else
    {
        printf("�������");
    }
    return 0;
}