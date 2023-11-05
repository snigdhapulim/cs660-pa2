#include <db/IndexPredicate.h>

using namespace db;

IndexPredicate::IndexPredicate(Op op, const Field *fvalue) {
    // TODO pa2.2: implement
}

const Field *IndexPredicate::getField() const {
    // TODO pa2.2: implement
    //return {};
    return fvalue;
}

Op IndexPredicate::getOp() const {
    // TODO pa2.2: implement
    //return {};
    return op;
}

bool IndexPredicate::operator==(const IndexPredicate &other) const {
    // TODO pa2.2: implement
    //return {};
    //return op == other.op && fvalue->compare(Predicate::Op::EQUAL, *other.fvalue);
    // This assumes that Field class has a compare method which performs the comparison based on the operation provided.
    if (fvalue == nullptr || other.fvalue == nullptr) {
        throw std::invalid_argument("Cannot compare predicates with null field values.");
    }
    return op == other.op && fvalue->compare(Op::EQUALS, other.fvalue);
}

std::size_t std::hash<IndexPredicate>::operator()(const IndexPredicate &ipd) const {
    // TODO pa2.2: implement
    //return {};
    if (ipd.getField() == nullptr) {
        throw std::invalid_argument("Cannot hash IndexPredicate with null field value.");
    }
    std::hash<const Field *> hash_field;
    std::hash<int> hash_op;
    return hash_field(ipd.getField()) ^ (hash_op(static_cast<int>(ipd.getOp())) << 1);

}
