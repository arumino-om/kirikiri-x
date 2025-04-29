#include <gtest/gtest.h>
#include <native_instances/rect_instance.h>

#define PROPERTY_EXPECT(dispatch, propname, expected) \
    dispatch->PropGet(TJS_MEMBERMUSTEXIST, TJS_W(propname), nullptr, &funcResult, dispatch); \
    EXPECT_EQ(funcResult.AsInteger(), expected);

#define BUILD_SINGLE_PARAM(name, arg1) \
    auto **name = new tTJSVariant*[1]; \
    name[0] = new tTJSVariant(arg1); \

#define BUILD_DOUBLE_PARAMS(name, arg1, arg2) \
    auto **name = new tTJSVariant*[2]; \
    name[0] = new tTJSVariant(arg1); \
    name[1] = new tTJSVariant(arg2); \

#define BUILD_QUADRUPLE_PARAMS(name, arg1, arg2, arg3, arg4) \
    auto **name = new tTJSVariant*[4]; \
    name[0] = new tTJSVariant(arg1); \
    name[1] = new tTJSVariant(arg2); \
    name[2] = new tTJSVariant(arg3); \
    name[3] = new tTJSVariant(arg4);

TEST(CoreNativeInstances_RectTest, EqualProperties) {
    auto rect_nc = LibRuntime::NativeClasses::RectNativeClass();
    iTJSDispatch2 *rect;
    tTJSVariant funcResult;

    BUILD_QUADRUPLE_PARAMS(rectParam, 10, 12, 24, 58);
    rect_nc.CreateNew(TJS_MEMBERMUSTEXIST, nullptr, nullptr, &rect, 4, rectParam, nullptr);

    PROPERTY_EXPECT(rect, "left", 10);
    PROPERTY_EXPECT(rect, "top", 12);
    PROPERTY_EXPECT(rect, "right", 24);
    PROPERTY_EXPECT(rect, "bottom", 58);
    PROPERTY_EXPECT(rect, "width", 24 - 10); //right - left
    PROPERTY_EXPECT(rect, "height", 58 - 12); //bottom - top

    delete[] rectParam;

    rect->Release();
}

TEST(CoreNativeInstances_RectTest, addOffset) {
    auto rect_nc = LibRuntime::NativeClasses::RectNativeClass();
    iTJSDispatch2 *rect;

    BUILD_QUADRUPLE_PARAMS(rectParam, 10, 12, 24, 58);
    rect_nc.CreateNew(TJS_MEMBERMUSTEXIST, nullptr, nullptr, &rect, 4, rectParam, nullptr);

    BUILD_DOUBLE_PARAMS(offsetParam, 12, 25);
    rect->FuncCall(TJS_MEMBERMUSTEXIST, TJS_W("addOffset"), nullptr, nullptr, 2, offsetParam, rect);

    tTJSVariant funcResult;
    PROPERTY_EXPECT(rect, "left", 10 + offsetParam[0]->AsInteger());
    PROPERTY_EXPECT(rect, "top", 12 + offsetParam[1]->AsInteger());
    PROPERTY_EXPECT(rect, "right", 24 + offsetParam[0]->AsInteger());
    PROPERTY_EXPECT(rect, "bottom", 58 + offsetParam[1]->AsInteger());
    PROPERTY_EXPECT(rect, "width", (24 + offsetParam[0]->AsInteger()) - (10 + offsetParam[0]->AsInteger())); //right - left
    PROPERTY_EXPECT(rect, "height", (58 + offsetParam[1]->AsInteger()) - (12 + offsetParam[1]->AsInteger())); //bottom - top

    delete[] rectParam;
    delete[] offsetParam;

    rect->Release();
}

