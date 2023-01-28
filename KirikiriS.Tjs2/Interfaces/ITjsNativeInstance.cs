using System;
using System.IO;
using KirikiriS.Tjs2.Types;

namespace KirikiriS.Tjs2.Interfaces
{
    public interface ITjsNativeInstance : IDisposable
    {
        TjsResultCode Construct(TjsVariant[] param, ITjsDispatch tjsObject);
        void Invalidate();
        //NOTE: Destruct() の代わりに Dispose() を使用します。 
    }
}