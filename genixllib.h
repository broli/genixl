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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <iconv.h>
#include <mxml.h>

/*This function will recieve an empty tree, and will
 * initialize it with the defaults
 * Returns 0 if ok, != 0 otherwise*/
int initialize(mxml_node_t *tree);

/*This function is the write call back
 * it will make the xml ""pretty""*/
const char *whitespace_cb(mxml_node_t *node, int where);



#endif /*GENIXLLIB_H_INCLUDED*/

