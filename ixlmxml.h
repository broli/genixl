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

#ifndef IXLMXML_H_INCLUDED
#define IXLMXML_H_INCLUDED

#include <mxml.h>

/*This function will recieve an empty tree, and will
 * initialize it with the defaults
 * Returns 0 if ok, != 0 otherwise*/
int initialize(mxml_node_t *tree);

/*This function is the write call back
 * it will make the xml ""pretty""
const char *whitespace_cb(mxml_node_t *node, int where);
this dosnt need to be public*/

/*Function te get the opaque value of the child node of an element*/
char *getElemData(mxml_node_t *TopNode,char *Name);
char *getElemvalue(mxml_node_t *TopNode,char *Name);


#endif /*IXLMXML_H_INCLUDED*/

