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

#include <memory>

#include <nc/common/Types.h>

namespace nc {

namespace core {

namespace ir {
    class Program;
    class Term;
}

namespace arch {

class Instruction;
class Operand;

namespace irgen {

/**
 * Class used for producing IR code from an instruction.
 */
class InstructionAnalyzer {
public:
    /**
     * \param[in] operand              Operand.
     * \return                         Intermediate representation of the given 
     *                                 operand as a term.
     */
    std::unique_ptr<ir::Term> createTerm(const Operand *operand) const;

    /**
     * Creates intermediate representation of an instruction and adds newly created statements to the control flow graph.
     *
     * \param[in] instruction           Valid pointer to the instruction to generate intermediate representation for.
     * \param[out] program              Valid pointer to the intermediate representation of a program.
     */
    void createStatements(const Instruction *instruction, ir::Program *program) const;

protected:
    /**
     * Actually creates intermediate representation of an instruction.
     *
     * \param[in] instruction           Valid pointer to the instruction to generate intermediate representation for.
     * \param[out] program              Valid pointer to the intermediate representation of a program.
     */
    virtual void doCreateStatements(const Instruction *instruction, ir::Program *program) const;

    /**
     * \param[in] operand               Operand.
     * \return                          Intermediate representation of the given operand.
     */
    virtual std::unique_ptr<ir::Term> doCreateTerm(const Operand *operand) const;
};

} // namespace irgen
} // namespace arch
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
