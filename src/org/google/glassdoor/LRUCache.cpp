#include<list>
#include<unordered_map>
using namespace std;

class LRUCache {
    private: 
        int mxs;
        list<int> pages;
        unordered_map<int, list<int>::iterator> access;
    public:
        LRUCache(int n): mxs(n) {}
        void refer(int);
        void display();
};

void LRUCache::refer(int x) {
    auto it = access.find(x);
    if(it == access.end()) {
        if(pages.size() == mxs) { 
            access.erase(pages.back());               // map erase overloaded both for key & iterator
            pages.pop_back();
        }
    } else {
        pages.erase(access[x]);                       // list erase only for iterator
    }

    pages.push_front(x);
    access[x] = pages.begin();
}

void LRUCache::display() {
    printf("Pages (sorted from most recently used): ");
    for_each(pages.begin(), pages.end(), [](int x) {
        printf("%d ", x);
    }); printf("\n");
}

int main() {
    LRUCache lru(4);

    lru.refer(1); 
    lru.refer(2); 
    lru.refer(3); 
    lru.refer(1); 
    lru.refer(4); 
    lru.refer(5); 
    lru.display();

    return 0;
}