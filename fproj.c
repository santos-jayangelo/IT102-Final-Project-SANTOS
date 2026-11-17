#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char again;

    do
    {
        system("cls");

        char c;
        int choice, shape, i, j, rows, size, inverted, space;

        printf("Main Menu: \n");
        printf(" 1) Pattern Generator\n");
        printf(" 2) Pascal's Triangle\n");
        printf(" 3) Grade Calculator\n");
        printf(" 4) Palindrome Checker\n");
        printf(" 5) Exit\n\n");

            printf("Pick a number: ");
            if (scanf("%d", &choice) != 1) {
                printf("\n== Error: That is not a valid number! ==\n");
                while (getchar() != '\n');
                choice = 0; 

            } else if ((c = getchar()) != '\n') {
                 printf("\n== Error: Whole numbers only, no decimals or letters! ==\n");
                while (getchar() != '\n');
                choice = 0; 

            } else if (choice <= 0 || choice > 5) {
                printf("\n== Error! Choose between (1-5) only. ==\n");
            }

        // PATTERN GENERATOR

        if (choice == 1)
        {
            printf("\n");

            int size, shape, i, j, space, tier;

            printf("Welcome to Pattern Generator!\n");

            size = 0;
            do{
                printf("Enter a size for the pattern (2-15): ");
                scanf("%d", &size);
                while (getchar() != '\n');
            } while (size < 2 || size > 15);
            

            printf("\nPattern Generator Menu:");
            printf("\n 1. Right Triangle");
            printf("\n 2. Square");
            printf("\n 3. Isosceles Triangle");
            printf("\n 4. Inverted Right Triangle");
            printf("\n 5. Christmas Tree\n\n");

            shape = 0;
            do
            {
                printf("Pick a number: ");
                scanf("%d", &shape);
                while (getchar() != '\n');
            }   while (shape < 1 || shape > 5);
            

            printf("\n");

            if (shape == 1)
            {
                for (i = 1; i <= size; i++)
                {
                    for (j = 1; j <= i; j++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            else if (shape == 2)
            {
                for (i = 1; i <= size; i++)
                {
                    for (j = 1; j <= size; j++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            else if (shape == 3)
            {
                for (i = 1; i <= size; i++)
                {
                    for (space = 1; space <= size - i; space++)
                    {
                        printf(" ");
                    }
                    for (j = 1; j <= 2 * i - 1; j++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            else if (shape == 4)
            {
                for (i = size; i >= 1; i--)
                {
                    for (j = 1; j <= i; j++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            else if (shape == 5)
            {
                for (tier = 1; tier <= 3; tier++)
                {
                    for (i = 1; i <= size; i++)
                    {
                        for (space = 1; space <= size - i; space++)
                        {
                            printf(" ");
                        }
                        for (j = 1; j <= 2 * i - 1; j++)
                        {
                            printf("*");
                        }
                        printf("\n");
                    }
                }

                for (i = 1; i <= 2; i++)
                {
                    for (space = 1; space <= size - 1; space++)
                    {
                        printf(" ");
                    }
                    printf("*\n");
                }
            }
        }

        // PASCALINE TRIANGLE
        else if (choice == 2)
        {
            int rows, i, j, space, pascal[10][10];

            printf(">Welcome to Pascal's Triangle!\n");
            printf("Put a number at least 1 and at most 10.\n");

            rows = 0;
            while (rows < 1 || rows > 10)
            {
                printf("Enter the number of rows: ");
                scanf("%d", &rows);
                while (getchar() != '\n');
            }

            for (i = 0; i < rows; i++)
            {
                for (j = 0; j <= i; j++)
                {
                    if (j == 0 || j == i)
                    {
                        pascal[i][j] = 1;
                    }
                    else
                    {
                        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                    }
                }
            }

            printf("\n");

            for (i = 0; i < rows; i++)
            {
                for (space = 1; space <= rows - i - 1; space++)
                {
                    printf("   ");
                }
                for (j = 0; j <= i; j++)
                {
                    printf("%6d", pascal[i][j]);
                }
                printf("\n");
            }    
        }

        
        else if (choice == 3)
        {
            float prelim, midterm, prefinal, final, total, average;

            printf(">Welcome to the Grade Calculator!\n");

            prelim = 0;
            while (prelim < 1.0 || prelim > 5.0)
            {
                printf("Enter Prelim grade: ");
                scanf("%f", &prelim);
            }

            midterm = 0;
            while (midterm < 1.0 || midterm > 5.0)
            {
                printf("Enter Midterm grade: ");
                scanf("%f", &midterm);
            }

            prefinal = 0;
            while (prefinal < 1.0 || prefinal > 5.0)
            {
                printf("Enter Pre-final grade: ");
                scanf("%f", &prefinal);
            }

            final = 0;
            while (final < 1.0 || final > 5.0)
            {
                printf("Enter Final grade: ");
                scanf("%f", &final);
            }

            total = prelim + midterm + prefinal + final;
            average = total / 4;

            printf("\nRESULTS\n");
            printf("Prelim: %.2f\n", prelim);
            printf("Midterm: %.2f\n", midterm);
            printf("Pre-Final: %.2f\n", prefinal);
            printf("Final: %.2f\n\n", final);
            printf(">Average: %.2f\n", average);

            if (average <= 3.0)
            {
                printf("Status: PASSED\n");
                printf("Congratulations on passing!\n");
            }
            else
            {
                printf("Status: FAILED\n");
                printf("Better Luck next time!\n");
            }

        }
            

        // PALINDROME CHECKER
        else if (choice == 4)
        {
           char word[50];
           int length, i, isword, ispal;

           printf(">Welcome to Palindrome Checker!\n");

           isword = 0;
           while (isword == 0)
            {
                printf("Enter a single word: ");
                scanf("%49s", word);
                while (getchar() != '\n');      // clear anythxing left on the line
 
                length = strlen(word);

                isword = 1;
                for (i = 0; i < length; i++)
                {
                    if (!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')))
                    {
                        isword = 0;
                    }
                }

                if (isword == 0)
                {
                    printf("Error: Input must be a word (letters only, no numbers or symbols).\n\n");
                }
            }

            ispal = 1;

            for (i = 0; i < length / 2; i++)
            {
                if (word[i] != word[length - 1 - i])
                {
                    ispal = 0;
                }
            }

            if (ispal == 1)
            {
                printf("\nThe word is a Palindrome.\n");
            }
            else
            {
                printf("\nThe word is NOT a Palindrome.\n");
            }
        }
        else if (choice == 5) 
        {
            printf("\n");
            break;
            
        }

        // TRY AGAIN QUESTION

        printf("\nDo you want to try another operation? (Y/N): ");
        scanf(" %c", &again);
        printf("\n");

    } while (again == 'y' || again == 'Y');

    printf("-Thank you for using the program, Have a great day!");
    return 0;
}
