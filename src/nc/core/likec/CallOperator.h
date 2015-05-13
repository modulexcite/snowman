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

#include <vector>
#include <memory> /* unique_ptr */

#include "Expression.h"
#include "VariableDeclaration.h"

namespace nc {
namespace core {
namespace likec {

/**
 * Function call.
 */
class CallOperator: public Expression {
    std::unique_ptr<Expression> callee_; ///< Callee.
    std::vector<std::unique_ptr<Expression> > arguments_; ///< Function arguments.

    public:

    /**
     * Class constructor.
     *
     * \param[in] tree Owning tree.
     * \param[in] callee Callee.
     */
    CallOperator(Tree &tree, std::unique_ptr<Expression> callee):
        Expression(tree, CALL_OPERATOR), callee_(std::move(callee)) {}

    /**
     * \return Callee.
     */
    Expression *callee() { return callee_.get(); }

    /**
     * \return Callee.
     */
    const Expression *callee() const { return callee_.get(); }

    /**
     * Function arguments.
     */
    const std::vector<std::unique_ptr<Expression> > &arguments() const { return arguments_; }

    /**
     * Adds argument to the function call and takes ownership of argument's expression.
     *
     * \param argument Valid pointer to an expression.
     */
    void addArgument(std::unique_ptr<Expression> argument) {
        assert(argument != NULL);
        arguments_.push_back(std::move(argument));
    }

    virtual const Type *getType() const override;
    virtual void visitChildNodes(Visitor<TreeNode> &visitor) override;
    virtual CallOperator *rewrite() override;
    virtual int precedence() const override { return 2; }

    protected:

    virtual void doPrint(PrintContext &context) const override;
};

} // namespace likec
} // namespace core
} // namespace nc

NC_REGISTER_CLASS_KIND(nc::core::likec::Expression, nc::core::likec::CallOperator, nc::core::likec::Expression::CALL_OPERATOR)

/* vim:set et sts=4 sw=4: */
