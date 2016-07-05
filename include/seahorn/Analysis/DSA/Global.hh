#ifndef __DSA_GLOBAL_HH_
#define __DSA_GLOBAL_HH_

#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"

#include "seahorn/Analysis/DSA/Graph.hh"

namespace llvm {
   class DataLayout;
   class TargetLibraryInfo;
}

using namespace llvm;

namespace seahorn
{
  namespace dsa
  {

    class Global : public ModulePass
    {
      const DataLayout *m_dl;
      const TargetLibraryInfo *m_tli;
      std::unique_ptr<Graph> m_graph;

    public:

      static char ID;

      Global ();

      void getAnalysisUsage (AnalysisUsage &AU) const override;

      bool runOnModule (Module &M) override;

      const char * getPassName() const override 
      { return "Context-insensitive Dsa global pass"; }

      const Graph& getGraph () const;

    };
  }
}
#endif 
