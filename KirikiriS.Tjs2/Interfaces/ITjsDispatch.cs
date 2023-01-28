using System;
using KirikiriS.Tjs2.Types;

namespace KirikiriS.Tjs2.Interfaces
{
    public interface ITjsDispatch : IDisposable
    {
        uint RefCount { get; set; }
        uint AddRef();
        uint Release();
        uint GetRefCount();

        (TjsResultCode, TjsVariant) FuncCall(uint flag, string memberName, ref uint hint, TjsVariant[] param, ITjsDispatch objThis);
        (TjsResultCode, TjsVariant) FuncCall(uint flag, int num, TjsVariant[] param, ITjsDispatch objThis);
        
        (TjsResultCode, TjsVariant) PropGet(uint flag, string memberName, ref uint hint, ITjsDispatch objThis);
        (TjsResultCode, TjsVariant) PropGet(uint flag, int num, ITjsDispatch objThis);
        
        TjsResultCode PropSet(uint flag, string memberName, ref uint hint, TjsVariant setValue, ITjsDispatch objThis);
        TjsResultCode PropSet(uint flag, int num, TjsVariant setValue, ITjsDispatch objThis);
        
        (TjsResultCode, int) GetCount(string memberName, ref uint hint, ITjsDispatch objThis);
        (TjsResultCode, int) GetCount(int num, ITjsDispatch objThis);

        TjsResultCode EnumMembers(uint flag, TjsVariantClosure callback, ITjsDispatch objThis);
        
        TjsResultCode DeleteMember(uint flag, string memberName, ref uint hint, ITjsDispatch objThis);
        TjsResultCode DeleteMember(uint flag, int num, ITjsDispatch objThis);
        
        TjsResultCode Invalidate(uint flag, string memberName, ref uint hint, ITjsDispatch objThis);
        TjsResultCode Invalidate(uint flag, int num, ITjsDispatch objThis);
        
        TjsResultCode IsValid(uint flag, string memberName, ref uint hint, ITjsDispatch objThis);
        TjsResultCode IsValid(uint flag, int num, ITjsDispatch objThis);

        (TjsResultCode, ITjsDispatch) CreateNew(uint flag, string memberName, uint hint, TjsVariant[] param,
            ITjsDispatch objThis);
        (TjsResultCode, ITjsDispatch) CreateNew(uint flag, int num, TjsVariant[] param, ITjsDispatch objThis);

        TjsResultCode IsInstanceOf(uint flag, string memberName, uint hint, string className, ITjsDispatch objThis);
        TjsResultCode IsInstanceOf(uint flag, int num, string className, ITjsDispatch objThis);

        (TjsResultCode, TjsVariant) Operation(uint flag, string memberName, uint hint, TjsVariant param, ITjsDispatch objThis);
        (TjsResultCode, TjsVariant) Operation(uint flag, int num, TjsVariant param, ITjsDispatch objThis);

        TjsResultCode NativeInstanceSupport(uint flag, int classId, ITjsNativeInstance instance);

        TjsResultCode ClassInstance(TjsCIIFlag flag, uint num, TjsVariant value);
        
        #region for private use
        TjsResultCode PropSet(uint flag, in string memberName, TjsVariant setValue, ITjsDispatch objThis);
        #endregion
    }
}