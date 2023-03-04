using System;
using KirikiriS.Tjs2.Types;

namespace KirikiriS.Tjs2.Interfaces
{
    public interface IDispatch : IDisposable
    {
        (ResultCode, VariantStruct) FuncCall(uint flag, string memberName, VariantStruct[] param, IDispatch objThis);
        (ResultCode, VariantStruct) FuncCall(uint flag, int num, VariantStruct[] param, IDispatch objThis);
        
        (ResultCode, VariantStruct) PropGet(uint flag, string memberName, IDispatch objThis);
        (ResultCode, VariantStruct) PropGet(uint flag, int num, IDispatch objThis);
        
        ResultCode PropSet(uint flag, string memberName, VariantStruct setValue, IDispatch objThis);
        ResultCode PropSet(uint flag, int num, VariantStruct setValue, IDispatch objThis);
        
        (ResultCode, int) GetCount(string memberName, IDispatch objThis);
        (ResultCode, int) GetCount(int num, IDispatch objThis);

        ResultCode EnumMembers(uint flag, VariantClosureStruct callback, IDispatch objThis);
        
        ResultCode DeleteMember(uint flag, string memberName, IDispatch objThis);
        ResultCode DeleteMember(uint flag, int num, IDispatch objThis);
        
        ResultCode Invalidate(uint flag, string memberName, IDispatch objThis);
        ResultCode Invalidate(uint flag, int num, IDispatch objThis);
        
        ResultCode IsValid(uint flag, string memberName, IDispatch objThis);
        ResultCode IsValid(uint flag, int num, IDispatch objThis);

        (ResultCode, IDispatch) CreateNew(uint flag, string memberName, VariantStruct[] param,
            IDispatch objThis);
        (ResultCode, IDispatch) CreateNew(uint flag, int num, VariantStruct[] param, IDispatch objThis);

        ResultCode IsInstanceOf(uint flag, string memberName, string className, IDispatch objThis);
        ResultCode IsInstanceOf(uint flag, int num, string className, IDispatch objThis);

        (ResultCode, VariantStruct) Operation(uint flag, string memberName, VariantStruct param, IDispatch objThis);
        (ResultCode, VariantStruct) Operation(uint flag, int num, VariantStruct param, IDispatch objThis);

        ResultCode NativeInstanceSupport(uint flag, int classId, ITjsNativeInstance instance);

        ResultCode ClassInstance(TjsCIIFlag flag, uint num, VariantStruct value);
        
        #region for private use
        ResultCode PropSet(uint flag, in string memberName, VariantStruct setValue, IDispatch objThis);
        #endregion
    }
}