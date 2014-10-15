#include "my_string.h"
#include "linked_list.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	printf("test");
	char buf[MAX];
	char d_name[20];
	Node* head = NULL;
	int count = 0;
#ifdef TEST
	FILE* source = fopen("test_datei.txt", "r");
#else
	fprintf(stdout, "Bitte Dateinamen angeben\n");
	scanf("%s", d_name);

	FILE* source = fopen(d_name, "r");
#endif

	if(!source)
	{
		fprintf(stderr, "Datei konnte nicht geöffnet werden");
		return 0;
	}
	else
	{
		while(!(feof(source)))
		{
			count = fscanf(source, "%s", buf);
			if(*buf == '\0') break;
			char* buf_vorname = (char*) malloc(count * (sizeof(int)) + 1); // char ist 1 
			char_cpy_until(buf_vorname, buf);
			count = fscanf(source, "%s", buf);
			char* buf_nachname = (char*) malloc(count * (sizeof(int)) + 1);
			char_cpy_until(buf_nachname, buf);
			head = insert_sorted(head, buf_vorname, buf_nachname);
			buf[0] = '\0';
		}
	}

	print_list(head);
	delete_list(head);

	fclose(source);

	return 0;
}
