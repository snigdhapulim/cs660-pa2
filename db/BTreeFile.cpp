#include <db/BTreeFile.h>
#include "db/Database.h"

using namespace db;

BTreeLeafPage *findLeafPage(TransactionId tid, PagesMap &dirtypages,
                            BTreePageId *pid, Permissions perm, const Field *f) {
    BTreePage *currentPage = nullptr;
    BTreeLeafPage *leafPage = nullptr;

    // Start at the root of the B+ tree and traverse the tree
    while (true) {
        currentPage = static_cast<BTreePage *>(Database::getBufferPool().getPage( pid));

        // Check if the current page is a leaf page
        if (currentPage->getType() == BTreePageType::LEAF) {
            leafPage = static_cast<BTreeLeafPage *>(currentPage);
            break; // We've reached a leaf page, so break out of the loop
        }

        // Find the appropriate child page using the IndexPredicate
        const IndexPredicate indexPredicate(IndexPredicate::Op::EQUAL, f);
        BTreePageId *childPid = currentPage->getChildId(indexPredicate);

        // Update the current page ID for the next iteration
        pid = childPid;
    }

    // Add the dirty pages to the list of dirty pages
    dirtypages[*pid] = leafPage;

    return leafPage;
}





BTreeLeafPage *BTreeFile::splitLeafPage(TransactionId tid, PagesMap &dirtypages, BTreeLeafPage *page, const Field *field) {
    // TODO pa2.3: implement
    return nullptr;
}

BTreeInternalPage *BTreeFile::splitInternalPage(TransactionId tid, PagesMap &dirtypages, BTreeInternalPage *page,
                                                Field *field) {
    // TODO pa2.3: implement
    return nullptr;
}

void BTreeFile::stealFromLeafPage(BTreeLeafPage *page, BTreeLeafPage *sibling, BTreeInternalPage *parent,
                                  BTreeEntry *entry, bool isRightSibling) {
    // TODO pa2.4: implement (BONUS)
}

void BTreeFile::stealFromLeftInternalPage(TransactionId tid, PagesMap &dirtypages, BTreeInternalPage *page,
                                          BTreeInternalPage *leftSibling, BTreeInternalPage *parent,
                                          BTreeEntry *parentEntry) {
    // TODO pa2.4: implement (BONUS)
}

void BTreeFile::stealFromRightInternalPage(TransactionId tid, PagesMap &dirtypages, BTreeInternalPage *page,
                                           BTreeInternalPage *rightSibling, BTreeInternalPage *parent,
                                           BTreeEntry *parentEntry) {
    // TODO pa2.4: implement (BONUS)
}

void BTreeFile::mergeLeafPages(TransactionId tid, PagesMap &dirtypages, BTreeLeafPage *leftPage,
                               BTreeLeafPage *rightPage, BTreeInternalPage *parent, BTreeEntry *parentEntry) {
    // TODO pa2.4: implement (BONUS)
}

void BTreeFile::mergeInternalPages(TransactionId tid, PagesMap &dirtypages, BTreeInternalPage *leftPage,
                                   BTreeInternalPage *rightPage, BTreeInternalPage *parent, BTreeEntry *parentEntry) {
    // TODO pa2.4: implement (BONUS)
}
