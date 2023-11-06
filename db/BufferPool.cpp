#include <db/BufferPool.h>
#include <db/Database.h>

using namespace db;

void BufferPool::evictPage() {
    // TODO pa2.1: implement
}

void BufferPool::flushAllPages() {
    // TODO pa2.1: implement
}

void BufferPool::discardPage(const PageId *pid) {
    // TODO pa2.1: implement
}

void BufferPool::flushPage(const PageId *pid) {
    // TODO pa2.1: implement
<<<<<<< HEAD

    auto it = pages.find(pid);
    if(it != pages.end()) {
        Page *page = it->second;
        if(page->isDirty()) {
            DbFile* file = Database::getCatalog().getDatabaseFile(pid->getTableId());

            file->writePage(page);
            page->markDirty(std::nullopt);
        }
    }
=======
>>>>>>> parent of 8cb0a1f (first)
}

void BufferPool::flushPages(const TransactionId &tid) {
    // TODO pa2.1: implement
}

void BufferPool::insertTuple(const TransactionId &tid, int tableId, Tuple *t) {
    // TODO pa2.3: implement
}

void BufferPool::deleteTuple(const TransactionId &tid, Tuple *t) {
    // TODO pa2.3: implement
}
