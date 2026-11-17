// @category BS2
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class ExportGameplay extends GhidraScript {
 public void run() throws Exception {
  File dir=new File(getScriptArgs()[0]);dir.mkdirs();
  FunctionIterator reset=currentProgram.getFunctionManager().getFunctions(true);
  while(reset.hasNext()){Function f=reset.next();if(f.getName().startsWith("__aeabi_"))f.setNoReturn(false);}
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);
  FunctionIterator it=currentProgram.getFunctionManager().getFunctions(true);int count=0;
  while(it.hasNext()){
   Function f=it.next();String n=f.getName(true);
   if(!(n.contains("CLFigureArchive::")||n.contains("CCLFigureMgr::")||n.contains("CCLGame::")||n.contains("CLMath::xAtan")||n.contains("CCLMatrix::")||n.contains("CCLSpline::")||n.contains("CCLPitch::")||n.contains("CCLCurveData::")||n.contains("CCLProjection::")||n.contains("CBBGRuleEngine::")||n.contains("GetBattingTiming")))continue;
   DecompileResults r=d.decompileFunction(f,30,monitor);
   try(PrintWriter w=new PrintWriter(new File(dir,f.getEntryPoint().toString()+".c"))){w.println("/* "+n+"; research only, not buildable source */");w.println(r.decompileCompleted()?r.getDecompiledFunction().getC():r.getErrorMessage());}
   count++;
  }
  d.dispose();println("EXPORTED "+count+" gameplay functions");
 }
}
