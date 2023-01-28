using KirikiriS.Tjs2.Interfaces;

namespace KirikiriS.Tjs2.Types
{
    public class TjsVariantClosure
    {
        public ITjsDispatch Object { get; set; }
        public ITjsDispatch ObjectThis { get; set; }
    }
}