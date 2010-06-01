#include <iostream>
#include <string.h>
#include <pcre.h>

void ask(const char *pattern, const char *match)
{
    const char *error;
    int errorOffset;
    int ovector[30];

    pcre *code = pcre_compile(pattern, PCRE_ANCHORED, &error, &errorOffset, 0);
    std::cout << match << "\t\t\t\t" << pattern << "\t\t\t\t" <<
        (pcre_exec(code, 0, match, strlen(match), 0, 0, ovector, 30) < 0 ? "false" : "true") << std::endl;
    pcre_free(code);
}

int main(int argc, char **argv)
{
    ask("[0-9]+", "aaa");
    ask("[0-9]+", "1234");
    ask("^[a-zA-Z]$", "Hello");
    ask("^[a-zA-Z]+$", "Hello");
    ask("[a-zA-Z]", "1234");

    return 0;
}
