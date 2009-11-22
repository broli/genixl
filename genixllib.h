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

/*Menu items enum*/
typedef enum menu_items_e
{
	MENU_MAIN,
	MENU_SOURCE.
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
	MENU_TARGETS
} menu_items_t;

/*Prints the corresponding menu*/
menu_items_t printmenu(menu_items_t menu);

menu_items_t getuserchoice(menu_items_t location);


#endif /*GENIXLLIB_H_INCLUDED*/