TEST(CoreNativeInstances_RectTest, clear)
{
    auto rect_nc = LibRuntime::NativeClasses::RectNativeClass();
    iTJSDispatch2 *rect;
    tTJSVariant funcResult;

    BUILD_QUADRUPLE_PARAMS(rectParam, 10, 12, 24, 58);
    rect_nc.CreateNew(TJS_MEMBERMUSTEXIST, nullptr, nullptr, &rect, 4, rectParam, nullptr);
    rect->FuncCall(TJS_MEMBERMUSTEXIST, TJS_W("clear"), nullptr, nullptr, 0, nullptr, rect);

    PROPERTY_EXPECT(rect, "left", 0);
    PROPERTY_EXPECT(rect, "top", 0);
    PROPERTY_EXPECT(rect, "right", 0);
    PROPERTY_EXPECT(rect, "bottom", 0);
    PROPERTY_EXPECT(rect, "width", 0); //right - left
    PROPERTY_EXPECT(rect, "height", 0); //bottom - top

    delete[] rectParam;

    rect->Release();
}

TEST(CoreNativeInstances_RectTest, clip)
{
    auto rect_nc = LibRuntime::NativeClasses::RectNativeClass();
    iTJSDispatch2 *rect1, *rect2;
    tTJSVariant funcResult;

    BUILD_QUADRUPLE_PARAMS(rectParam1, 14, 17, 50, 50);
    BUILD_QUADRUPLE_PARAMS(rectParam2, 12, 12, 20, 40);
    rect_nc.CreateNew(TJS_MEMBERMUSTEXIST, nullptr, nullptr, &rect1, 4, rectParam1, nullptr);
    rect_nc.CreateNew(TJS_MEMBERMUSTEXIST, nullptr, nullptr, &rect2, 4, rectParam2, nullptr);

    BUILD_SINGLE_PARAM(objectParam, rect2);
    rect1->FuncCall(TJS_MEMBERMUSTEXIST, TJS_W("clip"), nullptr, nullptr, 1, objectParam, rect1);

    PROPERTY_EXPECT(rect1, "left", 14);
    PROPERTY_EXPECT(rect1, "top", 17);
    PROPERTY_EXPECT(rect1, "right", 20);
    PROPERTY_EXPECT(rect1, "bottom", 40);
    PROPERTY_EXPECT(rect1, "width", 20 - 14); //right - left
    PROPERTY_EXPECT(rect1, "height", 40 - 17); //bottom - top

    delete[] rectParam1;
    delete[] rectParam2;
    delete[] objectParam;

    rect1->Release();
}

TEST(CoreNativeInstances_RectTest, equal)
{
    auto rect_nc = LibRuntime::NativeClasses::RectNativeClass();
    iTJSDispatch2 *rect1, *rect2;
    tTJSVariant funcResult, funcResult2;

    BUILD_QUADRUPLE_PARAMS(rectParam1, 14, 17, 50, 50);
    BUILD_QUADRUPLE_PARAMS(rectParam2, 12, 12, 20, 40);
    rect_nc.CreateNew(TJS_MEMBERMUSTEXIST, nullptr, nullptr, &rect1, 4, rectParam1, nullptr);
    rect_nc.CreateNew(TJS_MEMBERMUSTEXIST, nullptr, nullptr, &rect2, 4, rectParam2, nullptr);

    BUILD_SINGLE_PARAM(objectParam, rect2);
    rect1->FuncCall(TJS_MEMBERMUSTEXIST, TJS_W("equal"), nullptr, &funcResult, 1, objectParam, rect1);
    ASSERT_EQ(funcResult.AsInteger(), 0);   //ここでは一致していないはず

    rect2->FuncCall(TJS_MEMBERMUSTEXIST, TJS_W("set"), nullptr, nullptr, 4, rectParam1, rect2);
    rect1->FuncCall(TJS_MEMBERMUSTEXIST, TJS_W("equal"), nullptr, &funcResult, 1, objectParam, rect1);
    ASSERT_EQ(funcResult.AsInteger(), 1);   //ここでは一致しているはず

    delete[] rectParam1;
    delete[] rectParam2;

    rect1->Release();
}