#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decryptMessage(char *message, int key)
{
				const char alphabetPerso[26] = "9kzrx#wb$qpcnvh@&mdgy*o+a2";
				const char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
				int j;
				int index = 0;

				for (int i=0; message[i] != '\0'; i++)
				{
								j = 0;
								switch (message[i])
								{
												case ' ':
																message[i] = ' ';
												case '.':
																message[i] = '.';
												case '\n':
																message[i] = ' ';
												default:
												while(message[i] != alphabetPerso[j])
												{
																j++;
																if(j > 26)
																{
																				break;
																}
												}
												index = j - key;
												if (index < 0){
																index += 26;
												}
												message[i] = alphabet[index];
												}
				}
				

				printf("Message décrypté : %s\n", message);

}


int main(void)
{
				char message[500];
				int key = 0;
				printf("Entrez votre message à décrypter \n");
				fgets(message, 500, stdin);
				printf("Entrez la clé de déchiffrage\n");
				scanf("%d", &key);

				decryptMessage(message, key);

				return 0;
}
