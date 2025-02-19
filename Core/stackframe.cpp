#include "stackframe.h"
#include "glob.h"
#include "scope.h"

namespace X {
	namespace AST {
		bool StackFrame::AddVar(XlangRuntime* rt,std::string& name, X::Value& val)
		{
			AutoLock lock(m_lock);
			m_pScope->AddAndSet(rt, nullptr, name, val);
			return true;
		}
#if XLANG_ENG_DBG
		void StackFrame::ObjDbgSet(XObj* pObj)
		{
			G::I().ObjBindToStack(pObj, this);
		}
		void StackFrame::ObjDbgRemove(XObj* pObj)
		{
			G::I().ObjUnbindToStack(pObj, this);
		}
#endif
	}
}