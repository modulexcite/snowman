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

#include <cassert>

#include "Statement.h"

namespace nc {
namespace core {
namespace likec {

class LabelDeclaration;

/**
 * Label in place of a statement.
 */
class LabelStatement: public Statement {
    LabelDeclaration *label_; ///< Label.

    public:

    /**
     * Class constructor.
     *
     * \param[in] tree Owning tree.
     * \param[in] label Label.
     */
    LabelStatement(Tree &tree, LabelDeclaration *label):
        Statement(tree, LABEL_STATEMENT), label_(label)
    {
        assert(label);
    }

    /**
     * \return Label.
     */
    LabelDeclaration *label() const { return label_; }

    LabelStatement *rewrite() override;

    protected:

    virtual void doPrint(PrintContext &callback) const override;
};

} // namespace likec
} // namespace core
} // namespace nc

NC_REGISTER_CLASS_KIND(nc::core::likec::Statement, nc::core::likec::LabelStatement, nc::core::likec::Statement::LABEL_STATEMENT)

/* vim:set et sts=4 sw=4: */
