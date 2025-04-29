#pragma once
#include <tjs.h>
#include <tjsNative.h>

#include "../native_classes/rect.h"
#include "../types/rect.h"

namespace LibRuntime {
    namespace Rendering {
        class LayerTree;
    }

    namespace NativeInstances {
        class RectNativeInstance : public tTJSNativeInstance {
            friend class NativeClasses::RectNativeClass;

        public:
            RectNativeInstance();
            tjs_error TJS_INTF_METHOD Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj) override;
            void TJS_INTF_METHOD Invalidate() override;

            void add_offset(tjs_int x, tjs_int y);
            void clear();
            bool clip(RectNativeInstance &rect);
            bool equal(const RectNativeInstance &rect) const;
            bool included(RectNativeInstance &rect);
            bool included_position(tjs_int x, tjs_int y);
            bool intersects(RectNativeInstance &rect);
            bool is_empty();
            void set(tjs_int left, tjs_int top, tjs_int right, tjs_int bottom);
            void set_offset(tjs_int x, tjs_int y);
            void set_size(tjs_int width, tjs_int height);
            bool union_rect(RectNativeInstance &rect);

            void get_size(int &width, int &height) const;
        protected:
            Types::Rect rect_;

            void calc_size();
        };
    }

}
