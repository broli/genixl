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

#include "../genixllib.h"
#include <mxml.h>

printmenuSource(menu_items_t menu,mxml_node_t *tree);
printmenuDestination(menu_items_t menu,mxml_node_t *tree);
printmenuLinkOptions(menu_items_t menu,mxml_node_t *tree);
printmenuImageOptions(menu_items_t menu,mxml_node_t *tree);
printmenuTableOptions(menu_items_t menu,mxml_node_t *tree);
printmenuColorOptions(menu_items_t menu,mxml_node_t *tree);
printmenuMarginOptions(menu_items_t menu,mxml_node_t *tree);
printmenuSecurityOptions(menu_items_t menu,mxml_node_t *tree);
printmenuTextOptions(menu_items_t menu,mxml_node_t *tree);
printmenuDocumentOptions(menu_items_t menu,mxml_node_t *tree);
printmenuBookmarks(menu_items_t menu,mxml_node_t *tree);
printmenuLastConversion(menu_items_t menu,mxml_node_t *tree);
printmenuMessages(menu_items_t menu,mxml_node_t *tree);
printmenuCookieOptions(menu_items_t menu,mxml_node_t *tree);
printmenuScheduling(menu_items_t menu,mxml_node_t *tree);
printmenuTargets(menu_items_t menu,mxml_node_t *tree);


/*implementation of functions goes here*/
menu_items_t printmenu(menu_items_t menu,mxml_node_t *tree)
{
	if ( menu == MENU_MAIN )
	{
		/*TODO make main menu*/
	}
	else if ( menu == MENU_SOURCE )
	{
		/*TODO make source menu*/
	}
	else if ( menu == MENU_DESTINATION )
	{
		/*TODO make destination menu*/
	}
	else if ( menu == MENU_LINK )
	{
		/*TODO make link menu */
	}
	else if ( menu == MENU_IMAGE )
	{
		/*TODO make image menu*/
	}
	else if ( menu == MENU_COLOR )
	{
		/*TODO make color menu*/
	}
	else if ( menu == MENU_MARGIN )
	{
		/*TODO make margin menu*/
	}
	else if ( menu == MENU_SECURITY )
	{
		/*TODO make security menu*/
	{
	else if ( menu == MENU_TEXT )
	{
		/*TODO make text menu*/
	}
	else if ( menu = MENU_DOCUMENT )
	{
		/*TODO make document menu */
	}
	else if ( menu == MENU_BOOKMARKS )
	{
		/*TODO Make bookmarks menu*/
	}
	else if ( menu == MENU_LASTCONVERSION )
	{
		/*TODO read the ixl docs and find out if 
		 * this can/should be modified by other
		 * programs (other than iSilox that is*/
	}
	else if ( menu == MENU_MESSAGES )
	{
		/*TODO make a messages menu*/
	}
	else if ( menu == MENU_COOKIES )
	{
		/*TODO make a cookies menu
		 * (not all options) */
	}
	else if ( menu == MENU_SCHEDULING )
	{
		/* I have no idea what this does
		 * and no intention of suporting it for now*/
	}
	else if ( menu == MENU_TARGETS )
	{
		/* I have no idea what this does
		 * and no intention of suporting it for now*/

	}
} /* menu_items_t printmenu(menu_items_t menu) */
