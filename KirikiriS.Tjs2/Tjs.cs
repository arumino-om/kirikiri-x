using System;
using System.Collections.Generic;
using KirikiriS.Tjs2.Interfaces;

namespace KirikiriS.Tjs2
{
    public class Tjs : IDisposable
    {
        private const int VersionMajor = 2;
        private const int VersionMinor = 4;
        private const int VersionRelease = 28;
        private const int VersionHex = VersionMajor * 0x1000000 + VersionMinor * 0x10000 + VersionRelease;
        
        private int _refCount = 1;
        private Dictionary<string, int> _ppValues = new();
        private IDispatch GlobalObject;

        public Tjs()
        {
            _ppValues.Add("version", VersionHex);
        }
        
        public void AddRef() => _refCount++;
        
        public void Release()
        {
            _refCount--;
            if (_refCount <= 0) Dispose();
        }
        
        public void GetGlobal()
        {
            //TODO: グローバルオブジェクトを返す
        }
        
        public void Dispose()
        {
            //NOTE: オブジェクトの開放処理を追加
        }
    }
}
