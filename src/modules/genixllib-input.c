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

#include <mxml.h>
#include <stdlib.h>


#include "../genixllib.h"
#include "../ixlmxml.h"

/* This function reads the user input,and does one of two things
 *  while in the main Menu, it returns the sub menu choosed (tree can be null)
 *  while in a submenu, it reads the new value into the tree (tree required)
 * This Function returns 2 things
 *  while in the main menu, the submenu choosed
 *  while in the submenu,MENU_ERROR if it cant allocate or modify the tree, the submenu otherwise*/
menu_items_t processUserinput(menu_items_t location,mxml_node_t *tree);

/* Helper functions to distribute the work */
menu_items_t read_user_choice_Main(void);


menu_items_t processUserinput(menu_items_t location,mxml_node_t *tree)
{
	menu_items_t choice;

	if ( location == MENU_MAIN )
	{
		/* we are located in the main menu */
		/* I should read the user input, 
		 * and return the corresponding submenu */
		choice = read_user_choice_Main();
		return choice;
	}
	else
	{
		/* we are in a sub menu */
		/* i should read the user selection (node name)
		 * and ask about the data (node contents)
		 * validate, and add to the tree */
	}

}


menu_items_t read_user_choice_Main(void)
{
	char *line=NULL;
	size_t cant=0;   /* we let getline manage this) */
	
	if ( getline ( &line, &cant,stdin) == -1 )
	{
		fprintf (stderr, "Cant read from stdin\n");
	}
	else
	{
		/* was able to read user imput
		 * now i need to sanitize it and 
		 * make sure it makes some sense */
	}
}
