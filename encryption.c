#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void encryptMessage(char *message)
{

				const char alphabet[26] = "9kzrx#wb$qpcnvh@&mdgy*o+a2";
				int key = rand() % 26;

				if (key == 0)
				{
								srand(time(0) + 46);
								key = rand() % 26;				
				}
				
				for (int i = 0; message[i] != '\0'; i++)
				{
								if (isalpha(message[i]))
								{
												message[i] = tolower(message[i]);
												int index = message[i] - 'a';
												message[i] = alphabet[(index + key) % 26];
								}
								else if (message[i] == ' ') 
								{
												message[i] = ' ';
								}
				}


				printf("Encrypted message : %s\n", message);
				printf("Key to decrypt : %d\n", key);

}

int main (void)
{
				srand(time(0)+33);
				char message[500];

				printf("Entrez le message à encrypter \n");
				fgets(message, 500, stdin);
				
				encryptMessage(message);
								


				return 0;
}
