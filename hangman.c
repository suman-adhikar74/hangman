#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>




int x,y,z;


char gameS(char sWORD[])

{
    printf("\n\n\t\tlets hung you\n\n");

    printf("\n\n\t\tLoading list of words from file...\n    %d words loaded...\n\nGuess a word that is %d letter long.\n\n\n\n\n\n\n\n\n", 55900, strlen(sWORD));


    return '1';

}







int alphabet (char letter)


{
    if (letter >= 'a' && letter <= 'z')
        return 1;
    else
        return 0;
}




int gBEFORE(char letter, char Lguessed[])

{


    for (x = 0; x < strlen(Lguessed); x++)

    {
        if (letter == Lguessed[x])
            return 1;
    }
    return 0;
}







int EIS(char letter, char Sw[])


{

    for(x = 0; x < strlen(Sw); x++)
    {
        if (letter == Sw[x])
        return 1;
    }
    return 0;
}







int IS_VOWEL(char letter)
{
    if (letter == 'a' ||letter == 'e' ||letter == 'i' ||letter == 'o' ||letter == 'u')
        return 1;
    else
        return 0;
}




void letters_available(char LETTERS_GUESSED[])
{
    char available_letters[] = "abcdefghijklmnopqrstuvwxyz";

    int count;
    for ( x = 0; x < 26; x++)
    {
        count = 1;
        for( z = 0; z < 20; z++)
        {
            if (available_letters[x] == LETTERS_GUESSED[z])
            {
                count = 0;
                break;
            }
        }
        if (count == 1)
            printf("%c  ", available_letters[x]);
    }

}




int main()
{

    int GAME_FINISHED = 0;

    char SECRET_WORD[] = "apple";
    gameS(SECRET_WORD);

    for( x = 0; x < strlen(SECRET_WORD); x++)
    {
        SECRET_WORD[x] = tolower(SECRET_WORD[x]);
    }


    char DISPLAY[strlen(SECRET_WORD)];
    for( x = 0; x < strlen(SECRET_WORD); x++)
    {
        DISPLAY[x] = '_';
    }


    int LIVES = 6, WARNINGS_LEFT = 3, SCORE = 0;
    char GUESSED_LETTERS[26] = "--------------------";
    int GUESSED_COUNT = 0;
    char letter;

    GAME_IS_ON :

    printf("Lives = %d                                  Warnings Left = %d                                  Score = %d\n\n\n\n\n\n", LIVES, WARNINGS_LEFT, SCORE);
    for( x = 0; x < strlen(SECRET_WORD); x++)
    {
        printf("%c ", DISPLAY[x]);
    }

    printf("\n\nAVAILABLE LETTERS :\n");
    letters_available(GUESSED_LETTERS);

    printf("\n\n\n\n\nGuess the letter...\n");

    fflush(stdin);
    scanf("%c", &letter);
    letter = tolower(letter);
    fflush(stdin);
    system("cls");

    if (!alphabet(letter))
    {
        if(WARNINGS_LEFT >= 1)
        {
            WARNINGS_LEFT--;
            printf("Warning! The character you entered is invalid!\nYou have %d warnings left...\n\n", WARNINGS_LEFT);
        }
        else
        {
            LIVES--;
            printf("Due to no warnings left, your lives is reduced...\n\nYou have %d lives left\n\n", LIVES);
        }
    }
    else
    {
        if (gBEFORE(letter, GUESSED_LETTERS))
        {
            if(WARNINGS_LEFT >= 1)
            {
                WARNINGS_LEFT--;
                printf("Warning! The character you entered is invalid!\nYou have %d warnings left...\n\n", WARNINGS_LEFT);
            }
            else
            {
                LIVES--;
                printf("Due to no warnings left, your lives is reduced...\n\nYou have %d lives left\n\n", LIVES);
            }
        }
        else
        {
            GUESSED_LETTERS[GUESSED_COUNT] = letter;
            GUESSED_COUNT++;

            if (EIS(letter, SECRET_WORD))
            {
                printf("RIGHT GUESS...\n\n");
                for ( x = 0; x < strlen(SECRET_WORD); x++)
                {
                    if (letter == SECRET_WORD[x])
                        DISPLAY[x] = letter;
                }

                if(IS_VOWEL(letter))
                    SCORE += 30;
                else
                    SCORE += 20;
            }
            else
            {
                printf("WRONG GUESS...\n\n");

                if(IS_VOWEL(letter))
                {
                    LIVES -= 2;
                    SCORE += 10;
                }
                else
                {
                    LIVES --;
                    SCORE -= 5;
                }



            }
        }
    }
    if (SCORE < 0)
        SCORE = 0;

    if (LIVES <= 0)
    {
        system("cls");
        GAME_FINISHED = 1;
        printf("Game over...\nYou have no lives left...\n\nThe word was ");
        puts(SECRET_WORD);
        printf("\n\n");
        printf("You Scored %d.\n\n\n", SCORE);

    }


    if (strcmp(SECRET_WORD,DISPLAY) == 0)
    {
        system("cls");
        GAME_FINISHED = 1;
        printf("Congracts...\nYou revealed all the letters...\n\nThe word is ");
        puts(SECRET_WORD);
        printf("\n\n");
        printf("You Scored %d.\n\n\n", SCORE);
    }



    if (!GAME_FINISHED)
        goto GAME_IS_ON;

}
