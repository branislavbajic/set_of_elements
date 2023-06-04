//by Branislav Bajic
#ifndef _SET_H_
#define _SET_H_

class Set {

    public:
        Set();
        ~Set();

        bool addElement(int);
        bool removeElement(int);

        int getID() const;
        int getNumberOfElements() const;
        void printElements() const;

        static Set* _union(Set*, Set*);
        static Set* _intersection(Set*, Set*);
        static Set* _difference(Set*, Set*);

    protected:

    private:
        struct Elem {
            Elem(int val) {
                value = val;
                next = nullptr;
            }

            int value;
            Elem* next;

        };

        static int ID;
        int id = ++ID;

        Elem* head;
        Elem* tail;
        int elem_count;

};

#endif // _SET_H_
