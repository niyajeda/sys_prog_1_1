#include "my_string.h"
#include "linked_list.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char buf[MAX];
	char buf_vorname[MAX];
	char buf_nachname[MAX];
	char d_name[20];
	Node* head = NULL;

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
			fscanf(source, "%s", buf);
			char_cpy(buf_vorname, buf);
			fscanf(source, "%s", buf);
			char_cpy(buf_nachname, buf);
			head = insert_sorted(head, buf_vorname, buf_nachname);
		}
	}

	print_list(head);
	delete_list(head);

	fclose(source);

	return 0;
}
