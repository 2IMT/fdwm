#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fdwm.h"
#include "util.h"

int main(int argc, char* argv[]) {
    if (argc == 2 && !strcmp("-v", argv[1]))
        die("fdwm-" VERSION);
    else if (argc != 1)
        die("usage: fdwm [-v]");
    if (!setlocale(LC_CTYPE, "") || !XSupportsLocale())
        fputs("warning: no locale support\n", stderr);
    Display* dpy = XOpenDisplay(NULL);
    if (!dpy)
        die("fdwm: cannot open display");
    setglobaldisplay(XOpenDisplay(NULL));
    checkotherwm();
    setup();
#ifdef __OpenBSD__
    if (pledge("stdio rpath proc exec", NULL) == -1)
        die("pledge");
#endif
    scan();
    run();
    cleanup();
    XCloseDisplay(dpy);
    return EXIT_SUCCESS;
}
