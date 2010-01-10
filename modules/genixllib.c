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

/*Main menu, no error cheking and no parameters, just print the main menu*/
void printmenuMain(void);
/*these do have return code, because the mxml can fail
 * the only parameter needed is the tree,
 * so it can show the current setting*/
/* TODO re-think this error cheking thing. dosnt hold much water now*/
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


/*function to print paths*/
int PrintPath(mxml_node_t *TopNode,char *name);

/*function to print Patterns*/
int PrintPattern(mxml_node_t *TopNode,char *name);


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
		rtrnMenu = printmenuDestination(tree);	
		return rtrnMenu;
	}
	else if ( menu == MENU_LINK )
	{
		rtrnMenu = printmenuLinkOptions(tree);
		return rtrnMenu;
	}
	else if ( menu == MENU_IMAGE )
	{
		rtrnMenu = printmenuImageOptions(tree);
		return rtrnMenu;
	}
	else if ( menu == MENU_TABLE )
	{
		rtrnMenu = printmenuTableOptions(tree);	
		return rtrnMenu;
	}

	else if ( menu == MENU_COLOR )
	{
		rtrnMenu = printmenuColorOptions(tree);
		return rtrnMenu;
	}
	else if ( menu == MENU_MARGIN )
	{
		rtrnMenu = printmenuMarginOptions(tree);
		return rtrnMenu;
	}
	else if ( menu == MENU_SECURITY )
	{
		rtrnMenu = printmenuSecurityOptions(tree);
		return rtrnMenu; 
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



int PrintPath(mxml_node_t *TopNode,char *name)
{
	mxml_node_t *SearchedNode=NULL;
	mxml_node_t *Pathnode=NULL;

	/*This function searchs the given node, from the given top node
	 * and prints all the subnodes called Path
	 * (it assumes its a node with paths)*/
	SearchedNode = mxmlFindElement(TopNode,TopNode,		/*Search inside the TopNode node*/
					name, NULL, NULL,	/*The name sub node */
					MXML_DESCEND);		/*Descending*/
	if ( SearchedNode != NULL )
	{
		/*Got the SearchedNode node, search all the Paths inside*/
		Pathnode = mxmlFindElement(SearchedNode,SearchedNode,	/*Search inside the SearchedNode node*/
						"Path", NULL, NULL,	/*the path node*/
						MXML_DESCEND);          /*Descending*/
		if ( Pathnode == NULL)
		{
			/*there is a SearchedNode node, but no paths*/
			/*this double chek is necesary, because the else part 
			 * of this if has to be a loop with the same condition*/
			printf("*\t<n/a>\n");
		}
		while ( Pathnode != NULL )
		{
			if ( Pathnode->child != NULL && Pathnode->child->type == MXML_OPAQUE )
			{
				/*it has a child, and its opaque*/
				printf("*\t%s\n",Pathnode->child->value.opaque);
			}
			else
			{
				/*path with no data or data is not opaque*/
				printf("*\t<n/a>\n");
			}

			/*advance Pathnode to the next path*/
			Pathnode = mxmlFindElement(Pathnode, SearchedNode,	/*Search inside the Sources node*/
							"Path", NULL, NULL,	/*the path node*/
							MXML_DESCEND);          /*Descending*/

		} /*if we have no more Paths, the search will return null, and this loop wil end*/
	} /*end of the SearchedNode procesing code*/
	else
	{
		/*No SearchedNode node, print empty*/
		printf("*\t<n/a>\n");
	}

	return 0;
}

int PrintPattern(mxml_node_t *TopNode,char *name)
{
	/* TODO: rename variables in this function to match what it does*/
	mxml_node_t *SearchedNode=NULL;
	mxml_node_t *Pathnode=NULL;

	/*This function searchs the given node, from the given top node
	 * and prints all the subnodes called Path
	 * (it assumes its a node with paths)*/
	SearchedNode = mxmlFindElement(TopNode,TopNode,		/*Search inside the TopNode node*/
					name, NULL, NULL,	/*The name sub node */
					MXML_DESCEND);		/*Descending*/
	if ( SearchedNode != NULL )
	{
		/*Got the SearchedNode node, search all the Paths inside*/
		Pathnode = mxmlFindElement(SearchedNode,SearchedNode,	/*Search inside the SearchedNode node*/
						"Pattern", NULL, NULL,	/*the path node*/
						MXML_DESCEND);          /*Descending*/
		if ( Pathnode == NULL)
		{
			/*there is a SearchedNode node, but no paths*/
			/*this double chek is necesary, because the else part 
			 * of this if has to be a loop with the same condition*/
			printf("*\t<n/a>\n");
		}
		while ( Pathnode != NULL )
		{
			if ( Pathnode->child != NULL && Pathnode->child->type == MXML_OPAQUE )
			{
				/*it has a child, and its opaque*/
				printf("*\t%s\n",Pathnode->child->value.opaque);
			}
			else
			{
				/*path with no data or data is not opaque*/
				printf("*\t<n/a>\n");
			}

			/*advance Pathnode to the next path*/
			Pathnode = mxmlFindElement(Pathnode, SearchedNode,	/*Search inside the Sources node*/
							"Pattern", NULL, NULL,	/*the path node*/
							MXML_DESCEND);          /*Descending*/

		} /*if we have no more Paths, the search will return null, and this loop wil end*/
	} /*end of the SearchedNode procesing code*/
	else
	{
		/*No SearchedNode node, print empty*/
		printf("*\t<n/a>\n");
	}

	return 0;
}


void printmenuMain(void)
{
	system("clear");
	printf("Main\n----\n");
	printf( "01)  Source->\n"
		"02)  Destination->\n"
		"03)  LinkOptions->\n"
		"04)  ImageOptions->\n"
		"05)  TableOptions->\n"
		"06)  ColorOptions->\n"
		"07)  MarginOptions->\n"
		"08)  SecurityOptions->\n"
		"09)  TextOptions->\n"
		"10)  DocumentOptions->\n"
		"11)  Bookmarks->\n"
		"12)  LastConversion->\n"
		"13)  Messages->\n"
		"14)  CookieOptions->\n"
		"15)  Scheduling->\n"
		"16)  Targets->\n"
		"17)  Exit\n\n");
}

menu_items_t printmenuSource(mxml_node_t *tree)
{
	mxml_node_t *SourceNode=NULL; /*pointer to the Source node, topnode of this function*/

	system("clear");
	printf("Source\n------\n\n");

	SourceNode = mxmlFindElement(tree, tree, 		/*Search from the top*/
				"Source", NULL, NULL, 		/*The Source element*/
				MXML_DESCEND); 			/*Descending*/

	/*the search might return null*/
	if ( SourceNode != NULL )
	{
		/*search and handwalk */
		printf("01) Sources:\n");
		/*print all the Paths in the sources node*/
		PrintPath(SourceNode,"Sources");

		/*Now, lets search the User name********************************************/

		printf("02) UserName: %s\n",getElemData(SourceNode,"UserName") );

		/*Now, lets search the Password*******************************************/

		printf("03) Password: %s\n",getElemData(SourceNode,"Password") );

		/*Now, lets search the CharSet********************************************/

		printf("04) CharSet: %s\n\n",getElemData(SourceNode,"CharSet") );

	}
	else
	{
		/*No source node*/
		/*print empty */
		printf("01) Sources:\n"
				"*\t<n/a>\n\n"
			"02) UserName: <n/a>\n\n"
			"03) Password: <n/a>\n\n"
			"04) CharSet: <n/a>\n"
			"\n");
	}
	return MENU_SOURCE;
}


menu_items_t printmenuDestination(mxml_node_t *tree)
{
	mxml_node_t *Destination=NULL;

	system("clear");
	printf("Destination\n-----------\n\n");

	Destination = mxmlFindElement(tree, tree, 		/*Search from the top*/
				"Destination", NULL, NULL, 	/*The Destination element*/
				MXML_DESCEND); 			/*Descending*/

	/*the search might return null*/
	if ( Destination != NULL )
	{
		printf("01) Title: %s\n",getElemData(Destination,"Title") );
		
		/*Now, lets search the hotsync*********************************************/
		
		printf("02) HotSync:\n");
		PrintPath(Destination,"HotSync");

		/*Now, lets search the ActiveSync ***************************************/
		
		printf("03) ActiveSync:\n");
		PrintPath(Destination,"ActiveSync");

		/*Now, lets search the Files ***************************************/
		
		printf("05) Files:\n");
		PrintPath(Destination,"Files");

		printf("\n"); /*make it pretty*/


	}/*end of the Destination procesing*/
	else 
	{
		/*No destination node, print empty*/
		printf("01) Title: <n/a>\n"
			"02) HotSync:\n"
				"\t<n/a>\n"
			"03) ActiveSync:\n"
				"\t<n/a>\n"
			"04) Files:\n"
				"\t<n/a>\n");
	}

	return MENU_DESTINATION;
}

menu_items_t printmenuLinkOptions(mxml_node_t *tree)
{
	mxml_node_t *LinkOptions=NULL;

	system("clear");
	printf("LinkOptions\n-----------\n\n");

	LinkOptions = mxmlFindElement(tree, tree, 		/*Search from the top*/
				"LinkOptions", NULL, NULL, 	/*The LinkOptions element*/
				MXML_DESCEND); 			/*Descending*/

	/*the search might return null*/
	if ( LinkOptions != NULL )
	{
		/*Print MaximumDepth*/
		printf("01) MaximumDepth:\t\t%s\n",getElemValue(LinkOptions,"MaximumDepth"));

		/*Print FollowOffsite*/
		printf("02) FollowOffsite:\t\t%s\n",getElemValue(LinkOptions,"FollowOffsite") );

		/*Print MaximumOffsiteDepth*/
		printf("03) MaximumOffsiteDepth:\t%s\n",getElemValue(LinkOptions,"MaximumOffsiteDepth") );

		/*Print SubDirOnly*/
		printf("04) SubDirOnly:\t\t\t%s\n",getElemValue(LinkOptions,"SubDirOnly") );

		/*Print UnresolvedDetail*/
		printf("05) UnresolvedDetail:\t\t%s\n",getElemValue(LinkOptions,"UnresolvedDetail") );

		/*Print Exclude*/
		printf("06) Exclude:\n");
		PrintPattern(LinkOptions,"Exclude");

		/*Print include*/
		printf("07) Include:\n");
		PrintPattern(LinkOptions,"Include");

		/*Print External Docuemnts*/
		printf("\n"); /*make it pretty*/
		printf("08) ExternalDocuments ->(not implemented for now)\n\n");



	}/*end of the LinkOptions procesing*/
	else 
	{
		/*No LinkOptions node, print empty*/
		printf("01) MaximumDepth: \t<n/a>\n"
			"02) FollowOffsite: \t<n/a>\n"
			"03) MaximumOffsiteDepth: <n/a>\n"
			"04) SubDirOnly: \t\t<n/a>\n"
			"05) UnresolvedDetail \t<n/a>\n"
			"06) Exclude:\n"
				"\t<n/a>\n"
			"07) Include:\n"
				"\t<n/a>\n"
			"08) ExternalDocuments ->(not implemented for now)\n");
	}

	return  MENU_LINK;
}

menu_items_t printmenuImageOptions(mxml_node_t *tree)
{
	mxml_node_t *ImageOptions=NULL;
	system("clear");
	printf("ImageOptions\n-----------\n\n");

	ImageOptions = mxmlFindElement(tree, tree,               /*Search from the top*/
				"ImageOptions", NULL, NULL,      /*The Image element*/
				MXML_DESCEND);                  /*Descending*/

	/*the search might return null*/
	if ( ImageOptions != NULL )
	{
        	/*Print AltText*/
		printf("01) AltText:\t\t%s\n",getElemValue(ImageOptions,"AltText") );

		/*Print Images*/
		printf("02) Images:\t\t%s\n",getElemValue(ImageOptions,"Images") );

		/*Print ResizeLargeImages*/
		printf("03) ResizeLargeImages:\t%s\n",getElemValue(ImageOptions,"ResizeLargeImages") );

		/*Print MaximumWidth*/
		printf("04) MaximumWidth:\t%s\n",getElemValue(ImageOptions,"MaximumWidth") );

		/*Print MaximumHeight*/
		printf("05) MaximumHeight:\t%s\n",getElemValue(ImageOptions,"MaximumHeight") );

		/*Print ImproveContrast*/
		printf("06) ImproveContrast:\t%s\n",getElemValue(ImageOptions,"ImproveContrast") );

		/*Print Dither*/
		printf("07) Dither:\t\t%s\n",getElemValue(ImageOptions,"Dither") );

		/*Print Compress*/
		printf("08) Compress:\t\t%s\n",getElemValue(ImageOptions,"Compress") );

		/*Print LossyLevel*/
		printf("09) LossyLevel:\t\t%s\n",getElemValue(ImageOptions,"LossyLevel") );

		/*Print LossyQuality*/
		printf("10) LossyQuality:\t%s\n",getElemValue(ImageOptions,"LossyQuality") );

		/*Print BitDepth1*/
		printf("11) BitDepth1:\t\t%s\n",getElemValue(ImageOptions,"BitDepth1") );

		/*Print BitDepth2*/
		printf("12) BitDepth2:\t\t%s\n",getElemValue(ImageOptions,"BitDepth2") );

		/*Print BitDepth4*/
		printf("13) BitDepth4:\t\t%s\n",getElemValue(ImageOptions,"BitDepth4") );

		/*Print BitDepth8*/
		printf("14) BitDepth8:\t\t%s\n",getElemValue(ImageOptions,"BitDepth8") );

		/*Print BitDepth16*/
		printf("15) BitDepth16:\t\t%s\n",getElemValue(ImageOptions,"BitDepth16") );

		printf("\n\n");
	}
	/*end of the ImageOptions procesing*/
        else 
        {
                /*No ImageOptions node, print empty*/
                printf("01) AltText: \t\t<n/a>\n"
                        "02) Images: \t\t<n/a>\n"
                        "03) ResizeLargeImages: \t<n/a>\n"
                        "04) MaximumWidth: \t<n/a>\n"
			"05) MaximumHeight: \t<n/a>\n"
			"06) ImproveContrast: \t<n/a>\n"
			"07) Dither: \t\t<n/a>\n"
			"08) Compress: \t\t<n/a>\n"
			"09) LossyLevel: \t<n/a>\n"
			"10) LossyQuality: \t<n/a>\n"
			"11) BitDepth1: \t\t<n/a>\n"
			"12) BitDepth2: \t\t<n/a>\n"
			"13) BitDepth4: \t\t<n/a>\n"
			"14) BitDepth8: \t\t<n/a>\n"
			"15) BitDepth16: \t<n/a>\n"
                        "\n\n");
        }

	return MENU_IMAGE;
}


menu_items_t printmenuTableOptions(mxml_node_t *tree)
{
	mxml_node_t *TableOptions=NULL;

	system("clear");
	printf("TableOptions\n-----------\n\n");

	TableOptions = mxmlFindElement(tree, tree, 		/*Search from the top*/
				"TableOptions", NULL, NULL, 	/*The Table element*/
				MXML_DESCEND); 			/*Descending*/

	/*the search might return null*/
	if ( TableOptions != NULL )
	{

		/*Print IgnoreTables*/
		printf("01) IgnoreTables:\t\t%s\n",getElemValue(TableOptions,"IgnoreTables") );

		/*Print AddSeparators*/
		printf("02) AddSeparators:\t\t%s\n",getElemValue(TableOptions,"AddSeparators") );

		/*Print UseMinimumDepth*/
		printf("03) UseMinimumDepth:\t\t%s\n",getElemValue(TableOptions,"UseMinimumDepth") );

		/*Print MinimumDepth*/
		printf("04) MinimumDepth:\t\t%s\n",getElemValue(TableOptions,"MinimumDepth") );

		/*Print UseMaximumBottomReach*/
		printf("05) UseMaximumBottomReach:\t%s\n",getElemValue(TableOptions,"UseMaximumBottomReach") );

		/*Print MaximumBottomReach*/
		printf("06) MaximumBottomReach:\t\t%s\n",getElemValue(TableOptions,"MaximumBottomReach") );

		/*Print UnfoldFullPageTables*/
		printf("07) UnfoldFullPageTables:\t%s\n",getElemValue(TableOptions,"UnfoldFullPageTables") );

		/*Print IgnorePixelWidths*/
		printf("08) IgnorePixelWidths:\t\t%s\n",getElemValue(TableOptions,"IgnorePixelWidths") );


		printf("\n\n");

	}/*end of the TableOptions procesing*/
	else 
	{
		/*No TableOptions node, print empty*/
		printf("01) IgnoreTables: \t\t<n/a>\n"
			"02) AddSeparators: \t\t<n/a>\n"
			"03) UseMinimumDepth: \t\t<n/a>\n"
			"04) MinimumDepth: \t\t<n/a>\n"
			"05) UseMaximumBottomReach: \t<n/a>\n"
			"06) MaximumBottomReach: \t\t<n/a>\n"
			"07) UnfoldFullPageTables: \t<n/a>\n"
			"08) IgnorePixelWidths: \t\t<n/a>\n"
			"\n\n");
	}


	return MENU_TABLE;
}

menu_items_t printmenuColorOptions(mxml_node_t *tree)
{
	mxml_node_t *ColorOptions=NULL;

	system("clear");
	printf("ColorOptions\n-----------\n\n");

	ColorOptions = mxmlFindElement(tree, tree, 		/*Search from the top*/
				"ColorOptions", NULL, NULL, 	/*The ColorOptions element*/
				MXML_DESCEND); 			/*Descending*/

	/*the search might return null*/
	if ( ColorOptions != NULL )
	{
	
		/*Print BackgroundColors*/
		printf("01) BackgroundColors:\t%s\n",getElemValue(ColorOptions,"BackgroundColors") );
	
		/*Print TextColors*/
		printf("02) TextColors:\t\t%s\n",getElemValue(ColorOptions,"TextColors") );

		printf("\n\n");

	}/*end of the ColorOptions procesing*/
	else 
	{
		/*No ColorOptions node, print empty*/
		printf("01) BackgroundColors: \t<n/a>\n"
			"02) TextColors: \t\t<n/a>\n"
			"\n\n");
	}

	return MENU_COLOR;
}

menu_items_t printmenuMarginOptions(mxml_node_t *tree)
{
	mxml_node_t *MarginOptions=NULL;

	system("clear");
	printf("MarginOptions\n-----------\n\n");

	MarginOptions = mxmlFindElement(tree, tree, 		/*Search from the top*/
				"MarginOptions", NULL, NULL, 	/*The MarginOptions element*/
				MXML_DESCEND); 			/*Descending*/

	/*the search might return null*/
	if ( MarginOptions != NULL )
	{
	
		/*Print LeftRightMargins*/
		printf("01) LeftRightMargins:\t%s\n",getElemValue(MarginOptions,"LeftRightMargins") );
	
		/*Print LeftRightPadding*/
		printf("02) LeftRightPadding:\t%s\n",getElemValue(MarginOptions,"LeftRightPadding") );

		printf("\n\n");

	}/*end of the MarginOptions procesing*/
	else 
	{
		/*No MarginOptions node, print empty*/
		printf("01) LeftRightMargins: \t<n/a>\n"
			"02) LeftRightPadding:\t<n/a>\n"
			"\n\n");
	}
	
	return MENU_MARGIN;
}


menu_items_t printmenuSecurityOptions(mxml_node_t *tree)
{
	mxml_node_t *SecurityOptions=NULL;
	mxml_node_t *SecExpirationOptions=NULL;
	mxml_node_t *SecPasswordOptions=NULL;
	mxml_node_t *SecRegistrationCodeOptions=NULL;

	system("clear");
	printf("SecurityOptions\n-----------\n\n");

	SecurityOptions = mxmlFindElement(tree, tree, 		/*Search from the top*/
				"SecurityOptions", NULL, NULL, 	/*The SecurityOptions element*/
				MXML_DESCEND); 			/*Descending*/

	/*the search might return null*/
	if ( SecurityOptions != NULL )
	{

		/*Print LeftRightMargins*/
		printf("01) Convert:\t\t%s\n",getElemValue(SecurityOptions,"Convert") );

		/*Print CopyBeam*/
		printf("02) CopyBeam:\t\t%s\n",getElemValue(SecurityOptions,"CopyBeam") );

		/*Print CopyAndPaste*/
		printf("03) CopyAndPaste:\t%s\n",getElemValue(SecurityOptions,"CopyAndPaste") );

		/*Print Modify*/
		printf("04) Modify:\t\t%s\n",getElemValue(SecurityOptions,"Modify") );

		/*Print Print*/
		printf("05) Print:\t\t%s\n",getElemValue(SecurityOptions,"Print") );
		
		/*Print sub node Expiration*/
		printf("\nExpiration: \n");

		SecExpirationOptions = mxmlFindElement(SecurityOptions,SecurityOptions, 	/*Search inside SecurityOptions node*/
					"Expiration", NULL, NULL, 				/*The Expiration element*/
					MXML_DESCEND); 						/*Descending*/
		
		if (SecExpirationOptions != NULL)
		{
			/*print the subnodes*/
			/*Print Expires*/
			printf("\t 06) Expires:\t\t%s\n",getElemValue(SecExpirationOptions,"Expires") );

			/*Print Date*/
			printf("\t 07) Date:\t\t%s\n",getElemValue(SecExpirationOptions,"Date") );

		}
		else
		{
			/*print empty*/
			printf("\t 06) Expires:\t\t<n/a>\n"
				"\t 07) Date:\t\t<n/a>\n");

		}
		/*Print sub node Password*/
		printf("\nPassword:\n");

		SecPasswordOptions = mxmlFindElement(SecurityOptions,SecurityOptions, 	/*Search inside SecurityOptions node*/
					"Password", NULL, NULL, 				/*The Expiration element*/
					MXML_DESCEND); 						/*Descending*/
		
		if (SecPasswordOptions != NULL)
		{
			/*print the subnodes*/
			/*Print Require*/
			printf("\t 08) Require:\t\t%s\n",getElemValue(SecPasswordOptions,"Require") );

			/*Print Password*/
			printf("\t 09) Password:\t\t%s\n",getElemData(SecPasswordOptions,"Password") );

		}
		else
		{
			/*print empty*/
			printf("\t 08) Require:\t\t<n/a>\n"
				"\t 09) Password:\t\t<n/a>\n");

		}



	} /*end of the SecurityOptions procesing*/
	else 
	{
		/*No SecurityOptions node, print empty*/
		printf("01) Convert:\t\t<n/a>\n"
			"02) CopyBeam:\t\t<n/a>\n"
			"03) CopyAndPaste:\t<n/a>\n"
			"04) Modify:\t\t<n/a>\n"
			"05) Print:\t\t<n/a>\n"
			"\nExpiration: \n"
			"\t 06) Expires:\t\t<n/a>\n"
			"\t 07) Date:\t\t<n/a>\n"
			"\nPassword:\n"
			"\t 08) Require:\t\t<n/a>\n"
			"\t 09) Password:\t\t<n/a>\n"
			"\nRegistrationCode:\n"
			"\t 10) Require:\t\t<n/a>\n"
			"\t 11) DocumentID:\t<n/a>\n"
			"\n\n");

	}
		

	return MENU_SECURITY;
}

/*
menu_items_t printmenuLinkOptions(mxml_node_t *tree)
{
	mxml_node_t *LinkOptions=NULL;

	system("clear");
	printf("LinkOptions\n-----------\n\n");

	LinkOptions = mxmlFindElement(tree, tree, 		*Search from the top*
				"LinkOptions", NULL, NULL, 	*The LinkOptions element*
				MXML_DESCEND); 			*Descending*

	*the search might return null*
	if ( LinkOptions != NULL )
	{
		*Print MaximumDepth*
		.
		.
		.
		.

	}*end of the LinkOptions procesing*
	else 
	{
		*No LinkOptions node, print empty*
		printf("1) .
			.
			.
			.
			.\n\n");
	}

	return  MENU_LINK;
} */
