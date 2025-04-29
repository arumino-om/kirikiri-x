#include <tjsTypes.h>

namespace LibRuntime::Types
{
    union Rect
    {
        struct
        {
            tjs_int left;
            tjs_int top;
            tjs_int right;
            tjs_int bottom;
        };

        tjs_int values[4];
    };
}
