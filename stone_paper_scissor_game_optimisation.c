#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void bot_response_paper(char *BOT_response[3], int rando, int roun, char player_name[21], char player_response[8], int *point_player_score, int *point_bot_score)
{

    if (strcmp(BOT_response[rando], "PAPER") == 0 && strcmp(player_response, "STONE") == 0)
    {
        *point_bot_score += 1;

        printf("ROUND %d RESULTS:\n", roun);
        printf("BOT WON\n");
        printf("%s LOST\n", player_name);
    }
    else if (strcmp(BOT_response[rando], "PAPER") == 0 && strcmp(player_response, "PAPER") == 0)
    {

        printf("ROUND %d RESULTS:\n", roun);
        printf("BOTH EQUAL!!!\n");
    }
    else if (strcmp(BOT_response[rando], "PAPER") == 0 && strcmp(player_response, "SCISSOR") == 0)
    {
        *point_player_score += 1;

        printf("ROUND %d RESULTS:\n", roun);
        printf("%s WON\n", player_name);
        printf("BOT LOST\n");
    }
    else if (strcmp(BOT_response[rando], "SCISSOR") == 0 && strcmp(player_response, "SCISSOR") == 0)
    {

        printf("ROUND %d RESULTS:\n", roun);
        printf("BOTH EQUAL!!!\n");
    }
    else if (strcmp(BOT_response[rando], "SCISSOR") == 0 && strcmp(player_response, "PAPER") == 0)
    {
        *point_bot_score += 1;

        printf("ROUND %d RESULTS:\n", roun);
        printf("BOT WON\n");
        printf("%s LOST\n", player_name);
    }
    else if (strcmp(BOT_response[rando], "SCISSOR") == 0 && strcmp(player_response, "STONE") == 0)
    {
        *point_player_score += 1;

        printf("ROUND %d RESULTS:\n", roun);
        printf("%s WON\n", player_name);
        printf("BOT LOST\n");
    }
    else if (strcmp(BOT_response[rando], "STONE") == 0 && strcmp(player_response, "PAPER") == 0)
    {
        *point_player_score += 1;

        printf("ROUND %d RESULTS:\n", roun);
        printf("%s WON\n", player_name);
        printf("BOT LOST\n");
    }
    else if (strcmp(BOT_response[rando], "STONE") == 0 && strcmp(player_response, "STONE") == 0)
    {
        printf("ROUND %d RESULTS:\n", roun);
        printf("BOTH EQUAL!!!\n");
    }
    else if (strcmp(BOT_response[rando], "STONE") == 0 && strcmp(player_response, "SCISSOR") == 0)
    {
        *point_bot_score += 1;

        printf("ROUND %d RESULTS:\n", roun);
        printf("BOT WON\n");
        printf("%s LOST\n", player_name);
    }
}

int main()
{

    printf("****************************************************************************************************************************************************\n");
    printf("                                                  HEY! Welcome to STONE,PAPER and SCISSOR Game\n");
    printf("****************************************************************************************************************************************************\n");

    printf("\n\nWhat's YOUR Name (The name You entered will be used in this Game)::\n");
    char player_name[21];
    gets(player_name);

    printf("\n\n%s, How Many Rounds You want To Play!\n", player_name);
    int num_of_rounds;
    scanf("%d", &num_of_rounds);

    printf("\nAll the Best %s,You Are Playing Against The COMPUTER BOT!", player_name);


    int player_score = 0;
    int *ps = &player_score;
    int BOT_score = 0;
    int *bs = &BOT_score;


    printf("\n\n\t\t\t\t\t###### SCORES:%s = %d, BOT = %d ######", player_name, player_score, BOT_score);
    

    int rounds = 1;
    while (num_of_rounds >= rounds)
    {

        srand(time(0));
        int rando = rand() % 3 + 0;

        char player_response[8];
        char *BOT_response[3] = {"STONE", "PAPER", "SCISSOR"};
        printf("\n\nSELECT Stone or Paper or Scissor(All The Best!): \n");
        scanf("%s", player_response);
        for (int i = 0; player_response[i] != '\0'; i++)
        {
            player_response[i] = toupper(player_response[i]);
        }

        printf("\t\t------------------------- BOT Selected: %s and %s Selected: %s ------------------------\n\n", BOT_response[rando], player_name, player_response);
        bot_response_paper(BOT_response, rando, rounds, player_name, player_response, ps, bs);

        printf("\t\t\t\t\t\tROUND %d SCORES BOARD::\n", rounds);
        printf("\t\t\t\t\t###### SCORES:%s = %d, BOT = %d ######\n", player_name, player_score, BOT_score);

        rounds++;
    }

    printf("\n\n\nALL ROUNDS COMPLETED\n");
    printf("\t\t\t\t\t\tFINAL SCORES BOARD:::\n");
    printf("\t\t\t\t\t###### SCORES:%s = %d, BOT = %d ######\n", player_name, player_score, BOT_score);
    if (player_score > BOT_score)
    {
        printf("\nCONGRATULATIONS %s,You WON AGAINST COMPUTER BOT!! Hurray!!\n", player_name);
    }
    else if (BOT_score > player_score)
    {
        printf("\nSORRRY %s,You LOST AGAINST COMPUTER BOT!! BETTER LUCK NEXT TIME,OOPS!!\n", player_name);
    }
    else
    {
        printf("\n%s SCORE and BOT SCORE,BOTH ARE EQUAL,ANYWAY %s YOU GAVE TOUGH COMPETITION FOR BOT!!\n", player_name, player_name);
    }
    printf("\n\n\n****************************************************************************************************************************************************\n");
    printf("                                                    THANK YOU! HAVE A GREAT DAY :)\n");
    printf("****************************************************************************************************************************************************\n");
    return 0;
}