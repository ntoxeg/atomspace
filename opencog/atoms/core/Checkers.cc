/*
 * opencog/atoms/core/Checkers.cc
 *
 * Copyright (C) 2017 Linas Vepstas
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <opencog/atoms/base/Atom.h>
#include <opencog/atoms/base/ClassServer.h>

using namespace opencog;

/// Check to see if every input atom is of Evaluatable type.
bool check_evaluatable(const Handle& bool_atom)
{
	for (const Handle& h: bool_atom->getOutgoingSet())
	{
		if (not h->is_type(EVALUATABLE_LINK)) return false;
	}
	return true;
}

/* This runs when the shared lib is loaded. */
static __attribute__ ((constructor)) void init(void)
{
	classserver().addValidator(BOOLEAN_LINK, check_evaluatable);
}
