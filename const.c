#include <stdlib.h> #include <stdio.h>

#include <string.h>

/* Functions f and k demonstrate pointers to constant data. */
/* A pointer to a constant character! Not a constant pointer. */
void f(const char *input) {
        /* input[0] = 'G'; This does not compile as input points to
           constant characters. */
        printf("%s\n", input);

        /* assignment of the pointer works */
        input = "goodbye 1"; printf("%s\n", input);

        /* also, the assigned value doesn't have to point to const
           chars */
        char buf[16] = "goodbye 1.1"; input = buf;
        /* input[0] = 'G'; This still doesn't work, since even
           though input now points to the stack, it is still of
           type const char *, so it cannot be used to modify the
           memory it points to. */

        /* To modify the memory input points to it needs to be cast
           to char *, but that defeats the purpose of using (const
           char *) in the first place. */
        ((char *)(input))[0] = 'G'; printf("%s\n", input); }
/* This is the same as f. The difference is the type declaration of
 * the parameter, however const char is the same as char const. */
void k(char const *input) {
        /* input[0] = 'H'; invalid. see f */
        printf("%s\n", input);

        input = "goodbye 1"; printf("%s\n", input);

        char buf[16] = "goodbye 1.1"; input = buf;
        /* input[0] = 'G'; invalid. see f */
        ((char *)(input))[0] = 'G'; printf("%s\n", input); }

/* Function g demonstrates using different segments of memory. */
/* Not constant at all. No problem assigning values (if they are in
 * writable memory!! If a static string is passed there will be a
 * seg fault). */
void g(char *input) { input[0] = 'H'; printf("%s\n", input);

        /* This is potentially dangerous: we cast a const char * to
           char *.  The type of "goodbye 2" here is const
           char *, because the memory for it is allocated on the
           .bss segment.  Also, saying input = "goodbye 2"; is
           different than char input[16] = "goodbye 2"; because the
           former is assignment (of the pointer) and the second is
           initialization of the contents.  BEWARE! */
        input = "goodbye 2";
        /* input[0] = 'H'; This would produce a seg fault, as input
           points to memory in the .bss segment. */
        printf("%s\n", input);

        char buf[16] = "goodbye 2.1"; input = buf;
        /* This is OK, as the memory buf points to (and thus input,
           too) is on the stack, which is writeable. */
        input[0] = 'G'; printf("%s\n", input);

        input = (char *) malloc (sizeof(char) * 16); strcpy(input,
"goodbye 2.2");
        /* The heap is also writeable. Same as globals (not shown
           here). */
        input[0] = 'G'; printf("%s\n", input); free(input); }

/* Functions h and l demonstrate that constant pointers don't mean
 * constant data. */
/* The pointer is static, but the chars it points to are not. They
 * can be modified (as long as they are in writable memory). */
void h(char *const input) {
        /* This is OK, as the data is not const, just the pointer.*/
        input[0] = 'H'; printf("%s\n", input);
        /* input = "goodbye 3"; invalid - the pointer is constant */
}

/* Oops, the definition of l is invalid, despite my initial hopes.
 * It turns out that the type cannot contain parenthesis in itself.
 * This is the original comment before I tested it:
 *
 * The same as h. const * is the same as * const. However, if we
 * omit the brackets, we would have "char const *" which is
 * parenthesised as "(char const) *", and not "char (const *)". */
/*void l(char (const *) input) {
        input[0] = 'H'; printf("%s\n", input); }*/

/* A constant pointer to a constant character. Neither the pointer
 * nor its contents are modifiable. The placement of the const
 * keywords is a tribute to Dietmar Kuhl:
 * http://kuhllib.com/2012/01/17/continental-const-placement/ An
 * alternative would be "const char *const input". */
void m(char const *const input) { printf("%s\n", input); }

/* And how can we use those functions? */
int main() { f("hello 1"); k("hello 1");

        /* g("hello 2"); this will crash, as g writes to the given
           string; "hello 2" is on the .bss segment */

        /* This actually initlizes the string; it doesn't copy the
           pointer. */
        char hello2[16] = "hello 2"; g(hello2);
        
        /* h("hello 3"); this will crash, as h writes to the given
           string; "hello 3" is on the .bss segment */

        /* initlizes the string; doesn't copy the pointer */
        char hello3[16] = "hello 3"; h(hello3);
        /* l(hello3); the definition of l is invalid */

        m("hello 4");

        return 0; }
/* Voila! */
