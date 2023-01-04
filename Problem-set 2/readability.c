#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int main(void)
{
    string text = get_string("Text :  ");
    printf("%s\n",text);
    
    int letter = 0;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter++;
        }
    }

    int word = 1;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
    }

    
    int sent = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sent++;
        }
    }

    
    float cal = (0.0588 * letter / word * 100) - (0.296 * sent / word *100) - 15.8;
    int index = round(cal);
    
    if (index < 1)
    {
        printf("Before grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else 
    {
        printf("Grade %i\n",index);
    }
    
    
    
}
