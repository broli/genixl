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

#include "../ixlmxml.h"

/*Implementation of the functions goes here*/

char *getElemData(mxml_node_t *TopNode,char *Name)
{
        mxml_node_t *Element=NULL;

        Element = mxmlFindElement(TopNode,TopNode,              /*Search inside the TopNode node*/
                                   Name, NULL, NULL,            /*The "name" sub node */
                                   MXML_DESCEND);               /*Descending*/

        if ( Element != NULL && Element->child != NULL && Element->child->type == MXML_OPAQUE)
        {
                /*found the Element , and it has a child and its opaque*/
                return Element->child->value.opaque;
        }

        return "<n/a>"; /*default to <n/a> string*/
}


char *getElemData(mxml_node_t *TopNode,char *Name)
{
	mxml_node_t *Element=NULL;

        Element = mxmlFindElement(TopNode,TopNode,              /*Search inside the TopNode node*/
                                   Name, NULL, NULL,            /*The "name" sub node */
                                   MXML_DESCEND);               /*Descending*/

        if ( Element != NULL && Element->value.element.num_attrs > 0)
        {
                /*found the Element , and it has a value*/
                return mxmlElementGetAttr(Element, Name);
        }

	return "<n/a>"; /*default answer*/
}
