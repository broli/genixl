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

#ifndef GENIXLLIB_H_INCLUDED
#define GENIXLLIB_H_INCLUDED

#include <mxml.h>

/*Menu items enum*/
typedef enum menu_items_e 
{
	MENU_MAIN,
	MENU_SOURCE,
	MENU_DESTINATION,
	MENU_LINK,
	MENU_IMAGE,
	MENU_TABLE,
	MENU_COLOR,
	MENU_MARGIN,
	MENU_SECURITY,
	MENU_TEXT,
	MENU_DOCUMENT,
	MENU_BOOKMARKS, 
	MENU_LASTCONVERSION,
	MENU_MESSAGES,
	MENU_COOKIES,
	MENU_SCHEDULING,
	MENU_TARGETS,
	MENU_ERROR
} menu_items_t;

/*Prints the corresponding menu
 * it returns the menu that was just printed*/
menu_items_t printmenu(menu_items_t menu,mxml_node_t *tree);

/*This function reads the user input,and does one of two things
 * while in the main Menu, it returns the sub menu choosed (tree can be null)
 * while in a submenu, it reads the new value into the tree (tree required) 
 * This Function returns 2 things
 * while in the main menu, the submenu choosed
 * while in the submenu,MENU_ERROR if it cant allocate or modify the tree, the submenu otherwise*/
menu_items_t processUserinput(menu_items_t location,mxml_node_t *tree);


#endif /*GENIXLLIB_H_INCLUDED*/

