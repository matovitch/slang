#include "slang/ast.h"
#include "slang/print.h"

namespace slang {

// Defined in parser.cpp
int precedence(ast::BinOpExpr::Type type);

namespace ast {

void Module::print(Printer& printer) const {
    for (auto d : decls_) {
        d->print(printer);
        printer << "\n";
    }
}

void StorageQualifier::print(Printer& printer) const {
    switch (storage_) {
#define SLANG_KEY_QUAL_STORAGE(key, str) case STORAGE_##key: printer << str; break;
#include "slang/keywordlist.h"
        default: assert(0 && "Unknown storage qualifier");
    }
}

void PrecisionQualifier::print(Printer& printer) const {
    switch (prec_) {
#define SLANG_KEY_QUAL_PREC(key, str) case PREC_##key: printer << str; break;
#include "slang/keywordlist.h"
        default: assert(0 && "Unknown precision qualifier");
    }
}

void InterpQualifier::print(Printer& printer) const {
    switch (interp_) {
#define SLANG_KEY_QUAL_INTERP(key, str) case INTERP_##key: printer << str; break;
#include "slang/keywordlist.h"
        default: assert(0 && "Unknown interpolation qualifier");
    }
}

void SubroutineQualifier::print(Printer& printer) const {
    printer << "subroutine(";
    for (size_t i = 0; i < names_.size(); i++) {
        printer << names_[i];

        if (i != names_.size() - 1)
            printer << ", ";
    }
    printer << ")";
}

void LayoutQualifier::print(Printer& printer) const {
    printer << "layout(";
    for (auto it = layouts_.begin(); it != layouts_.end();) {
        printer << it->first;

        if (it->second) {
            printer << " = ";
            it->second->print(printer);
        }

        it++;
        if (it != layouts_.end())
            printer << ", ";
    }
    printer << ")";
}

void InvariantQualifier::print(Printer& printer) const {
    printer << "invariant";
}

void AttributeQualifier::print(Printer& printer) const {
    printer << "attribute";
}

void VaryingQualifier::print(Printer& printer) const {
    printer << "varying";
}

void ArraySpecifier::print(Printer& printer) const {
    for (auto d : dims_) {
        printer << "[";
        if (d) d->print(printer);
        printer << "]";
    }
}

void ErrorType::print(Printer& printer) const {
    printer << "<error>";
}

void PrimType::print(Printer& printer) const {
    for (auto q : quals_) {
        q->print(printer);
        printer << " ";
    }

    switch (prim_) {
#define SLANG_KEY_DATA(key, str, type, rows, cols) case PRIM_##key: printer << str; break;
#include "slang/keywordlist.h"
        default: assert(0 && "Unknown primitive type");
    }

    if (array_spec_)
        array_spec_->print(printer);
}

void NamedType::print(Printer& printer) const {
    for (auto q : quals_) {
        q->print(printer);
        printer << " ";
    }

    printer << name_;

    if (array_spec_)
        array_spec_->print(printer);
}

void StructType::print(Printer& printer) const {
    for (auto q : quals_) {
        q->print(printer);
        printer << " ";
    }

    printer << "struct " << name_ << " {";
    printer.indent();
    for (size_t i = 0; i < fields_.size(); i++) {
        printer.new_line();
        fields_[i]->print(printer);
    }
    printer.unindent();
    printer.new_line();
    printer << "}";

    if (array_spec_)
        array_spec_->print(printer);
}

void InterfaceType::print(Printer& printer) const {
    for (auto q : quals_) {
        q->print(printer);
        printer << " ";
    }

    printer << name_ << " {";
    printer.indent();
    for (size_t i = 0; i < fields_.size(); i++) {
        printer.new_line();
        fields_[i]->print(printer);
    }
    printer.unindent();
    printer.new_line();
    printer << "}";

    if (array_spec_)
        array_spec_->print(printer);
}

void PrecisionDecl::print(Printer& printer) const {
    printer << "precision ";

    if (prec_)
        prec_->print(printer);
    else
        printer << "<error>";
    printer << " ";

    type_->print(printer);
    printer << ";";
}

void VariableDecl::print(Printer& printer) const {
    type_->print(printer);

    if (vars_.size() > 0)
        printer << " ";

    for (size_t i = 0; i < vars_.size(); i++) {
        vars_[i]->print(printer);
        if (i < vars_.size() - 1)
            printer << ", ";
    }
    printer << ";";
}

void FunctionDecl::print(Printer& printer) const {
    type_->print(printer);
    printer << " " << name_;

    printer << "(";
    for (size_t i = 0; i < args_.size(); i++) {
        args_[i]->print(printer);
        if (i < args_.size() - 1)
            printer << ", ";
    }
    printer << ")";
    
    if (body_) {
        printer << " ";
        body_->print(printer);
    } else {
        printer << ";";
    }
}

void Variable::print(Printer& printer) const {
    printer << name_;

    if (array_spec_)
        array_spec_->print(printer);

    if (init_) {
        printer << " = ";
        init_->print(printer);
    }
}

void Arg::print(Printer& printer) const {
    type_->print(printer);
    if (!name_.empty()) {
        printer << " ";
        printer << name_;

        if (array_spec_)
            array_spec_->print(printer);
    }
}

void ExprList::print(Printer& printer) const {
    for (size_t i = 0; i < exprs_.size(); i++) {
        exprs_[i]->print(printer);
        if (i < exprs_.size() - 1)
            printer << ", ";
    }
}

void ErrorExpr::print(Printer& printer) const {
    printer << "<error>";
}

void FieldExpr::print(Printer& printer) const {
    left_->print(printer);
    printer << "." << field_name_;
}

void IndexExpr::print(Printer& printer) const {
    left_->print(printer);
    printer << "[";
    index_->print(printer);
    printer << "]";
}

void CallExpr::print(Printer& printer) const {
    if (is_constructor())
        type_->print(printer);
    else
        expr_->print(printer);

    printer << "(";
    for (size_t i = 0; i < args_.size(); i++) {
        args_[i]->print(printer);
        if (i < args_.size() - 1)
            printer << ", ";
    }
    printer << ")";
}

void LiteralExpr::print(Printer& printer) const {
    printer << lit_;
}

void IdentExpr::print(Printer& printer) const {
    printer << ident_;
}

std::string UnOpExpr::op_string() const {
    switch (type_) {
        case UNOP_INC:     return "++";
        case UNOP_DEC:     return "--";
        case UNOP_NOT:     return "!";
        case UNOP_BIT_NOT: return "~";
        case UNOP_PLUS:    return "+";
        case UNOP_MINUS:   return "-";
        default:
            assert(0 && "Unknown unary operation");
            return "";
    }
}

void UnOpExpr::print(Printer& printer) const {
     if (type_ == UNOP_POST_INC) {
        op_->print(printer);
        printer << "++";
    } else if (type_ == UNOP_POST_DEC) {
        op_->print(printer);
        printer << "--";
    } else {
        printer << op_string() << " ";
        op_->print(printer);
    }
}

void CondExpr::print(Printer& printer) const {
    cond_->print(printer);
    printer << " ? ";
    if_true_->print(printer);
    printer << " : ";
    if_false_->print(printer);
}

std::string AssignOpExpr::op_string() const {
    switch (type_) {
        case ASSIGN_EQUAL:  return "=";
        case ASSIGN_ADD:    return "+=";
        case ASSIGN_SUB:    return "-=";
        case ASSIGN_MUL:    return "*=";
        case ASSIGN_DIV:    return "/=";
        case ASSIGN_MOD:    return "%=";
        case ASSIGN_LSHIFT: return "<<=";
        case ASSIGN_RSHIFT: return ">>=";
        case ASSIGN_AND:    return "&=";
        case ASSIGN_XOR:    return "^=";
        case ASSIGN_OR:     return "|=";
        default:
            assert(0 && "Unknown assign operation");
            return "";
    }
}

void AssignOpExpr::print(Printer& printer) const {
    left_->print(printer);
    printer << " " << op_string() << " ";
    right_->print(printer);
}

inline void print_expr(const Expr* expr, Printer& printer, int prec) {
    if (auto bin_expr = expr->isa<BinOpExpr>()) {
        if (printer.force_pars() || precedence(bin_expr->type()) > prec) {
            printer << "(";
            expr->print(printer);
            printer << ")";
            return;
        }
    }

    expr->print(printer);
}

std::string BinOpExpr::op_string() const {
    switch (type_) {
        case BINOP_MUL:    return "*";
        case BINOP_DIV:    return "/";
        case BINOP_MOD:    return "%";
        case BINOP_ADD:    return "+";
        case BINOP_SUB:    return "-";
        case BINOP_LSHIFT: return "<<";
        case BINOP_RSHIFT: return ">>";
        case BINOP_LT:     return "<";
        case BINOP_GT:     return ">";
        case BINOP_LEQ:    return "<=";
        case BINOP_GEQ:    return ">=";
        case BINOP_EQ:     return "==";
        case BINOP_NEQ:    return "!=";
        case BINOP_AND:    return "&";
        case BINOP_XOR:    return "^";
        case BINOP_OR:     return "|";
        case BINOP_ANDAND: return "&&";
        case BINOP_XORXOR: return "^^";
        case BINOP_OROR:   return "||";
        default:
            assert(0 && "Unknown binary operation");
            return "";
    }
}

void BinOpExpr::print(Printer& printer) const {
    int prec = precedence(type_);
    print_expr(left_.get(), printer, prec);
    printer << " " << op_string() << " ";
    print_expr(right_.get(), printer, prec);
}

void InitExpr::print(Printer& printer) const {
    printer << "{";
    for (size_t i = 0; i < exprs_.size(); i++) {
        exprs_[i]->print(printer);
        if (i < exprs_.size() - 1)
            printer << ", ";
    }
    printer << "}";
}

void LoopCond::print(Printer& printer) const {
    if (is_var()) {
        assert(static_cast<bool>(var_type_) && "Invalid loop condition");
        var_type_->print(printer);
        printer << " ";
        var_->print(printer);
    } else {
        assert(is_expr() && "Invalid loop condition");
        expr_->print(printer);
    }
}

void StmtList::print(Printer& printer) const {
    printer << "{";
    printer.indent();
    for (auto s : stmts_) {
        printer.new_line();
        s->print(printer);
    }
    printer.unindent();
    printer.new_line();
    printer << "}";
}

void DeclStmt::print(Printer& printer) const {
    decl_->print(printer);
}

void ExprStmt::print(Printer& printer) const {
    if (expr_)
        expr_->print(printer);
    printer << ";";
}

void IfStmt::print(Printer& printer) const {
    printer << "if (";
    cond_->print(printer);
    printer << ") ";
    if_true_->print(printer);

    if (if_false_) {
        printer << " else ";
        if_false_->print(printer);
    }
}

void SwitchStmt::print(Printer& printer) const {
    printer << "switch (";
    expr_->print(printer);
    printer << ") ";
    list_->print(printer);
}

void CaseLabelStmt::print(Printer& printer) const {
    if (is_default()) {
        printer << "default:";
    } else {
        printer << "case ";
        expr_->print(printer);
        printer << " :";
    }
}

void ForLoopStmt::print(Printer& printer) const {
    printer << "for (";

    if (init_)
        init_->print(printer);
    else
        printer << ";";

    printer << " ";

    if (cond_) cond_->print(printer);
    printer << "; ";

    if (iter_) iter_->print(printer);
    printer << ") ";

    body_->print(printer);
}

void WhileLoopStmt::print(Printer& printer) const {
    printer << "while (";
    cond_->print(printer);
    printer << ") ";
    body_->print(printer);
}

void DoWhileLoopStmt::print(Printer& printer) const {
    printer << "do ";
    body_->print(printer);
    printer << " while (";
    cond_->print(printer);
    printer << ");";
}

void BreakStmt::print(Printer& printer) const {
    printer << "break;";
}

void ContinueStmt::print(Printer& printer) const {
    printer << "continue;";
}

void DiscardStmt::print(Printer& printer) const {
    printer << "discard;";
}

void ReturnStmt::print(Printer& printer) const {
    printer << "return";
    if (has_value()) {
        printer << " ";
        value_->print(printer);
    }
    printer << ";";
}

} // namespace ast

} // namespace slang
