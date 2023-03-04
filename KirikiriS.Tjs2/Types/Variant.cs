using System;
using System.IO.Compression;
using KirikiriS.Tjs2.Interfaces;

namespace KirikiriS.Tjs2.Types
{
    public class Variant
    {
        private VariantStruct _variantObject;
        
        

        public void ChangeClosureObjThis(IDispatch objthis)
        {
            
        }

        public bool NormalCompare(Variant val2)
        {
            if (_variantObject.VariantType != val2._variantObject.VariantType) return false;
            
            var cmp1 = _variantObject.Content;
            var cmp2 = val2._variantObject.Content;

            return _variantObject.VariantType switch
            {
                TJSVariantType.Integer => (int)cmp1 == (int)cmp2,
                TJSVariantType.String => (string)cmp1 == (string)cmp2,
                TJSVariantType.Octet => (byte[])cmp1 == (byte[])cmp2,
                TJSVariantType.Object => cmp1 == cmp2,
                TJSVariantType.Void => val2._variantObject.VariantType switch
                {
                    TJSVariantType.Integer => (int)cmp2 == 0,
                    TJSVariantType.Real => (double)cmp2 == 0,
                    TJSVariantType.String => string.IsNullOrEmpty((string)cmp2),
                    _ => false,
                },
                TJSVariantType.Real => (double)cmp1 == (double)cmp2,
                _ => false
            };
        }
        
        #region 演算子オーバーライド
        public static implicit operator Variant(VariantClosure src)
        {
            var dest = new Variant();
            dest._variantObject.Content = src;
            dest._variantObject.VariantType = TJSVariantType.Object;
            return dest;
        }

        public static implicit operator Variant(int src)
        {
            var dest = new Variant();
            dest._variantObject.Content = src;
            dest._variantObject.VariantType = TJSVariantType.Integer;
            return dest;
        }

        public static implicit operator Variant(double src)
        {
            var dest = new Variant();
            dest._variantObject.Content = src;
            dest._variantObject.VariantType = TJSVariantType.Real;
            return dest;
        }

        public static implicit operator Variant(bool src)
        {
            var dest = new Variant();
            dest._variantObject.Content = src ? 1 : 0;
            dest._variantObject.VariantType = TJSVariantType.Integer;
            return dest;
        }

        public static implicit operator Variant(string src)
        {
            var dest = new Variant();
            dest._variantObject.Content = src;
            dest._variantObject.VariantType = TJSVariantType.String;
            return dest;
        }

        public static implicit operator Variant(byte[] src)
        {
            var dest = new Variant();
            dest._variantObject.Content = src;
            dest._variantObject.VariantType = TJSVariantType.Octet;
            return dest;
        }
        #endregion
    }
}