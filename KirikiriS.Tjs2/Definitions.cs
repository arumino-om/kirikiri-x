namespace KirikiriS.Tjs2
{
    public enum TjsResultCode
    {
        E_MEMBERNOTFOUND = -1001,
        E_NOTIMPL = -1002,
        E_INVALIDPARAM = -1003,
        E_BADPARAMCOUNT = -1004,
        E_INVALIDTYPE = -1005,
        E_INVALIDOBJECT = -1006,
        E_ACCESSDENIED = -1007,
        E_NATIVECLASSCRASH = -1008,
        
        S_OK = 0,
        E_FAIL = -1
    }

    public enum TjsCIIFlag
    {
        ADD,
        GET,
        SET_FINALIZE,
        SET_MISSING
    }
}