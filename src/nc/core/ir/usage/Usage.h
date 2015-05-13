/* The file is part of Snowman decompiler.             */
/* See doc/licenses.txt for the licensing information. */

/* * SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
 * Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
 * Alexander Fokin, Sergey Levin, Leonid Tsvetkov
 *
 * This file is part of SmartDec decompiler.
 *
 * SmartDec decompiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SmartDec decompiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <nc/config.h>

#include <boost/unordered_set.hpp>

namespace nc {
namespace core {
namespace ir {

class Term;

namespace usage {

/**
 * Set of terms producing actual high-level code.
 */
class Usage {
    boost::unordered_set<const Term *> usedTerms_; ///< Set of used terms.

    public:

    /**
     * \param[in] term Term.
     *
     * \return True if term is used.
     */
    bool isUsed(const Term *term) const { return usedTerms_.find(term) != usedTerms_.end(); }

    /**
     * Marks a term as used.
     *
     * \param[in] term Term.
     */
    void makeUsed(const Term *term) { usedTerms_.insert(term); }

    /**
     * Marks a term as unused.
     *
     * \param[in] term Term.
     */
    void makeUnused(const Term *term) { usedTerms_.erase(term); }
};

} // namespace usage
} // namespace ir
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
