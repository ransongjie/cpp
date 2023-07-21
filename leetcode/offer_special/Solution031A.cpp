#include <unordered_map>
#include <optional>

using namespace std;
/**
 * 对比Solution031.cpp优化
 * myCache.get(key) 返回 optional<V> 代替返回特殊值-1
 * 构造函数:初始化成员变量 代替new指针
 */
/**
 * 最近最少使用缓存
 */

class Solution031A {
};

/**
 * 结点
 */
// 类模板
template<class K, class V>
class Node0 {
public:
    K key;
    V value;
    Node0<K, V> *nxt;
    Node0<K, V> *pre;

    Node0(K k, V v) {
        key = k;
        value = v;
    }
};

/**
 * 双向链表
 */
template<class K, class V>
class NodeDoubleLinkedList {
public:
    Node0<K, V> *head;
    Node0<K, V> *tail;

    NodeDoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(Node0<K, V> *newNode) {
        if (newNode == nullptr) {
            return;
        }
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->nxt = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }

    void moveNodeToTail(Node0<K, V> *node) {
        if (tail == node) {
            return;
        }
        if (head == node) {
            head = head->nxt;
            head->pre = nullptr;
        } else {
            node->pre->nxt = node->nxt;
            node->nxt->pre = node->pre;
        }
        tail->nxt = node;
        node->pre = tail;
        node->nxt = nullptr;
        tail = node;
    }

    Node0<K, V> *removeHead() {
        if (head == nullptr) {
            return nullptr;
        }
        Node0<K, V> *h = head;
        if (head == tail) { //
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->nxt;
            head->pre = nullptr;
        }
        h->nxt = nullptr;
        return h;
    }
};

/**
 * 真正cache的实现
 *
 * @param <K>
 * @param <V>
 */
template<class K, class V>
class MyCache {
public:
    // 容量
    const int capacity;
    // hash
    unordered_map<K, Node0<K, V> *> keyNode;
    // 双向链表
    NodeDoubleLinkedList<K, V> nodeList;

    // explicit 声明构造函数或者转换函数是显式的，禁止隐式的类型转换
    // : capacity(capacity)初始化成员变量
    explicit MyCache(int capacity) : capacity(capacity) {
    }

    // 所操作的结点会放到尾部, optional c++17
    optional<V> get(K k) {
        if (keyNode.count(k) > 0) {
            Node0<K, V> *node = keyNode[k];
            nodeList.moveNodeToTail(node); //
            return node->value;
        }
        return nullopt;//不是nullptr
    }

    // 所操作的结点会放到尾部
    void put(K k, V v) {
        if (keyNode.count(k)) {
            Node0<K, V> *node = keyNode[k];
            node->value = v;
            nodeList.moveNodeToTail(node); //
        } else {
            Node0<K, V> *node = new Node0<K, V>(k, v);
            keyNode[k] = node;
            nodeList.addNode(node); //
            if (keyNode.size() == capacity + 1) { //
                removeMostUnused();
            }
        }
    }

    // 到达容量限制，移除最近未使用的结点，头部结点
    void removeMostUnused() {
        Node0<K, V> *h = nodeList.removeHead();
        keyNode.erase(h->key);
    }
};

class LRUCache {
    //访问控制，默认private
public:
    MyCache<int, int> myCache;

    /**
     * @param m 初始容量
     */
    LRUCache(int m) : myCache(m) {
    }

    int get(int key) {
        auto value = myCache.get(key);
        return value == nullopt ? -1 : *value;
    }

    void put(int key, int value) {
        myCache.put(key, value);
    }
};