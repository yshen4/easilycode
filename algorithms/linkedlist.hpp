#include "node.hpp"

using yaal::ListNode;

namespace yaal {
    template <typename U>
    class LinkedListIter;

    template <typename T>
    struct LinkedList {
        LinkedList()
        : head(nullptr), tail(nullptr), size(0) {};

        virtual ~LinkedList() {
            ListNode<T> *pc = this->head;
            while(pc) {
                this->head = pc;
                pc = pc->next;
                delete this->head;
            }
            this->head = nullptr;
        }

        template <typename U>
        friend class LinkedListIter;

        size_t get_size() { return this->size; }
        bool empyt() { return this->size == 0; }

        int append(T v) {
            if (this->tail == nullptr) {
                this->head = this->tail = new ListNode<T>(v);
            }
            else {
                this->tail->next = new ListNode<T>(v);
                this->tail = this->tail->next;
            }
            return ++this->size;
        }

        int insert(T v) {
            if (this->head == nullptr) {
                this->head = this->tail = new ListNode<T>(v);
            }
            else {
                ListNode<T> *t = new ListNode<T>(v);
                t->next = this->head;
                this->head = t;
            }
            return ++this->size;
        }

        ListNode<T> *find(T v) {
            ListNode<T> *pc = this->head;
            while (pc) {
                if (pc->val == v) return pc;
                pc = pc->next;
            }
            return nullptr;
        }

        int erase(T v) {
            ListNode<T> *prev = nullptr, *pc = this->head;
            while(pc) {
                if (pc->val == v) break;
                prev = pc;
                pc = pc->next;
            }

            // didn't find v in the list
            if (!pc) return -1;

            // it is the head
            if (!prev) {
               pc = head;
               head = head->next;
               delete pc;
            }
            else {
               prev->next = pc->next;
               if (pc == this->tail) this->tail = prev;
               delete pc;
            }

            return --size;
        }

        void reverse() {
            ListNode<T> *prv = nullptr, *pc = this->head;
            this->tail = this->head;
            while (pc) {
                ListNode<T> *t = pc->next;
                pc->next = prv;
                prv = pc;
                pc = t;
            }
            this->head = prv;
        }

        friend std::ostream & operator<<(std::ostream &out, LinkedList<T> &me) {
            ListNode<T> *pc = me.head;
            while (pc) {
               out << pc->val;
               if (pc == me.tail)
                   out << std::endl;
               else
                   out << "->";
               pc = pc->next;
            }

            return out;
        }

        LinkedListIter<T> *createIter() const {
            return new LinkedListIter<T>(this);
        }

    private:
        ListNode<T> *head, *tail;
        size_t size;
    };

    template <typename U>
    class LinkedListIter {
    private:
        const LinkedList<U> *linkedList;
        ListNode<U> *cursor;
    public:
        LinkedListIter(const LinkedList<U> *ll): linkedList(ll), cursor(ll->head) {};

        U first() {
            cursor = linkedList->head;
            return this->currrent(); 
        }

        bool next() {
            if (!cursor || !cursor->next) 
                return false;
            else {
                cursor = cursor->next;
                return true;
            }
        }

        U current() {
            return cursor->val;
        }
    };
}
