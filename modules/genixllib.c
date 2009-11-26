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

menu_items_t printmenuSource(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuDestination(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuLinkOptions(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuImageOptions(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuTableOptions(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuColorOptions(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuMarginOptions(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuSecurityOptions(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuTextOptions(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuDocumentOptions(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuBookmarks(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuLastConversion(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuMessages(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuCookieOptions(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuScheduling(menu_items_t menu,mxml_node_t *tree);
menu_items_t printmenuTargets(menu_items_t menu,mxml_node_t *tree);


/*implementation of functions goes here*/
menu_items_t printmenu(menu_items_t menu,mxml_node_t *tree)
{
	if ( menu == MENU_MAIN )
	{
		/*TODO make main menu*/
		return MENU_MAIN;
	}
	else if ( menu == MENU_SOURCE )
	{
		/*TODO make source menu*/
		return MENU_SOURCE;
	}
	else if ( menu == MENU_DESTINATION )
	{
		/*TODO make destination menu*/
		return MENU_DESTINATION;
	}
	else if ( menu == MENU_LINK )
	{
		/*TODO make link menu */
		return MENU_LINK;
	}
	else if ( menu == MENU_IMAGE )
	{
		/*TODO make image menu*/
		return MENU_IMAGE;
	}
	else if ( menu == MENU_COLOR )
	{
		/*TODO make color menu*/
		return MENU_COLOR;
	}
	else if ( menu == MENU_MARGIN )
	{
		/*TODO make margin menu*/
		return MENU_MARGIN;
	}
	else if ( menu == MENU_SECURITY )
	{
		/*TODO make security menu*/
		return MENU_SECURITY;
	}
	else if ( menu == MENU_TEXT )
	{
		/*TODO make text menu*/
		return MENU_TEXT;
	}
	else if ( menu == MENU_DOCUMENT )
	{
		/*TODO make document menu */
		return MENU_DOCUMENT;
	}
	else if ( menu == MENU_BOOKMARKS )
	{
		/*TODO Make bookmarks menu*/
		return MENU_BOOKMARKS;
	}
	else if ( menu == MENU_LASTCONVERSION )
	{
		/*TODO read the ixl docs and find out if 
		 * this can/should be modified by other
		 * programs (other than iSilox that is*/
		/*For now we return error to catch this*/
		return MENU_ERROR;
	}
	else if ( menu == MENU_MESSAGES )
	{
		/*TODO make a messages menu*/
		return MENU_MESSAGES;
	}
	else if ( menu == MENU_COOKIES )
	{
		/*TODO make a cookies menu
		 * (not all options) */
		return MENU_COOKIES;
	}
	else if ( menu == MENU_SCHEDULING )
	{
		/* I have no idea what this does
		 * and no intention of suporting it for now*/
		return MENU_ERROR;
	}
	else if ( menu == MENU_TARGETS )
	{
		/* I have no idea what this does
		 * and no intention of suporting it for now*/
		return MENU_ERROR;

	}

	return MENU_ERROR;
} /* menu_items_t printmenu(menu_items_t menu) */


menu_items_t printmenuSource(menu_items_t menu,mxml_node_t *tree)
{
	
}
