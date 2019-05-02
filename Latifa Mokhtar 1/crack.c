#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <cs50.h>


bool crack(char *user_input, char *guess, char *salt);

int main(int argc, char *argv[])
{

    if(argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    char *user_input = argv[1];

    char salt[3];

    for(int i = 0; i < 2; i++)
      salt[i] = user_input[i];

    salt[2] = '\0';

  char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int alpha_len = (sizeof alpha / sizeof alpha[0]) - 1 ;

  // guess password length 1
  char g_1[2];
  for(int a1 = 0; a1 < alpha_len; a1++)
  {
    g_1[0] = alpha[a1]; g_1[1] = '\0';

    if(crack(user_input, g_1, salt))
    {
      printf("Password is: %s\n", g_1);
      return 0;
    }

  }



  // guess password length 2
  char g_2[3];
  for(int b2 = 0; b2 < alpha_len; b2++)
    for(int a2 = 0; a2 < alpha_len; a2++)
    {
      g_2[0] = alpha[b2]; g_2[1] = alpha[a2]; g_2[2] = '\0';

      if(crack(user_input, g_2, salt))
      {
        printf("Password is: %s\n", g_2);
        return 0;
      }

    }



  // guess password length 3
  char g_3[4];
  for(int c3 = 0; c3 < alpha_len; c3++)
    for(int b3 = 0; b3 < alpha_len; b3++)
      for(int a3 = 0; a3 < alpha_len; a3++)
      {
        g_3[0] = alpha[c3]; g_3[1] = alpha[b3]; g_3[2] = alpha[a3]; g_3[3] = '\0';

        if(crack(user_input, g_3, salt))
        {
          printf("Password is: %s\n", g_3);
          return 0;
        }

      }



    // guess password length 4
  char g_4[5];
  for(int d4 = 0; d4 < alpha_len; d4++)
    for(int c4 = 0; c4 < alpha_len; c4++)
      for(int b4 = 0; b4 < alpha_len; b4++)
        for(int a4 = 0; a4 < alpha_len; a4++)
        {
          g_4[0] = alpha[d4]; g_4[1] = alpha[c4]; g_4[2] = alpha[b4]; g_4[3] = alpha[a4]; g_4[4] = '\0';

          if(crack(user_input, g_4, salt))
          {
            printf("Password is: %s\n", g_4);
            return 0;
          }

        }


    // guess password length 5
  char g_5[6];
  for(int e5 = 0; e5 < alpha_len; e5++)
  {
    printf("working on it...\n");

    for(int d5 = 0; d5 < alpha_len; d5++)
      for(int c5 = 0; c5 < alpha_len; c5++)
        for(int b5 = 0; b5 < alpha_len; b5++)
          for(int a5 = 0; a5 < alpha_len; a5++)
          {
            g_5[0] = alpha[e5]; g_5[1] = alpha[d5]; g_5[2] = alpha[c5]; g_5[3] = alpha[b5]; g_5[4] = alpha[a5]; g_5[5] = '\0';

            if(crack(user_input, g_5, salt))
            {
              printf("Password is: %s\n", g_5);
              return 0;
            }


          }
  }


  printf("Password not found.\n");
  return 0;

}


bool crack(char *user_input, char *guess, char *salt)
{
    char *encrypted_guess = crypt(guess, salt);

    if (strcmp(encrypted_guess, user_input) == 0)
        return true;

    return false;
}
