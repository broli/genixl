/* This file is part of genixl
 *
 * genixl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * genixl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with genixl.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <iconv.h>
#include <mxml.h>

#include "ixlmxml.h"
#include "genixllib.h"

/*this file is a temporal file, until i finish the "lib"
 * i will test, and scrape it constantly*/

int main(int argc, char *argv[])
{
	char *CurLocale=NULL; /*var to hold the current locale*/
	FILE *fp=NULL;
	mxml_node_t *tree=NULL;

	CurLocale = setlocale(LC_ALL, "");/* set the user's env locale*/
	if ( CurLocale == NULL )
	{
		/*not critical, but lets just warn the user*/
		perror("Warning: Cant set locale, check your env\n");
	}
	if ( argc < 1 )
	{
		/*the app was run with parameters*/
		printf("The apps needs 1 parameter\n");
		return EXIT_FAILURE;
	}

	fp = fopen(argv[1], "r");
	tree = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);

	printmenu(MENU_MAIN,NULL);
	printmenu(MENU_SOURCE,tree);

	mxmlDelete(tree);
	fclose(fp);
	return EXIT_SUCCESS;
}

