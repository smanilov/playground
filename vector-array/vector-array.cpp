/**
 * Written to be compatible with c++98
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <cstdio>

using std::vector;
using std::cout;


// Silly functions:

/** Investigates the memory model of vector. Debugging mechanism. */
void vector_fun(vector<char>& v);

/** Ugly-print a vector. */
void print_vector(const vector<char>& buffer);

/** Check if a vector was successfully corrupted. */
void check(const vector<char>& buffer, char* array);


// Smart functions:

/** Get the address where the vector stores the pointer to the start of its
 *  data. */
char** get_vector_start_ptr_ptr(vector<char>& v) {
        // =====================================================================
        // Comment for all three meta-functions:                               
        // =====================================================================
        // The size of vector is architecture dependent:
        // for 32-bit arch sizeof(v) = 12
        // for 64-bit arch sizeof(v) = 24
        // This is so, because all v contains (as data) are three ptrs:
        //  - a ptr to the start of the data
        //  - a ptr to the end of the data
        //  - a ptr to the end of the allocated mem
        //
        // char** is a pointer to char*, thus sizeof<char**> would be the size
        // of any pointer (e.g. void**) so 4, or 8 resp
        //
        // Thus we cast the address of the vector to char**
        // =====================================================================

        return reinterpret_cast<char**>(&v);
}

/** Get the address where the vector stores the pointer to the end of its
 *  data. */
char** get_vector_finish_ptr_ptr(vector<char>& v) {
        return reinterpret_cast<char**>(&v) + 1;
}

/** Get the address where the vector stores the pointer to the end of the
 *  memory that it has allocated for its data (maybe more than size of data). */
char** get_vector_storage_end_ptr_ptr(vector<char>& v) {
        return reinterpret_cast<char**>(&v) + 2;
}

/** Corrupt the vector to use external data. Clean its memory to avoid leaks. */
void set_vector_data(vector<char>& v, char* ptr, int size) {
        // Get vector details
        int v_size = v.size();
        int v_cap  = v.capacity();

        char** ps = get_vector_start_ptr_ptr(v);
        char** pf = get_vector_finish_ptr_ptr(v);
        char** pe = get_vector_storage_end_ptr_ptr(v);

        // Debug properties
        assert(NULL != ps);
        assert(NULL != pf);
        assert(NULL != pe);

        assert(*pf - *ps == v_size);
        assert(*pe - *ps == v_cap);

        // Cleanup old memory to avoid leaks
        delete [] *ps;

        // Set new data
        *ps = ptr;
        *pf = ptr + size;
        *pe = *pf;
}

/** If the corrupt data was allocated on the stack it can not be delete'd.
 *  Steal the data from the vector so it doesn't attempt to clean it when it
 *  goes out of scope. */
void unset_vector_data(vector<char>& v) {
        // Get vector details
        char** ps = get_vector_start_ptr_ptr(v);
        char** pf = get_vector_finish_ptr_ptr(v);
        char** pe = get_vector_storage_end_ptr_ptr(v);

        // Unset data
        *ps = NULL;
        *pf = NULL;
        *pe = NULL;
}


// Examples:

void heap_example() {
        cout << "\nHeap example!\n";
        vector<char> buffer;
        buffer.push_back('A');
        buffer.push_back('B');
        buffer.push_back('C');
        buffer.push_back('D');

        // Heap memory:
        char* array = new char[10];
        const char* copy_me = "0123456789";
        int size = 10;
        for (int i = 0; i < size; ++i) {
                array[i] = copy_me[i];
        }

        print_vector(buffer);

        // Uncomment for some vector fun:
        // vector_fun(buffer);
        set_vector_data(buffer, array, size);

        check(buffer, array);

        print_vector(buffer);
        // if the vector loses the data it will leak so don't unset
        // unset_vector_data(buffer);
        // alternatively, unset the data, but delete it explicitly
}


void stack_example() {
        cout << "\nStack example!\n";
        vector<char> buffer;
        buffer.push_back('A');
        buffer.push_back('B');
        buffer.push_back('C');
        buffer.push_back('D');

        // Stack memory:
        char* array = "0123456789";
        int size = 10;

        print_vector(buffer);

        // Uncomment for some vector fun:
        // vector_fun(buffer);
        set_vector_data(buffer, array, size);

        check(buffer, array);

        print_vector(buffer);
        // unset vector data to avoid destructor trying to free stack memory
        unset_vector_data(buffer);
}


// Main:

int main() {
        heap_example();
        stack_example();
}


// Junk:

void vector_fun(vector<char>& v) {
        // The size of vector is 
        cout << "sizeof(v)=" << sizeof(v) << '\n';
        int n = sizeof(v) / sizeof(char**);
        char** start = reinterpret_cast<char**>(&v);
        char** end = start + n;
        printf("Dumping vector at %p[%d]\n", start, n);

        // see comment of get_vector_start... 
        for (char** it = start; it < end; it ++) {
                printf("%p -> %p\n", it, *it);
        }
}

void check(const vector<char>& buffer, char* array) {
        if (array == buffer.data()) {
                cout << "success!\n";
        } else {
                cout << "fail\n";
        }
}

void print_vector(const vector<char>& buffer) {
        cout << "printing buffer: ";
        for (int i = 0; i < buffer.size(); ++i) {
                cout << buffer[i] << ", ";
        }
        cout << '\n';
}
