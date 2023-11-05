#include <db/Predicate.h>

using namespace db;

// TODO pa2.2: implement
Predicate::Predicate(int field, Op op, const Field *operand) {}

int Predicate::getField() const {
    // TODO pa2.2: implement
    //return {};
    return field;
}

Op Predicate::getOp() const {
    // TODO pa2.2: implement
    //return {};
    return op;
}

const Field *Predicate::getOperand() const {
    // TODO pa2.2: implement
    //return {};
    return operand;
}

bool Predicate::filter(const Tuple &t) const {
    // TODO pa2.2: implement
    //return {};
    const Field &tupleField = t.getField(field);
    if (operand == nullptr || &tupleField == nullptr) {
        throw std::invalid_argument("Cannot filter on null field values.");
    }
    return tupleField.compare(op, operand);
}
