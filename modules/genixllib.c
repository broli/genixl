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
#include <stdlib.h>

/*Main menu, no error cheking and no parameters, just print the main menu*/
void printmenuMain(void);
/*these do have return code, because the mxml can fail
 * the only parameter needed is the tree,
 * so it can show the current setting*/
menu_items_t printmenuSource(mxml_node_t *tree);
menu_items_t printmenuDestination(mxml_node_t *tree);
menu_items_t printmenuLinkOptions(mxml_node_t *tree);
menu_items_t printmenuImageOptions(mxml_node_t *tree);
menu_items_t printmenuTableOptions(mxml_node_t *tree);
menu_items_t printmenuColorOptions(mxml_node_t *tree);
menu_items_t printmenuMarginOptions(mxml_node_t *tree);
menu_items_t printmenuSecurityOptions(mxml_node_t *tree);
menu_items_t printmenuTextOptions(mxml_node_t *tree);
menu_items_t printmenuDocumentOptions(mxml_node_t *tree);
menu_items_t printmenuBookmarks(mxml_node_t *tree);
menu_items_t printmenuLastConversion(mxml_node_t *tree);
menu_items_t printmenuMessages(mxml_node_t *tree);
menu_items_t printmenuCookieOptions(mxml_node_t *tree);
menu_items_t printmenuScheduling(mxml_node_t *tree);
menu_items_t printmenuTargets(mxml_node_t *tree);


/*implementation of functions goes here*/
menu_items_t printmenu(menu_items_t menu,mxml_node_t *tree)
{
	menu_items_t rtrnMenu=MENU_ERROR;

	if ( menu == MENU_MAIN )
	{
		printmenuMain();
		return MENU_MAIN;
	}
	else if ( menu == MENU_SOURCE )
	{
		rtrnMenu = printmenuSource(tree);
		return rtrnMenu;
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
	/*this never should be executed*/
	return MENU_ERROR;
} /* menu_items_t printmenu(menu_items_t menu) */

void printmenuMain(void)
{
	system("clear");
	printf("Main\n----\n");
	printf( "1)   Source\n"
		"2)   Destination\n"
		"3)   LinkOptions\n"
		"4)   ImageOptions\n"
		"5)   TableOptions\n"
		"6)   ColorOptions\n"
		"7)   MarginOptions\n"
		"8)   SecurityOptions\n"
		"9)   TextOptions\n"
		"10)  DocumentOptions\n"
		"11)  Bookmarks\n"
		"12)  LastConversion\n"
		"13)  Messages\n"
		"14)  CookieOptions\n"
		"15)  Scheduling\n"
		"16)  Targets\n"
		"17)  Exit\n\n");
}

menu_items_t printmenuSource(mxml_node_t *tree)
{
	mxml_node_t *node=NULL; /*temporal node, used to walk*/
	mxml_node_t *SourceNode=NULL; /*pointer to the Source node, topnode of this function*/
	mxml_node_t *SourcesNode=NULL;
	mxml_node_t *Pathnode=NULL; 
	mxml_node_t *UserName=NULL;


	char *charPtr=NULL; /*pointer to hold strstr return value*/

	
	system("clear");
	printf("Source\n------\n");

	SourceNode = mxmlFindElement(tree, tree, 		/*Search from the top*/
				"Source", NULL, NULL, 		/*The Source element*/
				MXML_DESCEND); 			/*Descending*/

	/*the search might return null*/
	if ( SourceNode != NULL )
	{
		/*search and handwalk */
		printf("1) Sources:\n");

		/*First lets search the Sources, its a multi string option 
		 * So we need to search, walk, and iterate, trough tree, with
		 * the SourcesNode beeing the top node*/
		SourcesNode = mxmlFindElement(SourceNode,SourceNode,	/*Search inside the Source node*/
						"Sources", NULL, NULL,	/*The Sources sub node */
						MXML_DESCEND);		/*Descending*/
		if ( SourcesNode != NULL )
		{
			/*Got the sources node, search all the Paths inside*/
			Pathnode = mxmlFindElement(SourcesNode,SourcesNode,	/*Search inside the Sources node*/
							"Path", NULL, NULL,	/*the path node*/
							MXML_DESCEND);          /*Descending*/
			if ( Pathnode == NULL)
			{
				/*there is a Sources node, but no paths*/
				/*if we are here the while 4 lines below is not gona execute*/
				printf("\t\t<n/a>\n");
			}

			while ( Pathnode != NULL )
			{
				node = mxmlWalkNext ( Pathnode, Pathnode, MXML_DESCEND); /*walk*/
				if ( node->type == MXML_OPAQUE )
				{
					/*its opaque, so it might be the data, or white space*/
					
					charPtr = strstr( node->value.opaque,"\n"); /*search for new line*/
					if (charPtr == NULL )
					{
						/*no whitespace, so this is the data*/
						printf("\t%s\n",node->value.opaque);
					}
					else
					{
						/*whitespace, so this is not the node i need*/
						node = mxmlWalkNext ( node,  Pathnode, MXML_DESCEND);
						if ( node->type == MXML_OPAQUE )
						{
							charPtr = strstr( node->value.opaque,"\n"); /*search for new line*/
							if (charPtr == NULL )
							{
								/*no whitespace, so this is the data*/
								printf("\t%s\n",node->value.opaque);
							}
						}
						else
						{
							/*if this is not opaque, we walked in the next path
							 * dont print anythin, and dont do anything
							 * the next iteration of the loop will search from the 
							 * previus Path node and find this one */
						}

					}
				}
				else
				{
					/*its not opaque, i dont know what to do*/
					/*TODO analize this situation, if its posible, and
					 * what to do when encountered*/
				}

				/*advance Pathnode to the next path*/
				Pathnode = mxmlFindElement(Pathnode, SourcesNode,	/*Search inside the Sources node*/
								"Path", NULL, NULL,	/*the path node*/
								MXML_DESCEND);          /*Descending*/

			} /*if we have no more Paths, the search will return null, and this loop wil end*/
		} /*end of the sources procesing code*/
		else
		{
			/*No sources node, print empty*/
			printf("\t<n/a>\n");
		}

		/*Now, lets search the User name*/
		UserName = mxmlFindElement(SourceNode,SourceNode,	/*Search inside the Source node*/
						"UserName", NULL, NULL,	/*The UserName sub node */
						MXML_DESCEND);		/*Descending*/
		if ( UserName != NULL && UserName->child != NULL)
		{
			/*found the user name, and it has a child*/
			printf("2) UserName: %s\n",UserName->child->value.opaque);

		}
		else 
		{
			
		}



	}
	else
	{
		/*No source node*/
		/*print empty */
		printf("1) Sources:\n"
				"\t\t<n/a>\n"
			"2) UserName: <n/a>\n"
			"3) Password: <n/a>\n"
			"4) CharSet: <n/a>\n");
	}
	return MENU_SOURCE;
}
