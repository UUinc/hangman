#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include"console.h"

void HangmanAscii(int, int, int);
void LetterGuessed(char*, char*, char);
void PrintSentence(char*);
int LetterExist(char*, char);
void ToUpper(char*);

int main()
{
    char guessPhrase[13], guessedPhrase[13]="____________";
    int level = 0;
    char letter = '_';

    do
    {
        //Wipe the console
        clrscr();

        //Game Title
        gotoxy(54, 2); printf("Hangman Game\n");
        
        gotoxy(29, 6);
        printf("Write a sentence (Max 12 characters): ");
        fflush(stdin);
        gets(guessPhrase);

        ToUpper(guessPhrase);

    }while(strlen(guessPhrase) > 12);

    //Wipe the console
    clrscr();

    //Main Game Loop
    while(1)
    {
        //Game Title
        gotoxy(54, 2); printf("Hangman Game\n");

        //Hangman Art
        HangmanAscii(level, 15, 8);

        gotoxy(80 ,13);
        LetterGuessed(guessPhrase, guessedPhrase, letter);
        PrintSentence(guessedPhrase);

        gotoxy(0 ,0);

        if(strcmp(guessPhrase, guessedPhrase) == 0)
        {
            gotoxy(54 ,10);
            printf("Player 2 Win");

            getch();
            break;
        }
        if(level >= 6)
        {
            gotoxy(54 ,10);
            printf("Player 1 Win");

            getch();
            break;
        }

        letter = toupper(getch());

        if(!LetterExist(guessPhrase, letter))
        {
            level++;
        }
    }
    
    return 0;
}

void HangmanAscii(int level, int x, int y)
{
    int i;
    char man[7] = "O|/\\/\\";
    char hangman[7] = "       ";

    for(i=0; i<level; i++)
    {
        hangman[i] = man[i];
    }

    gotoxy(x, y);        puts  ("   \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4");
    gotoxy(x, wherey()); puts  ("   \xB3      \xB3");
    gotoxy(x, wherey()); printf("   \xB3      %c\n", hangman[0]);
    gotoxy(x, wherey()); printf("   \xB3     %c%c%c\n", hangman[2], hangman[1], hangman[3]);
    gotoxy(x, wherey()); printf("   \xB3     %c %c\n", hangman[4], hangman[5]);
    gotoxy(x, wherey()); puts  ("   \xB3");
    gotoxy(x, wherey()); puts  ("\xC4\xC4\xC4\xC1\xC4\xC4\xC4");
}

void LetterGuessed(char *_sentence, char *_guessed , char _letter)
{
    int i, len = strlen(_sentence);

    for(i=0; i<len; i++)
    {
        if(*(_sentence+i) == *(_guessed+i))
            continue;
            
        if(*(_sentence+i) == ' ')
        {
            *(_guessed+i) = ' ';
        }
        else if(*(_sentence+i) == _letter)
        {
            *(_guessed+i) = _letter;
        }
    }
    *(_guessed+len) = '\0';
}
void PrintSentence(char *_sentence)
{
    int i, len = strlen(_sentence);

    for(i=0; i<len; i++)
    {
        printf("%c ", *(_sentence+i));
    }
}
int LetterExist(char *_sentence, char _letter)
{
    int i, len = strlen(_sentence);

    for(i=0; i<len; i++)
    {
        if(*(_sentence+i) == _letter)
            return 1;
    }
    return 0;
}
void ToUpper(char *_str)
{
    int i, len = strlen(_str);

    for(i=0; i<len; i++)
    {
        *(_str+i) = toupper(*(_str+i));
    }
}