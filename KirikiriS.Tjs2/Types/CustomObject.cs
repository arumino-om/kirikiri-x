using System;
using System.Collections.Generic;
using KirikiriS.Tjs2.Interfaces;

namespace KirikiriS.Tjs2.Types
{
    public abstract class CustomObject : IDispatch
    {
        private const int MAX_NATIVE_CLASS = 4;
        
        public struct SymbolData
        {
            public uint SymFlags;
            public uint Flags;
            public VariantStruct Value;
        }

        private enum ValidateStatus
        {
            Validate,
            Invalidating,
            Invalidate
        }
        
        private int Count;
        private Dictionary<string, SymbolData> _symbols;
        private bool _isInvalidated;
        private bool _isInvalidating;
        private ITjsNativeInstance[] _classInstances;
        private int[] _classIDs;
        
        protected bool CallFinalizeMethod;
        protected string FinalizeMethodName;
        
        protected bool CallMissingMethod;
        protected bool IsProcessingMissing;
        protected string MissingMethodName;
        
        public CustomObject(int hashbits)
        {
            Count = 0;
            _symbols = new Dictionary<string, SymbolData>();
            _isInvalidated = _isInvalidating = false;
            _classIDs = new int[MAX_NATIVE_CLASS];
            
            CallFinalizeMethod = true;
            CallMissingMethod = true;
            IsProcessingMissing = false;

            FinalizeMethodName = "finalize";
            MissingMethodName = "missing";

            for (var i = 0; i < MAX_NATIVE_CLASS; i++) _classIDs[i] = -1;
        }
        
        public void Dispose()
        {
            for (var i = 0; i < MAX_NATIVE_CLASS; i++) _classInstances[i].Dispose();
            _symbols = null; //GCに回収させる
        }

        private void StartObjectInvalidate()
        {
            if (_isInvalidating) return;
            _isInvalidating = true;

            try
            {
                if (_isInvalidated) return;
                ObjectInvalidate();
                _isInvalidated = true;
            }
            finally
            {
                _isInvalidating = false;
            }
        }

        public void ObjectInvalidate()
        {
            if (CallFinalizeMethod) FuncCall(0, FinalizeMethodName, null, this);

            for (var i = 0; i < MAX_NATIVE_CLASS; i++)
            {
                if (_classIDs[i] != -1) _classInstances[i].Invalidate();
            }

            DeleteAllMembers();
        }

        private void BeforeDispose() => StartObjectInvalidate();

        private bool CallGetMissing(string name)
        {
            if (IsProcessingMissing) return false;
            IsProcessingMissing = true;
            
        }

        public (ResultCode, VariantStruct)
            FuncCall(uint flag, string memberName, VariantStruct[] param, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public (ResultCode, VariantStruct) FuncCall(uint flag, int num, VariantStruct[] param, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public (ResultCode, VariantStruct) PropGet(uint flag, string memberName, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public (ResultCode, VariantStruct) PropGet(uint flag, int num, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode PropSet(uint flag, string memberName, VariantStruct setValue, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode PropSet(uint flag, int num, VariantStruct setValue, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public (ResultCode, int) GetCount(string memberName, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public (ResultCode, int) GetCount(int num, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode EnumMembers(uint flag, VariantClosureStruct callback, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode DeleteMember(uint flag, string memberName, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode DeleteMember(uint flag, int num, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode Invalidate(uint flag, string memberName, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode Invalidate(uint flag, int num, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode IsValid(uint flag, string memberName, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode IsValid(uint flag, int num, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public (ResultCode, IDispatch) CreateNew(uint flag, string memberName, VariantStruct[] param, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public (ResultCode, IDispatch) CreateNew(uint flag, int num, VariantStruct[] param, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode IsInstanceOf(uint flag, string memberName, string className, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode IsInstanceOf(uint flag, int num, string className, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public (ResultCode, VariantStruct) Operation(uint flag, string memberName, VariantStruct param, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public (ResultCode, VariantStruct) Operation(uint flag, int num, VariantStruct param, IDispatch objThis)
        {
            throw new NotImplementedException();
        }

        public ResultCode NativeInstanceSupport(uint flag, int classId, ITjsNativeInstance instance)
        {
            throw new NotImplementedException();
        }

        public ResultCode ClassInstance(TjsCIIFlag flag, uint num, VariantStruct value)
        {
            throw new NotImplementedException();
        }

        public ResultCode PropSet(uint flag, in string memberName, VariantStruct setValue, IDispatch objThis)
        {
            throw new NotImplementedException();
        }
    }
}