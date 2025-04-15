#ifndef FDWM_TYPES
#define FDWM_TYPES

#include <X11/Xlib.h>

/* enums */
enum { CurNormal, CurResize, CurMove, CurLast }; /* cursor */

enum { SchemeNorm, SchemeSel }; /* color schemes */

enum {
    NetSupported,
    NetWMName,
    NetWMState,
    NetWMCheck,
    NetSystemTray,
    NetSystemTrayOP,
    NetSystemTrayOrientation,
    NetSystemTrayOrientationHorz,
    NetWMFullscreen,
    NetActiveWindow,
    NetWMWindowType,
    NetWMWindowTypeDialog,
    NetClientList,
    NetLast,
}; /* EWMH atoms */

enum { Manager, Xembed, XembedInfo, XLast }; /* Xembed atoms */

enum {
    WMProtocols,
    WMDelete,
    WMState,
    WMTakeFocus,
    WMLast
}; /* default atoms */

enum {
    ClkTagBar,
    ClkLtSymbol,
    ClkStatusText,
    ClkWinTitle,
    ClkClientWin,
    ClkRootWin,
    ClkLast
}; /* clicks */

typedef union {
    int i;
    unsigned int ui;
    float f;
    const void* v;
} Arg;

typedef struct {
    unsigned int click;
    unsigned int mask;
    unsigned int button;
    void (*func)(const Arg* arg);
    const Arg arg;
} Button;

typedef struct Monitor Monitor;
typedef struct Client Client;

struct Client {
    char name[256];
    float mina, maxa;
    int x, y, w, h;
    int oldx, oldy, oldw, oldh;
    int basew, baseh, incw, inch, maxw, maxh, minw, minh, hintsvalid;
    int bw, oldbw;
    unsigned int tags;
    int isfixed, isfloating, isurgent, neverfocus, oldstate, isfullscreen;
    Client* next;
    Client* snext;
    Monitor* mon;
    Window win;
};

typedef struct {
    unsigned int mod;
    KeySym keysym;
    void (*func)(const Arg*);
    const Arg arg;
} Key;

typedef struct {
    void (*func)(const Arg*);
    const Arg arg;
} StartAction;

typedef struct {
    const char* symbol;
    void (*arrange)(Monitor*);
} Layout;

struct Monitor {
    char ltsymbol[16];
    float mfact;
    int nmaster;
    int num;
    int by; /* bar geometry */
    int mx, my, mw, mh; /* screen size */
    int wx, wy, ww, wh; /* window area  */
    unsigned int seltags;
    unsigned int sellt;
    unsigned int tagset[2];
    int showbar;
    int topbar;
    Client* clients;
    Client* sel;
    Client* stack;
    Monitor* next;
    Window barwin;
    const Layout* lt[2];
};

typedef struct {
    const char* class;
    const char* instance;
    const char* title;
    unsigned int tags;
    int isfloating;
    int monitor;
} Rule;

typedef struct Systray Systray;

struct Systray {
    Window win;
    Client* icons;
};

#endif
